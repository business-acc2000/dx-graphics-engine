#pragma once

#include <Windows.h>
#include <memory>

namespace dx_engine {
    struct engine_symbols_t
    {
        HWND window = nullptr;
        bool is_running = true;

        int width = 800;
        int height = 600;

        // Common and useful practice, could always add more variables
    };
    class engine_t {
       public:
        std::shared_ptr< engine_symbols_t > symbols;

        engine_t( );
        bool initialize( HINSTANCE ins );
        void run( );

        static LRESULT CALLBACK callback( HWND win, UINT msg, WPARAM w_param, LPARAM l_param );
       private:
        void update( float delta_time );
        void render( );
    };
}; 