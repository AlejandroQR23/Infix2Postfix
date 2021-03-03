//SLL.h

#ifndef _SLL_h_ //guardas de inclusion
#define _SLL_h_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef char item;
typedef char* itemPtr;

typedef struct Node
{
    item data;
    struct Node* next;
} Node;

typedef struct SLL
{
    Node* first; 
    Node* last; 
    Node* cursor; 
    size_t len; 
} SLL;

/*
* @brief Crea una nueva SLL dinámica
* @return La SLL creada
*/
SLL* SLL_New();

/*
* @brief Borra una SLL dinámica
* @param La SLL que se desea borrar
*/
void SLL_Delete( SLL* this );

/*
* @brief Inserta un valor en el back de la SLL
* @param La SLL a la que se le va a insertar y el valor a insertar
* @return Un valor booleano indicando si se hizo correctamente el proceso
*/
bool SLL_InsertBack( SLL* this, item _data );

/*
* @brief Inserta un valor en el front de la SLL
* @param La SLL a la que se le va a insertar y el valor a insertar
* @return Un valor booleano indicando si se hizo correctamente el proceso
*/
bool SLL_InsertFront( SLL* this, item _data ); 

/*
* @brief Inserta un valor en frente del cursor de la SLL
* @param La SLL a la que se le va a insertar y el valor a insertar
* @return Un valor booleano indicando si se hizo correctamente el proceso
*/
bool SLL_InsertAfter( SLL* this, item _data ); 

/*
* @brief Retira un valor del front de la SLL
* @param La SLL a la que se le va a retirar y un apuntador que almacenará la dirección del valor a remover
* @return Un valor booleano indicando si se hizo correctamente el proceso
*/
bool SLL_RemoveFront( SLL* this, itemPtr _data );

/*
* @brief Visualiza el elemento de la lista al que apunta el cursor
* @param La SLL donde se desea visualizar el elemento
* @return Un boolenao indicando si se hizo correctamente el proceso
*/
bool SLL_Peek( SLL* this, itemPtr _data_back );

/*
* @brief Indica el numero de elementos actuales en una lista
* @param La SLL de la cual se desea obtener el tamaño
* @return El tamaño de la SLL
*/
size_t SLL_Len( SLL* this ); 

/*
* @brief Indica si la lista esta vacia
* @param La SLL que se desea revisar
* @return Un booleano indicando si esta o no vacia
*/
bool SLL_IsEmpty( SLL* this ); 

/*
* @brief Vacia la SLL
* @param La SLL que se desea vaciar
*/
void SLL_MakeEmpty( SLL* this );

/*
* @brief Mueve el cursor al principio de la lista
* @param La SLL donde se desea mover el cursor
*/
void SLL_CursorFirst( SLL* this );

/*
* @brief Mueve el cursor al final de la lista
* @param La SLL donde se desea mover el cursor
*/
void SLL_CursorLast( SLL* this );

/*
* @brief Mueve el cursor al siguiente elemento de la lista
* @param La SLL donde se desea mover el cursor
*/
void SLL_CursorNext( SLL* this );

/*
* @brief Busca un elemento en la lista sin mover el cursor
* @param La SLL donde se desea buscar el elemento
* @return Un boolenao indicando si se encontro o no
*/
bool SLL_FindIf( SLL* this, item _data );

/*
* @brief Busca un elemento en la lista y deja el cursor apuntando al lugar donde se encuentra
* @param La SLL donde se desea buscar el elemento
* @return Un boolenao indicando si se encontro o no
*/
bool SLL_Search( SLL* this, item _data );

#endif
