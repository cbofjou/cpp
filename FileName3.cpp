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
        printf("С��");
    }
    else
    {
        printf("���");
    }
    return 0;
}