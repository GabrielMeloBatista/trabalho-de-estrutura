#include <stdio.h>
#include <stdlib.h>

struct estruturaCandidato
{
    int numeroCandidato;
    char nomeCandidato[20];
    int numeroVotos;
    struct estruturaCandidato *prox;
};

typedef struct estrutura celulaCandidato;

void adicionarCandidato(celulaCandidato *p)
{
    printf("\nA Fazer - Candidato");
}

void votar(celulaCandidato *p) // Utilizar um if para verificar se tem um candidato
{
    printf("\nA Fazer - votar");
}

void relatorio(celulaCandidato *le)
{
    celulaCandidato *p;
    int votosTotais = 0;
    for (p = le->prox; p != NULL; p = p->prox)
    {
        votosTotais += p->numeroVotos;

        printf("\nNome Candidato: %s", p->nomeCandidato);
        printf("\nNumero Candidato: %d", p->numeroCandidato);
        printf("\nNumero de votos: %d\n", p->numeroVotos);
    }
    printf("\n\nTotal de votos: %d", votosTotais);
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
