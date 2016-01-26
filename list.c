#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	list_t* return_val = head;
    
    assert(head != NULL);
    assert(new_element != NULL);
    
    //check to see if the new element should go at the head
    if(new_element->index <= head->index)
    {
        return_val = new_element;
        new_element->next = head;
        return return_val;
    }
    
    //get insert_ptr to point to the element in front of which we should 
    //insert new_element.  If it ends up as head, it goes to the start of the 
    //list.
    list_t* insert_ptr = head;
    while((insert_ptr->next != NULL) && 
          (insert_ptr->next->index < new_element->index))
    {
        insert_ptr = insert_ptr->next;
    }

    list_t* next_one = insert_ptr->next;
    insert_ptr->next = new_element;
    new_element->next = next_one;
    
    return return_val;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
    
    list_t* next;
    list_t* prev = NULL;
    while(head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    
    return prev;
}

