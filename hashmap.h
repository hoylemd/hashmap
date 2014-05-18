#ifndef HASHMAP_H
#define HASHMAP_H

/* include the bucket type*/
#include "bucket.h"

/* define the structure*/
typedef struct sHashmap {
    Bucket** bucket_array;
    int buckets;
} Hashmap;

#endif /* HASHMAP_H */

