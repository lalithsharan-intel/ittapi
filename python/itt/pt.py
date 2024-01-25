from . import utils
import itt_native

def itt_pt_region_create(region_name_str): 
    if utils.isWindows():
        return itt_native.py_itt_pt_region_createW(region_name_str)
    else:
        return itt_native.py_itt_pt_region_create(region_name_str)

if utils.isWindows():
     def itt_pt_region_createW(region_name_str):
        return itt_native.py_itt_pt_region_createW(region_name_str)

     def itt_pt_region_createA(region_name_str):
        return itt_native.py_itt_pt_region_createA(region_name_str)

def itt_mark_pt_region_begin(region_obj):
	itt_native.py_itt_mark_pt_region_begin(region_obj)
	
def itt_mark_pt_region_end(region_obj):
	itt_native.py_itt_mark_pt_region_end(region_obj)
