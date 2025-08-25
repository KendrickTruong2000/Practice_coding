#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *Push(void *array, size_t element_size, size_t *size, void *element)
{
    void *new_array = realloc(array, (*size + 1) * element_size);
    if (new_array == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    memcpy((char *)new_array + (*size) * element_size, element, element_size);
    (*size)++;
    return new_array;
}

void *Pop(void *array, size_t element_size, size_t *size)
{
    if (*size == 0)
    {
        printf("Array is empty, cannot pop\n");
        return array;
    }
    void *element = malloc(element_size);
    if (element == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    memcpy(element, (char *)array + (*size - 1) * element_size, element_size);
    void *new_array = realloc(array, (*size - 1) * element_size);
    if (new_array == NULL && *size > 1)
    {
        printf("Memory allocation failed\n");
        free(element);
        exit(1);
    }
    (*size)--;
    return new_array;
}

void *Get(void *array, size_t element_size, size_t index)
{
    if (index < 0 || index >= sizeof(array) / element_size)
    {
        printf("Index out of bounds\n");
        return NULL;
    }
    void *element = malloc(element_size);
    if (element == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    memcpy(element, (char *)array + index * element_size, element_size);
    return element;
}

void *Set(void *array, size_t element_size, size_t index, void *element)
{
    if (index < 0 || index >= sizeof(array) / element_size)
    {
        printf("Index out of bounds\n");
        return NULL;
    }
    memcpy((char *)array + index * element_size, element, element_size);
    return array;
}

int main(int argc, char const *argv[])
{
    char str[] = {"Hello, World!"};
    size_t size = 0;
    char *dynamic_array = NULL;
    int arr[] = {1, 2, 3, 4, 5};
    size_t arr_size = 0;
    dynamic_array = (char *)Push(dynamic_array, sizeof(char), &size, &str[0]);
    dynamic_array = (char *)Push(dynamic_array, sizeof(char), &size, &str[1]);
    dynamic_array = (char *)Push(dynamic_array, sizeof(char), &size, &str[2]);
    dynamic_array = (char *)Push(dynamic_array, sizeof(char), &size, &str[3]);
    dynamic_array = (char *)Push(dynamic_array, sizeof(char), &size, &str[4]);
    dynamic_array = (char *)Push(dynamic_array, sizeof(char), &size, &str[5]);
    dynamic_array = (char *)Push(dynamic_array, sizeof(char), &size, &str[6]);
    dynamic_array = (char *)Push(dynamic_array, sizeof(char), &size, &str[7]);
    dynamic_array = (char *)Push(dynamic_array, sizeof(char), &size, &str[8]);
    dynamic_array = (char *)Push(dynamic_array, sizeof(char), &size, &str[9]);
    dynamic_array = (char *)Push(dynamic_array, sizeof(char), &size, &str[10]);
    dynamic_array = (char *)Push(dynamic_array, sizeof(char), &size, &str[11]);
    dynamic_array = (char *)Push(dynamic_array, sizeof(char), &size, &str[12]);
    dynamic_array = (char *)Push(dynamic_array, sizeof(char), &size, &str[13]);
    printf("Dynamic Array: %s\n", dynamic_array);
    dynamic_array = (char *)Pop(dynamic_array, sizeof(char), &size);
    printf("After Pop: %s\n", dynamic_array);
    char *element = (char *)Get(dynamic_array, sizeof(char), 5);
    if (element != NULL)
    {
        printf("Element at index 5: %c\n", *element);
        free(element);
    }
    char new_element = 'X';
    dynamic_array = (char *)Set(dynamic_array, sizeof(char), 5, &new_element);
    printf("After Set: %s\n", dynamic_array);
    free(dynamic_array);
    dynamic_array = NULL;
    int *int_array = NULL;
    int_array = (int *)Push(int_array, sizeof(int), &arr_size, &arr[0]);
    int_array = (int *)Push(int_array, sizeof(int), &arr_size, &arr[1]);
    int_array = (int *)Push(int_array, sizeof(int), &arr_size, &arr[2]);
    int_array = (int *)Push(int_array, sizeof(int), &arr_size, &arr[3]);
    int_array = (int *)Push(int_array, sizeof(int), &arr_size, &arr[4]);
    printf("Dynamic Integer Array: ");
    for (size_t i = 0; i < arr_size; i++)
    {
        printf("%d ", int_array[i]);
    }
    printf("\n");
    int_array = (int *)Pop(int_array, sizeof(int), &arr_size);
    printf("After Pop: ");
    for (size_t i = 0; i < arr_size; i++)
    {
        printf("%d ", int_array[i]);
    }
    printf("\n");
    int *int_element = (int *)Get(int_array, sizeof(int), 2);
    if (int_element != NULL)
    {
        printf("Element at index 2: %d\n", *int_element);
        free(int_element);
    }
    int new_int_element = 99;
    int_array = (int *)Set(int_array, sizeof(int), 2, &new_int_element);
    printf("After Set: ");
    for (size_t i = 0; i < arr_size; i++)
    {
        printf("%d ", int_array[i]);
    }
    printf("\n");
    free(int_array);
    int_array = NULL;
    printf("Dynamic array operations completed successfully.\n");
    printf("Press any key to exit...\n");
    getchar();
    getchar(); // Wait for user input before exiting
    free(dynamic_array);
    dynamic_array = NULL;
    free(int_array);
    int_array = NULL;
    printf("Memory freed successfully.\n");
    printf("Exiting program.\n");
    getchar(); // Wait for user input before exiting
    free(dynamic_array);
    return 0;
}
