// Program - Binary Tree
// Reads list of words, stores them in a binary tree and displays them in sorted order

#include "tree.h"

int main()
{
    char filename[SIZE];
    int first_entry = TRUE;
    NODE *start;

    printf("Enter filename\n");
    printf("> ");
    scanf("%s", filename);
    getchar();

    if (fopen(filename, "r") == 0)
    {
        printf("Error opening >%s<\n", filename);
        return -1;
    }
    infile = fopen(filename, "r");

    while (fgets(inrec, SIZE, infile) > 0)
    {
        TRUNCATE(inrec);  // remove LF from each word in input file

        if (first_entry)
        {
            start = new_node(inrec);
            first_entry = FALSE;
        }
        else  // if tree already exists, add leaf
            add_data(start, inrec);
    }
    printf("** SORTED BINARY TREE **\n");
    print_tree(start);  // print contents of tree, sorted
    fclose(infile);
    return 0;
}

// add element to tree
void add_data(NODE *root, char *data)
{
    // Determine whether data to be added is greater or less alphabetically and adds new data at proper location
    // strcasecmp() - similar to _strcmpi()
    // returns 0 if strings are equal
    // returns <0 if data < root->data (ie b < g)
    // returns >0 if data > root->data (ie b > a)
    if (strcasecmp(data, root->data) < 0)
    {
        if (root->left != NULL)
            add_data(root->left, data);
        else
            root->left = new_node(data);
    }
    else if (strcasecmp(data, root->data) > 0)
    {
        if (root->right != NULL)
            add_data(root->right, data);
        else
             root->right = new_node(data);
    }
    else  // copy of data already exits so increase count
        root->count++;
}

// print contents of binary tree
void print_tree(NODE *root)
{
    // iterate through until the left most node is reached, once reached print contents of each subtree from left to right
    if (root->left != NULL)
        print_tree(root->left);

    while(root->count != 0)
    {
        printf("%s\n", root->data);
        root->count--;
    }

    if (root->right != NULL)
        print_tree(root->right);
}

// initializes a new node to be added to tree
NODE *new_node(char *data)
{
    NODE *n_node = calloc(1, sizeof(NODE));

    strcpy(n_node->data, data);
    n_node->count = 1;
    n_node->left = NULL;
    n_node->right = NULL;

    return n_node;
}