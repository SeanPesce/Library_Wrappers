## dinput8.dll proxy  
Made by Google  
Mar 15, 2013  
  
DirectX® up through version 11 uses the old dinput8 dynamic-link library.  

This is a complete proxy of all internal structs and virtual table methods within the .dll, not just the exported functions. This means IDirectInput and IDirectInputDevice methods have been implemented with proxy calls.  

The proxy calls for exported functions are done using the system path to retrieve dinput8.dll.  

Everything is written in pure C.  
  
# Significance  

A proxy .dll allows one to write hacks for a video game, among other things.  

By proxying dinput8.dll, all keyboard and mouse functions are directly hooked making it easy to write hacks such as macros and bots.  

Of course, if you want to use other DirectX functions, just load the libraries.  
  
# Usage  

The files included are a bare bones minimum proxy, as hacks generally must be written for use with a specific game. Implement proxy_IDirectInputDevice_GetDeviceData() to read macro/log files, edit memory offsets, and execute commands.  
  
```c
  
\#include "dinputproxy.h"  
  
  
HRESULT STDMETHODCALLTYPE proxy_IDirectInputDevice_GetDeviceData(struct IDirectInputDevice *idid, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags) { proxy_IDirectInputDevice *proxydid = (proxy_IDirectInputDevice *)idid; DIDEVICEOBJECTDATA data[128]; DWORD dwCount; HRESULT ret;  
  
// hack here  
if (proxydid->bKeyboard)  
    ret = proxydid->did->lpVtbl->GetDeviceData(proxydid->did, sizeof(data[0]), data, &dwCount, 0);  
else if (proxydid->bMouse)  
    ret = proxydid->did->lpVtbl->GetDeviceData(proxydid->did, sizeof(data[0]), data, &dwCount, 0);  
else  
    ret = proxydid->did->lpVtbl->GetDeviceData(proxydid->did, cbObjectData, rgdod, pdwInOut, dwFlags);  
  
return ret;  
}  
```
  
# Disclaimer  

All implementation details besides empty proxy calls written from scratch. DirectX® is a registered trademark of Microsoft.  
  
  
# Source  
https://code.google.com/archive/p/dinput-proxy-dll/  
