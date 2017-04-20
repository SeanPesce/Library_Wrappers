// Author: Sean Pesce
// Original d3d9.dll wrapper by Michael Koch

#pragma once

// Exported function
IDirect3D9* WINAPI Direct3DCreate9 (UINT SDKVersion);

// regular functions
void InitInstance(HANDLE hModule);
void ExitInstance(void);
void LoadOriginalDll(void);