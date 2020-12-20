//
// Created by 胡杨 on 2020/12/20.
//
#ifndef NEW_CONTACT_NEW_CONTACT_H
#define NEW_CONTACT_NEW_CONTACT_H

#endif //NEW_CONTACT_NEW_CONTACT_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


#define NUM 128
#define INIT 1
#define INC_SIZE 1

//成员结构体
typedef struct person
{
    char name[NUM / 4];
    int age;
    char sex;
    char telephone[NUM / 4];
    char address[NUM];
}person_t;

//通讯录结构体
typedef struct concat
{
    //cap:容量
    int cap;
    //size:通讯录大小
    int size;
    person_t persons[0];
}concat_t;



//声明
extern void Initconcat(concat_t **ct);
extern void AddPersonToContact(concat_t **ct);
extern void ShowConcat(concat_t *ct);
extern void DelPersonFromContact(concat_t *ct);
extern void SearchContact(concat_t *ct);
extern void ClearContact(concat_t *ct);
extern void SortContact(concat_t *ct);
extern void ModifConcat(concat_t *ct);
extern void SaveConcatByFile(concat_t *ct);