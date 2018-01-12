CFLAGS = -std=c99 -Wall -pedantic -g -Iinclude -c

build: main.o simulation.o LinkedListAPI.o patient.o addPatients.o PQueueAPI.o 
	gcc bin/main.o bin/simulation.o bin/LinkedListAPI.o bin/patient.o bin/addPatients.o bin/PQueueAPI.o -o bin/runMe

testBuild: testMain.o LinkedListAPI.o patient.o addPatients.o simulation.o PQueueAPI.o 
	gcc bin/testMain.o bin/simulation.o bin/LinkedListAPI.o bin/patient.o bin/addPatients.o bin/PQueueAPI.o -o bin/runTests

testMain.o:
	gcc $(CFLAGS) src/testMain.c -o bin/testMain.o

main.o:
	gcc $(CFLAGS) src/main.c -o bin/main.o

simulation.o:
	gcc $(CFLAGS) src/simulation.c -o bin/simulation.o

LinkedListAPI.o:
	gcc $(CFLAGS) src/LinkedListAPI.c -o bin/LinkedListAPI.o

patient.o:
	gcc $(CFLAGS) src/patient.c -o bin/patient.o

addPatients.o:
	gcc $(CFLAGS) src/addPatients.c -o bin/addPatients.o

PQueueAPI.o:
	gcc $(CFLAGS) src/PQueueAPI.c -o bin/PQueueAPI.o

clean:
	rm -f build testBuild *.o* *.a* *.gch

