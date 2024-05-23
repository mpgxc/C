#include <stdlib.h>
#include <stdio.h>

#define BREAK_LINE puts("");
#define array_len(arr)  (sizeof(arr) / sizeof((*arr)))

void reverse(int *arr, int size_arr)
{
  for (int index = 0; index < size_arr / 2; index++)
  {
    int lower = arr[index];
    int upper = size_arr - index - 1;

    arr[index] = arr[upper];
    arr[upper] = lower;
  }
}

void show(const int *arr, int size_arr)
{
  for (int index = 0; index < size_arr; index++)
  {
    printf("%d ", arr[index]);
  }
}

int main(int argc, char const *argv[])
{
  int arr[] = {1, 2, 3, 4, 5,6 ,7 , 8, 9, 0};
  int size_arr = array_len(arr);

  show(arr, size_arr);
  BREAK_LINE

  reverse(arr, size_arr);

  show(arr, size_arr);
  BREAK_LINE

  return EXIT_SUCCESS;
}
