#ifndef __android_opengl_GLUtils_GLUtils__
#define __android_opengl_GLUtils_GLUtils__

#include "Bitmap.h"

struct _JNIEnv;
typedef _JNIEnv JNIEnv;

class _jclass;
typedef _jclass* jclass;

namespace android_opengl_GLUtils
{
	class GLUtils
	{
	public:
		GLUtils();
		static int InitJNI(JNIEnv* env);
		static void texImage2D(int target, int level, android_graphics_Bitmap::Bitmap bitmap, int border);
	private:
		static JNIEnv* _env;
		static jclass _jcGlUtils;
		static jmethodID _mTexImage2D;
	};
}

#endif