#ifndef FFGLShader_H
#define FFGLShader_H

#include <FFGL.h>
#include <FFGLExtensions.h>
#include <string>

class FFGLShader
{
public:
	FFGLShader();
	virtual ~FFGLShader();

	void SetExtensions(FFGLExtensions *e);

	int IsReady();
	
	int Compile(const char *vtxProgram, const char *fragProgram);	
	int Compile(const std::string& vtxProgram, const std::string& fragProgram);

	GLuint FindUniform(const char *name);
	int BindShader();
	int UnbindShader();
	void FreeGLResources();

private:
	FFGLExtensions *m_extensions;
	GLenum m_glProgram;
	GLenum m_glVertexShader;
	GLenum m_glFragmentShader;
	GLuint m_linkStatus;

	void CreateGLResources();
};

#endif
