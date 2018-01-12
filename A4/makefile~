CFLAGS = -std=c99 -Wall -pedantic -g -Iinclude -c


build: main.o dictionaryFunctions.o LinkedListAPI.o HashTableAPI.o modifyDictionary.o hashData.o hashFunction.o testBuild
	gcc bin/main.o bin/dictionaryFunctions.o bin/LinkedListAPI.o bin/HashTableAPI.o bin/modifyDictionary.o bin/hashData.o bin/hashFunction.o -o bin/runMe 

testBuild: testMain.o dictionaryFunctions.o LinkedListAPI.o HashTableAPI.o modifyDictionary.o hashData.o hashFunction.o 
	gcc bin/testMain.o bin/dictionaryFunctions.o bin/LinkedListAPI.o bin/HashTableAPI.o bin/modifyDictionary.o bin/hashData.o bin/hashFunction.o -o bin/runTests

testMain.o:
	gcc $(CFLAGS) src/testMain.c -o bin/testMain.o

main.o:
	gcc $(CFLAGS) src/main.c -o bin/main.o

modifyDictionary.o:
	gcc $(CFLAGS) src/modifyDictionary.c -o bin/modifyDictionary.o

LinkedListAPI.o:
	gcc $(CFLAGS) src/LinkedListAPI.c -o bin/LinkedListAPI.o

HashDataAPI.o:
	gcc $(CFLAGS) src/HashTableAPI.c -o bin/HashTableAPI.o

hashData.o:
	gcc $(CFLAGS) src/hashData.c -o bin/hashData.o

hashFunction.o:
	gcc $(CFLAGS) src/hashFunction.c -o bin/hashFunction.o

dictionaryFunctions.o:
	gcc $(CFLAGS) src/dictionaryFunctions.c -o bin/dictionaryFunctions.o

HashTableAPI.o:
	gcc $(CFLAGS) src/HashTableAPI.c -o bin/HashTableAPI.o

clean:
	rm -f build testBuild *.o* *.a* *.gch

