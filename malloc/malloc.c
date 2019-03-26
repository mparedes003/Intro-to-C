#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

/*
    Duplicates the input string by dynamically allocating memory for 
    the duplicate string using `malloc` and then copying the string
    into the allocated memory. Returns a pointer to the allocated memory.
    You may want to use the string_length function to figure out the
    length of the input string.
    
    Do not use the `strdup` function from the standard library.
*/

char *string_dup(char *src)
{
    // initialize x that is equal to the string length of the source
    int x = string_length(src);
    // initialize character dup string to equal the string length of src + 1 using malloc
    char *dup = malloc(x + 1);

    for (int i = 0; i < x; i++)
    {
        // make the value of dup at each index equal the value of src at each index
        *(dup + i) = *(src + i);
    }
    // make the value of dup at index x equal to the NULL terminator
    *(dup + x) = '\0';

    // return dup
    return dup;
}

/*
    A generic version of string_copy, mem_copy receives a block of memory
    of any type and copies its contents to the destination pointer (dest).
    You may want to cast the input pointers to char pointers first before
    performing the copying. `n` is the amount of data that should be copied
    from `src` to `dest`. 
*/
void *mem_copy(void *dest, const void *src, int n)
{
    char *charsrc = (char *)src;
    char *chardest = (char *)dest;

    for (int i = 0; i < n; i++)
    {
        // make the value of chardest at each index i equal to the value of charsrc at each index i
        *(chardest + i) = *(charsrc + i);
    }
    // return chardest
    return chardest;
}

/*
    Given a pointer that `malloc`'d memory, this function will 
    attempt to resize the allocated memory to the new specified
    size. Any data that was previously in the old `malloc`'d 
    memory should be intact in the new resized block of memory. 

    Some edge cases to consider: how should resizing be handled
    in the case when old_size < new_size? What about when 
    old_size > new_size?

    Do not use the `realloc` function from the standard libary.
*/
// Still getting this error when using either option
// [ERROR] (tests/malloc_tests.c:63: errno: None)
// Your resize_memory function did not truncate the size of the given string correctly.
void *resize_memory(void *ptr, int old_size, int new_size)
{
}

#ifndef TESTING
int main(void)
{
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);

    printf("Duplicated string: %s\n", dup);

    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int *target = malloc(n * sizeof(int));

    mem_copy(target, numbers, n * sizeof(int));

    printf("Copied array: ");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", target[i]);
    }

    printf("\n");

    char *url = string_dup("http://lambdaschool.com");
    char *path = string_dup("/students/");
    int url_length = string_length(url);
    int path_length = string_length(path);

    int new_length = url_length - 1 + path_length;
    char *new_url = resize_memory(url, url_length, new_length);
    char *p = new_url + url_length;

    while (*path != '\0')
    {
        *p = *path;
        p++;
        path++;
    }

    printf("Full path string: %s\n", new_url);

    return 0;
}
#endif
