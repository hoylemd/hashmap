HEADERS=bucket.h hashmap.h
OBJECTS=bucket.o hashmap.o

all : test_hashmap

bucket.o : bucket.h bucket.c
	gcc bucket.c -c -o bucket.o

hashmap.o : bucket.h hashmap.h hashmap.c
	gcc hashmap.c -c -o hashmap.o

test_hashmap : main.c $(HEADERS) $(OBJECTS)
	gcc $(OBJECTS) main.c -o test_hashmap

test : test_hashmap
	./test_hashmap

clean :
	rm -f *.o test_hashmap

