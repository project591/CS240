// This program turns as string of lowercase letters into uppercase letters 
// and any uppercase letters are turned to lowercase

#include <stdio.h>

int main() {

	int c, nw = 2, count = 0, counter = 0;
	char arr1[200] = {'0'};

	while ((c = getchar()) != EOF)
	{
		if (c >= 65 && c <= 90)
		{
			c = c + 32;
		}

		else if (c >= 97 && c <= 122)
		{
			c = c - 32; //convert to uppercase
		}

		if (c == '\n')
		{
			counter++;
		}

		if (counter == nw)
		{
			break;
		}

		if (c != '\n')
		arr1[count++] = c;
	}

	printf("%s", arr1);
	
}
