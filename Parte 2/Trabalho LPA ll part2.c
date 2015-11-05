#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct arvore {
   int graupart;
   int chave;
   char unidade[20];
   struct arvore *pai;
   struct arvore *mae; 
};

int grau = 0;

// cria o tipo  "arvore" de modo "global" , onde o s galhos s�o os "parentes da raiz"

_Bool comparastring(char*string1,char*string2); //fun��o que compara strings e retorna verdadeiro ou falso 
void insercao(struct arvore *root,char*membro1,char*membro2,char*membro3);//prototipo de fun��o que insere membros na arvore;
void findgeracao(struct arvore *bo, int b); // prototipo da fun��o que imprime membros de uma mesma gera��o;
void antepassados(struct arvore *nome, char *filho);//prototipo da fun��o que imprime os antepassados;//
void passandostring(char*copiardaqui,char *colaraki);//prototipo da fun���o que copia strings
void Labelled(struct arvore *nome);// prototipo da fun��o que imprime em labelled breckting;
struct arvore *select(struct arvore *no, char *filho);
int retornagrau(struct arvore * no,char*membro);


main(){
	int comando,tuplas,grau,d,t,index,exit,op,bus,j,keys,ger,grauu;
	j=0;
	char filho[20] ;char pai[20];char mae[20];char name[20];char ment1[20];char ment2[20];
	int i = 0 ; // contadorA

	printf("                             ARVORE EM C\n                         RELACIONADO PARENTESCOS                  \n");
	printf("Digite o numero do item desejado para iniciar o comando sobre a arvore:\n\n1-Insercao\n2-Antepassados\n3-Imprime Geracao\n4-Grau de Parentesco\n5-Impressao da arvore em \"labelled bracketing\"\n\n");
	scanf("%d",&comando);
	while(comando!=1){
		system("cls");
		printf("O valor entrado corresponde a nenhuma das operacoes\npor favor digite um valor correspondente a uma operacao\n");
		scanf("%d",&comando);
	}//criou-se um tipo de menu para o usu�rio
	
	struct arvore * raiz = (struct arvore*)malloc(sizeof(struct arvore));//cria a primeira parte da  arvore , a raiz! aterrando os seus bra�os;
	raiz->pai = NULL;
	raiz->mae = NULL;
	
	//Agora cada comando ir� corresponder a uma fun��o
	
	
	if(comando == 1){ // ir� inserir os valores na �rvore
		system("cls");
		printf("Por favor digite o numero de Tuplas que serao inseridas na arvore: ");
		scanf("%d",&tuplas); //armazena qual  a quantidade de valores a serem armazenados
		printf("\nPor favor entre com a primeira tupla, na ordem filho - pai - mae , separando-os por espa�o :\n");
		scanf("%s",filho); // armazena em varia�veis "tempor�rias" os "nomes" de cada unidade;
		scanf("%s",pai);
		scanf("%s",mae);
	    raiz->graupart = 0 ; // faz o primeiro grua de parentesco , o da raiz , ser 0;
		passandostring(filho,raiz->unidade);	 // esta fun��o ir� copiar o "conteudo" de filho para raiz->nome;evitando o uso constante dos ciclos;
		insercao(raiz,filho,pai,mae);
		printf("Entre com os valores que serao inseridos separando-os por espaco:\n\n");
				
		for(i;i<tuplas-1;i++){ // faza inser��o de valores entrados pelo usu�rio;
			printf("Digite a proxima tupla:\n");
    		scanf("%s",filho); 
			scanf("%s",pai);
			scanf("%s",mae);
			raiz->graupart ++;
    		insercao(raiz,filho,pai,mae);//chama a fun��o para inserir dois novos membros relacionados a um membro j� existente;
    		
			 
		}
		
		printf("Os valores foram armazenados com sucesso!");
		
		printf("\n\n\aEscolha uma das opcoes:\n1-Sair\n2-Antepassados\n3-Imprime Geracao\n4-Grau de Parentesco\n5-Impressao da arvore em \"labelled bracketing\" \n ");//op��es para o usu�rio realizar outra a��o usando o "switch case";
		scanf("%d",&t);
		
		if(t==2){
			system("cls");
			index=2;
		}
		if(t==3){
			system("cls");
			index=3;
		}
		if(t==4){
			system("cls");
			index=4;
		}	
		if(t==5){
			system("cls");
			index=5;
		}

	}

	if(comando == 2){ // ir� remover valores da arvore;
		index = 2;//cria fun��o e a faz recursiva caso o usu�rio queira remover mais de um valor  da arvore;
		
		printf("\n\n\aEscolha uma das opcoes:\n1-Sair\n2-Antepassados\n3-Imprime Geracao\n4-Grau de Parentesco\n5-Impressao da arvore em \"labelled bracketing\" \n ");//op��es para o usu�rio realizar outra a��o usando o "switch case";
		scanf("%d",&t);
		
		if(t==2){
			system("cls");
			index=2;
		}
		if(t==3){
			system("cls");
			index=3;
		}
		if(t==4){
			system("cls");
			index=4;
		}	
		if(t==5){
			system("cls");
			index=5;
		}
				
	}
	if(comando == 3){
		system("cls");
		index = 3;		
		
		printf("\n\n\aEscolha uma das opcoes:\n1-Sair\n2-Antepassados\n3-Imprime Geracao\n4-Grau de Parentesco\n5-Impressao da arvore em \"labelled bracketing\" \n ");//op��es para o usu�rio realizar outra a��o usando o "switch case";
		scanf("%d",&t);
		if(t==2){
			system("cls");
			index=2;
		}
		if(t==3){
			system("cls");
			index=3;
		}
		if(t==4){
			system("cls");
			index=4;
		}	
		if(t==5){
			system("cls");
			index=5;
		}
		
	}
	if(comando == 4){
		system("cls");
		
	    index = 4;
		printf("\n\n\aEscolha uma das opcoes:\n1-Sair\n2-Antepassados\n3-Imprime Geracao\n4-Grau de Parentesco\n5-Impressao da arvore em \"labelled bracketing\" \n ");//op��es para o usu�rio realizar outra a��o usando o "switch case";
		scanf("%d",&t);
		if(t==2){
			system("cls");
			index=2;
		}
		if(t==3){
			system("cls");
			index=3;
		}
		if(t==4){
			system("cls");
			index=4;
		}	
		if(t==5){
			system("cls");
			index=5;
		}
	
	
	}
	if(comando == 5){
		system("cls");
		index = 5;
		
		printf("\n\n\aEscolha uma das opcoes:\n1-Sair\n2-Antepassados\n3-Imprime Geracao\n4-Grau de Parentesco\n5-Impressao da arvore em \"labelled bracketing\" \n ");//op��es para o usu�rio realizar outra a��o usando o "switch case";
		scanf("%d",&t);
		if(t==2){
			system("cls");
			index=2;
		}
		if(t==3){
			system("cls");
			index=3;
		}
		if(t==4){
			system("cls");
			index=4;
		}	
		if(t==5){
			system("cls");
			index=5;
		}
		
	}
	
 switch (index){
	case 2:
		printf("Digite o membro o qual deseja conhecer os seus antepassados:\n ");
		scanf("%s",name);
		system("cls");
		antepassados(raiz, name);
		printf("Serao os antepassados");
		
		break;		
	case 3:
	    printf("Digite a geracao cujos membros deseja vizualizar: ");
	    scanf("%d",&ger);
	    findgeracao(raiz,ger);
	    
		break;		
	case 4:
		printf("Digite , separando por espaco, os nomes que deseja verificar\no grau de parentesco\n");
		scanf("%s",ment1);
		scanf("%s",ment2);
			grauu = retornagrau(raiz,ment1) - retornagrau(raiz,ment2);
			if(grauu<0){			
			printf("O grau de parentesco entre %s e %s eh %d",ment1,ment2,-grauu);
			}else if(grauu==0){
				printf("Nao existe parentesco entre %s e %s ,assim o grau eh %d",ment1,ment2,grauu);
				}else{
				printf("O grau de parentesco entre %s e %s eh %d",ment1,ment2,grauu);
			}
			
			 
			
		
		break;
	case 5:
		printf("A impressao em \"Labelled Bracketing\" serah :\n\n");
		Labelled(raiz);
		break;	


		
}
	
}


void findgeracao(struct arvore *bo, int b){ //usando estrutura do "emordem";

	if(bo!=NULL){
		findgeracao(bo->pai,b);
		if(bo->graupart == b){
			printf("\n\n %s \n\nPertence a essa geracao.",bo->unidade);
		}
		findgeracao(bo->mae,b);
	}

}

void insercao(struct arvore *root,char*membro1,char*membro2,char*membro3){ // se insere a raiz da arvore , o nome do membro 1 , nome do membro q  ser� a nova raiz, membro 2 meembro que ser� inserido;
	
	if(root!= NULL){
		
		if(comparastring(root->unidade,membro1)){//comparastring(root->unidade,membro1)
		
			struct arvore *novopai=(struct arvore*)malloc(sizeof(struct arvore)); //insere o novo  pai;como parente de membro 1
			passandostring(membro2,novopai->unidade);
			root->pai = novopai;
			novopai->pai=NULL;
			novopai->mae=NULL;
			novopai->graupart = root->graupart+2;
		
			struct arvore *novamae=(struct arvore*)malloc(sizeof(struct arvore)); // insere a nova mae; como parente de membro 1
			passandostring(membro3,novamae->unidade);
			root->mae = novamae;
			novamae->pai=NULL;
			novamae->mae=NULL;
			novamae->graupart = root->graupart+2;
			
			printf("\nEssa Tupla foi inserida com sucesso!\n\n");
		}else{	
	
			insercao(root->pai,membro1,membro2,membro3);
			insercao(root->mae,membro1,membro2,membro3);
		}
		
	}
	
}


_Bool comparastring(char*string1,char*string2){
	int i = 0;
	
	while(string1[i]==string2[i] && string1[i]!='\0'&& string2[i]!='\0'){
		i++;
	}
	
	if(string1[i] =='\0' && string2[i]=='\0'){
		return 1;
	}else{
		return 0;
	}
		
}

void passandostring(char*copiardaqui,char *colaraki){ // fun��o para copiar strings;
	
	while(*copiardaqui!='\0'){
		*colaraki = *copiardaqui;
		copiardaqui++;
		colaraki++;
		
	}
	*colaraki='\0';
	
}

void antepassados(struct arvore *nome, char *filho){
	if(nome!=NULL){
		if (strcmp(nome->unidade, filho) != 0){//strcmp fun��o que ira comparar o conteudo das duas strings e consequentemente com o valor 0;
			printf("\n %s \n", nome->unidade);
		}
		antepassados(nome->mae, filho);
		antepassados(nome->pai, filho);
	}
}

void Labelled(struct arvore *nome){
	if(nome!=NULL)
	{
		printf("[%s", nome->unidade);
		Labelled(nome->mae);
		printf("]");
		Labelled(nome->pai);
		printf("]");
	}
	else 
	printf("[");
}




int retornagrau(struct arvore * no,char*membro){
	if(no!=NULL){
		if(comparastring(no->unidade,membro)){
			return no->graupart;
		}else{
			retornagrau(no->pai,membro);
			retornagrau(no->mae,membro);
		}
	}
	
}




