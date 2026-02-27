#include "input.h"
#include "heap_err.h"

char* repl() {
    while(1) {
        char* user_input = malloc(sizeof(char) * INIT_INPUT_BUFFER);
        char c = '\n';
        size_t iter = 0, cbuf = INIT_INPUT_BUFFER; // cbuf = current buffer size
        while((c = getchar()) != '\n' && c != EOF) {
            if(iter == cbuf - 1) {
                char *tmp = realloc(user_input, cbuf * 2);
                if (!tmp) {
                    malloc_err();
                }
                user_input = tmp;
            }
            cbuf = cbuf * 2;
            user_input[iter] = c;
            iter++;
        }
        return user_input;
    }
}