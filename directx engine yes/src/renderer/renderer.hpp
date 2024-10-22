#pragma once

#pragma region directx includes

#include <d3d11_1.h>
#pragma comment( lib, "d3d11.lib" )

#include <d3dcompiler.h>
#pragma comment( lib, "d3dcompiler.lib" )

#pragma endregion

#include <wrl/client.h>
#include <memory>

using namespace Microsoft::WRL;

namespace dx_engine
{
    class renderer_symbols_t 
	{
        ComPtr< ID3D11Device > base_device;
        ComPtr< ID3D11DeviceContext > base_context;
		ComPtr< ID3D11Device1 > device;
        ComPtr< ID3D11DeviceContext1 > context;
		ComPtr< ID3D11RenderTargetView > render_target_view;

		ComPtr< IDXGIAdapter > dxgi_adapter;
		ComPtr< IDXGIDevice1 > dxgi_device;
		ComPtr< IDXGISwapChain1 > dxgi_swap_chain;
        ComPtr< IDXGIFactory2 > dxgi_factory;
	};
	class renderer_t {
       public:
        std::shared_ptr< renderer_symbols_t > symbols;
        renderer_t( );


	};
}