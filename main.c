#include<stdio.h>
#include<ctype.h>
#include"gate.h"
/*
The essential key to encode and decypher EOF_code
*/
const char keybook[ROWS][COLS] = {
	{'E', 'T', 'S', 'A', 'K', 'N', 'M', 'B'},
	{'O', 'L', 'P', 'Z', 'C', 'V', 'W', 'Q'},
	{'F', 'R', 'G', 'J', 'I', 'X', 'U', 'H', 'D', 'Y'},
	{'7', '1', '3', '4', '8', '2', '5', '6', '0', '9'}
};
char input[SENT];
int count = 0;

/*
function declarations
*/
void code(char);
char get_fir(void);
char get_fir_char(void);

int main(void)
{
	char cmd;

	printf("Please make your input.\n");
	fgets(input, SENT, stdin);
	for (count = 0; count < SENT; count++)
		input[count] = toupper(input[count]);

	printf("Do you want to encript this pharse or decypher it?\n");
	printf("(E\C. encript   D. decypher   Q. quit): ");
	cmd = get_fir_char();
	cmd = toupper(cmd);

	while (cmd != 'Q')
	{
		if (cmd == 'C' || cmd == 'D' || cmd == 'E')
		{
			code(cmd);
			getch();

			printf("Any further command?\n");
			printf("(E\C. encript   D. decypher   Q. quit): ");
			cmd = get_fir_char();
			cmd = toupper(cmd);
		}
		else
		{
			printf("(E\C. encript   D. decypher   Q. quit): ");
			cmd = get_fir_char();
			cmd = toupper(cmd);
		}
	}

	puts("Your code is: ");
	puts(input[SENT]);

	return 0;
}

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
