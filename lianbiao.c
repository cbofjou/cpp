#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
struct dsb
{
	int n;
	int* c;
};
int main()
{
    struct dsb* p=(struct dsb*)malloc(sizeof(struct dsb));
    p->c=(struct dsb*)malloc(sizeof(int)*5);
	return 0;
}