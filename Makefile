all: testBinary

createlist.o: createlist.c
	gcc  -c createlist.c

createopcode.o: createopcode.c
	gcc -c createopcode.c

createsymboltable.o: createsymboltable.c
	gcc -c createsymboltable.c

validatesymbol.o: validatesymbol.c
	gcc -c validatesymbol.c

invalidsymol.o: invalidsymol.c
	gcc -c invalidsymol.c

intermediate.o: intermediate.c
	gcc -c intermediate.c


testBinary: testlist.c createlist.o createopcode.o createsymboltable.o validatesymbol.o invalidsymol.o intermediate.o  
	gcc  -o testBinary testlist.c  createopcode.o createlist.o createsymboltable.o validatesymbol.o invalidsymol.o intermediate.o 
