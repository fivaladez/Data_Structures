#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node_t;

void append_node(node_t** head, int data);
void print_linked_list(node_t** head);


int main(void)
{
    node_t* head = NULL;
    append_node(&head, 5);
    append_node(&head, 8);
    append_node(&head, 3);
    print_linked_list(&head);

    return 0;
}

void append_node(node_t** phead, int data)
{
    // Temporal pointer
    node_t* temp;

    // Init Node
    node_t* new_node = (node_t*)malloc(sizeof(new_node));
    new_node->data = data;
    new_node->next = NULL;

    if(*phead == NULL) // Check if the new Node will be the first list element
    {
        *phead = new_node; // Attach Head
    }
    else
    {
        temp = *phead;
        while(temp != NULL)
        {
            if(temp->next == NULL) // Loof for the last list element
            {
                temp->next = new_node;
                new_node->next = NULL;
            }
            temp = temp->next; // Go to next list element
        }
    }
}

void print_linked_list(node_t** phead)
{
    node_t* temp = *phead;
    printf("Head = %x\n", temp);
    printf("    |\n");
    while (temp != NULL)
    {
        printf("| %d | %x |\n", temp->data, temp->next);
        temp = temp->next;
    }
}
