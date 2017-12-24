#include "linked_list_int.h"

#include <stdlib.h> /* For malloc and free */

#define MAGIC 271828182

struct _lli_{
  int value;
  struct _lli_ *next;
};

struct linked_list_int{
  struct _lli_ * first_node;
  int magic;
  int size;
};

/* Internal functions */

/* Check if the pointer actually points to a valid linked_list_int struc */
int lli_check_type(linked_list_int lli){
  if (lli->magic!=MAGIC){
    return 0;
  } else {
    return 1;
  }
}

/* External (public) functions.
 * + Defined in linked_list_int.h file
 */

/* creates new instance of a dynamic array */
linked_list_int lli_create(){
  linked_list_int lli = (linked_list_int)malloc(sizeof(struct linked_list_int));
  lli->first_node = NULL;
  lli->magic = MAGIC;
  lli->size = 0;
  return lli;
}

/* Gets the element at index 'index' */
int lli_get(linked_list_int lli, int index){
  if (!lli_check_type(lli))
    return 0;
  int current_index=0;
  struct _lli_ *current_node=lli->first_node;
  while (current_index<index &&
         current_node !=NULL){
    current_index++;
    current_node = current_node->next;
  }
  if (current_node==NULL){
    return 0;
  }
  return current_node->value;
}

/* Adds element 'i' to the end of the linked list */
unsigned int lli_push_back(linked_list_int lli, int i){
  if (!lli_check_type(lli))
    return 0;
  struct _lli_ *new_node = (struct _lli_*) malloc(sizeof(struct _lli_));
  new_node->value=i;
  new_node->next=NULL;
  if (lli->first_node == NULL){
    lli->first_node = new_node;
  } else {
    struct _lli_ *current_node = lli->first_node;
    while (current_node->next!=NULL)
      current_node = current_node->next;
    current_node->next=new_node;
  }
  lli->size = lli_size(lli) + 1;
  return 1;
}

/* Removes last element of linked list 'lli'
 *
 * TODO
 */
unsigned int lli_pop_back(linked_list_int lli){
  if (!lli_check_type(lli))
    return 0;

  struct _lli_ *current_node = lli->first_node;
  struct _lli_ *aux = lli->first_node;

  int size = lli_size(lli);
  while (current_node->next != NULL){
    aux = current_node;
    current_node = current_node->next;
  }

  aux->next = NULL;
  lli->size = size-1;
  free(current_node);

  return 0;
}


/* Gets number of int elements stored in 'lli'
 * TODO: Optimize size with a variable that stores
 * the number of nodes in the list. Must update all
 * functions that change number of nodes.
 *
 */
unsigned int lli_size(linked_list_int lli){
  if (!lli_check_type(lli))
    return 0;
  /*int size=0;
  struct _lli_ *current_node = lli->first_node;
  while (current_node!=NULL){
    size++;
    current_node = current_node->next;
  }*/
  return lli->size;
}


/*
 * TODO:
*/
int lli_find(linked_list_int lli, int element){
  if (!lli_check_type(lli))
    return 0;

  int index = 0;
  struct _lli_ *current_node = lli->first_node;
  while (current_node!=NULL){
    if(current_node->value == element)
      return index;
    current_node = current_node->next;
    index++;
  }

  return -1;
}

/**
 * TODO:
 */
int lli_insert_at(linked_list_int lli, int index, int value){
  if (!lli_check_type(lli))
    return -1;

  if(index >= lli_size(lli))
    return -1;

  int current_index = -1;
  struct _lli_ *current_node=lli->first_node;
  struct _lli_ *aux;

  struct _lli_ *new_node = (struct _lli_*) malloc(sizeof(struct _lli_));
  new_node->value=value;

  while (current_index<index &&
         current_node != NULL){

    current_index++;

    if(current_index == index-1){
      aux = current_node->next;
      current_node->next = new_node;
      new_node->next = aux;

      lli->size = lli_size(lli) + 1;
      return current_index;
    }
    else{
      current_node = current_node->next;
    }
  }

  return -1;
}

/**
 * TODO:
 */
int lli_remove_from(linked_list_int lli, int index){
  return -1;
}

/**
 * TODO: */
unsigned int lli_capacity(linked_list_int lli){
  if (!lli_check_type(lli))
    return 0;
  return lli->size;
}


/**
 * TODO: */
double lli_percent_occuped(linked_list_int lli){
  return 1.0;
}

/* Release memory used by the struct and invalidate it.
 *
 * TODO
 */
void lli_destroy(linked_list_int lli){
  /* TODO: Apagar todos os nós da lista */

    struct _lli_ *current_node = lli->first_node;
    struct _lli_ *aux;
    while (current_node!=NULL){
      aux = current_node;
      current_node = current_node->next;

      aux->value = 0;

      free(aux);
    }
    lli->magic = 0;
  }
