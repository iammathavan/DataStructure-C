#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HashTable.h"

HashTable* ht_create(){
    HashTable* ht = NULL;
    ht = (HashTable *)calloc(1, sizeof(HashTable));
    ht->count = 0;
    return ht;
}

void ht_print(HashTable* ht){
    if (ht == NULL){
        printf("Hashtable does not exists\n");
        return;
    }
    for (int i = 0; i < TABLE_SIZE; i++){
        printf("%d == %s\n", i, ht->entry[i].value);
    }
}

int hash(char* value){
    int position = 0;
    for (int i = 0; i < strlen(value); i++){
        position += (int)value[i];
    }
    position += strlen(value);
    position = position % TABLE_SIZE;
    return position;
}

void ht_add(HashTable* ht, char* value){
    if(ht == NULL){
        printf("Hashtable does not exists\n");
        return;
    }
    if (ht->count > TABLE_SIZE - 1){
        printf("Hashtable is full\n");
        return;
    }
    if (ht->entry[hash(value)].value != NULL){
        int start = hash(value);
        int i = hash(value) + 1;
        if (i > TABLE_SIZE - 1){
            i = 0;
        }
        while (i != start && ht->entry[i].value != NULL){
            if (i > TABLE_SIZE - 1){
                i = 0;
            }
            i += 1;
        }
        ht->entry[i].value = value;
        ht->count += 1;
        printf("Collision Detected when adding %s\n", value);
        return;
    }
    ht->entry[hash(value)].value = value;
    ht->count += 1;
    return;
}

//NOTE: Hash Table Resizing  can be tricky so tell user hash table is full and ask them to expand hash table.

//Implement first ht_get, then ht_delete. Worry about collision later. 

//Modify it so it returns the position of the string
char* ht_get(HashTable* ht, int key){
    if (ht->entry[key].value == NULL){
        printf("The value is not found :(\n");
        return "";
    }
    return ht->entry[key].value;
}
