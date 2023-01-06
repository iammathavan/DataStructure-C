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

int check_outbound(int value){
    if (value > TABLE_SIZE - 1){
        return 0;
    }
    return value;
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
        if (strcmp(ht->entry[hash(key)].key, DELETE) != 0){
            int start = hash(key);
            int i = hash(key) + 1;
            i = check_outbound(i);
            while (i != start && ht->entry[i].key != NULL && (strcmp(ht->entry[i].key, DELETE)) != 0){
                i += 1;
                i = check_outbound(i);
            }
            ht->entry[i].key = key;
            ht->count += 1;
            printf("Collision Detected when adding %s, at %d so added in %d instead\n", key, hash(key), i);
            return;
        }
    }
    ht->entry[hash(key)].key = key;
    ht->count += 1;
    return;
}

//NOTE: Hash Table Resizing  can be tricky so tell user hash table is full and ask them to expand hash table.

int ht_get(HashTable* ht, char* key){
    if (ht == NULL){
        printf("Hashtable does not exists\n");
        return -1;
    }
    int value = hash(key);
    if (ht->entry[value].key == NULL){
        return -1;
    }
    if (strcmp(key, ht->entry[value].key) == 0){
        return value;
    }
    int start = value;
    value += 1;
    value = check_outbound(value);
    while (value != start && ht->entry[value].key != NULL){
        if (strcmp(key, ht->entry[value].key) == 0){
            return value;
        }
        value += 1;
        value = check_outbound(value);
    }
    return -1;
}

void ht_delete(HashTable* ht, char* key){
    int value = hash(key);
    if (ht->entry[value].key == NULL){
        printf("Key do not exists\n");
        return;
    }
    if (strcmp(key, ht->entry[value].key) == 0){
        ht->entry[value].key = DELETE;
        ht->count -= 1;
        return;
    }
    int start = value;
    value += 1;
    value = check_outbound(value);
    while (value != start && ht->entry[value].key != NULL){
        if (strcmp(key, ht->entry[value].key) == 0){
            ht->entry[value].key = DELETE;
            ht->count -= 1;
            return;
        }
        value += 1;
        value = check_outbound(value);
    }
    printf("Key do not exists\n");
    return;
}
