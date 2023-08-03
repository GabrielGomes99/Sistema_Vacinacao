#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct Paciente
{
  char nome[80];
  char cpf[20];
  char vacina[20];
  char data[15];
  int lote;
  int codigo;
} Paciente;

Paciente paciente_especial [999]; 


void consultar();
void imprimir();
void cadastrar();


int main(void)
{
  setlocale(LC_ALL,"portuguese");
  int opcao;
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);
	
  
  do
  {
    system("cls||clear");
    printf("\n-----------------MENU--------------------\n\
            \n\r 1 - Cadastrar       \n\
            \r 2 - Listar Aplicações \n\
            \r 3 - Pesquisar por CPF \n\
            \r 4 - Sair              \n\
            \r\n --------------------------------------\n\
            \r\n     Digite a opção:  ");
    scanf("%d%*C", &opcao);
    switch(opcao)
    {
    case 1:
      cadastrar();
      break;
    case 2:
      imprimir();
      break;
    case 3:
      consultar();
      break;
    case 4:
      system("exit");
      break;
    default:
      printf("Opção Inválida, Tecle Enter Para Continuar . . . !\n");
      break;
    }
  } while( opcao != 4 );
  
}

void cadastrar(){
	
	int op = 0;
	int num;
	
	do{
		system("cls");
		static int i;	
		printf("\nDigite o Nome Completo: ");
		fflush(stdin);
	 	gets(paciente_especial[i].nome);
		
		printf("\nDigite o CPF: ");
		fflush(stdin);
		gets(paciente_especial[i].cpf);
	
		printf("\nDigite o Nome da Vacina: ");
		fflush(stdin);
		scanf("%s", &paciente_especial[i].vacina);
		getchar(); 
		
		printf("\nDigite a Data da Vacina: ");
	    fflush(stdin);
		gets(paciente_especial[i].data); 
		
		printf("\nDigite o Lote da Vacina: ");
		fflush(stdin);
		scanf("%d", &paciente_especial[i].lote);
		
		printf("\nDigite 1 Para Cadastrar Novamente ou Outro Valor Para Sair: ");
		fflush(stdin);
		scanf("%d", &op);	
		static int num = 1;
		
	    paciente_especial[i].codigo = num;
		
		num++;
		
		i++;
		
	}while(op==1);
}

void imprimir(){
	
	int i;
	system("cls");
	for(i=0;i<999;i++){
		if(paciente_especial[i].lote>0){
			
		printf("\nNome: %s\nCPF: %s\nVacina: %s\nData: %s\nLote: %d\nCodigo: %d\n", paciente_especial[i].nome, paciente_especial[i].cpf, paciente_especial[i].vacina, paciente_especial[i].data, paciente_especial[i].lote, paciente_especial[i].codigo);
		printf("-------------------------------------");
		}else{
			printf("\nTecle Enter 2x para Continuar: ");
			break;
		}

 }
	getchar();
	getchar();
}

void consultar(){
	
	char cpfpesquisa[30];
	int j;
	int op;
	
	system("cls");
	do{
		printf("\nCaso o CPF Informado For Inválido Não Aparecerá Nada na Tela ! \nDigite o CPF: ");
		fflush(stdin);
		gets(cpfpesquisa);
	
	 	for(j=0;j<999;j++){
			if(strcmp(paciente_especial[j].cpf, cpfpesquisa)==0){
				printf("\nResultado:\n");
	 			printf("\nNome: %s\nCPF: %s\nVacina: %s\nData: %s\nLote: %d\nCodigo: %d\n", paciente_especial[j].nome, paciente_especial[j].cpf, paciente_especial[j].vacina, paciente_especial[j].data, paciente_especial[j].lote, paciente_especial[j].codigo);	
				break;
			
			}
	 		
		}

		printf("\nDigite 1 Para Continuar Pesquisando ou Outro Número Para Encerrar: ");
		scanf("%d", &op);
		
	}while(op==1);
}
	
  


