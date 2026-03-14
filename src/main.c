#include "main.h"
#include "header.h"
#include "file_handler.h"
#include "input.h"

int main() {
    printf("CSQL VERSION %d\nENTER COMMANDS BELOW LINE BY LINE\n", VERSION);
    repl();
    
    return 0;
}