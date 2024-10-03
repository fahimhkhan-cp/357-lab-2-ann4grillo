#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

    int i;

    if (argc > 1){
        for (i = 0; i < argc; i++){
            if (argv[i][0] == 45){
                printf("%s\n", argv[i]);
            }
        }
    }
    return 0;
 
}