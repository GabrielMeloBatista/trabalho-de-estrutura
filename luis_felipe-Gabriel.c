#include <stdio.h>
#include <stdlib.h>
#define TAM 25

struct reg
{
    char nome[TAM];
    int numero, voto;
    struct reg *prox;
};
typedef struct reg celula;

void imprime(celula *le)
{
    le = le->prox;
    if (le != NULL)
    {
        printf("\nNome: %s\n", le->nome);
        printf("Numero: %d\n", le->numero);
        imprime(le);
    }
}

celula *busca(int x, celula *le)
{
    celula *p;
    p = le;
    while (p != NULL && p->numero != x)
    {
        p = p->prox;
    }
    return p;
}

void inserirCandidato(celula *p)
{
    int numero;
    celula *nova;
    nova = malloc(sizeof(celula));
    printf("\nNome: ");
    getchar();
    gets(nova->nome);
    printf("Numero: ");
    scanf("%d", &numero);
    nova->numero = numero;
    nova->voto = 0;
    nova->prox = p->prox;
    p->prox = nova;
}

void alterarCandidato(int y, celula *le)
{
    int numero;
    celula *p, *q, *nova;
    nova = malloc(sizeof(celula));
    printf("\nNome: ");
    getchar();
    gets(nova->nome);
    printf("Numero: ");
    scanf("%d", &numero);
    nova->numero = numero;
    nova->voto = 0;
    p = le;
    q = le->prox;
    while (q != NULL && q->numero != y)
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

void selecionarAlterar(celula *p)
{
    int seletor;
    printf("numero: ");
    scanf("%d", &seletor);
    alterarCandidato(seletor, p);
}

void removerCandidato(int y, celula *le)
{
    celula *p, *q;
    p = le;
    q = le->prox;
    while (q != NULL && q->numero != y)
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

void selecionarRemover(celula *p)
{
    int seletor;
    printf("numero: ");
    scanf("%d", &seletor);
    removerCandidato(seletor, p);
}

void crudCandidato(celula *p)
{
    int seletor;
    printf("\n1 - inserir, 2 - alterar, 3 - excluir, 0 - selecionar anterior\n");
    scanf("%d", &seletor);
    switch (seletor)
    {
    case 0:
        break;
    case 1:
        inserirCandidato(p);
        crudCandidato(p);
        break;
    case 2:
        selecionarAlterar(p);
        crudCandidato(p);
        break;
    case 3:
        selecionarRemover(p);
        crudCandidato(p);
        break;
    }
}

void selecionarCandidato(celula *presidente, celula *governador, celula *senador)
{
    int seletor;
    printf("\n1 - Presidente, 2 - Governador, 3 - Senador, 0 - selecionar anterior\n");
    scanf("%d", &seletor);
    switch (seletor)
    {
    case 0:
        break;
    case 1:
        crudCandidato(presidente);
        selecionarCandidato(presidente, governador, senador);
        break;
    case 2:
        crudCandidato(governador);
        selecionarCandidato(presidente, governador, senador);
        break;
    case 3:
        crudCandidato(senador);
        selecionarCandidato(presidente, governador, senador);
        break;
    }
}

void votarCandidato(celula *le) // Utilizar um if para verificar se tem um candidato
{
    celula *p, *q, *lista;
    int voto;
    lista = le;
    imprime(lista);
    printf("Digite aqui seu voto: ");
    scanf("%d", &voto);
    p = busca(voto, le);
    q = le->prox;
    if (voto == p->numero)
    {
        printf("Seu voto foi para %s\n", p->nome);
        p->voto++;
    }
}

void votar(celula *presidente, celula *governador, celula *senador)
{
    votarCandidato(presidente);
    votarCandidato(governador);
    votarCandidato(senador);
}

void mostrarRelatorio(celula *le, int totalVotos)
{
    float porcentagem;
    le = le->prox;
    if (le != NULL)
    {
        porcentagem = (le->voto * 100) / totalVotos;
        printf("\nNome Candidato: %s", le->nome);
        printf("\nNumero Candidato: %d", le->numero);
        printf("\nPorcentagem de votos: %.2f %c\n", porcentagem, 37);
    }
    if (le->prox != NULL)
    {
        mostrarRelatorio(le, totalVotos);
    }
}

int contarVotos(celula *le)
{
    le = le->prox;
    int totalVotos = 0;
    for (celula *p = le; p != NULL; p = p->prox)
    {
        totalVotos += p->voto;
    }
    return totalVotos;
}

void relatorioGeral(celula *le)
{
    celula *p, *q;
    p = le, q = le;
    
    int totalVotos = contarVotos(p);
    if (totalVotos <= 0)
    {
        printf("Nao a votos");
    }
    else
    {
        printf("Total de votos: %d", totalVotos);
    }
    mostrarRelatorio(q, totalVotos);
}

void relatorio(celula *presidente, celula *governador, celula *senador)
{
    printf("\nSenador\n");
    relatorioGeral(senador);
    printf("\nGovernador\n");
    relatorioGeral(governador);
    printf("\nPresidente\n");
    relatorioGeral(presidente);
}

void selecionar(celula *presidente, celula *governador, celula *senador)
{
    int seletor;
    printf("\n1 - Adicionar Candidatos, 2 - Votar nos candidatos, 0 - Sair e mostrar relatorio\n");
    scanf("%d", &seletor);
    switch (seletor)
    {
    case 0:
        relatorio(presidente, governador, senador);
        break;
    case 1:
        selecionarCandidato(presidente, governador, senador);
        selecionar(presidente, governador, senador);
        break;

    case 2:
        votar(presidente, governador, senador);
        selecionar(presidente, governador, senador);
        break;
    }
}

int main()
{
    celula *senador = malloc(sizeof(celula));
    celula *governador = malloc(sizeof(celula));
    celula *presidente = malloc(sizeof(celula));
    presidente->prox = NULL;
    governador->prox = NULL;
    senador->prox = NULL;
    selecionar(presidente, governador, senador);
    return 0;
}
