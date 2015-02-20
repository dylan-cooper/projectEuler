#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef FILENAME
#define FILENAME "PE42_words.txt"
#endif

#define ISTRIANGLE(a) ((int) a == 1 || \
	(int) a == 3 || (int) a == 6 || \
	(int) a == 10 || (int) a == 15 || \
	(int) a == 21 || (int) a == 28 || \
	(int) a == 36 || (int) a == 45 || \
	(int) a == 55 || (int) a == 66 || \
	(int) a == 78 || (int) a == 91 || \
	(int) a == 105 || (int) a == 120 || \
	(int) a == 136 || (int) a == 153 || \
	(int) a == 171 || (int) a == 190 || \
	(int) a == 210 || (int) a == 231 || \
	(int) a == 253 || (int) a == 276)

int main(){
	FILE * fp;
	char * buffer;
	char a;
	int inStr = 0;
	int sum = 0;
	int triangles = 0;

	fp = fopen(FILENAME, "r");
	if (!fp){
		printf("There was an error with the file.");
		exit(1);
	}

	while ((a = fgetc(fp)) != EOF){
		if (a == '\"'){
			inStr = !inStr;
			if (!inStr){
				triangles += (ISTRIANGLE(sum) ? 1 : 0);
				sum = 0;
			}
		} else if (inStr) {
			sum += a-'A'+1;
		}
	}
	printf("%d\n", triangles);
}