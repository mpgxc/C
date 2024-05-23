#include <stdio.h>
#include <stdlib.h>

typedef struct Elem
{
  int Info;
  struct Elem *Proximo;
} Elemento;

typedef struct
{
  Elemento *Inicio, *Final;
  int Tamanho;
} Lista;

Lista *Initialize()
{
  Lista *Temp = (Lista *)malloc(sizeof(Lista));
  Temp->Inicio = Temp->Final = NULL;
  Temp->Tamanho = 0;
  return Temp;
}

void Insere(Lista *MyList, const int Valor)
{

  Elemento *Temp = (Elemento *)malloc(sizeof(Elemento));

  Temp->Info = Valor;
  Temp->Proximo = NULL;

  if (MyList->Final == NULL)
  {
    MyList->Inicio = Temp;
  }
  else
  {
    MyList->Final->Proximo = Temp;
  }
  MyList->Tamanho++;
  MyList->Final = Temp;
}

void Remove(Lista *MyList, const int Valor)
{

  Elemento *Anterior, *Node = MyList->Inicio;

  while (Node != NULL && Node->Info != Valor)
  {
    Anterior = Node;
    Node = Node->Proximo;
  }
  if (Node == MyList->Inicio)
  {
    MyList->Inicio = Node->Proximo;
  }
  else
  {
    Anterior->Proximo = Node->Proximo;
  }

  MyList->Tamanho--;

  free(Node);
}

Elemento *ReturnMenor(Elemento *Dados)
{

  Elemento *Temp = Dados, *Menor = Dados;

  for (; Temp != NULL; Temp = Temp->Proximo)
  {
    if (Menor->Info > Temp->Info)
    {
      Menor = Temp;
    }
  }
  return Menor;
}

Lista *Order(Lista *Dados)
{

  Lista *Novo = Initialize();

  for (int Index = 0; Index < Dados->Tamanho; Index++)
  {
    Elemento *Menor = ReturnMenor(Dados->Inicio);
    Insere(Novo, Menor->Info);
    Remove(Dados, Menor->Info);
  }
  return Novo;
}

void Mostrar(Elemento *Dados)
{

  if (Dados != NULL)
  {
    printf("%d, ", Dados->Info);
    Mostrar(Dados->Proximo);
  }
}

int main(void)
{

  Lista *Atual = Initialize();

  Insere(Atual, 5);
  Insere(Atual, 9);
  Insere(Atual, 4);
  Insere(Atual, 6);
  Insere(Atual, 0);
  Insere(Atual, 8);
  Insere(Atual, 1);
  Insere(Atual, 3);
  Insere(Atual, 2);
  Insere(Atual, 7);

  Lista *Novo = Order(Atual);

  Mostrar(Novo->Inicio);

  free(Atual);

  return 0;
}
