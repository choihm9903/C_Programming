#include <stdio.h>

int main(void)
{
	int n;
	int divisor;
	printf("���� ���� �Է�: ");
	scanf("%d", &n);
	printf("1���� %d ������ ��� �Ҽ�: ",n);
	for (int num = 1; num <= n; num++)
	{
		divisor = 0;
		for (int i = 1; i <= num; i++)
		{
			if (num % i == 0)
			{
				divisor++;
			}
		}
		if (divisor == 2)
		{
			printf("%d ", num);
		}
	}
	return 0;
}