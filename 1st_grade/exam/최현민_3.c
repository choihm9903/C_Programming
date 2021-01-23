#include <stdio.h>

int radius(void)
{
	int r;
	do
	{
		printf("1 �̻��� ����� �Է�: ");
		scanf("%d", &r);
	} while (r<1);
	return r;
}

int circle(int x, int y, int r)
{
	if (x*x + y*y <= r*r)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main(void)
{
	int r = radius();
	int x = 0;
	int y = 0;
	int t = 0;
	int count = 0;

	while (x<=r)
	{
		while (x*x+y*y <= r*r)
		{
			t =circle(x, y, r);
			if (t == 1)
			{
				count++;
			}
			y++;
		}
		x++;
	}
	printf("�������� %d�� ���� ������ ��ǥ�� %d�� �ִ�.\n", r, count * 4);
	return 0;
}