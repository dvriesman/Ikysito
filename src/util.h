#ifndef __UTIL_H
#define __UTIL_H

int strcmp(const char *p, const char *q);


extern unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count);
extern unsigned char *memset(unsigned char *dest, unsigned char val, int count);

extern unsigned char *memsetA(void *dest, char val, int count);


extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);
extern int strlen(const char *str);

extern unsigned char inportb (unsigned short _port);
extern void outportb (unsigned short _port, unsigned char _data);


#endif
