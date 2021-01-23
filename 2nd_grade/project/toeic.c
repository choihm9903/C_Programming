#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 256
#define MAX 64

int day[] = { 31, 28, 31, 30, 31, 30, 31,31, 30, 31, 30, 31 };  // �迭�� 1~12�� ���� ��������¥ �ֱ�

typedef struct
{
    char year[MAX]; // ����
    char month[MAX]; // ��
    char day[MAX]; // ��
}TOEIC;

typedef struct
{
    char enlgish[MAX]; // ���� �ܾ�
    char korean1[MAX]; // �ѱ� ��1
    char korean2[MAX]; // �ѱ� �� 2
}Word;

int n; // word.txt�� ��ü �迭�� ��
int m; // toeic.txt�� ��ü �迭�� ��
Word* list;  // word.txt�� �����迭
TOEIC* T; // toeic.txt�� �����迭

void Aoption(Word* arr, int a, char* A[]); // a �ɼ� �Լ�, ����ܾ� ���� �����Ϳ� �߰��ϴ� �Լ�
void Doption(Word* arr, char* A[]); // d �ɼ� �Լ� , ����ܾ� ���� �����Ϳ��� �����ϴ� �Լ�
void Eloption(Word* arr, int n); // el �ɼ� �Լ�, ���� ���� ������ �����ϴ� �Լ� 
void Kloption(Word* arr, int n);  // kl �ɼ� �Լ�, �ѱ��� �� ���� ������ �����ϴ� �Լ�
void Roption(Word* arr, int n); // r �ɼ� �Լ�, ���� ���� �� �ݴ�� �����ϴ� �Լ�
void Rtoption(Word* arr, int n); // rt �ɼ� �Լ�, ���� �׽�Ʈ �Լ�
void Dtoption(Word* arr, int n); // dt �ɼ� �Լ�, ���� �׽�Ʈ �Լ�
void Coption(FILE* fp); // c �ɼ� �Լ�, ���� ��¥�� �޿� ���� ���������� �޷����� ����ϴ� �Լ�
void Findoption(Word* arr, char* A[]); // ã�� ���� ����ܾ� �Ǵ� �ѱ��� ���� �Է��ϸ� ����ܾ� ���� �����Ϳ��� ã�� �Լ�
void Use(Word* arr); // ������ �����ϴ� �Լ�
void Swap(Word* p, Word* q); // p�� q�� �ٲٴ� �Լ�
int count_line(FILE* fp); // �������� �� ���� ���� �Լ�
void read_Word(FILE* fp); // word.txt������ �����͸� �о list�� �����ϴ� �Լ�
void read_Toeic(FILE* fp); // toeic.txt������ �����͸� �о T�� �����ϴ� �Լ�
void print_Word(); // ����ܾ� ���� �����͸� ����ϴ� �Լ�
void write_Word(FILE* fp); // ����ܾ� ���� �����͸� word.txt�� ���� �Լ�
void data_erase(char* filename); // filename�� �����͸� �ʱ�ȭ�ϴ� �Լ�
int search(char s[], char t[]); // ���ڿ� s�� ���ڿ� t�� �ִ��� Ȯ���ϴ� �Լ�
int yoon(int year); // �ش� ������ �������� Ȯ���ϴ� �Լ�
int Firstday(int year, int month); // �ش� ���� ù° �� ������ Ȯ���ϴ� �Լ� 
void print(int year, int month, int first); // �ش� ���� �޷��� ����ϴ� �Լ�
int toeic_day(int year, int month, int day); // �ش� ��¥�� ���ͽ������� Ȯ���ϴ� �Լ�
void printColorString(int color, int* i); // ������ �ٸ��� ����ϴ� �Լ�
char* strsep(char** stringp, const char* delim);

int main(int argc, char* argv[])
{
    FILE* fp = fopen("word.txt", "r+"); // word.txt�� r+�� ����
    FILE* fp2 = fopen("toeic.txt", "r"); // toeic.txt�� r�� ����
    n = count_line(fp); // �������� �� ���� ���� n�� ����
    m = count_line(fp2); // �������� �� ���� ���� m�� ����
    list = (Word*)calloc(n, sizeof(Word)); // ������� �����͸� �����ϴ� ���� �迭
    T = (TOEIC*)calloc(m, sizeof(TOEIC)); // ���ͽ��� ��¥�� �����ϴ� ���� �迭
    read_Word(fp); // word.txt�� �о list�� �����ϴ� �Լ�
    read_Toeic(fp2); // toeic.txt�� �о T�� �����ϴ� �Լ� 
    if (argc > 1 && strcmp(argv[1], "-a") == 0) // -a�� �ԷµǸ�
        Aoption(list, argc, argv);  // a �ɼ� ����
    else if (argc > 1 && strcmp(argv[1], "-d") == 0) // -d�� �ԷµǸ�
        Doption(list, argv); // d �ɼ� ����
    else if (argc > 1 && strcmp(argv[1], "-el") == 0) // -el�� �ԷµǸ�
        Eloption(list, n); // el �ɼ� ����
    else if (argc > 1 && strcmp(argv[1], "-kl") == 0) // -kl�� �ԷµǸ�
        Kloption(list, n); // kl �ɼ� ����
    else if (argc > 1 && strcmp(argv[1], "-r") == 0) // -r�� �ԷµǸ�
        Roption(list, n); // r �ɼ� ����
    else if (argc > 1 && strcmp(argv[1], "-rt") == 0) // -rt�� �ԷµǸ�
        Rtoption(list, n); // rt �ɼ� ����
    else if (argc > 1 && strcmp(argv[1], "-dt") == 0) // -dt�� �ԷµǸ�
        Dtoption(list, n); // dt �ɼ� ����
    else if (argc > 1 && strcmp(argv[1], "-c") == 0) // -c�� �ԷµǸ�
        Coption(fp2); // c �ɼ� ����
    else if (argc > 1) // ã�� ���� ���� �ԷµǸ�
        Findoption(list, argv); // find �ɼ� ����
    else // �ƹ� ���� �Էµ��� ������
        Use(list); // ���� ���
    data_erase("word.txt"); // word.txt�� �ʱ�ȭ
    write_Word(fp); // word.txt�� list ���� ����
    free(list);
    free(T);
    fclose(fp);
    fclose(fp2);
    return 0;
}

void Aoption(Word* arr, int a, char* A[]) // a �ɼ� �Լ�, ������� �����Ϳ� �߰��ϴ� �Լ�
{
    char Y;
    int i;
    n++; // ������� �������� ���� 1�� ����
    realloc(list, sizeof(Word) * n); // list�� ũ�� n�� �ٽ� �Ҵ�
    for (i = 2; i < a; i++)
        printf("%s ", A[i]); // �Է��� �� ���
    printf("\nadd? [Y/N]: ");
    scanf("%c", &Y);
    if (Y == 'Y') // Y�� �Է¹�����
    {
        strcpy(list[n - 1].korean1, "\0"); // realloc���� �Ҵ�� ������ ���� �ʱ�ȭ
        strcpy(list[n - 1].korean2, "\0"); // realloc���� �Ҵ�� ������ ���� �ʱ�ȭ
        switch (a)
        {
        case 5:
            strcpy(list[n - 1].korean2, A[4]); // ���� �Ҵ�� ������ korean2�� �Է�
        case 4:
            strcpy(list[n - 1].korean1, A[3]); // ���� �Ҵ�� ������ korean1�� �Է�
        case 3:
            strcpy(list[n - 1].enlgish, A[2]); // ���� �Ҵ�� ������ english�� �Է�
        default:
            break;
        }
    }
    else // Y�� �Էµ��� ������
    {
        n--; // �ø� ��ȭ��ȣ �������� ���� ������� ����
        realloc(list, sizeof(Word) * n); // list�� ũ�⸦ ������ ������ �Ҵ�
    }
    print_Word(); // ������� �����͸� ���
}

void Doption(Word* arr, char* A[]) // d �ɼ� �Լ�, ������� �����Ϳ��� �����ϴ� �Լ�
{
    int index[N]; // �˻��� ���� �ε����� �����ϴ� �迭
    int i, j;
    int a = 0;
    int b; // ����� ���� ��ȣ�� �Է¹޴� ����
    for (i = 0; i < n; i++)
    {
        if (search(arr[i].enlgish, A[2]) || search(arr[i].korean1, A[2]) || search(arr[i].korean2, A[2])) // A[2]�� ������ ��
        {
            printf("%d %s %s %s\n", a + 1, list[i].enlgish, list[i].korean1, list[i].korean2); // ������ ���� ������ ������ ��� ���
            index[a] = i; // ������ ���� �ε����� ����
            a++;
        }
    }
    if (a > 0) // ������ ���� �����Ϳ� ������
    {
        printf("which one? ");
        scanf("%d", &b);
        if (a >= b) // a ���� ���� ���� �Է��ϸ�
        {
            for (j = index[b - 1]; j < n; j++) // ������ �� �ں��� �ϳ� ������ �����
                list[j] = list[j + 1];
            n--;
            realloc(arr, sizeof(Word) * n); // �ڿ� ���� ���� �����
        }
        else // a ���� ���� ���� �Է��ϸ�
            printf("out of range\n");
    }
    else // ������ ���� �����Ϳ� ������
        printf("no match found.\n");
    print_Word(); // ������� �����͸� ���
}

void Eloption(Word* arr, int n) // l �ɼ� �Լ�, ����ܾ ���� ������ �����ϴ� �Լ� 
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (strcmp(arr[i].enlgish, arr[j].enlgish) < 0)  //arr[i].num�� arr[j].num���� ������ 0���� ������ ��ȯ
                Swap(&arr[i], &arr[j]); //Swap�Լ��� �̿��� ���� �ٲٱ� 
        }
    }
    print_Word(); // ������� �����͸� ���
}

void Kloption(Word* arr, int n) // kl �ɼ� �Լ�, �ѱ��� ���� ���� ������ �����ϴ� �Լ�
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (strcmp(arr[i].korean1, arr[j].korean1) < 0)  //arr[i].num�� arr[j].num���� ������ 0���� ������ ��ȯ
                Swap(&arr[i], &arr[j]); //Swap�Լ��� �̿��� ���� �ٲٱ� 
        }
    }
    print_Word(); // ������� �����͸� ���
}

void Roption(Word* arr, int n) // r �ɼ� �Լ�, ����ܾ ���� �� �ݴ�� �����ϴ� �Լ�
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (strcmp(arr[i].enlgish, arr[j].enlgish) > 0)  //arr[i].num�� arr[j].num���� ������ 0���� ������ ��ȯ
                Swap(&arr[i], &arr[j]); //Swap�Լ��� �̿��� ���� �ٲٱ� 
        }
    }
    print_Word(); // ������� �����͸� ���
}

void Rtoption(Word* arr, int n) // rt �ɼ� �Լ�, ���� �׽�Ʈ �Լ�
{
    int num, number, i;
    int correct = 0; // ���� Ƚ��(0���� �ʱ�ȭ)
    char korean[MAX]; // ��(�ѱ��� ��)�� ���� �迭
    srand(time(NULL));
    printf("���� ���� �׽�Ʈ ���\n");
    printf("Ǯ�� ���� ��������: "); // Ǯ�� ���� �������� �Է�
    scanf("%d", &number);
    for (i = 0; i < number; i++)
    {
        num = rand() % n; // 0���� n-1���� ��������
        printf("%s : ", arr[num].enlgish);
        scanf("%s", korean); // ��(�ѱ��� ��)�� �迭�� ����
        if (!strcmp(arr[num].korean1, korean) || !strcmp(arr[num].korean2, korean)) // ���� ���� �� '�����Դϴ�'�� ����ϰ� ���� Ƚ���� ����
        {
            printf("�����Դϴ�.\n");
            correct++;
        }
        else // ���� Ʋ�� �� '�����Դϴ�'�� ������ �����
        {
            printf("�����Դϴ�.\t");
            printf("%s : %s\n", arr[num].enlgish, arr[num].korean1);
        }
    }
    printf("���� ����:%d, Ʋ�� ����:%d\n", correct, number - correct); // ���� Ƚ���� Ʋ�� Ƚ���� �����
}

void Dtoption(Word* arr, int n) // dt �ɼ� �Լ�, ���� �׽�Ʈ �Լ�
{
    int number, i, j;
    int correct = 0; // ���� Ƚ��(0���� �ʱ�ȭ)
    int incorrect = 0; // Ʋ�� Ƚ��(0���� �ʱ�ȭ)
    int index; // �˻��� �ܾ��� �ε���
    char english[MAX]; // ������ ����ܾ�
    char korean[MAX]; // ������ �ѱ��� ��
    printf("���� ���� �׽�Ʈ ���\n");
    printf("Ǯ�� ���� ��������: "); // Ǯ�� ���� �������� �Է� 
    scanf("%d", &number);
    for (i = 0; i < number; i++)
    {
        index = -1;
        int num = n;
        printf("����: ");
        scanf("%s", english); // Ǯ�� ���� ������ ����ܾ� �Է�
        printf("��: ");
        scanf("%s", korean); // ������ �ѱ��� �� �Է�
        for (j = 0; j < n; j++)
            if (!strcmp(english, arr[j].enlgish)) // Ǯ�� ���� ������ ����ܾ ������� �����Ϳ� �����ϴ��� Ȯ��
                index = j;
        if (index == -1) // ������� �����Ϳ� �������� ������ '��������� �����ϴ�.' �� ���
            printf("%s�� ��������� �����ϴ�.\n", english);
        else // ������� �����Ϳ� �����Ҷ�
        {
            if (!strcmp(arr[index].korean1, korean) || !strcmp(arr[index].korean2, korean)) // ���� ���� �� '�����Դϴ�'�� ����ϰ� ���� Ƚ���� ����
            {
                printf("�����Դϴ�.\n");
                correct++;
            }
            else // ���� Ʋ�� �� '�����Դϴ�'�� ������ ����ϰ� Ʋ�� Ƚ���� ����
            {
                printf("�����Դϴ�.\t");
                printf("%s : %s\n", arr[index].enlgish, arr[index].korean1);
                incorrect++;
            }
        }
    }
    printf("���� ����:%d, Ʋ�� ����:%d\n", correct, incorrect); // ���� Ƚ���� Ʋ�� Ƚ���� �����
}

void Coption(FILE* fp) // c �ɼ� �Լ�, ���� ��¥�� �޿� ���� ���������� �޷����� ����ϴ� �Լ�
{
    int year, month;
    printf("�⵵�� �Է��ϼ���: ");
    scanf("%d", &year);
    printf("���� �Է��ϼ���: ");
    scanf("%d", &month);
    print(year, month, Firstday(year, month)); // �ش� ������ ���� �޷��� ��� 
}

void Findoption(Word* arr, char* A[]) // ã�� ���� ����ܾ� �Ǵ� �ѱ��� ���� �Է��ϸ� ����ܾ� ���� �����Ϳ��� ã�� �Լ�
{
    int i;
    int a = 0;
    for (i = 0; i < n; i++)
    {
        if (search(arr[i].enlgish, A[1]) || search(arr[i].korean1, A[1]) || search(arr[i].korean2, A[1])) // A[1]�� �˻��� ��
        {
            printf("%d %s %s %s\n", a + 1, list[i].enlgish, list[i].korean1, list[i].korean2); // �˻��� ���� ������ ������ ��� ���
            a++;
        }
    }
    if (a > 0) // �˻��� ���� ������� �����Ϳ� ������
        printf("match found.\n");
    else // �˻��� ���� ������� �����Ϳ� ������
        printf("no match found.\n");
}

void Use(Word* arr) // ������ �����ϴ� �Լ�
{
    printf("NAME \t\tEnglish dictionary - a program that manages English words.\n");
    printf("SYNOPSIS \tdic[-option] words.\n");
    printf("DESCRIPTION \tPrograms that search, add, delete, list, test, calender etc. english words.\n");
    printf("  -a\t\tAdd or exit program if the right number range is in which one ?\n");
    printf("  -d\t\tIf the correct number range is in which one ? , delete the entry or exit the program\n");
    printf("  -el\t\tArrange english dictionaries in order of alphabetic.\n");
    printf("  -kl\t\tArrange english dictionaries in order of korean.\n");
    printf("  -r\t\tArrange english dictionaries in order of reverse alphabetic\n");
    printf("  -rt\t\tWhen a given English word comes out, the Korean language is matched.\n");
    printf("  -dt\t\tEnter English and Korean meaning to solve the problem.\n");
    printf("  -c\t\tEntering the year and month shows the TOEIC date and calendar of the month.\n");
    printf("  words\t\tFind the line to which the word belongs and if there is no output, no match found output\n");
}

void Swap(Word* p, Word* q) // p�� q�� �ٲٴ� �Լ�
{
    Word tmp = *p;
    *p = *q;
    *q = tmp;
}

int count_line(FILE* fp)  //fp�� �����ϴ� ������ �� ���� ���� �Լ�
{
    char str[N]; // N ũ���� �迭 ����
    int i = 0;
    while (fgets(str, N, fp) != NULL) // fp�� �о NULL�� �ƴҶ� ����
        i++;
    rewind(fp); // fp�� ���� �����͸� ���� �������� �̵�
    return i;
}

void read_Word(FILE* fp) // word.txt�� �о list�� �����ϴ� �Լ�
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
            parts = strsep(&str, "."); // buffer�� ���ڿ��� :�� �����Ͽ� parts�� ����
            int i = 0;
            while (parts != NULL) // parts�� NULL�� �ƴҶ� ����
            {
                switch (i)
                {
                case 0:
                    strcpy(list[j].enlgish, parts); // i�� 0�̸� parts�� english�� ����
                    break;
                case 1:
                    strcpy(list[j].korean1, parts); // i�� 1�̸� parts�� korean1�� ����
                    break;
                case 2:
                    strcpy(list[j].korean2, parts); // i�� 2�� parts�� korean2�� ����
                    break;
                }
                parts = strsep(&str, ".\n"); // buffer�� ���ڿ��� :�� \n ���� �����Ͽ� parts�� ����
                i++;
            }
            j++;
        }
    }
    rewind(fp); // fp�� ���� �����͸� ���� �������� �̵�
}

void read_Toeic(FILE* fp) // toeic.txt�� �о T�� �����ϴ� �Լ�
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
            parts = strsep(&str, "."); // buffer�� ���ڿ��� :�� �����Ͽ� parts�� ����
            int i = 0;
            while (parts != NULL) // parts�� NULL�� �ƴҶ� ����
            {
                switch (i)
                {
                case 0:
                    strcpy(T[j].year, parts); // i�� 1�̸� parts�� year�� ����
                    break;
                case 1:
                    strcpy(T[j].month, parts); // i�� 2�� parts�� month�� ����
                    break;
                case 2:
                    strcpy(T[j].day, parts); // i�� 3�� parts�� day�� ����
                    break;
                }
                parts = strsep(&str, ".\n"); // buffer�� ���ڿ��� :�� \n ���� �����Ͽ� parts�� ����
                i++;
            }
            j++;
        }
    }
    rewind(fp); // fp�� ���� �����͸� ���� �������� �̵�
}

void print_Word() // ����ܾ� ���� �����͸� ����ϴ� �Լ�
{
    int i;
    for (i = 0; i < n; i++)
        printf(" %3d %s %s %s\n", i + 1, list[i].enlgish, list[i].korean1, list[i].korean2); // ��� ������� �����͸� ���
}

void write_Word(FILE* fp) // ����ܾ� ���� �����͸� word.txt�� ���� �Լ�
{
    int i;
    for (i = 0; i < n; i++)
        fprintf(fp, "%s.%s.%s\n", list[i].enlgish, list[i].korean1, list[i].korean2); // ��� ������� �����͸� fp�� ����
}

void data_erase(char* filename) // filename�� �����͸� �ʱ�ȭ�ϴ� �Լ�
{
    FILE* fp1 = fopen(filename, "w"); // filename�� �ش��ϴ� txt������ w���� ���� txt���ϳ����� �ʱ�ȭ
    fclose(fp1);
}

int search(char s[], char t[]) // ���ڿ� s�� ���ڿ� t�� �ִ��� Ȯ���ϴ� �Լ�
{
    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) // s[i]�� NULL�� �ƴ� ������
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) // t[k]�� NULL�� �ƴϰ� s[j]�� t[k]�� ������ j++ k++ 
            ;
        if (k > 0 && t[k] == '\0') // ���ڿ� s�� ���ڿ� t�� ���ԵǴ� ��� (k=0���� k++�� �ݺ��Ͽ� t[k]�� NULL�� ���)
            return 1;
    }
    return 0; // ���ڿ� s�� ���ڿ� t�� ���Ե��� �ʴ� ���
}

int yoon(int year) // �ش� ������ �������� Ȯ���ϴ� �Լ�
{ 
    if ((year % 4 == 0) && !(year % 100 == 0) || (year % 400 == 0))
        return 2;  //�����϶��� 2
    else
        return 1;  //������ �ƴ� ���� 1
}

int Firstday(int year, int month) // �ش� ���� ù° �� ������ Ȯ���ϴ� �Լ� 
{
    int total = 0;
    for (int i = 2001; i < year; i++)  // 2001�⵵ ���� ���⵵���� �� �������� ���ϱ� 
        if (yoon(i) == 2)  // �Է��� �⵵�� ������ ��� 2���� �� 366�� ���ϱ� 
            total += 366;
        else
            total += 365;
    for (int i = 1; i <= month - 1; i++) {  // �Է��� �⵵ 1������ �Է��ѳ⵵�� �� �ޱ��� �������� ���ϱ� 
        if (yoon(year) == 2 && i == 2)  // �Է��� �⵵�� ������ ��� 2���� 29�� ���ϱ� 
            total += 29;
        else
            total += day[i - 1];
    }
    return (total % 7);
}

void print(int year, int month, int first) // �ش� ���� �޷��� ����ϴ� �Լ�
{
    int cnt = 0;
    printf("      %d�� %d   \n", month, year);
    printf("�� �� ȭ �� �� �� ��\n");
    if (first == 6)  // first�� 6�ΰ�쿡�� 6���� ������ ���⳪ �Ͽ��Ϻ��� �����̹Ƿ�
        printf("");
    else
    {
        for (int i = 0; i < first + 1; i++) { // ù ��° ���� ������ ���� ����ϱ� 
            printf("   ");
            cnt++;
        }
    }
    if (yoon(year) == 2 && month == 2) { // ������ ��� 2���� 29�ϱ��� ����ϱ� 
        for (int i = 1; i <= day[1] + 1; ++i) {
            if (toeic_day(year, month, i))
                printColorString(43, i);
            else
                printf("%2d ", i);
            cnt++;
            if (cnt % 7 == 0)
                printf("\n");
        }
    }
    else // 2���� �ƴϰ� ������ �ƴҰ�� ����ϱ� 
    {
        for (int i = 1; i <= day[month - 1]; ++i) {
            if (toeic_day(year, month, i)) // �ش� ��¥�� ���ͽ����� ������ ���� �ٲ㼭 ���
                printColorString(43, i);
            else
                printf("%2d ", i);
            cnt++;
            if (cnt % 7 == 0)
                printf("\n");
        }
    }
}

int toeic_day(int year, int month, int day) // �ش� ��¥�� ���ͽ������� Ȯ���ϴ� �Լ�
{
    for (int i = 0; i < m; i++)
        if (atoi(T[i].year) == year && atoi(T[i].month) == month && atoi(T[i].day) == day) // �ش� ��¥�� ���ͽ����̸� 1�� �ƴϸ� 0�� ��ȯ
            return 1;
    return 0;
}

void printColorString(int color, int* i) // ������ �ٸ��� ����ϴ� �Լ�
{
    printf("\033[%dm%2d \033[0m", color, i);
}

char* strsep(char** stringp, const char* delim)
{
    char* ptr = *stringp;
    if (ptr == NULL)
    {
        return NULL;
    }
    while (**stringp)
    {
        if (strchr(delim, **stringp) != NULL)
        {
            **stringp = 0x00; (*stringp)++; return ptr;
        }
        (*stringp)++;
    }
    *stringp = NULL;
    return ptr;
}