#include "shell.h"

int main() 
{
    char str[] = "This,is,a sample string";
    char *token = _strtok(str, ",");

    while (token != NULL) {
        printf("%s\n", token);
        token = _strtok(NULL, ",");
    }

    return (0);
}
