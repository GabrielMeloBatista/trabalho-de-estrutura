#include <stdio.h>
#include <stdlib.h>
#define tamanhoNome 20

struct estruturaCandidato
{
    int numeroCandidato;
    char nomeCandidato[tamanhoNome];
    int numeroVotos;
    struct estruturaCandidato *prox;
};

typedef struct estruturaCandidato celulaCandidato;

void adicionarCandidato(celulaCandidato *p)
{
    celulaCandidato *nova;
    int numeroCandidato;

    nova = malloc(sizeof(celulaCandidato));

    printf("\nNome do Candidato: ");
    getchar();
    gets(nova->nomeCandidato);

    printf("Numero do Candidato: ");
    scanf("%d", &numeroCandidato);

    // Logica de inserção
    nova->numeroCandidato = numeroCandidato;
    nova->numeroVotos = 0;
    nova->prox = p->prox;
    p->prox = nova;
}

void alterarCandidato(celulaCandidato *p)
{
    // int numeroCandidato;

    // printf("\nNome do Candidato: ");
    // getchar();
    // gets(p->nomeCandidato);

    // printf("Numero do Candidato: ");
    // scanf("%d", &numeroCandidato);

    // // Logica de inserção
    // p->numeroCandidato = numeroCandidato;
    printf("Fazer alterarCandidato");
}

void removerCandidato(int y, celulaCandidato *le)
{
    celulaCandidato *p, *q;
    p = le;
    q = le->prox;
    while (q != NULL && q->numeroCandidato != y)
    {
        p = q;
        q = q->prox;
    }
    if (q != NULL)
    {
        p->prox = q->prox;
        free(q);
    }
}

void menuRemoverPresidente(celulaCandidato *p)
{
    int seletor;
    printf("numero do candidato a ser removido: ");
    scanf("%d", &seletor);

    removerCandidato(seletor, p);
}

void crudPresidente(celulaCandidato *p)
{
    int seletor;
    printf("\n|| 1 - inserir || 2 - alterar || 3 - excluir || Outro - Menu anterior ||\n");
    scanf("%d", &seletor);
    switch (seletor)
    {
    case 1:
        adicionarCandidato(p);
        crudPresidente(p);
        break;

    case 2:
        alterarCandidato(p);
        crudPresidente(p);
        break;

    case 3:
        menuRemoverPresidente(p);
        crudPresidente(p);
        break;

    default:
        break;
    }
}

void menuCandidato(celulaCandidato *p)
{
    int seletor;
    printf("\n|| 1 - Presidente || 2 - Governador || 3 - Senador || Outro - Menu anterior ||\n");
    scanf("%d", &seletor);
    switch (seletor)
    {
    case 1:
        crudPresidente(p);
        menuCandidato(p);
        break;

    default:
        break;
    }
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
    printf("\n|| 1 - Adicionar Candidatos || 2 - Votar || Outro - Sair e mostrar relatorio ||\n");
    scanf("%d", &seletor);
    switch (seletor)
    {
    case 1:
        menuCandidato(p);
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
    celulaCandidato *p = malloc(sizeof(celulaCandidato));
    p->prox = NULL;

    menu(p);
    return 0;
}
