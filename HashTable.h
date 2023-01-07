#ifndef HASHTABLE_H
#define HASHTABLE_H

/* IMPORTANT: THE HASH TABLE USES LINEAR PROBING.  */

#define DELETE "***DELETED***"
/* IMPORTANT: THE TABLE IS FIXED, IF YOU WANT TO CHANGE TABLE SIZE DO SO ACCORDING TO YOUR DATA BELOW.  */
#define TABLE_SIZE 32

/* Basic Structure to store the key.  */
typedef struct HashEntry{
    char* key;
}HashEntry;

/* Hash Table structure, that has the arrays of entries, and count, which is number of items in the Hash Table.  */
typedef struct HashTable{
    HashEntry entry[TABLE_SIZE];
    int count;
}HashTable;

/* Create Hash Table.  */
HashTable* ht_create();

/* Print Hash Table.  */
void ht_print(HashTable* ht);

/* Add new key into the Hash Table.  */
void ht_add(HashTable* ht, char* key);

/* Get the place at where the key is at in the Hash Table.  */
int ht_get(HashTable* ht, char* key);

/* Delete the key from the Hash Table.  */
void ht_delete(HashTable* ht, char* key);

/* Delete the Hash Table.  */
HashTable* ht_clear(HashTable* ht);

#endif
