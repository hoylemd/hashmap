#include "bucket.h"
#include "hashmap.h"

#include <stdio.h>
#include <string.h>

int main() {
    int passing = 1;
    char * test_key = "thing";
    char * test_value = "This is a string";

    if (passing) {
        /* bucket test variables */
        Bucket * test_bucket = NULL;

        /* test the bucket constructor */
        test_bucket = newBucket(test_key, "string", (void *)test_value, strlen(test_value));

        /* check the values */
        if (strncmp(test_bucket->key, test_key, test_bucket->key_length)) {
            passing = 0;
            fprintf(stderr, "bucket key is incorrect: '%s', expected '%s'\n", test_bucket->key, test_key);
        }

        /* check the values */
        if (strncmp((char *)test_bucket->value, test_value, strlen(test_value))) {
            passing = 0;
            fprintf(stderr, "bucket value is incorrect: '%s', expected '%s'\n", (char *)test_bucket->value, test_value);
        }

        if (passing) {
            printf("bucket constructed successfully\n");
        }
    }

    return 0;
}
