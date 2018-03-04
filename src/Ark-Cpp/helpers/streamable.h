

#ifndef STREAMABLE_H
#define STREAMABLE_H

/*************************************************
*
**************************************************/
template<class T> inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; } 
template<class T> inline const char* &operator <<(char &obj, T arg) { strcpy(obj, arg); return obj; } 

#endif