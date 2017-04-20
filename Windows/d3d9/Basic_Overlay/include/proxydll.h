// Author: Sean Pesce
// Original d3d9.dll wrapper by Michael Koch

#pragma once

#include <d3dx9core.h>

// Data structures for the text overlay:
D3DRECT text_background;
RECT text_box;
RECT text_shadow_box;
RECT text_outline_boxes[8];
ID3DXFont* SP_font = NULL;
TCHAR *SP_font_name = "Arial";

// Constants & Variables:
bool font_initialized = false;
int overlay_text_type;
extern const char *example_overlay_text;
const char *example_overlay_text = "Example overlay by Sean Pesce";

// Exported function
IDirect3D9* WINAPI Direct3DCreate9 (UINT SDKVersion);

// Regular functions
void InitInstance(HANDLE hModule);
void ExitInstance(void);
void LoadOriginalDll(void);