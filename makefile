CFLAGS=-Wall -pedantic
HEADERS=bucket.h hashmap.h
OBJECTS=bucket.o hashmap.o

all : test_hashmap

bucket.o : bucket.h bucket.c
	gcc -c -o bucket.o $(CFLAGS) bucket.c

hashmap.o : bucket.h hashmap.h hashmap.c
	gcc -c -o hashmap.o $(CFLAGS) hashmap.c

test_hashmap : main.c $(HEADERS) $(OBJECTS)
	gcc -o test_hashmap $(CFLAGS) $(OBJECTS) main.c

test : test_hashmap
	./test_hashmap

clean :
	rm -f *.o test_hashmap

