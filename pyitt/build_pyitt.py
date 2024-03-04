#!/usr/bin/env python
import os
import subprocess
import shutil

pyitt_local_dir_name = 'pyitt'
pyitt_local_dir_abspath = os.path.join(os.getcwd(),pyitt_local_dir_name )
pyitt_repo_url = 'https://github.com/esuldin/pyitt'
pyitt_clone_cmd = 'git clone --branch main --single-branch https://github.com/esuldin/pyitt {}'.format(pyitt_local_dir_name)
pyitt_co_cmd = 'git checkout a7679c43211e80aa7876b65c96a8e95ede52f6b4'
pyitt_install_cmd = 'pip install .'

print("#################################################")
print ('Building pyitt - start')

# Check if pyitt directory exists and delete it
if (os.path.exists(pyitt_local_dir_name)):
    print ('Deleting {}'.format(pyitt_local_dir_name))
    shutil.rmtree('pyitt')

# Clone pyitt repo
print("#################################################")
print('Cloning pyitt repo : {}'.format(pyitt_clone_cmd))
subprocess.run(pyitt_clone_cmd.split(), check=True)
if not os.path.exists(pyitt_local_dir_name):
    print('Cloning pyitt repo failed')
    exit(-1)

# Checkout the commit
os.chdir(pyitt_local_dir_name)
subprocess.run(pyitt_co_cmd.split(), check=True)

# execute pip install
print("#################################################")
print('Installing pyitt module : {}'.format(pyitt_install_cmd))
pyitt_env = dict(os.environ)
pyitt_env ['PYITT_ITT_API_SOURCE_DIR'] = '../../'
pyitt_env ['PYITT_BUILD_WITH_ITT_API_IPT_SUPPOR'] = '1'
pyitt_install_cmd_process = subprocess.Popen(pyitt_install_cmd.split(), stdout=subprocess.PIPE, stderr=subprocess.PIPE,  env= pyitt_env)
stdout, stderr = pyitt_install_cmd_process.communicate()
print('{}'.format(stdout.decode()))
print('{}'.format(stderr.decode()))

print("#################################################")
print ('Building pyitt - end')
