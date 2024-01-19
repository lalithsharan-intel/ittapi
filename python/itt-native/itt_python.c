#include "itt_python.h"


#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef itt_module = {
    PyModuleDef_HEAD_INIT,
    "itt_native",
    docstring,
    -1,
    itt_methods
};

PyMODINIT_FUNC PyInit_itt_native(void)
{
    return PyModule_Create(&itt_module);
}

#else
void inititt_native(void)
{
    Py_InitModule3("itt_native", itt_methods, docstring);
}
#endif