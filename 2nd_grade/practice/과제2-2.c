#include <stdio.h>

int main(void)
{
	int num;
	int number;
	printf("���� �Է�: ");
	scanf("%d",&num);
	while (num!=0)
	{
		number = num % 10;
		num = num / 10;
		printf("%d",number);
	}
	return 0;
}