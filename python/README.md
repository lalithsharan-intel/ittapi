# Python bindings
Python Bindings for ITT API

## Install
Set the following environment variables to point to ITT include and lib directories from VTune installation
export ITT_INCLUDE_DIR=$VTUNE_PROFILER_DIR/include
export ITT_LIB_DIR=$VTUNE_PROFILER_DIR/lib64
python setup.py install

## Usage
    from itt import domain, string_handle, task

    domain1 = domain.itt_domain_create("mydomain1")
    string_handle1 = string_handle.itt_string_handle_create("Task:Task1")
    string_handle2 = string_handle.itt_string_handle_create("Task:Task2")

    # Some interesting task 
    task.itt_task_begin(domain1, string_handle1)
    # Task code 
    task.itt_task_end(domain1)

    # Some other interesting task 
    task.itt_task_begin(domain1, string_handle1)
    # Task code 
    task.itt_task_end(domain1)
