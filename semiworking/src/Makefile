all:
	lex lexer.l
	yacc -v parser.y
	g++ -Wno-error=all y.tab.c

clean:
	rm -f a.out lex.yy.c y.tab.c y.output
