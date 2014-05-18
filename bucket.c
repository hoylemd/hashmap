#include "bucket.h"

Bucket * newBucket(char * key, char * value_type, void * value, unsigned int size) {
    Bucket * the_new_bucket = (Bucket *) malloc(sizeof (Bucket));

    /* populate the key*/
    the_new_bucket->key = key;
    the_new_bucket->key_length = strlen(key);

    /* popuate the value indicator*/
    the_new_bucket->value_type = value_type;
    the_new_bucket->value_type_length = strlen(value_type);

    /* populate the value*/
    the_new_bucket->value = value;
    the_new_bucket->size = size;

    /* populate the next pointer*/
    the_new_bucket->next_bucket = NULL;

    return the_new_bucket;
}

/* destructor*/
Bucket * freeBucket(Bucket * bucket) {
    return NULL;
}

