链表实现集合差


#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

struct jiedian
{
	int a;
	struct jiedian* next;
};
struct jiedian* jllb(int num)
{
	struct jiedian* head = NULL;
	struct jiedian* last = NULL;
	struct jiedian* p = NULL;
	for (int i = 0;i < num;i++)
	{
		p = (struct jiedian*)malloc(sizeof(struct jiedian));
		if (p == NULL)
		{
			printf("开辟空间错误！");
			return 0;
		}
		else
		{
			scanf_s("%d", &p->a);
			if (i == 0)
			{
				head = p;
				last = p;
				last->next = NULL;
			}
			else
			{
				last->next = p;
				last = p;
				last->next = NULL;
			}
		}
	}
	return head;
}
void cj(struct jiedian* head1, struct jiedian* head2,int num1,int num2)
{
	printf("集合A-B=");
	struct jiedian* head = head2;
	int flag = 0, flag2 = 0;
	for (int i = 0;i < num1;i++)
	{
		for (int j = 0;j < num2;j++)
		{
			if (head1->a == head2->a)
			{
				flag++;
			}
			head2 = head2->next;
		}
		if (flag == 0)
		{
			printf("%d ", head1->a);
			flag2++;
		}
		flag = 0;
		head2 = head;
		head1 = head1->next;
	}
	if (flag2 == 0)
	{
		printf("空");
	}
}
int main()
{
	int num1 = 0;
	scanf_s("%d", &num1);
	struct jiedian* head1 = jllb(num1);
	int num2 = 0;
	scanf_s("%d", &num2);
	struct jiedian* head2 = jllb(num2);
	cj(head1, head2, num1, num2);
	free(head1);
	free(head2);
	return 0;
}
