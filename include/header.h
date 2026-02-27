#ifndef CSQL_DB_HEADER_H
#define CSQL_DB_HEADER_H

#include <stdint.h>
#include <stdio.h>

#define MAGIC_SIZE 5
#define PAGE_SIZE 4096
#define VERSION 1
#define DEFAULT_ENDIANNESS 0
#define FLAG_RESERVE_SIZE 15
#define EMPLACE_RESULT_SIZE 5

typedef enum { DB_OK, DB_ERR_FILE } DbStatus;

struct DbHeader {
    char magic[MAGIC_SIZE];
    uint16_t version;
    uint32_t page_size;
    uint8_t endianness;
    uint8_t reserved[FLAG_RESERVE_SIZE];
};

struct DbEmplaceResult {
    DbStatus status;
};

#endif