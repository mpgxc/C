#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define inlinetialize_linkedList \
  NULL

#define linkedList_malloc(generic_ptr) \
  (generic_ptr *)malloc(sizeof(generic_ptr))

typedef char *string;
typedef struct this
{
  int this_value;
  struct this *next;
}
linkedList;

linkedList *linkedList_append(linkedList *origin_linkedList, int value)
{
  linkedList *tmp = linkedList_malloc(linkedList);
  tmp->this_value = value;
  tmp->next = NULL;

  if (origin_linkedList != NULL)
  {
    linkedList *aux = origin_linkedList;

    while (aux->next != NULL)
      aux = aux->next;
    aux->next = tmp;
    // O intuído é criar  um novo estado para a lista
    // e não utilizar o ponteiro de referência para manipular a memória.
    return origin_linkedList;
  }
  return tmp;
}

void linkedList_show(linkedList *origin_linkedList)
{
  if (origin_linkedList != NULL)
  {
    printf("%d\n", origin_linkedList->this_value);
    linkedList_show(origin_linkedList->next);
  }
}

int main(int argc, string *argv)
{
  // State Pattern > Imutabilidade

  linkedList *my_linkedList = inlinetialize_linkedList;

  my_linkedList = linkedList_append(my_linkedList, 1);
  my_linkedList = linkedList_append(my_linkedList, 2);
  my_linkedList = linkedList_append(my_linkedList, 3);
  my_linkedList = linkedList_append(my_linkedList, 4);
  my_linkedList = linkedList_append(my_linkedList, 5);

  linkedList_show(my_linkedList);

  return 0;
}
