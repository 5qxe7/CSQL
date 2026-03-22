#include "header.h"
#include "parser_handler.h"

struct HandlerResult db_emplace (char **strtok_r_saveptr, char *token) {
    //create header and write flags to file
    struct DbHeader header;
    strcpy(header.magic, "csql");
    header.version = VERSION;
    header.page_size = PAGE_SIZE;
    header.endianness = DEFAULT_ENDIANNESS;
    memset(header.reserved, 0, FLAG_RESERVE_SIZE);
    struct HandlerResult result;

    if(!token) {
        result.result_status = HANDLE_ERR;
        return result;
    }
    char *db_name = strtok_r(NULL, " ", strtok_r_saveptr);
    
    FILE *file = fopen(db_name, "wb"); 
    // DbEmplaceResult returns only one item right now
    // Struct decision for expandibility
    if(!file) {
        result.result_status = HANDLE_ERR;
        return result;
    };

    fwrite(&header, sizeof(header), 1, file);
    fclose(file);

    result.result_status = HANDLE_OK;
    return result;
}

void create_table (char **strtok_r_saveptr, char *token) { // change from void later, declared in file_handler.h
    
}