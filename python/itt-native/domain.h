#ifndef DOMAIN_HPP
#define DOMAIN_HPP

#include "common.h"

extern char docstring_itt_domain_create[];

extern __itt_domain* PyDomain_ToNativeDomain(PyObject *obj);
extern PyObject* PyDomain_FromNativeDomain(__itt_domain* domain);
extern PyObject* py_itt_domain_create(PyObject* self, PyObject* args);

#endif  // DOMAIN_HPP