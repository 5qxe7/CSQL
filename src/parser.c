#include "parser.h"
#include "file_handler.h"
#include "header.h"

struct ParseResult parse(char *input) {
    struct ParseResult result;
    result.status = PARSE_ERR;
    result.exit_code = 0;

    char *strtok_r_saveptr;
    char *token = strtok_r(input, " ", &strtok_r_saveptr);
    
    while(token != NULL) { // main parser loop
        if(strcmp(token, "SELECT") == 0) {
            // TODO: handle select after file implementation is done
        }
        else if(strcmp(token, "CREATE") == 0) {
            token = strtok_r(NULL, " ", &strtok_r_saveptr);

            if(token != NULL && strcmp(token, "DATABASE") == 0) {
                token = strtok_r(NULL, " ", &strtok_r_saveptr);
                if(token != NULL) {
                    struct DbEmplaceResult emplace_result = db_emplace(token);
                    if(emplace_result.status == DB_OK) {
                        result.status = PARSE_OK;
                        return result;
                    }
                    continue;
                }
            result.status = PARSE_ERR;
        }
    }
        else if(strcmp(token, "EXIT") == 0) {
            token = strtok_r(NULL, " ", &strtok_r_saveptr);
            char *endptr; // required by strtol, points to the first char that couldn't be converted
            long code = strtol(token, &endptr, 10);
            if (!(endptr == token || *endptr != '\0' && token != NULL)) { // if endptr == token, that means endptr didnt advance (nothing was converted)
                result.exit_code = (int)code;
            }
            result.status = PARSE_EXIT;
            return result;
        }
        else {
            // for now non-matching statements will be considered empty, handle unrecognized syntax later
            result.status = PARSE_EMPTY;
            return result;
        }
    }
    token = strtok_r(NULL, " ", &strtok_r_saveptr); // advance to next token
}