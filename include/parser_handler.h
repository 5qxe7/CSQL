#ifndef CSQL_PARSER_HANDLER_H
#define CSQL_PARSER_HANDLER_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h> // <<-temp


typedef struct HandlerResult (*func_ptr)(char *strtok_r_saveptr, char *token);

struct HandlerResult db_emplace (char *strtok_r_saveptr, char *token);

struct HandlerResult handler_exit(char *strtok_r_saveptr, char *token);

struct Handler {
    char *name;
    func_ptr ptr;
};

static struct Handler Handlers[] = {
    {"SELECT", },
    {"CREATE", db_emplace},
    {"EXIT", handler_exit},
};

typedef enum {
    HANDLE_OK,
    HANDLE_ERR,
    HANDLE_EXIT,
    HANDLE_EMPTY,
} HandlerResult;

struct HandlerResult {
    HandlerResult result_status;
    int exit_code; // exit code for HANDLE_EXIT, disregard otherwise
    char *saveptr_new;
    // later returns pointer to the resulting element in the db
};

#endif