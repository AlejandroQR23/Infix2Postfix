#include "SLL.h"
#include "Stack.h"

Stack* Stack_New( size_t _capacity )
{
	Stack* s = (Stack*) malloc( sizeof ( Stack ) );
    
    if( NULL != s ){
        s->stack = SLL_New(); 
        
        if( NULL == s->stack ){
            free( s );
            s = NULL; 
		}
        else{
        	s->top = 0;
            s->capacity = _capacity;
        }
    }
    
    return s;
}

void Stack_Delete( Stack* this )
{
	assert( this );
	SLL_Delete( this->stack );
	free(this);
}

void Stack_Push( Stack* this, item _val )
{
	assert( this );
	SLL_InsertFront( this->stack, _val );
	
	++this->top;
}

item Stack_Pop( Stack* this ) 
{
	assert( this );
	--this->top;
	
	item _val;
	SLL_RemoveFront( this->stack, &_val );
	return _val;
}

item Stack_Peek( Stack* this ) 
{
    assert( this->stack->len > 0 );
    if( Stack_IsEmpty( this ) ){ return ' '; }
    return this->stack->first->data; 
}

bool Stack_IsEmpty( Stack* this )
{
	return SLL_IsEmpty(this->stack);
}

bool Stack_IsFull( Stack* this )
{
	return (this->top >= this->capacity); 
}

size_t Stack_Len( Stack* this )
{
	return this->stack->len;
}

size_t Stack_Capacity( Stack* this )
{
	return this->capacity;
}

