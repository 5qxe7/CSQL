#include "parser.h"
#include "file_handler.h"
#include "header.h"
#include "parser_handler.h"

struct ParseResult parse(char *input) {
    struct ParseResult result;
    result.status = PARSE_EMPTY;
    result.exit_code = 0;

    char *strtok_r_saveptr;
    char *token = strtok_r(input, " ", &strtok_r_saveptr);

    struct HandlerResult handler_result;

    while(token != NULL) { // main parser loop
        printf("%s", "in parser body\n");
        for (size_t i = 0; i < sizeof(Handlers) / sizeof(Handlers[0]); i++) {
            if(strcmp(token, Handlers[i].name) == 0) {
                handler_result = Handlers[i].ptr(strtok_r_saveptr, input);
                strtok_r_saveptr = handler_result.saveptr_new;
                break;
            }
        };
        token = strtok_r(NULL, " ", &strtok_r_saveptr);
        printf("%s %s", "object pointed to: ", strtok_r_saveptr);
    }
    if(handler_result.result_status == HANDLE_EXIT) {
        result.status = PARSE_EXIT;
        result.exit_code = handler_result.exit_code;
    }
    return result;
}