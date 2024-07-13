#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> // Biblioteca responsável por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); // Responsável por copiar valores da string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria/escrever o arquivo
	fprintf(file,"CPF: ");
	fprintf(file,cpf); // Salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nNome: ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSobrenome: ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo: ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);

	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo o idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // Comando para a busca
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // Comando para ler os arquivos
	
	if(file == NULL) // Verificação para arquivo(s) não encontrado(s)
	{
		printf("\nArquivo não encontrado! \n");
		printf("\n");
		fclose(file);
		system("pause");
		return 1;
	}
	
	printf("\nEssas são as informações do usuário! \n\n"); // Retorno quando encontrado o arquivo que foi buscado
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s",conteudo);
	}
	
	printf("\n\n");
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	char confirmacao;
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // Tentar ler o arquivo para ver se existe
	
	if(file == NULL) // Veriica se o arquivo não foi encontrado
	{
		printf("\nUsuário não encontrado no sistema! \n");
		printf("\n");
		system("pause");
		return 1;
	}
	
	else
	{
		fclose(file);
		
		printf("\nTem certeza que deseja excluir esse usuário %s? (s/n):", cpf); 
		scanf(" %c", &confirmacao);
		
		if (confirmacao == 's')
		{
			remove(cpf); // Remover o arquivo
			printf("\nUsuário deletado com sucesso! \n");
			printf("\n");	
		}
		
		else
		{
			printf("\nOperação de exclusão cancelada!\n");
			printf("\n");
		}
				
		system("pause");
	}
	
	
}

int main()
{
	int opcao=0; // Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); // Definindo o idioma
	
		printf("### Cartório da EBAC ###\n\n"); // Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes. \n");
		printf("\t2 - Consultar nomes. \n");
		printf("\t3 - Deletar nomes. \n\n"); 
		printf("Opção: "); // Final do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usuário
	
		system("cls");
		
		switch(opcao) // Inicio da seleção
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não existe! \n");
			system("pause");
			break; 	
		} // Fim da seleção
	
	}
	
}
