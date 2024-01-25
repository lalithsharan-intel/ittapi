#ifndef STRING_HANDLE_HPP
#define STRING_HANDLE_HPP

#include "common.h"

#if ITT_PLATFORM==ITT_PLATFORM_WIN
extern PyObject* py_itt_string_handle_createA(PyObject* self, PyObject* args);
extern PyObject* py_itt_string_handle_createW(PyObject* self, PyObject* args);
#else
extern PyObject* py_itt_string_handle_create(PyObject* self, PyObject* args);
#endif

extern char docstring_itt_string_handle_create[];

extern __itt_string_handle* PyStringHandle_ToNativeStringHandle(PyObject *obj);
extern PyObject* PyStringHandle_FromNativeStringHandle(__itt_string_handle* string_handle);

#endif // STRING_HANDLE_HPP