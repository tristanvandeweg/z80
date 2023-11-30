#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exit_handler(int status){
    exit(status);
}

const char *inputFile;

int main(int argc, char **argv){
    
    for (size_t i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    for (size_t i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "--help") == 0)
        {
            printf("Help\n");
            exit_handler(0);
        }
        
    }
    

    return 0;
}