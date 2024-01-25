#include "task.h"

char docstring_itt_task_begin[] = "void ITTAPI __itt_task_begin(const __itt_domain *domain, __itt_id taskid, __itt_id parentid, __itt_string_handle *name);";
char docstring_itt_task_end[] = "void ITTAPI __itt_task_end(const __itt_domain *domain);";

PyObject* py_itt_task_begin(PyObject* self, PyObject* args)
{
    PyObject *py_domain, *py_string_handle, *py_taskid, *py_parentid;
    __itt_domain* domain;
    __itt_string_handle* string_handle;

    if (!PyArg_ParseTuple(args,"OOOO",&py_domain, &py_taskid, &py_parentid, &py_string_handle)) {
        return NULL;
    }

    domain = PyDomain_ToNativeDomain(py_domain);
    string_handle = PyStringHandle_ToNativeStringHandle(py_string_handle);
    Py_BEGIN_ALLOW_THREADS;
    __itt_task_begin(domain, __itt_null, __itt_null, string_handle);
    Py_END_ALLOW_THREADS;
    Py_RETURN_NONE;
}

PyObject* py_itt_task_end(PyObject* self, PyObject* args)
{
    PyObject *py_domain;
    __itt_domain* domain;

    if (!PyArg_ParseTuple(args,"O",&py_domain)) {
        return NULL;
    }
    domain = PyDomain_ToNativeDomain(py_domain);
    Py_BEGIN_ALLOW_THREADS;
    __itt_task_end(domain);
    Py_END_ALLOW_THREADS;
    Py_RETURN_NONE;
}