#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int power(int base, int pw)
{
	if (pw == 0)
		return 1;
	
	return base * power(base, pw - 1);
}
	
void printSet(char* funcSet, int setSize) {
	for (int i = 0; i < setSize; ++i)
		printf("%c ", funcSet[i]);

	printf("\n");
}

void printPairs(char** funcSet, char* srcSet, int setSize)
{
	for (int i = 0; i < power(setSize, setSize); ++i) {
		printf("%i: ", i);
		for (int j = 0; j < setSize; ++j)
			printf("<%c,%c> ", srcSet[j], funcSet[i][j]);
		printf("\n");
	}
}

int main (void)
{
	char srcSet[] = {'a', 'b', 'c', 'd', 'e'};
	
	int setSize = sizeof srcSet / sizeof(char);

	char** funcSet = malloc(sizeof (char*) * power(setSize, setSize));

	for (int i = 0; i < power(setSize,setSize); ++i) {
		char* func = malloc(sizeof(char) * setSize);

		for (int j = 0; j < setSize; ++j) {
			func[j] = srcSet[i / power(setSize, j) % setSize];
		}
		funcSet[i] = func;
	}

	printPairs(funcSet, srcSet, setSize);

	return 0;
}
