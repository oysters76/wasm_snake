#include <stdlib.h>
#include <stdio.h> 
#include <time.h>

#define WIDTH 20 
#define MULT 20 
#define WORLD_HEIGHT 400 
#define WORLD_WIDTH 400 
#define HEIGHT 20 

typedef struct {
    int x, y;
} Point;

Point food = {0};

int is_width_within_world(int x){
    return (x*MULT < WORLD_WIDTH); 
}

int is_height_within_world(int y){
    return (y*MULT < WORLD_HEIGHT);
}

void place_food(){
    int x = rand() % WIDTH; 
    while(!is_width_within_world(x)){
        x = rand() % WIDTH; 
    }
    int y = rand() % HEIGHT; 
    while(!is_height_within_world(y)){
        y = rand() % HEIGHT; 
    }
    food.x = x; 
    food.y = y; 
}


int main(void){
    srand(time(NULL));
    int x = rand() % WIDTH;
    printf("%d\n", x); 
    place_food();

    printf("%d : %d\n", food.x, food.y);

}

