#include <stdio.h>

int main(void)
{
	int n;
	int k;
	int num;

	printf("n: ");
	scanf("%d", &n);
	printf("k: ");
	scanf("%d", &k);

	num = n;
	while (num%k!=0)
	{
		num--;
	}

	printf("%d�� ���������鼭 ���� ����� %d�� ����� %d�̴�.", n, k, num);
	return 0;
}