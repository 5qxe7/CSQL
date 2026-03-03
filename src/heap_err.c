#include "heap_err.h"

void malloc_err() {
    printf("%s", "FATAL: Failed to initialize string with malloc");
    exit(1);
}