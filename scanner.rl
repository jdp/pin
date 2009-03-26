#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
#include "pin.h"
#include "grammar.h"
#include "token.h"
#include "scanner.h"

#define TOKEN(T) PinParser(parser, TK_##T, PinTokenCreate(TK_##T, ts, te-ts))
#define ERROR(m) printf("\nError %s '%c'\n", m, *ts)

%%{
	machine pin;
	
	newline = "\r"? "\n" ;
	ident   = alpha (alnum|"-")* ("?"|"!")? ;
	number  = "-"? [1-9] digit* ("." digit+)? ;

	main := |*
		ident   $err{ ERROR("i"); } { TOKEN(IDENT); } ;
		number  $err{ ERROR("n"); } { TOKEN(NUMBER); } ;
		newline ;
		space   ;
	*|;
	
	write data nofinal;
}%%

void PinBlock(char *buffer, size_t length) {
	int cs, act;
	char *ts, *te;
	char *p = buffer;
	char *pe = p + length;
	char *eof = pe;
	
	%% write init;
	
	void *parser;
	parser = PinParserAlloc(malloc);

	%% write exec;
	
	if (cs == 0) {
		printf("\nfuck\n");
	}
	else {
		PinParser(parser, 0, NULL);
	}
	
	printf("\n");
	
	PinParserFree(parser, free);
}
