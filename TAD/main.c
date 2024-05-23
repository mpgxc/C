#include <stdio.h>
#include "header.h"

int main()
{
  Endereco *endereco = criar_endereco("Rua Exemplo", 123, "Cidade Exemplo", "Estado Exemplo", "12345-678");

  if (endereco == NULL)
  {
    fprintf(stderr, "Erro ao criar o endereço\n");
    return 1;
  }

  Pessoa *pessoa = criar_pessoa("João Silva", 30, endereco);
  if (pessoa == NULL)
  {
    fprintf(stderr, "Erro ao criar a pessoa\n");
    endereco->destruir(endereco);
    return 1;
  }

  pessoa->imprimir(pessoa);

  endereco->destruir(endereco);
  pessoa->destruir(pessoa);

  return 0;
}
