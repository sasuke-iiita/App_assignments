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

char check( struct Node * root1 , struct Node * root2 ) {

    if(root1 == root2 && root1 == NULL) {
        return 'y';
    }

    if ( root1 == NULL || root2 == NULL ) {
        return 'n';
    }

    if(root1->val != root2 ->val) {
        return 'n';
    }
    
    if (check(root1->left, root2 -> left) == 'n') {
        return 'n';
    }
    if (check(root1->right, root2 -> right) == 'n') {
        return 'n';
    }
    return 'y';
}
int main(){
    int T,n,val;
    scanf("%d",&T);
    scanf("%d",&n);

    while(T)
    {
        T--;
    
        struct Node * root1 =NULL;
        struct Node * root2 =NULL;
        for( int i=0; i< n;i++) {
            scanf("%d",&val);
            root1=insert_node(val,root1);
        }
        for( int i=0; i< n;i++) {
            scanf("%d",&val);
            root2=insert_node(val,root2);
        }
        printf("%c\n",check(root1,root2));
    }
}