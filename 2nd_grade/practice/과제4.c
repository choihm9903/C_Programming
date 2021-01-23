#include <stdio.h>

int integer_sum(int a, int b);
int b_square(int a, int b);
int k_square(int a, int b);

int main(void)
{
	int num1, num2;
	printf("����1 �Է�: ");
	scanf("%d",&num1);
	printf("����2 �Է�: ");
	scanf("%d", &num2);
	printf("1) %d, %d�� �����Ͽ� �� ���� �������� ���� %d�̴�.\n", num1, num2, integer_sum(num1, num2));
	printf("2) %d�� %d���� %d�̴�.\n", num1, num2, b_square(num1,num2));
	printf("3) %d�� k�� <= %d�� �����ϴ� ������ ���� ū ���� k�� %d�̴�.\n", num1, num2, k_square(num1,num2));
	return 0;
}

int integer_sum(int a, int b)
{
	int sum = 0;
	while (a<=b)
	{
		sum += a;
		a++;
	}
	return sum;
}

int b_square(int a, int b)
{
	int sum = 1;
	for (int i = 0; i < b; i++)
	{
		sum *= a;
	}
	return sum;
}

int k_square(int a, int b)
{
	int sum = 1;
	int k = 0;
	while (1)
	{
		sum *= a;
		if (sum > b)
			break;
		k++;
	}
	return k;
}