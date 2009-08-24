/* A recursive-descent parser generated by peg 0.1.2 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define YYRULECOUNT 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pin.h"

/* Current line number */
static int yylineno;

/* Populate this with the code to compile */
static char* codebuf;

/* Pin context handlers */
static PIN_CONTEXT* context;
static PIN_CONTEXT* contexts[64];
static int context_depth;

static PIN_AST_NODE* quote;

/* Send input to yyparse from codebuf instead of stdin */
#define YY_INPUT(buf, result, max_size) {        \
	int yyc;                                     \
	if (codebuf && *codebuf != '\0')             \
		yyc= *codebuf++;                         \
	else                                         \
		yyc= EOF;                                \
	result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1); \
}

#define PIN_FINISH() printf("ok\n")
#define PIN_ERROR(E) PinError(1, yylineno, E)

#define NODE(T,R) PinAddNode(context, PINT_##T, R)


#ifndef YY_VARIABLE
#define YY_VARIABLE(T)	static T
#endif
#ifndef YY_LOCAL
#define YY_LOCAL(T)	static T
#endif
#ifndef YY_ACTION
#define YY_ACTION(T)	static T
#endif
#ifndef YY_RULE
#define YY_RULE(T)	static T
#endif
#ifndef YY_PARSE
#define YY_PARSE(T)	T
#endif
#ifndef YYPARSE
#define YYPARSE		yyparse
#endif
#ifndef YYPARSEFROM
#define YYPARSEFROM	yyparsefrom
#endif
#ifndef YY_INPUT
#define YY_INPUT(buf, result, max_size)			\
  {							\
    int yyc= getchar();					\
    result= (EOF == yyc) ? 0 : (*(buf)= yyc, 1);	\
    yyprintf((stderr, "<%c>", yyc));			\
  }
#endif
#ifndef YY_BEGIN
#define YY_BEGIN	( yybegin= yypos, 1)
#endif
#ifndef YY_END
#define YY_END		( yyend= yypos, 1)
#endif
#ifdef YY_DEBUG
# define yyprintf(args)	fprintf args
#else
# define yyprintf(args)
#endif
#ifndef YYSTYPE
#define YYSTYPE	int
#endif

#ifndef YY_PART

typedef void (*yyaction)(char *yytext, int yyleng);
typedef struct _yythunk { int begin, end;  yyaction  action;  struct _yythunk *next; } yythunk;

YY_VARIABLE(char *   ) yybuf= 0;
YY_VARIABLE(int	     ) yybuflen= 0;
YY_VARIABLE(int	     ) yypos= 0;
YY_VARIABLE(int	     ) yylimit= 0;
YY_VARIABLE(char *   ) yytext= 0;
YY_VARIABLE(int	     ) yytextlen= 0;
YY_VARIABLE(int	     ) yybegin= 0;
YY_VARIABLE(int	     ) yyend= 0;
YY_VARIABLE(int	     ) yytextmax= 0;
YY_VARIABLE(yythunk *) yythunks= 0;
YY_VARIABLE(int	     ) yythunkslen= 0;
YY_VARIABLE(int      ) yythunkpos= 0;
YY_VARIABLE(YYSTYPE  ) yy;
YY_VARIABLE(YYSTYPE *) yyval= 0;
YY_VARIABLE(YYSTYPE *) yyvals= 0;
YY_VARIABLE(int      ) yyvalslen= 0;

YY_LOCAL(int) yyrefill(void)
{
  int yyn;
  while (yybuflen - yypos < 512)
    {
      yybuflen *= 2;
      yybuf= realloc(yybuf, yybuflen);
    }
  YY_INPUT((yybuf + yypos), yyn, (yybuflen - yypos));
  if (!yyn) return 0;
  yylimit += yyn;
  return 1;
}

YY_LOCAL(int) yymatchDot(void)
{
  if (yypos >= yylimit && !yyrefill()) return 0;
  ++yypos;
  return 1;
}

YY_LOCAL(int) yymatchChar(int c)
{
  if (yypos >= yylimit && !yyrefill()) return 0;
  if (yybuf[yypos] == c)
    {
      ++yypos;
      yyprintf((stderr, "  ok   yymatchChar(%c) @ %s\n", c, yybuf+yypos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchChar(%c) @ %s\n", c, yybuf+yypos));
  return 0;
}

YY_LOCAL(int) yymatchString(char *s)
{
  int yysav= yypos;
  while (*s)
    {
      if (yypos >= yylimit && !yyrefill()) return 0;
      if (yybuf[yypos] != *s)
        {
          yypos= yysav;
          return 0;
        }
      ++s;
      ++yypos;
    }
  return 1;
}

YY_LOCAL(int) yymatchClass(unsigned char *bits)
{
  int c;
  if (yypos >= yylimit && !yyrefill()) return 0;
  c= yybuf[yypos];
  if (bits[c >> 3] & (1 << (c & 7)))
    {
      ++yypos;
      yyprintf((stderr, "  ok   yymatchClass @ %s\n", yybuf+yypos));
      return 1;
    }
  yyprintf((stderr, "  fail yymatchClass @ %s\n", yybuf+yypos));
  return 0;
}

YY_LOCAL(void) yyDo(yyaction action, int begin, int end)
{
  while (yythunkpos >= yythunkslen)
    {
      yythunkslen *= 2;
      yythunks= realloc(yythunks, sizeof(yythunk) * yythunkslen);
    }
  yythunks[yythunkpos].begin=  begin;
  yythunks[yythunkpos].end=    end;
  yythunks[yythunkpos].action= action;
  ++yythunkpos;
}

YY_LOCAL(int) yyText(int begin, int end)
{
  int yyleng= end - begin;
  if (yyleng <= 0)
    yyleng= 0;
  else
    {
      while (yytextlen < (yyleng - 1))
	{
	  yytextlen *= 2;
	  yytext= realloc(yytext, yytextlen);
	}
      memcpy(yytext, yybuf + begin, yyleng);
    }
  yytext[yyleng]= '\0';
  return yyleng;
}

YY_LOCAL(void) yyDone(void)
{
  int pos;
  for (pos= 0;  pos < yythunkpos;  ++pos)
    {
      yythunk *thunk= &yythunks[pos];
      int yyleng= thunk->end ? yyText(thunk->begin, thunk->end) : thunk->begin;
      yyprintf((stderr, "DO [%d] %p %s\n", pos, thunk->action, yytext));
      thunk->action(yytext, yyleng);
    }
  yythunkpos= 0;
}

YY_LOCAL(void) yyCommit()
{
  if ((yylimit -= yypos))
    {
      memmove(yybuf, yybuf + yypos, yylimit);
    }
  yybegin -= yypos;
  yyend -= yypos;
  yypos= yythunkpos= 0;
}

YY_LOCAL(int) yyAccept(int tp0)
{
  if (tp0)
    {
      fprintf(stderr, "accept denied at %d\n", tp0);
      return 0;
    }
  else
    {
      yyDone();
      yyCommit();
    }
  return 1;
}

YY_LOCAL(void) yyPush(char *text, int count)	{ yyval += count; }
YY_LOCAL(void) yyPop(char *text, int count)	{ yyval -= count; }
YY_LOCAL(void) yySet(char *text, int count)	{ yyval[count]= yy; }

#endif /* YY_PART */

#define	YYACCEPT	yyAccept(yythunkpos0)

YY_RULE(int) yy_eol(); /* 11 */
YY_RULE(int) yy_space(); /* 10 */
YY_RULE(int) yy__(); /* 9 */
YY_RULE(int) yy_r_bracket(); /* 8 */
YY_RULE(int) yy_l_bracket(); /* 7 */
YY_RULE(int) yy_quotation(); /* 6 */
YY_RULE(int) yy_number(); /* 5 */
YY_RULE(int) yy_ident(); /* 4 */
YY_RULE(int) yy_eof(); /* 3 */
YY_RULE(int) yy_word(); /* 2 */
YY_RULE(int) yy_pin(); /* 1 */

YY_ACTION(void) yy_1_eol(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_1_eol\n"));
   yylineno++; ;
}
YY_ACTION(void) yy_1_number(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_1_number\n"));
   NODE(NUMBER, yytext); ;
}
YY_ACTION(void) yy_1_ident(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_1_ident\n"));
   NODE(IDENT, yytext); ;
}
YY_ACTION(void) yy_1_r_bracket(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_1_r_bracket\n"));
   context = contexts[--context_depth]; ;
}
YY_ACTION(void) yy_1_l_bracket(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_1_l_bracket\n"));
   quote = NODE(QUOTATION, "["); contexts[++context_depth] = (PIN_CONTEXT*)quote->quotation; context = contexts[context_depth]; ;
}
YY_ACTION(void) yy_2_pin(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_2_pin\n"));
   PIN_ERROR("Parse error"); ;
}
YY_ACTION(void) yy_1_pin(char *yytext, int yyleng)
{
  yyprintf((stderr, "do yy_1_pin\n"));
   PIN_FINISH(); ;
}

YY_RULE(int) yy_eol()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "eol"));
  {  int yypos2= yypos, yythunkpos2= yythunkpos;  if (!yymatchString("\r\n")) goto l3;  goto l2;
  l3:;	  yypos= yypos2; yythunkpos= yythunkpos2;  if (!yymatchChar('\r')) goto l4;  goto l2;
  l4:;	  yypos= yypos2; yythunkpos= yythunkpos2;  if (!yymatchChar('\n')) goto l1;
  }
  l2:;	  yyDo(yy_1_eol, yybegin, yyend);
  yyprintf((stderr, "  ok   %s @ %s\n", "eol", yybuf+yypos));
  return 1;
  l1:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "eol", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_space()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "space"));
  {  int yypos6= yypos, yythunkpos6= yythunkpos;  if (!yymatchClass((unsigned char *)"\000\002\000\000\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l7;  goto l6;
  l7:;	  yypos= yypos6; yythunkpos= yythunkpos6;  if (!yy_eol()) goto l5;
  }
  l6:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "space", yybuf+yypos));
  return 1;
  l5:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "space", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy__()
{
  yyprintf((stderr, "%s\n", "_"));
  l9:;	
  {  int yypos10= yypos, yythunkpos10= yythunkpos;  if (!yy_space()) goto l10;  goto l9;
  l10:;	  yypos= yypos10; yythunkpos= yythunkpos10;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "_", yybuf+yypos));
  return 1;
}
YY_RULE(int) yy_r_bracket()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "r_bracket"));  if (!yymatchChar(']')) goto l11;  if (!yy__()) goto l11;  yyDo(yy_1_r_bracket, yybegin, yyend);
  yyprintf((stderr, "  ok   %s @ %s\n", "r_bracket", yybuf+yypos));
  return 1;
  l11:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "r_bracket", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_l_bracket()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "l_bracket"));  if (!yymatchChar('[')) goto l12;  if (!yy__()) goto l12;  yyDo(yy_1_l_bracket, yybegin, yyend);
  yyprintf((stderr, "  ok   %s @ %s\n", "l_bracket", yybuf+yypos));
  return 1;
  l12:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "l_bracket", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_quotation()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "quotation"));  if (!yy_l_bracket()) goto l13;
  l14:;	
  {  int yypos15= yypos, yythunkpos15= yythunkpos;  if (!yy_word()) goto l15;  goto l14;
  l15:;	  yypos= yypos15; yythunkpos= yythunkpos15;
  }  if (!yy_r_bracket()) goto l13;
  yyprintf((stderr, "  ok   %s @ %s\n", "quotation", yybuf+yypos));
  return 1;
  l13:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "quotation", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_number()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "number"));  yyText(yybegin, yyend);  if (!(YY_BEGIN)) goto l16;
  {  int yypos17= yypos, yythunkpos17= yythunkpos;  if (!yymatchChar('-')) goto l17;  goto l18;
  l17:;	  yypos= yypos17; yythunkpos= yythunkpos17;
  }
  l18:;	  if (!yymatchClass((unsigned char *)"\000\000\000\000\000\000\377\003\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l16;
  l19:;	
  {  int yypos20= yypos, yythunkpos20= yythunkpos;  if (!yymatchClass((unsigned char *)"\000\000\000\000\000\000\377\003\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l20;  goto l19;
  l20:;	  yypos= yypos20; yythunkpos= yythunkpos20;
  }  yyText(yybegin, yyend);  if (!(YY_END)) goto l16;  if (!yy__()) goto l16;  yyDo(yy_1_number, yybegin, yyend);
  yyprintf((stderr, "  ok   %s @ %s\n", "number", yybuf+yypos));
  return 1;
  l16:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "number", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_ident()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "ident"));  yyText(yybegin, yyend);  if (!(YY_BEGIN)) goto l21;  if (!yymatchClass((unsigned char *)"\000\000\000\000\000\000\000\000\376\377\377\007\376\377\377\007\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l21;
  l22:;	
  {  int yypos23= yypos, yythunkpos23= yythunkpos;  if (!yymatchClass((unsigned char *)"\000\000\000\000\000\000\000\000\376\377\377\007\376\377\377\007\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000")) goto l23;  goto l22;
  l23:;	  yypos= yypos23; yythunkpos= yythunkpos23;
  }  yyText(yybegin, yyend);  if (!(YY_END)) goto l21;  if (!yy__()) goto l21;  yyDo(yy_1_ident, yybegin, yyend);
  yyprintf((stderr, "  ok   %s @ %s\n", "ident", yybuf+yypos));
  return 1;
  l21:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "ident", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_eof()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "eof"));
  {  int yypos25= yypos, yythunkpos25= yythunkpos;  if (!yymatchDot()) goto l25;  goto l24;
  l25:;	  yypos= yypos25; yythunkpos= yythunkpos25;
  }
  yyprintf((stderr, "  ok   %s @ %s\n", "eof", yybuf+yypos));
  return 1;
  l24:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "eof", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_word()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "word"));
  {  int yypos27= yypos, yythunkpos27= yythunkpos;  if (!yy_ident()) goto l28;  goto l27;
  l28:;	  yypos= yypos27; yythunkpos= yythunkpos27;  if (!yy_number()) goto l29;  goto l27;
  l29:;	  yypos= yypos27; yythunkpos= yythunkpos27;  if (!yy_quotation()) goto l26;
  }
  l27:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "word", yybuf+yypos));
  return 1;
  l26:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "word", yybuf+yypos));
  return 0;
}
YY_RULE(int) yy_pin()
{  int yypos0= yypos, yythunkpos0= yythunkpos;
  yyprintf((stderr, "%s\n", "pin"));
  {  int yypos31= yypos, yythunkpos31= yythunkpos;  if (!yy_word()) goto l32;
  l33:;	
  {  int yypos34= yypos, yythunkpos34= yythunkpos;  if (!yy_word()) goto l34;  goto l33;
  l34:;	  yypos= yypos34; yythunkpos= yythunkpos34;
  }  if (!yy_eof()) goto l32;  yyDo(yy_1_pin, yybegin, yyend);  goto l31;
  l32:;	  yypos= yypos31; yythunkpos= yythunkpos31;  yyText(yybegin, yyend);  if (!(YY_BEGIN)) goto l30;  if (!yymatchDot()) goto l30;
  l35:;	
  {  int yypos36= yypos, yythunkpos36= yythunkpos;  if (!yymatchDot()) goto l36;  goto l35;
  l36:;	  yypos= yypos36; yythunkpos= yythunkpos36;
  }  yyText(yybegin, yyend);  if (!(YY_END)) goto l30;  yyDo(yy_2_pin, yybegin, yyend);
  }
  l31:;	
  yyprintf((stderr, "  ok   %s @ %s\n", "pin", yybuf+yypos));
  return 1;
  l30:;	  yypos= yypos0; yythunkpos= yythunkpos0;
  yyprintf((stderr, "  fail %s @ %s\n", "pin", yybuf+yypos));
  return 0;
}

#ifndef YY_PART

typedef int (*yyrule)();

YY_PARSE(int) YYPARSEFROM(yyrule yystart)
{
  int yyok;
  if (!yybuflen)
    {
      yybuflen= 1024;
      yybuf= malloc(yybuflen);
      yytextlen= 1024;
      yytext= malloc(yytextlen);
      yythunkslen= 32;
      yythunks= malloc(sizeof(yythunk) * yythunkslen);
      yyvalslen= 32;
      yyvals= malloc(sizeof(YYSTYPE) * yyvalslen);
      yybegin= yyend= yypos= yylimit= yythunkpos= 0;
    }
  yybegin= yyend= yypos;
  yythunkpos= 0;
  yyval= yyvals;
  yyok= yystart();
  if (yyok) yyDone();
  yyCommit();
  return yyok;
  (void)yyrefill;
  (void)yymatchDot;
  (void)yymatchChar;
  (void)yymatchString;
  (void)yymatchClass;
  (void)yyDo;
  (void)yyText;
  (void)yyDone;
  (void)yyCommit;
  (void)yyAccept;
  (void)yyPush;
  (void)yyPop;
  (void)yySet;
  (void)yytextmax;
}

YY_PARSE(int) YYPARSE(void)
{
  return YYPARSEFROM(yy_pin);
}

#endif


void PinTree(PIN_CONTEXT* ctx, int depth) {
	PIN_AST_NODE* node;
	node = ctx->node_head;
	while (node != NULL) {
		if (node->type == PINT_QUOTATION) {
			printf("[ ");
			PinTree((PIN_CONTEXT*)node->quotation, depth+1);
			printf("] ");
		}
		else {
			printf("%s ", node->repr);
		}
		node = node->next;
	}
}

PIN_CONTEXT* PinDo(char *code) {
	/* Manage context stack */
	contexts[0] = PinNew();
	context = contexts[0];
	context_depth = 0;
	/* Parse code */
	codebuf = code;
	yylineno = 1;
	while (yyparse());
	codebuf = 0;
	/* Validate and print out AST */
	context->nodes = context->node_head;
	if (context->nodes == NULL) {
		printf("I fucked up!\n");
	}
	else {
		PinTree(context, 0);
		printf("\n");
	}
	return context;
}

