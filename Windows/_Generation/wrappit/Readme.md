## Wrappit  
Author: Michael Chourdakis  
May 14, 2007  
  
  
# Description  
Wrappit is an automatic proxy DLL generator for 32-bit DLLs.  
  
For more info, see the documentation in the /docs directory.  
  
# Usage  
```
WRAPPIT <dll> <txt> <convention> <point dll name> <cpp> <def>  
```  
  
For more info on usage, see the documentation in the /docs directory.  
  
# Compiling  
To compile, open the Visual Studio Developer Command Prompt, navigate to the project directory, and use this command:  

```
md build & md bin & cl.exe /EHsc /I include /Fobuild\wrappit.obj /Febin/wrappit.exe src\wrappit.cpp /link /LIBPATH:lib  
```
  
The compiled executable will be in the newly-created /bin directory.  

Generated DLLs will be compiled and linked using VC++ by default. To compile and link DLLs with BC++ instead, use this command to compile wrappit:  

```
md build & md bin & cl.exe /EHsc /D_USE_BCPP_ /I include /Fobuild\wrappit.obj /Febin/wrappit.exe src\wrappit.cpp /link /LIBPATH:lib  
```  
  
  
# Important Information  
* This won't work for creating 64-bit DLLs (In-line assembly isn't supported on x64), and it is recommended to use Lin Min's DLL Wrapper Generator instead (located in ../DLL Wrapper Gen).  
* The files in the /include and /lib directories are shared library files and should only be used if issues are encountered when using default the directories (C:\Program Files (x86)\Windows Kits\*); an example is that cl.exe can have issues locating the default directories if the user has certain other things installed.  



