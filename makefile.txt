fb1-5:  fb1-5.l fb1-5.y
    bison -b parser.y -d fb1-5.y
    flex lexer.l
    cc lex.yy.c -ll
    notepad
    gcc -o fb1-5 fb1-5.tab.c lex.yy.c -lfl -ly -Wfatal-errors