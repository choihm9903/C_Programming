#include <stdio.h>

int main(void)
{
	int money;
	int price;
	int change;
	int tax;

	printf("������ : ");
	scanf("%d", &money);
	printf("��ǰ�� �Ѿ� : ");
	scanf("%d", &price);
	tax = price / 10;
	change = money - price;

	printf("�ΰ��� : %d\n", tax);
	printf("�ܵ� : %d\n", change);
	return 0;
}