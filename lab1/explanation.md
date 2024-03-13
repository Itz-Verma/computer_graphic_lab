## graphics.h:
Header file which provides acess to simple graphics library that helps us to draw differnt shapes, text, images and so on, on the screen.

## DETECT:
Macro of graphics.h library that instruct compiler for auto detection of graphics driver. It sets graphicsDriver.

## graphicsDriver:
It is a variable which store a interger which points to a graphics driver and tells compiler  that what graphics driver to use.

## graphicsMode:
It is a variable which store a interger which points to the mode in which the graphics driver has to be used.

## graphicsDriverDirectoryPath:
It specifies the directory path where the graphics driver file (BGI files) are located. If working with turbo C++ the path may be __C://turboc3//bgi or C://tc//bgi__. In our case the we links the files at compile time.

## initgraph(int* gd, int* gm, char* path):
This fuction initialize graph and it takes three arguments, 1st argument is the address of graphicsDriver, 2nd is address of graphicsMode and last one the path where BGI files are present.It sets graphicsMode and  returns nothing(void).

## delay(int millisecs):
The fuctions pauses the computation for the specified number of milliseconds. It returns nothing.

## closegraph(int wid=ALL_WINDOWS):
Deallocates all memory allocated by the graphics system, then restore the screen to the mode it was in before initgraph(). If we don't passes the argument it will close all window and it returns nothing.
