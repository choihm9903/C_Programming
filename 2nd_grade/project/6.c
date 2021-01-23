#include <stdio.h>
#define N 256

void binary(int num); // 10������ ���� 'num'�� 2������ ��ȯ�� ���� �迭 'n'�� ������ �� ����ϴ� �Լ�

int main(void)
{
	int num; // ������ ���� ����							
	printf("10������ �Է��ϼ���: ");	
	scanf("%d", &num); // 10������ scanf�� ���� ���� num�� ����		
	binary(num); // �Լ� 'binary'�� ���� 10������ 2������ ���
	return 0;
}

void binary(int num) // 10������ ���� 'num'�� 2������ ��ȯ�� ���� �迭 'n'�� ������ �� ����ϴ� �Լ�
{
	int i = 0; // �ݺ����� ���� ���� ����
	int j;
	int n[N] = { 0, }; // 'num'�� 2������ ��ȯ�� ���� ������ �迭
	printf("������: ");
	if (num == 0) // 'num'�� 0�� ��
		printf("%d", num);
	while (num != 0) // 'num'�� 0�� �ƴ� ��
	{
		n[i] = num % 2; // 'num'�� 2�� ���� �������� �迭 'n'�� ����
		num /= 2; // 'num'�� 2�� ����
		i++;
	}
	for (j = i-1; j >= 0; j--) // 'num'�� 2������ ��ȯ�� ���� ������ �迭 'n'�� �ڿ��� ���� ���
		printf("%d", n[j]);
	printf("\n");
}