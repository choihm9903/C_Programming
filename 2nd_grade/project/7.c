#include <stdio.h>
#include <time.h>
#define M 12

int Day[M] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  // 1~12������ �� ���� �� �ϼ��� ���� �迭

int yoon(int year); // �ش� ������ �������� Ȯ���ϴ� �Լ�
int days(int year, int month, int day); // �ش� ������ 1�� 1�Ϻ��� �ش� �������� �ϼ��� ��ȯ�ϴ� �Լ�
int total(int year1, int month1, int day1, int year2, int month2, int day2); // �����Ϸκ��� ����ϱ����� �ϼ��� ��ȯ�ϴ� �Լ�

int main(void)
{
	int year1, month1, day1; // �������� ���� ������ ���� ����
	int year2, month2, day2; // ������� ���� ������ ���� ����

	// ������ �Է�
	printf("�������� �Է��ϼ���.\n"); 
	printf("yyyy mm dd: ");
	scanf("%d %d %d", &year1, &month1, &day1);
	printf("%d %d %d\n", year1, month1, day1);
	
	// ����� �Է�
	printf("������� �Է��ϼ���.\n");
	printf("yyyy mm dd: ");
	scanf("%d %d %d", &year2, &month2, &day2);
	printf("%d %d %d\n", year2, month2, day2);

	// ������� �����Ϻ��� Ŭ �� 'total'�Լ��� ���� �����Ϸκ��� ����ϱ����� �ϼ��� ���
	if (year2 > year1 || ((year2 == year1 && month2 > month1) || (year2 == year1 && month2 == month1 && day2 >= day1)))
		printf("%d��° �Դϴ�.\n", total(year1, month1, day1, year2, month2, day2));
	else // ������� �����Ϻ��� ���� �� ����ó��
		printf("�������� ����Ϻ��� ŭ�ϴ�. �ٽ� �Է��ϼ���.\n");
	return 0;
}

int yoon(int year) // �ش� ������ �������� Ȯ���ϴ� �Լ�
{
	if ((year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0))
		return 1;  //�����϶��� 1�� ��ȯ
	else
		return 0;  //������ �ƴ� ���� 0�� ��ȯ
}

int days(int year, int month, int day) // �ش� ������ 1�� 1�Ϻ��� �ش� �������� �ϼ��� ��ȯ�ϴ� �Լ�
{
	int i; // �ݺ����� ���� ���� ����
	int days = 0; // �� �ϼ��� ���� ������ ���� �� �ʱ�ȭ
	for (i = 1; i < month; i++)
	{
		days += Day[i-1]; // �ش� ���� �ϼ��� �� �ϼ��� ����
		if (i == 2 && yoon(year)) // �ش� ������ �����̰� �ش� ���� 2���̸� �� �ϼ��� 1�� ����
			days++;
	}
	days += day; // �ش� ���� �� �ϼ��� ����
	return days; // �� �ϼ��� ��ȯ
}

int total(int year1, int month1, int day1, int year2, int month2, int day2) // �����Ϸκ��� ����ϱ����� �ϼ��� ��ȯ�ϴ� �Լ�
{
	int i; // �ݺ����� ���� ���� ����
	int total = 0; // �����Ϸκ��� ����ϱ����� �ϼ��� ���� ������ ���� �� �ʱ�ȭ
	if (year1 == year2) // �����ϰ� ������� ���� ������ ��
		total = days(year2, month2, day2) - days(year1, month1, day1) + 1; // ������� �� �ϼ��� �������� �� �ϼ��� �� �� 1�� ����
	else // �����ϰ� ������� �ٸ� ������ ��
	{
		for (i = year1 + 1; i < year2; i++)
		{
			total += 365; // �����ϰ� ����ϻ��� ��� ������ �ϼ��� ����
			if (yoon(i))
				total++; // �ش� ������ �����̸� �����Ϸκ��� ����ϱ����� �ϼ��� 1�� ����
		}
		total += 365 - days(year1, month1, day1) + 1; // days�Լ��� ���� ���� �����Ϻ��� �������� ���� 12�� 31�ϱ����� �ϼ�(1�� - �� �ϼ�)�� �����Ϸκ��� ����ϱ����� �ϼ��� ����
		total += days(year2, month2, day2); // days�Լ��� ���� ���� ������� ����� ���� �� �ϼ��� �����Ϸκ��� ����ϱ����� �ϼ��� ����
		if (yoon(year1)) // �������� �����̸� 1�� ����
			total++; 
	}
	return total; // �����Ϸκ��� ����ϱ����� �ϼ��� ��ȯ
}