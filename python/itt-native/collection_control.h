#ifndef COLLECTION_CONTROL_HPP
#define COLLECTION_CONTROL_HPP

#include "common.h"

extern char docstring_itt_pause[];
extern char docstring_itt_resume[];
extern char docstring_itt_detach[];

extern PyObject* py_itt_pause(PyObject* self, PyObject* args);
extern PyObject* py_itt_resume(PyObject* self, PyObject* args);
extern PyObject* py_itt_detach(PyObject* self, PyObject* args);

#endif // #ifndef COLLECTION_CONTROL_HPP