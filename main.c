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
    ht_add(ht, "Hello");
    ht_add(ht, "Guys");
    ht_add(ht, "How");
    ht_add(ht, "You");
    ht_add(ht, "Doing");
    ht_add(ht, "Apple");
    ht_add(ht, "Banana");
    ht_add(ht, "Orange");
    ht_add(ht, "Table");
    ht_add(ht, "Map");
    ht_add(ht, "Guys");
    ht_print(ht);
    printf("%s\n", ht_get(ht, 0));
    printf("Num of val in HT are %d\n", ht->count);
	return 0;
}
