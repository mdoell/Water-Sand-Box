#ifndef _glfonth_
#define _glfonth_

//*********************************************************
//GLFONT.H -- Header for GLFONT.CPP
//Copyright (c) 1998 Brad Fish
//Copyright (c) 2002 Henri Kyrki
//See glFont.txt for terms of use
//10.5 2002
//*********************************************************

#ifndef TRUE
#define TRUE	1
#endif

#ifndef FALSE
#define FALSE	0
#endif

#include <string>
#include <GL/gl.h>

using namespace std;

namespace GLFontError {
	struct InvalidFile{};
	struct InvalidFont{};
}

class GLFontBase {
public:
	GLFontBase();
	void Begin();
	virtual ~GLFontBase();
protected:

	void CreateImpl(const string &FileName, GLuint Tex, bool PixelPerfect = FALSE);

	typedef struct
	{
	union {
		float dx;
		int width;
	};
	union {
		float dy;
		int height;
	};
	float tx1, ty1;
	float tx2, ty2;
	} GLFONTCHAR;

	typedef struct

	{
	int Tex;
	int TexWidth, TexHeight;
	int IntStart, IntEnd;
	GLFONTCHAR *Char;
	} GLFONT;

	GLFONT Font;
	bool ok;
private:
	void FreeResources();
};

class GLFont : public GLFontBase {
public:
	GLFont();
	void Create(const string &FileName, GLuint Tex);
	void TextOut (string String, float x, float y, float z);
	float GetCharsHeight();
	float GetPixelHeight();
};

class PixelPerfectGLFont : public GLFontBase {
public:
	PixelPerfectGLFont();
	void Create(const string &FileName, GLuint Tex);
	void TextOut (string String, int x, int y, int z);
	float GetCharsHeight();
	float GetPixelHeight();
};

#endif
//End of file


