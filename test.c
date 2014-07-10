#include "bucket.h"
#include "hashmap.h"

#include <stdio.h>
#include <string.h>

/* shorthand constructor for the first test bucket */
Bucket * firstTestBucket() {
    char * test_key = "thing";
    char * test_value = "This is a string";
    return newBucket(test_key, "string", (void *)test_value, strlen(test_value));
}

/* shorthand constructor for the second test bucket */
Bucket * secondTestBucket() {
    char * test_key = "potato";
    char * test_value = "This is a different string";
    return newBucket(test_key, "string", (void *)test_value, strlen(test_value));
}

/* shorthand constructor for the third test bucket */
Bucket * thirdTestBucket() {
    char * test_key = "pikachu";
    char * test_value = "Pika pika piiiii";
    return newBucket(test_key, "string", (void *)test_value, strlen(test_value));
}

/* test for creation and destruction */
int bucketCreationTests() {
    int passing = 1;
    char * test_key = "thing";
    char * test_value = "This is a string";
    /* bucket test variables */
    Bucket * test_bucket = NULL;

    /* test the bucket constructor */
    if (passing) {
        test_bucket = firstTestBucket();

        /* check the values */
        if (strncmp(test_bucket->key, test_key, test_bucket->key_length)) {
            passing = 0;
            fprintf(stderr, "bucket key is incorrect: '%s', expected '%s'\n",
                test_bucket->key, test_key);
        }

        /* check the values */
        if (strncmp((char *)test_bucket->value, test_value, strlen(test_value))) {
            passing = 0;
            fprintf(stderr, "bucket value is incorrect: '%s', expected '%s'\n",
                (char *)test_bucket->value, test_value);
        }


        if (passing) {
            printf("bucket constructed successfully\n");
        }
    }

    /* check free */
    if (passing) {
        test_bucket = freeBucket(test_bucket);

        if (test_bucket) {
            passing = 0;
            fprintf(stderr, "bucket did not free successfully\n");
        }

        if (passing) {
            printf("bucket freed successfully\n");
        }
    }

    return passing;
}

/* tests for bucket accessing */
int testBucketAccessing() {
    Bucket * first = firstTestBucket();
    Bucket * second = secondTestBucket();
    Bucket * third = thirdTestBucket();
    int passing = 1;

    /* set up the list */
    first->next = second;
    second->next = third;

    /* test the accessor for the first one */
    if (bucketGet(first, "thing") != first) {
        passing = 0;
        fprintf(stderr, "bucket did not free successfully\n");
    }


    freeBucket(first);
    freeBucket(second);
    freeBucket(third);

    return passing;
}

int testBucket() {
    int passing = bucketCreationTests();

    return passing;
}

int main() {
    int passing = testBucket();

    return 0;
}
