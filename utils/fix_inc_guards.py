#!/usr/bin/python

import os

def fix_file(fpath):
	print "Processing:",fpath
	content = read_file(fpath)
	content = adjust_content(content)
	write_file(fpath, content)

def read_file(fpath):
	f = open(fpath, 'r')
	c = f.read()
	f.close()
	return c

def write_file(fpath, content):
	f = open(fpath, 'w')
	f.write(content)
	f.close()

def adjust_content(content):
	# replace first all GUARD_EVIPP with GUARD_ and then GUARD_ with GUARD_EVIPP
	# seems pointless on the first look, however we don't have to check if GUARD_ is there alone
	# or if GUARD_EVIPP is there
	# We always want GUARD_EVIPP
	return content.replace('GUARD_EVIPP_','GUARD_').replace('GUARD_', 'GUARD_EVIPP_')

def goto_include():	
	while not os.path.exists( os.path.join( os.getcwd(), '.git' ) ):
		os.chdir('..')
	os.chdir('include')

def check_dir(name):
	os.chdir(name)
	for f in os.listdir('.'):
		fpath = os.path.join(os.getcwd(), f ) 
		if os.path.isdir(fpath):
			check_dir(f)
		elif os.path.isfile(fpath):
			fix_file(fpath)
	os.chdir('..')

def fix_headers():
	goto_include()
	check_dir('evipp')

fix_headers()
