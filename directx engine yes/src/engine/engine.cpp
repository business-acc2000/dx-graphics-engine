#include "engine.hpp"

namespace dx_engine {
    dx_engine::engine_t::engine_t( ) : symbols( std::make_shared< engine_symbols_t >( ) )
    {
    }
    bool engine_t::initialize( HINSTANCE ins ) {
        WNDCLASSEX wc;
        ZeroMemory( &wc, sizeof( wc ) );

        wc.cbSize = sizeof( WNDCLASSEX );
        wc.style = CS_OWNDC;
        wc.lpfnWndProc = callback;
        wc.hInstance = ins;
        wc.lpszClassName = L"dx_engine";

        HWND win = CreateWindowEx(
            NULL, wc.lpszClassName, L"engine", WS_OVERLAPPEDWINDOW, 0, 0, 800, 600, nullptr, nullptr, nullptr, nullptr );

        symbols->window = win;

        if ( !win ) {
            MessageBoxA( nullptr, "Error", "Cannot create a window handle [CreateWindowEx]", 0 );
            return false;
        }

        this->run( );
        return true;
    }
    void engine_t::run( ) {
        bool done = false;
        while ( !done ) 
        {
            MSG msg;
            while ( PeekMessage( &msg, nullptr, 0, 0, PM_REMOVE ) ) {
                TranslateMessage( &msg );
                DispatchMessage( &msg );
                if ( msg.message = WM_QUIT )
                    done = true;
            }

            if ( done ) 
            {
                symbols->is_running = false;
                break;
            }

            this->render( );

        }
    }
    LRESULT engine_t::callback( HWND win, UINT msg, WPARAM w_param, LPARAM l_param ) {
        PAINTSTRUCT ps;
        HDC hdc;

        switch ( msg ) 
        {
            case WM_PAINT: 
            {
                hdc = BeginPaint( win, &ps );
                EndPaint( win, &ps );
                break;
            }
            case WM_DESTROY: 
            {
                PostQuitMessage( NULL );
                break;
            }
            case WM_SYSCOMMAND: 
            {
                if ( ( w_param & 0xfff0 ) == SC_KEYMENU )
                    return EXIT_SUCCESS;

                break;
            }
        }

        return DefWindowProc( win, msg, w_param, l_param );
    }
    void engine_t::update( float delta_time ) {
    }
    void engine_t::render( ) {
    }
}