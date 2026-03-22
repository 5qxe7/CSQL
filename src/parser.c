#include "parser.h"
#include "file_handler.h"
#include "header.h"
#include "parser_handler.h"
#include "create.h"

struct ParseResult parse(char *input) {
    struct ParseResult result;
    result.status = PARSE_EMPTY;
    result.exit_code = 0;
    char *strtok_r_saveptr;
    char *token = strtok_r(input, " ", &strtok_r_saveptr);

    struct HandlerResult handler_result;

    while(token != NULL) { // main parser loop
        for (size_t i = 0; i < sizeof(Handlers) / sizeof(Handlers[0]); i++) {
            if(strcmp(token, Handlers[i].name) == 0) {
                handler_result = Handlers[i].ptr(&strtok_r_saveptr, input);
                break;
            }
        };
        token = strtok_r(NULL, " ", &strtok_r_saveptr);
    }
    if(handler_result.result_status == HANDLE_EXIT) {
        result.status = PARSE_EXIT;
    } else if (handler_result.result_status == HANDLE_OK) {
        result.status = PARSE_OK;
    } else if (handler_result.result_status == HANDLE_ERR) {
        result.status = HANDLE_ERR;
    } else {
        result.status = HANDLE_EMPTY;
    }
    return result;
}