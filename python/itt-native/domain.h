#ifndef DOMAIN_HPP
#define DOMAIN_HPP

#include "common.h"

#if ITT_PLATFORM==ITT_PLATFORM_WIN
extern PyObject* py_itt_domain_createW(PyObject* self, PyObject* args);
extern PyObject* py_itt_domain_createA(PyObject* self, PyObject* args);
#else
extern PyObject* py_itt_domain_create(PyObject* self, PyObject* args);
#endif

extern char docstring_itt_domain_create[];

extern __itt_domain* PyDomain_ToNativeDomain(PyObject *obj);
extern PyObject* PyDomain_FromNativeDomain(__itt_domain* domain);


#endif  // DOMAIN_HPP