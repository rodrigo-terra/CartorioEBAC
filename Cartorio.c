#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h> // Biblioteca respons�vel por cuidar das string

int registro() // Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	// Inicio da cria��o das vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o das vari�veis/strings
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando infoma��o do usu�rio
	scanf("%s",cpf); // %s refere-se a string, quando precisa-se salvar uma string
	
	strcpy(arquivo, cpf); // Respons�vel por copiar valores da string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria/escrever o arquivo, sendo que o "w" significa "escrever"
	fprintf(file,"CPF: "); // Adiciona a palavra "CPF" para aparecer antes da informa��o, mantendo organizado quando for consultar
	fprintf(file,cpf); // Salva o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre e altera o aqruivo
	fprintf(file,"\nNome: "); // Adiciona a palavra "Nome" para organizar as informa��es quando forem consultadas
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Chama a mensagem para cadastrar o nome 
	scanf("%s",nome); // Salva a informa��o "nome"
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSobrenome: "); // Adiciona a palavra "Sobrenome" para organizar as informa��es quando forem consultadas
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); // Chama a mensagem para cadastrar o Sobrenome
	scanf("%s",sobrenome); // Salva a informa��o "sobrenome"
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo: "); // Adiciona a palavra "Sobrenome" para organizar quando for consultadas as informa��es
	fclose(file); // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Chama a mensagem para adicionar o cargo
	scanf("%s",cargo); // Salva a informa��o "cargo"

	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); // Pausa o sistema, sendo necess�rio uma a��o para seguir	
}

int consulta() // Fun��o respons�vel por consultar os usu�rios cadastrados
{
	setlocale(LC_ALL, "Portuguese"); // Definindo o idioma
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); // Comando para a busca
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // Comando para ler os arquivos
	
	if(file == NULL) // Verifica��o para arquivo(s) n�o encontrado(s)
	{
		// Inicio da verifica��o
		printf("\nArquivo n�o encontrado! \n");
		printf("\n");
		fclose(file);
		system("pause");
		return 1;
		// Fim da verifica��o
	}
	
	printf("\nEssas s�o as informa��es do usu�rio! \n\n"); // Retorno quando encontrado o arquivo que foi buscado
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s",conteudo);
	}
	
	printf("\n\n");
	fclose(file);
	system("pause");
}

int deletar() // Fun��o respons�vel por deletar os usu�rios cadastrados
{
	char cpf[40]; // Armazenar o CPF do usu�rio
	char confirmacao; // Confirma o armazenamento do usu�rio
	
	printf("Digite o CPF do usu�rio a ser deletado: "); // Chama a mensagem para o CPF a ser deletado
	scanf("%s",cpf);
	
	// Tenta abrir o arquivo para ver se ele existe
	FILE *file;
	file = fopen(cpf,"r"); // Tentar ler o arquivo para ver se existe
	
	if(file == NULL) // Veriica se o arquivo n�o foi encontrado
	{
		// Inicio da verifica��o
		printf("\nUsu�rio n�o encontrado no sistema! \n");
		printf("\n");
		system("pause");
		return 1;
		// Final da verifica��o
	}
	
	else
	{
		fclose(file); // Fecha o arquivo 
		
		// Solicita a confirma��o para a exclus�o do usu�rio
		printf("\nTem certeza que deseja excluir esse usu�rio %s? \nInsira: \n(s) para Confirmar!\n(n) para Cancelar!\n", cpf); 
		scanf(" %c", &confirmacao);
		
		if (confirmacao == 's') // Comando para confirmar a exclus�o 
		{
			remove(cpf); // Remover o arquivo
			printf("\nUsu�rio deletado com sucesso! \n");
			printf("\n");
			system("pause");
			return 1;	
		}
		
		if (confirmacao == 'n') // Comando para cancelar a exclus�o
		{
			printf("\nOpera��o de exclus�o cancelada!\n");
			printf("\n");
			fclose(file);
		}
		
		else // Comando em caso de inserir caracteres invalidos e/ou n�o cadastrados
		{
			printf("\nInsira um caracter de comando valido!\n");
			printf("\n");
			fclose(file);

		}
				
		system("pause"); // Pausa do sistema, requer a��o para prosseguir
	}
	
	
}

int main() // Cria��o do menu de sele��o
{
	int opcao=0; // Armazena a op��o do usu�rio
	int laco=1; // Controla o loop
	
	for(laco=1;laco=1;) // Loop infinito para o menu principal
	{
		system("cls"); // Limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); // Definindo o idioma
		
		// Exibe o menu principal
		printf("### Cart�rio da EBAC ###\n\n"); // Inicio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes. \n");
		printf("\t2 - Consultar nomes. \n");
		printf("\t3 - Deletar nomes. \n");
		printf("\t4 - Sair do sistema. \n\n"); 
		printf("Op��o: "); // Final do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
		system("cls"); // Respons�vel por limpar a tela
		
		switch(opcao) // Inicio da sele��o com base na escolha do usu�rio
		{
			case 1:
			registro(); // Chamado de fun��es de registrar os dados
			break;
			
			case 2:
			consulta(); // Chamado de fun��es de registrar os dados
			break;
			
			case 3:
			deletar(); // Chamado de fun��es de registrar os dados
			break;
			
			case 4:
			printf("\nAt� logo! \n");
			return 0;
			break;
			
			// Chama a mensagem caso n�o exista ou n�o tenha sido cadastrada a op��o a ser registrada
			default:
			printf("Essa op��o n�o existe! \n");
			system("pause");
			break; 	
			
			// Fim da sele��o
		} 
	
	}
	
}
