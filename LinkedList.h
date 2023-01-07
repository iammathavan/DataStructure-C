#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/* IMPORTANT: After finish using the LinkedList, call the clearLL(...) function to free up the memory. */

/* Structure for the node, number is the value to be stored in the list.  */
typedef struct LinkedList{
	int number;
	struct LinkedList* next;
}LinkedList;

/* Returns the length of the List.  */
int lenLL(LinkedList* head);

/* Append to the List, add data to the end of the List.  */
LinkedList* appendLL(int data, LinkedList* head);

/* Insert data in the provided place of the List.  */
LinkedList* insertLL(int data, int place, LinkedList* head);

/* Remove/Delete the value from the List. */
LinkedList* removeLL(int value, LinkedList* head);

/* Returns the index or the position of the value in the List.  */
int indexLL(int value, LinkedList* head);

/* Returns the number of times the value appear in the List.  */
int countLL(int value, LinkedList* head);

/* Sort the List using Insertion Sort Algorithm.  */
LinkedList* insertion_sortLL(LinkedList* head);

/* Print the List into the console.  */
void printLL(LinkedList* head);

/* Delete the List.  */
LinkedList* clearLL(LinkedList* head);
#endif
