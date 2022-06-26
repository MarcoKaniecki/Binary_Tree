//
// Created by Marco Kaniecki on 2022-06-25.
//

#ifndef L4_TREES_TREE_H
#define L4_TREES_TREE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE               128
#define TRUE               1
#define FALSE              0
#define TRUNCATE(name)     name[strlen(name)-1] = '\0'

FILE *infile;
char inrec[SIZE];

typedef struct node
{
    int count;
    char data[SIZE];
    struct node *left, *right;
}NODE;

NODE* new_node(char *data);
void add_data(NODE *root, char *data);
void print_tree(NODE *root);

#endif //L4_TREES_TREE_H
