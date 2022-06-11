#include <stdio.h>
#include <stdlib.h>

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

void menu()
{
    int seletor;
    printf("\n|| 1 - Adicionar Candidadtos || 2 - Votar || Outro - Sair e mostrar relatorio ||\n");
    scanf("%d", &seletor);
    switch (seletor)
    {
    case 1:
        adicionarCandidato();
        menu();
        break;

    case 2:
        votar();
        menu();
        break;

    default:
        relatorio();
        break;
    }
}

int main()
{
    menu();

    return 0;
}
