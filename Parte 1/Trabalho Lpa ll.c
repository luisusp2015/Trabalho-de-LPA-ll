#include<stdio.h>
#include<stdlib.h>

struct arvore {
   int chave;
   int dado;
   struct arvore *esq;
   struct arvore *dir; 
};

// cria o tipo  "arvore" de modo "global" 

void insercao(struct arvore* no, int chave); // prototipo da função de inserção ;
void remocao(struct arvore *no, int chave) ; //prototipo da função de remoção;
void posordem(struct arvore*ko); // funções de impressão em preoderm posordem emordem;
void preordem(struct arvore *po);
void emordem(struct arvore *lo);
struct arvore*busca(struct arvore*ho, int chave); //função de busca na arvore
void Labelled(struct arvore *jo); //função de impressao;


main(){
	int comando,numentrada,contraiz,d,t,index,exit,op,bus;
	int i = 0 ; // contadorA

	printf("                             ARVORE EM C\n                         ARMAZENANDO INTEIROS                  \n");
	printf("Digite o numero do item desejado para iniciar o comando sobre a arvore:\n\n1-Insercao\n2-Remocao\n3-Busca\n4-Impressao\n5-Impressao da arvore em \"labelled bracketing\"\n\n");
	scanf("%d",&comando);
	while(comando!=1){
		system("cls");
		printf("O valor entrado deve corresponder a operacao de insercao,\npois a arvore ainda nao foi criada\npor favor digite um valor correspondente a uma operacao\n");
		scanf("%d",&comando);
	}//criou-se um tipo de menu para o usuário
	
	struct arvore * raiz = (struct arvore*)malloc(sizeof(struct arvore));//cria a primeira parte da  arvore , a raiz! aterrando os seus braços;
	raiz->esq = NULL;
	raiz->dir = NULL;
	
	//Agora cada comando irá corresponder a uma função
	
	
	if(comando == 1){ // irá inserir os valores na árvore
		system("cls");
		printf("Por favor digite o numero de entradas que serao inseridas na arvore: ");
		scanf("%d",&numentrada); //armazena qual  a quantidade de valores a serem armazenados
		printf("\nPor favor entre com o valor  da raiz: ");
		scanf("%d",&contraiz);
		raiz->chave = contraiz;		
		printf("Entre com os valores que serao inseridos separando-os por espaco:\n\n");
		
		for(i;i<numentrada-1;i++){ // faza inserção de valores entrados pelo usuário;
    	scanf("%d",&d);
    	insercao(raiz,d); // chama a função de insercao;
		}
		
			printf("Os valores foram armazenados com sucesso!");
		
		printf("\n\n\aEscolha uma das opcoes:\n1-Sair\n2-Remocao\n3-Busca\n4-Impressao\n5-Impressao da arvore em \"labelled bracketing\" \n ");//opções para o usuário realizar outra ação usando o "switch case";
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
 switch (index){ // usando o switch para facilitar o acesso das opções do menu para o usuário;
	case 2:
		printf("Digite o valor o qual deseja remover: ");
		scanf("%d",&exit);
		remocao(raiz,exit);
		printf("\n\nO valor foi removido com sucesso!");
		break;		
	case 3:
		printf("Digite o valor do elemento a ser buscado na arvore: ");
		scanf("%d",&bus);
		struct arvore *teste = busca(raiz, bus);
		if(teste !=NULL){
			printf("\nO valor existe na arvore!");
			
		}else{
			printf("\nO valor nao existe na arvore!");
		}
		break;		
	case 4:
		printf("Escolha uma opcao de impressao:\n1--Pos-ordem \n2--pre-ordem \n3--em ordem:\n\n ");
		scanf("%d",&op);
		printf("\n\n\nA sequencia serah:\n");
		if(op == 1){
			posordem(raiz);
		}
		if(op == 2){
			preordem(raiz);
		}
		if(op == 3){
			emordem(raiz);
		}
		break;
	case 5:
		printf("A impressao em \"Labelled Bracketing\" serah :\n\n");
		Labelled(raiz);
		break;	


		
}
	
}
	

//função de inserção
void insercao(struct arvore* no, int chave){
    struct arvore *p = no;
    struct arvore *pai = NULL;
     
    while(p != NULL) {
        pai = p;
        if (p->chave >= chave) {
            p = p->esq;
        } else {
            p= p->dir;
        }
    }
 
    struct arvore *novo= (struct arvore*)malloc(sizeof(struct arvore));     
    novo->chave = chave;
    novo->esq = NULL;
    novo->dir = NULL;
     
    if(pai->chave >= novo->chave){
        pai->esq=novo;
    }   
    else{
        pai->dir=novo;
        }
    printf("O valor eh %d\n",novo->chave);    
}  




//função de remoção
void remocao(struct arvore *no, int chave){
    struct arvore *p = no;
    struct arvore *pai = NULL;
     
    while(p != NULL && p->chave != chave) {
        pai = p;
        if (p->chave >= chave) {
            p = p->esq;
        } else {
            p = p->dir;
        }
    }
        if(p == NULL){
                 return;
    }
    struct arvore *m = p->dir;
    while(m != NULL && m->esq != NULL){
            m = m->esq;
    }
    struct arvore *n;
        if(m != NULL){
        m -> esq = p -> esq;
        n = p->dir;
    } else {
        n = p->esq;
    }
        if(pai->chave < chave) {
        pai->dir = n;
    } else {
        pai->esq = n;
    }
    free(p);
}

//funções de impressão
void posordem(struct arvore *ko){
	struct arvore *j = ko;
	if(j!=NULL){
		
		printf("\n\n %d \n\n",ko->chave);
		posordem(ko->esq);
		posordem(ko->dir);
		
	}
}

void preordem(struct arvore *po){
	struct arvore *h = po;
	if(h!=NULL){
		
		preordem(po->esq);
		preordem(po->dir);
		printf("\n\n %d \n\n",po->chave);
		
	}
}

void emordem(struct arvore *lo){
	struct arvore *g = lo;
	if(g!=NULL){
		
		emordem(lo->esq);
		printf("\n\n %d \n\n",lo->chave);
		emordem(lo->dir);
		
	}
}

//função de busca
struct arvore*busca(struct arvore*ho, int chave){
    if(ho==NULL){
	return NULL;
	}
    if(ho->chave==chave){
        return ho;
    }
    if(chave>=ho->chave){
        return busca(ho->dir, chave);
	}
    if(chave < ho->chave){
        return busca(ho->esq, chave);
    }
}

//função de impressão em labelled;
void Labelled(struct arvore *jo){
	if(jo!=NULL)
	{
		printf("[%d", jo->chave);
		Labelled(jo->esq);
		printf("]");
		Labelled(jo->dir);
		printf("]");
	}
	else 
	printf("[");
}



