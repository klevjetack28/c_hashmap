#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/hashmap.h"

void setNode(node_t* node, char* key, int value)
{
    node->key = key;
    node->value = value;
    node->next = NULL;
}

void initializeHashMap(hashmap_t* map)
{
    map->numNodes = 0;
    map->capacity = 8;
    map->arr = (node_t**)malloc(map->capacity * sizeof(node_t*));
}

int hashFunction(hashmap_t* map, char* key)
{
    int hash = 5381;
    int c;
    
    while(c = *key++)
    {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % map->capacity;
}

void insert(hashmap_t* map, char* key, int value)
{
    int hash = hashFunction(map, key);

    node_t* newNode = (node_t*)malloc(sizeof(node_t*));
    setNode(newNode, key, value);

    if (map->arr[hash] == NULL)
    {
        map->arr[hash] = newNode;
    } 
    else
    {
        map->arr[hash]->next = map->arr[hash];
        map->arr[hash] = newNode;
    }
    return;
}

void delete(hashmap_t* map, char* key)
{
    int hash = hashFunction(map, key);

    node_t* prevNode = NULL;
    node_t* currNode = map->arr[hash];

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

int search(hashmap_t* map, char* key)
{
    int hash = hashFunction(map, key);

    node_t* currNode = map->arr[hash];

    while (currNode != NULL)
    {
        if (strcmp(currNode->key, key) == 0)
        {
            return currNode->value;
        }
        currNode = currNode->next;
    }

    return -1;
}
