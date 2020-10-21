//
// Created by 胡杨 on 2020/10/20.
//

#include "Contact.h"

void InitContact(struct Contact* ps)
{
    memset(ps ->data,0,sizeof(ps ->data));
    ps ->size = 0; //设置通讯录最初只有0个元素；
}

void AddContact(struct Contact* ps)
{
    if (ps ->size == MAX)
    {
        printf("通讯录已满!\n");
    } else{
        printf("请输入姓名:\n");scanf("%s",ps ->data[ps ->size].name);
        printf("请输入年龄:\n");scanf("%d",&(ps ->data[ps ->size].age));
        printf("请输入性别:\n");scanf("%s",ps ->data[ps ->size].sex);
        printf("请输入电话:\n");scanf("%s",ps ->data[ps ->size].tele);
        printf("请输入地址:\n");scanf("%s",ps ->data[ps ->size].addr);

        ps ->size++;
        printf("添加成功!\n");
    }
}


void ShowContact(const struct Contact *ps)
{
    if (ps ->size == 0)
    {
        printf("通讯录为空！\n");
    } else{
        printf("%-20s\t   %-4s\t   %-5s\t    %-12s\t    %-20s\n","名字","年龄","性别","电话","地址");
        for (int i = 0;i < ps ->size;i++)
        {
            printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                    ps ->data[i].name,
                    ps ->data[i].age,
                    ps ->data[i].sex,
                    ps ->data[i].tele,
                    ps ->data[i].addr);
        }
    }
}

static int FindbyName(const struct Contact *ps, char name[MAX_NAME])
{
    for (int i = 0;i < ps ->size;i++) {
        if (strcmp((ps->data[i].name), name) == 0) {
            break;
        }
    }
    return -1;
}

void DelContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入要删除的名字:\n");
    scanf("%s",name);
    int pos =FindbyName(ps,name);
    if (pos == -1)
    {
        printf("查找的姓名不存在!\n");
    } else{
            for (int j = pos;j < ps ->size -1;j++)
            {
                ps ->data[j] = ps ->data[j + 1];
            }
            ps ->size--;
            printf("删除成功！\n");
        }
}

void SearchContact(const struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入要查找的姓名\n");
    scanf("%s",name);
    int pos = FindbyName(ps,name);
    if (pos == -1)
    {
        printf("用户查找不存在!\n");
    } else{
        printf("%-20s\t   %-4s\t   %-5s\t    %-12s\t    %-20s\n","名字","年龄","性别","电话","地址");
        printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
               ps ->data[pos].name,
               ps ->data[pos].age,
               ps ->data[pos].sex,
               ps ->data[pos].tele,
               ps ->data[pos].addr);
    }
}


void ModifyContact(struct Contact* ps)
{
    char name[MAX_NAME];
    printf("请输入要修改用户的名字:\n");
    scanf("%s",name);
    int pos = FindbyName(ps,name);
    if (pos == -1)
    {
        printf("所需要修改的用户信息不存在!\n");
    } else{
        printf("请输入姓名:\n");scanf("%s",ps ->data[pos].name);
        printf("请输入年龄:\n");scanf("%d",&(ps ->data[pos].age));
        printf("请输入性别:\n");scanf("%s",ps ->data[pos].sex);
        printf("请输入电话:\n");scanf("%s",ps ->data[pos].tele);
        printf("请输入地址:\n");scanf("%s",ps ->data[pos].addr);
        printf("用户信息修改成功！\n");
    }
}

static char* my_strcpy(char* dest, const char* src)
{
    assert(dest != NULL);
    assert(src != NULL);
    char* ret = dest;
    //拷贝src指向的字符串到dest指向的空间，包含'\0'.
    while (*dest++ = *src++)
    {
        ;
    }
    //返回目的空间的起始值。
    return ret;

}

void SortContact(const struct Contact* ps)
{
    char * tmp;
    char name[MAX_NAME];
    printf("即将按照姓名首字母排序!\n");
    for (int i = 0;i < ps ->size - 1;i++)
    {
        for (int j = j + 1;j < ps ->size; j++)
        {
            if (strcmp(ps ->data[i].name,ps ->data[j].name) < 0)
            {
                my_strcpy(tmp,ps ->data[i].name);
                my_strcpy(ps ->data[i].name,ps ->data[j].name);
                my_strcpy(ps ->data[j].name,tmp);
            }
        }
    }
}
