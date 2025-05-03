#include <stdio.h>
#include <stdlib.h>

#include "../include/hashmap.h"

int main()
{
    hashmap_t* map;
    initializeHashMap(map);

    insert(map, "JEQ", 0b011);
    printf("%d\n", search(map, "JEQ"));

    return 0;
}

