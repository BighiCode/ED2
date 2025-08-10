#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    srand(time(NULL));
    
    if(argc <= 2) {
        printf("Usage: %s <parametro> <valor>\n", argv[0]);
        return 1;
    }
    
    

    if(strcmp(argv[1], "-c") == 0) {
        FILE *f = fopen(argv[1]+1, "w");
        int n = atoi(argv[2]);
        for(int i = 1; i <= n; i++) {
            fprintf(f, "%d\n", i);

        }
        fclose(f);
    }

    if(strcmp(argv[1], "-d") == 0) {
        FILE *f = fopen(argv[1]+1, "w");
        int n = atoi(argv[2]);
        for(int i = n; i > 0; i--) {
            fprintf(f, "%d\n", i);

        }
        fclose(f);
    }

    if(strcmp(argv[1], "-r") == 0) {
        FILE *f = fopen(argv[1]+1, "w");

        int n = atoi(argv[2]);
        
        for(int i = 1; i <= n; i++) {
            int r = rand() % n + 1;
            fprintf(f, "%d\n", r);

        }
        fclose(f);
    }
    
    return 0;
}