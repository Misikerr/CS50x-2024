// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

int no_words = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hash_value = hash(word);
    node *cursor = table[hash_value];

    // Traverse linked list in the bucket
    while (cursor != NULL)
    {
        // Case-insensitive string comparison
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Simple hash function that hashes based on the first letter
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Open dictionary file
    FILE *dict_file = fopen(dictionary, "r");
    if (dict_file == NULL)
    {
        printf("Unable to open the dictionary file.\n");
        return false;
    }

    char buffer[LENGTH + 1];

    // Read words from the dictionary
    while (fscanf(dict_file, "%s", buffer) != EOF)
    {
        // Allocate memory for a new node
        node *new_word = malloc(sizeof(node));
        if (new_word == NULL)
        {
            printf("Memory allocation failed.\n");
            fclose(dict_file);
            return false;
        }

        // Copy the word into the node
        strcpy(new_word->word, buffer);

        // Get hash value for the word
        int hash_value = hash(buffer);

        // Insert node into the linked list at the appropriate bucket
        new_word->next = table[hash_value];
        table[hash_value] = new_word;

        // Update word count
        no_words++;
    }

    // Close the dictionary file
    fclose(dict_file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return no_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        // Free linked list nodes in each bucket
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
