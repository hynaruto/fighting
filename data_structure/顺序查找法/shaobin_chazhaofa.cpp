//哨兵顺序查找法
#include <stdio.h>

#define NUMBER  8
#define FAILED -1

int search(int vc[], int key,int no)
{
    int i = 0;
    vc[no] = key;
    while (1){
        if (vc[i] == key)
            break;
        i++;
    }
    return (i == no ? FAILED : i);
}

int main()
{
    int i ,ky,idx;
    int vx[NUMBER + 1];

    for (i = 0;i < NUMBER;i++){
        printf("vx[%d]:",i);
        scanf("%d",&vx[i]);
    }
    printf("需要查找的值:");
    scanf("%d",&ky);

   idx = search(vx,ky,NUMBER);

    if (idx == FAILED)
        puts("\a查找失败");
    else
        printf("%d是数组的第%d号元素。\n",ky,idx+1);

    return 0;

}