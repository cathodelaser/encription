#include<stdio.h>
#include<stdlib.h>
#include"gate.h"
/*
declare variebles
*/
extern char keybook[ROWS][COLS];
extern char input[SENT];
extern int count;
static int subcode[2][SENT];
static int cat[2][SENT / 8];

/*
declare functions
*/
int remain(int);
int codcmp(char *);
void pcode(int, int, int);
int EVEN(int);
int codecat(int);
void construct(int);

void code(char cmd)
{
	int i;
	int e_o;
	int row, col;
	int wcount;							//count how many letters are actually in the argument
	int ccount;							//count sections cut by the codecat() function
	int cut;							//number of sections cut by the codecat() function

	printf("Code called.\n");

	for (i = 0; i < SENT; i++)
	{
		row, col = codcmp(input[i]);	//get the value of the letter
		wcount++;

		/*process*/
		{
			//row
			if (row = NULL)
				row = 3;
			//column
			if (col = NULL)
				col = remain(i + 1);
		}

		subcode[0][i] = row;			//store the rows in the first line
		subcode[1][i] = col;			//store the columns in the second line
	}
	
	/*command process*/
	if (cmd = 'D')
	{
		subcode[0][i] = NULL;
		subcode[1][i] = NULL;
		cut = codecat(i - 1);

		for (ccount = 1; ccount < cut; ccount++)
			pcode(cat[0][ccount - 1], cat[0][ccount], cat[1][ccount]);
	}
	else
	{
		cut = codecat(i);

		for (ccount = 1; ccount < cut; ccount++)
			pcode(cat[0][ccount - 1], cat[0][ccount], cat[1][ccount]);

		count++;
		input[i] = count;
	}

	construct(i);
	printf("Process made.\n");

	return;
}

int remain(int i)
{
	int otc;

	if (i > 0 && i <= 8)
	{
		return i;
	}
	else if (i > 8)
	{
		otc = i % 8;

		if (otc = 0)
		{
			return 8;
		}
		else
		{
			return otc;
		}
	}
	else
	{
		printf("error _int remain(int). i <= 0 or i is not an integer.\n");
		getch();
		exit(1);
	}
}

int codcmp(char *input)
{
	int row;							//count row
	int col;							//count column

	printf("Start compare.\n");

	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLS; col++)
		{
			if (*input == keybook[row][col])
			{
				printf("Found the letter at %d, %d.\n", row, col);

				return row;
				return col;
			}
		}
	}
}

void pcode(int start, int end, int e_o)
{
	extern int subcode[2][SENT];
	auto int temp;						//temporary storage

	printf("Starting to process codes.\n");

	if (e_o)							//odd
		for (start = 0; start < (end - 1) / 2; start++)
		{
			temp = subcode[1][start];
			subcode[1][start] = subcode[2][end];
			subcode[1][end] = temp;
		}
	else								//even
		for (start = 0; start < end / 2 - 1; start++)
		{
			temp = subcode[1][start];
			subcode[1][start] = subcode[2][end];
			subcode[1][end] = temp;
		}

	puts(subcode[0]);
	puts(subcode[1]);

	return;
}

int EVEN(int num)						//maybe it is because of me, but really? no one defined this in the liberary?
{
	int rmn;							//remain after a division of 2
	rmn = num % 2;
	if (rmn == 0)
		return 0;						//return 0 when even
	else return 1;						//return 1 when odd
}

int codecat(int string)
{
	int i, n, m;
	cat[0][0] = 0;
	cat[1][0] = NULL;

	if (string <= 10)
	{
		cat[0][1] = string;
		cat[1][1] = EVEN(string);
		puts(cat);

		return 1;
	}
	else
	{
		if (string % 10 < 4 && string % 10 > 0)
		{
			n = string / 8;
			m = string % 8;

			for (i = 1; i < n; i++)
			{
				cat[0][i] = 8 * i;
				cat[1][i] = 0;
			}
			cat[0][n] = string;
			cat[1][n] = EVEN(m);
		}
		else if (string % 8 < 4 && string % 8 > 0)
		{
			n = string / 7;
			m = string % 7;

			for (i = 1; i < n; i++)
			{
				cat[0][i] = 7 * i;
				cat[1][i] = 1;
			}
			cat[0][n] = string;
			cat[1][n] = EVEN(m);
		}
		else
		{
			n = string / 10;
			m = string % 10;

			for (i = 1; i < n; i++)
			{
				cat[0][i] = 10 * i;
				cat[1][i] = 0;
			}
			cat[0][n] = string;
			cat[1][n] = EVEN(m);
		}
		puts(cat);

		return n;
	}
}

void construct(int string)
{
	int row;
	int col;
	auto int count;

	for (count = 0; count < string; count++)
	{
		row = subcode[0][count];
		col = subcode[1][count];
		input[count] = keybook[row][col];
	}

	return;
}
