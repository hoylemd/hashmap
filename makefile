all : test_hashmap

hashmap.o : hashmap.h hashmap.c
	gcc hashmap.c -c -o hashmap.o

test_hashmap : main.c hashmap.h hashmap.o
	gcc hashmap.o main.c -o test_hashmap

test : test_hashmap
	./test_hashmap

