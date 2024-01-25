#ifndef PT_HPP
#define PT_HPP

#include "common.h"

#if ITT_PLATFORM==ITT_PLATFORM_WIN
extern PyObject* py_itt_pt_region_createA(PyObject* self, PyObject* args);
extern PyObject* py_itt_pt_region_createW(PyObject* self, PyObject* args);
#else
extern PyObject* py_itt_pt_region_create(PyObject* self, PyObject* args);
#endif

extern char docstring_itt_pt_region_create[];
extern char docstring_itt_mark_pt_region_begin[];
extern char docstring_itt_mark_pt_region_end[];

extern PyObject* py_itt_mark_pt_region_begin(PyObject* self, PyObject* args);
extern PyObject* py_itt_mark_pt_region_end(PyObject* self, PyObject* args);

#endif // PT_HPP