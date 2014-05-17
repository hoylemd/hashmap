#include <stdlib.h>

typedef struct sBucket {
    char * key;
    int key_length;

    struct sBucket * nextBucket;

    void * value;

    char * value_type;
    int value_type_length;
} Bucket;
