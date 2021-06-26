#include "Shader.h"

Shader::Shader()
{

}

Shader::Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
{
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;

    // ifstream 객체들이 예외를 던질 수 있도록 합니다.
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        // 파일 열기
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // stream에 파일의 버퍼 내용을 읽기
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // 파일 핸들러 닫기
        vShaderFile.close();
        fShaderFile.close();
        // stream을 string으로 변환
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();

    unsigned int vertex, fragment;

    int success;

    char infoLog[512];

    // vertex Shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    // 오류가 발생한다면 컴파일 오류를 출력
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };

    // Fragment shader도 마찬가지


    fragment = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    // 오류가 발생한다면 컴파일 오류를 출력
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    };


    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    // 오류가 발생한다면 링킹 오류를 출력
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // program 내부에서 shader들이 링크 완료되었다면 이제 필요 없으므로 shader들을 삭제
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::Use()
{
    glUseProgram(ID);
}

void Shader::SetBool(const std::string& name, bool value) const
{

}

void Shader::SetInt(const std::string& name, int value) const
{
}

void Shader::SetFloat(const std::string& name, float value) const
{
}
