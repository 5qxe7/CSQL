#ifndef CSQL_PARSER_H
#define CSQL_PARSER_H

#include <string.h>
#include <stdio.h> //remove after testing

typedef enum {
    PARSE_OK,
    PARSE_ERR,
    PARSE_EXIT,
    PARSE_EMPTY,
} ParseStatus;

struct ParseResult {
    ParseStatus status;
    int exit_code;
};

struct ParseResult parse(char *arg);

#endif