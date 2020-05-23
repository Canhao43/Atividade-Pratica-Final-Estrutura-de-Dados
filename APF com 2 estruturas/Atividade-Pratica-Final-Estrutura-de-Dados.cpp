#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define BUFSIZE 256 //tamanho do buffer do char
#define total 10000 //total de disciplina e alunos possiveis cadastrar

/* 	Nome : Caio Marques de Souza 
	RA : 1303757
	Nome : Matheus Enrique Castro Silva
	RA : 3511216
	Nome : Lucas Cardoso dos Santos	
	RA : 3235421
	Nome : Lucas Grigoleto de Melo Gomes
	RA : 3227720
	 
	Atividade Prática Final - Estrutura de Dados
	Professor : Ariel da Silva Dias
	
	Título do projeto : Sistema de Gerenciamento de Alunos*/

struct reg_disciplina{
	int codigo;
	char disciplina[BUFSIZE];
}disciplina[total];

struct reg_notas{
	float aval1;
	float aval2;
	float aval3;
	float media;
}notas[total];

struct reg_estudantes{
	int codigo;
	int codigo_disc;
	char nome[BUFSIZE];
	char materia[BUFSIZE];
}estudantes[total];

int op, est, disc, disct=0, estt=0;

int Cadastro(void);
int Busca(void);
int Alteracao(void);
int Relatorio(void);
int Erro();

int main(){
	system("cls");
	int sair=1;
	setlocale(LC_ALL,"Portuguese");
	system("color 0F");
	do{
       	system("cls");
       	printf("\n");
       	printf("\t########################################################\n");
       	printf("\t#        					       #\n");
       	printf("\t#                 Gerenciamento de Alunos              #\n");
       	printf("\t#                                                      #\n");
       	printf("\t########################################################\n\n");
       	printf("\n Digite uma das opções\n\n");
       	printf("\n <1> - Cadastrar Disciplina");
       	printf("\n <2> - Alterar Disciplina");
       	printf("\n <3> - Consultar Disciplinas");
       	printf("\n <4> - Cadastrar Aluno");
       	printf("\n <5> - Alterar Aluno");
       	printf("\n <6> - Consultar Alunos");
       	printf("\n <7> - Lançar Nota");
       	printf("\n <8> - Alterar Nota");
       	printf("\n <9> - Relatório dos Estudantes");
       	printf("\n <0> - Sair");
       	printf("\n\n\n Digite sua opção:");
		scanf("%d",&op);
       	switch(op){	
	  		case 1: 
	  			if(disct <= total)
					Cadastro();
				else
					Erro();
			break;
	  		case 2: 
				Alteracao();
			break;
			case 3:
				Relatorio();
			break;
	  		case 4:
			  	if(estt <= total) 
					Cadastro();
				else
					Erro();
			break;
	  		case 5: 
				Alteracao();
			break;
			case 6:
				Relatorio();
			break;
	  		case 7: 
				Cadastro();
			break;
	  		case 8: 
				Alteracao();
			break;
			case 9:
				Relatorio();
			break;
	  		case 0: 
				sair=0;
       	}
 	}while(sair!=0);
}

Cadastro(void){  
	setlocale(LC_ALL, "portuguese");
	char resp[BUFSIZE];
    if(op == 1){
		do{	
    		system("cls");
    		printf("\n\n");
    		printf("\t########################################################\n");
    		printf("\t#        					       #\n");
    		printf("\t#                Cadastrar Disciplina                  #\n");
    		printf("\t#                                                      #\n");
			printf("\t########################################################\n\n\n");
			printf("\n\t Tecle 'ENTER' para continuar ou digite <FIM> para sair : ");
			fflush(stdin);
			gets(resp);
			if ((strcmp(resp,"fim")!=0)&&(strcmp(resp,"FIM")!=0)){
				printf("\n\t Nome da Disciplina : ");
				gets(disciplina[disct].disciplina);
				printf("\n\t Código da Disciplina : ");
				scanf("%d",&disciplina[disct].codigo);
				disct= disct + 1;
				printf("\n\t Gravação feita com sucesso...tecle 'ENTER' para continuar\n\n");
				system("pause > null");
			}
		}while((strcmp(resp,"fim")!=0)&&(strcmp(resp,"FIM")!=0));
	}
	if(op == 4){
		int sair=1,posicao=0,pos, j;
		int codigo;
		do{	
    		system("cls");
    		printf("\n\n");
    		printf("\t########################################################\n");
    		printf("\t#        					       #\n");
    		printf("\t#                Cadastrar Estudantes                  #\n");
    		printf("\t#                                                      #\n");
			printf("\t########################################################\n\n\n");
			printf("\n\t Tecle 'ENTER' para continuar ou digite <FIM> para sair : ");
			fflush(stdin);
			gets(resp);
			if ((strcmp(resp,"fim")!=0)&&(strcmp(resp,"FIM")!=0)){
				printf("\n\t Nome do aluno : ");
				gets(estudantes[estt].nome);
				printf("\n\t Código do aluno : ");
				scanf("%d",&estudantes[estt].codigo);
				do{
					printf("\n\t Código da disciplina que o aluno está cursando : ");
					scanf("%d",&codigo);
					for(int i=0; i<=disct; i++){
	    				if(codigo == disciplina[i].codigo){
	       					posicao=1;
	       					j = i;
	     					i=disct;
	     					estudantes[estt].codigo_disc = disciplina[j].codigo;
	     					strcpy(estudantes[estt].materia,disciplina[j].disciplina);
	     					estt++;
	     					
	    				}
	    				else{
	    					posicao=-1;
						}
					}
   					pos=posicao;
					if(pos==-1){
						printf("\n\t Disciplina inexistente no arquivo !");
	 					system("pause > null");
    				}
					else{
						sair=0;	
					}
				}while(sair!=0);
			printf("\n\t Gravação feita com sucesso...tecle 'ENTER' para continuar\n\n");
			system("pause > null");
			}
		}while((strcmp(resp,"fim")!=0)&&(strcmp(resp,"FIM")!=0));
	}
	if(op == 7){
		int pos, sair;
		pos=Busca();
		if(pos==-1){
			printf("\n\t Aluno inexistente no arquivo !");
	 		system("pause > null");
    	}
    	else{
    		do{
    		system("cls");
    		printf("\n\n");
    		printf("\t########################################################\n");
    		printf("\t#        					       #\n");
    		printf("\t#                   Cadastrar Notas                    #\n");
    		printf("\t#                                                      #\n");
			printf("\t########################################################\n\n\n");   
	    	printf("\n\t Nome do Estudante : %s",estudantes[est].nome);
	    	printf("\n\t Código do Estudantes : %d",estudantes[est].codigo);
	    	printf("\n\t Código da Disciplina que o Estudante Cursa : %d",estudantes[est].codigo_disc);
	    	printf("\n\t Disciplina que o Estudante Cursa : %s",estudantes[est].materia);
	    	printf("\n\t Tecle 'ENTER' para continuar\n\n");
	    	system("pause > null");
	    	printf("\n\t Digite as notas do aluno :\n");
	    	sair = 0;
	    	do{
	    		printf("\n\t Nota avaliação 1 : ");
	    		scanf("%f",&notas[est].aval1);
				if(notas[est].aval1 >=0 && notas[est].aval1 <=10)
					sair = 3;	
			}while(sair != 3);
			sair = 0;
	    	do{
	    		printf("\n\t Nota avaliação 2 : ");
	    		scanf("%f",&notas[est].aval2);
				if(notas[est].aval2 >=0 && notas[est].aval2 <=10)
					sair = 3;	
			}while(sair != 3);
			sair = 0;
	    	do{
	    		printf("\n\t Nota avaliação 3 : ");
	    		scanf("%f",&notas[est].aval3);
				if(notas[est].aval3 >=0 && notas[est].aval3 <=10)
					sair = 3;	
			}while(sair != 3);
	    	notas[est].media = (notas[est].aval1 + notas[est].aval2 + notas[est].aval3)/3;
	    	printf("\n\t Gravação feita com sucesso...tecle 'ENTER' para continuar\n\n");
			system("pause > null");	
			}while(sair != 3);
		}
	}
}

Busca(void){
   	int posicao=0;
   	char busca[BUFSIZE];
   	setlocale(LC_ALL,"Portuguese");
   	system("cls");
    printf("\n\n");
    printf("\t########################################################\n");
    printf("\t#        					       #\n");
    printf("\t#                       Menu de Busca                  #\n");
    printf("\t#                                                      #\n");
    printf("\t########################################################\n\n\n");
    if(op == 2 || op == 3){
    	printf("\n\t Digite a disciplina a ser procurada : ");
    	fflush(stdin);
    	gets(busca);
    	for(int i=0; i<=disct; i++){
	    	if(strcmp(busca,disciplina[i].disciplina)==0){
	       			posicao=1;
	       			disc = i;
	     			i = disct;
	    	}
	    	else{
	    		posicao=-1;
			}
		}
   		return(posicao);
	}
   	if(op == 4 || op == 5 || op == 6 || op == 7 || op == 8){
    	printf("\n\t Digite o nome do aluno a ser procurado : ");
    	fflush(stdin);
    	gets(busca);
   		for(int i=0; i<=estt; i++){
	    	if(strcmp(busca,estudantes[i].nome)==0){
	       			posicao=1;
	       			est = i;
	     			i = estt;
	    	}
	    	else{
	    		posicao=-1;
			}
		}
   		return(posicao);
	}	
}

Alteracao(void){
   	int pos;
    setlocale(LC_ALL,"Portuguese");
   	pos=Busca();
   	if(op == 2){
   		if(pos==-1){
			printf("\n\t Disciplina inexistente no arquivo !");
	 		system("pause > null");
    	}
		else{    
	    	printf("\n\t Nome da Disciplina : %s",disciplina[disc].disciplina);
	    	printf("\n\t Código da Disciplina : %d",disciplina[disc].codigo);
	    	printf("\n\t Tecle 'ENTER' para continuar\n\n");
	    	system("pause > null");
	    	printf("\n\t Digite as informações corretas :\n");
	    	printf("\n\t Nome da Disciplina : ");
	    	fflush(stdin);
	    	gets(disciplina[disc].disciplina);
	    	printf("\n\t Código da Disciplina : ");
	    	scanf("%d",&disciplina[disc].codigo);
	    	printf("\n\t Regravação feita com sucesso...");
			system("pause > null");
		}
	}
	if(op == 5){
		int sair=1,posicao=0,pos, j;
		if(pos==-1){
			printf("\n\t Aluno inexistente no arquivo !");
	 		system("pause > null");
    	}
		else{    
	    	printf("\n\t Nome do Estudante : %s",estudantes[est].nome);
	    	printf("\n\t Código do Estudantes : %d",estudantes[est].codigo);
	    	printf("\n\t Código da Disciplina que o Estudante Cursa : %d",estudantes[est].codigo_disc);
	    	printf("\n\t Disciplina que o Estudante Cursa : %s",estudantes[est].materia);
	    	printf("\n\t Tecle 'ENTER' para continuar\n\n");
	    	system("pause > null");
	    	printf("\n\t Digite as informações corretas :\n");
			printf("\n\t Nome do Estudante : ");
			gets(estudantes[est].nome);
			printf("\n\t Código do Estudante : ");
			scanf("%d",&estudantes[est].codigo);
			do{
				printf("\n\t Código da Disciplina que o Estudante Cursa : ");
				scanf("%d",&estudantes[est].codigo_disc);
				for(int i=0; i<=disct; i++){
	    			if(estudantes[est].codigo_disc == disciplina[i].codigo){
	       				posicao=1;
	       				j = i;
	     				i=disct;
	     				estudantes[est].codigo_disc = disciplina[j].codigo;
	     				strcpy(estudantes[est].materia,disciplina[j].disciplina);
	     					
	    			}
	    			else{
	    				posicao=-1;
					}
				}
   				pos=posicao;
				if(pos==-1){
					printf("\n\t Disciplina inexistente no arquivo !");
	 				system("pause > null");
    			}
				else{
					sair=0;	
				}
			}while(sair!=0);
			printf("\n\t Regravação feita com sucesso...");
			system("pause > null");
		}
	}
	if(op == 8){
		int sair=0, opcao;
		if(pos==-1){
			printf("\n\t Aluno inexistente no arquivo !");
	 		system("pause > null");
    	}
		else{
			do{
	    		printf("\n\t Nome do Estudante : %s",estudantes[est].nome);
	    		printf("\n\t Código do Estudantes : %d",estudantes[est].codigo);
	    		printf("\n\t Código da Disciplina que o Estudante Cursa : %d",estudantes[est].codigo_disc);
	    		printf("\n\t Disciplina que o Estudante Cursa : %s",estudantes[est].materia);
	    		printf("\n\t Nota Avaliação 1 : %.2f",notas[est].aval1);
	    		printf("\n\t Nota Avaliação 2 : %.2f",notas[est].aval2);
	    		printf("\n\t Nota Avaliação 3 : %.2f",notas[est].aval3);
	    		printf("\n\t Tecle 'ENTER' para continuar\n\n");
	    		system("pause > null");
	    		printf("\n\t Escolha qual Avaliação deseja alterar :");
	    		printf("\n\t [1]. Avaliação 1");
	    		printf("\n\t [2]. Avaliação 2");
	    		printf("\n\t [3]. Avaliação 3");
	    		do{
	    			printf("\n\t Digite a opção escolhida : ");
	    			scanf("%d",&opcao);
	    			if(opcao == 1 || opcao == 2 || opcao == 3)
	    				sair = 1;
				}while(sair != 1);
				switch(opcao){
	    			case 1:
	    				printf("\n\t Digite a nota da Avaliação 1 : ");
	    				scanf("%f",&notas[est].aval1);
	    			break;
	    			case 2:
	    				printf("\n\t Digite a nota da Avaliação 2 : ");
	    				scanf("%f",&notas[est].aval2);
	    			break;
	    			case 3:
	    				printf("\n\t Digite a nota da Avaliação 3 : ");
	    				scanf("%f",&notas[est].aval3);
	    			break;
				}
			}while(sair != 1);
			printf("\n\t Regravação feita com sucesso...");
			system("pause > null");
		}
	}
}

Relatorio(void){
	if(op == 3){
		int pos;
	    setlocale(LC_ALL,"Portuguese");
	   	pos=Busca();
	   	if(pos==-1){
			printf("\n\t Disciplina inexistente no arquivo !");
		 	system("pause > null");
	    }
		else{    
		   	printf("\n\t Nome da Disciplina : %s",disciplina[disc].disciplina);
		   	printf("\n\t Código da Disciplina : %d",disciplina[disc].codigo);
		   	printf("\n\t Tecle 'ENTER' para voltar ao menu principal\n\n");
		   	system("pause > null");
		}
	}
	if(op == 6){
		int pos;
		pos=Busca();
		if(pos==-1){
			printf("\n\t Aluno inexistente no arquivo !");
	 		system("pause > null");
    	}
		else{    
	    	printf("\n\t Nome do Estudante : %s",estudantes[est].nome);
	    	printf("\n\t Código do Estudantes : %d",estudantes[est].codigo);
	    	printf("\n\t Código da Disciplina que o Estudante Cursa : %d",estudantes[est].codigo_disc);
	    	printf("\n\t Disciplina que o Estudante Cursa : %s",estudantes[est].materia);
	    	printf("\n\t Tecle 'ENTER' para continuar\n\n");
	    	system("pause > null");
		}
	}
	if(op == 9){
		int cont=0;
		setlocale(LC_ALL, "portuguese");
   		system("cls");
    	printf("\n\n");
	    printf("\t########################################################\n");
	    printf("\t#        					       #\n");
	    printf("\t#                Relatório dos Estudantes              #\n");
	    printf("\t#                                                      #\n");
	    printf("\t########################################################\n\n\n");
	   	printf("\n\t | Código | Nome | Disciplina |Aval.1|Aval.2|Aval.3| Média | Conceito |\n");
	    	for(int i=0; i<estt; i++){
				printf("\n\t | %d ", estudantes[i].codigo);
				printf("| %s ", estudantes[i].nome);
				printf("| %s ", estudantes[i].materia);
				printf("| %.2f ", notas[i].aval1);
				printf("| %.2f ", notas[i].aval2);
				printf("| %.2f ", notas[i].aval3);
				printf("| %.2f ", notas[i].media);
				if(notas[i].media >= 8.5 && notas[i].media <= 10.0)
		    		printf("| A |\n");
		    	if(notas[i].media >= 7.0 && notas[i].media <= 8.4999)
		    		printf("| B |\n");
		    	if(notas[i].media >= 6.0 && notas[i].media <= 6.9999)
		    		printf("| C |\n");
		    	if(notas[i].media >= 4.0 && notas[i].media <= 5.9999)
		    		printf("| D |\n");
		    	if(notas[i].media >= 0.0 && notas[i].media <= 3.9999)
		    		printf("| F |\n");
		    	cont++;	
				}
	   	printf("\n\t #Número de Alunos Cadastrados = %d#",cont);
	   	system("pause > null");
		}
}

Erro(){
	system("cls");
	printf("\n");
    printf("\t########################################################\n");
    printf("\t#        					       #\n");
    printf("\t#                 	Menu de ERRO                    #\n");
    printf("\t#                                                      #\n");
    printf("\t########################################################\n\n");
    printf("\n\n\t Não é possível cadastrar mais ");
    if(op == 1){
    	printf("disciplinas !!");
	}
	if(op == 3){
		printf("alunos !!");
	}
	printf("\n\n\t Pois o valor maximo de cadastros foi atingido !!");
	printf("\n\n\t Tecle 'ENTER' para voltar ao menu");
	system("pause > null");
}
