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


void  find_succesor( struct Node * root)
{
	if ( root == NULL ) {
	return ;
	}
	if (!root->left)
	{
		printf("succesor -> %d ",root->val);
		return ;
	}
	find_succesor(root -> left);
}


void  find_pre( struct Node * root)
{
	if ( root == NULL ) {
	return ;
	}
	if (!root->right)
	{
		printf("\npredecessor -> %d ",root->val);
		return ;
	}
	find_pre(root -> right);
}



void find_node(int n, struct Node * root)
{
    if ( root == NULL ) {
        return ;
    }

    if( n < root -> val ) {
        find_node(n,root -> left);
    }
    else if (n > root -> val){
        find_node(n,root -> right);
    } else {
	
	find_succesor(root);
	find_pre(root);
	}
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
    find_node(val,root);
}

