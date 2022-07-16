#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//total surface area of prisim plus slack equal to smallest side
int getPaperArea(int l, int w, int h){
    //calculate side area
    int side_one = l*w;
    int side_two = l*h;
    int side_three = w*h;
    //figure out smallest size to get slack paper
    if(side_one <= side_two && side_one <= side_three){
        return 3*side_one + 2*side_two + 2*side_three;
    }
    else if (side_two <= side_three){
        return 2*side_one + 3*side_two + 2*side_three;
    }
    else {
        return 2*side_one + 2*side_two + 3*side_three;
    }
}

//length of shortest side perimiter plus slack equal to volume
int getRibbonLength(int l, int w, int h){
    int perim;
    //figure out longest side to get slack
    if(l >= w && l >= h){
        perim = 2*w + 2*h;
    }
    else if (w >= h){
        perim = 2*l + 2*h;
    }
    else {
        perim = 2*l + 2*w;
    }
    return perim + l*w*h;
}

int main(){

    FILE * inputFile = fopen("day2Input.txt", "r");
    size_t linesize = 16;
    char * curline;
    int l, w, h, totalPaper = 0, totalRibbon = 0;

    curline = (char*)malloc(sizeof(char*)*linesize);

    while(getline(&curline, &linesize, inputFile) >= 0){

        l = atoi(strtok(curline, "x")); 
        w = atoi(strtok(NULL, "x"));
        h = atoi(strtok(NULL, "x"));
        totalPaper += getPaperArea(l, w, h);
        totalRibbon += getRibbonLength(l, w, h);
    }

    printf("part 1 solution %d\n", totalPaper); 
    printf("part 2 solution %d\n", totalRibbon);
    free(curline);
    return 0;
}


