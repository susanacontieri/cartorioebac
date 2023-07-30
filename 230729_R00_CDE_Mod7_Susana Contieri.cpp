#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel pelas strings

int registro()//Fun��o respons�vel por registrar os usu�rios no sistema
{
	
	setlocale(LC_ALL, "Portuguese"); 
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando as informa��es do usu�rio
	scanf("%s", cpf); //%s � referente a string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar os valores das strings
	
	FILE *file; // Cria o arquivo 
	file = fopen(arquivo, "w"); //Cria o arquivo - W de write
	fprintf(file, cpf); //Salva o valor da vair�vel
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //a para atualiza��o
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando as informa��es do usu�rio
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando as informa��es do usu�rio
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando as informa��es do usu�rio
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()//respons�vel por consultar os usu�rios que foram registrados na plataforma
{
	
	setlocale(LC_ALL, "Portuguese"); 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando as informa��es do usu�rio
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//r de read
	
	if(file == NULL)
	{
		printf("Arquivo n�o localizado!\n"); //retorno caso n�o encontre o CPF na plataforma
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
}

int deletar()
{
	
	setlocale(LC_ALL, "Portuguese"); 
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //registra as informa��es inseridas pelo usu�rio
	scanf("%s", &cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o foi encontrado no sistema.\n"); //retorno quando o usu�rio n�o foi encontrado no sistema 
		system("pause");
		fclose(file);
	}
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usu�rio deletado com sucesso!\n"); //retorno quando o usu�rio foi deletado com sucesso
		system("pause");
	}
	
}


int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		system("cls"); //respons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("*** Cart�rio da EBAC ***\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Finalizar sistema\n\n");//fim do menu
		printf("Op��o: ");

		scanf("%d", &opcao); //Armazenamento da escolha do usu�rio
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de fun��o
			break;
			
			case 2:
			consulta(); //chamada de fun��o
			break;
			
			case 3:
			deletar(); //chamada de fun��o
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause");
			break;
		} // fim da sele��o
	
	
	}
}
