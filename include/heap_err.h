#ifndef CSQL_HEAP_ERR_H
#define CSQL_HEAP_ERR_H

#include <stdio.h>
#include <stdlib.h>

void malloc_err() {
    printf("%s", "FATAL: Failed to initialize string with malloc");
    exit(1);
}

#endif