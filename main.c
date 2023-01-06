#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "HashTable.h"

int main(){
    //Just need to implement the sorting algorithms for LL.
// 	LinkedList* head = NULL;
//     head = insertLL(1, 0, head);
//     head = insertLL(5, 0, head);
//     head = insertLL(4, 0, head);
//     head = insertLL(7, -1, head);
//     head = insertLL(2, 3, head);
//     head = insertLL(9, 2, head);
//     head = appendLL(4, head);
//     printLL(head);
//     head = insertion_sortLL(head);
//     printf("Printing the List\n");
//     printLL(head);
//     printf("The length of the LL is %d\n", lenLL(head));
//     printf("The index of it is %d\n", indexLL(18, head));
//     printf("The num of occurance of it is %d\n", countLL(4, head));
//     head = clearLL(head);
//     printf("Printing the List\n");
//     printLL(head);
    HashTable* ht = NULL;
    ht = ht_create();
    ht_add(ht, "Toy Story");
    ht_add(ht, "End Game");
    ht_add(ht, "Django Unchained");
    printf("Initial\n");
    ht_print(ht);
    printf("The number of items are %d\n", ht->count);
    ht_add(ht, "Jackie Chan 3");
    ht_add(ht, "Mission Impossible");
    printf("After adding 2 movies\n");
    ht_print(ht);
    printf("The number of items are %d\n", ht->count);
    ht_delete(ht, "End Game");
    printf("After deleting end game\n");
    ht_print(ht);
    printf("The number of items are %d\n", ht->count);
    ht_delete(ht, "Jackie Chan 3");
    printf("After deleting JC\n");
    ht_print(ht);
    printf("The number of items are %d\n", ht->count);
    ht_add(ht, "Jackie Chan 3");
    printf("After re-adding JC\n");
    ht_print(ht);
    printf("The number of items are %d\n", ht->count);
	return 0;
}
