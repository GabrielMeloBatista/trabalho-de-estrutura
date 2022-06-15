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

typedef struct estruturaCandidato celula;

void adicionarCandidato(celula *p)
{
    int numeroCandidato;
    celula *nova;

    nova = (celula*)malloc(sizeof(celula));

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

void alterarCandidato(int y, celula *le)
{
    int numeroCandidato;
    celula *p, *q, *nova;
    nova = (celula*)malloc(sizeof(celula));
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

void menuAlterarCandidato(celula *p)
{
    int seletor;
    printf("numero do candidato a ser alterado: ");
    scanf("%d", &seletor);

    alterarCandidato(seletor, p);
}

void removerCandidato(int y, celula *le)
{
    celula *p, *q;
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

void menuRemoverPresidente(celula *p)
{
    int seletor;
    printf("numero do candidato a ser removido: ");
    scanf("%d", &seletor);

    removerCandidato(seletor, p);
}

void crudCandidato(celula *p)
{
    int seletor;
    printf("\n|| 1 - inserir || 2 - alterar || 3 - excluir || 0 - Menu anterior ||\n");
    scanf("%d", &seletor);
    switch (seletor)
    {
    	
    case 0:
        break;	
    	
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
    	printf("Numero invalido!\n");
        break;
    }
}

void menuCandidato(celula *presidente, celula *governador, celula *senador)
{
    int seletor;
    printf("\n|| 1 - Presidente || 2 - Governador || 3 - Senador || 0 - Menu anterior ||\n");
    scanf("%d", &seletor);
    switch (seletor)
    {
    case 0:
    	break;
    	
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
    	printf("Numero invalido!");
    	 break;
	}
}

// Função para mostrar os candidatos.
void imprime(celula *le)
{
    le = le->prox;
    if (le != NULL)
    {
        printf("\nNome do Candidato: %s\n", le->nomeCandidato);
        printf("Numero do Candidato: %d\n", le->numeroCandidato);
        imprime(le);
    }
}

void votarCandidato(celula *le) // Utilizar um if para verificar se tem um candidato
{
    // Botão para sair da função
    celula *p, *q;
    int voto;
    imprime(le);

    printf("Digite aqui seu voto para Presidente\n");
    scanf("%d", &voto);

    p = le;
    q = le->prox;
    while (q != NULL)
    {

        if (voto == p->numeroCandidato)
        {
            printf("Seu voto foi para %s\n", p->nomeCandidato);
            p->numeroVotos++;
        }
        p = q;
        q = q->prox;
    }
}

void votar(celula *presidente, celula *governador, celula *senador)
{
    votarCandidato(presidente);
    votarCandidato(governador);
    votarCandidato(senador);
}

int contarVotos(celula *le)
{
    le = le->prox;
    if (le != NULL)
    {
        return le->numeroVotos + contarVotos(le);
    }
}

void relatorioGeral(celula *le)
{
    celula *p;
    double porcentagem;
    int votosTotais = contarVotos(le);
    if (votosTotais > 0)
    {
        printf("\n\nTotal de votos: %d", votosTotais);
    }
    for (p = le->prox; p != NULL; p = p->prox)
    {
        porcentagem = (p->numeroVotos * 100) / votosTotais;
        printf("\nNome Candidato: %s", p->nomeCandidato);
        printf("\nNumero Candidato: %d", p->numeroCandidato);
        // FIXME Concerte a porcentagem
        printf("\nPorcentagem de votos: %.2f %c\n", porcentagem, 37);
    }
}

void relatorio(celula *presidente, celula *governador, celula *senador)
{
    relatorioGeral(presidente);
    relatorioGeral(governador);
    relatorioGeral(senador);
}

void menu(celula *presidente, celula *governador, celula *senador)
{
    int seletor;
    printf("\n|| 1 - Adicionar Candidatos || 2 - Votar nos candidatos || 0 - Sair e mostrar relatorio ||\n");
    scanf("%d", &seletor);
    switch (seletor)
    {
    	case 0:
        break;
    case 1:
        menuCandidato(presidente, governador, senador);
        menu(presidente, governador, senador);
        break;

    case 2:
        votar(presidente, governador, senador);
        menu(presidente, governador, senador);
        break;

    default:
        relatorio(presidente, governador, senador);
        break;
    }
}

int main()
{
    celula *presidente = (celula*)malloc(sizeof(celula));
    celula *governador = (celula*)malloc(sizeof(celula));
    celula *senador = (celula*)malloc(sizeof(celula));
    presidente->prox = NULL;
    governador->prox = NULL;
    senador->prox = NULL;

    menu(presidente, governador, senador);
    return 0;
}
