#include "new_contact.h"
void Menu()
{
    printf("***************************\n");
    printf("***********1.ADD***********\n");
    printf("***********2.Del***********\n");
    printf("***********3.Search********\n");
    printf("***********4.Mod***********\n");
    printf("***********5.Qsort*********\n");
    printf("***********6.Clear*********\n");
    printf("***********7.Show**********\n");
    printf("***********8.Save**********\n");
    printf("***********0.Exit**********\n");
    printf("***************************\n");
    printf("Please select:\n");
}
//枚举
enum
{
    Exit,ADD,Del,Search,Mod,Qsort,Clear,Show,Save
};
int main()
{
    int quit = 1;
    int select = 0;
    concat_t *ct = NULL;
    Initconcat(&ct);
    while (quit)
    {
        Menu();
        scanf("%d",&select);
        switch (select)
        {
            case ADD:
                AddPersonToContact(&ct);
                break;
            case Del:
                DelPersonFromContact(ct);
                break;
            case Search:
                SearchContact(ct);
                break;
            case Mod:
                ModifConcat(ct);
                break;
            case Qsort:
                SortContact(ct);
                break;
            case Clear:
                ClearContact(ct);
                break;
            case Show:
                ShowConcat(ct);
                break;
            case Save:
                SaveConcatByFile(ct);
                break;
            case Exit:
                quit = 0;
                printf("Exit successful!");
                break;
            default:
                printf("Select error,please select again!\n");
                break;
        }
    }
    return 0;
}