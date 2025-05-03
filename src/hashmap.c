#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/hashmap.h"

void setNode(node* node, char* key, int value)
{
    node->key = key;
    node->value = value;
    node->next = NULL;
    return;
}

void initializeHashMap(struct hashMap* map)
{
    map->numNodes = 0;
    map->capacity = 8;
    map->arr = (struct node**)malloc(map->capacity * sizeof(struct node*));
}

int hashFunction(struct hashMap* map, char* key)
{
    int hash = 5381;
    int c;
    
    while(c = *key++)
    {
        hash = ((hash << 5) + hash) + c;
    }

    return hash % map->capacity;
}

void insert(struct hashMap* map, char* key, int value)
{
    int hash = hashFunction(map, key);

    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    setNode(newNode);

    if (map->arr[hash]->next == NULL)
    {
        map->arr[hash]->next = newNode;
    }

    else
    {
        map->arr[hash]->next = map->arr[hash];
        map->arr[hash] = newNode;
    }
}

void delete(struct hashMap* map, char* key)
{
    int hash = hashFunction(map, key);

    struct node* prevNode = NULL;
    struct node* currNode = map->arr[hash];

    while (currNode != NULL)
    {
        if (strcmp(currNode->key, key) == 0)
        {
            if (currNode == map->arr[hash])
            {
                currNode = currNode->next;
            }
            else
            {
                prevNode->next = currNode->next;
            }
            free(currNode);
            return;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
}

int search(struct hashMap* map, char* key);
{
    int hash = hashFunction(map, key);

    struct node* currNode = map->arr[hash];

    while (currNode->next != NULL)
    {
        if (strcmp(currNode->key, key) == 0)
        {
            return currNode->value;
        }
        currNode = currNode->next;
    }

    return -1;
}
