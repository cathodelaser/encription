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
int input_count = 0;

/*
function declarations
*/
extern void code(char);
extern char get_fir(void);
extern char get_fir_char(void);
extern int s_gets(char *, int);
extern int remain(int);
extern int codcmp(char *);
extern void pcode(int, int, int);
extern int EVEN(int);
extern int codecat(int);
extern void construct(int);

int main(void)
{
	char cmd;
	auto int count;

	/*
	Enter input, and toupper it
	*/
	printf("Please make your input.\n");
	input_count = s_gets(input, SENT);

	for (count = 0; count < input_count; count++)
		input[count] = toupper(input[count]);

	printf("You entered %d characters.\n", input_count);

	printf("Do you want to encrypt this pharse or decypher it?\n");
	printf("(E\C. encrypt   D. decypher   Q. quit): ");
	cmd = get_fir_char();
	cmd = toupper(cmd);

	while (cmd != 'Q')
	{
		if (cmd == 'C' || cmd == 'D' || cmd == 'E')
		{
			code(cmd);
			getch();

			printf("Any further command?\n");
			printf("(E\C. encrypt   D. decypher   Q. quit): ");
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

	printf("Your code is:\n%s", input);

	return 0;
}
