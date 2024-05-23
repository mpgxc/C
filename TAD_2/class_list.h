#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdbool.h>

#define linkedList_malloc(generic_ptr) \
  (generic_ptr *)malloc(sizeof(generic_ptr));

typedef struct self_node
{
  int this_info;
  struct self_node *next;
} Node;

typedef struct self_queue
{
  Node *head;
  // Methods
  void (*push_head)(struct self_queue *, const int);
  void (*push_rear)(struct self_queue *, const int);

  void (*show)(Node *);
  int (*size)(Node *);

  // Ainda não implementadas
  bool (*pop_head)(Node *);
  bool (*pop_rear)(Node *);

  bool (*remove_who)(Node *, const int);
  bool (*search_who)(Node *, const int);

} generic_linkedList;

generic_linkedList *initialize_linkedList();

#endif /*LIST_H*/
