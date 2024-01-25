from . import utils
import itt_native

def itt_string_handle_create(string_name_str):
    if utils.isWindows():
        return itt_native.py_itt_string_handle_createW(string_name_str)
    else:
        return itt_native.py_itt_string_handle_create(string_name_str)

if utils.isWindows():
    def itt_string_handle_createA(string_name_str):
        return itt_native.py_itt_string_handle_createA(string_name_str)

    def itt_string_handle_createW(string_name_str):
        return itt_native.py_itt_string_handle_createW(string_name_str)


