from distutils.core import setup, Extension

import os
import sys
import platform
import sysconfig

extension_args = {
    'name' : 'itt_native',
    'sources' : [
            'itt-native/itt_python.c', 'itt-native/task.c', 'itt-native/collection_control.c', 
            'itt-native/string_handle.c', 'itt-native/domain.c', 'itt-native/pt.c' 
        ],
    'extra_objects' : [],
    'include_dirs' : [],
    'library_dirs' : [],
}

# path for Python.h
python_include_dir = sysconfig.get_path("include")
extension_args["include_dirs"] = [python_include_dir]

# path for ittnotify.h
ITT_INCLUDE_DIR_ENV = "ITT_INCLUDE_DIR"
itt_include = None
itt_include_file_name = "ittnotify.h"
itt_include_dir = os.environ.get(ITT_INCLUDE_DIR_ENV, None)
if itt_include_dir:
    itt_include_dir = itt_include_dir.replace('"','')
    print('{} is set to {}'.format(ITT_INCLUDE_DIR_ENV,itt_include_dir))
    itt_include = os.path.join(itt_include_dir, itt_include_file_name)

if itt_include == None:
    print('ITT include {0} not found. Set env varable {1} to directory of {0}'.format(itt_include_file_name, ITT_INCLUDE_DIR_ENV))
    sys.exit(-1)
else:
    extension_args["include_dirs"].extend([itt_include_dir])

# path for ittnotify.a
ITT_LIB_DIR_ENV = "ITT_LIB_DIR"
itt_lib_dir = os.environ.get("ITT_LIB_DIR", None)
itt_lib_file_name = "libittnotify.a"
itt_lib = None

if platform.system() == "Linux":
    itt_lib_file_name = "libittnotify.a"
else:
    itt_lib_file_name = "libittnotify.lib"

if itt_lib_dir == None:
    print('ITT library {0} not found. Set env varable {1} to directory of {0}'.format(itt_lib_file_name, ITT_LIB_DIR_ENV))
    sys.exit(-1)
else:
    itt_lib_dir = itt_lib_dir.replace('"','')
    print('{} is set to {}'.format(ITT_LIB_DIR_ENV,itt_lib_dir))
    extension_args["library_dirs"].extend([itt_lib_dir])

itt_lib = os.path.join(itt_lib_dir, itt_lib_file_name)
if itt_lib == None:
    print('ITT library not found : {}'.format(itt_lib))
    sys.exit(-1)
else:
    extension_args["extra_objects"].extend([itt_lib])


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