#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável pelas strings

int registro()//Função responsável por registrar os usuários no sistema
{
	
	setlocale(LC_ALL, "Portuguese"); 
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //coletando as informações do usuário
	scanf("%s", cpf); //%s é referente a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das strings
	
	FILE *file; // Cria o arquivo 
	file = fopen(arquivo, "w"); //Cria o arquivo - W de write
	fprintf(file, cpf); //Salva o valor da vairável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a"); //a para atualização
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando as informações do usuário
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando as informações do usuário
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando as informações do usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()//responsável por consultar os usuários que foram registrados na plataforma
{
	
	setlocale(LC_ALL, "Portuguese"); 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando as informações do usuário
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//r de read
	
	if(file == NULL)
	{
		printf("Arquivo não localizado!\n"); //retorno caso não encontre o CPF na plataforma
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
	
	printf("Digite o CPF do usuário a ser deletado: "); //registra as informações inseridas pelo usuário
	scanf("%s", &cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não foi encontrado no sistema.\n"); //retorno quando o usuário não foi encontrado no sistema 
		system("pause");
		fclose(file);
	}
	else
	{
		fclose(file);
		remove(cpf);
		printf("Usuário deletado com sucesso!\n"); //retorno quando o usuário foi deletado com sucesso
		system("pause");
	}
	
}


int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1; laco=1;)
	{
		
		system("cls"); //responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("*** Cartório da EBAC ***\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Finalizar sistema\n\n");//fim do menu
		printf("Opção: ");

		scanf("%d", &opcao); //Armazenamento da escolha do usuário
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registro(); //chamada de função
			break;
			
			case 2:
			consulta(); //chamada de função
			break;
			
			case 3:
			deletar(); //chamada de função
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
		} // fim da seleção
	
	
	}
}
