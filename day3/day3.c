#include <stdio.h>
#include <stdlib.h>

int countVisited(int ** grid, int grid_size){
    int visited = 0;
    for(int row = 0; row < grid_size; row++){
        for(int col = 0; col < grid_size; col++){
            if(grid[row][col] > 0)
                visited++;
        }
    }
    return visited;
}

int main(){

    FILE * inputFile = fopen("day3Input.txt", "r");
    int ** grid;
    int maxsize = 2048;
    size_t linesize = 2048;
    char * moves = (char*)malloc(maxsize * sizeof(char));
    int x, y, robo_x, robo_y, num_moves, is_santa = 1;
    char cur;

    //get moves string
    if((num_moves = getline(&moves, &linesize, inputFile)) < 0){
        printf("num_moves=%d\n", num_moves);
        printf("returning from getline\n");
        return -1;
    }

    grid = (int**)malloc(2*num_moves * sizeof(int*));
    for(int i=0; i<2*num_moves; i++)
    {
        grid[i] = (int*)malloc(2*num_moves * sizeof(int));
    }
    
    //starting location in middle
    x = y = robo_x = robo_y = num_moves;
    grid[x][y] = 1;

    /*
    //Part 1 Grid Fill
    for(int i=0; i<num_moves; i++){
        cur = moves[i];
        if(cur == '^')
            x += 1;
        if(cur == 'v')
            x -= 1;
        if(cur == '>')
            y += 1;
        if(cur == '<')
            y -= 1;
        grid[x][y] += 1;
    }
    */

    //Part 2 Grid Fill
    for(int i=0; i < num_moves; i++){
        cur = moves[i];
        if(cur == '^'){
            is_santa ? x++ : robo_x++;
        }
        if(cur == 'v'){
            is_santa ? x-- : robo_x--;
        }
        if(cur == '>'){
            is_santa ? y++ : robo_y++;
        }
        if(cur == '<'){
            is_santa ? y-- : robo_y--;
        }
        is_santa ? grid[x][y]++ : grid[robo_x][robo_y]++;
        is_santa = !is_santa;
    }

    //printf("part 1 solution %d\n", countVisited(grid, 2*num_moves));
    printf("part 2 solution %d\n", countVisited(grid, 2*num_moves));

    //free grid
    for(int i=0; i<2*num_moves; i++)
        free(grid[i]);
    free(grid);

    return 0;
}
