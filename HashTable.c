#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HashTable.h"

HashTable* ht_create(){
    /** 
     * Creates the Hash Table.
     * IMPORTANT: USE ht_clear(...) AFTER DONE USING THE MODULE. 
     */
    HashTable* ht = NULL;
    ht = (HashTable *)calloc(1, sizeof(HashTable));
    ht->count = 0;
    printf("Hash Table is successfully created, remember to delete the Hashtable once you done using it. Call ht_clear() function for that.\n");
    return ht;
}

int check_outbound(int index){
    /** 
     * Helper function to see if the index goes out of bounds. 
     * If it does, go back to 0th index. 
     */
    if (index > TABLE_SIZE - 1){
        return 0;
    }
    return index;
}

void ht_print(HashTable* ht){
    /** 
     * Prints the Hash Table in the console.
     */
    if (ht == NULL){
        printf("Hash Table does not exists\n");
        return;
    }
    printf("\n---\tHash Table\t---\n");
    for (int i = 0; i < TABLE_SIZE; i++){
        printf("%d == %s\n", i, ht->entry[i].key);
    }
    printf("-----\tEnd\t-----\n");
}

int hash(char* str){
    /** 
     * Helper function to find the hash value of the str.
     * Returns the position of str key.
     */
    int position = 0;
    for (int i = 0; i < strlen(str); i++){
        position += (int)str[i];
    }
    position += strlen(str);
    position = position % TABLE_SIZE;
    return position;
}

void ht_add(HashTable* ht, char* key){
    /** 
     * Add the key to the Hash Table, ht.
     * It will not add if the ht is full or ht does not exist.
     */
    if(ht == NULL){
        printf("Hash Table does not exists\n");
        return;
    }
    if (ht->count > TABLE_SIZE - 1){
        printf("Hash Table is full\n");
        return;
    }
    // Collision detected
    if (ht->entry[hash(key)].key != NULL){
        if (strcmp(ht->entry[hash(key)].key, DELETE) != 0){
            int start = hash(key);
            int i = start;
            do{
                i += 1;
                check_outbound(i);
            }while (i != start && ht->entry[i].key != NULL && (strcmp(ht->entry[i].key, DELETE)) != 0);
            ht->entry[i].key = key;
            ht->count += 1;
            //printf("Collision Detected when adding %s, at %d so added in %d instead\n", key, hash(key), i);
            return;
        }
    }
    ht->entry[hash(key)].key = key;
    ht->count += 1;
    return;
}

int ht_get(HashTable* ht, char* key){
    /** 
     * Returns the place in where the key exists in the Hash Table.
     * If the key do not exists, returns -1.
     */
    if (ht == NULL){
        printf("Hash Table does not exists\n");
        return -1;
    }
    int value = hash(key);
    if (ht->entry[value].key != NULL){
        int start = value;
        do{
            if (strcmp(key, ht->entry[value].key) == 0){
                return value;
            }
            value += 1;
            value = check_outbound(value);
        }while(value != start && ht->entry[value].key != NULL);
    }
    return -1;
}

void ht_delete(HashTable* ht, char* key){
    /** 
     * Delete the key if it exists, from the Hash Table, ht.
     */
    if (ht == NULL){
        printf("Hash Table does not exists\n");
        return;
    }
    int value = hash(key);
    if (ht->entry[value].key != NULL){
        int start = value;
        do{
            if (strcmp(key, ht->entry[value].key) == 0){
                ht->entry[value].key = DELETE;
                ht->count -= 1;
                return;
            }
            value += 1;
            value = check_outbound(value);
            
        }while(value != start && ht->entry[value].key != NULL);
    }
    printf("Key do not exists\n");
    return;
}

HashTable* ht_clear(HashTable* ht){
    /** 
     * Delete the Hash Table.
     */
    free(ht);
    return NULL;
}
