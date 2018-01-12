CFLAGS = -std=c99 -Wall -pedantic -g -Iinclude -c


build: main.o BinarySearchTreeAPI.o BSTFunctions.o assistantFunctions.o addRemoveRule.o rule.o testBuild
	gcc bin/main.o bin/BinarySearchTreeAPI.o bin/BSTFunctions.o bin/assistantFunctions.o bin/addRemoveRule.o bin/rule.o -o bin/runMe 

testBuild: testMain.o BinarySearchTreeAPI.o BSTFunctions.o assistantFunctions.o addRemoveRule.o rule.o
	gcc bin/testMain.o bin/BinarySearchTreeAPI.o bin/BSTFunctions.o bin/assistantFunctions.o bin/addRemoveRule.o bin/rule.o -o bin/runTests

testMain.o:
	gcc $(CFLAGS) src/testMain.c -o bin/testMain.o

main.o:
	gcc $(CFLAGS) src/main.c -o bin/main.o

BinarySearchTreeAPI.o:
	gcc $(CFLAGS) src/BinarySearchTreeAPI.c -o bin/BinarySearchTreeAPI.o

BSTFunctions.o:
	gcc $(CFLAGS) src/BSTFunctions.c -o bin/BSTFunctions.o

assistantFunctions.o:
	gcc $(CFLAGS) src/assistantFunctions.c -o bin/assistantFunctions.o

addRemoveRule.o:
	gcc $(CFLAGS) src/addRemoveRule.c -o bin/addRemoveRule.o

rule.o:
	gcc $(CFLAGS) src/rule.c -o bin/rule.o

clean:
	rm -f build testBuild *.o* *.a* *.gch

