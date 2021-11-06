#include <userlibc.h>
#include <stdarg.h>
#include <stdint.h>
#include <syscalls.h>
#include <stdlib.h>

#define BUFFER_SIZE 32

#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define CLOCK_HOURS 7
#define CLOCK_MINUTES 4
#define CLOCK_SECONDS 2

static char *buffer[BUFFER_SIZE] = {0};

static char hexArray[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

char *numToStr(unsigned long int num, int base)
{
	cleanBuffer();
	char aux = num % base;
	int i = BUFFER_SIZE;
	buffer[i] = 0;
	if (num == 0)
		buffer[i--] = '0';
	while (i >= 0 && num > 0)
	{
		aux = num % base;
		buffer[i] = hexArray[aux];
		i--;
		num /= base;
	}

	//aca antes estaba asi:     return buffer+i+1;
	return *(buffer + i + 1);
}

int strToNum(char *str)
{
	int num = 0;

	for (int i = 0; str[i]; i++)
	{
		num *= 10;
		if (str[i] < '0' || str[i] > '9') //no es un numero valido
			return -1;
		num += str[i] - '0';
	}
	return num;
}

int string_compare(const char *s1, const char *s2)
{
	int i;
	for (i = 0; s1[i] == s2[i]; i++)
	{
		if (s1[i] == '\0')
			return 0;
	}
	return s1[i] - s2[i];
}

int scanf(char *str, ...)
{
	va_list vl;
	int i = 0, j = 0, ret = 0;
	char buff[100] = {0}, c; //tmp[20] no se usa
	char *out_loc;
	while (c)
	{
		if (sys_read(STDIN, &c, 1))
		{
			buff[i] = c;
			i++;
		}
	}
	va_start(vl, str);
	i = 0;
	while (str && str[i])
	{
		if (str[i] == '%')
		{
			i++;
			switch (str[i])
			{
			case 'c':
			{
				*(char *)va_arg(vl, char *) = buff[j];
				j++;
				ret++;
				break;
			}
			case 'd':
			{
				*(int *)va_arg(vl, int *) = strtol(&buff[j], &out_loc, 10);
				j += out_loc - &buff[j];
				ret++;
				break;
			}
			case 'x':
			{
				*(int *)va_arg(vl, int *) = strtol(&buff[j], &out_loc, 16);
				j += out_loc - &buff[j];
				ret++;
				break;
			}
			}
		}
		else
		{
			buff[j] = str[i];
			j++;
		}
		i++;
	}
	va_end(vl);
	return ret;
}

void printf(char *string, ...)
{
	int i = 0, argumentCount = 0;
	while (string[i])
	{
		if (string[i] == '%')
			argumentCount++;
		i++;
	}
	va_list list;
	va_start(list, argumentCount);
	while (*string)
	{
		if (*string == '\'')
		{
			string++;
			sys_write(STDOUT, string, 1);
			string++;
		}
		else if (*string != '%')
		{
			sys_write(STDOUT, string, 1);
			string++;
		}
		else
		{
			string++;
			switch (*string)
			{
			case 'd':
				printDec(va_arg(list, int));
				break;
			case 'c':
				putChar(va_arg(list, int));
				break;
			case 's':
				printf(va_arg(list, int));
				break;
			default:
				break;
			}
			string++;
		}
	}
	va_end(list);
}

uint8_t getChar()
{
	uint8_t c;
	sys_read(STDIN, &c, 1);
	return c;
}

void putChar(uint8_t c)
{
	sys_write(STDOUT, &c, 1);
}

void printDec(int num)
{
	printf(numToStr(num, 10));
}

void printHex(int num)
{
	printf(numToStr(num, 16));
}

void cleanBuffer()
{
	for (int i = 0; i < BUFFER_SIZE; i++)
	{
		buffer[i] = 0;
	}
}

uint8_t getHours()
{
	return sys_clock(CLOCK_HOURS);
}

uint8_t getMinutes()
{
	return sys_clock(CLOCK_MINUTES);
}

uint8_t getSeconds()
{
	return sys_clock(CLOCK_SECONDS);
}

void clear()
{
	for (int i = 0; i < 25; i++)
	{
		printf("\n");
	}
}