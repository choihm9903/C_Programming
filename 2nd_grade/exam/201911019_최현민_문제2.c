#include <stdio.h>

int main(void)
{
	int c1, c2, c3;								//��ǻ���� ����
	int n1, n2, n3;								//�̿����� ����
	int strike = 0;								//��Ʈ����ũ
	int ball = 0;								//��
	int sum = 0;								//���� ������ ����
	int i = 0;									//����Ƚ��
	while (sum != 3)							//����ڰ� ���� 3���� �� ���⶧���� �ݺ�
	{
		strike = 0;								//��Ʈ����ũ �ʱ�ȭ
		ball = 0;								//�� �ʱ�ȭ
		i++;									//����Ƚ�� �߰�
		printf(" ���ھ߱����� %d��°\n", i);
		
		printf(" ���� 3�� �Է�(��ǻ��)\n");		//��ǻ���� ���� �Է�
		printf(" c1: ");
		scanf("%d", &c1);
		printf(" c2: ");
		scanf("%d", &c2);
		while (c2 == c1)						//���� �ߺ��� �ٽ� �Է�
		{
			printf("���� �ߺ� �Ұ�\n");
			printf(" c2: ");
			scanf("%d", &c2);
		}
		printf(" c3: ");
		scanf("%d", &c3);
		while (c3 == c1 || c3 == c2)			//���� �ߺ��� �ٽ� �Է�
		{
			printf("���� �ߺ� �Ұ�\n");
			printf(" c3: ");
			scanf("%d", &c3);
		}
		
		printf(" ���� 3�� �Է�(�����)\n");		//������� ���� �Է�
		printf(" n1: ");
		scanf("%d", &n1);
		printf(" n2: ");
		scanf("%d", &n2);
		while (n2 == n1)						//���� �ߺ��� �ٽ� �Է�
		{
			printf("���� �ߺ� �Ұ�\n");
			printf(" n2: ");
			scanf("%d", &n2);
		}
		printf(" n3: ");
		scanf("%d", &n3);
		while (n3 == n1 || n3 == n2)			//���� �ߺ��� �ٽ� �Է�
		{
			printf("���� �ߺ� �Ұ�\n");
			printf(" n3: ");
			scanf("%d", &n3);
		}

		if (c1 == n1)							//�� �ڸ����� ���ڰ� ��ġ(��Ʈ����ũ)
			strike++;
		if (c1 == n2)							//���ڸ� ��ġ(��)
			ball++;
		if (c1 == n3)							//���ڸ� ��ġ(��)
			ball++;
		if (c2 == n1)							//���ڸ� ��ġ(��)
			ball++;
		if (c2 == n2)							//�� �ڸ����� ���ڰ� ��ġ(��Ʈ����ũ)
			strike++;
		if (c2 == n3)							//���ڸ� ��ġ(��)
			ball++;
		if (c3 == n1)							//���ڸ� ��ġ(��)
			ball++;
		if (c3 == n2)							//���ڸ� ��ġ(��)
			ball++;
		if (c3 == n3)							//�� �ڸ����� ���ڰ� ��ġ(��Ʈ����ũ)
			strike++;
		
		sum = strike + ball;					//���� ������ ����
		printf(" %d, %d, %d vs %d, %d, %d\n", c1, c2, c3, n1, n2, n3);
		printf(" %d��Ʈ����ũ %d��\n", strike, ball);	//��� ���
		printf("\n");
	}
	printf(" �� %d�� �����ߴ�.\n", i);
	return 0;
}