#include <stdio.h> //biblioteca de comunicação com o usuario!
#include <stdlib.h> //biblioteca de alocação de espaço de memoria 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das strings

int registrar() //função responsavel por registrar o usuário
{
	//inicio da criação de variaveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];	

	printf("Digite Seu CPF a ser cadastrado: "); //coletar informações do usuário
	scanf("%s", cpf); //refere-se as strings
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",  nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadatrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL) // validação de CPF
	{
		printf("Não foi possível abrir o arquivo, Não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as infomações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser Deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //remove o arquivo escolhido 
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao = 0; //Definindo Variaveis
	int laco=1; 
	
	for(laco=1;laco=1;)
	{
	
		system("cls"); //Limpa a ação anterior
	
		setlocale(LC_ALL, "Portuguese");
	
		printf("### Cartório da EBAC ### \n\n"); 
		printf("Escolha a opção desejada no menu: \n\n");
		printf("\t1 - Registar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n");
		printf("\t4 - Sair do Sistema\n\n\n");
		printf("Opção: ");
	
		scanf ("%d", &opcao); //Amarzenando a escolha do user
	
		system("cls");
		
		switch(opcao)
		{
			case 1:
			registrar();
		 	break;
		 	
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar nosso sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa Opção não está disponível!\n");
			system("pause");// Pausa na Opção que escolheu
			break;			
		}	//Fim da Decisão
	}
}
