#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void imprimir_endereco(const Endereco *endereco)
{
  if (endereco != NULL)
  {
    printf("Rua: %s, Número: %d, Cidade: %s, Estado: %s, CEP: %s\n",
           endereco->rua, endereco->numero, endereco->cidade, endereco->estado, endereco->cep);
  }
}

void destruir_endereco(Endereco *endereco)
{
  if (endereco != NULL)
  {
    free(endereco);
  }
}

Endereco *criar_endereco(const char *rua, int numero, const char *cidade, const char *estado, const char *cep)
{
  Endereco *endereco = (Endereco *)malloc(sizeof(Endereco));
  if (endereco == NULL)
  {
    return NULL;
  }

  endereco->rua = (char *)rua;
  endereco->cep = (char *)cep;
  endereco->cidade = (char *)cidade;
  endereco->estado = (char *)estado;
  endereco->numero = numero;

  endereco->imprimir = imprimir_endereco;
  endereco->destruir = &destruir_endereco;

  return endereco;
}

void imprimir_pessoa(const Pessoa *pessoa)
{
  if (pessoa != NULL)
  {
    printf("Nome: %s, Idade: %d\n", pessoa->nome, pessoa->idade);

    pessoa->endereco.imprimir(&pessoa->endereco);
  }
}

void destruir_pessoa(Pessoa *pessoa)
{
  if (pessoa != NULL)
  {
    free(pessoa);
  }
}

Pessoa *criar_pessoa(const char *nome, int idade, Endereco *endereco)
{
  Pessoa *pessoa = (Pessoa *)malloc(sizeof(Pessoa));
  if (pessoa == NULL)
  {
    return NULL;
  }

  pessoa->idade = idade;
  pessoa->nome = (char *)nome;
  pessoa->endereco = *endereco;

  pessoa->imprimir = imprimir_pessoa;
  pessoa->destruir = &destruir_pessoa;

  return pessoa;
}
