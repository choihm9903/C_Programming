#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define WORD 5													// �ܾ��� ����
#define MAX 20													// �ܾ��� �ִ����

void swap(int* a, int* b);										// �� ���� a�� b�� ���� �ٲ��ִ� �Լ�(swap)
int test(char w[MAX], int n);									// �ܾ �޾� ��ĭ ������ ���� ������ 1 Ʋ���� 0�� ��ȯ�ϴ� ���� �ܾ� ���� �Լ�(test)

int main(void)
{
	int i = 0;													// �ݺ� ����									
	char word[WORD][MAX];										// ���ڿ�(�ܾ�)�� ������ ������ �迭(word)
	int count = 0;												// ���� Ƚ��
	FILE* fp = fopen("word.txt", "rt");							// "word.txt" ������ "rt"(�б�)���� ��
	if (fp == NULL)												// ���� ���� ���� �� ����ó��
	{
		printf("���� ���� ����\n");
		return -1;
	}	
	while (fgets(word[i], MAX, fp) != NULL)						// fp���� '\n'�� ���� �������� ���ڿ��� ������ �迭�� i��(word[i])�� ����  
	{
		if (word[i][strlen(word[i]) - 1] == '\n')				// fgets�� ���� ���ڿ�(word[i]) ���� '\n'�� ���Ե� ��� '\0'�� ��ȯ�Ͽ� ����
			word[i][strlen(word[i]) - 1] = '\0';					
		i++;													// i++�� �� ��ȯ
	}
	printf(" ���� �ܾ� ���� ���α׷�\n");
	printf(" ���ݺ��� ���� �ܾ� ������ �ǽ��ϰڽ��ϴ�.\n");
	for (i = 0; i < WORD; i++)
		if (test(word[i], i))									// test �Լ��� ������ ���߸� ���� Ƚ��(count)�� 1�� ����
			count++;
	printf(" ���� %d�� �� %d���� ���߼̽��ϴ�. 100�� ������ %d���Դϴ�.\n", WORD, count, count * 100 / WORD);	// ���� ����, ���� ����, ����(�����) ���� ����/ ���� ���� * 100 ���
	fclose(fp);													// ������ ����
	return 0;
}

void swap(int* a, int* b)										// �� ���� a�� b�� ���� �ٲ��ִ� �Լ�(swap)
{
	int temp = *a;												// ���� a�� �ּҰ���(*a) ����(temp)�� ����
	*a = *b;													// ���� b�� �ּҰ���(*b) ���� a�� �ּҰ���(*a) ����
	*b = temp;													// ���� a�� �ּҰ���(temp) ���� b�� �ּҰ���(*b) ����
}

int test(char w[MAX], int n)									// �ܾ �޾� ��ĭ ������ ���� ������ 1 Ʋ���� 0�� ��ȯ�ϴ� ���� �ܾ� ���� �Լ�(test)
{		
	srand(time(NULL));											// 1�� ������ ���ϴ� time(NULL)���� srand �Լ��� ���� �õ� ���� ����
	int len = strlen(w);										// ���ڿ��� ����
	int r1 = rand() % len;										// ù��° ��ĭ�� �ε���, 0���� n-1������ ����(r1)
	int r2 = rand() % len;										// �ι�° ��ĭ�� �ε���, 0���� n-1������ ����(r2)
	char c1, c2;												// ���� ���� ���� ����(c1, c2)
	int i;														// �ݺ� ����
	while (r1 == r2)											// r1�� r2�� ���� �� �� ���� �ٸ������� r2�� �ٽ� ����
	{
		r2 = rand() % len;
		if (r1 != r2)
			break;
	}
	if (r1 > r2)												// r1�� r2���� Ŭ �� �� ���� ���� �ٲ�
		swap(&r1, &r2);
	printf(" ����%d: ", n + 1);
	for (i = 0; i < len; i++)
	{
		if (i == r1 || i == r2)									// ���ڿ��� �ε���(i)�� r1 �Ǵ� r2�϶� ���� ��� ��ĭ(-) ���
			printf("_");
		else													// ���ڿ��� �ε���(i)�� r1 �Ǵ� r2�� �ƴ� �� �ش� �ε����� ���� ���
			printf("%c", w[i]);
	}
	printf("\n ù ��° ���� �Է�: ");
	scanf("%c", &c1);
	getchar();													// �Է� ���� ����
	printf(" �� ��° ���� �Է�: ");
	scanf("%c", &c2);
	getchar();													// �Է� ���� ����
	if (w[r1] == c1 && w[r2] == c2)								// �� ���ڸ� �°� �Է������� "�����Դϴ�"�� ����ϰ� 1�� ��ȯ
	{
		printf(" �����Դϴ�. �����մϴ�.\n\n");
		return 1;
	}
	else														// �� ���� �� �ϳ��� Ʋ������ "Ʋ�Ƚ��ϴ�"�� ������ ����ϰ� 0�� ��ȯ
	{
		printf(" Ʋ�Ƚ��ϴ�. ������ %s�Դϴ�.\n\n", w);
		return 0;
	}
}