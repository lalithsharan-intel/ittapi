from itt_native import py_itt_pt_region_create, py_itt_mark_pt_region_begin, py_itt_mark_pt_region_end


def itt_pt_region_create(region_name_str): 
	return py_itt_pt_region_create(region_name_str)
	
def itt_mark_pt_region_begin(region_obj):
	py_itt_mark_pt_region_begin(region_obj)
	
def itt_mark_pt_region_end(region_obj):
	py_itt_mark_pt_region_end(region_obj)