#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char **argv) {

    int max1 = 0;  //one of the 3 largest calorie counts for a single elf, so far
    int max2 = 0;
    int max3 = 0;
    int elf = 0; //current elf index being measured
    int maxElf = 0; //The index of the largest caloried elf measured so far
    int current = 0; //Current elf being measured
    char line[150]; //String used to read one line of the file, can  hold up  to 150 characters
    char elfFilename[] = "elf-input-full.txt"; //the file name of our input
    printf("current number: %i\n", current);

    struct stat statFile;
    
    FILE * elfLog = fopen(elfFilename, "r");
    if (elfLog == NULL) {
        printf("File Read Error");
        return 0;
    }
    stat(elfFilename , &statFile);
    printf("File size is: %i\n", statFile.st_size);
    
    elf = 1;
    while( fgets(line, 150, elfLog) != NULL ) {
       if(line[0] == '\n') {
            if (current > max1) {
                maxElf = elf;
                max1 = current;
            }
            elf++;
            current = 0;
       }else{
            current += atoi(line);
            printf("Adding %i to current, total: %i , elf#: %i\n", atoi(line), current, elf);
       }
    }
    fclose(elfLog);
    
    printf("Now, max calories is: %i\n And the elf is: %i", max1, maxElf);
    return 0;
}