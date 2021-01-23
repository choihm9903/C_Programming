#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 5																	// ��� ���� �ִ밪

typedef struct																	// ������������ ��� ����ü ����
{
	double a[MAX][MAX];
}matrix;

typedef struct																	// ���������� ���� ��� ����ü ���� 
{
	double c[MAX];
}column;

typedef enum																	// True, False ����ü ����
{
	E_FALSE, E_TRUE
}E_BOOL;

void printout(matrix a, column c, int n);										// ��� ����Լ�
void gauss(matrix a, column c, int n);											// ���콺 �ҰŹ� ����Լ�
void backsub(matrix a, column c, int n);										// �����Թ� ����Լ�

int main(void)
{
	int i, j;
	int n;

	matrix a;
	column c;

	printf(" ���콺 ���� �ҰŹ��� �̿��� ���������� ��� ���α׷�\n\n");
	printf(" ������������ �ִ� ������ �Է�: ");									// ����� ũ�� �Է�
	scanf("%d", &n);
	printf("\n ������������ ������ �Է��ϼ���.\n");								// ������������ ���� �Է�
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			printf(" %d ��° ���������� x%d �� ��: ", i + 1, j + 1);
			scanf("%lf", &a.a[i][j]);
		}
	printf("\n ������������ ��� ���� �Է��ϼ���.\n");							// ������������ ��� �� �Է�
	for (i = 0; i < n; i++)
	{
		printf(" %d ��° ������������ ��� ��: ", i + 1);
		scanf("%lf", &c.c[i]);
	}
	gauss(a, c, n);
	return 0;
}

void printout(matrix a, column c, int n)										// ������ ���
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf(" %+.lf\t", a.a[i][j]);
		printf(" x%d ", i + 1);
		printf(" %+.lf \n", c.c[i]);
	}
	printf("\n");
}

void gauss(matrix a, column c, int n)											// ������������ ���콺 �ҰŹ����� ���
{
	E_BOOL error;
	int i, j, k, l;
	double multi = 0, temp = 0;
	printf("\n ���콺 ���ܼҰŹ� Ǯ�� ���� \n\n");

	error = E_FALSE;
	k = 0;

	while (k < n && error != E_TRUE)
	{
		l = k;
		for (j = k + 1; j < n; j++)
		{
			if (fabs(a.a[j][k]) > fabs(a.a[l][k]))
				l = j;

			for (j = k; j < n; j++)
			{
				temp = a.a[k][j];
				a.a[k][j] = a.a[l][j];
				a.a[l][j] = temp;
			}
			temp = c.c[k];
			c.c[k] = c.c[l];
			c.c[l] = temp;
			if (a.a[k][k] != 0)
			{
				for (j = k + 1; j < n; j++)
				{
					multi = -1 * a.a[j][k] / a.a[k][k];
					for (i = k; i < n; i++)
						if (multi != 0)
							a.a[j][i] += multi * a.a[k][i];
					c.c[j] += multi * c.c[k];
				}
				printout(a, c, n);
			}
			else
				error = E_TRUE;
		}
		k++;
	}
	if (error == E_TRUE)
		printf(" ���ǿ� ������ ����");
	printout(a, c, n);
	backsub(a, c, n);
}

void backsub(matrix a, column c, int n)											// �����Թ����� ���			
{
	int i, j, k;
	float sum;
	column mat = { 0. };
	printf(" a[n, n] = %.f\n\n", a.a[n - 1][n - 1]);
	if (fabs(a.a[n - 1][n - 1]) == 0 || fabs(a.a[n - 1][n - 1]) < 1 / 1000000)
		printf(" ������ �ظ� ���� �ʴ´�.\n\n");
	else
	{
		mat.c[n - 1] = c.c[n - 1] / (a.a[n - 1][n - 1]);
		for (i = n - 2; i > -1; i--)
		{
			sum = 0.0f;
			for (j = n - 1; j > i; j--)
				sum += a.a[i][j] * mat.c[j];
			if (fabs(a.a[n - 1][n - 1]) == 0 || fabs(a.a[n - 1][n - 1]) < 1 / 1000000)
				printf(" ������ �ظ� ���� �ʴ´�.\n\n");
			else
				mat.c[i] = (c.c[i] - sum) / a.a[i][i];
		}
		printf(" �Է��� ������������ �ش�\n");
		for (k = 0; k < n; k++)
		{
			printf(" x%d = ", k + 1);
			printf("%.lf \t", mat.c[k]);
		}
		printf("\n\n");
	}
}