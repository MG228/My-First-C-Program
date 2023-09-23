// 
// Implementation for linked list.
//
// <Maya Griffin>

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"
// Intended to allocate memory for a new list
list_t *list_alloc() {
  list_t* new_list = (list_t*)malloc(sizeof(list_t));
  if (new_list == NULL) {
    exit(1);
  }
  new_list->head = NULL;
  return new_list;
}

// Intended to free memory used by list
void list_free(list_t *l) {
  if (l == NULL) {
    return;
  }

  Node* current = l->head;
  while(current != NULL) {
    Node* temp = current;
    current = current->next;
    free(temp);
  }
  free(l);
}

// Intended to print the elements
void list_print(list_t *l) {
  if (l == NULL) {
    printf("List empty.\n");
    return;
  }

  Node* current = l->head;
  while (current != NULL) {
    printf ("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

// intended to return the length of list
int list_length(list_t *l) {
  int length = 0;

  if (l == NULL) {
    return length;
  }
  Node* current = l->head;
  while (current != NULL){
    length++;
    current = current->next;
  }
  return length;

}

// intended to add elem at the tail
void list_add_to_back(list_t *l, elem value) {
   if (l == NULL) {
        return;
    }
    Node* newNode = createNode(value);
    if (l->head == NULL) {
        l->head = newNode;
    } else {
        Node* current = l->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// intended to add elem at the head
void list_add_to_front(list_t *l, elem value) {
  if (l == NULL) {
    return;
  }

  Node* newNode = createNode(value);
  newNode->next = l->head;
  l->head = newNode;
}

// intended to add elem at given index
void list_add_at_index(list_t *l, elem value, int index) {
  if (l == NULL || index < 0) {
        return; 
    }
    Node* newNode = createNode(value); 
    if (index == 0) {
        newNode->next = l->head;
        l->head = newNode;
    } else {
        Node* current = l->head;
        int i = 0;
        while (current != NULL && i < index - 1) {
            current = current->next;
            i++;
        }
        if (current != NULL) {
            newNode->next = current->next;
            current->next = newNode;
        } else {
            list_add_to_back(l, value);
        }
    }
}

// intended to remove elem at the tail
elem list_remove_from_back(list_t *l) {
  if (l == NULL || l->head == NULL) {
    return -1;
  }
  
  if (l->head->next == NULL) {
    elem data = l->head->data;
    free(l->head);
    l->head = NULL;
    return data;
  }
  Node* current = l->head;
  while (current->next->next != NULL) {
    current = current->next;
  }
  
  elem data = current->next->data;
  free(current->next);
  current->next = NULL;
  return data;
}

// intended to remove elem at the head
elem list_remove_from_front(list_t *l) {
  if (l == NULL || l->head == NULL) {
    return -1;
  }
  Node* removedNode = 1->head;
  elem data = removedNode->data;

  l->head = l->head->next;
  free(removedNode);
  
   return data;
}

// intended to remove elem at the given index
elem list_remove_at_index(list_t *l, int index) {
  (l == NULL || index < 0 || l->head == NULL) {
    return -1;
  }
  if (index == 0) {
    Node* removedNode = l->head;
    elem data = removedNode->data;
    l->head = l->head->next;
    return data;
  }

  Node* current = l->head;
  int i = 0;
  while (current->next != NULL && i < index - 1) {
    current = current->next;
    i++;
  }

  if (i < index - 1 || current->next == NULL) {
    return -1;
  }

  Node* removedNode = current->next;
  elem data = removedNode->data;
  current->next = current->next->next;
  free(removedNode);
  return data;
}

// intended to see if elem in list
bool list_is_in(list_t *l, elem value) {
if (l == NULL || l->head == NULL) {
        return false; 
    }

    Node* current = l->head;
    while (current != NULL) {
        if (current->data == value) {
            return true; 
        }
        current = current->next;
    }

    return false; 
}

// intended to return elem at given index
elem list_get_elem_at(list_t *l, int index) {
if (l == NULL || index < 0 || l->head == NULL) {
        return -1; 
    }
    Node* current = l->head;
    int i = 0;
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }
    if (i == index && current != NULL) {
        return current->data; 
    }
    return -1;
}

// intended to return the index of the first occurance of given elem
int list_get_index_of(list_t *l, elem value) {
  if (l == NULL || l->head == NULL) {
  return -1; 
  }
  Node* current = l->head;
  int index = 0;

  while (current != NULL) {
    if (current->data == value) {
      return index;
    }
    current = current->next;
    index++;
  }
  return -1;

}