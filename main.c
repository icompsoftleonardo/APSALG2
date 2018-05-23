#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<mysql.h>
#include<winsock2.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
//constantes para efetuar login ao DB, utilizado o MYSQL do Xampp
#define servidor "127.0.0.1"
#define usuario "host" //por padrão o MYSQL vem com usuário Host
#define senha "" //por padrão a senha vem vazia
#define bd "APSALG2" //nome da base de dados
//cabe�alhos
void Menu();
void Salvar();
void Cadastro_Cliente();
void Limpar_Tela();
void Orcamento();
void Imprimir();
    //var globais
    char i_Nome[30];
    char i_CPF[11];
    char i_Cidade[30];
    char i_Veiculo[20];
    char i_DataNasc[8];
    char i_Telefone[20];
    //SQL PRA CRIAÇÃO DA TABELA
    // CREATE TABLE `APSALG2`.`Clientes` CRIANDO TABELA CLIENTES
    // ( `i_Nome` VARCHAR(255) NOT NULL, DECLARANDO A COLUNA "I_NOME" DO TIPO VARCHAR 255 CARACTERES NÃO NULO
    // `i_CPF` VARCHAR(255) NOT NULL, DECLARANDO A COLUNA "I_CPF" DO TIPO VARCHAR 255 CARACTERES NÃO NULO
    // `i_Cidade` VARCHAR(255) NOT NULL , DECLARANDO A COLUNA "I_CIDADE" DO TIPO VARCHAR 255 CARACTERES NÃO NULO
    // `i_Veiculo` VARCHAR(255) NOT NULL , DECLARANDO A COLUNA "I_VEICULO" DO TIPO VARCHAR 255 CARACTERES NÃO NULO
    // `i_DataNasc` VARCHAR(255) NOT NULL , DECLARANDO A COLUNA "I_DATANASC" DO TIPO VARCHAR 255 CARACTERES NÃO NULO
    // `i_Telefone` VARCHAR(255) NOT NULL ); DECLARANDO A COLUNA "I_TELEFONE" DO TIPO VARCHAR 255 CARACTERES NÃO NULO

int main (void){
    //execu�ao




    Menu();
    return 0;
}


void Salvar()//salvar cadastros realizados, colocado aqui pra deixar pré carregando quando for chamado
{
    char *Nome;
    char *CPF;
    char *Cidade;
    char *Veiculo;
    char *DataNasc;
    char *Telefone;

    Nome = &i_Nome;
    CPF = &i_CPF;
    Cidade = &i_Cidade;
    Veiculo = &i_Veiculo;
    DataNasc = &i_DataNasc;
    Telefone = &i_Telefone;

    MYSQL conexao;
    char query[200];

    mysql_init(&conexao);
    if(mysql_real_connect(&conexao, "127.0.0.1", "root", "", "APSALG2", 0, NULL, 0)){
        printf("Conectado com sucesso!\n");
        //printf("INSERT INTO Clientes(i_Nome, i_CPF, i_Cidade, i_Veiculo, i_DataNasc, i_Telefone) values(%s, %s, %s, %s, %s, %s);", Nome, CPF, Cidade, Veiculo, DataNasc, Telefone);
        sprintf(query,"INSERT INTO clientes(i_Nome, i_CPF, i_Cidade, i_Veiculo, i_DataNasc, i_Telefone) values('%s', '%s', '%s', '%s', '%s', '%s');", Nome, CPF, Cidade, Veiculo, DataNasc, Telefone);

       if (!mysql_query(&conexao, query)){
            printf("Registros inseridos %d", mysql_affected_rows(&conexao));
        }
        else{
            printf("Erro na insercao %d : %s", mysql_errno(&conexao), mysql_error(&conexao));
            mysql_close(&conexao);
        }
    }
    else{
        printf("Falha de conexao");
        printf("Erro %d : %sn", mysql_errno(&conexao), mysql_error(&conexao));
    }
}

void opcao()//op�ao para realizar um novo cadastro ou voltar ao menu inicial
{
    int l_op;
    printf("Selecione a op��o desejada:\n1-Realizar novo Cadastro:\n2-Voltar ao menu principal:\n");
        scanf("%d",&l_op);
        switch(l_op)
        {
        case 1:
            Limpar_Tela();
            Cadastro_Cliente();

        case 2:
            Limpar_Tela();
            Menu();
    }
}

void Limpar_Tela()//limpar a tela a cada execu��o
{
    system("cls");
}

void Cadastro_Cliente()//cadastrar um cliente
{
    printf("Nome:\n");
    scanf(" %s", i_Nome);
    printf("CPF:\n");
    scanf(" %s", i_CPF);
    printf("Cidade:\n");
    scanf(" %[^\n]s", i_Cidade);
    printf("Veiculo:\n");
    scanf(" %s", i_Veiculo);
    printf("Data de Nascimento:\n");
    scanf(" %s", i_DataNasc);
    printf("Telefone:\n");
    scanf(" %s", i_Telefone);

    printf("Deseja salvar este cadastro?\n S / N:\n");
    char l_Salvar,l_opcao;
    scanf(" %c",&l_Salvar);
    if(l_Salvar=='S'||l_Salvar=='s')
        Salvar();
    else
    {
        Limpar_Tela();

        opcao();
    }
}
void Orcamento()//imprimir or�amentos
{
    printf("Nome Cliente:\n");
    scanf(" %s",i_Nome);
    printf("Veiculo:\n");
    scanf(" %s",i_Veiculo);
    printf("Informe quantidade de pe�as:\n");
    int i,peca;
    double valor=0,v, mao_de_obra;
    scanf("%d",&peca);
    for(i=1;i<=peca;i++)
    {
        printf("Pe�a %d valor R$:\n",i);
        scanf("%lf",&v);
        valor+=v;
        printf("...............................................\n");
    }
    printf("Valor M�o de obra R$:\n");
    scanf("%lf",&mao_de_obra);

    valor+= mao_de_obra;
    printf("Total................................. R$%.2lf\n",valor);
    printf("Deseja imprimir o or�amento? S/N\n");
    char op;
    scanf(" %c",&op);
    if(op=='s'||op=='S')
        Imprimir();
    else
    {
        Limpar_Tela();
        Menu();
    }
}
void Imprimir()//iprimir o or�amento
{

}
void Mostrar_Cadastros()//mostrar todos os clientes cadastrados
{

}
void Apagar_Cadastros()//apagar todos os cadastros
{

}

void Menu()//menu principal
{
    int escolha;
    printf("Escolha uma op��o desejada;\n");
    printf("1- Cadastro Cliente:\n");
    printf("2- Mostrar todos os cadastros:\n");
    printf("3- Apagar todos os cadastros;\n");
    printf("4- Fazer or�amento:\n");
    printf("5- Sair:\n");
    scanf("%d",&escolha);

    Limpar_Tela();

    switch (escolha)
    {
    case (1):
        Cadastro_Cliente();
    case (2):
        Mostrar_Cadastros();
    case (3):
        Apagar_Cadastros();
    case (4):
        Orcamento();
    case (5):
        break;

        /* printf("Favor selecionar uma op��o:")
         Menu();*/
    }
}


