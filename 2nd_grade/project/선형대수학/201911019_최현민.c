#include <stdio.h>
#include <math.h>
#define N 64
#define MIN -1024

void matrix_make(double(*A)[N], int n);                                     // ����� ���� �Է¹޴� �Լ�
void matrix_print(double(*A)[N], int n, int m);                             // ����� ����ϴ� �Լ�
int matrix_det(double(*A)[N], int n);                                       // ����� ��Ľ��� ��ȯ�ϴ� �Լ�
void matrix_cpy(double(*A)[N], double(*B)[N], int n);                       // ��� A�� ���� ��� B�� ���� �����ϴ� �Լ�
void change(double(*A)[N], int n, double m);                                // �������� ���ϱ� ���� ����� �ִ밢���� �Ǽ� m�� ���� �Լ�
void gauss(double(*A)[N], int n);                                           // ���콺-���ܼҰŹ��� ���� ����� �ﰢ��ķ� ��ȯ�ϴ� �Լ�
void backsub(double(*A)[N], int n);                                         // ����� �������͸� �����Թ��� ���� ���ϴ� �Լ� 
void printout(double(*A)[N], int n);                                        // ���콺-���ܼҰŹ� Ǯ�� ������ ����Ͽ� �����ִ� �Լ�

int main(void)
{
    double matrixA[N][N] = { 0, };                                          // �������� �������͸� ���� ���
    double matrixB[N][N] = { 0, };                                          // ó�� �Է¹��� ����� ���� ������ ���
    double C[N] = { 0, };                                                   // ����� �������� ������ �迭
    int i;                                                                  // �ݺ�����
    int n;                                                                  // ����� ũ��
    int count = 0;                                                          // �������� ����
    int value = MIN;                                                        // ������(������ MIN���� �ʱ�ȭ) 

    printf("\n ����� �������� �������� ��� ���α׷�\n\n");
    printf(" ����� ũ�� �Է�: ");
    scanf("%d", &n);                                                        // ����� ũ�⸦ n���� �Է¹���
    matrix_make(matrixA, n);                                                // ����� ���� matrix_make �Լ��� �Է¹���
    while (count < n)                                                       // ����� �������� ����(count)�� ����� ũ��(n)�� ���� ������ �������� �˻���  
    {
        matrix_cpy(matrixA, matrixB, n);                                    // ó�� �Է¹��� ���(matrixA)�� ���� ���(matrixB)�� matrix_cpy �Լ��� ���� �����Ͽ� ������
        change(matrixB, n, value);                                          // �������� ���ϱ� ���� change �Լ��� ���� ���(matrixB)�� �ִ밢���� value�� ��
        if (matrix_det(matrixB, n) == 0)                                    // ���(matrixB)�� ��Ľ��� matrix_det �Լ��� ���� ���ϰ� ��Ľ��� 0 �϶�
        {
            C[count] = value;                                               // ������(value)�� �迭(C)�� ������
            count++;                                                        // ������ ����(count)�� 1�� ����
        }
        value++;                                                            // ����� ũ��(n)�� �������� ����(count)�� ���� ������ �������� 1�� ���ذ��� �˻���
    }

    printf("\n �Է��� ���\n");
    matrix_print(matrixA, n, n);                                            // �Է��� ����� matrix_print �Լ��� ���� �����
    printf("\n ����� ������\n");
    for (i = 0; i < n; i++)                                                 // �迭(C)�� ����� �������� ��� ���
        printf(" ��%d = %.lf \t", i + 1, C[i]);
    printf("\n\n ����� ��������\n");
    for (i = 0; i < n; i++)
    {
        printf(" *********************************************\n\n");
        printf(" ������ �� = %.lf�϶� ��������\n", C[i]);
        matrix_cpy(matrixA, matrixB, n);                                    // ó�� �Է¹��� ���(matrixA)�� ���� ���(matrixB)�� matrix_cpy �Լ��� ���� �����Ͽ� ������
        change(matrixB, n, C[i]);                                           // �������͸� ���ϱ� ���� change �Լ��� ���� ���(matrixB)�� �ִ밢���� ������(C[i])�� ��
        gauss(matrixB, n);                                                  // gauss �Լ��� ���� �������͸� ����
    }
    return 0;
}

void matrix_make(double(*A)[N], int n)                                      // ����� ���� �Է¹޴� �Լ�
{
    int i, j;
    printf("\n ����� ���� �Է��ϼ���.\n");
    for (i = 0; i < n; i++)                                                 // n*n ����� ��� ���� i�� j�� 0���� n���� ���ϸ� A[i][j](i+1��, j+1��)�� �Է¹���
        for (j = 0; j < n; j++)
        {
            printf(" %d * %d ����� ���� �Է�: ", i + 1, j + 1);
            scanf("%lf", &(*(A + i))[j]);
        }
}

void matrix_print(double(*A)[N], int n, int m)                              // ����� ����ϴ� �Լ�
{
    int i, j;
    for (int i = 0; i < n; i++)
    {
        printf(" |  ");
        for (int j = 0; j < m; j++)                                         // n*m ����� ��� ���� �����
        {
            if (n == m)                                                     // �Է¹��� ����� ����� ��
                printf("%+3.lf  ", (*(A + i))[j]);
            else                                                            // �������͸� ����� ��
                printf("%+.3lf ", (*(A + i))[j]);
        }
        printf(" |\n");
    }
}

int matrix_det(double(*A)[N], int n)                                        // ����� ��Ľ��� ��ȯ�ϴ� �Լ�
{
    int i, j, k, y;                                                         // �ݺ������� ����Ľ��� ������ �Ǵ� ��� ��
    int det = 0;                                                            // ��Ľ��� ������ ���� det
    double temp[N][N];                                                      // ����Ľ��� ������ ���(temp)
    if (n != 1)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 1; j < n; j++)
            {
                y = 0;
                for (k = 0; k < n; k++)
                    if (k != i)                                             // ���(A)�� 1�� i+1���� �������� ����Ľ�(temp)�� ����
                        temp[j - 1][y++] = (*A + j * N)[k];
            }
            det += pow(-1, i) * (*A + 0)[i] * matrix_det(temp, n - 1);      // ��Ľ� ���� 1�� i+1���� ���μ�(A[0][i])�� ���� 
        }
        return det;                                                         // ���� ��Ľ��� ��ȯ��
    }
    else                                                                    // ����� ũ�Ⱑ 1�� �� ��Ľ��� ����� ���̹Ƿ� �̸� ��ȯ�� 
        return *A[0];
}

void matrix_cpy(double(*A)[N], double(*B)[N], int n)                        // ��� A�� ���� ��� B�� ���� �����ϴ� �Լ�
{
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)                                             // n*n ��� A, B�� ��� ��
            B[i][j] = A[i][j];                                              // ��� B�� ���� ��� A�� ���� ������
}

void change(double(*A)[N], int n, double m)                                 // �������� ���ϱ� ���� ����� �ִ밢���� �Ǽ� m�� ���� �Լ�
{
    int i;
    for (i = 0; i < n; i++)
        A[i][i] -= m;                                                       // ��� A�� �ִ밢���� �Ǽ� m�� ��
}


void gauss(double(*A)[N], int n)                                            // ���콺-���ܼҰŹ��� ���� ����� �ﰢ��ķ� ��ȯ�ϴ� �Լ�
{
    int i = 0, j = 0, k = 0, l = 0;
    double multi = 0, temp = 0;
    printf("\n ���콺-���ܼҰŹ� Ǯ�� ����\n");
    while (k < n)                                                           // ���� ��(k)�� ����� ũ��(n)���� ������
    {
        l = k;                                                              // l�� ���ؿ�(k)�� ������
        for (j = k + 1; j < n; j++)
        {
            if (fabs(A[j][k]) > fabs(A[l][k]))
                l = j;                                                      // ���밪 A[j][k]�� ���밪 A[l][k]���� Ŭ�� l�� j�� ������
            for (j = k; j < n; j++)
            {
                temp = A[k][j];                                             // temp�� ���� A[k][j]�� A[l][j]�� ���� ������
                A[k][j] = A[l][j];
                A[l][j] = temp;
            }
            if (A[k][k] != 0)
                for (j = k + 1; j < n; j++)
                {
                    multi = -1 * (A[j][k]) / A[k][k];                       // A[j][k]�� A[k][k]�� ������ -��ȣ�� �ٿ� mulit�� ������
                    for (i = k; i < n; i++)
                        if (multi != 0)                                     // multi�� 0�� �ƴҶ�
                            A[j][i] += multi * A[k][i];                     // A[j][k]�� ���� multi�� A[k][i]�� ���� ���� �� 
                }
        }
        k++;                                                                // ���� ��(k)�� 1�� ����
    }
    printout(A, n);                                                         // printout �Լ��� ���� ���콺-���ܼҰŹ� Ǯ�� ������ �����
    backsub(A, n);                                                          // �ﰢ��ķ� ��ȯ�� ����� �������͸� �����Թ��� ���� ���� 
}

void backsub(double(*A)[N], int n)                                          // ����� �������͸� �����Թ��� ���� ���ϴ� �Լ� 
{
    int i = 0, j = 0, k = 0;                                                // �ݺ�����(0���� �ʱ�ȭ)
    float sum;                                                              // ����(sum)
    double mat[N][N] = { 0, };                                              // �������͸� ������ �迭(mat)
    if (fabs(A[n - 1][n - 1]) < 0.00000001)                                 // ��� A�� n�� n���� ���� 0�� ��(0�� ���� ���� �ϸ� �ε��Ҽ��� ������ �߻��Ͽ� 0.00000001���� ���� ���� ǥ����)
        mat[n - 1][0] = 1;                                                  // ���������� ���а��� 1�� ����
    else
        mat[n - 1][0] = 0;                                                  // ���������� ���а��� 0��
    for (i = n - 2; i > -1; i--)
    {
        sum = 0.0f;                                                         // ����(sum)�� 0���� �ʱ�ȭ
        for (j = n - 1; j > i; j--)
            sum += A[i][j] * mat[j][0];                                     // ��� A�� i-1�� j-1��(A[i][j]) ���� ���� sum�� ����
       if (fabs(A[i][i]) < 0.00000001)                                     // ��� A�� n�� n���� ���� 0�� ��(0�� ���� ���� �ϸ� �ε��Ҽ��� ������ �߻��Ͽ� 0.00000001���� ���� ���� ǥ����)
            mat[i][0] = 1;                                                  // ���������� ���а��� 1�� ����
        else
            mat[i][0] = -sum / A[i][i];                                     // ����(sum)�� -��ȣ�� ���̰� A�� i-1�� i-1��(A[i][i]) ���� ������ �������͸� ����
    }
    printf(" ���������� ��������\n");
    matrix_print(mat, n, 1);                                                // �������� ������ �迭�� matrix_print �Լ��� ���� ���
    printf("\n");
}

void printout(double(*A)[N], int n)                                         // ���콺-���ܼҰŹ� Ǯ�� ������ ����Ͽ� �����ִ� �Լ�
{
    int i, j;                                                               // �ݺ�����
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf(" %+.1lf\t", A[i][j]);                                   // ���(A)�� ��� ���� ��� 
        printf(" x%d ", i + 1);
        printf("  %+.lf \n", 0);
    }
    printf("\n");
}