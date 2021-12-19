# FT_PRINTF
![](https://img.shields.io/badge/Language-C-blue)
![](https://img.shields.io/badge/School-42-black)
### I. How to use ft_printf in you project:

Clone repository

	git clone https://github.com/vscabell/ft_printf.git

Compile and include

	#include "libftprintf.h" in your project
	run make to compile libftprintf.a
	link you binary with -L. -lftprintf flag

### II.  The Function:

ft_printf writes the C string pointed by format to the standard output (stdout). If format includes format specifiers (subsequences beginning with %), the additional arguments following format are formatted and inserted in the resulting string replacing their respective specifiers.

prototype: **int ft_printf ( const char *format, ... )**;

| Specifier | Description |
| ------------ | ------------ |
|**c**| character|
|**s**|	NULL - terminated string|
|**p**|	pointer memory address|
|**d**| signed decimal base|
|**i**|	signed decimal base|
|**u**|	unsigned decimal base|
|**x**|	unsigned hex base (lowercase)|
|**X**|	unsigned hex base (uppercase)|
|**%**|	'%' char literal|

| Flag | Description |
| ------------ | ------------|
|**-**|	left-justify within he given field width; right justification is the default|
|**0**|	left-pads the number with zeroes (0) instead of spaces when padding is specified|

| Width| Description |
| ------------ | ------------ |
|**(number)**|Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger.|
|*|The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.|

| Precision | Description |
| ------------ | ------------ |
|**.number**|For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6). For g and G specifiers: This is the maximum number of significant digits to be printed. For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for precision, 0 is assumed.|
|*|The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.|

> Reference: https://www.cplusplus.com/reference/cstdio/printf/?kw=printf
