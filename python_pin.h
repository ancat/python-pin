#ifndef B_H
#define B_H

PyObject* module;
PyObject** hooks_syscall_entry = NULL;
PyObject** hooks_syscall_exit = NULL;
PyObject** hooks_instrument_function = NULL;
PyObject** hooks_img_load = NULL;
PyObject** hooks_img_unload = NULL;
PyObject** hooks_trace_instrument = NULL;
void initialize_pin_module();

void add_hook(PyObject*** hooks, PyObject* new_hook);

void SyscallEntry(THREADID threadIndex, CONTEXT *ctxt, SYSCALL_STANDARD std, VOID *v);
void SyscallExit(THREADID threadIndex, CONTEXT *ctxt, SYSCALL_STANDARD std, VOID* v);
PyObject* Python_PIN_AddSyscallExitFunction(PyObject* self, PyObject* args);
PyObject* Python_PIN_AddSyscallEntryFunction(PyObject* self, PyObject* args);
PyObject* Python_TRACE_AddInstrumentFunction(PyObject* self, PyObject* args) ;

void InstrumentFunction(RTN rtn, VOID *v);
PyObject* Python_RTN_AddInstrumentFunction(PyObject* self, PyObject* args);


typedef struct rtn_hook {
    PyObject* function;
    int arguments;
} rtn_hook;

void ImageLoad(IMG img, VOID *v);
void ImageUnload(IMG img, VOID *v);
void Trace(TRACE trace, VOID *v);

static PyMethodDef methods[] = {
    {"AddSyscallEntryFunction",
        Python_PIN_AddSyscallEntryFunction,
        METH_VARARGS,
        "Register a notification function that is called immediately before execution of a system call."},
    {"AddSyscallExitFunction",
        Python_PIN_AddSyscallExitFunction,
        METH_VARARGS,
        "Register a notification function that is called immediately after execution of a system call."},
    {"GetSyscallNumber",
        Python_PIN_GetSyscallNumber,
        METH_VARARGS,
        "Get the number (ID) of the system call to be executed in the specified context."},
    {"GetSyscallArgument",
        Python_PIN_GetSyscallArgument,
        METH_VARARGS,
        "Get the value of the argument of the system call to be executed in the specified context."},
    {"GetSyscallReturn",
        Python_PIN_GetSyscallReturn,
        METH_VARARGS,
        "Get the return value of the system call which has just returned with the specified context."},
    {"SetSyscallArgument",
        Python_PIN_SetSyscallArgument,
        METH_VARARGS,
        "Set the given value for the argument of the system call to be executed in the specified context."},
    {"SetSyscallNumber",
        Python_PIN_SetSyscallNumber,
        METH_VARARGS,
        "Set the number (ID) of the system call to be executed in the specified context."},

    {"RTN_AddInstrumentFunction",
        Python_RTN_AddInstrumentFunction,
        METH_VARARGS,
        "Set the number (ID) of the system call to be executed in the specified context."},
    {"RTN_Name",
        Python_RTN_Name,
        METH_VARARGS,
        "fuck if I know dude"},
    {"RTN_InsertCall",
        Python_RTN_InsertCall,
        METH_VARARGS,
        "stop"},
    {"IMG_Next",
        Python_IMG_Next,
        METH_VARARGS,
        "Of the list of currently loaded images in memory it returns the image loaded after image x, or IMG_Invalid() if x is the last image"},
    {"IMG_Prev",
        Python_IMG_Prev,
        METH_VARARGS,
        "Of the list of currently loaded images in memory it returns the image loaded prior to image x, or IMG_Invalid() if x is the first image"},
    {"IMG_Invalid",
        Python_IMG_Invalid,
        METH_VARARGS,
        "Used to indicate no image"},
    {"IMG_Valid",
        Python_IMG_Valid,
        METH_VARARGS,
        "True if x is not IMG_Invalid()"},
    {"IMG_SecHead",
        Python_IMG_SecHead,
        METH_VARARGS,
        "First section in image"},
    {"IMG_SecTail",
        Python_IMG_SecTail,
        METH_VARARGS,
        "Last section in image"},
    {"IMG_RegsymHead",
        Python_IMG_RegsymHead,
        METH_VARARGS,
        "First regular symbol in image"},
    {"IMG_Entry",
        Python_IMG_Entry,
        METH_VARARGS,
        "Address of first instruction executed when image is loaded"},
    {"IMG_Name",
        Python_IMG_Name,
        METH_VARARGS,
        "Name of image, Image names are encoded in UTF8 (a superset of ASCII), this is supported for Linux (only for locales encoded in UTF8) and Windows"},
    {"IMG_Gp",
        Python_IMG_Gp,
        METH_VARARGS,
        "Global pointer (GP) of image, if a GP is used to address global data"},
    {"IMG_LoadOffset",
        Python_IMG_LoadOffset,
        METH_VARARGS,
        "Offset from the image's link-time address to its load-time address."},
    {"IMG_LowAddress",
        Python_IMG_LowAddress,
        METH_VARARGS,
        "The lowest virtual address of the image in the memory"},
    {"IMG_HighAddress",
        Python_IMG_HighAddress,
        METH_VARARGS,
        "The highest virtual address of the image in the memory"},
    {"IMG_StartAddress",
        Python_IMG_StartAddress,
        METH_VARARGS,
        "The starting virtual address that the image is mapped to"},
    {"IMG_SizeMapped",
        Python_IMG_SizeMapped,
        METH_VARARGS,
        "The size of the image mapped"},
    {"IMG_Type",
        Python_IMG_Type,
        METH_VARARGS,
        "Image type"},
    {"IMG_IsMainExecutable",
        Python_IMG_IsMainExecutable,
        METH_VARARGS,
        "TRUE if this is the main executable of an application"},
    {"IMG_Id",
        Python_IMG_Id,
        METH_VARARGS,
        "Returns a unique ID for the image. If an image is unloaded, the ID is not reused for a different image. If an image is unloaded and the same one is loaded back, the ID is different."},
    {"IMG_FindImgById",
        Python_IMG_FindImgById,
        METH_VARARGS,
        "Find image by Id"},
    {"IMG_FindByAddress",
        Python_IMG_FindByAddress,
        METH_VARARGS,
        "Find image by address"},
    {"IMG_AddInstrumentFunction",
        Python_IMG_AddInstrumentFunction,
        METH_VARARGS,
        "Use this to register a call back to catch the loading of an image"},
    {"IMG_AddUnloadFunction",
        Python_IMG_AddUnloadFunction,
        METH_VARARGS,
        "Register fun as a call back to be used when an image is unloaded. This is not an instrumentation function--it doesn't make sense to instrument a function when it removed from memory."},
    {"IMG_Open",
        Python_IMG_Open,
        METH_VARARGS,
        "Allows one to open and image and browse it statically. There can only be one image opened at a time. File names are encoded in UTF8 (a superset of ASCII), this is supported for Linux (only for locales encoded in UTF8) and Windows Returns IMG_INVALID() if the image can not be opened"},
    {"IMG_Close",
        Python_IMG_Close,
        METH_VARARGS,
        "Close the image that was opened"},
    {"APP_ImgHead",
        Python_APP_ImgHead,
        METH_VARARGS,
        "The first image loaded into memory"},
    {"APP_ImgTail",
        Python_APP_ImgTail,
        METH_VARARGS,
        "The last image loaded into memory"},
    {"TRACE_Address",
        Python_TRACE_Address,
        METH_VARARGS,
        "Returns Address of trace"
    },
    { "TRACE_BblHead",
        Python_TRACE_BblHead,
        METH_VARARGS,
        "Returns reference to first basic block in trace"
    },
    { "TRACE_AddInstrumentFunction",
        Python_TRACE_AddInstrumentFunction,
        METH_VARARGS,
        "Add trace to program"
    },
    {NULL, NULL, 0, NULL}
};
#endif

    // {"BBL_Address",
    //     Python_BBL_Address,
    //     METH_VARARGS,
    //     "Get first address of a basic block"},