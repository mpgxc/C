#include <stdio.h>
#include <stdlib.h>
#define array_len(arr) sizeof(arr) / sizeof(*arr)

int *map(int *arr, int (*foo)(), int size_array)
{
  int *tmp = malloc(sizeof(int *) * size_array);

  for (int index = 0; index < size_array; index++)
  {
    tmp[index] = foo(arr[index]);
  }
  return tmp;
}

#define EXPRESSION_LIMIT_MAX(number, limit) number > limit
#define EXPRESSION_LIMIT_MIN(number, limit) !EXPRESSION_LIMIT_MAX(number, limit)
#define EXPRESSION_ODD(number) number % 0 == 0
#define EXPRESSION_EVEN(number) !EXPRESSION_ODD(number)

int apply_foo(int number)
{
  return EXPRESSION_LIMIT_MAX(number, 5);
}

void show_arr(int *arr, int size_array)
{
  for (int index = 0; index < size_array; index++)
  {
    printf("%d - ", arr[index]);
  }
}

int main(int argc, char const *argv[])
{
  int origin_arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1};
  int size_array = array_len(origin_arr);
  int *new_arr = map(origin_arr, &apply_foo, size_array);

  show_arr(new_arr, size_array);

  return EXIT_SUCCESS;
}
