#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

// no da arvore
typedef struct estr {
        int chave;
        struct estr *esq;
	struct estr *dir;
} NO;

// no de lista ligada (caso queira usar alguma estrutura auxiliar)
typedef struct estrL {
        int chave;
        struct estrL *prox;
} NOL;

//Imprime lista ligada
void show(NOL* p){
	while(p){
		printf("%d ", p->chave);
		p = p->prox;
	}
	printf("\n");
}

//Informa quantidade de elementos da lista
int listSize(NOL* p){
    int counter = 0;
    while(p){
        p = p->prox;
        counter++;
    }
    return counter;
}

//***** Esta sessão extra é em relação à lista ligada, caso seja interessante alterá-la *****
//Cria nó da lista ligada
NOL* createNOL(int key) {
	NOL* newElem = (NOL*)malloc(sizeof(NOL));
	if (newElem){
		newElem->chave = key;
		newElem->prox = NULL;
	}
	return newElem;
}

//Verifica estado da lista ligada
int isEmpty(NOL* list) {
	return !list;
}

//Busca sequencial da lista ligada
int seqSearch(NOL* p, int key, NOL** ant){
	NOL* p1 = p;
    while (p1 != NULL) {
        if (p1->chave >= key){
            break;
        }
        *ant = p1;
        p1 = p1->prox;
    }
   	if (p1 && p1->chave == key){
        return 1;
   	}
    return 0;
}

//Insere na lista ligada
int insertLinkedList(NOL** p, int key) {
	NOL* newElem = createNOL(key);
  	if(!*p) {
    	*p = newElem;
    	return 1;
  	}
  	NOL* ant = NULL;
  	int isOnList = seqSearch(*p, key, &ant);
  	if(!isOnList){
		if(ant){
    		newElem->prox = ant->prox;
    		ant->prox = newElem;
			return 1;
		}
		if((*p)->chave < key){
            (*p)->prox = newElem;
		}
		else {
			newElem->prox = *p;
			*p = newElem;
		}
    	return 1;
  	}
	return 0;
}
//***** Fim sessão extra da lista ligada *****


//Imprime árvore com identação; valor de spaceSize determina o tamanho dos espaços entre níveis
void indentedPrint(NO* p, int spaceSize){
    if(p){
        if(p->dir){
            indentedPrint(p->dir, spaceSize+1);
        }
        for(int i = 0; i <= spaceSize; i++){
            printf("...");
        }
        printf("%d \n", p->chave);
        if(p->esq){
            indentedPrint(p->esq, spaceSize+1);
        }
    }
}

//Transfere valores da árvore para uma lista ligada em ordem CRESCENTE
void keyList(NO* p, NOL** first){
    if(p){
        keyList(p->dir, first); //Necessário vir antes de esq para sair em ordem
        NOL* n = (NOL*)malloc(sizeof(NOL));
        n->chave = p->chave;
        n->prox = *first;
        *first = n;
        keyList(p->esq, first);
    }
}

//Busca na árvore, retorna chave desejada e ponteiro para o pai
NO* search(NO* root, int key, NO** parent){
        *parent = NULL;
        if(!root){
            return NULL;
        }
        NO* p = root;
        while(p && p->chave != key){
            *parent = p;
            if(p->chave > key) p = p->esq;
            else p = p->dir;
        }
        if(p && p->chave == key){
            return p;
        }
        else return NULL;
}

//Insere chave, sem repetição, na árvore
int insert(NO** root, int key){
    NO* parent = NULL;
    NO* actual = search(*root, key, &parent);
    if(actual){
       return 0;
    }
    NO* newElem = (NO*)malloc(sizeof(NO));
    newElem->chave = key;
    newElem->esq = NULL;
    newElem->dir = NULL;
    if(parent){
        if(key < parent->chave){
            parent->esq = newElem;
        }
        else{
            parent->dir = newElem;
        }
    } else {
        *root = newElem;
    }
    return -1;
}

//Localiza o elemento do meio da lista ligada com elementos da árvore
NOL* middleElement(NOL* first, NOL* last){
    int fixedValue = 1;
    NOL* p = first;
    int counter = fixedValue;
    while(p != last->prox){
        counter = counter + 1;
        p = p->prox;
    }
    int middle = counter/2;
    if(counter == fixedValue) middle = fixedValue;
    int secCounter = fixedValue;
    p = first;
    while(secCounter != middle){
        secCounter = secCounter + 1;
        p = p->prox;
    }
    return p;
}

//Insere elemento do meio na árvore
void insertion(NO** root, NOL* first, NOL* last){
    NOL* newElem = middleElement(first, last);
    insert(root, newElem->chave);
}

//Localiza os elementos medianos da lista com elementos da árvore
void keyPoints(NO** root, NOL* first, NOL* last){
    if(first != last){
        NOL* meio = middleElement(first, last);
        insertion(root, first, last);
        keyPoints(root, first, meio);
        keyPoints(root, meio->prox, last);
    }
    else{
        insertion(root, first, last);
    }
}

// caso o compilador exija declarar a funcao aqui
NO* copiaCompleta(NO* raiz);

NO* copiaCompleta(NO* raiz){
    NO* ans = NULL;
    NOL* listPointer = NULL;

    keyList(raiz, &listPointer);

    NOL* auxPointer = listPointer;
    NOL* last = NULL;
    while(auxPointer){
        last = auxPointer;
        auxPointer = auxPointer->prox;
    }

    keyPoints(&ans, listPointer, last);

    return ans;
}


int main() {

    /*NO* raiz = NULL;
	NOL* p = NULL;

	insert(&raiz, 600);
	insert(&raiz, 17);
	insert(&raiz, 13);
	insert(&raiz, 99);
	insert(&raiz, 1);
	insert(&raiz, 500);
	insert(&raiz, 100);
	insert(&raiz, 3);
	insert(&raiz, 400);

	keyList(raiz, &p);

    show(p);

	NO* resp = copiaCompleta(raiz);
	indentedPrint(resp, 10);*/

}