#line 1 "scanner.rl"
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


#line 16 "scanner.c"
static const char _pin_actions[] = {
	0, 1, 1, 1, 2, 1, 3, 1, 
	4, 1, 5, 1, 6, 1, 7, 1, 
	8, 1, 9, 1, 10, 1, 11, 2, 
	0, 1, 2, 1, 11
};

static const char _pin_key_offsets[] = {
	0, 0, 2, 4, 16, 17, 20, 22
};

static const char _pin_trans_keys[] = {
	49, 57, 48, 57, 10, 13, 32, 45, 
	9, 12, 49, 57, 65, 90, 97, 122, 
	10, 46, 48, 57, 48, 57, 33, 45, 
	63, 48, 57, 65, 90, 97, 122, 0
};

static const char _pin_single_lengths[] = {
	0, 0, 0, 4, 1, 1, 0, 3
};

static const char _pin_range_lengths[] = {
	0, 1, 1, 4, 0, 1, 1, 3
};

static const char _pin_index_offsets[] = {
	0, 0, 2, 4, 13, 15, 18, 20
};

static const char _pin_trans_targs[] = {
	5, 0, 6, 3, 3, 4, 3, 1, 
	3, 5, 7, 7, 0, 3, 3, 2, 
	5, 3, 6, 3, 3, 7, 3, 7, 
	7, 7, 3, 3, 3, 3, 3, 3, 
	0
};

static const char _pin_trans_actions[] = {
	7, 1, 0, 21, 11, 0, 13, 0, 
	13, 7, 0, 0, 23, 11, 19, 0, 
	7, 17, 0, 17, 9, 0, 9, 0, 
	0, 0, 15, 26, 19, 17, 17, 15, 
	0
};

static const char _pin_to_state_actions[] = {
	0, 0, 0, 3, 0, 0, 0, 0
};

static const char _pin_from_state_actions[] = {
	0, 0, 0, 5, 0, 0, 0, 0
};

static const char _pin_eof_actions[] = {
	0, 1, 0, 0, 0, 0, 0, 0
};

static const char _pin_eof_trans[] = {
	0, 0, 28, 0, 29, 31, 31, 32
};

static const int pin_start = 3;
static const int pin_error = 0;

static const int pin_en_main = 3;

#line 28 "scanner.rl"


void PinBlock(char *buffer, size_t length) {
	int cs, act;
	char *ts, *te;
	char *p = buffer;
	char *pe = p + length;
	char *eof = pe;
	
	
#line 95 "scanner.c"
	{
	cs = pin_start;
	ts = 0;
	te = 0;
	act = 0;
	}
#line 38 "scanner.rl"
	
	void *parser;
	parser = PinParserAlloc(malloc);

	
#line 108 "scanner.c"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_acts = _pin_actions + _pin_from_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 3:
#line 1 "scanner.rl"
	{ts = p;}
	break;
#line 129 "scanner.c"
		}
	}

	_keys = _pin_trans_keys + _pin_key_offsets[cs];
	_trans = _pin_index_offsets[cs];

	_klen = _pin_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _pin_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
_eof_trans:
	cs = _pin_trans_targs[_trans];

	if ( _pin_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _pin_actions + _pin_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 0:
#line 21 "scanner.rl"
	{ ERROR("i"); }
	break;
	case 1:
#line 22 "scanner.rl"
	{ ERROR("n"); }
	break;
	case 4:
#line 1 "scanner.rl"
	{te = p+1;}
	break;
	case 5:
#line 21 "scanner.rl"
	{te = p+1;{ TOKEN(IDENT); }}
	break;
	case 6:
#line 23 "scanner.rl"
	{te = p+1;}
	break;
	case 7:
#line 24 "scanner.rl"
	{te = p+1;}
	break;
	case 8:
#line 21 "scanner.rl"
	{te = p;p--;{ TOKEN(IDENT); }}
	break;
	case 9:
#line 22 "scanner.rl"
	{te = p;p--;{ TOKEN(NUMBER); }}
	break;
	case 10:
#line 24 "scanner.rl"
	{te = p;p--;}
	break;
	case 11:
#line 22 "scanner.rl"
	{{p = ((te))-1;}{ TOKEN(NUMBER); }}
	break;
#line 234 "scanner.c"
		}
	}

_again:
	_acts = _pin_actions + _pin_to_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 2:
#line 1 "scanner.rl"
	{ts = 0;}
	break;
#line 247 "scanner.c"
		}
	}

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	if ( _pin_eof_trans[cs] > 0 ) {
		_trans = _pin_eof_trans[cs] - 1;
		goto _eof_trans;
	}
	const char *__acts = _pin_actions + _pin_eof_actions[cs];
	unsigned int __nacts = (unsigned int) *__acts++;
	while ( __nacts-- > 0 ) {
		switch ( *__acts++ ) {
	case 1:
#line 22 "scanner.rl"
	{ ERROR("n"); }
	break;
#line 270 "scanner.c"
		}
	}
	}

	_out: {}
	}
#line 43 "scanner.rl"
	
	if (cs == 0) {
		printf("\nfuck\n");
	}
	else {
		PinParser(parser, 0, NULL);
	}
	
	printf("\n");
	
	PinParserFree(parser, free);
}
