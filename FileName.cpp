#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int c, i = 2, e = 2, l = 0;
	int ch[1005] = { 0 };
	scanf_s("%d %d %d", &ch[0], &ch[1], &c);

	for (l = 0;e < c + 1;l++)
	{
		ch[e] = ch[i - 1] * ch[i - 2];
		if (ch[e] > 9)
		{
			ch[e] = (ch[i - 1] * ch[i - 2]) / 10;
			e++;
			ch[e] = (ch[i - 1] * ch[i - 2]) % 10;

		}
		e++;
		i++;
	}
	printf("%d", ch[0]);
	for (i = 1;i < c;i++)
	{
		printf(" %d", ch[i]);
	}
	return 0;
}