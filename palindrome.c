#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define PASSED(word) (printf("\n\nYour word '%s' is a palindrome\n\n", word))
#define FAILED(word) (printf("\n\nYour word '%s' is not a palindrome\n\n", word)

#define CAPACITY 128


bool testing();                             // debug
void test();                                // debug

void runProgram();                          // If we're not debugging, run normal program
int  get_input(char*);                      // Get user-input, store values in memory
int  clean_input(char*, char*);             // Remove spaces & special characters
bool isPalindrome(char*, char*);            // Checks if user-input is a palindrome

/* Start of main program */
int main() 
{

	testing() ? test() : runProgram();

	return 0;

}

void runProgram()
{
	char* input   = calloc(CAPACITY, sizeof(char));                             // Using calloc to zero memory
	char* cleaned = calloc(CAPACITY, sizeof(char));

	get_input(input);
	clean_input(input, cleaned);

	char* left  = cleaned;
	char* right = NULL;

	if(cleaned != NULL)                                                         // Ensures we're not setting the right pointer to 0
	{
		right = (strlen(cleaned) - 1) + left;
	}

	isPalindrome(left, right) ? PASSED(cleaned) : FAILED(cleaned));

	free(input);                                                               // Free memory
	free(cleaned);

	input = NULL;                                                              // Handle dangling pointer
	cleaned = NULL;

}

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

int clean_input(char* input, char* cleaned) 
{
	int i, j = 0;

	for (i = 0; i < strlen(input); i++) 
	{
		if ((!isspace(input[i])) && isalpha(input[i]))                          // If the character is not a space or non alphabet character
		{                                                                       // Add it to the clean array
			cleaned[j] = tolower(input[i]);
			j++;
		}
	}

	return j;
}

bool isPalindrome(char* left, char* right) 
{
	while (left <= right)														
	{
		if (*left != *right)                                                    // If the value of left and right pointer aren't equal, not palindrome
		{
			return false;
		}

		left++;                                                                 // Move pointer to the right (until it's collided with left ptr)
		right--;                                                                // Move pointer to the left (until it's collided with right ptr)
	}

	return true;
}

bool testing()
{
	char answer;

	printf("Would you like to test the program? (y / n) ");
	scanf("%c", &answer);

	return tolower(answer) == 'y';
}

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

		free(test);     // handle memory
		test = NULL;    // handle dangling pointer
	}
}