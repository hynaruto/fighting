//
// Created by 胡杨 on 2020/12/20.
//
#include "new_contact.h"

//申请空间
void Initconcat(concat_t **ct)
{
    *ct = (concat_t*)malloc(sizeof(concat_t) + INIT * sizeof(person_t));
    if (*ct == NULL)
    {
        printf("malloc error");
        exit(1);
    }
    (*ct) ->size = 0;
    (*ct) ->cap = INIT;
}

//判断添加人员是否存在(用电话判断)
static IsExit(concat_t *ct,const char* telephone)
{
    assert(ct);
    person_t *p = ct ->persons;
    person_t *end = ct ->persons + ct ->size;
    while (p < end){
        if (0 == strcmp(p ->telephone,telephone)){
            return p - ct ->persons;
        }
        p++;
    }
    return - 1;
}

//判断通讯录是否满了
static IsFull(concat_t *ct)
{
    assert(ct);
    return ct ->size == ct ->cap;
}

//通讯录扩容
static Inc(concat_t **ct)
{
    assert(ct);
    int ret = 0;
    concat_t *p = (concat_t*)realloc(*ct, sizeof(concat_t) + sizeof(person_t) * ((*ct) ->cap + INC_SIZE));
    if (p != NULL){
        printf("realloc successful!\n");
        //更新通讯录容量
        p ->cap = (*ct) ->cap + INC_SIZE;
        *ct = p;
        ret = 1;
    }
}
//添加通讯录成员
void AddPersonToContact(concat_t **ct)
{
    assert(ct);
    //判断通讯录是否满了和通讯录人员是否存在(如果通讯录满了，则扩容),IsFull:0\1
    if (!(IsFull) || Inc)
    {
        person_t *p = (*ct) ->size + (*ct) ->persons;
        printf("Please Enter name:\n");
        scanf("%s",p ->name);
        printf("Please Enter age:\n");
        scanf("%d",&(p ->age));
        printf("Please Enter sex:\n");
        scanf("%s",&(p ->sex));
        printf("Please Enter telephone:\n");
        scanf("%s",p ->telephone);
        if (IsExit(*ct,p ->telephone) >=0)
        {
            printf("People is exit!\n");
            return;
        }
        printf("Please Enter address:\n");
        scanf("%s",p ->address);
        //如果程序执行到此，证明添加成功
        printf("add %s successful!\n",p ->name);
        (*ct) ->size += 1;
    } else{
        printf("realloc error!\n");
    }
}

//删除通讯录中的某个人
void DelPersonFromContact(concat_t *ct)
{
    assert(ct);
    char telephone[NUM / 4];
    printf("Please search the telephone:\n");
    scanf("%s",telephone);
    int pos = IsExit(ct,telephone);
    if (pos >= 0)
    {
        ct ->persons[pos] = ct ->persons[ct ->size - 1];
        ct ->size -= 1;
        printf("del is successful!\n");
    } else{
        printf("del person is not exit!\n");
    }
}

//按电话号查找通讯录人员
void SearchContact(concat_t *ct)
{
    assert(ct);
    char telephone[NUM / 4];
    printf("Please enter telephone:\n");
    scanf("%s",telephone);
    int pos = IsExit(ct,telephone);
    if (pos >= 0)
    {
        ShowConcat(ct);
        printf("%d",pos);
    } else{
        printf("the member is not exit!\n");
    }
}

//清空通讯录
void ClearContact(concat_t *ct)
{
    assert(ct);
    ct ->size = 0;
    printf("Clear successful!\n");
}

//显示通讯录
void ShowConcat(concat_t *ct)
{
    assert(ct);
    int pos;
    printf("%d/%d|",ct ->size,ct ->cap);
    if (pos == -1)
    {
        if (ct ->size == 0)
        {
            printf("Concat is empty!\n");
        } else{
            for (int i = 0;i < ct ->size;++i)
            {
                printf("10%s|5%d|10%s|10%s|10%s\n",ct ->persons[i].name,ct ->persons[i].age,ct ->persons[i] .sex,ct ->persons[i].telephone,ct ->persons[i].address);
            }
        }
    } else{
        printf("10%s|5%d|10%s|10%s|10%s\n",ct ->persons[pos].name,ct ->persons[pos].age,ct ->persons[pos].sex,ct ->persons[pos].telephone,ct ->persons[pos].address);
    }
}

//按照姓名排序
void SortContact(concat_t *ct)
{
    assert(ct);
    char name[NUM / 4];
    if (!IsFull(ct))
    {
        int i ,j = 0;
        int flag = 0;
        printf("sort begin!\n");
        while (!flag)
        {
            flag = 0;
            for (i = 0;i < ct ->size;++i)
            {
                if (strcmp(ct ->persons[i].name,ct ->persons[i + 1].name) > 0)
                {
                    person_t tmp  = ct ->persons[i];
                    ct ->persons[i] = ct ->persons[i + 1];
                    ct ->persons[i + 1] = tmp;
                    flag = 1;
                }
            }
            if (flag == 0)
            {
                break;
            }
        }
    } else{
        printf("the concat is empty!\n");
        return;
    }
}

//修改通讯录信息
void ModifConcat(concat_t *ct)
{
    assert(ct);
    char telephone[NUM / 4];
    printf("Enter telephone\n");
    scanf("%s",telephone);
    int pos = IsExit(ct,telephone);
    if (pos > -1)
    {
        printf("\n\t\tConcat\n");
        printf("10%s|5%d|10%s|10%s|10%s\n",ct ->persons[pos].name,ct ->persons[pos].age,ct ->persons[pos].sex,ct ->persons[pos].telephone,ct ->persons[pos].address);
        printf("请输入修改后的姓名:\n");
        scanf("%s",ct ->persons[pos].name);
        printf("请输入修改后的年龄:\n");
        scanf("%d",ct ->persons[pos].age);
        printf("请输入修改后的性别:\n");
        scanf("%s",ct ->persons[pos].sex);
        printf("请输入修改后的电话:\n");
        scanf("%s",ct ->persons[pos].telephone);
        printf("请输入修改后的住址:\n");
        scanf("%s",ct ->persons[pos].address);
        printf("Modify successful!\n");
    } else{
        printf("Concat member is not exit!\n");
    }
}

//通过文件形式保存通讯录
void SaveConcatByFile(concat_t *ct)
{
    assert(ct);
    FILE *p = fopen("Concat.data","w");
    if (p == NULL)
    {
        perror("open file error!\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0;i < ct ->size;++i)
    {
        fwrite(&(ct ->persons[i]),sizeof(person_t),1,p);
    }
    printf("Save File successful!\n");
    fclose(p);
}