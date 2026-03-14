#ifndef CSQL_PARSER_HANDLER_H
#define CSQL_PARSER_HANDLER_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h> // <<-temp
#include "create.h"
#include "handler_types.h"

typedef struct HandlerResult (*func_ptr)(char **strtok_r_saveptr, char *token);

struct HandlerResult create (char **strtok_r_saveptr, char *token);

struct HandlerResult handler_exit(char **strtok_r_saveptr, char *token);

struct Handler {
    char *name;
    func_ptr ptr;
};

static struct Handler Handlers[] = {
    //{"SELECT", },
    {"CREATE", create},
    {"EXIT", handler_exit},
};

#endif