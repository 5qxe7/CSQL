#ifndef CSQL_FILE_HANDLER_H
#define CSQL_FILE_HANDLER_H

#include <string.h>
#include <stdlib.h>
#include "handler_types.h"

struct HandlerResult db_emplace(char **strtok_r_saveptr, char *token);
void create_table (char **strtok_r_saveptr, char *token);

struct ParseTableData {
    
};

#endif