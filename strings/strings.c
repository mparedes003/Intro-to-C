#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s (as a pointer), return the number of characters 
    in the string.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char *s)
{
    // initialize i as an integer 0
    int i = 0;
    // while the index of s is not equal to null
    while (s[i] != '\0')
    {
        // increment i by 1
        i++;
    }
    // return 0
    return i;
}

/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/
char *reverse_string(char *rv, char *s)
{
    // initialize start position
    int start;
    // initialize end position
    int end;
    // initialize size to the string length of s
    int size = string_length(s);

    // end equals size - 1
    end = size - 1;

    for (start = 0; start < size; start++)
    {
        // the start of rv equals the end of s
        rv[start] = s[end];
        // deincrement from s[end] to s[start]
        end--;
    }
    // NULL terminator goes at the end when done
    rv[start] = '\0';
    // return rv
    return rv;
}

#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));

    return 0;
}
#endif
