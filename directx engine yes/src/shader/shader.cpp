#include "shader.hpp"

namespace dx_engine {
    HRESULT dx_engine::shader_t::compile_shader( std::string file, std::string entry, std::string model, ID3DBlob** out ) {
        ID3DBlob* err;
        HRESULT result = D3DCompileFromFile(
            std::wstring( file.begin( ), file.end( ) ).c_str( ),
            nullptr,
            nullptr,
            entry.c_str( ),
            model.c_str( ),
            D3DCOMPILE_ENABLE_STRICTNESS,
            0,
            out,
            &err );

        if ( FAILED( result ) ) 
        {
            const char* err_msg = nullptr;
            if ( result == HRESULT_FROM_WIN32( ERROR_FILE_NOT_FOUND ) )
                err_msg = "Couldn't find the shader file (same directory?)";
            else if ( err )
            {
                err_msg = ( const char* )err->GetBufferPointer( );
                err->Release( );
            }

            MessageBoxA( nullptr, err_msg, "Shader Compiler", 0 );
            return E_NOTIMPL;
        }
        
        return result;
    }
    HRESULT shader_t::create_input_layout( ) {
        return E_NOTIMPL;
    }
} 