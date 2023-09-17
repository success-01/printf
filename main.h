#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdarg.h>
#include <string.h>

/**
 * struct convert - symbols structure and functions is defined
 *
 * @sym: Operator
 * @f: Associated function
 */

struct convert
{
	char *sym;
	int (*f)(va_list);
};

typedef struct convert conver_t;

/*Main functions*/

int _printf(const char *format, ...);
int parser(const char *format, conver_t f_list[], va_list arg_list);

#endif
