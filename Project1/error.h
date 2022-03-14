//
// Created by kalen on 2022-03-14.
//
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef IJC_ERROR_H
#define IJC_ERROR_H

void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);

#endif //IJC_ERROR_H
