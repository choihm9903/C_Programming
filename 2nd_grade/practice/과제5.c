#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

void print_matrix(int n, int(*A)[MAX]);								// ����� ����ϴ� �Լ�
int confirm_all(int n, int(*A)[MAX]);								// ����� ��� ��� ���� �������� Ȯ���ϴ� �Լ�

int main(void)
{
	int tile[MAX][MAX] = { 0, };									// Ÿ�Ͽ� ���������� ������ Ƚ���� �����ϴ� �������迭 
	srand(time(NULL));
	int number;
	int count = 0;													// ���������� �̵�Ƚ��
	int y = 5;														// ���������� ��ġ y��ǥ, 5�� �ʱ�ȭ
	int x = 5;														// ���������� ��ġ x��ǥ, 5�� �ʱ�ȭ
	while (!confirm_all(10, tile))
	{
		number = rand() % 8;
		switch (number)
		{
		case 0:														// number�� 0�� �� (x, y-1)
			if (y != 0)												// �̵��� �� �ִ� ��츸 �̵�
				y--;
			break;
		case 1:														// number�� 1�� �� (x+1, y-1)
			if (y != 0 && x != 9)									// �̵��� �� �ִ� ��츸 �̵�
			{
				x++;
				y--;
			}
			break;
		case 2:														// number�� 2�� �� (x+1, y)
			if (x != 9)												// �̵��� �� �ִ� ��츸 �̵�
				x++;
			break;
		case 3:														// number�� 3�� �� (x+1, y+1)
			if (y != 9 && x != 9)									// �̵��� �� �ִ� ��츸 �̵�
			{
				x++;
				y++;
			}
			break;
		case 4:														// number�� 4�� �� (x, y+1)
			if (y != 9)												// �̵��� �� �ִ� ��츸 �̵�
				y++;
			break;
		case 5:														// number�� 5�� �� (x-1, y+1)
			if (y != 9 && x != 0)									// �̵��� �� �ִ� ��츸 �̵�
			{
				x--;
				y++;
			}
			break;
		case 6:														// number�� 6�� �� (x-1, y)
			if (x != 0)												// �̵��� �� �ִ� ��츸 �̵�
				x--;
			break;
		default:													// number�� 7�� �� (x, y-1)
			if (y != 0 && x != 0)									// �̵��� �� �ִ� ��츸 �̵�
			{
				x--;
				y--;
			}
		}
		tile[y][x] = 1;												// ���������� ���� ��ġ�� 1�� �ٲ�
		count++;
		if (count == 10)
		{
			printf("\n 10��° random walk ���\n");
			print_matrix(MAX, tile);
		}
		else if (count == 100)
		{
			printf("\n 100��° random walk ���\n");
			print_matrix(MAX, tile);
		}
	}
	printf("\n random walk ���\n");
	print_matrix(MAX, tile);
	printf("\n �� %d�� ��������.\n", count);					   // �� �̵� Ƚ���� ���
	return 0;
}

void print_matrix(int n, int(*A)[MAX])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf(" %4d ", A[i][j]);								// ����� ��� ��� �� ���
		printf("\n");
	}
}

int confirm_all(int n, int(*A)[MAX])
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)										
			if (A[i][j] == 0)
				return 0;											// ����� � ��� ���� 0�� �� 0�� ��ȯ
	return 1;														// ����� ��� ��� ���� 0�� �ƴ� �� 1�� ��ȯ
}