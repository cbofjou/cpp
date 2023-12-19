// #include<stdio.h>
// #include<math.h>
// #include<string.h>
// #include<stdlib.h>
// #include<windows.h>
// struct dsb
// {
// 	int n;
// 	int ch[0];
// };
// int main()
// {
//     int a;
//     scanf("%d",&a);
// 	struct dsb* p=(struct dsb*)malloc(sizeof(struct dsb)+a*sizeof(int));
//     p->n=100;
//     for(int i=0;i<a;i++)
//     {
//         p->ch[i]=i;
//     }
//     for(int i=0;i<a;i++)
//     {
//         if(i==0)
//         {
//             printf("%d\n",p->n);
//         }
//         printf("%d ",p->ch[i]);
//     }
//     printf("\n");
//     int b=0;
//     scanf("%d",&b);
//     struct dsb* q=(struct dsb*)realloc(p,sizeof(struct dsb)+(a+b)*sizeof(int));
//     if(q!=NULL)
//     {
//         p=q;
//     }
//     for(int i=a;i<a+b;i++)
//     {
//         p->ch[i]=i;
//     }
//     for(int i=0;i<a+b;i++)
//     {
//         printf("%d ",p->ch[i]);
//     }
//     free(p);
//     p=NULL;
// 	return 0;
// }


//与柔性数组相同效果
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
    p->c=(int*)malloc(sizeof(int)*5);
    for(int i=0;i<5;i++)
    {
        p->c[i]=i;
    }
    //调整大小
    int* q=realloc(p->c,10*sizeof(int));
    if(q!=NULL)
    {
        p->c=q;
    }
    for(int i=5;i<10;i++)
    {
        p->c[i]=i;
    }
    for(int i=0;i<10;i++)
    {
        printf("%d ",p->c[i]);
    }
    free(p->c);
    free(p);
    p->c=NULL;
    p=NULL;
    return 0;
}