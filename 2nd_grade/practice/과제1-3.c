#include <stdio.h>

int main(void)
{
	int height;
	float inch;
	int feet;

	printf("cm�� ǥ���� Ű �Է�: ");
	scanf("%d", &height);
	inch = height / 2.54;
	feet = inch / 12;
	inch = inch - feet*12;
	printf("%dcm�� %d��Ʈ %lf ��ġ�̴�.\n",height, feet, inch);
	return 0;
}