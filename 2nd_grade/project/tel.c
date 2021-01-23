#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 256

typedef struct
{
    char name[30];
    char phone1[20];
    char phone2[20];
    char memo[40];
}Phone;

int n; // ��ü �迭�� ��
Phone* slist;  //�����迭

void Aoption(Phone* arr, int a, char* A[]); // a �ɼ� �Լ�, ��ȭ��ȣ �����Ϳ� �߰��ϴ� �Լ�
void Doption(Phone* arr, char* A[]); // d �ɼ� �Լ� , ��ȭ��ȣ �����Ϳ��� �����ϴ� �Լ�
void Loption(Phone* arr, int n); // l �ɼ� �Լ�, ������ �����ϴ� �Լ� 
void Findoption(Phone* arr, char* A[]); // ã�� ���� ���ڿ��� �Է��ϸ� ��ȭ��ȣ �����Ϳ��� ã�� �Լ� 
void Use(Phone* arr); // ������ �����ϴ� �Լ�
void Swap(Phone* p, Phone* q); // p�� q�� �ٲٴ� �Լ�
int count_Phone(FILE* fp); // �������� �� ���� ���� �Լ�
void read_Phone(FILE* fp); // data.txt�� �о slist�� �����ϴ� �Լ�
void print_Phone(); // ��ȭ��ȣ �����͸� ����ϴ� �Լ�
void write_Phone(FILE* fp); // slist ���� data.txt�� ���� �Լ�
void data_erase(char* filename); // filename�� �����͸� �ʱ�ȭ�ϴ� �Լ�
int search(char s[], char t[]); // ���ڿ� s�� ���ڿ� t�� �ִ��� Ȯ���ϴ� �Լ�
char* strsep(char** stringp, const char* delim);

int main(int argc, char* argv[])
{
    FILE* fp = fopen("data.txt", "r+"); // data.txt�� r+�� ����
    n = count_Phone(fp); // �������� �� ���� ���� n�� ����
    slist = (Phone*)calloc(n, sizeof(Phone));  // ��ȭ��ȣ �����͸� �����ϴ� ���� �迭
    read_Phone(fp);  //data.txt�� �о slist�� �����ϴ� �Լ�
    if (argc > 1 && strcmp(argv[1], "-a") == 0) // -a�� �ԷµǸ�
        Aoption(slist, argc, argv);  // a �ɼ� ����
    else if (argc > 1 && strcmp(argv[1], "-d") == 0) // -d�� �ԷµǸ�
        Doption(slist, argv); // d �ɼ� ����
    else if (argc > 1 && strcmp(argv[1], "-l") == 0) // -l�� �ԷµǸ�
        Loption(slist, n); // l �ɼ� ����
    else if (argc > 1) // ã�� ���� ���� �ԷµǸ�
        Findoption(slist, argv); // find �ɼ� ����
    else // �ƹ� ���� �Էµ��� ������
        Use(slist); // ���� ���
    data_erase("data.txt"); // data.txt�� �ʱ�ȭ
    write_Phone(fp); //fp�� slist ���� ����
    free(slist);
    fclose(fp);
    return 0;
}

void Swap(Phone* p, Phone* q) // p�� q�� �ٲٴ� �Լ�
{
    Phone tmp = *p;
    *p = *q;
    *q = tmp;
}

void Aoption(Phone* arr, int a, char* A[]) // a �ɼ� �Լ�, ��ȭ��ȣ �����Ϳ� �߰��ϴ� �Լ�
{
    char Y;
    int i;
    n++; // ��ȭ��ȣ �������� ���� 1�� ����
    realloc(slist, sizeof(Phone) * n); // slist�� ũ�� n�� �ٽ� �Ҵ�
    for (i = 2; i < a; i++)
        printf("%s ", A[i]); // �Է��� �� ���
    printf("\nadd? [Y/N]: ");
    scanf("%c", &Y);
    if (Y == 'Y') // Y�� �Է¹�����
    {
        strcpy(slist[n - 1].phone1, "\0"); // realloc���� �Ҵ�� ������ ���� �ʱ�ȭ
        strcpy(slist[n - 1].phone2, "\0"); // realloc���� �Ҵ�� ������ ���� �ʱ�ȭ
        strcpy(slist[n - 1].memo, "\0"); // realloc���� �Ҵ�� ������ ���� �ʱ�ȭ
        switch (a)
        {
        case 6:
            strcpy(slist[n - 1].memo, A[5]); // ���� �Ҵ�� ������ memo�� �Է�
        case 5:
            strcpy(slist[n - 1].phone2, A[4]); // ���� �Ҵ�� ������ phone2�� �Է�
        case 4:
            strcpy(slist[n - 1].phone1, A[3]); // ���� �Ҵ�� ������ phone1�� �Է�
        case 3:
            strcpy(slist[n - 1].name, A[2]); // ���� �Ҵ�� ������ name�� �Է�
        default:
            break;
        }
    }
    else // Y�� �Էµ��� ������
    {
        n--; // �ø� ��ȭ��ȣ �������� ���� ������� ����
        realloc(slist, sizeof(Phone) * n); // slist�� ũ�⸦ ������ ������ �Ҵ�
    }
    print_Phone(); // ��ȭ��ȣ �����͸� ���
}

void Doption(Phone* arr, char* A[]) // d �ɼ� �Լ�, ��ȭ��ȣ �����Ϳ��� �����ϴ� �Լ�
{
    int index[N]; // �˻��� ���� �ε����� �����ϴ� �迭
    int i, j;
    int a = 0;
    int b; // ����� ���� ��ȣ�� �Է¹޴� ����
    for (i = 0; i < n; i++)
    {
        if (search(arr[i].name, A[2]) || search(arr[i].phone1, A[2]) || search(arr[i].phone2, A[2]) || search(arr[i].memo, A[2])) // A[2]�� ������ ��
        {
            printf("%d %s %s %s %s\n", a + 1, slist[i].name, slist[i].phone1, slist[i].phone2, slist[i].memo); // ������ ���� ������ ������ ��� ���
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
                slist[j] = slist[j + 1];
            n--;
            realloc(arr, sizeof(Phone) * n); // �ڿ� ���� ���� �����
        }
        else // a ���� ���� ���� �Է��ϸ�
            printf("out of range\n");
    }
    else // ������ ���� �����Ϳ� ������
        printf("no match found.\n");
    print_Phone(); // ��ȭ��ȣ �����͸� ���
}

void Loption(Phone* arr, int n) // l �ɼ� �Լ�, ������ �����ϴ� �Լ� 
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (strcmp(arr[i].name, arr[j].name) < 0)  //arr[i].num�� arr[j].num���� ������ 0���� ������ ��ȯ
                Swap(&arr[i], &arr[j]); //Swap�Լ��� �̿��� ���� �ٲٱ� 
        }
    }
    print_Phone(); // ��ȭ��ȣ �����͸� ���
}

void Findoption(Phone* arr, char* A[]) // ã�� ���� ���ڿ��� �Է��ϸ� ��ȭ��ȣ �����Ϳ��� ã�� �Լ� 
{
    int i;
    int a = 0;
    for (i = 0; i < n; i++)
    {
        if (search(arr[i].name, A[1]) || search(arr[i].phone1, A[1]) || search(arr[i].phone2, A[1]) || search(arr[i].memo, A[1])) // A[1]�� �˻��� ��
        {
            printf("%d %s %s %s %s\n", a + 1, slist[i].name, slist[i].phone1, slist[i].phone2, slist[i].memo); // �˻��� ���� ������ ������ ��� ���
            a++;
        }
    }
    if (a > 0) // �˻��� ���� ��ȭ��ȣ �����Ϳ� ������
        printf("match found.\n");
    else // �˻��� ���� ��ȭ��ȣ �����Ϳ� ������
        printf("no match found.\n");
}

void Use(Phone* arr) // ������ �����ϴ� �Լ�
{
    printf("NAME \t\ttel - telephone number management program\n");
    printf("SYNOPSIS \ttel[-option] words\n");
    printf("DESCRIPTION \tPrograms that search, add, delete, list, etc. phone numbers\n");
    printf("  words\t\tFind the line to which the word belongs and if there is no output, no match found output\n");
    printf("  -a\t\tAdd or exit program if the right number range is in which one ?\n");
    printf("  -d\t\tIf the correct number range is in which one ? , delete the entry or exit the program\n");
    printf("  -l\t\tutput a complete list with an Alphabetical order of the name\n");
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

void read_Phone(FILE* fp) // data.txt�� �о slist�� �����ϴ� �Լ�
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
                    strcpy(slist[j].name, parts); // i�� 0�̸� parts�� name�� ����
                    break;
                case 1:
                    strcpy(slist[j].phone1, parts); // i�� 1�̸� parts�� phone1�� ����
                    break;
                case 2:
                    strcpy(slist[j].phone2, parts); // i�� 2�� parts�� phone2�� ����
                    break;
                case 3:
                    strcpy(slist[j].memo, parts); // i�� 3�� parts�� memo�� ����
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

void print_Phone()
{
    int i;
    for (i = 0; i < n; i++)
        printf("%s %s %s %s\n", slist[i].name, slist[i].phone1, slist[i].phone2, slist[i].memo); // ��� ��ȭ��ȣ �����͸� ���
}

void write_Phone(FILE* fp)
{
    int i;
    for (i = 0; i < n; i++)
        fprintf(fp, "%s:%s:%s:%s\n", slist[i].name, slist[i].phone1, slist[i].phone2, slist[i].memo); // ��� ��ȭ��ȣ �����͸� fp�� ����
}

void data_erase(char* filename)
{
    FILE* fp1 = fopen(filename, "w"); // filename�� �ش��ϴ� txt������ w���� ���� txt���ϳ����� �ʱ�ȭ
    fclose(fp1);
}

int search(char s[], char t[])
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