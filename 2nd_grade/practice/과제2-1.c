#include <stdio.h>

int main(void)
{
	int num;
	int sum = 0;
	printf("���� �Է�: ");
	scanf("%d", &num);
	while (num!=0)
	{
		sum += num % 10;
		num = num / 10;
	}
	printf("�� �ڸ����� ���� %d�̴�.\n", sum);
	return 0;
}