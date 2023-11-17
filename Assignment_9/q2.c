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

void preorder(struct Node * root)
{
    if(!root) {
        return;
    }
    printf("%d_",root ->val);
    preorder(root -> left);
    preorder(root -> right);
}


void inorder(struct Node * root)
{
    if(!root) {
        return;
    }
    
    inorder(root -> left);
    printf("%d_",root ->val);
    inorder(root -> right);
}

void postorder(struct Node * root)
{
    if(!root) {
        return;
    }
    
    postorder(root -> left);
    postorder(root -> right);
    printf("%d_",root ->val);
    
}
int main(){
    int n,val;
    scanf("%d",&n);

    struct Node * root =NULL;
    for( int i=0; i< n;i++) {
        scanf("%d",&val);
        root=insert_node(val,root);
    }

    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);

    // printf("\n__________\n");
    
    // printf("\n__________\n");

    // scanf("%d",&n);

    // // struct Node *root =NULL;
    // for( int i=0; i< n;i++) {
    //     scanf("%d",&val);
    //     printf("%c",search(root,val));
    // }

}