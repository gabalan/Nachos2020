//
// Created by nlesne on 10/10/2019.
//

#ifndef VSPRINTF_H
#define VSPRINTF_H

#include <stdarg.h>

typedef unsigned int	size_t;

int vsprintf(char *buf, const char *fmt, va_list args);
int sprintf(char *buf, const char *fmt, ...);
int printf(const char* format, ...);

#endif //VSPRINTF_H
