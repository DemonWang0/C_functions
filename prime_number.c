#include <stdio.h>
#include <stdlib.h>

typedef struct number_list {
	int number;
	struct number_list *next;
} numList;

/**
 * primeNumber: 筛选质数函数
 * @head: 指向numList结构体的链表表头
 * @count: 从1开始的count个正整数
 */ 
void primeNumber(numList *head, int count)
{
	int i, key;
	numList *temp, *tail, *pre;	/* pre用来存储被删结点的上一个结点 */ 
	tail = head;

	/* 构建链表 */ 
	for (i = 1; i <= count; i++)
	{
		temp = (numList *)malloc(sizeof(numList));
		temp->number = i;
		temp->next = head;
		tail->next = temp;
		tail = temp;
	}

	/* 质数只能被1和自身整除，所以从2开始计算 */ 
	for (tail = head->next->next; tail->number != 0; tail = tail->next)
	{
		key = tail->number;
		pre = tail;
		for (temp = tail->next; temp->number != 0; temp = temp->next)
		{
			if (temp->number % key == 0)
			{
				pre->next = pre->next->next;
				free(temp);
				temp = pre;
			}
			pre = temp;
		}
	}

	i = 1;
	for (head = head->next; head->number != 0; head = head->next)
	{
		printf("%d\t", head->number);
		i++;
		if (i == 5)
		{
			printf("\n");
			i = 1;
		}
	}
}


int main(void)
{
	numList *head;
	int count;

	head = (numList *)malloc(sizeof(numList));
	head->number = 0; 	/* 将头结点的键值设为0，可作为循环判断的标志 */ 
	head->next = head;

	printf("Numbers: ");
	scanf("%d", &count);

	primeNumber(head, count);

	return 0;
}


