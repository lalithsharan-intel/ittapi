#include "domain.h"

#define ITT_CAPSULE_NAME_DOMAIN "__itt_domain"

char docstring_itt_domain_create[] = "__itt_domain* ITTAPI __itt_domain_createA(const char    *name)";

__itt_domain* PyDomain_ToNativeDomain(PyObject *obj) {
  return (__itt_domain*) PyCapsule_GetPointer(obj, ITT_CAPSULE_NAME_DOMAIN);
}

PyObject* PyDomain_FromNativeDomain(__itt_domain* domain){
    return PyCapsule_New(domain,ITT_CAPSULE_NAME_DOMAIN,NULL);
}

PyObject* py_itt_domain_create(PyObject* self, PyObject* args){
    const char* name;
    __itt_domain* domain;

    if(!PyArg_ParseTuple(args,"s", &name)){
        return NULL;
    }
    Py_BEGIN_ALLOW_THREADS;
    domain = __itt_domain_create(name);
    Py_END_ALLOW_THREADS;
    return PyDomain_FromNativeDomain(domain);
}
