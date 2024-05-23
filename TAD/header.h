#ifndef HEADER_H
#define HEADER_H

typedef struct Endereco Endereco;
typedef struct Pessoa Pessoa;

struct Endereco
{
  int numero;
  char *rua;
  char *cidade;
  char *estado;
  char *cep;

  void (*imprimir)(const Endereco *);
  void (*destruir)(Endereco *);
};

struct Pessoa
{
  char *nome;
  int idade;
  Endereco endereco;

  void (*imprimir)(const Pessoa *);
  void (*destruir)(Pessoa *);
};

Endereco *criar_endereco(const char *rua, int numero, const char *cidade, const char *estado, const char *cep);
Pessoa *criar_pessoa(const char *nome, int idade, Endereco *endereco);

#endif // HEADER_H
