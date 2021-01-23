#include <stdio.h>
#define MAX 30

print_matrix(int(*A)[MAX], int n, int m);
make_matrix(int(*A)[MAX], int n, int m);
sum_matrix(int(*A)[MAX], int(*B)[MAX], int(*S)[MAX], int n, int m);
multiply_matrix(int(*A)[MAX], int(*B)[MAX], int(*S)[MAX], int n, int s, int m);

int main(void)
{
	int An, Am, Bn, Bm;
	int matrixA[MAX][MAX];
	int matrixB[MAX][MAX];
	int matrixS[MAX][MAX];
	int matrixM[MAX][MAX];

	printf("��� ��� ���α׷�\n");
	printf("\nù��° ����� �Է��ϼ���.\n");
	printf("����� �� ũ�� �Է�: ");
	scanf("%d", &An);
	printf("����� �� ũ�� �Է�: ");
	scanf("%d", &Am);
	printf("\nù��° ����� ���� �Է��ϼ���.\n");
	make_matrix(matrixA, An, Am);

	printf("\n�ι�° ����� �Է��ϼ���.\n");
	printf("����� �� ũ�� �Է�: ");
	scanf("%d", &Bn);
	printf("����� �� ũ�� �Է�: ");
	scanf("%d", &Bm);
	printf("\n�ι�° ����� ���� �Է��ϼ���.\n");
	make_matrix(matrixB, Bn, Bm);

	printf("\n�� ����� ��\n");
	if (An != Bn || Am != Bm)
		printf("�� ����� ���� �������� �ʴ´�.\n");
	else
	{
		sum_matrix(matrixA, matrixB, matrixS, An, Am);
		print_matrix(matrixS, An, Am);
	}

	printf("\n�� ����� ��\n");
	if (Bm == An)
	{
		multiply_matrix(matrixA, matrixB, matrixM, An, Am, Bm);
		print_matrix(matrixM, An, Bm);
	}
	else
		printf("�� ����� ���� �������� �ʴ´�.\n");
	
	return 0;
}

make_matrix(int(*A)[MAX], int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			printf("%d * %d ����� �� �Է�: ", i + 1, j + 1);
			scanf("%d", &(*(A + i))[j]);
		}
}

print_matrix(int(*A)[MAX], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf(" %4d ", (*(A + i))[j]);
		printf("\n");
	}
}

sum_matrix(int(*A)[MAX], int(*B)[MAX], int(*S)[MAX], int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			(*(S + i))[j] = (*(A + i))[j] + (*(B + i))[j];
}

multiply_matrix(int(*A)[MAX], int(*B)[MAX], int(*S)[MAX], int n, int s, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			(*(S + i))[j] = 0;
			for (int k = 0; k < s; k++)
				(*(S + i))[j] += (*(A + i))[k] * (*(B + k))[j];
		}
}