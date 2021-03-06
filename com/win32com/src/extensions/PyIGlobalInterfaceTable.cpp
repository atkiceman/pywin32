// This file implements the IGlobalInterfaceTable Interface for Python.
// Generated by makegw.py

#include "stdafx.h"
#include "PythonCOM.h"
#include "PyIGlobalInterfaceTable.h"

// ---------------------------------------------------
//
// Interface Implementation

PyIGlobalInterfaceTable::PyIGlobalInterfaceTable(IUnknown *pdisp) : PyIUnknown(pdisp) { ob_type = &type; }

PyIGlobalInterfaceTable::~PyIGlobalInterfaceTable() {}

IGlobalInterfaceTable *PyIGlobalInterfaceTable::GetI(PyObject *self)
{
    return (IGlobalInterfaceTable *)PyIUnknown::GetI(self);
}

PyObject *PyIGlobalInterfaceTable::RegisterInterfaceInGlobal(PyObject *self, PyObject *args)
{
    PyObject *obpUnk = NULL;
    PyObject *obriid = NULL;
    IUnknown *pUnk;
    IID riid;
    DWORD pdwCookie;
    PyObject *ppyobRetval = NULL;
    HRESULT hr;

    IGlobalInterfaceTable *pIGIT = GetI(self);
    if (pIGIT == NULL) {
        return NULL;
    }
    if (!PyArg_ParseTuple(args, "OO:RegisterInterfaceInGlobal", &obpUnk, &obriid)) {
        return NULL;
    }
    BOOL bPythonIsHappy = TRUE;
    if (!PyCom_InterfaceFromPyInstanceOrObject(obpUnk, IID_IUnknown, (void **)&pUnk, TRUE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (!PyWinObject_AsIID(obriid, &riid))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy) {
        return NULL;
    }
    PY_INTERFACE_PRECALL;
    hr = pIGIT->RegisterInterfaceInGlobal(pUnk, riid, &pdwCookie);
    if (pUnk)
        pUnk->Release();
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr)) {
        return PyCom_BuildPyException(hr, pIGIT, IID_IGlobalInterfaceTable);
    }
    ppyobRetval = Py_BuildValue("l", pdwCookie);
    return ppyobRetval;
}

PyObject *PyIGlobalInterfaceTable::RevokeInterfaceFromGlobal(PyObject *self, PyObject *args)
{
    DWORD dwCookie;
    HRESULT hr;

    IGlobalInterfaceTable *pIGIT = GetI(self);
    if (pIGIT == NULL) {
        return NULL;
    }
    if (!PyArg_ParseTuple(args, "l:RevokeInterfaceFromGlobal", &dwCookie)) {
        return NULL;
    }
    PY_INTERFACE_PRECALL;
    hr = pIGIT->RevokeInterfaceFromGlobal(dwCookie);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr)) {
        return PyCom_BuildPyException(hr, pIGIT, IID_IGlobalInterfaceTable);
    }
    Py_INCREF(Py_None);
    return Py_None;
}

PyObject *PyIGlobalInterfaceTable::GetInterfaceFromGlobal(PyObject *self, PyObject *args)
{
    PyObject *obriid = NULL;
    DWORD dwCookie;
    IID riid;
    void *ppv;
    HRESULT hr;

    IGlobalInterfaceTable *pIGIT = GetI(self);
    if (pIGIT == NULL) {
        return NULL;
    }
    if (!PyArg_ParseTuple(args, "lO:GetInterfaceFromGlobal", &dwCookie, &obriid)) {
        return NULL;
    }
    BOOL bPythonIsHappy = TRUE;
    if (!PyWinObject_AsIID(obriid, &riid))
        bPythonIsHappy = FALSE;

    if (!bPythonIsHappy) {
        return NULL;
    }
    PY_INTERFACE_PRECALL;
    hr = pIGIT->GetInterfaceFromGlobal(dwCookie, riid, &ppv);
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr)) {
        return PyCom_BuildPyException(hr, pIGIT, IID_IGlobalInterfaceTable);
    }
    return PyCom_PyObjectFromIUnknown((IUnknown *)ppv, riid, FALSE);
}

static struct PyMethodDef PyIGlobalInterfaceTable_methods[] = {
    {"RegisterInterfaceInGlobal", PyIGlobalInterfaceTable::RegisterInterfaceInGlobal, 1},
    {"RevokeInterfaceFromGlobal", PyIGlobalInterfaceTable::RevokeInterfaceFromGlobal, 1},
    {"GetInterfaceFromGlobal", PyIGlobalInterfaceTable::GetInterfaceFromGlobal, 1},
    {NULL}};

PyComTypeObject PyIGlobalInterfaceTable::type("PyIGlobalInterfaceTable", &PyIUnknown::type,
                                              sizeof(PyIGlobalInterfaceTable), PyIGlobalInterfaceTable_methods,
                                              GET_PYCOM_CTOR(PyIGlobalInterfaceTable));
