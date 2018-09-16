#pragma once

size_t ExtractFileName(const char *pszSource, char *pszDest);
size_t ExtractFileName(const char *pszSourceDest);
size_t ExtractFileDir(const char *pszSource, char *pszDest);
size_t ExtractFileDir(char *pszSourceDest);

char *va(const char *format, ...);