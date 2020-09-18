#include <stdio.h>
// 把0赋值给有n0个元素的数组vc
void int_ste(int vc[],int no)
{
    int i;
    for (i = 0;i < no;i++)
        vc[i] = 0;
}
int main()
{
    int i;
    int ary1[] = {1,2,3,4,5};
    int ary2[] = {3,2,1};

    int_ste(ary1,5);
    int_ste(ary2,3);

    for (i = 0;i < 5; i++)  printf("ary1[%d] = %d\n",i,ary1[i]);


    for (i = 0;i < 3;i++)  printf("ary2[%d] = %d\n",i,ary2[i]);



    return 0;
}