#include<stdio.h>

int main(void)
{
	int n1, n2, n3;
	int a, b, c;
	int repeat = 1;

	while (repeat == 1)
	{
		printf("\n�ﰢ�� ���� Ȯ�� ���α׷�\n");
		printf("���� ����1: ");
		scanf("%d", &n1);
		printf("���� ����2: ");
		scanf("%d", &n2);
		printf("���� ����3: ");
		scanf("%d", &n3);

		if (n1 > n2)
		{
			if (n1 > n3)
			{
				c = n1;
				if (n2 > n3)
				{
					b = n2;
					a = n3;
				}
				else
				{
					b = n3;
					a = n2;
				}
			}
			else
			{
				c = n3;
				b = n1;
				a = n2;
			}
		}
		else
		{
			if (n2 > n3)
			{
				c = n2;
				if (n1 > n3)
				{
					b = n1;
					a = n3;
				}
				else
				{
					b = n3;
					a = n1;
				}
			}
			else
			{
				c = n3;
				b = n2;
				a = n1;
			}
		}

		printf("%d, %d, %d �� �̷���� �ﰢ���� ", n1, n2, n3);
		if (a + b > c)
		{
			if (a * a + b * b == c * c)
				printf("�����ﰢ���̴�.\n");
			else if (a == b && b == c)
				printf("���ﰢ���̴�.\n");
			else if (c == a || c == b)
				printf("�̵�ﰢ���̴�.\n");
			else
				printf("�Ϲݻﰢ���̴�.\n");
		}
		else
			printf("�������� �ʴ´�.\n");

		printf("1 �Է½� �ٽ� ���� : ");
		scanf("%d", &repeat);
	}
	return 0;
}