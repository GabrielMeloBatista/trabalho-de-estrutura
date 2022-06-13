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

void alterarCandidato(int y, celulaCandidato *le)
{
    int numeroCandidato;
    celulaCandidato *p, *q, *nova;
    nova = malloc(sizeof(celulaCandidato));
    /* Logica dados novos aqui */

    printf("\nNome do Candidato: ");
    getchar();
    gets(nova->nomeCandidato);

    printf("Numero do Candidato: ");
    scanf("%d", &numeroCandidato);

    nova->numeroCandidato = numeroCandidato;
    nova->numeroVotos = 0;

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
    nova->prox = q;
    p->prox = nova;
}

void menuAlterarCandidato(celulaCandidato *p)
{
    int seletor;
    printf("numero do candidato a ser alterado: ");
    scanf("%d", &seletor);

    alterarCandidato(seletor, p);
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

void crudCandidato(celulaCandidato *p)
{
    int seletor;
    printf("\n|| 1 - inserir || 2 - alterar || 3 - excluir || Outro - Menu anterior ||\n");
    scanf("%d", &seletor);
    switch (seletor)
    {
    case 1:
        adicionarCandidato(p);
        crudCandidato(p);
        break;

    case 2:
        menuAlterarCandidato(p);
        crudCandidato(p);
        break;

    case 3:
        menuRemoverPresidente(p);
        crudCandidato(p);
        break;

    default:
        break;
    }
}

void menuCandidato(celulaCandidato *presidente, celulaCandidato *governador, celulaCandidato *senador)
{
    int seletor;
    printf("\n|| 1 - Presidente || 2 - Governador || 3 - Senador || Outro - Menu anterior ||\n");
    scanf("%d", &seletor);
    switch (seletor)
    {
    case 1:
        crudCandidato(presidente);
        menuCandidato(presidente, governador, senador);
        break;
    case 2:
        crudCandidato(governador);
        menuCandidato(presidente, governador, senador);
        break;
    case 3:
        crudCandidato(senador);
        menuCandidato(presidente, governador, senador);
        break;

    default:
        break;
    }
}

void votar(celulaCandidato *p) // Utilizar um if para verificar se tem um candidato
{
    printf("\nA Fazer - votar");
}

void relatorioGeral(celulaCandidato *le)
{
    celulaCandidato *p;
    int votosTotais = 0;
    for (p = le->prox; p != NULL; p = p->prox)
    {
        votosTotais += p->numeroVotos;
    }

    if (votosTotais >= 0)
    {
        printf("\n\nTotal de votos: %d", votosTotais);
        for (p = le->prox; p != NULL; p = p->prox)
        {
            printf("\nNome Candidato: %s", p->nomeCandidato);
            printf("\nNumero Candidato: %d", p->numeroCandidato);
            printf("\nPorcentagem de votos: %.2f %c\n", (p->numeroVotos / votosTotais) * 100, 37);
        }
    }
}

void relatorio(celulaCandidato *presidente, celulaCandidato *governador, celulaCandidato *senador)
{
    relatorioGeral(presidente);
    relatorioGeral(governador);
    relatorioGeral(senador);
}

void menu(celulaCandidato *presidente, celulaCandidato *governador, celulaCandidato *senador)
{
    int seletor;
    printf("\n|| 1 - Gerenciar Candidatos || 2 - Votar nos candidatos || Outro - Sair e mostrar relatorio ||\n");
    scanf("%d", &seletor);
    switch (seletor)
    {
    case 1:
        menuCandidato(presidente, governador, senador);
        menu(presidente, governador, senador);
        break;

    case 2:
        votar(presidente);
        menu(presidente, governador, senador);
        break;

    default:
        relatorio(presidente, governador, senador);
        break;
    }
}

int main()
{
    celulaCandidato *presidente = malloc(sizeof(celulaCandidato));
    celulaCandidato *governador = malloc(sizeof(celulaCandidato));
    celulaCandidato *senador = malloc(sizeof(celulaCandidato));
    presidente->prox = NULL;
    governador->prox = NULL;
    senador->prox = NULL;

    menu(presidente, governador, senador);
    return 0;
}
