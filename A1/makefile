CFLAGS = -std=c99 -Wall -pedantic -g -Iinclude -c

build: main.o simulation.o carList.o car.o
	gcc bin/main.o bin/simulation.o bin/carList.o bin/car.o  -o bin/runMe 

main.o:
	gcc $(CFLAGS) src/main.c -o bin/main.o

simulation.o:
	gcc $(CFLAGS) src/simulation.c -o bin/simulation.o

carList.o:
	gcc $(CFLAGS) src/carList.c -o bin/carList.o

car.o:
	gcc $(CFLAGS) src/car.c -o bin/car.o

clean:
	rm -f build *.o* *.a* *.gch

