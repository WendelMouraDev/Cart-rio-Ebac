#include <stdio.h>  //biblioteca de comunica��o com o usu�rio.
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria.
#include <locale.h> //biblioteca de aloca��o de texto por regi�o(portugu�s).
#include <string.h> //biblioteca respons�vel por cuidar das strings.

int registro()//Fun��o respons�vel por registrar os usu�rios no sistema.
{
	//In�cio da cria��o de vari�veis/strings.
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis.
	
	printf("digite o CPF a ser cadastrado: ");//Coletando informa��es do usu�rio.
	scanf("%s", cpf);//%s serve para salvar uma string.
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings.
	
	FILE *file; //criar o arquivo.
	file = fopen(arquivo , "w"); //cria o arquivo e "w" significa escrever.
	fprintf(file,cpf); //salvar o valor da vari�vel.
	fclose(file); //fechar o arquivo.
	
	file = fopen(arquivo, "a");//adicionar v�rgula.
	fprintf(file, ",");
	fclose(file);

	printf("Digite o nome a ser cadastrado: ");//cadastro de nomes.
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");//salvar os nomes no arquivo/abrir o arquivo.
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");//adicionar v�rgula.
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");//cadastro de sobrenomes.
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");//salvar os sobrenomes no arquivo/abrir o arquivo.
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");//adicionar v�rgula.
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
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
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
		printf("O usu�rio n�o se encontra no sistema!\n");
	}
	
	system("pause");
	
}

int main()//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
{
	int opcao=0; //definindo vari�veis
	int laco=1;

	for(laco=1; laco=1;)//REVISAR
	{
	
		system("cls");//Respons�vel por limpar a tela no sistema windows.	
		
		setlocale(LC_ALL, "portuguese");  //definindo a linguagem
	
		printf("\tCART�RIO DA EBAC\n\n"); //in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes \n\n");
		printf("\t2 - Consultar nomes \n\n");
		printf("\t3 - Deletar nomes \n\n");
		printf("Op��o: ");//final do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio.
	
		system("cls");//Respons�vel por limpar a tela no sistema windows.
	
		switch(opcao)
		{
			case 1:
			registro();//Chamada de fun��es.
			break;
			
			case 2:
			consulta();//chamada de fun��es. 
			break;
			
			case 3:
			deletar();//Chamada de fun��es.
			break;
			
			default://Caso o usu�rio escolha uma op��o inv�lida.
			printf("Est� op��o n�o est� dispon�vel!\n ");		
			system("pause");
			break;
		}	
 	}
}







