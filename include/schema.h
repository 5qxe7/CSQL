#ifndef CSQL_SCHEMA_H
#define CSQL_SCHEMA_H

#include "header.h"

#define MAX_VARCHAR_LENGTH 255
#define MAX_COLUMN_NAME 64
#define MAX_TABLE_NAME 64
#define MAX_COLUMNS 32
#define PAGE_HEADER_SIZE 16

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_VARCHAR
} ColumnType;

struct Column {
    char name[MAX_COLUMN_NAME];
    ColumnType type;
    uint16_t max_length; //relevant for varchar later
};

struct TableSchema {
    char name[MAX_TABLE_NAME];
    uint8_t column_count;
    struct Column columns[MAX_COLUMNS];
};

typedef enum {
    PAGE_CATALOG,
    PAGE_DATA,
    PAGE_FREE,
} PageType;

struct PageHeader {
    PageType type;
    char table_name[MAX_TABLE_NAME];
    uint16_t row_count;
    uint16_t free_space;
};

#endif