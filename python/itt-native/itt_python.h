#ifndef ITT_PYTHON_HPP
#define ITT_PYTHON_HPP

#include "collection_control.h"
#include "task.h"
#include "string_handle.h"
#include "pt.h"
#include "domain.h"

static char docstring[] = "Python bindings for ITT API";

static PyMethodDef itt_methods[] = {
    // collection_control 
    {"py_itt_pause", py_itt_pause, METH_VARARGS,docstring_itt_pause},
    {"py_itt_resume", py_itt_resume, METH_VARARGS,docstring_itt_resume},
    {"py_itt_detach",py_itt_detach, METH_VARARGS, docstring_itt_detach},

    // task
    {"py_itt_task_begin",py_itt_task_begin,METH_VARARGS,docstring_itt_task_begin},
    {"py_itt_task_end",py_itt_task_end,METH_VARARGS,docstring_itt_task_end},

    // string_handle
    {"py_itt_string_handle_create",py_itt_string_handle_create,METH_VARARGS,docstring_itt_string_handle_create},

    // pt
    {"py_itt_pt_region_create", py_itt_pt_region_create,METH_VARARGS, docstring_itt_pt_region_create},
    {"py_itt_mark_pt_region_begin", py_itt_mark_pt_region_begin, METH_VARARGS, docstring_itt_mark_pt_region_begin},
    {"py_itt_mark_pt_region_end", py_itt_mark_pt_region_end, METH_VARARGS, docstring_itt_mark_pt_region_end},

    // domain    
    {"py_itt_domain_create",py_itt_domain_create,METH_VARARGS,docstring_itt_domain_create},

    // End
    {NULL, NULL, 0, NULL}
};

#endif // ITT_PYTHON_HPP