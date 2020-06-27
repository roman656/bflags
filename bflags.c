#include "bflags.h"

short writeDecNumberInSystemN(unsigned int number, char* output, unsigned int outputLength, unsigned short system)
{
	/* Обработка ошибок во входных параметрах. */
	if ((system < 2) || (system > 20) || (output == NULL) || (outputLength < 2) || (number < 0))
	{
		return -1;
	}

	/* Инициализация результата. */
	for (unsigned int i = 0; i < outputLength - 1; i++)
	{
		output[i] = '0';
	}
	output[outputLength - 1] = '\0';

	/* Вычисление результата. */
	unsigned int divRemainder;
    for (unsigned int i = outputLength - 2; number > 0; i--)
    {
		if (i < 0)    // Место для записи результата кончилось.
		{
			return -2;
		}
    	divRemainder = number % system;
        number /= system;
    	switch (divRemainder)
		{
			case 10:
			{
				output[i] = 'A';
				break;
			}
			case 11:
			{
				output[i] = 'B';
				break;
			}
			case 12:
			{
				output[i] = 'C';
				break;
			}
			case 13:
			{
				output[i] = 'D';
				break;
			}
			case 14:
			{
				output[i] = 'E';
				break;
			}
			case 15:
			{
				output[i] = 'F';
				break;
			}
			case 16:
			{
				output[i] = 'G';
				break;
			}
			case 17:
			{
				output[i] = 'H';
				break;
			}
			case 18:
			{
				output[i] = 'I';
				break;
			}
			case 19:
			{
				output[i] = 'J';
				break;
			}
			default:
			{
				output[i] = divRemainder + '0';
			}
		}
	}
	
	return 0;
}

void fprintFlags(FILE* filestream, Flags* target, PrintStyle style)
{
	short outputLength = 9;
	char output[outputLength];
	switch (style)
	{
		case TERNARY:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 3);
			break;
		}
		case QUATERNARY:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 4);
			break;
		}
		case QUINARY:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 5);
			break;
		}
		case SENARY:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 6);
			break;
		}
		case SEPTENARY:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 7);
			break;
		}
		case OCTAL:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 8);
			break;
		}
		case NONARY:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 9);
			break;
		}
		case DECIMAL:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 10);
			break;
		}
		case UNDECIMAL:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 11);
			break;
		}
		case DUODECIMAL:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 12);
			break;
		}
		case TRIDECIMAL:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 13);
			break;
		}
		case TETRADECIMAL:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 14);
			break;
		}
		case PENTADECIMAL:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 15);
			break;
		}
		case HEXADECIMAL:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 16);
			break;
		}
		case HEPTADECIMAL:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 17);
			break;
		}
		case OCTODECIMAL:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 18);
			break;
		}
		case ENNEADECIMAL:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 19);
			break;
		}
		case VIGESIMAL:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 20);
			break;
		}
		case TABLE:
		case BINARY:
		default:
		{
			writeDecNumberInSystemN(target->flags, output, outputLength, 2);
		}
	}
	
	if (style != TABLE)
	{
		fprintf(filestream, "%s", output);
	}
	else
	{
		fprintf(filestream, "--------------FLAGS--------------\n"
		        			"|f:7|f:6|f:5|f:4|f:3|f:2|f:1|f:0|\n"
		        			"---------------------------------\n");
		for (short i = 0; i < outputLength - 1; i++)
		{
			fprintf(filestream, "| %c ", output[i]);
		}
		fprintf(filestream, "|\n---------------------------------\n");
	}
}

void printFlags(Flags* target, PrintStyle style)
{
	fprintFlags(stdout, target, style);
}

void flagsSetOn(Flags* target)
{
	target->flags |= ALL;
}

void flagsSetOff(Flags* target)
{
	target->flags &= NONE;
}

void setOnExactFlags(Flags* target, FlagsValues flags)
{
	target->flags |= flags;
}

void setOffExactFlags(Flags* target, FlagsValues flags)
{
	target->flags &= ~flags;
}

short isSetOnExactFlags(Flags* target, FlagsValues flags)
{
	if (flags == NONE)
	{
		if (target->flags != NONE)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else if ((target->flags & flags) == flags)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

short isSetOffExactFlags(Flags* target, FlagsValues flags)
{
	if (flags == ALL)
	{
		if (target->flags != ALL)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if (((target->flags & flags) & flags) == NONE)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}