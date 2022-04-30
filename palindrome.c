#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define CAPACITY 128

int get_input(char*);

/* Start of main program */
int main() 
{
	get_input(NULL);
	return 0;

}

/* Reads user-input */
int get_input(char* input) 
{

	printf("Please enter a word: ");

	int ch, i = 0;

	while (isspace(ch = getchar()));

	while (ch != '\n' && ch != EOF) 
	{
		if (i < CAPACITY) 
		{
			input[i++] = ch;
		}
		ch = getchar();
	}
	input[i] = '\0';
	return i;

}