#ifndef HASHMAP_H
#define HASHMAP_H

struct node 
{
    char* key;
    int value;
    struct node* next;
};

struct hashMap
{
    int numNodes, capacity;
    struct node** map;  
};

void setNode(node* node, char* key, int value);

void initializeHashMap(struct hashMap* map);

int hash(struct hashMap* map, char* key);

void insert(struct hashMap* map, char* key, int value);

void delete(struct hashMap* map, char* key);

int search(struct hashMap* map, char* key);

#endif // HASHMAP_H
