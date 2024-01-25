#include "collection_control.h"

char docstring_itt_pause[] = "void ITTAPI __itt_pause(void);";
char docstring_itt_resume[] = "void ITTAPI __itt_resume(void);";
char docstring_itt_detach[] = "void ITTAPI __itt_detach(void);";

PyObject* py_itt_pause(PyObject* self, PyObject* args)
{
    Py_BEGIN_ALLOW_THREADS;
    __itt_pause();
    Py_END_ALLOW_THREADS;
    Py_RETURN_NONE;
}

PyObject* py_itt_resume(PyObject* self, PyObject* args)
{
    Py_BEGIN_ALLOW_THREADS;
    __itt_resume();
    Py_END_ALLOW_THREADS;
    Py_RETURN_NONE;
}

PyObject* py_itt_detach(PyObject* self, PyObject* args)
{
    Py_BEGIN_ALLOW_THREADS;
    __itt_detach();
    Py_END_ALLOW_THREADS;
    Py_RETURN_NONE;
}
