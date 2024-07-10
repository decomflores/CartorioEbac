#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaços de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca de strings.
int registro() //função para cadastro de usuários
{
	//criação das variáveis/string
	char arquivo[40]; //variável de nome de arquivo
	char cpf[40]; //variável CPF
	char nome[40]; //variável nome
	char sobrenome[40]; //variável sobrenome
	char cargo[40]; //variável cargo
	
	printf("Digite o CPF a ser cadastrado: "); //recebe informação do usuário
	scanf("%s", cpf); //pega a informação digitada e coloca dentro da variável CPF
	
	strcpy(arquivo, cpf); //strcopy é STRING COPY - para copiar informações da variável à direita para o item à esquerda
	
	FILE *file; // FILE - função para abrir o FILE. *file; - é um comando.
	file = fopen(arquivo, "w"); //o comando de *file; - é abrir o arquivo com o nome da variável arquivo, e "W" é de write, portanto, cria um arquivo com o nome.
	fprintf(file, cpf); //fprintf - é o mesmo printf só que dentro de um arquivo. 
						//Nos parênteses se coloca o que quer ser salvo (à direita) aonde quer que seja salvo (à esquerda)
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" é para atualizar o arquivo, não é para Write, nem Delete
	fprintf(file, ","); //fprintf para salvar informações dentro do arquivo (se for colocado dessa forma, adiciona um caractere ao final do arquivo)
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coleta informação do usuário
	scanf("%s", nome); //coloca informação digitada dentro da variável
	
	file = fopen(arquivo, "a");//abre arquivo para atualizar, se estiver com "a".
	fprintf(file, nome);//coloca a informação da variável "nome" dentro do arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");//abre arquivo para atualizar, se estiver com "a"
	fprintf(file, ",");//insere o caractere à direita ao final do arquivo
	fclose(file);
	
	printf("Digite agora o sobrenome: ");//coleta informação do usuário
	scanf("%s", sobrenome);//joga informação digitada para dentro da variável
	
	file = fopen(arquivo, "a");//abre arquivo para atualizar
	fprintf(file, sobrenome);//adiciona a informação da variável dentro do arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");//abre o arquivo para atualizar
	fprintf(file, ",");//insere o caractere à direita no arquivo
	fclose(file);
	
	printf("Digite o cargo: ");//coleta informação do usuário
	scanf("%s", cargo);//joga informação digitada para dentro da variável
	
	file = fopen(arquivo, "a");//abre arquivo para atualizar
	fprintf(file, cargo);//adiciona a informação da variável dentro do arquivo
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//define idioma para português, para utilização de acentos
	//criação de variáveis
	char cpf[40];
	char conteudo[200];
	char *token;//criação de token/ponteiro para separar as informações de dentro da string
	
	printf("Digite o CPF a ser consultado: ");//coleta informação do usuário
	scanf("%s", cpf);//coloca a informação pra dentro da variável
	
	FILE *file;//abre o arquivo
	file = fopen(cpf, "r"); //"r" de read - para ler o arquivo. Abre o arquivo correspondente ao CPF digitado.
	
	if(file == NULL) //se na hora de colocar o CPF o retorno for NULO, ou seja, não existe...
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//fgets é para pegar informação dentro de um arquivo. ele vai procurar o conteudo dentro dos 200 caracteres do file
											// quando não tiver mais informações a serem lidas, ele quebra o laço
	{
		printf("\nEssas são as informações do usuário: \n");
		
		token = strtok(conteudo, ",");//token é utilizado para separar a partir daquele caractere, dentro da variavel conteudo
		printf("CPF: %s\n", token);//o token recebe a informação do primeiro item da string
		
		token = strtok(NULL, ",");//ao invés de colocar Conteudo, se coloca NULL, caso contrário o token vai separar o primeiro item da string novamente
		printf("Nome: %s\n", token);//separa o segundo item da string
		
		token = strtok(NULL, ",");//ao invés de colocar Conteudo, se coloca NULL, caso contrário o token vai separar o primeiro item da string novamente
		printf("Sobrenome: %s\n", token);//separa o terceiro item da string
		
		token = strtok(NULL, ",");//ao invés de colocar Conteudo, se coloca NULL, caso contrário o token vai separar o primeiro item da string novamente
		printf("Cargo: %s\n", token);//separa o quarto item da string
		
		printf("\n\n");
	}

	fclose(file);		
	system("pause");
}

int exclusao()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário que deseja excluir: ");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf, "r");

	if(file == NULL)
	{
		printf("Usuário não encontrado!\n");
		system("pause");
	}
	else
	{
	fclose(file);
		
		if(remove(cpf) == 0)//tenta remover o cpf digitado
		{
			printf("\nUsuário excluído com sucesso!\n\n");//caso exclusão tenha sido bem sucedida
			system("pause");
		}
	
	}
}

int main()//menu
{
	int opcao=0; //Definir a variável
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls");//clear screen
		
		setlocale(LC_ALL, "Portuguese");//definir a língua
		
		printf("### Cartório da EBAC ###\n\n");
		//início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Excluir nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");
		
		scanf("%d", &opcao);//recebendo a escolha do usuário
		
		system("cls");//clear screen
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			exclusao();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Opção não disponível\n");
			system("pause");
			break;
		}
	}
}
