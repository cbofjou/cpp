#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	/*int a;
	scanf_s("%d", &a);*/
	//int* p = (int*)malloc(sizeof(int)*a);
	int* p = (int*)calloc(1,sizeof(int));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{ 
		for (int i = 0;i < 1;i++)
		{
			*(p + i) = i;
		}
	}
	printf("%p\n", p);
	int* p1 = (int*)realloc(p, 8);
	printf("%p\n",p);
	printf("%p\n", p1);
	if (p1 != NULL)
	{
		p = p1;
	}
	printf("%p\n", p);
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		for (int i = 1;i < 2;i++)
		{
			*(p + i) = i;
		}
		for (int i = 0;i < 2;i++)
		{
			printf("%d ", *(p + i));
		}
	}
	free(p);
	p = NULL;
	p1 = NULL;
	return 0;
}