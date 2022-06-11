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

void adicionarCandidato()
{
    printf("\nA Fazer - Candidato");
}

void votar()
{
    printf("\nA Fazer - votar");
}

void relatorio()
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
        adicionarCandidato();
        menu(p);
        break;

    case 2:
        votar();
        menu(p);
        break;

    default:
        relatorio();
        break;
    }
}

int main()
{
    celulaCandidato *p = malloc(sizeof(celulaCandidato *));
    menu(p);

    return 0;
}
