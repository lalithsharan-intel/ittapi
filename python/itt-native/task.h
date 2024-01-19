#ifndef TASK_HPP
#define TASK_HPP

#include "common.h"
#include "domain.h"
#include "string_handle.h"

extern char docstring_itt_task_begin[];
extern char docstring_itt_task_end[];

extern PyObject* py_itt_task_begin(PyObject* self, PyObject* args);
extern PyObject* py_itt_task_end(PyObject* self, PyObject* args);

#endif // TASK_HPP