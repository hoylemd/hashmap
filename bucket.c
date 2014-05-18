#include "bucket.h"

Bucket * newBucket(char * new_key, char * value_type, void * value) {
    Bucket * the_new_bucket = (Bucket *) malloc(sizeof (Bucket));

    // populate the key
    the_new_bucket->key = new_key;
    the_new_bucket->key_length = strlen(new_key);

    // popuate the value indicator
    the_new_bucket->value_type = value_type;
    the_new_bucket->value_type_length = strlen(value_type);

    // populate the value
    the_new_bucket->value = value;

    // populate the next pointer
    the_new_bucket->next_bucket = NULL;

    return the_new_bucket;
}

// destructor
Bucket * freeBucket(Bucket * bucket) {
    return NULL;
}

