#include "tree.h"

int main()
{
    char data[SIZE];
    int first_entry = TRUE;
    NODE *start;

    infile = fopen("in.txt", "r");

    while (fgets(inrec, SIZE, infile) > 0)
    {
        if (first_entry)
        {
            start = new_node(inrec);
            first_entry = FALSE;
        }
        else
        {
            printf("adding node\n");
        }

    }
    return 0;
}


void add_data(NODE *root, char *data)
{
    if (strcasecmp(root->data, data) < 0)
    {
        if (root->left != NULL)
        {
            add_data(root->left, data);
        }
        else
        {
            root = new_node(data);  // TODO: ????
        }
    }
    else if (strcasecmp(root->data, data) > 0)
    {
        if (root->right != NULL)
        {
            add_data(root->right, data);
        }
        else
        {
             root = new_node(data);
        }
    }
    else  // copy of data already exits
    {
        root->count++;
    }

    

}


NODE *new_node(char *data)
{
    NODE *n_node = calloc(1, sizeof(NODE));
    strcpy(n_node->data, data);
    n_node->left = NULL;
    n_node->right = NULL;

    return n_node;
}