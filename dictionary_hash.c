#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bucket
{
    char letter;
    bool found;
} bucket;

bucket letters[26];

int create_hash(char a);
int main(void)
{
    char arr1[] = {'c', 'A', 'e', 'f', 'q', '\0'};
    char arr2[] = {'x', 'a', 'e', 'z', '\0'};

    // create hash table

    for (int i = 0; i < strlen(arr1); i++)
    {
        if (!letters[create_hash(arr1[i])].found)
        {
            letters[create_hash(arr1[i])].letter = arr1[i];
            letters[create_hash(arr1[i])].found = true;
        }
    }

    for (int i = 0; i < strlen(arr2); i++)
    {
        if (letters[create_hash(arr2[i])].found)
        {
            printf("Found letter: %c\n", arr2[i]);
        }
    }
}

int create_hash(char a)
{
    if (a >= 'A' && a <= 'Z')
    {
        return a - 'A';
    }
    else if (a >= 'a' && a <= 'z')
    {
        return a - 'a';
    }
}
