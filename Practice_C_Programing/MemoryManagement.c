#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t size);
void my_free(void *ptr);

int main(int argc, char const *argv[])
{
    int size;
    printf("Enter size of memory to allocate: ");
    scanf("%d", &size);

    int *ptr = (int *)my_malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        ptr[i] = i + 1;
    }

    printf("Allocated memory contents:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    my_free(ptr);

    return 0;
}

void *my_malloc(size_t size)
{
    int *ptr = (int *)malloc(size);

    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    return ptr;
}

void my_free(void *ptr)
{
    if (ptr != NULL)
    {
        free(ptr);
    }
}