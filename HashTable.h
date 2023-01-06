#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 8
#define DELETE "***DELETED***"

typedef struct HashEntry{
    char* key;
}HashEntry;

typedef struct HashTable{
    HashEntry entry[TABLE_SIZE];
    int count;
}HashTable;

HashTable* ht_create();

void ht_print(HashTable* ht);

void ht_add(HashTable* ht, char* key);

int ht_get(HashTable* ht, char* key);

void ht_delete(HashTable* ht, char* key);

#endif
