#include <stdio.h> // Biblioteca de comunicação om o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca

int Registrar()
{
    char arquivo [40];
    char CPF [40];
    char Nome [40];
    char Sobrenome [40];
    char Cargo [40];

    printf("Digite o CPF a ser cadastrado");
    scanf("%s", CPF);

    strcpy (arquivo, CPF); // Responsável por copiar valores nas string

    FILE *file; // Cria o arquivo
    file = fopen (arquivo, "w"); // Cria o arquivo

    fprintf(file, CPF); // Salvar o valor da variável
    fclose(file); //Fecha o arquivo

    file = fopen (arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o nome a ser cadastrado");
    scanf("%s", Nome);
    file = fopen (arquivo,"a");
    fprintf(file, Nome);
    fclose(file);
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", Sobrenome);
    file = fopen(arquivo, "a");
    fprintf(file, Sobrenome);
    fclose(file);
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", Cargo);
    file = fopen(arquivo, "a");
    fprintf(file, Cargo);
    fclose(file);
        
    system ("pause");

}


int Consultar()
{

    setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem

    char CPF[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado");
    scanf("%s", CPF);

    FILE *file;
    file = fopen(CPF, "r");

    if (file == NULL)
    {
        printf("Não foi possível abrir o arquivo");
    }

    while (fgets(conteudo, 100, file) != NULL)

    {
        printf("\nEssas são as informações do usuário");
        printf("%s" , conteudo);
        printf("\n\n");
    }

    system("pause");
    
}


int Excluir()
{   
    char CPF[40];

    printf("Digite o CPF a ser excluido\n");
    scanf("%s",CPF);

    remove(CPF);

    FILE *file;
    file = fopen (CPF, "r");

    if(file==NULL)
    {
        printf("Usuário não cadastrado.\n");
        system("pause");
    }
    
}

int main()
{    
    int opcao=0; // Definindo variáveis
    int laco=1;

    for(laco=1;laco=1;)
    {
        system("cls");
        

        setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
        printf("###Cartório da EBAC###\n\n");
        printf("Escolha uma opção do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Excluir nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Esse software é exclusivo para alunos\n");
        printf("opção: "); // Fim do menu

        scanf ("%d", &opcao); // Armazenando a escolha do usuário

        system ("cls");
        

        switch (opcao) //Inicio da seleção
        {
            case 1:
            Registrar();  
            break;

            case 2:
            Consultar();
            break;

            case 3:
            Excluir();
            break;

            case 4:
            printf("Obrigada por utilizar o sistema!\n");
            return 0;
            break;

            default:
            printf("Opção inválida!\n");
            system("pause");
            break;
        }   // Fim da seleção
    }

}
    


