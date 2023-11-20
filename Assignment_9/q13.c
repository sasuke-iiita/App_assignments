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


int print_ancestor(struct Node *root,int n)
{
	if(root == NULL) {
		return 0;
	}
	if(root->val == n) {
		return 1;
	}


	if(print_ancestor(root->left,n) ||print_ancestor(root->right,n)) {
		printf("%d",root->val);
		return 1;
	}
	return 0;
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
    print_ancestor(root,val);
}
