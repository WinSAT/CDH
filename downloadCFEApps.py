appsList = ['cf','cs','ds','fm','hk','hs','lc','md','mm','sc','sch']

import subprocess
import os

cwd = os.getcwd()

def runCommand(cmd):
	isShell = False
	if type(cmd) == list:
		for i in cmd:
			print("cmd: ",i)
			if i[:3] == 'mv ':
				command = subprocess.Popen(i, stdout=subprocess.PIPE, shell=True)
			else:
				command = subprocess.Popen(i.split(' '), stdout=subprocess.PIPE)
			output = command.communicate()[0]
	elif type(cmd) == str:
		print('cmd: ',cmd)
		if cmd[:3] == 'mv ':
			command = subprocess.Popen(cmd, stdout=subprocess.PIPE, shell=True)
		else:
			command = subprocess.Popen(cmd.split(' '), stdout=subprocess.PIPE)
		output = command.communicate()[0]

for app in appsList:
	appDir = "{}/cFE/apps/{}".format(cwd,app)
	runCommand([
		'rm -rf {}'.format(appDir),
		"wget https://github.com/nasa/{}/archive/master.zip -P {}".format(app,appDir),
		"unzip {0}/master.zip -d {0}/".format(appDir)
	])
	dirlist = [ item for item in os.listdir(appDir) if os.path.isdir(os.path.join(appDir, item)) ]
	runCommand([
		'mv {0}/{1}/* {0}/'.format(appDir,dirlist[0]),
		'rm {}/master.zip'.format(appDir),
		'rm -rf {}/{}'.format(appDir,dirlist[0]),
	])
	print 'Finalized {}: {}'.format(app, os.listdir(appDir))
