#include <stdio.h>

int main(void)
{
	int time;
	int hour;
	int minute;
	int second;

	printf("�ð��� �ʴ����� �Է�: ");
	scanf("%d", &time);
	hour = time / 3600;
	minute = (time % 3600) / 60;
	second = (time % 3600) % 60;

	printf("%d�ʴ� %d�ð� %d�� %d���̴�.\n", time, hour, minute, second);
	return 0;
}