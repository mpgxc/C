#include <stdio.h>
#include <string.h>

int verify_letter(char *str, int index_letter)
{

  int hit = 0;

  for (int index = 0; index < strlen(str); index++)
  {
    if (str[index] == str[index_letter])
    {
      hit += 1;
    }
  }
  return hit;
}

char find_first_letter(char *str)
{

  char letter = *str;

  for (int index = 0; index < strlen(str); index++)
  {
    if (verify_letter(str, index) == 1)
    {
      return str[index];
    }
  }
  return letter;
}

int main()
{
  char letter = find_first_letter("googleessssssssssssfcxflll");
  printf("%c\n", letter);
  return 0;
}
