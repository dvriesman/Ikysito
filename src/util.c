#include "util.h"

unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count)
{
  int i;
  for (i=0; i<count;i++) dest[i]=src[i];
  return dest;
}

unsigned char *memset(unsigned char *dest, unsigned char val, int count)
{
  int i;
  for (i=0; i<count;i++) dest[i]=val;
  return dest;
}

unsigned char *memsetA(void *dest, char val, int count) {

    char* temp = (char *) dest;
    for(;count !=0; count--) *temp++ = val;
    return dest;

}


unsigned short *memsetw(unsigned short *dest, unsigned short val, int count)
{
  int i;
  for (i=0; i<count;i++) dest[i]=val;
  return dest;
}

int strlen(const char *str)
{
  int i;
  for (i=0;;i++) if (str[i] == '\0') return i;
}

/* We can use this for reading from the I/O ports to get data from
*  devices such as the keyboard. We are using what is called 'inline
*  assembly' in these routines to actually do the work. [XXX I still
*  have to add devices to the tutorial] */
unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

/* We can use this to write to I/O ports to send bytes to
*  devices. Again, we use some inline assembly for the stuff that
*  simply cannot be done in C */
void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));

}

int strcmp(const char *p, const char *q)
{
	while (*p && *p == *q)
		p++, q++;

	return (unsigned char) *p - (unsigned char) *q;
}
