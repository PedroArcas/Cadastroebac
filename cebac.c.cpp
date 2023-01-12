#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	
	// In�cio da cria��o de vari�veis (string)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o de vari�veis (string)
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); // %s (percentual de uma string)
	
	strcpy(arquivo,cpf); // respons�vel por copiar os valores das strings
	
	FILE *file; // cria o arquivo no banco de dados (pc)
	file = fopen(arquivo, "w"); // cria o arquivo e o W significa write (escrever)
	fprintf(file,cpf); // salva o valor da vari�vel
	fclose(file); // fecha o arquivo
	
	file = fopen (arquivo, "a"); // abre o arquivo, aonde "a" atualizara o arquivo que foi criado (w)
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
		
	
}

int consulta()
{
	
	setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // Ir� Ler ( r , isto � read) a informa��o cpf
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n");
		
		
	}
	
	while(fgets(conteudo, 200, file) != NULL) // !=NULLL, significa parar quando for nulo.
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{

	char cpf [40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usu�rio n�o se encontra no sistema!.\n");
		system("pause");
		
	}
	
}




int main()
{
	int opcao=0; // Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system ("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definindo linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); // in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - Sair do Sistema\n\n");
		printf("Op��o: "); // fim do menu
	
		scanf("%d", &opcao); // armazenamento a escolha do usu�rio
	
		system("cls"); // limpa a tela para uma nova, visa boa apresenta��o para o usu�rio
		
		
	switch(opcao) // in�cio da sele��o do menu
	{
		case 1:
		registro(); // chamada de fun��es
		break;
		
		case 2:
		consulta();
		break;
			
		case 3:
		deletar();
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");	
		return 0;
		break;	
			
		default:
		printf("Essa op��o n�o est� dispon�vel\n");
		system("pause");
		break;
		
		}
	
	}	
}
