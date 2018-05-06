#ifndef UTIL_H
#define UTIL_H

#define STRING_VAR_DECL(s) char s##_str[] PROGMEM = #s;

#define STRING_VAR(s) s##_str

#endif
