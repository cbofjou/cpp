#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char ch[105] = {0};
    gets(ch);
    int a = 0;
    scanf("%d", &a);
    int len = strlen(ch);
    int m = 0;
    int yu = 0;
    int arr[105] = { 0 };
    for (int i = 0;i <= len - 1;i++)
    {
        m = yu * 10 + (ch[i] - '0');
        if (m >= a)
        {
            arr[i] = m / a;
            yu = m % a;
        }
        else
        {
            arr[i] = 0;
            yu = m;
        }
    }
    int i = 0;
    while (arr[i++]==0)
    {
        ;
    }
    for (int j = i - 1;j <= len - 1;j++)
    {
        printf("商为：%d", arr[j]);
    }
    printf("\n余为；%d", yu);
    return 0;
}
