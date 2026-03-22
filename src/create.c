#include "create.h"
#include "parser_handler.h"
#include "file_handler.h"
#include "schema.h"
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
    } else if (strcmp(token, "TABLE") == 0) {
        token = strtok_r(NULL, " ", strtok_r_saveptr);
        if(!token) {
            result.result_status = HANDLE_EMPTY;
            return result;
        }
        // create_table();
        struct TableSchema schema;
        strcpy(schema.name, token);
        schema.column_count = 0;

        while(token != NULL) {
            struct Column column = {0};
            printf("token: %s\n", token);
            if(strcmp(token, "INT") == 0) {
                ColumnType column_type = TYPE_INT;
                column.type = column_type;
                token = strtok_r(NULL, " ", strtok_r_saveptr);
                if(!token) {
                    result.result_status = HANDLE_EMPTY;
                    break;
                }
                strcpy(column.name, token);
                schema.columns[schema.column_count] = column;
                schema.column_count++;
                printf("%s, %d", column.name, column_type);
            } else if (strcmp(token, "FLOAT") == 0) {
                ColumnType column_type = TYPE_FLOAT;
                column.type = column_type;
                token = strtok_r(NULL, " ", strtok_r_saveptr);
                if(!token) {
                    result.result_status = HANDLE_EMPTY;
                    break;
                }
                strcpy(column.name, token);
                schema.columns[schema.column_count] = column;
                schema.column_count++;
                printf("%s, %d", column.name, column_type);
            } else if (strcmp(token, "VARCHAR") == 0) {
                ColumnType column_type = TYPE_VARCHAR;
                column.type = column_type;
                token = strtok_r(NULL, " ", strtok_r_saveptr);
                if(!token) {
                    result.result_status = HANDLE_EMPTY;
                    break;
                }
                strcpy(column.name, token);
                schema.columns[schema.column_count] = column;
                schema.column_count++;
                printf("%s, %d", column.name, column.type);
            }
            token = strtok_r(NULL, " ", strtok_r_saveptr);
        }

        
        result.result_status = HANDLE_OK;
        return result;
    }
}