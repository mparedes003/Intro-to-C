#include <stdio.h>

/*
    Your fizzbuzz implementation should initialize a counter, then
    iterate n times. If the ith iteration is divisible by 3, print
    "Fizz". If it's divisible by 5, print "Buzz". If it's divisible
    by both 3 and 5, print "FizzBuzz". Increment the counter variable
    every time that nothing gets printed and return the counter.
    Don't forget to include newlines '\n' in your printf statements!
*/
int fizzbuzz(int n)
{
    // initialize a counter
    int counter = 0;

    for (int i = 0; i <= n; i++)
    {
        // if i is divisible by 3 and 5
        if (i % 3 == 0 && i % 5 == 0)
        {
            // print FizzBuzz
            printf("FizzBuzz\n");
        }
        // else if i is divisible by
        else if (i % 3 == 0)
        {
            // print Fizz
            printf("Fizz\n");
        }
        // if i is divisible by 5
        else if (i % 5 == 0)
        {
            // print Buzz
            printf("Buzz\n");
        }
        // else
        else
        {
            // print i if not divisible by 3 and or 5
            printf("%d\n", i);
            // increment the counter variable every time i is what gets printed
            counter++;
        }
    }
    // return counter
    return counter;
}

#ifndef TESTING
int main(void)
{
    fizzbuzz(20);

    return 0;
}
#endif
