//
// Created by 胡杨 on 2020/10/20.
//

#ifndef CONTACT_CONTACT_H
#define CONTACT_CONTACT_H

#endif //CONTACT_CONTACT_H

#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX  5
#define MAX_TEl  16
#define MAX_ADDR 30
#include <stdio.h>
#include <string.h>
#include <assert.h>

enum Option
{
    EXIT,ADD,DEL,SEARCH,MODIFY,SHOW,SORT
};


struct PeopleInfo
{
char name[MAX_NAME];
int age;
char tele[MAX_TEl];
char sex[MAX_SEX];
char addr[MAX_ADDR];
};

//通讯录类型
struct Contact
{
    struct PeopleInfo data[MAX];
    int size; //记录当前已经有的元素个数；
};

//声明函数
void InitContact(struct Contact* ps);
void AddContact(struct Contact* ps);
void ShowContact(const struct Contact* ps);
void DelContact(struct Contact* ps);
void SearchContact(const struct Contact* ps);
void ModifyContact(struct Contact* ps);
void SortContact(const struct Contact* ps);