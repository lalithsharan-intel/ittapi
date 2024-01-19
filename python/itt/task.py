from itt_native import py_itt_task_begin, py_itt_task_end

def itt_task_begin(domain_obj, string_handle_obj):
    py_itt_task_begin(domain_obj, None, None, string_handle_obj)

def itt_task_end(domain_obj):
    py_itt_task_end(domain_obj)