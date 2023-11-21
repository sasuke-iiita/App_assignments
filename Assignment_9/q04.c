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

struct Node * insert_node(int n, struct Node * root)
{
    if ( root == NULL ) {
        return createNode(n);
    }

    if( n <= root -> val ) {
        root -> left = insert_node(n,root -> left);
    }
    else {
        root -> right = insert_node(n,root -> right);
    }

    return root;    
}

void preorder(struct Node * root,int path[],int num)
{
    if(!root) {

        return;
    }

    path[num]=root->val;
    if(root->left == root->right && root->right == NULL) {
        for( int i = 0; i < num+1; i++ )
        {
            printf("%d -",path[i]);
        }
        printf("\n");
    }

    preorder(root -> left,path,num+1);
    preorder(root -> right,path,num+1);
}

int main(){
    int n,val;
    scanf("%d",&n);


    struct Node * root =NULL;
    for( int i=0; i< n;i++) {
        scanf("%d",&val);
        root=insert_node(val,root);
    }
    int path[100];
    preorder(root,path,0);
}