#include <stdio.h>
#define MAX 30

int main(void)
{
	int i, j, k;
	int An, Am, Bn, Bm;
	int matrixA[MAX][MAX];
	int matrixB[MAX][MAX];
	int matrixS[MAX][MAX];

	printf("����� �� ��� ���α׷�\n");
	printf("\nù��° ����� �Է��ϼ���.\n");
	printf("ù��° ����� �� ũ�� �Է�: ");
	scanf("%d", &An);
	printf("ù��° ����� �� ũ�� �Է�: ");
	scanf("%d", &Am);
	printf("\nù��° ����� ���� �Է��ϼ���.\n");
	for (i = 0; i < An; i++)
		for (j = 0; j < Am; j++)
		{
			printf("%d * %d ����� �� �Է�: ", i + 1, j + 1);
			scanf("%d", &matrixA[i][j]);
		}

	printf("\n�ι�° ����� �Է��ϼ���.\n");
	printf("�ι�° ����� �� ũ�� �Է�: ");
	scanf("%d", &Bn);
	printf("�ι�° ����� �� ũ�� �Է�: ");
	scanf("%d", &Bm);
	printf("\n�ι�° ����� ���� �Է��ϼ���.\n");
	for (i = 0; i < Bn; i++)
		for (j = 0; j < Bm; j++)
		{
			printf("%d * %d ����� �� �Է�: ", i + 1, j + 1);
			scanf("%d", &matrixB[i][j]);
		}

	for (i = 0; i < An; i++)
		for (j = 0; j < Bm; j++)
		{
			matrixS[i][j] = 0;
			for (k = 0; k < Am; k++)
				matrixS[i][j] += matrixA[i][k] * matrixB[k][j];
		}

	printf("\n�� ��� ���� �����\n");
	for (i = 0; i < An; i++)
	{
		for (j = 0; j < Bm; j++)
			printf(" %4d ", matrixS[i][j]);
		printf("\n");
	}
	return 0;
}