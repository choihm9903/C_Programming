#include <stdio.h>
#define MAX 128
#define SIZE 3

typedef struct
{
	char number[MAX];
	char name[MAX];
	char memo[MAX];
}Phonenumber;

void Read(Phonenumber arr)
{
	Phonenumber str = arr;
	printf("��ȭ��ȣ ������ �Է��Ͻÿ�.\n");
	printf("��ȣ: ");
	scanf("%s", str.number);
	printf("�̸�: ");
	scanf("%s", str.name);
	printf("�޸�: ");
	scanf("%s", str.memo);
}

int main(void)
{
	Phonenumber arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		Read(arr[i]);
		for (int j = 0; j <= i; j++)
		{
			printf("%d %s %s %s \n", j + 1, arr[j].number, arr[j].name, arr[j].memo);
		}
	}
	return 0;
}

/*
int main(void)
{
	Phonenumber arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		printf("��ȭ��ȣ ������ �Է��Ͻÿ�.\n");
		printf("��ȣ: ");
		scanf("%s", arr[i].number);
		printf("�̸�: ");
		scanf("%s", arr[i].name);
		printf("�޸�: ");
		scanf("%s", arr[i].memo);
		for (int j = 0; j <= i; j++)
		{
			printf("%d %s %s %s \n", j+1, arr[j].number, arr[j].name, arr[j].memo);
		}
	}
	return 0;
}
*/
