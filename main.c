
#include <string.h>
#include <stdbool.h>

#include "Stack.h"
#include "SLL.h"

bool Jerarquia(char x, char y)
{
	bool r = false;
	
	if (x == '*'){
		r = true;
	}
	
	if (x == '+'){
		if( y == '*'){
			r = false;
		} else {
			r = true;
		}
	}
	
	if (x == '-'){
		r == false;
	}
	
	return r;
}

char* Infix2Rpn( char* _expr )
{
    Stack* miPila = Stack_New(strlen(_expr));
    size_t i, j;
    char* expr = _expr;
    
    for( i = 0, j = -1; i < strlen(expr); i++ ){
        if( expr[i] >= '0' && expr[i] <= '9'){
			expr[++j] = expr[i];
		} else if (expr[i] == '('){
		    Stack_Push(miPila, expr[i]);
		} else if (expr[i] == ')'){
		    while( !Stack_IsEmpty(miPila) && Stack_Peek(miPila) != '('){
		        expr[++j] = Stack_Pop(miPila);
		    }
		    if( !Stack_IsEmpty(miPila) && Stack_Peek(miPila) != '('){
		        exit(1); //expresion invalida
		    } else {
		        Stack_Pop(miPila);
		    }
		    
		} else {
		    while( !Stack_IsEmpty(miPila) && Jerarquia( Stack_Peek(miPila), expr[i]) ){
		        expr[++j] = Stack_Pop( miPila );
		    }
		    Stack_Push(miPila, expr[i]);
		}
    }
    
    while ( !Stack_IsEmpty(miPila) ){
        expr[++j] = Stack_Pop(miPila);    
    }
    
    expr[++j] = '\0';
	
	Stack_Delete(miPila);
	
	return expr;
}

int EvaluateRpn( char* _expr )
{
	Stack* miPila = Stack_New(strlen(_expr));
	
	for(size_t i = 0; i < strlen(_expr); ++i){
		if( _expr[i] >= '0' && _expr[i] <= '9'){
			Stack_Push(miPila, _expr[i]);
		} else {
			int n1 = Stack_Pop(miPila) - '0';
			int n2 = Stack_Pop(miPila) - '0';
			int n3;
			if( _expr[i] == '+'){
				n3 = n1 + n2;
			} else if( _expr[i] == '-'){
				n3 = n1 - n2;
			} else if( _expr[i] == '*'){
				n3 = n1 * n2;
			}
			
			Stack_Push(miPila, n3 +'0');
		}
	}
	
	int x = Stack_Pop(miPila) - '0';
	Stack_Delete(miPila);
	
	return x;
}

int main(){
	
	char expresion[50] = "(((3-6)*6)-(4*6))";
	printf("\n La expresion original es: %s", expresion);
	char* n_exp = Infix2Rpn( expresion );
	printf("\n La expresion en postfix es: %s", n_exp);
	printf("\n El valor numerico de la expresion es: %d", EvaluateRpn(n_exp));
	
	return 0;
}
