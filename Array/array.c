#include <stdio.h>

void print_array(int* array, size_t size);
void insert_array(int* array, size_t size, int position, int value);
void remove_array(int* array, size_t size, int value);
void search_array(int* array, size_t size, int value);
void update_array(int* array, size_t size, int position, int value);


int main()
{
    size_t array_size = 4;
    int array[] = {1, 2, 2, 7};

    print_array(&array[0], array_size);
    insert_array(&array[0], array_size, 1, 5);
    remove_array(&array[0], array_size, 2);
    search_array(&array[0], array_size, 2);
    search_array(&array[0], array_size, 45);
    update_array(&array[0], array_size, 1, 0);
    print_array(&array[0], array_size);

    return 0;
}

void print_array(int* p, size_t size)
{
    for(int index = 0; index < size; index++)
    {
        printf("%d", *(p + index));
    }
    printf("\n");
}

void insert_array(int* p, size_t size, int position, int value)
{
    // The size of an array is fixed, so, for insertion operation we only can print the new array
    for(int index = 0; index < size; index++)
    {
        if(index != position)
            printf("%d", *(p + index));
        else
        {
            printf("%d", value);
            printf("%d", *(p + index));
        }
    }
    printf("\n");
}

void remove_array(int* p, size_t size, int value)
{
    for(int index = 0; index < size; index++)
    {
        if(*(p + index) != value)
            printf("%d", *(p + index));
    }
    printf("\n");
}

void search_array(int* p, size_t size, int value)
{
    int match = 0;
    for(int index = 0; index < size; index++)
    {
        if(*(p + index) == value)
            match = 1;
    }
    if(match != 0)
        printf("True\n");
    else
        printf("False\n");
}

void update_array(int* p, size_t size, int position, int value)
{
    for(int index = 0; index < size; index++)
    {
        if(index == position)
            *(p + index) = value;
    }
    printf("\n");
}
