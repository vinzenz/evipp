#!/usr/bin/python

import os

def fix_file(fpath):
	content = read_file(fpath)
	content = adjust_content(content)
	write_file(fpath, content)

def read_file(fpath):
	f = open(fpath, 'r')
	c = c.read()
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
	return content.replace(' GUARD_EVIPP',' GUARD_').replace(' GUARD_', ' GUARD_EVIPP')

def goto_includes():
	while not os.path.exists( os.path.combine( os.getcwd(), '.git' ) ):
		os.chdir('..')
	os.chdir('includes')

def check_dir(name):
	os.chdir(name)
	for f in os.listdir('.'):
		fpath = os.path.combine(os.getcwd(), f ) 
		if os.path.isdir(fpath):
			check_dir(f)
		elif os.path.isfile(fpath):
			fix_file(fpath)
	os.chdir('')

def fix_headers():
	goto_includes()
	os.listdir('evipp')

fix_headers()
