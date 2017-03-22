## Wrappit  
Made by Michael Chourdakis  
  
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
  
  
NOTE: This won't work for creating proxy DLLs for 64-bit DLLs. You can try editing the final generated .cpp file and changing every jmp [n*4] instruction to jmp [n*8] instead.  
  
NOTE: The files in the /include and /lib directories are shared library files, but cl.exe can have issues locating their default directories (C:\Program Files (x86)\Windows Kits\*) if the user has certain other things installed. For this reason, these shared files have been included in the local directory to avoid issues.  



