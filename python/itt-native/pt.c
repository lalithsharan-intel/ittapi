#include "pt.h"

char docstring_itt_pt_region_create[] = "__itt_pt_region ITTAPI __itt_pt_region_create(const char *name);";
char docstring_itt_mark_pt_region_begin[] = "void __itt_mark_pt_region_begin(__itt_pt_region region);";
char docstring_itt_mark_pt_region_end[] = "void __itt_mark_pt_region_end(__itt_pt_region region);";

PyObject* py_itt_pt_region_create(PyObject* self, PyObject* args){
    const char* name;
    __itt_pt_region region;

    if(!PyArg_ParseTuple(args,"s", &name)){
        return NULL;
    }
    Py_BEGIN_ALLOW_THREADS;
    region = __itt_pt_region_create(name);
    Py_END_ALLOW_THREADS;
    return Py_BuildValue("B",region);
}

PyObject* py_itt_mark_pt_region_begin(PyObject* self, PyObject* args){
    __itt_pt_region region;

    if(!PyArg_ParseTuple(args,"B", &region)){
        return NULL;
    }
    Py_BEGIN_ALLOW_THREADS;
    __itt_mark_pt_region_begin(region);
    Py_END_ALLOW_THREADS;
    Py_RETURN_NONE;
}

PyObject* py_itt_mark_pt_region_end(PyObject* self, PyObject* args){
    __itt_pt_region region;

    if(!PyArg_ParseTuple(args,"B", &region)){
        return NULL;
    }
    Py_BEGIN_ALLOW_THREADS;
    __itt_mark_pt_region_end(region);
    Py_END_ALLOW_THREADS;
    Py_RETURN_NONE;
}