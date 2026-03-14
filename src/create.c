#include "create.h"
#include "parser_handler.h"
#include "file_handler.h"
#include <string.h>

struct HandlerResult create(char **strtok_r_saveptr, char *token) {
    struct HandlerResult result;
    token = strtok_r(NULL, " ", strtok_r_saveptr);
    if(!token) {
        result.result_status = HANDLE_EMPTY;
        return result;
    }

    if(strcmp(token, "DATABASE") == 0) {
        return db_emplace(strtok_r_saveptr, token);
    }
}