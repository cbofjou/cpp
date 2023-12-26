高精度乘法


#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    char ch[205] = { 0 }, arr[205] = { 0 };
    int count[500] = { 0 };
    int m = 0, n = 0;
    gets(ch);
    gets(arr);
    m = strlen(ch);
    n = strlen(arr);
    int a = 0;
    int yu = 0;
    for (int i = m - 1;i >= 0;i--)                                   //此处将对应位上数相乘并相加，先不进位
    {
        a = m - i - 1;
        for (int j = n - 1; j >= 0;j--)
        {
            count[a] = (count[a] + ((arr[j] - '0') * (ch[i] - '0')));
            a++;
        }
    }
    for (int i = 0;i <= a;i++)                                       //此处才开始进位，这样简洁，可读性强
    {
        count[i + 1] = count[i + 1] + count[i] / 10;
        count[i] = count[i] % 10;
    }
    while (count[a] == 0 && a > 0)
    {
        a--;
    }
    for (int i = a;i >= 0;i--)
        printf("%d", count[i]);
    return 0;
}
