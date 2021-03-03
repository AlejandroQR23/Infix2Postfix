#include "SLL.h"

static Node* newNode( item _data )
{
    Node* nodo = (Node*) malloc( sizeof( Node ) );
    
    if( nodo ){
        nodo->data = _data;
        nodo->next = NULL;
    }
    
    return nodo;
}

SLL* SLL_New()
{
    
    SLL* list = (SLL*) malloc( sizeof( SLL ) );
    
    if( list ){
        list->first = NULL;
        list->last = NULL;
        list->cursor = NULL;
        list->len = 0;
    }
    
    return list;
}

void SLL_Delete( SLL* this )
{
    
    if( this ){
        while( !SLL_IsEmpty( this ) ){
            Node* tmp = this->first->next;
            free( this->first );
            this->first = tmp;
        }
        free( this );
    }
}

bool SLL_IsEmpty( SLL* this )
{
    return this->first == NULL;
}

void SLL_MakeEmpty( SLL* this ) 
{
    assert( this );
    
    while( !SLL_IsEmpty( this )){
        Node* next = this->first->next;
        free( this->first );
        this->first = next;
        --this->len;
    }
    
    assert( this->len == 0);
    //¿borramos todo?
    
    this->first = this->last = this->cursor = NULL;
    this->len = 0;
}

bool SLL_InsertBack( SLL* this, item _data )
{
    assert( this );
    bool done = false;
    
    Node* n = newNode( _data );
    if( n ){
        done = true;
        
        if( SLL_IsEmpty( this ) ){
            this->first = this->last = this->cursor = n; 
        }
        // la lista está vacía; éste es el primer nodo.
        else{ 
            this->last->next = n;
            this->last = n;
        }
        // la lista ya tenía nodos. El último nodo apunta al nuevo.
 
        ++this->len;
    }
    
    return done;
}

bool SLL_InsertFront( SLL* this, item _data ) 
{
    assert( this );
    bool done = false;
    
    Node* n = newNode( _data);
    if( n ){
        done = true;
        
        if ( SLL_IsEmpty( this )){
            this->first = this->last = this->cursor = n;
            this->len = 1;
        }
        
        else {
            n->next = this->first;
            this->first = n;
            ++this->len;
        }
        
    }
    
    return done;
}

bool SLL_InsertAfter( SLL* this, item _data )
{
    assert( this );
    bool done = false;
    
    Node* n = newNode( _data );
    if( n ){
        done = true;
        
        if ( SLL_IsEmpty( this )){
            this->first = this->last = this->cursor = n;
        }
        else {
        	n->next = this->cursor->next;
        	this->cursor->next = n;
		}
    }
}

bool SLL_RemoveFront( SLL* this, itemPtr _data )
{
    assert( this );
    
    *_data = this->first->data;
    Node* tmp = this->first->next;
    free( this->first );
    this->first = tmp;
    --this->len;
  
    return true;
}

void SLL_CursorFirst( SLL* this )
{
    this->cursor = this->first;
}

void SLL_CursorLast( SLL* this )
{
    this->cursor = this->last;
}

void SLL_CursorNext( SLL* this ) 
{
    assert(this);
    if( this->cursor != NULL){
        this->cursor = this->cursor->next;
    }
}

size_t SLL_Len( SLL* this )
{
    return this->len;
}

bool SLL_FindIf( SLL* this, item _key ) 
{
    assert( this );
    bool found = false;
    
    if( !SLL_IsEmpty( this )){
        Node* i = this->first; //copia de first 
        while( i->next != NULL){
            if( _key == i->data){
                found = true;
                break;
            }
            
            i = i->next;
        }
    }
    return found;
}

bool SLL_Search( SLL* this, item _key ) 
{
    assert( this );
    bool found = false;
    
    if( !SLL_IsEmpty( this )){
        Node* i = this->first;
        while( i->next != NULL){
            if( _key == i->data){
                this->cursor = i;
                found = true;
                break;
            }
            
            i = i->next;
        }
    }
    
    return found;
}



