#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    // while the value of y(y pointer) is not a NULL terminator
    while (*y != '\0')
    {
        // the value of x(x pointer) is equal to the value of y(y pointer)
        *x = *y;
        // increment x by 1
        x++;
        // increment y by 1
        y++;
    }
    // when the value of y(y pointer) = '\0', the value of x(x pointer) will also be '\0'
    *x = '\0';
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    // initialize char pointer target to equal NULL
    char *target = NULL;
    // initialize i to equal 0
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        // if the value of str at index i equals c
        if (str[i] == c)
        {
            // the target is at the address of str at index i
            target = &str[i];
            // stop
            break;
        }
        // if the value of str at index i equals the NULL terminator
        if (str[i] == '\0')
            // stop
            break;
    }
    // return target
    return target;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
    // initialize the char pointer h to equal haystack
    char *h = haystack;

    // while the value of h is not equal to the NULL terminator
    while (*h != '\0')
    {
        // initialize the char pointer h_beginning to equal h
        char *h_begin = h;
        // initialize the char pointer n to equal needle
        char *n = needle;

        // while the value of h is not equal to the NULL terminator
        while (*h != '\0')
        {
            // increment h by 1 (continue going through the haystack)
            h++;
            // increment n by 1 (continue collecting the needle)
            n++;
        }
        // if the value of n is equal to the NULL terminator
        if (*n == '\0')
        {
            // return h_begin
            return h_begin;
        }
        // increment h by 1
        h++;
    }
    // return NULL
    return NULL;
}

#ifndef TESTING
int main(void)
{
    char *hello = "Hello!";
    char *world = "World";
    char buffer[1024];

    string_copy(buffer, "Hello!");

    printf("%s\n", buffer);

    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
