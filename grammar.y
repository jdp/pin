%include {
	#include <assert.h>
	#include <stdlib.h>
	#include "token.h"
}

%name PinParser
%token_prefix TK_
%token_type { PinToken* }
%token_destructor {
	free($$->value);
	free($$);
}

pin ::= words.

words   ::= word.
words   ::= words word.

word    ::= IDENT(I). { printf("IDENT %s\n", I->value); }
word    ::= NUMBER(N). { printf("NUMBER %s\n", N->value); }
