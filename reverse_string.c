#include <stdio.h>

void reverse_string(char *string)
{
	int strSize;
	char *tempStr = string;
	char temp;

	/* 获取字符串长度 */ 
	for (strSize = 0; *tempStr != '\0'; tempStr++)
		strSize++;

	for (int i = 0; i < (strSize / 2); i++)
	{
		temp = *(string + i);
		*(string + i) = *(string + strSize -1 - i);
		*(string + strSize - 1) = temp;
	}
}

int main(void)
{
	char str[10];

	scanf("%s", str);
	printf("reversing...\n");
	reverse_string(str);
	printf("%s\n", str);

	return 0;
}

