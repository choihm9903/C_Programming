#include <stdio.h>
#define PI 3.141592

int main(void)
{
	int radius;
	float circle_area;
	float circumference;
	int cylinder_height;
	float cylinder_area;
	float cylider_volume;
	float sphere_volume;

	printf("��\n");
	printf("���� ������: ");
	scanf("%d", &radius);
	circle_area = radius * radius * PI;
	circumference = 2 * radius * PI;
	printf("���� ����: %lf\n", circle_area);
	printf("���� �ѷ�: %lf\n\n", circumference);

	printf("�����\n");
	printf("����� �ظ��� ������: %d\n", radius);
	printf("������� ����: ");
	scanf("%d", &cylinder_height);
	cylinder_area = circle_area * 2 + circumference * cylinder_height;
	cylider_volume = circle_area * cylinder_height;
	printf("������� �ѳ���: %lf\n", cylinder_area);
	printf("������� ����: %lf\n\n", cylider_volume);

	printf("��\n");
	printf("���� ������: %d\n", radius);
	sphere_volume = 4 / 3 * PI * radius * radius * radius;
	printf("���� ����: %lf\n", sphere_volume);
	return 0;
}