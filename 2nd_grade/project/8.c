#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 256

typedef struct 
{
	char name[N]; // �̸�
	int score1; // ����1
	int score2; // ����2
	int score3; // ����3
	int sum; // ��
	double average; // ���
}Score;

int count(FILE* fp);  //fp�� �����ϴ� ������ �� ���� ���� �Լ�
void read(FILE* fp, Score* list); // 'data.txt'�� �о list�� �����ϴ� �Լ�
int compare(const void* p, const void* q);
void print_txt(int n, Score* list);
void print_result(int n, Score* list);

int main(void)
{
    FILE* fp = fopen("data.txt", "rt"); // 'data.txt'�� 'rt'�� ����
    Score* list = (Score*)calloc(N, sizeof(Score));
    int n = count(fp); // ���� �迭 ��
    read(fp, list); // 'data.txt'�� �о list�� ����
    print_txt(n, list); // 'print_txt' �Լ��� �̿��� txt������ ���
    print_result(n, list); // 'print_result' �Լ��� �̿��� ����� ���
    return 0;
}

int count(FILE* fp)  //fp�� �����ϴ� ������ �� ���� ���� �Լ�
{
    char str[N]; // N ũ���� �迭 ����
    int i = 0; // �ݺ����� ���� ���� ����
    while (fgets(str, N, fp) != NULL) // fp�� �о NULL�� �ƴҶ� ����
        i++;
    rewind(fp); // fp�� ���� �����͸� ���� �������� �̵�
    return i;
}

void read(FILE* fp, Score* list) // 'data.txt'�� �о list�� �����ϴ� �Լ�
{
    int i = 0; // �ݺ����� ���� ���� ����
    int j = 0;
    char str[N]; // N ũ���� �迭 ����
    if (fp != NULL) // fp�� NULL�� �ƴϸ�
    {
        while (fgets(str, N, fp) != NULL) // fp�� �о NULL�� �ƴҶ� ����
        {
            char* parts = strtok(str, ":");
            i = 0;
            while (parts != NULL) // parts�� NULL�� �ƴҶ� ����
            {
                switch (i)
                {
                case 0:
                    strcpy(list[j].name, parts); // i�� 0�̸� parts�� name�� ����
                    break;
                case 1:
                    list[j].score1 = atoi(parts); // i�� 1�̸� atoi �Լ��� ���� parts�� ������ ��ȯ�Ͽ� score1�� ����
                    break;
                case 2:
                    list[j].score2 = atoi(parts); // i�� 2�̸� atoi �Լ��� ���� parts�� ������ ��ȯ�Ͽ� score2�� ����
                    break;
                case 3:
                    list[j].score3 = atoi(parts); // i�� 3�̸� atoi �Լ��� ���� parts�� ������ ��ȯ�Ͽ� score3�� ����
                    break;
                }
                parts = strtok(NULL, ":\n"); // buffer�� ���ڿ��� :�� \n ���� �����Ͽ� parts�� ����
                i++;
                list[j].sum = list[j].score1 + list[j].score2 + list[j].score3; // score1, score2, score3�� ��� ���ؼ� ���� sum�� ���� 
                list[j].average = list[j].sum / 3.0; // ���� sum�� 3���� ������ ��� average�� ���� 
            }
            j++;
        }
    }
    rewind(fp); // fp�� ���� �����͸� ���� �������� �̵�
}

int compare(const void* p, const void* q) // p�� q�� ���ϴ� �Լ�
{
    int i = ((Score*)p)->sum; // p�� sum�� i�� ����
    int j = ((Score*)q)->sum; // q�� sum�� j�� ����
    return (j - i); // qsort�� ������������ �ϱ� ���� j-i�� ��ȯ 
}

void print_txt(int n, Score* list) // 'print_txt' �Լ��� �̿��� txt������ ���
{
    int i; // �ݺ����� ���� ���� ����
    printf("data.txt�� ����\n");
    for (i = 0; i < n; i++) // list'�� �Էµ� �� �� 'data.txt'�� ����� ���� ��� ���
        printf("\t%4s\t%2d\t%2d\t%2d\n", list[i].name, list[i].score1, list[i].score2, list[i].score3);
    printf("\n");
}

void print_result(int n, Score* list) // 'print_result' �Լ��� �̿��� ����� ���
{
    int i; // �ݺ����� ���� ���� ����
    printf("�� �������� ���� ��\n");
    printf("\t�̸�   ����1   ����2   ����3\t��\t���\n");
    qsort(list, n, sizeof(Score), compare); // qsort�� �̿��� ������������ ����
    for (i = 0; i < n; i++) // 'list'�� �Էµ� ��� ���� ��� ���
        printf("\t%4s\t%2d\t%2d\t%2d\t%2d\t%2.2f\n", list[i].name, list[i].score1, list[i].score2, list[i].score3, list[i].sum, list[i].average);
    printf("\n");
}