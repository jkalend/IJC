// error.h
// Řešení IJC-DU1, příklad b), 16.3.2022
// Autor: Jan Kalenda, FIT
// Přeloženo: gcc 11.2


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef IJC_ERROR_H
#define IJC_ERROR_H

void warning_msg(const char *fmt, ...);
void error_exit(const char *fmt, ...);

#endif //IJC_ERROR_H
