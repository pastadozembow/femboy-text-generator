#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int randNum = 0;

char* getFemboyWord(){
    FILE *file = fopen("femboyWords.txt", "r"); 
    if (file == NULL) {
        printf("Error opening file.\n");
        return "err 1";
    }
        
    char line[256];
    int currentLine = 1;
    char *message = (char*)malloc(256 * sizeof(char));

    randNum = 1 + (rand() % 8);
    while (fgets(line, sizeof(line), file)) {
        if (currentLine == randNum) {
            if (message != NULL) {
                strcpy(message, line);
            }
            fclose(file);
            return message;
        }
        currentLine++;
    }
    
    return "err 2"; 
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return 1;
    }
    srand(time(NULL));

    int ammount = atoi(argv[1]);
    for(int i = 1; i <= ammount; i++){
        char *word = getFemboyWord();
        printf("\033[38;5;5m");
        printf("%s", word);
        printf("\033[0m");
        free(word);
    }
    return 0;
}