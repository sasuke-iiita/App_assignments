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


void inorder(struct Node * root)
{
    if(!root) {
        return;
    }

    inorder(root -> left);
    printf("%d_",root ->val);
    inorder(root -> right);
}


void  node_at_k( struct Node * root, int k,int d)
{
    if ( root == NULL ) {
        return ;
    }

    if(d == k) {
	printf("%d ",root->val);
	return;
    }

    if ( d > k) {
	return ;
    }

    node_at_k(root->left,k,d+1);
    node_at_k(root->right,k,d+1);

}




int main()
{
    int n,val;
    scanf("%d",&n);

    struct Node * root =NULL;
    for (int i=0;i<n;i++) {
	scanf("%d",&val);
        root = insert_node(val,root);
    }
    scanf("%d",&val);
    node_at_k(root,val,0);
}