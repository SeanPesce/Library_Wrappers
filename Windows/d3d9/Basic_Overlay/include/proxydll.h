// Author: Sean Pesce
// Original d3d9.dll wrapper by Michael Koch

#pragma once

#include <d3dx9core.h>


// Constants & Variables:
extern const char *example_overlay_text;
const char *example_overlay_text = "Example overlay by Sean Pesce";

// Exported function
IDirect3D9* WINAPI Direct3DCreate9 (UINT SDKVersion);

// Regular functions
void InitInstance(HANDLE hModule);
void ExitInstance(void);
void LoadOriginalDll(void);