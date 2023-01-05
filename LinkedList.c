#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

int lenLL(LinkedList* head){
    int count = 0;
    LinkedList* ptr = head;
    while (ptr != NULL){
        count += 1;
        ptr = ptr->next;
    }
    return count;
}


LinkedList* appendLL(int data, LinkedList* head){
	LinkedList* new_node = NULL;
	new_node = (LinkedList *)calloc(1, sizeof(LinkedList));
	new_node->number = data;
	LinkedList* pointer = head;
	if (pointer == NULL){
		head = new_node;
	}else{
		while(pointer->next != NULL){
			pointer = pointer->next;
		}
		pointer->next = new_node;
	}
	return head;
}

LinkedList* insertLL(int data, int place, LinkedList* head){
    int length = lenLL(head);
    int the_place;
    if (place < 0 || place > length){
        the_place = 0;
    }else{
        the_place = place;
    }
    if (the_place == length){
        head = appendLL(data, head);
        return head;
    }
    LinkedList* ptr = head;
    LinkedList* new_node = NULL;
    LinkedList* prev = NULL;
    for(int i = 0; i < the_place; i++){
        prev = ptr;
        ptr = ptr->next; 
    }
    new_node = (LinkedList *)calloc(1, sizeof(LinkedList));
    new_node->number = data;
    new_node->next = ptr;
    if(prev == NULL){
        return new_node;
    }
    prev->next = new_node;
    return head;
}

LinkedList* removeLL(int value, LinkedList* head){
    LinkedList* current = head;
    LinkedList* previous = NULL;
    while(current != NULL && current->number != value){
        previous = current;
        current = current->next;
    }
    if(previous == NULL){
        previous = current;
        current = current->next;
        free(previous);
        return current;
    }
    //The value is not in the LinkedList
    if (current == NULL){
        return head;
    }
    previous->next = current->next;
    free(current);
    return head;
}

int indexLL(int value, LinkedList* head){
    LinkedList* ptr = head;
    int index = 0;
    while (ptr != NULL && ptr->number != value){
        index += 1;
        ptr = ptr->next;
    }
    if (index == lenLL(head)){
        return -1;
    }
    return index;
}

int countLL(int value, LinkedList* head){
    LinkedList* ptr = head;
    int count = 0;
    while (ptr != NULL){
        if (ptr->number == value){
            count += 1;
        }
        ptr = ptr->next;
    }
    return count;
}


void printLL(LinkedList* head){
	LinkedList* current = head;
	while (current != NULL){
		printf("%d -> ", current->number);
		current = current->next;
	}
	printf("NIL\n");
}

LinkedList* insertion_sortLL(LinkedList* head){
    LinkedList* first = head;
    LinkedList* second = NULL;
    while (first != NULL){
        if (first->next != NULL){
            second = first->next;
            while (second != NULL){
                if (second->number < first->number){
                    int temp = first->number;
                    first->number = second->number;
                    second->number= temp;
                }
                second = second->next;
            }
        }
        first = first->next;
    }
    return head;
}


LinkedList* clearLL(LinkedList* head){
	LinkedList* current = head;
	LinkedList* temp = NULL;
	while (current != NULL){
		temp = current->next;
		free(current);
		current = temp;
	}
	return NULL;
}

