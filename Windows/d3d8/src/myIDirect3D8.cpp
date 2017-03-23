// myIDirect3D8.cpp
#include "stdafx.h"

myIDirect3D8::myIDirect3D8(IDirect3D8 *pOriginal)
{
	m_pIDirect3D8 = pOriginal;  // store the pointer to original object
}

myIDirect3D8::~myIDirect3D8()
{
    
}

HRESULT __stdcall myIDirect3D8::QueryInterface(REFIID riid, void** ppvObj)
{
	*ppvObj = NULL;

	// call this to increase AddRef at original object
	// and to check if such an interface is there

	HRESULT hRes = m_pIDirect3D8->QueryInterface(riid, ppvObj); 

	if (hRes == NOERROR) // if OK, send our "fake" address
	{
		*ppvObj = this;
	}
	
	return hRes;
}

ULONG __stdcall myIDirect3D8::AddRef()
{
	return(m_pIDirect3D8->AddRef());
}

ULONG __stdcall myIDirect3D8::Release()
{
    extern myIDirect3D8* gl_pmyIDirect3D8;

	// call original routine
	ULONG count = m_pIDirect3D8->Release();
	
    // in case no further Ref is there, the Original Object has deleted itself
	// so do we here
	if (count == 0) 
	{
		gl_pmyIDirect3D8 = NULL;
  	    delete(this); 
	}

	return(count);
}

HRESULT __stdcall myIDirect3D8::RegisterSoftwareDevice(void* pInitializeFunction)
{
	return(m_pIDirect3D8->RegisterSoftwareDevice(pInitializeFunction));
}
 
UINT __stdcall myIDirect3D8::GetAdapterCount() 
{
	return(m_pIDirect3D8->GetAdapterCount());
}

HRESULT __stdcall myIDirect3D8::GetAdapterIdentifier(UINT Adapter,DWORD Flags,D3DADAPTER_IDENTIFIER8* pIdentifier) 
{
	return(m_pIDirect3D8->GetAdapterIdentifier( Adapter, Flags, pIdentifier));
}

UINT __stdcall myIDirect3D8::GetAdapterModeCount(UINT Adapter) 
{
	return(m_pIDirect3D8->GetAdapterModeCount(Adapter));
}

HRESULT __stdcall myIDirect3D8::EnumAdapterModes(UINT Adapter,UINT Mode,D3DDISPLAYMODE* pMode) 
{
    return(m_pIDirect3D8->EnumAdapterModes( Adapter, Mode, pMode) );
}

HRESULT __stdcall myIDirect3D8::GetAdapterDisplayMode( UINT Adapter,D3DDISPLAYMODE* pMode) 
{
	return(m_pIDirect3D8->GetAdapterDisplayMode(  Adapter, pMode) );
}

HRESULT __stdcall myIDirect3D8::CheckDeviceType(UINT Adapter,D3DDEVTYPE CheckType,D3DFORMAT DisplayFormat,D3DFORMAT BackBufferFormat,BOOL Windowed) 
{
	return(m_pIDirect3D8->CheckDeviceType( Adapter, CheckType, DisplayFormat, BackBufferFormat, Windowed) );
}

HRESULT __stdcall myIDirect3D8::CheckDeviceFormat(UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,DWORD Usage,D3DRESOURCETYPE RType,D3DFORMAT CheckFormat) 
{
	return(m_pIDirect3D8->CheckDeviceFormat( Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat) );
}

HRESULT __stdcall myIDirect3D8::CheckDeviceMultiSampleType(UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SurfaceFormat,BOOL Windowed,D3DMULTISAMPLE_TYPE MultiSampleType) 
{
	return(m_pIDirect3D8->CheckDeviceMultiSampleType( Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType));
}

HRESULT __stdcall myIDirect3D8::CheckDepthStencilMatch(UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,D3DFORMAT RenderTargetFormat,D3DFORMAT DepthStencilFormat) 
{
	return(m_pIDirect3D8->CheckDepthStencilMatch( Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat));
}

HRESULT __stdcall myIDirect3D8::GetDeviceCaps(UINT Adapter,D3DDEVTYPE DeviceType,D3DCAPS8* pCaps) 
{
	return(m_pIDirect3D8->GetDeviceCaps( Adapter, DeviceType, pCaps));
}

HMONITOR __stdcall myIDirect3D8::GetAdapterMonitor(UINT Adapter) 
{
	return(m_pIDirect3D8->GetAdapterMonitor( Adapter));
}

HRESULT __stdcall myIDirect3D8::CreateDevice(UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice8** ppReturnedDeviceInterface) 
{
	// global var
	extern myIDirect3DDevice8* gl_pmyIDirect3DDevice8;

	// we intercept this call and provide our own "fake" Device Object
	HRESULT hres = m_pIDirect3D8->CreateDevice( Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, ppReturnedDeviceInterface);
    
	// Create our own Device object and store it in global pointer
	// note: the object will delete itself once Ref count is zero (similar to COM objects)
	gl_pmyIDirect3DDevice8 = new myIDirect3DDevice8(*ppReturnedDeviceInterface);
	
	// store our pointer (the fake one) for returning it to the calling progam
	*ppReturnedDeviceInterface = gl_pmyIDirect3DDevice8;

	return(hres); 
}
