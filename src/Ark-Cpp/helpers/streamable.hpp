

#ifndef STREAMABLE_HPP
#define STREAMABLE_HPP

#if ARDUINO >= 100

/*************************************************
* **ARDUINO ONLY** Stream object to Serial
**************************************************/
template<class T> inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; }

#else

/*************************************************
* Stream const char* (cstring) to const char*
**************************************************/
template<class T> inline const char* &operator <<(char &obj, T arg) { strcpy(obj, arg); return obj; } 

#endif

#endif
