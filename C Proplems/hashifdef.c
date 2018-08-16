#include <stdio.h>
#include "typedefs.h"

#define x
void main (void) {
#ifdef x
printf("HELLO1\n");
#else
printf("HELLO2\n");
#endif
}