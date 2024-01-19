#ifndef PT_HPP
#define PT_HPP

#include "common.h"

extern char docstring_itt_pt_region_create[];
extern char docstring_itt_mark_pt_region_begin[];
extern char docstring_itt_mark_pt_region_end[];

extern PyObject* py_itt_pt_region_create(PyObject* self, PyObject* args);
extern PyObject* py_itt_mark_pt_region_begin(PyObject* self, PyObject* args);
extern PyObject* py_itt_mark_pt_region_end(PyObject* self, PyObject* args);

#endif // PT_HPP