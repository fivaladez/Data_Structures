#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
   int data;
   struct node *left_child;
   struct node *right_child;
}node_t;

void insert_node(node_t** root, int data);
void print_path_to_node(node_t** root, int data);

int main() {
    node_t* root = NULL;

    print_path_to_node(&root, 1);

    insert_node(&root, 27);
    insert_node(&root, 14);
    insert_node(&root, 35);
    insert_node(&root, 10);
    insert_node(&root, 19);
    insert_node(&root, 31);
    insert_node(&root, 42);

    print_path_to_node(&root, 42);
    print_path_to_node(&root, 19);
    print_path_to_node(&root, 31);

    print_path_to_node(&root, 66);

   return 0;
}

void insert_node(node_t** root, int data)
{
    node_t* current_node;
    node_t* parent_node;
    node_t* new_node = (node_t*) malloc(sizeof(node_t));

    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    //if tree is empty, create root node
    if(*root == NULL)
    {
        *root = new_node;
        printf("New node created\n");
    }
    else
    {
        current_node = *root;
        parent_node  = NULL;
        while(1)
        {
            parent_node = current_node;
            if(data < parent_node->data)//go to left of the tree
            {
                current_node = current_node->left_child;
                //insert to the left
                if(current_node == NULL)
                {
                    parent_node->left_child = new_node;
                    break;
                }
            }
            else //go to right of the tree
            {
                current_node = current_node->right_child;
                //insert to the right
                if(current_node == NULL)
                {
                    parent_node->right_child = new_node;
                    break;
                }
            }
        }
    }
}

void print_path_to_node(node_t** root, int data)
{
    node_t* current_node;
    node_t* parent_node;

    if(*root == NULL)
    {
        printf("\nThere is not a tree to print\n");
    }
    else
    {
        current_node = *root;
        parent_node  = NULL;
        printf("Looking for: %d | ", data);

        while(1)
        {
            parent_node = current_node;

            if(data < parent_node->data)//go to left of the tree
            {
                printf("%d -> ", parent_node->data);
                current_node = current_node->left_child;
                //insert to the left
                if(current_node == NULL)
                {
                    printf("\tThat node is not in the tree\n");
                    break;
                }
            }
            else if(data > parent_node->data)//go to right of the tree
            {
                printf("%d -> ", parent_node->data);
                current_node = current_node->right_child;
                //insert to the right
                if(current_node == NULL)
                {
                    printf("\tThat node is not in the tree\n");
                    break;
                }
            }
            else // Node found
            {
                printf("%d", parent_node->data);
                printf("\tNode found in the tree\n");
                break;
            }
        }
    }
}
