#include <stdio.h>

//feof�Լ� ����� ���Ϻ��� ���α׷�
int main(void)
{
	FILE* src = fopen("src.txt", "rt");
	FILE* dest = fopen("dest.txt", "wt");
	int ch;
	if (src == NULL || dest == NULL)
	{
		puts("���Ͽ��� ����!");
		return -1;
	}
	while ((ch=fgetc(src)) != EOF)
	{
		fputc(ch, dest);
	}
	fclose(src);
	fclose(dest);
	return 0;
}

//���ڿ� ���� ���Ϻ��� ���α׷�
int main(void)
{
	FILE* src = fopen("src.txt", "rt");
	FILE* dest = fopen("dest.txt", "wt");
	char str;
	if (src == NULL || dest == NULL)
	{
		puts("���Ͽ��� ����!");
		return -1;
	}
	while (fgets(str,sizeof(str),src) != NULL)
	{
		fputs(str, dest);
	}
	fclose(src);
	fclose(dest);
	return 0;
}