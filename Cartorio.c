#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> // Biblioteca responsável por cuidar das string

int registro() // Função responsável por cadastrar os usuários no sistema
{
	// Inicio da criação das variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação das variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando infomação do usuário
	scanf("%s",cpf); // %s refere-se a string, quando precisa-se salvar uma string
	
	strcpy(arquivo, cpf); // Responsável por copiar valores da string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria/escrever o arquivo, sendo que o "w" significa "escrever"
	fprintf(file,"CPF: "); // Adiciona a palavra "CPF" para aparecer antes da informação, mantendo organizado quando for consultar
	fprintf(file,cpf); // Salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre e altera o aqruivo
	fprintf(file,"\nNome: "); // Adiciona a palavra "Nome" para organizar as informações quando forem consultadas
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Chama a mensagem para cadastrar o nome 
	scanf("%s",nome); // Salva a informação "nome"
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nSobrenome: "); // Adiciona a palavra "Sobrenome" para organizar as informações quando forem consultadas
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); // Chama a mensagem para cadastrar o Sobrenome
	scanf("%s",sobrenome); // Salva a informação "sobrenome"
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo: "); // Adiciona a palavra "Sobrenome" para organizar quando for consultadas as informações
	fclose(file); // Fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); // Chama a mensagem para adicionar o cargo
	scanf("%s",cargo); // Salva a informação "cargo"

	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause"); // Pausa o sistema, sendo necessário uma ação para seguir	
}

int consulta() // Função responsável por consultar os usuários cadastrados
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
		// Inicio da verificação
		printf("\nArquivo não encontrado! \n");
		printf("\n");
		fclose(file);
		system("pause");
		return 1;
		// Fim da verificação
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

int deletar() // Função responsável por deletar os usuários cadastrados
{
	char cpf[40]; // Armazenar o CPF do usuário
	char confirmacao; // Confirma o armazenamento do usuário
	
	printf("Digite o CPF do usuário a ser deletado: "); // Chama a mensagem para o CPF a ser deletado
	scanf("%s",cpf);
	
	// Tenta abrir o arquivo para ver se ele existe
	FILE *file;
	file = fopen(cpf,"r"); // Tentar ler o arquivo para ver se existe
	
	if(file == NULL) // Veriica se o arquivo não foi encontrado
	{
		// Inicio da verificação
		printf("\nUsuário não encontrado no sistema! \n");
		printf("\n");
		system("pause");
		return 1;
		// Final da verificação
	}
	
	else
	{
		fclose(file); // Fecha o arquivo 
		
		// Solicita a confirmação para a exclusão do usuário
		printf("\nTem certeza que deseja excluir esse usuário %s? \nInsira: \n(s) para Confirmar!\n(n) para Cancelar!\n", cpf); 
		scanf(" %c", &confirmacao);
		
		if (confirmacao == 's') // Comando para confirmar a exclusão 
		{
			remove(cpf); // Remover o arquivo
			printf("\nUsuário deletado com sucesso! \n");
			printf("\n");
			system("pause");
			return 1;	
		}
		
		if (confirmacao == 'n') // Comando para cancelar a exclusão
		{
			printf("\nOperação de exclusão cancelada!\n");
			printf("\n");
			fclose(file);
		}
		
		else // Comando em caso de inserir caracteres invalidos e/ou não cadastrados
		{
			printf("\nInsira um caracter de comando valido!\n");
			printf("\n");
			fclose(file);

		}
				
		system("pause"); // Pausa do sistema, requer ação para prosseguir
	}
	
	
}

int main() // Criação do menu de seleção
{
	int opcao=0; // Armazena a opção do usuário
	int laco=1; // Controla o loop
	
	for(laco=1;laco=1;) // Loop infinito para o menu principal
	{
		system("cls"); // Limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); // Definindo o idioma
		
		// Exibe o menu principal
		printf("### Cartório da EBAC ###\n\n"); // Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes. \n");
		printf("\t2 - Consultar nomes. \n");
		printf("\t3 - Deletar nomes. \n");
		printf("\t4 - Sair do sistema. \n\n"); 
		printf("Opção: "); // Final do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usuário
	
		system("cls"); // Responsável por limpar a tela
		
		switch(opcao) // Inicio da seleção com base na escolha do usuário
		{
			case 1:
			registro(); // Chamado de funções de registrar os dados
			break;
			
			case 2:
			consulta(); // Chamado de funções de registrar os dados
			break;
			
			case 3:
			deletar(); // Chamado de funções de registrar os dados
			break;
			
			case 4:
			printf("\nAté logo! \n");
			return 0;
			break;
			
			// Chama a mensagem caso não exista ou não tenha sido cadastrada a opção a ser registrada
			default:
			printf("Essa opção não existe! \n");
			system("pause");
			break; 	
			
			// Fim da seleção
		} 
	
	}
	
}
