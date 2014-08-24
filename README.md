python-pin
==========

Python bindings for pin.

#TODO

1. Finish current sub groups
2. Split into multiple files and master pin's makefile schema
3. Continue expanding Pin Python's functionality

###Install Instructions

1 Install Python-Dev via apt-get istall python-dev

2 Copy python_tool.cpp into ~/pin/source/tools/MyPinTool/MyPinTool.cpp and python_pin.h into that directory as well

3 Copy lel.py into above directory

4 Locate "unistd_64.h" and change directory in lel.py accordignly

5 Navigate to  ~/pin/source/tools/Config/makefile.unix.config and append -lpython2.7 -I/usr/include/python2.7 -rdynamic  to the back of TOOL_LIBS := -lpin -lxed 
