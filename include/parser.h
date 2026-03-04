#ifndef CSQL_PARSER_H
#define CSQL_PARSER_H

#include <string.h>
#include <stdio.h> //remove after testing
#include <stdbool.h>

typedef enum {
    PARSE_OK,
    PARSE_ERR,
    PARSE_EXIT,
    PARSE_EMPTY,
} ParseStatus;

struct ParseResult {
    ParseStatus status;
    long exit_code;
};

struct ParseResult parse(char *arg);

#endif