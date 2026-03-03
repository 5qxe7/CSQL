#include "input.h"
#include "heap_err.h"
#include "parser.h"

char* repl() {
    int running = 1;
    while(running) {
        char* user_input = malloc(sizeof(char) * INIT_INPUT_BUFFER);
        printf("%s", "hey");
        char c = '\n';
        size_t iter = 0, cbuf = INIT_INPUT_BUFFER; // cbuf = current buffer size
        while((c = getchar()) != '\n' && c != EOF) {
            if(iter == cbuf) {
                char *tmp = realloc(user_input, cbuf * 2);
                if (!tmp) {
                    malloc_err();
                }
                user_input = tmp;
                cbuf = cbuf * 2;
            }
            user_input[iter] = c;
            iter++;
        }
        struct ParseResult result = parse(user_input);
        free(user_input);
        // break off execution later
        switch (result.status) {
            case PARSE_OK:
                printf("%s", "SUCCESS!\n");
                break;
            case PARSE_ERR:
                printf("%s", "FAIL!\n");
                break;
            case PARSE_EXIT:
                printf("%s %d %c", "Exitted with code", result.exit_code, '\n');
                running = 0;
                break;
            case PARSE_EMPTY:
                printf("%c", '\n');
                break;
        }
    }
}
