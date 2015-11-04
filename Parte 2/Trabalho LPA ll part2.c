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

// cria o tipo  "arvore" de modo "global" , onde o s galhos são os "parentes da raiz"

void insertion(struct arvore* no, int chave,char *nome);//prototipo de função que insere membros na arvore;
void remocao(struct arvore *no, int chave) ; //prototipo da função de remoção;
void findgeracao(struct arvore *no, int b); // prototipo da função que imprime membros de uma mesma geração;
void antepassados(struct arvore *nome, char *filho);//prototipo da função que imprime os antepassados;
void Labelled(struct arvore *jo); // prototipo da função que imprime em labelled breckting;
void passandostring(char*copiardaqui,char *colaraki);//prototipo da funçção que copia strings



main(){
	int comando,tuplas,grau,d,t,index,exit,op,bus,j,keys,ger;
	j=0;
	char filho[20] ;char pai[20];char mae[20];
	int i = 0 ; // contadorA

	printf("                             ARVORE EM C\n                         RELACIONADO PARENTESCOS                  \n");
	printf("Digite o numero do item desejado para iniciar o comando sobre a arvore:\n\n1-Insercao\n2-Remocao\n3-Imprime Geracao\n4-Impressao\n5-Impressao da arvore em \"labelled bracketing\"\n\n");
	scanf("%d",&comando);
	while(comando>5 || comando<1){
		system("cls");
		printf("O valor entrado corresponde a nenhuma das operacoes\npor favor digite um valor correspondente a uma operacao\n");
		scanf("%d",&comando);
	}//criou-se um tipo de menu para o usuário
	
	struct arvore * raiz = (struct arvore*)malloc(sizeof(struct arvore));//cria a primeira parte da  arvore , a raiz! aterrando os seus braços;
	raiz->pai = NULL;
	raiz->mae = NULL;
	
	//Agora cada comando irá corresponder a uma função
	
	
	if(comando == 1){ // irá inserir os valores na árvore
		system("cls");
		printf("Por favor digite o numero de Tuplas que serao inseridas na arvore: ");
		scanf("%d",&tuplas); //armazena qual  a quantidade de valores a serem armazenados
		printf("\nPor favor entre com a primeira tupla, na ordem filho - pai - mae , separando-os por espaço :\n");
		scanf("%s",filho); // armazena em variaáveis "temporárias" os "nomes" de cada unidade;
		scanf("%s",pai);
		scanf("%s",mae);
	    raiz->graupart = 0; // faz o primeiro grua de parentesco , o da raiz , ser 0;
		passandostring(filho,raiz->unidade);	 // esta função irá copiar o "conteudo" de filho para raiz->nome;evitando o uso constante dos ciclos;
		keys = tuplas;
		raiz->chave = keys; // cria uma chave para a raiz
		;//chama a função insercao para inserir a tupla na arvore;
		
		printf("Entre com os valores que serao inseridos separando-os por espaco:\n\n");
				
		for(i;i<tuplas-1;i++){ // faza inserção de valores entrados pelo usuário;
			printf("Digite a proxima tupla:\n");
    		scanf("%s",filho); 
			scanf("%s",pai);
			scanf("%s",mae);
			
    		insertion(raiz,j,filho); // será a "nova raiz"
    		insertion(raiz,keys-2,pai); // atribui chaves para a função;
    		insertion(raiz,keys*3,mae);
    		j++; //
    		keys++;// irá criar novas chaves a cada ciclo;
    		
			 
		}
		
		printf("Os valores foram armazenados com sucesso!");
		
		printf("\n\n\aEscolha uma das opcoes:\n1-Sair\n2-Remocao\n3-Imprime Geracao\n4-Impressao\n5-Impressao da arvore em \"labelled bracketing\" \n ");//opções para o usuário realizar outra ação usando o "switch case";
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
	
	
	if(comando == 2){ // irá remover valores da arvore;
		index = 2;//cria função e a faz recursiva caso o usuário queira remover mais de um valor  da arvore;
		
		printf("\n\aEscolha uma das opcoes:\n1-Sair\n2-Remocao\n3-Busca\n4-Impressao\n5-Impressao da arvore em \"labelled bracketing\" \n ");//opções para o usuário realizar outra ação usando o "switch case";
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
		
		printf("\n\aEscolha uma das opcoes:\n1-Sair\n2-Remocao\n3-Busca\n4-Impressao\n5-Impressao da arvore em \"labelled bracketing\" \n ");//opções para o usuário realizar outra ação usando o "switch case";
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
		
		printf("\n\aEscolha uma das opcoes:\n1-Sair\n2-Remocao\n3-Busca\n4-Impressao\n5-Impressao da arvore em \"labelled bracketing\" \n ");//opções para o usuário realizar outra ação usando o "switch case";
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
		
		printf("\n\aEscolha uma das opcoes:\n1-Sair\n2-Remocao\n3-Busca\n4-Impressao\n5-Impressao da arvore em \"labelled bracketing\" \n ");//opções para o usuário realizar outra ação usando o "switch case";
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
		printf("Digite o valor o qual deseja remover: ");
		scanf("%d",&exit);
		
		printf("\n\nO valor foi removido com sucesso!");
		break;		
	case 3:
	    printf("Digite a geracao cujos membros deseja vizualizar: ");
	    scanf("%d",ger);
	    findgeracao(raiz,ger);
	    
		break;		
	case 4:
	
		break;
	case 5:
		printf("A impressao em \"Labelled Bracketing\" serah :\n\n");
		
		break;	


		
}
	
}

  

void findgeracao(struct arvore *no, int b){ //usando estrutura do "emordem";
	struct arvore *g = no;
	if(g!=NULL){
		
		findgeracao(no->pai,b);
		if(no->graupart == b){
			printf("\n\n %s \n\nPertencem a mesma geracao.",no->unidade);
		}
		findgeracao(no->mae,b);
		
	}

}


void insertion(struct arvore* no, int chave,char *nome){ //função de inserção em arvores que usa chaves;
    struct arvore *p = no;
    struct arvore *paii = NULL;
    int grau;
    grau = no->graupart;
     
    while(p != NULL) {
        paii = p;
        if (p->chave >= chave) {
            p = p->pai;
        } else {
            p= p->mae;
        }
    }
 
    struct arvore*novo=(struct arvore*)malloc(sizeof(struct arvore)); // cria novas caixas
    novo->chave = chave;
	novo->pai =NULL;
	novo->mae = NULL; 
	passandostring(nome,novo->unidade);
	novo->graupart = grau+1;  //aumenta um grau de parentesco a cada ciclo;  

     
    if(paii->chave >= novo->chave){
        paii->pai=novo;
    }   
    else{
        paii->mae=novo;
        }
  
} 


void passandostring(char*copiardaqui,char *colaraki){ // função para copiar strings;
	
	while(*copiardaqui!='\0'){
		*colaraki = *copiardaqui;
		copiardaqui++;
		colaraki++;
		
	}
	*colaraki='\0';
	
}

void antepassados(struct arvore *nome, char *filho){
	if(pessoa!=NULL){
		if (strcmp(nome->unidade, filho) != 0){//strcmp função que ira comparar o conteudo das duas strings e consequentemente com o valor 0;
			printf("\n %s \n", pessoa->unidade);
		}
		antepassados(nome->mae, filho);
		antepassados(nome->pai, filho);
	}
}


void grauparentesco(struct arvore *raiz, char *noh, char *no){
	struct arvore *a = select(raiz, noh);
	struct arvore *b = select(a, no);
	int grau;
	if(a == -2){
		printf("\n%s e %s nao possuem garu de parentesco (grau = 0)\n", noh, no);
	}
	else if (b == -2){
		printf("\n%s e %s nao possuem garu de parentesco (grau = 0)\n", noh, no);
	}
	else{
		grau = b->grau - a->grau;
		printf("\nO grau de parentesco entre %s e %s eh %d\n", noh, no, grau);
	}
}
