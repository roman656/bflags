/*
 * bflags (Flags library).
 * Copyright (C) 2020 Roman S <romanstrah@mail.ru>
 * 
 * bflags is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * bflags is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BFLAGS_H_INCLUDED
#define BFLAGS_H_INCLUDED

/*-----------Библиотеки-начало----------*/
#include <stdio.h>
/*-----------Библиотеки-конец-----------*/

/*----------Перечисления-начало---------*/
typedef enum FlagsValues
{
	NONE,                                           //0000 0000
	F0,                                             //0000 0001
	F1 = 1 << 1,                                    //0000 0010
	F2 = 1 << 2,                                    //0000 0100
	F3 = 1 << 3,                                    //0000 1000
	F4 = 1 << 4,                                    //0001 0000
	F5 = 1 << 5,                                    //0010 0000
	F6 = 1 << 6,                                    //0100 0000
	F7 = 1 << 7,                                    //1000 0000
	ALL = F0 | F1 | F2 | F3 | F4 | F5 | F6 | F7     //1111 1111
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
/*----------Перечисления-конец----------*/

/*-----------Структуры-начало-----------*/
typedef struct Flags
{
	unsigned char flags;
} Flags;
/*------------Структуры-конец-----------*/

/*-------Функции/процедуры-начало-------*/
short writeDecNumberInSystemN(unsigned int number, char* output, unsigned int outputLength, unsigned short system);
void fprintFlags(FILE* filestream, Flags* target, PrintStyle style);
void printFlags(Flags* target, PrintStyle style);
void flagsSetOn(Flags* target);
void flagsSetOff(Flags* target);
void setOnExactFlags(Flags* target, FlagsValues flags);
void setOffExactFlags(Flags* target, FlagsValues flags);
short isSetOnExactFlags(Flags* target, FlagsValues flags);
short isSetOffExactFlags(Flags* target, FlagsValues flags);
/*--------Функции/процедуры-конец-------*/

#endif // BFLAGS_H_INCLUDED