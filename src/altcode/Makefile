all:
	lex clexer.lex
	yacc -v cparser1.y
	gcc -Wno-error=all y.tab.c

clean:
	rm -f a.out lex.yy.c y.tab.c y.output
