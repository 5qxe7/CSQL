#include "parser_handler.h"

struct HandlerResult handler_exit(char **strtok_r_saveptr, char *token) {
    // input is current token from the caller
    struct HandlerResult result = {0};
    result.result_status = HANDLE_EXIT;
    token = strtok_r(NULL, " ", strtok_r_saveptr);
    if(token){
        char *endptr;
        long number = strtol(token, &endptr, 0);
            if(endptr != token && *endptr == '\0') {
            result.exit_code = (int)number;
        }
    }

    return result;
    
}