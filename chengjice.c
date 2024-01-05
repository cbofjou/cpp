#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
//结
struct student
{
    int no;
    char name[10];
    int score;
    struct student* next;
};
//建立链表，并输入信息
struct student* jllb(int num)
{
    struct student* head = NULL;
    struct student* p = NULL;
    struct student* last = NULL;
    for (int i = 0;i < num;i++)
    {
        p = (struct student*)malloc(sizeof(struct student));
        if (p == NULL)
        {
            printf("开辟空间失败");
            return NULL;
        }
        if (i == 0)
        {
            printf(">>请输入学生信息（从左至右为学号，姓名，分数，以空格分隔）：\n");
        }
        scanf("%d %s %d", &p->no, p->name,&p->score);
        if (i == 0)
        {
            head = p;
            last = p;
            last->next = NULL;
        }
        else
        {
            last->next = p;
            last = p;
            last->next = NULL;
        }
    }
    return head;
}
//菜单
void meun()
{
    printf("*********************************\n");
    printf("*********************************\n");
    printf("**   0、建立        1、添加    **\n");
    printf("**   2、输出        3、查找    **\n");
    printf("**   4、修改        5、删除    **\n");
    printf("**   6、退出                   **\n");
    printf("*********************************\n");
}
//存储
void baocun(struct student* head)
{
    FILE* p = fopen("student.bin", "w");
    if (p == NULL)
    {
        printf("%s\n", strerror(errno));
        return;
    }
    while (head->next != NULL)
    {
        fprintf(p, "%d %s %d\n", head->no, head->name, head->score);
        head = head->next;
    }
    fprintf(p, "%d %s %d\n", head->no, head->name, head->score);
    rewind(p);
    fclose(p);
    p = NULL;
}
//读取结点
int duqujiedian()
{
    struct student m;
    int count = 0;
    FILE* p = fopen("student.bin", "r");
    if (p == NULL)
    {
        printf("%s\n", strerror(errno));
        return 0;
    }
    while (1)
    {
        if (fscanf(p, "%d %s %d", &m.no, m.name, &m.score) == 3)
        {
            count++;
        }
        else
        {
            break;
        }
    }
    rewind(p);
    fclose(p);
    p = NULL;
    return count;
}
//重建链表
struct student* chongjian(int jiedian)
{
    FILE* pf = fopen("student.bin", "r");
    if (pf == NULL)
    {
        printf("%s\n", strerror(errno));
        return NULL;
    }
    struct student* head = NULL;
    struct student* p = NULL;
    struct student* last = NULL;
    for (int i = 0;i < jiedian;i++)
    {
        p = (struct student*)malloc(sizeof(struct student));
        if (p == NULL)
        {
            printf("开辟空间失败");
            return NULL;
        }
        fscanf(pf,"%d %s %d", &p->no, p->name,&p->score);
        if (i == 0)
        {
            head = p;
            last = p;
            last->next = NULL;
        }
        else
        {
            last->next = p;
            last = p;
            last->next = NULL;
        }
    }
    rewind(pf);
    fclose(pf);
    pf = NULL;
    return head;
}
//建立成绩表功能
struct student* jianli()
{
    printf(">>请输入要输入的学生信息数量：");
    int num = 0;
    scanf("%d", &num);
    struct student* head = jllb(num);
    if (head == NULL)
    {
        return 0;
    }
    return head;
}
//添加功能
void tianjia(struct student* head)
{
    while (head->next != NULL)
    {
        head = head->next;
    }
    int a = 0;
    struct student* p = NULL;
    struct student* last = NULL;
    printf(">>请输入要添加学生数量：");
    scanf("%d", &a);
    for(int i=0;i<a;i++)
    {
        p = (struct student*)malloc(sizeof(struct student));
        if (p == NULL)
        {
            printf("开辟空间失败");
            return;
        }
        if (i == 0)
        {
            printf(">>请输入学生信息（从左至右为学号，姓名，分数，以空格分隔）：\n");
        }
        scanf("%d %s %d", &p->no, p->name,10, &p->score);
        if (i == 0)
        {
            head->next = p;
            last = p;
            last->next = NULL;
        }
        else
        {
            last->next = p;
            last = p;
            last->next = NULL;
        }
        a--;
    }

}
//输出功能
void shuchu(struct student* head)
{
    while (head->next != NULL)
    {
        printf("%d %s %d\n", head->no, head->name, head->score);
        head = head->next;
    }
    printf("%d %s %d\n", head->no, head->name, head->score);
}
//查找功能
void chazhao(struct student* head)
{
    int a = 0;
    int flag = 0;
    printf(">>输入要查找的学生学号：");
    scanf("%d", &a);
    while (flag == 0)
    {
        if (head == NULL && flag == 0)
        {
            printf(">>查找不到该学生\n");
            return;
        }
        if (head->no == a)
        {
            flag = 1;
            printf("%d %s %d\n", head->no, head->name, head->score);
        }
        head = head->next;
    }
}
//修改功能
void xiugai(struct student* head)
{
    int a = 0;
    int flag = 0;
    printf(">>请输入修改学生学号：");
    scanf("%d", &a);
    while (flag == 0)
    {
        if (head == NULL && flag == 0)
        {
            printf(">>查找不到该学生\n");
            return;
        }
        if (head->no == a)
        {
            flag = 1;
            printf(">>请输入修改的信息：");
            scanf("%d %s %d", &head->no, head->name, 10, &head->score);
        }
        head = head->next;
    }
}
//删除功能
struct student* shanchu(struct student* head)
{
    int a = 0;
    int flag = 0;
    printf(">>请输入要删除学生学号：");
    scanf("%d", &a);
    while (flag == 0)
    {
        struct student* lsbl = head;
        lsbl = head->next;
        if (head->no == a)
        {
            return lsbl;
        }
        if (lsbl == NULL)
        {
            printf(">>查找不到该学生\n");
            return NULL;
        }
        if (lsbl->no == a)
        {
            flag = 1;
            head->next = lsbl->next;
            free(lsbl);
            lsbl = NULL;
        }
    }
    return head;
}
//主函数
int main()
{
    int a = 0;
    int jiedian = 0;
    struct student* head = NULL;
    jiedian = duqujiedian();
    if (jiedian != 0)
    {
        head = chongjian(jiedian);
    }
    do
    {
        printf("\n");
        meun();
        printf(">>请选择您要使用功能：");
        scanf("%d", &a);
        switch (a)
        {
        case 0:
        {
            head = jianli();
            baocun(head);
            break;
        }
        case 1:
        {
            tianjia(head);
            baocun(head);
            break;
        }
        case 2:
        {
            shuchu(head);
            break;
        }
        case 3:
        {
            chazhao(head);
            break;
        }
        case 4:
        {
            xiugai(head);
            baocun(head);
            break;
        }
        case 5:
        {
            head = shanchu(head);
            baocun(head);
            break;
        }
        case 6:
        {
            goto tuichu;
        }
        }
    } while (1);
    tuichu:;
    //释放
    struct student* current = head;
    struct student* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
    return 0;
}
