#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

#define MAX 2500

int main() {

	int c, count = 0, nw = 0;// nw is for counting the newlines. 	
	char arr[MAX] = {'\0'};
	char arr[MAX] = {'\0'};

	int stop = 0;
	scanf("%d", &stop); // So this will count then as a newspace. Can't be more than 20. Equal to zero then is greater than zero. Do a check. 
	int lines = (stop + 1); // This would be for input for the lines written by the user. 

	while ((c = getchar()) != EOF && (stop >= 1 && stop <= 20))
	{
		if (c != '\n') {
		  arr[count++] = c;
		}
		if (c == '\n')
		{
			nw++;
		}

		if (nw == lines)
		{
			break;
		}
	}
	
	//printf("This is the nw %d\n",  nw); // Counting the lines. 
	printf("%d", count);
	printf("\n%s", arr);
	
	return 0;
}
