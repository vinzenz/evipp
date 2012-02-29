#!/usr/bin/python

import os, sys

def _get_my_directory():
	return os.path.dirname(__file__)


def _get_template_file_path():
	return os.path.join( _get_my_directory(), "../templates/header.tpl")

def _find_git():
	path = _get_my_directory()
	while True:
		test = os.path.join(path, ".git")
		if os.path.exists( test ):
			return path
		if os.path.ismount( path ):
			raise Exception("Couldn't find .git folder")
		path = os.path.abspath( os.path.join( path, ".." ) )
	

def _create_target_directory(sections):
	base_path = os.path.join( _find_git(), "include/evipp")
	for section in sections[:-1]:
		base_path = os.path.join( base_path, section )
		if not os.path.exists( base_path ):
			os.mkdir( base_path, 0644 )
	return base_path	

def _build_target_file_path(sections):
	base_path = _create_target_directory(sections)
	return os.path.join( base_path, "%s.hpp" % sections[-1] )
			

def _build_include_guard(sections):
	guard = ""
	for section in sections:
		guard = "%s_%s" % ( guard, section.upper() )
	return "%s_HPP_" % guard

def _build_namespace_begin(sections):
	namespaces = []
	for section in sections[:-1]:
		namespaces.append( "namespace %s {" % section )
	return '\n'.join(namespaces)

def _build_namespace_end(sections):
	return "}" * (len(sections) - 1)


def _format_file(sections):
	tplf = open( _get_template_file_path(), 'r' )
	tpl = tplf.read()
	tplf.close()

	tpl = tpl.replace('%GUARD_NAME%', _build_include_guard(sections) )
	tpl = tpl.replace('%NAMESPACE_BEGIN%', _build_namespace_begin(sections) )
	tpl = tpl.replace('%NAMESPACE_END%', _build_namespace_end(sections) )

	hdrf = open(_build_target_file_path(sections), 'w')
	hdrf.write(tpl)
	hdrf.close()


def generate(path):
	"""
		Generates a header file from the passed path information
	"""
	sections = path.split('/')
	_format_file(sections)
	
generate(sys.argv[1])
