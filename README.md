python-pin
==========

Python bindings for pin.

#TODO

1. Finish current sub groups
2. Split into multiple files and master pin's makefile schema
3. Continue expanding Pin Python's functionality
4. Read Pythons reference counting information and implement into our Pin tool.

#Build Instructions

Copy the entire directory into ~/pin/source/tools

Type make 

When make completes run ../../../pin -t obj-intel64/Python_Pin.so -- /bin/ls and ensure the output is correct

Enjoy!

#Using the Extension
Most of pin's functionality is exposed via the `pin` module, internal to the pintool. Its implementation is very similar to the way gdb handles python extensions.

To run a specific python script, for example the strace script:
`../../../pin -t obj-intel64/Python_Pin.so -m examples/strace.py -- /bin/ls`


#Current Issues

1. ~~Modifying the Makefile is a huge pain. It needs to be made easier for distribution.~~
    - ~~This means everything has to be in the single, huge cpp file for now. And it has to be named MyPinTool.cpp.~~
    
2. Some Python modules are compiled as shared objects without symbols. These modules can't be loaded from within the python pin tool. (solution is to either not use those modules, or have a custom build of python alongside the pintool)

