from distutils.core import setup, Extension

import os
import sys
import platform
import sysconfig
import subprocess

extension_args = {
    'name' : 'itt_native',
    'sources' : [],
    'include_dirs' : [],
    'extra_objects': []
}

# python extension sources
extension_args["sources"].extend(
    [
        'itt-native/itt_python.c', 'itt-native/task.c', 'itt-native/collection_control.c', 
        'itt-native/string_handle.c', 'itt-native/domain.c', 'itt-native/pt.c'
    ]
)

bits = '62' if (sys.maxsize > 2**32) else '32'

python_ext_dir = os.path.dirname(__file__)
ittapi_dir = os.path.realpath(os.path.join(python_ext_dir, '..'))

# path for Python.h
python_include_dir = sysconfig.get_path("include")
extension_args["include_dirs"] = [python_include_dir]

# itt source
bits = '64'
if platform.system() == "Linux":
    itt_lib_file_name = "libittnotify.a"
else:
    itt_lib_file_name = "libittnotify.lib"

itt_lib = os.path.join(ittapi_dir, "build_" + sys.platform.replace('32', ""), bits, 'bin', itt_lib_file_name)
if not os.path.exists(itt_lib):
    # ittapi not found, build it
    print('ITTAPI Library {} not found. Building'.format(itt_lib))
    sys.stdout.flush()
    sys.stderr.flush()
    subprocess.run(['python', 'buildall.py', '-pt', '--force_bits', bits], cwd=ittapi_dir)
    if not os.path.exists(itt_lib):
        # Still not found
        assert os.path.exists(itt_lib) , 'ITTAPI library {0} not found.'.format(itt_lib)

extension_args["extra_objects"].extend([itt_lib])


# ittnotify.h,
itt_include_dir = [os.path.join(ittapi_dir, 'include')]
extension_args["include_dirs"].extend(itt_include_dir)

print('Extension : {}'.format(extension_args))
extension = Extension(
    **extension_args
)

setup(
    name = "itt",
    version = "0.0.1",
    description="ITT API for Python",
    author='Intel',
    url='https://github.com/intel/ittapi',
    ext_modules=[extension],
    packages = ['itt'],
)