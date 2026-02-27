#include "main.h"
#include "header.h"
#include "file_handler.h"
#include "input.h"

int main() {
    char* db_name = repl();
    printf("%s", db_name);
    
    int result = db_emplace(db_name).status;

    free(db_name);

    switch (result) {
        case 0:
            printf("%s", "SUCCESS\n");
            break;
        case 1:
            printf("%s", "IO_ERR\n");
            break;
    }

    

    return 0;
}