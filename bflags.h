#ifndef WFLAGS_H_INCLUDED
#define WFLAGS_H_INCLUDED

#include <stdio.h>

typedef enum FlagsValues
{
	NONE,											//0000 0000
	F0,												//0000 0001
	F1 = 1 << 1,									//0000 0010
	F2 = 1 << 2,									//0000 0100
	F3 = 1 << 3,									//0000 1000
	F4 = 1 << 4,									//0001 0000
	F5 = 1 << 5,									//0010 0000
	F6 = 1 << 6,									//0100 0000
	F7 = 1 << 7,									//1000 0000
	ALL = F0 | F1 | F2 | F3 | F4 | F5 | F6 | F7		//1111 1111
} FlagsValues;

typedef enum PrintStyle
{
	TABLE,
	BINARY,
	TERNARY,
	QUATERNARY,
	QUINARY,
	SENARY,
	SEPTENARY,
	OCTAL,
	NONARY,
	DECIMAL,
	UNDECIMAL,
	DUODECIMAL,
	TRIDECIMAL,
	TETRADECIMAL,
	PENTADECIMAL,
	HEXADECIMAL,
	HEPTADECIMAL,
	OCTODECIMAL,
	ENNEADECIMAL,
	VIGESIMAL
} PrintStyle;

typedef struct Flags
{
	unsigned char flags;
} Flags;

short writeDecNumberInSystemN(unsigned int number, char* output, unsigned int outputLength, unsigned short system);
void fprintFlags(FILE* filestream, Flags* target, PrintStyle style);
void printFlags(Flags* target, PrintStyle style);
void flagsSetOn(Flags* target);
void flagsSetOff(Flags* target);
void setOnExactFlags(Flags* target, FlagsValues flags);
void setOffExactFlags(Flags* target, FlagsValues flags);
short isSetOnExactFlags(Flags* target, FlagsValues flags);
short isSetOffExactFlags(Flags* target, FlagsValues flags);

#endif // WFLAGS_H_INCLUDED