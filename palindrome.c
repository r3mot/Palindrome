#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define CAPACITY 128

bool testing();
void test();

int get_input(char*);
int clean_input(char*, char*);
bool isPalindrome(char*, char*);

/* Start of main program */
int main() 
{

	if (testing()) {
		test();
	}
	else {


		char* input = calloc(CAPACITY, sizeof(char));
		char* cleaned = calloc(CAPACITY, sizeof(char));

		get_input(input);
		clean_input(input, cleaned);

		char* left = cleaned;
		char* right = NULL;
		if (cleaned != NULL)
		{
			right = (strlen(cleaned) - 1) + left;
		}

		if (isPalindrome(left, right))
		{
			printf("Palindrome");
		}
		else {
			printf("Not a palindrome");
		}
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

/* For debug */
bool testing()
{
	printf("Would you like to test the program? (y / n) ");
	char answer;
	scanf("%c", &answer);

	return tolower(answer) == 'y';
}

/* Debug - Tests multiple cases of palindromes */
void test()
{
	printf("\n\n. . . Testing . . . \n\n");

	char* test_array[21] =
	{
		"Don;t nod.",
		"Evil olive.",
		"Amore, Roma",
		"Yo, banana boy!",
		"Dammit, I;m mad!",
		"Borrow or rob?",
		"I did, did I?",
		"Draw, O coward!",
		"Wonton? Not now!",
		"Nev#er odd or &even.",
		"Pull up, Eva! we;re here! Wave! Pull up!",
		"Anne, I vo@te more cars race Rome to Vienna.",
		"Ed, I saw Harpo Marx ram Oprah W. aside.",
		"Oozy rat in a sanitary zoo.",
		"Madam, in Eden, I'm Adam.",
		"Ma is a nun, as I am.",
		"As I pee, 6sir, I see Pisa!",
		"A man, a plan, a canal: Panama.",
		"Cigar? Toss it in a can. It is so tragic.",
		"Doc, note I dissent: a fast never prevents a fatness. I diet on cod."
	};

	for(int word = 0; word < 20; word++)
	{
		char* test = calloc(CAPACITY, sizeof(char));

		clean_input(*(test_array + word), test);

		char* left = test;
		char* right = NULL;

		if (test != NULL)
		{
			right = (strlen(test) - 1) + left;
		}

		if (isPalindrome(left, right))
		{
			printf("PASSED:    %s \n", test_array[word]);
		}
		else
		{
			printf("FAILED:    %s \n", test_array[word]);
		}

		free(test);			// handle memory
		test = NULL;		// handle dangling pointer
	}
}