#include </usr/include/python2.7/Python.h>
#include "pin.H"
#include <strings.h>
#include <stdlib.h>
#include "IMG.h"


// void add_hook(PyObject*** hooks, PyObject* new_hook);// {
//     PyObject** hooks_list = *hooks;
//     if (hooks_list == NULL) {
//         hooks_list = (PyObject**) malloc(sizeof(PyObject*)*2);
//         hooks_list[0] = new_hook;
//         hooks_list[1] = NULL;
//     } else {
//         int hook_count;
//         for(hook_count=0; hooks_list[hook_count]; hook_count++);
//         hooks_list = (PyObject**) realloc(hooks_list, sizeof(PyObject*)*(hook_count+2));
//         hooks_list[hook_count] = new_hook;
//         hooks_list[hook_count+1] = NULL;
//     }

//     *hooks = hooks_list;
// }
// PyObject** hooks_syscall_entry = NULL;
// PyObject** hooks_syscall_exit = NULL;
// PyObject** hooks_instrument_function = NULL;
// PyObject** hooks_img_load = NULL;
// PyObject** hooks_img_unload = NULL;
// ------------------- auto generated
PyObject* Python_IMG_Next(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Prev(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Invalid(PyObject* self, PyObject* args) {
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Valid(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_SecHead(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_SecTail(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_RegsymHead(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Entry(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Name(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("s", IMG_Name(img_object).c_str());
}

PyObject* Python_IMG_Gp(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_LoadOffset(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_LowAddress(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_HighAddress(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_StartAddress(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_SizeMapped(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Type(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_IsMainExecutable(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Id(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_FindImgById(PyObject* self, PyObject* args) {
    PyObject* id;
    PyArg_ParseTuple(args, "O", &id);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_FindByAddress(PyObject* self, PyObject* args) {
    PyObject* address;
    PyArg_ParseTuple(args, "O", &address);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Open(PyObject* self, PyObject* args) {
    PyObject* filename;
    PyArg_ParseTuple(args, "O", &filename);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_IMG_Close(PyObject* self, PyObject* args) {
    PyObject* img;
    PyArg_ParseTuple(args, "O", &img);
    // IMG img_object = *(IMG*)PyInt_AsLong(img);
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_APP_ImgHead(PyObject* self, PyObject* args) {
    return Py_BuildValue("O", Py_True);
}

PyObject* Python_APP_ImgTail(PyObject* self, PyObject* args) {
    return Py_BuildValue("O", Py_True);
}

// ------------------- auto generated

