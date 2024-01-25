#include "string_handle.h"

#define ITT_CAPSULE_NAME_STRING_HANDLE "__itt_string_handle"

char docstring_itt_string_handle_create[] = "__itt_string_handle* ITTAPI __itt_string_handle_create(const char *name);";

__itt_string_handle* PyStringHandle_ToNativeStringHandle(PyObject *obj) 
{
  return (__itt_string_handle*) PyCapsule_GetPointer(obj, ITT_CAPSULE_NAME_STRING_HANDLE);
}

PyObject* PyStringHandle_FromNativeStringHandle(__itt_string_handle* string_handle)
{
    return PyCapsule_New(string_handle,ITT_CAPSULE_NAME_STRING_HANDLE,NULL);
}


#if ITT_PLATFORM==ITT_PLATFORM_WIN
PyObject* py_itt_string_handle_createW(PyObject* self, PyObject* args)
{
    const wchar_t* name;
    __itt_string_handle* string_handle;

    if(!PyArg_ParseTuple(args,"u", &name)){
        return NULL;
    }
    Py_BEGIN_ALLOW_THREADS;
    string_handle = __itt_string_handle_createW(name);
    Py_END_ALLOW_THREADS;
    return PyStringHandle_FromNativeStringHandle(string_handle);
}
#endif

#if ITT_PLATFORM==ITT_PLATFORM_WIN
PyObject* py_itt_string_handle_createA(PyObject* self, PyObject* args)
#else
PyObject* py_itt_string_handle_create(PyObject* self, PyObject* args)
#endif
{
    const char* name;
    __itt_string_handle* string_handle;

    if(!PyArg_ParseTuple(args,"s", &name)){
        return NULL;
    }
    Py_BEGIN_ALLOW_THREADS;
#if ITT_PLATFORM==ITT_PLATFORM_WIN
    string_handle = __itt_string_handle_createA(name);
#else
    string_handle = __itt_string_handle_create(name);
#endif
    Py_END_ALLOW_THREADS;
    return PyStringHandle_FromNativeStringHandle(string_handle);
}