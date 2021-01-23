#include <stdio.h>
#include <math.h>

#define MAX 5	//��� ���� �ִ밪

typedef struct	//��� ����ü ����
{
	double a[MAX][MAX];
}matrix;

typedef struct	//���� �迭 ����ü ���� 
{
	double c[MAX];
}column;

typedef enum	//True, False ����ü ����
{
	E_FALSE, E_TRUE
}E_BOOL;

int det(matrix a, int n);	//��Ľ� ����Լ�
void printout(matrix a, column c, int n);	//��� ����Լ�
void gauss(matrix a, column c, int n);	//���콺 �ҰŹ� ����Լ�
void backsub(matrix a, column c, int n);	//�����Թ� ����Լ�

int main(void)
{
	int i, j, k, l;	//�ݺ����� ����
	int n;	//��� ��� ���� ũ��
	int m = 0;	//�������� ����
	int eigenvalue = -256;	//������
	matrix a, b;	//�������� ���� ���
	column c, value;	//�ؿ� �������� �迭

	printf(" ���콺 ���� �ҰŹ��� �̿��� �������� �������� ��� ���α׷�\n\n");
	printf(" ��� ���� ũ�⸦ �Է�: ");	//��� ���� ũ�⸦ n�� �Է�						
	scanf("%d", &n);
	printf("\n ����� ���� �Է��ϼ���.\n");	//����� �� �Է�								
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			printf(" %d * %d ����� ��: ", i + 1, j + 1);
			scanf("%lf", &a.a[i][j]);
		}
	for (i = 0; i < n; i++)	//�ظ� �迭�� �Է�
		c.c[i] = 0;

	while (m < n)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				b.a[i][j] = a.a[i][j];	//��� a�� ���� ��� b�� ���� ����
		for (i = 0; i < n; i++)	//��� b�� �ִ밢���� ������ ���� eigenvalue�� ��
			b.a[i][i] -= eigenvalue;
		if (det(b, n) == 0)	//��� b�� ��Ľ��� 0�� �� ������ �迭 value�� �ش� ���� ���� 
		{
			value.c[m] = eigenvalue;
			m++;
		}
		eigenvalue++;
	}
	
	printf("\n ����� ������\n");
	for (i = 0; i < n; i++)	//������ �迭 value�� ����� �������� ��� ���
		printf(" ��%d = %.lf\t", i + 1, value.c[i]);
	
	printf("\n\n ����� ��������\n\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
				b.a[j][k] = a.a[j][k];	//��� a�� ���� ��� b�� ���� ����
		for (l = 0; l < n; l++)	//��� b�� �ִ밢���� ������ value.c[i]�� ��
			b.a[l][l] -= value.c[i];
		printf(" ��%d = %.lf �϶� ��������\n", i + 1, value.c[i]);
		gauss(b, c, n);	//�ش� �������� �������͸� gauss �Լ��� ���� ����
	}
	return 0;
}

int det(matrix a, int n)	//��Ľ� ����Լ�
{
	int i, j, k, y;
	int sum = 0;
	matrix temp;	//����Ľ��� ������ ���
	if (n != 1)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 1; j < n; j++)
			{
				y = 0;
				for (k = 0; k < n; k++)
					if (k != i)
						temp.a[j - 1][y++] = a.a[j][k];	//1�� i+1���� �������� ����Ľ��� ����
			}
			sum += pow(-1, i) * a.a[0][i] * det(temp, n - 1);	//���� sum�� ���μ��� ����
		}
		return sum;
	}
	else
		return a.a[0][0];
}

void printout(matrix a, column c, int n)	//��� ����Լ�
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf(" %+.lf\t", a.a[i][j]);	//���콺-���� �ҰŹ� Ǯ�̰����� ���
		printf(" x%d ", i + 1);
		printf(" %+.lf \n", c.c[i]);
	}
	printf("\n");
}

void gauss(matrix a, column c, int n)	//���콺 �ҰŹ� ����Լ�
{
	E_BOOL error;
	int i, j, k, l;
	double multi = 0, temp = 0;
	printf("\n ���콺 ���ܼҰŹ� Ǯ�� ���� \n");

	error = E_FALSE;
	k = 0;

	while (k < n && error != E_TRUE)	//���콺-���� �ҰŹ��� ���� ����� �ﰢ��ķ� ��ȯ
	{
		l = k;
		for (j = k + 1; j < n; j++)
		{
			if (fabs(a.a[j][k]) > fabs(a.a[l][k]))
				l = j;
			for (j = k; j < n; j++)	//a.a[k][j]�� a.a[l][j]�� ���� �ٲ�
			{
				temp = a.a[k][j];
				a.a[k][j] = a.a[l][j];
				a.a[l][j] = temp;
			}
			temp = c.c[k];	//c.c[k]�� c.c[l]�� ���� �ٲ�
			c.c[k] = c.c[l];
			c.c[l] = temp;
			if (a.a[k][k] != 0)
			{
				for (j = k + 1; j < n; j++)
				{
					multi = -1 * a.a[j][k] / a.a[k][k];	//a.a[j][k]�� a.a[k][k]�� �� ���� a.a[j][i]�� �Ұ�
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

void backsub(matrix a, column c, int n)	//�����Թ� ����Լ�			
{
	int i, j, k;
	float sum;
	column mat = { 0. };
	if (fabs(a.a[n - 1][n - 1]) < 0.01)	//a.a[n-1][n-1]�� 0�� ��(�ε��Ҽ��� ���� ����) mat.c[n-1]�� 1�� ����
		mat.c[n - 1] = 1;
	else
		mat.c[n - 1] = c.c[n - 1] / (a.a[n - 1][n - 1]); //a.a[n-1][n-1]�� 0�� �ƴ� �� ���� ����
	for (i = n - 2; i > -1; i--)
	{
		sum = 0.0f;
		for (j = n - 1; j > i; j--)
			sum += a.a[i][j] * mat.c[j];	//mat.c[i]�� ���ϱ� ���� ������ ������ ����
		if (fabs(a.a[i][i]) < 0.01)	//a.a[i][i]�� 0�� ��(�ε��Ҽ��� ���� ����) mat.c[i]�� 1�� ����
			mat.c[i] = 1;
		else
			mat.c[i] = (c.c[i] - sum) / a.a[i][i];	//a.a[i][i]�� 0�� �ƴ� �� ���� ����
	}
	for (k = 0; k < n; k++)
	{
		printf(" x%d = ", k + 1);
		printf("%.4lf \t", mat.c[k]);
	}
	printf("\n\n\n");
}