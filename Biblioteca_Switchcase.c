#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�os de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca de strings.
int registro() //fun��o para cadastro de usu�rios
{
	//cria��o das vari�veis/string
	char arquivo[40]; //vari�vel de nome de arquivo
	char cpf[40]; //vari�vel CPF
	char nome[40]; //vari�vel nome
	char sobrenome[40]; //vari�vel sobrenome
	char cargo[40]; //vari�vel cargo
	
	printf("Digite o CPF a ser cadastrado: "); //recebe informa��o do usu�rio
	scanf("%s", cpf); //pega a informa��o digitada e coloca dentro da vari�vel CPF
	
	strcpy(arquivo, cpf); //strcopy � STRING COPY - para copiar informa��es da vari�vel � direita para o item � esquerda
	
	FILE *file; // FILE - fun��o para abrir o FILE. *file; - � um comando.
	file = fopen(arquivo, "w"); //o comando de *file; - � abrir o arquivo com o nome da vari�vel arquivo, e "W" � de write, portanto, cria um arquivo com o nome.
	fprintf(file, cpf); //fprintf - � o mesmo printf s� que dentro de um arquivo. 
						//Nos par�nteses se coloca o que quer ser salvo (� direita) aonde quer que seja salvo (� esquerda)
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" � para atualizar o arquivo, n�o � para Write, nem Delete
	fprintf(file, ","); //fprintf para salvar informa��es dentro do arquivo (se for colocado dessa forma, adiciona um caractere ao final do arquivo)
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coleta informa��o do usu�rio
	scanf("%s", nome); //coloca informa��o digitada dentro da vari�vel
	
	file = fopen(arquivo, "a");//abre arquivo para atualizar, se estiver com "a".
	fprintf(file, nome);//coloca a informa��o da vari�vel "nome" dentro do arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");//abre arquivo para atualizar, se estiver com "a"
	fprintf(file, ",");//insere o caractere � direita ao final do arquivo
	fclose(file);
	
	printf("Digite agora o sobrenome: ");//coleta informa��o do usu�rio
	scanf("%s", sobrenome);//joga informa��o digitada para dentro da vari�vel
	
	file = fopen(arquivo, "a");//abre arquivo para atualizar
	fprintf(file, sobrenome);//adiciona a informa��o da vari�vel dentro do arquivo
	fclose(file);
	
	file = fopen(arquivo, "a");//abre o arquivo para atualizar
	fprintf(file, ",");//insere o caractere � direita no arquivo
	fclose(file);
	
	printf("Digite o cargo: ");//coleta informa��o do usu�rio
	scanf("%s", cargo);//joga informa��o digitada para dentro da vari�vel
	
	file = fopen(arquivo, "a");//abre arquivo para atualizar
	fprintf(file, cargo);//adiciona a informa��o da vari�vel dentro do arquivo
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//define idioma para portugu�s, para utiliza��o de acentos
	//cria��o de vari�veis
	char cpf[40];
	char conteudo[200];
	char *token;//cria��o de token/ponteiro para separar as informa��es de dentro da string
	
	printf("Digite o CPF a ser consultado: ");//coleta informa��o do usu�rio
	scanf("%s", cpf);//coloca a informa��o pra dentro da vari�vel
	
	FILE *file;//abre o arquivo
	file = fopen(cpf, "r"); //"r" de read - para ler o arquivo. Abre o arquivo correspondente ao CPF digitado.
	
	if(file == NULL) //se na hora de colocar o CPF o retorno for NULO, ou seja, n�o existe...
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)//fgets � para pegar informa��o dentro de um arquivo. ele vai procurar o conteudo dentro dos 200 caracteres do file
											// quando n�o tiver mais informa��es a serem lidas, ele quebra o la�o
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n");
		
		token = strtok(conteudo, ",");//token � utilizado para separar a partir daquele caractere, dentro da variavel conteudo
		printf("CPF: %s\n", token);//o token recebe a informa��o do primeiro item da string
		
		token = strtok(NULL, ",");//ao inv�s de colocar Conteudo, se coloca NULL, caso contr�rio o token vai separar o primeiro item da string novamente
		printf("Nome: %s\n", token);//separa o segundo item da string
		
		token = strtok(NULL, ",");//ao inv�s de colocar Conteudo, se coloca NULL, caso contr�rio o token vai separar o primeiro item da string novamente
		printf("Sobrenome: %s\n", token);//separa o terceiro item da string
		
		token = strtok(NULL, ",");//ao inv�s de colocar Conteudo, se coloca NULL, caso contr�rio o token vai separar o primeiro item da string novamente
		printf("Cargo: %s\n", token);//separa o quarto item da string
		
		printf("\n\n");
	}

	fclose(file);		
	system("pause");
}

int exclusao()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja excluir: ");
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf, "r");

	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado!\n");
		system("pause");
	}
	else
	{
	fclose(file);
		
		if(remove(cpf) == 0)//tenta remover o cpf digitado
		{
			printf("\nUsu�rio exclu�do com sucesso!\n\n");//caso exclus�o tenha sido bem sucedida
			system("pause");
		}
	
	}
}

int main()//menu
{
	int opcao=0; //Definir a vari�vel
	int x=1;
	
	for(x=1;x=1;)
	{
		system("cls");//clear screen
		
		setlocale(LC_ALL, "Portuguese");//definir a l�ngua
		
		printf("### Cart�rio da EBAC ###\n\n");
		//in�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Excluir nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");
		
		scanf("%d", &opcao);//recebendo a escolha do usu�rio
		
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
			printf("Op��o n�o dispon�vel\n");
			system("pause");
			break;
		}
	}
}
