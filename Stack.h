//Stack.h

#ifndef _Stack_h_ //guardas de inclusion
#define _Stack_h_

#include "SLL.h"

typedef struct
{
    SLL* stack;
	size_t top; 
    size_t capacity; 
} Stack;

/*
* @brief Crea un nuevo objeto dinamico tipo pila
* @param La capacidad con la que ser� creada la pila
* @return El apuntador a la pila creada
*/
Stack* Stack_New( size_t _capacity );

/*
* @brief Destruye una pila dada
* @param La pila que se desea destruir
*/
void Stack_Delete( Stack* this ); 

/*
* @brief Ingresa un dato a la pila
* @param La pila a la que se le desea insertar el dato
*/
void Stack_Push( Stack* this, item _val ); 

/*
* @brief Retira un dato a la pila
* @param La pila a la que se le desea retirar el dato
* @return El dato retirado
*/
item Stack_Pop( Stack* this ); 

/*
* @brief Observa un dato a la pila
* @param La pila a la que se le desea retirar el dato
* @return El dato observado
*/
item Stack_Peek( Stack* this ); 

/*
* @brief Indica si la pila est� vacia
* @param La pila que se desea evaluar
* @return Un booleano que indica si est� vacia o no
*/
bool Stack_IsEmpty( Stack* this ); 

/*
* @brief Indica si la pila est� llena
* @param La pila que se desea evaluar
* @return Un booleano que indica si llena vacia o no
*/
bool Stack_IsFull( Stack* this ); 

/*
* @brief Indica el tama�o de la pila
* @param La pila de la que se desea conocer el tama�o
* @return El valor del tama�o
*/
size_t Stack_Len( Stack* this ); 

/*
* @brief Indica la capacidad de la pila
* @param La pila de la que se desea conocer la capacidad
* @return El valor de la capacidad
*/
size_t Stack_Capacity( Stack* this ); 

/*
* @brief Vacia una pila dada
* @param La pila que se desea vaciar
*/
void Stack_MakeEmpty( Stack* this );

#endif
