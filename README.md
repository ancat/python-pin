python-pin
==========

Python bindings for pin.

#TODO

1. Finish current sub groups
2. Split into multiple files and master pin's makefile schema
3. Continue expanding Pin Python's functionality

#Build Instructions

Copy the entire directory into ~/pin/source/tools

Type make 

When make completes run ../../../pin -t obj-intel64/Python_Pin.so -- /bin/ls and ensure the output is correct

Enjoy!


#Current Issues

~~1. Modifying the Makefile is a huge pain. It needs to be made easier for distribution.
    - This means everything has to be in the single, huge cpp file for now. And it has to be named MyPinTool.cpp.~~
    
2. Some Python modules are compiled as shared objects without symbols. These modules can't be loaded from within the python pin tool. (solution is to either not use those modules, or have a custom build of python alongside the pintool)

