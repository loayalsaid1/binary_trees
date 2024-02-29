#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node {
    int val;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

tree_node *create_node(int val)
{
    tree_node *node = malloc(sizeof(tree_node));
    if (node == NULL)
        return NULL;
    
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void print_tabs(int number)
{
    int i;

    for (i = 0; i < number; i++)
    {
        putchar('\t');
    }
}

void print_tree_rec(tree_node *root, int level)
{
    if (root == NULL)
    {
        print_tabs(level);
        printf("--empty--\n");
        return;
    }
    print_tabs(level);
    printf("Value: %d\n", root->val);
    print_tabs(level);
    printf("Left\n");
    print_tree_rec(root->left, level + 1);
    print_tabs(level);
    printf("Right\n");
    print_tree_rec(root->right, level + 1);
    print_tabs(level);

    printf("done\n");
}

void print_tree(tree_node *root)
{
    print_tree_rec(root, 0);
}

int main (void)
{
    tree_node *n1 = create_node(10);
    tree_node *n2 = create_node(11);
    tree_node *n3 = create_node(12);
    tree_node *n4 = create_node(13);
    tree_node *n5 = create_node(14);
    
    n1->left = n2;
    n1->right = n3;
    n3->left = n4;
    n3->right = n5;


    print_tree(n1);


    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    

    return (0);
}
