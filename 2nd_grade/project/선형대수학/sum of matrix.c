#include <stdio.h>
#define MAX 30

int main(void)
{
	int matrixA[MAX][MAX];
	int matrixB[MAX][MAX];
	int matrixSum[MAX][MAX];
	int n, m;

	printf("����� �� ��� ���α׷�\n\n");
	printf("�����Ϸ��� ����� ũ�⸦ �Է��ϼ���.\n");
	printf("����� �� ũ�� �Է�: ");
	scanf("%d", &n);
	printf("����� �� ũ�� �Է�: ");
	scanf("%d", &m);

	printf("\nù��° ����� ���� �Է��ϼ���.\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d*%d ����� �� �Է�: ", i+1, j+1);
			scanf("%d", &matrixA[i][j]);
		}
	}

	printf("\n�ι�° ����� ���� �Է��ϼ���.\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d*%d ����� �� �Է�: ", i + 1, j + 1);
			scanf("%d", &matrixB[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{ 
			matrixSum[i][j] = matrixA[i][j] + matrixB[i][j];
		}
	}

	printf("\n�� ��� ������ �����\n");
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf(" %4d ", matrixSum[i][j]);
		}
		printf("\n");
	}
	return 0;
}