openjudge 1.8 25



#include<stdio.h>
#include<string.h>
#include<math.h>
void dsb(char ch, int pch[5])
{
	for (int i = 0;i < 5;i++)
	{
		pch[i] = 0;
	}
	int m = 0, flag = 0;
	if (ch == ' ')
	{
		m = 0;
	}
	else
	{
		m = ch - '@';
	}
	for (int j = 0;flag != 1;j++)
	{
		pch[j] = m % 2;
		m = m / 2;
		if (m == 0)
		{
			flag = 1;
		}
	}
}
int main()
{
	int a, b, c = 0, d = 0, m = 0;
	char ch[90] = { 0 };
	int arr[21][21] = { 0 };
	int tmp[450] = { 0 };
	int pch[5] = { 0 };
	scanf_s("%d %d", &a, &b);
	getchar();
	gets_s(ch);
	c = strlen(ch);
	for (int i = 0;i < c;i++)
	{
		dsb(ch[i], pch);
		for (int j = 4;j >= 0;j--)
		{
			tmp[d++] = pch[j];
		}
	}
	for (int i = 0;i < 21;i++)
	{
		for (int j = 0;j < 21;j++)
		{
			arr[i][j] = -1;
		}
	}
	int k = 0, l = -1;
	for (int n = 0;1;n++)
	{
		for (int j = l + 1;j < b;j++)
		{
			int i = k;
			if (arr[i][j] != -1)
			{
				break;
			}
			arr[i][j] = tmp[m];
			m++;
			if (m == d)
			{
				break;
			}
			k = i;
			l = j;

		}
		if (m == d)
		{
			break;
		}
		for (int i = k + 1;i < a;i++)
		{
			int j = l;
			if (arr[i][j] != -1)
			{
				break;
			}
			arr[i][j] = tmp[m];
			m++;
			if (m == d)
			{
				break;
			}
			k = i;
			l = j;
		}
		if (m == d)
		{
			break;
		}
		for (int j = l - 1;j >= 0;j--)
		{
			int i = k;
			if (arr[i][j] != -1)
			{
				break;
			}
			arr[i][j] = tmp[m];
			m++;
			if (m == d)
			{
				break;
			}
			k = i;
			l = j;
		}
		if (m == d)
		{
			break;
		}
		for (int i = k - 1;i >= 0;i--)
		{
			int j = l;
			if (arr[i][j] != -1)
			{
				break;
			}
			arr[i][j] = tmp[m];
			m++;
			if (m == d)
			{
				break;
			}
			k = i;
			l = j;
		}
		if (m == d)
		{
			break;
		}
	}
	for (int i = 0;i < a;i++)
	{
		for (int j = 0;j < b;j++)
		{
			if (arr[i][j] == -1)
			{
				printf("0");
				continue;
			}
			printf("%d", arr[i][j]);
		}
	}
	return 0;
}
