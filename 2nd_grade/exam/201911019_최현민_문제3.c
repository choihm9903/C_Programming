#include <stdio.h>
#define MAX 10

int main(void)
{
	int Num[MAX];								//���� 10���� �Է¹��� �迭
	int freq_num, freq;							//�ֺ󰪰� �󵵼�
	int count = 1;								//���� ���� ���� �󵵼�
	int i, j;
	printf(" �ֺ� ��� ���α׷�\n");
	printf(" ���� 10���� �Է��ϼ���.\n");
	for (i = 0; i < MAX; i++)					//�迭�� ���� 10���� �Է�
	{
		printf(" n%d: ", i + 1);
		scanf("%d", &Num[i]);
	}
	for (i = 0; i < MAX; i++)					//�迭�� �ֺ� Ȯ��
	{
		freq = 1;
		for (j = i + 1; j < MAX; j++)
			if (Num[i] == Num[j])				//�ش� ���� ���� ���� ��
				freq++;							//�󵵼� �߰�
		if (freq>=count)						//�ش� ���� �󵵼��� ���� ���� ���� �󵵼� ���� Ŭ ��
		{
			freq_num = Num[i];					//�ֺ� ����
			count = freq;						//���� ���� ���� �󵵼� ����
		}
	}
	printf(" �迭�� ����� �� �� �ֺ��� %d�̴�.\n", freq_num);
	return 0;
}