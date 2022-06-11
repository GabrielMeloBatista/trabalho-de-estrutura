#include <stdio.h>
#include <stdlib.h>

struct estruturaCandidato
{
    int numeroCandidato;
    char nomeCandidato[20];
    int numeroVotos;
    struct estrutura *prox;
};

typedef struct estrutura celulaCandidato;

void adicionarCandidato(celulaCandidato *p)
{
    printf("\nA Fazer - Candidato");
}

void votar(celulaCandidato *p)
{
    printf("\nA Fazer - votar");
}

void relatorio(celulaCandidato *p)
{
    printf("\nA Fazer - relatorio");
}

void menu(celulaCandidato *p)
{
    int seletor;
    printf("\n|| 1 - Adicionar Candidadtos || 2 - Votar || Outro - Sair e mostrar relatorio ||\n");
    scanf("%d", &seletor);
    switch (seletor)
    {
    case 1:
        adicionarCandidato(p);
        menu(p);
        break;

    case 2:
        votar(p);
        menu(p);
        break;

    default:
        relatorio(p);
        break;
    }
}

int main()
{
    celulaCandidato *p = malloc(sizeof(celulaCandidato *));
    menu(p);

    return 0;
}
