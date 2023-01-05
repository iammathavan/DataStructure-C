#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 32

typedef struct HashEntry{
    char* value;
}HashEntry;

typedef struct HashTable{
    HashEntry entry[TABLE_SIZE];
    int count;
}HashTable;

HashTable* ht_create();

void ht_print(HashTable* ht);

void ht_add(HashTable* ht, char* value);

char* ht_get(HashTable* ht, int key);

#endif
