#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node * right;
    struct Node * left;
};

struct Node * createNode(int val)
{
    struct Node * nn = (struct Node *)malloc(sizeof(struct Node));
    nn -> val = val;
    nn->right = NULL;
    nn->left = NULL;
    return nn;
}

int search(int inorder[],int start,int end,int val)
{
    for(int i=start;i<=end;i++)
    {
        if (inorder[i] ==  val)
        {
            return i;
        }
    }
    return -1;
}

struct node * create_tree(int inorder[],int postorder[],int start,int end,int * postorderIndex)
{
    if( start < end)
    {
        return NULL;
    }
    struct Node * cn=createNode(postorder[postorderIndex]);
    *preorderIndex--;

    rootindex=search(inorder,start,end);
    cn->right=create_tree(inorder,postorder,rootindex,end,postorderIndex);
    cn->left=create_tree(inorder,postorder,start,rootindex-1,postorderIndex);
    return cn;
}

void dft(struct Node * root)
{
    if(!root) {
        return;
    }
    printf("%d_",root ->val);
    dft(root -> left);
    dft(root -> right);
}

int main()
{
    int n;
    scanf("%d",&n);

    int inorder[n];
    int postorder[n];

    for (int i=0;i<n;i++) {
        scanf("%d",&inorder[i]);
    }
    for (int i=0;i<n;i++) {
        scanf("%d",&postorder[i]);
    }

    int postorderIndex = n-1;

    struct Node * root=create_tree(inorder,postorder,0,n-1,&postorderIndex);
    dft(root);
}
