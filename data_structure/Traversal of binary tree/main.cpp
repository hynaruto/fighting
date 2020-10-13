#include <stdio.h>
#include <cstdlib>

//定义树的节点
typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

//定义树根
typedef struct {
    Node* root;
}Tree;

//创建一棵树
void Create(Tree* tree,int value)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node ->data  = value;
    node ->left  = NULL;
    node ->right = NULL;
    //判断树是否为空
    if (tree ->root == NULL)
    {
        tree ->root = node;
    } else{
        Node* temp = tree ->root;
        while (temp != NULL)
        {
            if (value < temp ->data)
            {
                if (temp ->left ==NULL)
                {
                    temp ->left = node;
                    return;
                } else{
                    temp = temp ->left;
                }
            } else{
                if (temp ->right == NULL)
                {
                    temp ->right = node;
                    return;
                } else{
                    temp = temp ->right;
                }
            }
        }
    }
    return;
}

//中序遍历
void Inorder(Node* node)
{
    if (node != NULL)
    {
        Inorder(node ->left);
        printf("%d",node ->data);
        Inorder(node ->right);
    }
}


int main()
{
    Tree tree;
    //创建空树
    tree.root = NULL;
    int i = 0;
    scanf("%d",&i);
    for (int j = 0;j < i;j++)
    {
        int temp;
        scanf("%d",&temp);
        Create(&tree,temp);
    }
    //中序遍历
    Inorder(tree.root);
    getchar();
    return 0;
}