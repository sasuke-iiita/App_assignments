#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *right;
    struct Node *left;
};

struct Node *createNode(int val) {
    struct Node *nn = (struct Node *)malloc(sizeof(struct Node));
    nn->val = val;
    nn->right = NULL;
    nn->left = NULL;
    return nn;
}

struct Node *insert_node(int n, struct Node *root) {
    if (root == NULL) {
        return createNode(n);
    }

    if (n <= root->val) {
        root->left = insert_node(n, root->left);
    } else {
        root->right = insert_node(n, root->right);
    }

    return root;
}

struct Node *find_min(struct Node *root) {
    struct Node *current = root;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

struct Node *delete_node(struct Node *root, int n) {
    if (!root) {
        return NULL;
    }

    if (n < root->val) {
        root->left = delete_node(root->left, n);
    } else if (n > root->val) {
        root->right = delete_node(root->right, n);
    } else {

        if (!root->left && root->right) {
            struct Node *tmp = root->right;
            free(root);
            return tmp;
        }

        if (root->left && !root->right) {
            struct Node *tmp = root->left;
            free(root);
            return tmp;
        }

        struct Node *tmp = find_min(root->right);
        root->val = tmp->val;

        root->right = delete_node(root->right, tmp->val);
    }
    return root;
}

void inorder(struct Node *root) {
    if (!root) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    int n, val;
    scanf("%d", &n);

    struct Node *root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert_node(val, root);
    }

    inorder(root);
    printf("\n");


    while (root) {

        root = delete_node(root, root->val);

        inorder(root);
        printf("\n");
    }

    return 0;
}
