#include "header.h"
#include "parser_handler.h"

struct HandlerResult db_emplace (char *strtok_r_saveptr, char *token) {
    //create header and write flags to file
    struct DbHeader header;
    strcpy(header.magic, "csql");
    header.version = VERSION;
    header.page_size = PAGE_SIZE;
    header.endianness = DEFAULT_ENDIANNESS;
    memset(header.reserved, 0, FLAG_RESERVE_SIZE);

    char *db_name = strtok_r(token, " ", NULL);
    if(!token) {
        exit(0);
    }

    FILE *file = fopen(db_name, "wb");
    // DbEmplaceResult returns only one item right now
    // Struct decision for expandibility
    if(!file) {
        struct HandlerResult result_struct;
        result_struct.result_status = HANDLE_ERR;
        return result_struct;
    };

    fwrite(&header, sizeof(header), 1, file);
    fclose(file);

    struct HandlerResult result_struct;
    result_struct.result_status = HANDLE_OK;
    return result_struct;
}