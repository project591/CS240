#include <stdio.h>

int main() {

	int c, count = 0, Ccount = 0;
	int letters[26] = { 0 }; // initialize to null. Will display amount of time letter appears.
	int bigLetters[26] = { 0 }, isMore[6] = {0};
	int isDigit[10] = { 0 }, isAmper[7]= {0};
	int isSign[15] = { 0 }, isLast[7] = {0};
	char input[5000] = { '\0' };

	while ((c = getchar()) != EOF)
	{
		if ((c >= '!' && c <= '/')) {
			++isSign[(c - '!')];
			// Protecting the input array from spaces and tabs
			input[count++] = c;
		}

		if ((c >= '0' && c <= '9')) {
			++isDigit[(c - '0')];
			// Filling up the input array here. 
			input[count++] = c;
		}

		if ((c >= ':' && c <= '@')) {
			++isAmper[(c - ':')];
			input[count++] = c;
		}

		if ((c >= 'a' && c <= 'z')) {
			++letters[(c - 'a')];
			input[count++] = c;
		}

		if ((c >= '[' && c <= '`')) {
			++isMore[(c - '[')];
			input[count++] = c;
		}

		if ((c >= 'A' && c <= 'Z'))
		{
			++bigLetters[(c - 'A')];
			input[count++] = c;
		}

		if ((c >= '{' && c <= '~')) {
			++isLast[(c - '{')];
			input[count++] = c;
		}
	}
	// Printing the output here. 
	for (int i = 0; i < count; i++) {

		printf("%c", input[i]);
	}

	printf("\n");
	// Printing the results below. 
	for (int i = 0; i < 15; i++) {
		if (isSign[i] > 0)
			printf("%c %d\n", i + '!', isSign[i]);
	}

	for (int i = 0; i < 10; i++) {
		if (isDigit[i] > 0)
			printf("%c %d\n", i + '0', isDigit[i]);
	}

	for (int i = 0; i < 7; i++) {
		if (isAmper[i] > 0)
			printf("%c %d\n", i + ':', isAmper[i]);
	}

	for (int i = 0; i < 26; i++) {
		if (bigLetters[i] > 0)
			printf("%c %d \n", i + 'A', bigLetters[i]);
	}

	for (int i = 0; i < 6; i++) {
		if (isMore[i] > 0)
			printf("%c %d \n", i + '[', isMore[i]);
	}

	for (int i = 0; i < 26; i++) {
		if (letters[i] > 0)
			printf("%c %d \n", i + 'a', letters[i]);
	}

	for (int i = 0; i < 7; i++) {
		if (isLast[i] > 0)
			printf("%c %d \n", i + '{', isLast[i]);
	}

	return 0;
}