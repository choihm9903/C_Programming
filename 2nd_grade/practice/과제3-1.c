#include <stdio.h>

int main(void)
{
	int num;
	printf("���� ���� �Է�: ");
	scanf("%d", &num);
	printf("%d�� ���: ", num);
	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
	return 0;
}