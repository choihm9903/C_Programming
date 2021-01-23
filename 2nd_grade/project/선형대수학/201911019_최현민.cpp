#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 5

void input_equation(double(*A)[N], int n);								// ������������ ������ �Է¹޴� �Լ�
void input_sum(double* A, int n);										// ������������ ������� �Է¹޴� �Լ�
void print_equation(double(*A)[N], double C[N], int n);					// ������������ ����� ����ϴ� �Լ�
double det(double(*A)[N], int n);										// ��Ľ��� ���ϴ� �Լ�
void crammer(double(*A)[N], double C[N], int n, int c);					// ũ������ ��Ģ�� ���� ������������ �ظ� ���ϴ� �Լ�

int main(void)
{
	int i, j;															// �ݺ��� ����� ���� ���� ����
	int n;																// ������������ �ִ� ���� ����
	double A[N][N] = {0, };												// ������������ ����� ���� 2���� �迭�� ���� �� 0���� �ʱ�ȭ
	double C[N] = { 0, };												// ������������ ������� ���� 1���� �迭�� ���� �� 0���� �ʱ�ȭ
	printf(" ũ������ ��Ģ�� �̿��� ���������� ��� ���α׷�\n\n");
	printf(" ������������ �ִ� ���� �Է�: ");
	scanf("%d", &n);													// ������������ �ִ� ���� �Է�

	input_equation(A, n);												// 2���� �迭 A�� ������������ ������ �Է¹޴� �Լ�(input_equation)�� ���� ��� �Է�
	input_sum(C, n);													// 1���� �迭 C�� ������������ ������� �Է¹޴� �Լ�(input_sum)�� ���� ����� �Է� 
	print_equation(A, C, n);											// ������������ ����� ����ϴ� �Լ�(print_equation)�� �������� ���İ� ������� A�� C�� �޾� ��� ���

	printf("\n �Է��� ������������ ��Ľ� ��\n");
	printf(" Det(A) = %.f\n\n", det(A, n));								// ��Ľ��� ���ϴ� �Լ�(det)�� ���� 2���� �迭 A�� ��Ľ� ����
	printf(" �Է��� ������������ �ش�\n");
	for (i = 1; i < n + 1; i++)
		crammer(A, C, n, i);											// ������������ �ظ� ���ϴ� �Լ�(crammer)�� ���� �������� �� ���
	printf("\n\n");
}

void input_equation(double(*A)[N], int n)
{
	int i, j;
	printf("\n ������������ ������ �Է��ϼ���. \n");					// ������������ ������ �Է�
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			printf(" %d ��° ���������� x%d �� ��: ", i + 1, j + 1);
			scanf("%lf", &A[i][j]);										// �־��� 2���� �迭 A�� A[i][j]�� i+1 ��° ���������� x(j+1)�� ��(���)�� �Է� 
		}
}

void input_sum(double* A, int n)
{
	int i;
	printf("\n ������������ ��� ���� �Է��ϼ���. \n");					// ������������ ������� �Է�
	for (i = 0; i < n; i++)
	{
		printf(" %d ��° ������������ ��� ��: ", i + 1);
		scanf("%lf", &A[i]);											// �־��� 1���� �迭 A�� A[i]�� i+1 ��° ������������ ������� �Է�
	}
}

void print_equation(double(*A)[N], double B[N], int n)
{
	int i, j;
	printf("\n �Է��� ������������ ��� = \n\n");						// �Է��� ������������ ��� ���
	for (i = 0; i < n; i++)
	{
		printf(" |\t");
		for (j = 0; j < n; j++)
			printf(" %.f x%d\t", A[i][j], j + 1);						// ������������ ������ ���� 2���� �迭 A�� ���
		printf("=\t");
		printf("%.f\t", B[i]);											// ������������ ������� ���� 1���� �迭 B�� ���
		printf("|\n");
	}
}

double det(double(*A)[N], int n)
{
	int i, j, k, y;														// �ݺ��� ����� ���� ���� ����
	double det_a = 0;													// ��Ľ� ���� ����
	double temp[N][N];													// ������ �Ǵ� ���� ����Ľ��� ������ �ӽ� �迭

	if (n != 1)															// n�� 1�� �ƴ� �� ���μ��� ���� ��Ľ��� ����
	{
		for (i = 0; i < n; i++)											// A����� 1������ n������ �̵�(i�� 0���� n-1), A����� i���� �������� ����Ľ��� ����
		{
			for (j = 1; j < n; j++)										// A����� 2����� n����� �̵�(i�� 1���� n-1), A����� 1���� �������� ����Ľ��� ���� 
			{
				y = 0;													// ����Ľ� ����� ��
				for (k = 0; k < n; k++)									// k�� ������ �Ǵ� ���� �ش��ϴ� i+1���� ������ A�� ��
					if (k != i)
						temp[j - 1][y++] = (*A + j * N)[k];				// temp�� ������ �Ǵ� �� A[0][i]�� ����Ľ�, �̶� (*A + j * N)[k] �� A����� j+1�� k+1�� ����Ŵ  
			}																
			det_a = det_a + *(A[0] + i) * (pow(-1, i)) * det(temp, n - 1);	// ����Ľ��� �̿��� ��Ľ��� ���� 
		}
		return det_a;												    // ��Ľ� ��ȯ 
	}
	else															    // n�� 1�� �� �� �״�� ��Ľ��̹Ƿ� �״�� ��ȯ
		return *A[0];
}

void crammer(double(*A)[N], double C[N], int n, int c)
{
	int i, j ;															// �ݺ��� ����� ���� ���� ����
	double temp[N][N] = {0, };											// 2���� �迭 temp�� A��Ŀ� ���� ���� ��ü�� �ӽ� ���
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			temp[i][j] = A[i][j];										// 2���� �迭 temp�� A��� �Է�
	for (i = 0; i < n; i++)	
		temp[i][c-1] = C[i];											// A����� temp�� c���� ������� C��ķ� ��ü
	printf(" x%d = %.f\t", c, det(temp, n) / det(A, n));				// ������������ �ظ� ���
}