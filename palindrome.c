#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define CAPACITY 128

int get_input(char*);
int clean_input(char*, char*);
bool isPalindrome(char*, char*);

/* Start of main program */
int main() 
{

	char* input = calloc(CAPACITY, sizeof(char));
	char* cleaned = calloc(CAPACITY, sizeof(char));

	get_input(input);
	clean_input(input, cleaned);

	char* left = cleaned;
	char* right = (strlen(cleaned) - 1) + 1;

	if (isPalindrome(left, right))
	{
		printf("Palindrome");
	}
	else {
		printf("Not a palindrome");
	}

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

/* Removes spaces & special characters from user-input */
int clean_input(char* input, char* cleaned) 
{
	int i, j = 0;

	for (i = 0; i < strlen(input); i++) 
	{
		if ((!isspace(input[i])) && isalpha(input[i]))
		{
			cleaned[j] = tolower(input[i]);
			j++;
		}
	}
	return j;
}

/* Checks if input is a palindrome */
bool isPalindrome(char* left, char* right) 
{
	while (left <= right)
	{
		if (*left != *right)
		{
			return false;
		}

		left++;
		right--;
	}

	return true;
}