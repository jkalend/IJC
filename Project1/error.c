//
// Created by kalen on 2022-03-14.
//

#include "error.h"

void warning_msg(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    fprintf(stderr, "Chyba: ");
    vfprintf(stderr, fmt, args);
    va_end(args);
}

void error_exit(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    fprintf(stderr, "Chyba: ");
    vfprintf(stderr, fmt, args);
    va_end(args);

    exit(1);
}
