# CPSC 323 Project

Compile Instructions:

1. Compile/run part1.cpp to produce new text file with removed comments and whitespaces.  
g++ part1.cpp  
./a.out

2. Process LEX file  
lex proj.l

2. Process YACC file  
yacc -d proj.y

3. Link lex.yy.c & y.tab.c using gcc to produce an output file.  
gcc lex.yy.c y.tab.c -o proj.out

4. Run output file with newly edited text file.  
./proj.out < final2.txt

5. Compile/run abc13.cpp file.  
g++ abc13.cpp  
./a.out
