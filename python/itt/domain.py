from . import utils
import itt_native

def itt_domain_create(domain_name_str):
    if utils.isWindows():
        return itt_native.py_itt_domain_createW(domain_name_str)
    else:
        return itt_native.py_itt_domain_create(domain_name_str)

if utils.isWindows():
    def itt_domain_createA(domain_name_str):
        return itt_native.py_itt_domain_createA(domain_name_str)

    def itt_domain_createW(domain_name_str):
        return itt_native.py_itt_domain_createW(domain_name_str)
