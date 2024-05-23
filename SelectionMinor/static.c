#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MenorReturned(int *Vetor, const int Tamanho, int *Posix)
{
  int Index, Position = 0;

  for (Index = 1; Index < Tamanho; Index++)
  {
    if (Vetor[Position] > Vetor[Index])
    {
      Position = Index;
    }
  }
  *Posix = Position;
  return Vetor[Position];
}

void Order_BasedMinNumber(int *Vetor, int *Novo, int Tamanho)
{

  int Index, Posix, Secund, ChangeSize = Tamanho;

  for (Index = 0; Index < Tamanho; Index++)
  {
    Novo[Index] = MenorReturned(Vetor, ChangeSize, &Posix); // Vetor vazio recebendo o menor elemento da função por retorno.
    for (Secund = Posix; Secund < ChangeSize - 1; Secund++)
    {
      Vetor[Secund] = Vetor[Secund + 1];
    }
    ChangeSize -= 1;
  }
}

void Mostra(int Tamanho, int *vet)
{
  if (Tamanho != 0)
  {
    Mostra(Tamanho - 1, vet);
    printf(" %d", vet[Tamanho - 1]);
  }
}

int main(void)
{

  int vet[] = {9, 0, 1, 3, 4, 6, 2, 7, 5, 8};

  int Tamanho = 10;
  int novo[Tamanho];

  Order_BasedMinNumber(vet, novo, Tamanho);
  Mostra(Tamanho, novo);
  puts(" ");
  return 0;
}
