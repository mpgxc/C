#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

typedef char *string;
typedef struct
{
  string name;
  string sname;
  unsigned short int id;
} struct_person;

#define tmp_buffer(length) ({            \
  (string) calloc(sizeof(char), length); \
})

//Aloca espaço de memória e define o valor passado por parâmetro
#define str_malloc(str) (                                            \
    {                                                                \
      string _tmp = (string)malloc(sizeof(char) * (int)strlen(str)); \
      strcpy(_tmp, str);                                             \
      _tmp;                                                          \
    })

#define struct_malloc(generic_ptr) \
  (generic_ptr *)malloc(sizeof(generic_ptr))

static void alert(const string fmt, ...)
{
  /*
        ... doing
    */
  va_list args;

  va_start(args, fmt);
  vfprintf(stderr, fmt, args);

  va_end(args);
  fputc('\n', stderr);

  exit(true);
}

string toString(struct_person *ptr)
{
  string buffer = tmp_buffer(255);
  sprintf(buffer, "name:\t%s\nsname:\t%s\nid:\t%d\n",
          ptr->name, ptr->sname, ptr->id);

  return buffer;
}

int main(int argc, string *argv)
{
  //Opa #0
  struct_person *person0 = struct_malloc(struct_person);

  person0->name = str_malloc("Mateus");
  person0->sname = str_malloc("Pinto Garcia");
  person0->id = 100;

  puts(toString(person0));

  //Opa #1
  struct_person person1[2];

  person1[0].name = "Ana Clara";
  person1[0].sname = "Pinto Garcia";
  person1[0].id = 101;

  puts(toString(&person1[0]));

  //Opa #2

  person1[1].name = str_malloc("Emiliana Vitoria");
  person1[1].sname = str_malloc("Pinto Garcia");
  person1[1].id = 102;

  puts(toString(&person1[1]));

  // Opa #3
  struct_person person2 = {
      .name = "Ana",
      .sname = "Caroline",
      .id = 103};

  puts(toString(&person2));

  alert("Matando Processo: %d / %s %d Tests %s", 1, "Done", 2, "!");

  return 0;
}
