判断大小端

#include<stdio.h>
#include<string.h>
#include<math.h>
int test()
{
    int i = 1;
    return *(char*)&i;
}
int main()
{
    if (test() == 1)
    {
        printf("小端");
    }
    else
    {
        printf("大端");
    }
    return 0;
}
