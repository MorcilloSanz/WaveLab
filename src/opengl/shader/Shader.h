#pragma once

#include <iostream>
#include <string>

#include "../../../glew/glew.h"

/*
    TODO: Add uniforms to ShaderProgram
*/

class Shader {
public:
    enum class ShaderType {
        None, Vertex, Fragment
    };
private:
    std::string code, filePath;
    ShaderType shaderType;
    unsigned int shaderID;
private:
    Shader(const std::string& _code, const ShaderType& _shaderType);
    static std::string readFile(const std::string& path);
    void compileShader();
public:
    Shader();
    ~Shader() = default;
    Shader(const Shader& shader);
    Shader(Shader&& shader) noexcept;
    Shader& operator=(const Shader& shader);
public:
    inline static Shader fromFile(const std::string& filePath, const ShaderType& shaderType) {
        return Shader(readFile(filePath), shaderType);
    }

    inline static Shader fromCode(const std::string& code, const ShaderType& shaderType) {
        return Shader(code, shaderType);
    }

    inline void deleteShader() {
        glDeleteShader(shaderID);
    }
public:
    inline std::string& getCode() {
        return code;
    }

    inline unsigned int getShaderID() const {
        return shaderID;
    }

    inline ShaderType& getShaderType() {
        return shaderType;
    }
};

class ShaderProgram {
private:
    unsigned int shaderProgramID;
    Shader vertexShader, fragmentShader;
public:
    ShaderProgram(const Shader& _vertexShader, const Shader& _fragmentShader);
    ShaderProgram();
    ShaderProgram(const ShaderProgram& shaderProgram);
    ShaderProgram(ShaderProgram&& shaderProgram) noexcept;
    ~ShaderProgram();
    ShaderProgram& operator=(const ShaderProgram& shaderProgram);
private:
    void link();
public:
    inline void useProgram() {
        glUseProgram(shaderProgramID);
    }

    inline unsigned int getShaderProgramID() const {
        return shaderProgramID;
    }

    inline Shader& getVertexShader() {
        return vertexShader;
    }

    inline Shader& getFragmentShader() {
        return fragmentShader;
    }
};