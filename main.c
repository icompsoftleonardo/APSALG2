#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
//cabeçalhos
void Menu();
void Salvar();
void Cadastro_Cliente();
void Limpar_Tela();
void Orcamento();
void Imprimir();


void opcao()//opçao para realizar um novo cadastro ou voltar ao menu inicial
{
    int l_op;
    printf("Selecione a opção desejada:\n1-Realizar novo Cadastro:\n2-Voltar ao menu principal:\n");
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
//variaveis usadas varias vzs no programa
char i_nome[30];
char i_CPF[11];
char i_Cidade[30];
char i_Veiculo[20];
char i_DataNasc[8];
char i_Telefone[20];

void Limpar_Tela()//limpar a tela a cada execução
{
    system("cls");
}

void Cadastro_Cliente()//cadastrar um cliente
{
    printf("Nome:\n");
    scanf(" %s",i_nome);
    printf("CPF:\n");
    scanf(" %s",i_CPF);
    printf("Cidade:\n");
    scanf(" %s",i_Cidade);
    printf("Veiculo:\n");
    scanf(" %s",i_Veiculo);
    printf("Data de Nascimento:\n");
    scanf(" %s",i_DataNasc);
    printf("Telefone:\n");
    scanf(" %s",i_Telefone);

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
void Orcamento()//imprimir orçamentos
{
    printf("Nome Cliente:\n");
    scanf(" %s",i_nome);
    printf("Veiculo:\n");
    scanf(" %s",i_Veiculo);
    printf("Informe quantidade de peças:\n");
    int i,peca;
    double valor=0,v, mao_de_obra;
    scanf("%d",&peca);
    for(i=1;i<=peca;i++)
    {
        printf("Peça %d valor R$:\n",i);
        scanf("%lf",&v);
        valor+=v;
        printf("...............................................\n");
    }
    printf("Valor Mão de obra R$:\n");
    scanf("%lf",&mao_de_obra);

    valor+= mao_de_obra;
    printf("Total................................. R$%.2lf\n",valor);
    printf("Deseja imprimir o orçamento? S/N\n");
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
void Imprimir()//iprimir o orçamento
{

}
void Mostrar_Cadastros()//mostrar todos os clientes cadastrados
{

}
void Apagar_Cadastros()//apagar todos os cadastros
{

}
void Salvar()//salvar cadastros realizados
{

}

void Menu()//menu principal
{
    int escolha;
    printf("Escolha uma opção desejada;\n");
    printf("1- Cadastro Cliente:\n");
    printf("2- Mostrar todos os cadastros:\n");
    printf("3- Apagar todos os cadastros;\n");
    printf("4- Fazer orçamento:\n");
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

        /* printf("Favor selecionar uma opção:")
         Menu();*/
    }
}

int main()//execuçao
{
    Menu();
    return 0;
}
