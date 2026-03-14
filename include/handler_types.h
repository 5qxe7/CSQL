#ifndef CSQL_HANDLER_TYPES_H
#define CSQL_HANDLER_TYPES_H


typedef enum {
    HANDLE_OK,
    HANDLE_ERR,
    HANDLE_EXIT,
    HANDLE_EMPTY,
} HandlerStatus;

struct HandlerResult {
    HandlerStatus result_status;
    int exit_code; // exit code for HANDLE_EXIT, disregard otherwise
    // later returns pointer to the resulting element in the db
};

#endif