#include <stdio.h>

int main(void)
{
	int num;
	int divisor = 0;
	printf("���� ���� �Է�: ");
	scanf("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		if (num%i == 0)
		{
			divisor++;
		}
	}
	if (divisor == 2)
	{
		printf("%d�� �Ҽ��̴�.\n", num);
	}
	else
	{
		printf("%d�� �Ҽ��� �ƴϴ�.\n", num);
	}
	return 0;
}