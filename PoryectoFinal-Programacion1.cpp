#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<ctime>

using namespace std;

//Estructura de la Lista
typedef struct lista{
	int dato;
	struct lista *ptrSiguiente;
}Lista;

typedef Lista *ptrLista;

//Funciones
//Ingresar
void ingresarI(ptrLista *lista, int dato);
void ingresarF(ptrLista *lista, int dato);
void ingresaPosicion(ptrLista *lista);

//Mostrar lista
void mostrarLista(ptrLista lista);

//Elimina elemento
void eliminaElemento(ptrLista *lista);
//Destruir
void destruir(ptrLista *lista);
//Esta Vacio
int estaVacia(ptrLista lista);
//Texto
void menu();
void error();
void vacio();
void title(string title);

int main(){
	int dato, op;
	char opC[2];
	ptrLista lista = NULL;
	
	printf("\t\t\"Bienvenido Estimado Ususario\"\n\n");
	do{
		system("color 17");
		menu();
		scanf("%d", &op);
		system("cls");
		
		//Menu
		switch(op){
			case 1:
				title("Ingresa al Inicio");
				system("color 20");
				
				ingresarI(&lista, dato);						
				break;
			
			case 2:	
				system("color B0");	
					
				IngresarF:
				title("Ingresa al Final");								
				printf("Ingrese el numero que desea ingresar al final de la lista (Debe ser un numero impar): ");
				scanf("%d", &dato);
				
				if(dato % 2){
					system("color B0");
					ingresarF(&lista, dato);
				}else{
					system("color 47");
					printf("El numero %d no es impar. intente de nuevo.\a\n\n", dato);
					system("PAUSE");
					system("cls");										
					goto IngresarF;
				}
				break;
				
			case 3:   /*  ------->  Yo  */  
											/*
											Ingresar posicion especifica
											En el case 3 hacemos la llamada a dos funciones: 
											Primero, Mostrar lista 
											Segundo, Ingresar posicion
											*/
				title("Ingresa en una Posicion Especifica");								
				mostrarLista(lista);
				
				system("color 57");
   				 ingresaPosicion(&lista);								
				break;
				
			case 4:   /*  ------->  Yo  */
										
										/*
										Eliminar elemento
										En el case 4 hacemos el llamado a la funcion:
										elimina elemento.
										- Si la lista esta vacia por medio de un else dara el aviso de "lista vacia"
										*/
				title("Eliminar Elemento");
				system("color 80");
				if(!estaVacia(lista)){
					eliminaElemento(&lista);
					
				}else{
					printf("La lista esta vacia.\n");
				}
				
				break;
				
			case 5:
			ElimLista:
				title("Eliminar Lista");
				system("color 70");
				if(!estaVacia(lista)){  
					mostrarLista(lista);
										
					printf("Desea eliminar la lista actual Si/No: ");
					scanf("\n%s", opC);
					
					strupr(opC);
					
					if(strcmp(opC, "SI")==0){
						destruir(&lista);
						if(lista==NULL){
							printf("\nLa lista fue eliminada correctamente :).\n\n");
						}else{
							printf("La lista no pudo eliminar, surgio un error :/\n");
						}
					}else if(strcmp(opC, "NO")==0){ 
						
					}else{
						error();
						system("PAUSE");
						system("cls"); 
						goto ElimLista;
					}										
				}else{
					printf("La lista esta vacia.\n");
				}
				break;
				
			case 6:
				title("Mostrar Lista");
				system("color 07");
				mostrarLista(lista);
				break;
				
			case 7:
				printf("Fin del programa...\n");
				break;
				
			default:
				error();
				break;	
		}
		system("PAUSE");
		system("cls");
	}while(op!=7);
	
	title("Integrantes");
	printf("\tRicardo Javier Galindo Flores - 5090 22 4077\n\n");
	printf("\tRicardo Antonio Cruz Lemus - 5090-22-3615\n\n");
	printf("\tSergio David Jacobo Martínez - 5090-22-3388\n");
	return 0;
}

//Ingresar

//IngresarI
void ingresarI(ptrLista *lista, int dato) {
    
	ptrLista nuevo;
	ptrLista anterior;
	ptrLista siguiente;
	
	IngresoIn:
    printf("Ingrese el numero que desea ingresar al inicio de la lista (Debe ser un numero par): ");
    scanf("%d", &dato);

    if (dato % 2 == 0) {
    	system("color 20");
        ptrLista nuevo = (Lista*)malloc(sizeof(Lista));
        if (nuevo == NULL) {
            printf("No hay espacio de memoria disponible.\n");
        } else {
            nuevo->dato = dato;
            nuevo->ptrSiguiente = *lista;
            *lista = nuevo;
            printf("\nEl numero %d se ha ingresado correctamente al inicio de la lista.\n", dato);
        }
    } else {
    	system("color 47");
        printf("\nEl numero %d no es par. Intente de nuevo.\a\n", dato);
        system("PAUSE");
        system("cls");
        title("Ingresa al Inicio");
        goto IngresoIn;
    }
}

//Ingresar al Final de la lista numeros impares
void ingresarF(ptrLista *lista, int dato){
	ptrLista nuevo;
	ptrLista anterior;
	ptrLista siguiente;
	
	nuevo = (Lista*)malloc(sizeof(Lista));
	if(nuevo==NULL){
		printf("No hay espacio de memoria disponible.\n");
	}else{
		nuevo->dato = dato;
		nuevo->ptrSiguiente = NULL;
		anterior = *lista;
		
		
		if(*lista==NULL){
			nuevo->ptrSiguiente = *lista;
			*lista = nuevo;	
			anterior = *lista;
		}else{
			while(anterior->ptrSiguiente !=NULL){
				anterior = anterior->ptrSiguiente ;

			}
			anterior->ptrSiguiente = nuevo;
		}
		
		if(anterior !=NULL){
			printf("\nEl elemento %d se han ingresado correctamente al final de la lista.\n", dato);
		}else{
			printf("Se produjo un error en el ingreso del elemento %d a la lista.\n", dato);
		}
		
	}
}

//Ingresar en posicion especifica   -------> Yo
void ingresaPosicion(ptrLista *lista){
    ptrLista nuevo, anterior, actual;
    int dato, posicion, i=1;

    nuevo = (Lista*)malloc(sizeof(Lista));
    if(nuevo != NULL){   	/* 
							En la funcion ingresar posicion ocurren 3 procesos
							1. Primero nos pregunta el elemento que deseamos ingresar en la lista por medio de un IF, 
							(Un aviso que si la lista esta vacia muestra un mensaje).
							
							2. El segundo es la posicion del elemento que deseamos agregar
							(La podemos observar en la parte del else).
							
							3. En el while pasamos la validacion de los 2 procesos anteriores
							(Si se cumple el elemento y la posicion, este elemento es agregado a la lista).
							sino la posicion escogida esta fuera de rango.
							*/
    
    	printf("\nIngrese el elemento que desea agregar: ");
    	scanf("%d", &dato);
    	    	
    	nuevo->dato = dato;

   	 	if(*lista == NULL){
        	nuevo->ptrSiguiente = NULL;
        	*lista = nuevo;
        	printf("\nLa lista esta vacia, el elemento %d, fue ingresado al inicio de la lista.\n",dato);
        	
    	}else{
		IngrePos:
    		printf("\nIngrese la posicion en la que desea agregar el elemento: ");
    		scanf("%d", &posicion);
    		system("color 57");//Color
    		
    		if(posicion <1){
				system("color 47");
				printf("\nLa posicion escogida esta fuera de rango. Ingrese nuevamente la posicion para el elemento \"%d\".\n\n\a", dato);
				system("PAUSE");
    			system("cls");
            	title("Ingresa en una Posicion Especifica");								           	
            	goto IngrePos;
			}
			
        	actual = *lista;
        	anterior = NULL;
        	i=1;

       	 	while(actual != NULL && i < posicion){ 
            	anterior = actual;
            	actual = actual->ptrSiguiente;
            	i++;
        	}

        	if(posicion == 1){
            	nuevo->ptrSiguiente = actual; 
            	*lista = nuevo;
        	}else if(actual == NULL){
            	system("color 47");
            	printf("\nLa posicion escogida esta fuera de rango, la lista tiene \"%d\". Ingrese nuevamente la posicion para el elemento \"%d\".\n\n\a",i-1, dato);
            	system("PAUSE");
    			system("cls");
            	title("Ingresa en una Posicion Especifica");								           	
            	goto IngrePos;
        	}else{
            	anterior->ptrSiguiente = nuevo;
            	nuevo->ptrSiguiente = actual;
        	}
			printf("\nEl elemento %d ha sido ingresado en la posicion %d de la lista.\n", dato, posicion);
    	}

    

	}else{
		printf("No hay espacio de memoria disponible.\n");
	}
}

//Mostrar   ------->
void mostrarLista(ptrLista lista) {
						
						/*
						En esta paso mostraremos la lista 
						(Si la lista es igual a NULL la lista esta vacia)
						y si la lista es diferente de NULL muestra la lista con los numeros 
						*/
    if (lista == NULL) {
        printf("La lista esta vacia.\n");
    } else {
        printf("La lista es: ");
        while (lista != NULL) {
            printf("%d -> ", lista->dato);
            lista = lista->ptrSiguiente;
        }
        printf("NULL\n\n");
    }
}

//Eliminar elemento  --------> Yo
void eliminaElemento(ptrLista *lista){
    ptrLista anterior, actual;
    int dato;
    char op[2];
						
						/*
						En la funcion elemina elemento al memento si la lista este vacia con un IF nos avisara que no se 
						encuentra ningun elemento a eliminar.
						
						- Por medio de un scanf debemos ingresar el elemento a elimirnar de la lista
						- Luego de eso un While hara la validacion de la eliminacion del elemento en la lista 
						- Si el elemento no se encuentra en la lista puede volver hacer ingresado por medio de
						un do while.
						- Cundo el elemento es eliminado de la lsita por medio de un else nos muestra el mensaje de 
						"Elemento ha sido eliminado de la lista"
						*/
    if(*lista == NULL){
        printf("La lista esta vacia. No se puede eliminar ningun elemento.\n");
    }else{
    	ElimEle:
    	title("Eliminar Elemento");
    	system("color 80");//Color
    	mostrarLista(*lista);
  		printf("Ingrese el elemento que desea eliminar: ");
    	scanf("%d", &dato);
        actual = *lista;
        anterior = NULL;

        while(actual != NULL && actual->dato != dato){
            anterior = actual;
            actual = actual->ptrSiguiente;
        }

        if(actual == NULL){
        	do{
        		printf("\n\aEl elemento \"%d\" no se encuentra en la lista.\n¿Desea volver a intentarlo? Si \\ No: ", dato);
            	scanf("\n%s", op);
            	strupr(op);
            	
            	if(strcmp(op, "SI")!=0 && strcmp(op, "NO")!=0){
            		cout<<endl;
					error(); 
            		system("PAUSE"); 
					system("cls");          		
				}
			}while(strcmp(op, "SI")!=0 && strcmp(op, "NO")!=0);
			
			if(strcmp(op, "SI")==0){
				system("cls"); 
				goto ElimEle;
			}
            
        }else if(anterior == NULL){
            *lista = actual->ptrSiguiente;
            free(actual);
            printf("El elemento %d ha sido eliminado de la lista.\n\n", dato);
            mostrarLista(*lista);
        }else{
            anterior->ptrSiguiente = actual->ptrSiguiente;
            free(actual);
            printf("El elemento %d ha sido eliminado de la lista.\n\n", dato);
            mostrarLista(*lista);
        }
    }
}
//Destruir
void destruir(ptrLista *lista){
	ptrLista temp;
	while(*lista!=NULL){
		temp = *lista;
		*lista = (*lista)->ptrSiguiente;
		free(temp);
	}
}

//Esta Vacio
int estaVacia(ptrLista lista){
	return lista==NULL;
}


//Texto
void menu(){
	title("Menu");
	printf("Ingrese la opcion deseada.\n\n");
	printf("1.\tIngresar al inicio de la lista.\n\n");
	printf("2.\tIngresar al final de la lista.\n\n");
	printf("3.\tIngresar en posicion especifica.\n\n");
	printf("4.\tEliminar elemento.\n\n");
	printf("5.\tEliminar lista completa.\n\n");
	printf("6.\tMostrar toda la lista.\n\n");
	printf("7.\tSalir.\n\n");
	printf("Opcion [ ]\b\b");
}

void error(){
	printf("Opcion no valida. Intente de nuevo.\a\n");
	system("color 47");
}

void vacio(){
	printf("La lista esta vacia.\n");
}

void title(string title){ 
	const int limit = 81;
	for(int i=0; i<limit; i++){
		cout<<"-";
		if(i == (limit/2)){
			cout<<title;
		}
	}
	cout<<endl;
}

void prueba(ptrLista *lista){
	int date;
	ptrLista nuevo;
	ptrLista siguiente;
	
	
	for(int i=0; i<6; i++){
		siguiente = *lista;
		nuevo = (Lista*)malloc(sizeof(Lista));
		
		date = i;
		nuevo->dato = date;
		nuevo->ptrSiguiente = NULL;
		
		if(*lista==NULL){
			nuevo->ptrSiguiente = *lista;
			*lista = nuevo;
		}else{
			while(siguiente->ptrSiguiente !=NULL){
				siguiente = siguiente->ptrSiguiente;
			}
			siguiente->ptrSiguiente = nuevo;
		}
		
	}
	
	ptrLista mostrar = *lista;
	printf("La lista de prueba es:\n");
	while(mostrar!=NULL){
		cout<<mostrar->dato<<"->";
		mostrar = mostrar->ptrSiguiente;
	}
	cout<<"NULL\n\n";
}