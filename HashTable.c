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
        printf("%d == %s\n", i, ht->entry[i].key);
    }
}

int hash(char* str){
    int position = 0;
    for (int i = 0; i < strlen(str); i++){
        position += (int)str[i];
    }
    position += strlen(str);
    position = position % TABLE_SIZE;
    return position;
}

void ht_add(HashTable* ht, char* key){
    if(ht == NULL){
        printf("Hashtable does not exists\n");
        return;
    }
    if (ht->count > TABLE_SIZE - 1){
        printf("Hashtable is full\n");
        return;
    }
    if (ht->entry[hash(key)].key != NULL){
        int start = hash(key);
        int i = hash(key) + 1;
        if (i > TABLE_SIZE - 1){
            i = 0;
        }
        while (i != start && ht->entry[i].key != NULL){
            if (i > TABLE_SIZE - 1){
                i = 0;
            }
            i += 1;
        }
        ht->entry[i].key = key;
        ht->count += 1;
        printf("Collision Detected when adding %s, %d\n", key, hash(key));
        return;
    }
    ht->entry[hash(key)].key = key;
    ht->count += 1;
    return;
}

//NOTE: Hash Table Resizing  can be tricky so tell user hash table is full and ask them to expand hash table.

//Implement first ht_delete. Worry about Resizing later. 

int ht_get(HashTable* ht, char* key){
    int value = hash(key);
    if (ht->entry[value].key == NULL){
        return -1;
    }
    if (strcmp(key, ht->entry[value].key) == 0){
        return value;
    }
    int start = value;
    value += 1;
    if (value > TABLE_SIZE - 1){
            value = 0;
    }
    while (value != start && ht->entry[value].key != NULL){
        if (value > TABLE_SIZE - 1){
            value = 0;
        }
        if (strcmp(key, ht->entry[value].key) == 0){
            return value;
        }
        value += 1;
    }
    return -1;
}
