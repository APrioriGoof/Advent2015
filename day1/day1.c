#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE * inputFile = fopen("day1Input.txt", "r");
    int upCount = 0;
    int downCount = 0;
    int firstBasement = 0;
    char cur;

    while((cur = (char) fgetc(inputFile)) != EOF) {
        if(cur == '(') {
            upCount++;
        }
        else if(cur == ')') {
            downCount++;
        }
        if(upCount - downCount < 0 && firstBasement == 0){
            firstBasement = upCount + downCount;
        }
    }
    
    printf("part 1 solution: %d\n", upCount - downCount);
    printf("part 2 solution: %d\n", firstBasement);
    fclose(inputFile);
    return 0;
}
