#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 256

typedef struct
{
	char str[MAX];
	int len;
	int word;
}STR;

int main(void)
{
	int num;
	int length = 0;
	int wordsum = 0;

	printf("�Է��� ���ڿ� ����: ");
	scanf("%d", &num);
	getchar();

	STR* A = (STR*)malloc(sizeof(STR) * num);
	
	for (int i = 0; i < num; i++)
	{
		printf("���ڿ�%d: ", i + 1);
		gets(A[i].str);
	}
	
	for (int i = 0; i < num; i++)
	{
		A[i].len = strlen(A[i].str);
	}

	for (int i = 0; i < num; i++)
	{
		int count = 0;
		char* word = strtok(A[i].str, " \t");
		while (word != NULL)
		{
			word = strtok(NULL, " \t");
			count++;
		}
		A[i].word = count;
	}
	
	for (int i = 0; i < num; i++)
	{
		printf("%d��° ���ڿ��� ����: %d\n", i + 1, A[i].len);
		printf("%d��° �ܾ��� ����: %d\n", i + 1, A[i].word);
		length += A[i].len;
		wordsum += A[i].word;
	}
	printf("���ڿ����� ������ ��: %d\n�ܾ� ������ ��: %d\n", length, wordsum);
	free(A);
	return 0;
}