#include "stack.h"
#include <stdlib.h>

struct NodeImplementation{
  void* data;
  Node next;
};
struct StackImplementation{
  Node head;
  int length;

};

/**
 * Used to create a stack structure.
 * @return The newly created stack.
 */
Stack create_stack(){
  Stack newstack = (Stack)smalloc(sizeof(StackImplementation));
  newstack->head = 0;
  newstack->length = 0;
  return newstack;
}

/**
 * Used to free all memory the supplied stack allocated.
 * @param stack The stack to be deleted.
 * @note delete structure, including the struct itself, but not the data!
 */
void delete_stack(Stack stack){
  while (stack->head != 0) {
    Node to_be_deleted = stack->head;
    stack->head = stack->head->next;
    sfree(to_be_deleted);
  }
  sfree(stack);
}

/**
 * Adds a new node with the supplied data to the top of the stack.
 * @param stack The stack onto which data has to be pushed.
 * @param data The data to be pushed.
 */
void push_stack(Stack stack, void* data){
  Node newNode = (Node) smalloc(sizeof(NodeImplementation));
  newNode->data = data;
  newNode->next = 0;

  if (stack->head == 0) {
    stack->head = newNode;
  }else
  {
    newNode->next=stack->head;
    stack->head=newNode;
  }
  stack->length++;
}
/**
 * @param stack The stack which number of elements to be retrieved.
 * @return The number of items currently on the stack.
 */
int get_count(Stack stack){
  return stack->length;
}

/**
 * Removes and returns the topmost item of the stack.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.
 */
void* pop_stack(Stack stack){
  if(stack->head!=0)
  {
    Node deleteNode=stack->head;
    stack->head=stack->head->next;


    void* deletedData=deleteNode->data;
    sfree(deleteNode);
    stack->length--;
    return deletedData;
  }

  return 0;
}

/**
 * Returns the topmost item of the stack without removing it.
 * @param stack The stack from which to take.
 * @return The element returned from the stack.
*/
void* peek_stack(Stack stack){
  if (stack != 0) {
    return stack->head->data;
  }
  return 0;
}
