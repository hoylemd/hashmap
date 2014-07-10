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
    the_new_bucket->next = NULL;

    return the_new_bucket;
}

/* destructor*/
Bucket * freeBucket(Bucket * bucket) {
    bucket->key = NULL;
    bucket->value_type = NULL;
    bucket->value = NULL;
    bucket->next = NULL;

    free(bucket);

    return NULL;
}

/* accessor */
Bucket * bucketGet(Bucket * bucket, char * key) {
    Bucket * current_bucket = bucket;
    int len = strlen(key);

    while (current_bucket) {
        /* check length first */
        if (len - current_bucket->key_length == 0) {
            /* check the key */
            if (strncmp(key, current_bucket->key, len) == 0) {
                return current_bucket;
            }
        }
        current_bucket = current_bucket->next;
    }

    return NULL;
}
