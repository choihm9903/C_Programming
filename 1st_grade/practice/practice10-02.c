#include <stdio.h>
#include <string.h>

#define MAX 256

int main(void)
{
	FILE* fp = fopen("data.txt", "rt");
	if (fp == NULL) 
	{
		puts("���� ���� ����!");
		return -1;
	}

	char A[MAX];
	char* p = fgets(A, MAX, fp);
	while (p!=NULL)
	{
		printf("%s", A);
		p = fgets(A, MAX, fp);
	}
	fclose(fp);
	return 0;
}