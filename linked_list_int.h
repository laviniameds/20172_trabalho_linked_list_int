/**
 * ANSI C Linked List of int values library
 *
 * Author:
 * Date:
 *
 */

#ifndef _LINKED_LIST_INT_H_
#define _LINKED_LIST_INT_H_

/**
 * Type: linked_list_int
 * Description: a linked_list_int is a pointer to a type that
 *              stores the dynamic data. The struct is
 *              defined in the linked_list_int implementation.
 *
 */
typedef struct linked_list_int * linked_list_int;

/**
 * Function: linked_list_int lli_init();
 *
 * Description: Creates and initialize a dynamic linked list of integers.
 *
 * Return: The linked_list_int type, a reference (pointer)
 *         to a dynamic linked implementation
 *
 */
linked_list_int lli_create();

/**
 * Function: int lli_get(linked_list_int lli, int index);
 *
 * Description: Gets the element at index 'index'.
 *
 * Return: The element located at index i.
 *         The value is undeterminated if index is not in the range [0..size-1]
 *
 */
int lli_get(linked_list_int lli, int index);

/**
 * Function: unsigned int lli_push_back(linked_list_int lli, int i);
 *
 * Description: Add integer value 'i' to the end of the 'lli' dynamic linked.
 *
 * Return: The number of elements stored in 'lli' AFTER inserting 'i'.
 *
 */
unsigned int lli_push_back(linked_list_int lli, int i);

/**
 * Function: unsigned int lli_pop_back(linked_list_int lli);
 *
 * Description: Removes the last element of the dynamic linked
 *              referenced (pointed) by 'lli.
 *
 * Return: The number of elements after deletion. -1 if the linked
 *         was empty before deletion.
 *
 */
unsigned int lli_pop_back(linked_list_int lli);


/**
 * Function: unsigned int lli_size(linked_list_int lli);
 *
 * Description: Computes the number of int elements stored in 'lli'.
 *
 * Return: The number of integer values stored in 'lli'.
 *
 */
unsigned int lli_size(linked_list_int lli);

/**
 * Function: int lli_find(linked_list_int lli, int element);
 *
 * Description: Gets the index of  element 'element'.
 *
 * Return: The index of element 'element' if element is in the range [0..size-1].
 *
 */
int lli_find(linked_list_int lli, int element);

/**
 * Function: int lli_insert_at(linked_list_int lli, int index, int value);
 *
 * Description: Inserts int value 'value' at index 'index'. 'index' must
 *              be a valid index, between 0 and 'lli_size'-1.
 *
 * Return: the value index, if insertion ok or -1 if the insertion could
 *         not be done.
 *
 */
int lli_insert_at(linked_list_int lli, int index, int value);

/**
 * Function: lli_remove_from(linked_list_int lli, int index);
 *
 * Description: Removes the value at index 'index'. 'index' must
 *              be a valid index, between 0 and 'lli_size'-1.
 *
 * Return: The size of the new linked_list_int.
 *
 */
int lli_remove_from(linked_list_int lli, int index);

/**
 * Function: unsigned int lli_capacity(linked_list_int lli);
 *
 * Description: Computes the linked_list_int lli capacity.
 *
 * Return: The capicity of the 'lli' linked_list_int.
 *
 */
unsigned int lli_capacity(linked_list_int lli);

/**
 * Function: unsigned int lli_percent_occuped(linked_list_int lli);
 *
 * Description: Check the linked_list_int 'lli' occupation, in percent.
 *
 * Return: A double, from 0 to 1 with the occupation rate of 'lli'.
 *
 */
double lli_percent_occuped(linked_list_int lli);

/**
 * Function: void lli_destroy(linked_list_int lli);
 *
 * Description: Relese memory used by the 'lli' reference.
 *              Invalidate memory area too.
 *
 */
void lli_destroy(linked_list_int lli);

#endif
