#include "bucket.h"
#include "hashmap.h"

#include <stdio.h>
#include <string.h>

int test_bucket() {
    int passing = 1;
    char * test_key = "thing";
    char * test_value = "This is a string";
    /* bucket test variables */
    Bucket * test_bucket = NULL;

    /* test the bucket constructor */
    if (passing) {
        test_bucket = newBucket(test_key, "string", (void *)test_value, strlen(test_value));

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

int main() {
    int passing = test_bucket();

    return 0;
}
