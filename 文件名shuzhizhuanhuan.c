自定义进制转换
范围是2进制到16进制之间
openjudge 1.13.1


#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	long long a = 0, b = 0;
	char ch[100] = { 0 };
	char arr[100] = { 0 };
	long long ten = 0;
	char pth[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	scanf("%lld", &a);
	getchar();
	scanf("%s %lld", &ch, &b);
	long long m = 0;
	for (int i = strlen(ch) - 1;i >= 0;i--)
	{
		if (ch[i] >= '0' && ch[i] <= '9')
		{
			ten = ten + (ch[i] - '0') * pow(a, m);
			m++;
			continue;
		}
		if (ch[i] >= 'A' && ch[i] <= 'F')
		{
			ten = ten + (ch[i] - '7') * pow(a, m);
			m++;
			continue;
		}
		if (ch[i] >= 'a' && ch[i] <= 'f')
		{
			ten = ten + (ch[i] - 'W') * pow(a, m);
			m++;
			continue;
		}
	}
	long long i = 0;
	for (i = 0;1;i++)
	{
			arr[i] = pth[ten % b];
			ten = ten / b;
			if (ten == 0)
			{
				break;
			}
	}
	for (long long j = i;j >= 0;j--)
	{
		printf("%c", arr[j]);
	}
	return 0;
}
