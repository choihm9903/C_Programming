#include <stdio.h>

int main(void)
{
	int a = 1;
	while (a*a*a*a <= 10000)
	{
		a++;
	}
	printf("a�� 4���� 10000�� �Ѵ� �������� �������� %d �̴�.\n", a*a*a*a);
	return 0;
}