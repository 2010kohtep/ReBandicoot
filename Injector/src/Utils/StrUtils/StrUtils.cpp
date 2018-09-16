#include "StrUtils.h"

#ifndef _CRT_SECURE_NO_WARNINGS
	#define _CRT_TEMP_DISABLE
	#define _CRT_SECURE_NO_WARNINGS
#endif

#include <string>
#include <stdarg.h> // va_start, va_end

size_t ExtractFileName(const char *pszSource, char *pszDest)
{
	if (pszSource == 0)
		return 0;

	char* p = (char*)pszSource;
	p = strchr(p, '\0');
	p = (char*)strrchr(pszSource, '\\');

	if (p == nullptr)
		return 0;

	strcpy(pszDest, p + 1);
	return strlen(pszDest);
}

size_t ExtractFileName(char *pszSourceDest)
{
	return ExtractFileName(pszSourceDest, pszSourceDest);
}

size_t ExtractFileDir(const char* pszSource, char *pszDest)
{
	if (pszSource == 0 || pszDest == 0)
	{
		return 0;
	}

	if (pszSource != pszDest)
	{
		strcpy(pszDest, pszSource);
	}

	char* p = (char*)pszDest;
	p = strchr(p, '\0');
	p = (char*)strrchr(pszDest, '\\');

	if (p == nullptr)
	{
		return 0;
	}

	p++;
	*p = '\0';

	return strlen(pszDest);
}

size_t ExtractFileDir(char *pszSourceDest)
{
	return ExtractFileDir(pszSourceDest, pszSourceDest);
}

char *va(const char *fmt, ...)
{
	va_list arg;
	static int nCur = 0;
	static char c_szStrings[16][1024];

	nCur = (nCur + 1) % 16;

	va_start(arg, fmt);
	vsnprintf(c_szStrings[nCur], _countof(c_szStrings[nCur]), fmt, arg);
	va_end(arg);

	return c_szStrings[nCur];
}

#ifdef _CRT_TEMP_DISABLE
	#undef _CRT_TEMP_DISABLE
	#undef _CRT_SECURE_NO_WARNINGS
#endif