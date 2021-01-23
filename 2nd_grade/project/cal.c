#include <stdio.h>
#define MAX 64
#define N 256

typedef struct {
    char number[MAX];
    char year[MAX];
    char month[MAX];
    char day[MAX];
}TOEIC;

int Day[] = { 31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31 };  //�迭�� 1~12�� ���� ��������¥ �ֱ�
int m;
TOEIC* T;

int yoon(int year) {  // ���ⱸ�ϴ� �Լ� 
    if ((year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0))
        return 2;  //�����϶��� 2
    else
        return 1;  //������ �ƴ� ���� 1
}
int Firstday(int year, int month)  // 1���� ���� �������� ���ϱ� 
{
    int total = 0;
    for (int i = 2001; i < year; i++)  // 2001�⵵ ���� ���⵵���� �� �������� ���ϱ� 
        if (yoon(i) == 2)  // �Է��� �⵵�� ������ ��� 2���� �� 366�� ���ϱ� 
            total += 366;
        else
            total += 365;
    for (int i = 1; i <= month - 1; i++) {  // �Է��� �⵵ 1������ �Է��ѳ⵵�� �� �ޱ��� �������� ���ϱ� 
        if (yoon(year) == 2 && i == 2)  //�Է��� �⵵�� ������ ��� 2���� 29�� ���ϱ� 
            total += 29;
        else
            total += Day[i - 1];
    }
    return (total % 7);
}
void Coption(FILE* fp)  //first�� MOD�� �� �������� 0, �Ͽ����� 6
{
    int year, month, day;
    int first;
    int cnt = 0;

    printf("�⵵�� �Է��ϼ���: ");
    scanf("%d", &year);
    printf("���� �Է��ϼ���: ");
    scanf("%d", &month);
    printf("��¥�� �Է��ϼ���: ");
    scanf("%d", &day);
    first = Firstday(year, month);
    printf("      %d�� %d   \n", month, year);
    printf("�� �� ȭ �� �� �� ��\n");
    if (first == 6)  //first�� 6�ΰ�쿡�� 6���� ������ ���⳪ �Ͽ��Ϻ��� �����̹Ƿ�
        printf("");
    else
    {
        for (int i = 0; i < first + 1; i++) { // ù ��° ���� ������ ���� ����ϱ� 
            printf("   ");
            cnt++;
        }
    }

    if (yoon(year) == 2 && month == 2) { // ������ ��� 2���� 29�ϱ��� ����ϱ� 
        for (int i = 1; i <= Day[1] + 1; ++i) {
            printf("%2d ", i);
            cnt++;
            if (cnt % 7 == 0)
                printf("\n");
        }
    }
    else // 2���� �ƴϰ� ������ �ƴҰ�� ����ϱ� 
    {
        for (int i = 1; i <= day[month - 1]; ++i) {
            printf("%2d ", i);
            cnt++;
            if (cnt % 7 == 0)
                printf("\n");
        }
    }
}

void read_Toeic(FILE* fp) // data.txt�� �о slist�� �����ϴ� �Լ�
{
    int i = 0;
    char buffer[N];
    int j = 0;
    if (fp != NULL) // fp�� NULL�� �ƴϸ�
    {
        while (fgets(buffer, N, fp) != NULL) // fp�� �о NULL�� �ƴҶ� ����
        {
            char* parts;
            char* str = buffer;
            parts = strsep(&str, ":"); // buffer�� ���ڿ��� :�� �����Ͽ� parts�� ����
            int i = 0;
            while (parts != NULL) // parts�� NULL�� �ƴҶ� ����
            {
                switch (i)
                {
                case 0:
                    strcpy(T[j].number, parts); // i�� 0�̸� parts�� name�� ����
                    break;
                case 1:
                    strcpy(T[j].year, parts); // i�� 1�̸� parts�� phone1�� ����
                    break;
                case 2:
                    strcpy(T[j].month, parts); // i�� 2�� parts�� phone2�� ����
                    break;
                case 3:
                    strcpy(T[j].day, parts); // i�� 3�� parts�� memo�� ����
                    break;
                }
                parts = strsep(&str, ":\n"); // buffer�� ���ڿ��� :�� \n ���� �����Ͽ� parts�� ����
                i++;
            }
            j++;
        }
    }
    rewind(fp); // fp�� ���� �����͸� ���� �������� �̵�
}

int count_Phone(FILE* fp)  //fp�� �����ϴ� ������ �� ���� ���� �Լ�
{
    char str[N]; // N ũ���� �迭 ����
    int i = 0;
    while (fgets(str, N, fp) != NULL) // fp�� �о NULL�� �ƴҶ� ����
        i++;
    rewind(fp); // fp�� ���� �����͸� ���� �������� �̵�
    return i;
}

int main(void)
{
    int year, month;
    FILE* fp2 = fopen("toeic.txt", "r"); // data.txt�� r+�� ����
    m = count_Toeic(fp2); // �������� �� ���� ���� n�� ����
    T = (TOEIC*)calloc(m, sizeof(TOEIC));  // ��ȭ��ȣ �����͸� �����ϴ� ���� �迭
    Coption(fp2); // print �Լ��� �Է¹��� year�� month �׸���
    return 0;
}