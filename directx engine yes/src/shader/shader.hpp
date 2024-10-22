#pragma once

#include "../renderer/renderer.hpp"
#include <string>

namespace dx_engine {
    class shader_t {
       public:
        HRESULT compile_shader( std::string file, std::string entry, std::string model, ID3DBlob** out );
        HRESULT create_input_layout( );
    };
} 