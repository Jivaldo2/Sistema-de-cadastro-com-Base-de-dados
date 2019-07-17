/*
    programador: Jivaldo Da Cruz
    feito: 16/07/2019
    titulo: Cadastro com db
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Variável global
char nome[50][100];
char senha [50][100];
static int contador = 0;

int main(void);//Protótipo de função principal
void cadastro(void);//Protótipo de função cadastrar usuários
void login(void);//Protótipo de função logar
void listar(void);//Protótipo de função listar cadastro
void pesquisar(void);//Protótipo de função pesquisar

//Função principal
int main(void){
    system("cls || clear");
    printf("###############################################\n");
    printf("\t\tSistema De Cadastro\n");
    printf("###############################################\n\n");
    auto int valor;

    printf("1. Cadastrar\t");
    printf("2. Logar\t");
    printf("3. Listar\t");
    printf("4. Pesquisar\t");
    printf("5. Sair\n");
    printf("Insira um valor: ");
    scanf("%d",&valor);

    switch(valor){
        case 1:
            system("cls || clear");
            cadastro();
        break;
        case 2:
            system("cls || clear");
            login();
        break;
        case 3:
            system("cls || clear");
            listar();
        break;
        case 4:
            system("cls || clear");
            pesquisar();
        break;
        case 5:
            system("cls || clear");
            system("exit");
        break;
        default:
            system("cls || clear");
            main();
        break;
    }

return 0;
}

//Função cadastro
void cadastro(void){
    printf("###############################################\n");
    printf("\t\tCadastrar pessoas\n");
    printf("###############################################\n\n");

    FILE *arquivo;//Para endicar que vamos criar um arquivo
    arquivo = fopen("lista.txt", "ab+");

    auto int opcao = 1;

    while(opcao == 1){
        printf("Insira seu nome: ");
        scanf("%s",nome[contador]);
        fprintf(arquivo,"%s\n",nome[contador]);
        printf("Insira sua senha: ");
        scanf("%s",senha[contador]);
        fprintf(arquivo,"%s\n",senha[contador]);
        printf("[-1 para sair 1 para continuar]: ");
        scanf("%d",&opcao);
        contador++;
    }
    //Fechar o arquivo
    fclose(arquivo);
    main();
}

//Função login
void login(void){

    auto int a = 0, c = 0;
    auto char nomeLogar[30], senhaLogar[30];

    FILE *arquivoLogar;
    arquivoLogar = fopen("lista.txt", "r");

    printf("Insira seu nome: ");
    scanf("%s",nomeLogar);
    printf("Insira sua senha: ");
    scanf("%s",senhaLogar);

    while( !feof(arquivoLogar) ){
        fscanf(arquivoLogar,"%s",nome[a]);
        fscanf(arquivoLogar,"%s",senha[a]);
        if(strcmp(nome[a],nomeLogar) == 0 && strcmp(senha[a],senhaLogar) == 0){
            printf("Logado com sucesso!\n");;
        }
        a++;
    }
    fclose(arquivoLogar);
    getchar();
    getchar();
    main();
}

//Função para mostrar lista completa
void listar(void){
    printf("###############################################\n");
    printf("\t\tLista de pessoas\n");
    printf("###############################################\n\n");

    FILE *arquivo;//Para endicar que vamos criar um arquivo
    arquivo = fopen("lista.txt", "r");
    int aCont = 0;

    while( !feof(arquivo) ){
        fgets(nome[aCont], 255, (FILE*)arquivo);
        fgets(senha[aCont], 255, (FILE*)arquivo);
        aCont++;
    }
    aCont -= 1;
    auto int a = 0;
    while( a != aCont ){
        fgets(nome[a], 255, (FILE*)arquivo);
        printf("%d -> Nome: %s\n", (a+1),nome[a]);
        fgets(senha[a], 255, (FILE*)arquivo);
        printf("%d -> Senha: %s\n", (a+1),senha[a]);
        printf("---------------------------------\n");
        a++;
    }
    //Fechar o arquivo
    fclose(arquivo);

    getchar();
    getchar();
    main();
}

//Função para pesquisar
void pesquisar(void){
    auto char nomePesq[30];
    auto int a = 0;

    FILE *arquivoPesquisa;
    arquivoPesquisa = fopen("lista.txt", "r");

    printf("Insira seu nome: ");
    scanf("%s",nomePesq);

    while( !feof(arquivoPesquisa) ){
        fscanf(arquivoPesquisa, "%s", nome[a]);
        if(strcmp(nome[a],nomePesq) == 0){
            fgets(nome[a], 255, (FILE*)arquivoPesquisa);
            printf("%d -> Nome: %s\n", (a+1), nomePesq);
            fgets(senha[a], 255, (FILE*)arquivoPesquisa);
            printf("%d -> Senha: %s\n", (a+1), senha[a]);
            printf("------------------------------------\n");
        }
        a++;
    }
    //Fechar o arquivo
    fclose(arquivoPesquisa);

    getchar();
    getchar();
    main();
}
