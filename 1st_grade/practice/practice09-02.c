#include <stdio.h>
#include <string.h>
#define MAX 20
#define WORD 5

typedef struct
{
	char word[MAX];
	int sum;
}ASCII;

int sum(char* s)
{
	int sum = 0;
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		sum += s[i];
	}
	return sum;
}

int main(void)
{
	ASCII A[WORD];
	for (int i = 0; i < WORD; i++)
	{
		printf("�ܾ�%d: ", i+1);
		scanf("%s", A[i].word);
		A[i].sum = sum(A[i].word);
	}
	for (int i = 0; i < WORD; i++)
	{
		printf("�ܾ�%d�� �ƽ�Ű�ڵ� ��: %d\n", i+1, A[i].sum);
	}
	return 0;
}