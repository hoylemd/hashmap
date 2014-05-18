#ifndef BUCKET_H
#define BUCKET_H

/* include standard libraries*/
#include <stdlib.h>
#include <string.h>

/* define the structure*/
typedef struct sBucket {
    /* key*/
    char * key;
    int key_length;

    /* value indicator*/
    char * value_type;
    int value_type_length;

    /* value*/
    void * value;

    /* pointer to the next bucket*/
    struct sBucket * next_bucket;
} Bucket;

/* constructor*/
Bucket * newBucket(char * new_key, char * value_type, void * value);

/* destructor*/
Bucket * freeBucket(Bucket * bucket);

#endif /*BUCKET_H*/
