#include <stdio.h>
#include <stdlib.h>
#define _GNU_SOURCE
#include <string.h>

int main(int argc, char *argv[]){
    FILE *fp;

	if(argc > 1){
		printf("%s\n", argv[1]);
		fp = fopen(argv[1], "r");
		
		if (fp == NULL){
			perror("file open");
			exit(-1);
		}
	}

	char *line1 = NULL, *line2 = NULL, *cur = NULL;
    size_t size = 0;
ssize_t chars_read;
    

    while(getline(&cur, &size, fp) != EOF){
        if (line2){
            free(line2);
        }
        line2 = line1;
        line1 = strdup(cur);

        if (line1 == NULL) {
            perror("Error duplicating line");
            exit(-1);
        }

    }
        if (line2){
            printf("%s", line2);  
        }
        if (line1) {
            printf("%s\n", line1);  
        }
        free(cur);
        free(line1);
        free(line2);
        fclose(fp);
}
