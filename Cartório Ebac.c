#include <stdio.h>  //biblioteca de comunicação com o usuário.
#include <stdlib.h> //biblioteca de alocação de espaço em memória.
#include <locale.h> //biblioteca de alocação de texto por região(português).
#include <string.h> //biblioteca responsável por cuidar das strings.

int registro()//Função responsável por registrar os usuários no sistema.
{
	//Início da criação de variáveis/strings.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis.
	
	printf("digite o CPF a ser cadastrado: ");//Coletando informações do usuário.
	scanf("%s", cpf);//%s serve para salvar uma string.
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings.
	
	FILE *file; //criar o arquivo.
	file = fopen(arquivo , "w"); //cria o arquivo e "w" significa escrever.
	fprintf(file,cpf); //salvar o valor da variável.
	fclose(file); //fechar o arquivo.
	
	file = fopen(arquivo, "a");//adicionar vírgula.
	fprintf(file, ",");
	fclose(file);

	printf("Digite o nome a ser cadastrado: ");//cadastro de nomes.
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");//salvar os nomes no arquivo/abrir o arquivo.
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");//adicionar vírgula.
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//cadastro de sobrenomes.
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");//salvar os sobrenomes no arquivo/abrir o arquivo.
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");//adicionar vírgula.
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");//cadastro de cargos.
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");//salvar os cargos no arquivo/abrir o arquivo.
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");

	
}

int consulta()//------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{
	char cpf[40];
	char conteudo[200];
	
	setlocale(LC_ALL, "portuguese");  //definindo a linguagem
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	fclose(file);
	
	system("pause");
}



int deletar()//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;//REVISAR
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
	}
	
	system("pause");
	
}

int main()//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{
	int opcao=0; //definindo variáveis
	int laco=1;

	for(laco=1; laco=1;)//REVISAR
	{
	
		system("cls");//Responsável por limpar a tela no sistema windows.	
		
		setlocale(LC_ALL, "portuguese");  //definindo a linguagem
	
		printf("\tCARTÓRIO DA EBAC\n\n"); //início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes \n\n");
		printf("\t2 - Consultar nomes \n\n");
		printf("\t3 - Deletar nomes \n\n");
		printf("Opção: ");//final do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário.
	
		system("cls");//Responsável por limpar a tela no sistema windows.
	
		switch(opcao)
		{
			case 1:
			registro();//Chamada de funções.
			break;
			
			case 2:
			consulta();//chamada de funções. 
			break;
			
			case 3:
			deletar();//Chamada de funções.
			break;
			
			default://Caso o usuário escolha uma opção inválida.
			printf("Está opção não está disponível!\n ");		
			system("pause");
			break;
		}	
 	}
}







