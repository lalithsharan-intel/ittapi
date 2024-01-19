#ifndef STRING_HANDLE_HPP
#define STRING_HANDLE_HPP

#include "common.h"

extern char docstring_itt_string_handle_create[];

extern PyObject* py_itt_string_handle_create(PyObject* self, PyObject* args);
extern __itt_string_handle* PyStringHandle_ToNativeStringHandle(PyObject *obj);
extern PyObject* PyStringHandle_FromNativeStringHandle(__itt_string_handle* string_handle);

#endif // STRING_HANDLE_HPP