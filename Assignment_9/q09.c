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

void delet_node(struct Node * curr , struct Node * prev,int flag) 
{
	if(curr == NULL ) {
		return ;
	}

	delet_node(curr->left,curr,0);
	delet_node(curr->right,curr,1);
	
	if(flag ==  0) {
		prev->left = NULL;
	} else if (flag ==  1){
		prev->right = NULL;
	} 
	printf("%d  ",curr->val);
	free(curr);

}







int main()
{
    int n,val;
    scanf("%d",&n);

    struct Node * root =NULL;
    for (int i=0;i<n;i++) {
	scanf("%d",&val);
       root=insert_node(val,root);
    }

    delet_node(root,NULL,-1);

}
