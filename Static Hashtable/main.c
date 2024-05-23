#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAMANHO_HT 101

/*
    Código produzido durante a cadeira Estruturas de Dados II
*/

typedef struct
{
  char *Chave;
} hashTable;

hashTable *criaTabela(const int Tamanho)
{
  hashTable *Temp = (hashTable *)calloc(sizeof(hashTable), Tamanho);

  for (int init = 0; init < Tamanho; init++)
  {
    Temp[init].Chave = (char *)calloc(sizeof(char), 15);
  }
  return Temp;
}

int h(char *Chave)
{
  int k = 0;
  for (int i = 1; i <= strlen(Chave); i++)
  {
    k += Chave[i - 1] * i;
  }
  return k * 19;
}

int calculaHash(char *Chave)
{
  return h(Chave) % TAMANHO_HT;
}

int Colisoes(hashTable *tabela, char *Chave)
{
  int hash, conta = 1;

  for (int i = 0; i <= 20; i++)
  {
    hash = h(Chave) + (conta * conta) + (23 * conta);
    hash = hash % TAMANHO_HT;

    if (strlen(tabela[hash].Chave) == 0)
    {
      return hash;
    }
  }
  return -1; // Deu erro!
}

void Inserir(hashTable *tabela, char *Chave)
{
  int hash = calculaHash(Chave);
  if (strlen(tabela[hash].Chave) == 0)
  {
    strcpy(tabela[hash].Chave, Chave);
  }
  else if (strcmp(tabela[hash].Chave, Chave) == 0)
  {
    puts("Chave já inserida!");
  }
  else
  {
    hash = Colisoes(tabela, Chave);
    if (hash != (-1))
    {
      strcpy(tabela[hash].Chave, Chave);
    }
  }
}

void Remover(hashTable *tabela, char *Chave)
{
  int hash = calculaHash(Chave);
  if (strlen(tabela[hash].Chave) != 0)
  {
    if (strcmp(tabela[hash].Chave, Chave) == 0)
    {
      printf("%s - Encontrado!\n", Chave);
      strcpy(tabela[hash].Chave, "");
      return;
    }
    else
    {
      int hash, conta = 1;

      for (int i = 0; i <= 20; i++)
      {
        hash = h(Chave) + (conta * conta) + (23 * conta);
        hash = hash % TAMANHO_HT;

        if (strcmp(tabela[hash].Chave, Chave) == 0)
        {
          printf("%s - Encontrado! [Remake]\n", Chave);
          strcpy(tabela[hash].Chave, "");
          return;
        }
      }
    }
  }
  printf("%s - Elemento não existe!\n", Chave);
  return;
}

void Listar(FILE *fileSaida, hashTable *tabela, const int Tamanho)
{
  int Count = 0;
  for (int i = 0; i < Tamanho; i++)
    if (strlen(tabela[i].Chave) != 0)
      Count++;

  fprintf(fileSaida, "%d\n", Count);

  for (int i = 0; i < Tamanho; i++)
    if (strlen(tabela[i].Chave) != 0)
      fprintf(fileSaida, "%d:%s\n", i, tabela[i].Chave);
}

int main(int argc, char const *argv[])
{
  hashTable *obj;
  FILE *Entrada = fopen(argv[1], "r");
  FILE *fileSaida = fopen(argv[2], "w");

  int Testes, Linhas;
  char *flag = (char *)calloc(sizeof(char), 15);

  fscanf(Entrada, "%d", &Testes);
  printf(">> %d\n", Testes);
  for (int k = 0; k < Testes; k++)
  {
    obj = criaTabela(TAMANHO_HT);
    fscanf(Entrada, "%d", &Linhas);
    for (int l = 0; l < Linhas; l++)
    {
      fscanf(Entrada, "%s", flag);
      if (flag[0] == 'A')
      {
        Inserir(obj, &(flag[4]));
      }
      else
      {
        Remover(obj, &(flag[4]));
      }
    }
    Listar(fileSaida, obj, TAMANHO_HT);
  }

  fclose(fileSaida);
  fclose(Entrada);
  free(obj);

  return 0;
}
