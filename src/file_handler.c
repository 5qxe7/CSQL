#include "header.h"
#include "file_handler.h"


struct DbEmplaceResult db_emplace (char *db_name) {
    //create header and write flags to file
    struct DbHeader header;
    strcpy(header.magic, "csql");
    header.version = VERSION;
    header.page_size = PAGE_SIZE;
    header.endianness = DEFAULT_ENDIANNESS;
    memset(header.reserved, 0, FLAG_RESERVE_SIZE);

    FILE *file = fopen(db_name, "wb");
    // DbEmplaceResult returns only one item right now
    // Struct decision for expandibility
    if(!file) {
        struct DbEmplaceResult result_struct;
        result_struct.status = DB_ERR_FILE;
        return result_struct;
    };

    fwrite(&header, sizeof(header), 1, file);
    fclose(file);

    struct DbEmplaceResult result_struct;
    result_struct.status = DB_OK;
    return result_struct;
}