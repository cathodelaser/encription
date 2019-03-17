#include<stdio.h>
#include<ctype.h>

char get_fir(void)
{
	char ch;
	ch = getchar();

	while (getchar() != '\n')
		continue;

	return ch;
}

char get_fir_char(void)
{
	char ch;
	ch = getchar();

	while (ch < 'A' || ch > 'z' || (ch > 'Z' && ch < 'a'))
	{
		ch = getchar();
	}

	while (getchar() != '\n')
		continue;

	return ch;
}

int s_gets(char * Buffer, int Max_count)
{
	auto int count;

	for (count = 0, *Buffer = getchar(); count < Max_count; count++)
	{
		printf("Loop %d.\n", count + 1);
		if (*Buffer == NULL)
			break;
		else if (*Buffer == '\n')
		{
			*Buffer = NULL;
			break;
		}
		else
			*++Buffer = getchar();
	}

	return count;
}
