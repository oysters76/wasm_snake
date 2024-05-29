#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 20
#define WORLD_WIDTH 400 
#define WORLD_HEIGHT 400 
#define MULT 20 

typedef struct {
    float x, y;
} Point;

typedef struct {
    Point pos;
    Point dir;
    int size; 
} Snake;

Snake snake;
Point food;
int game_over;


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


void init_game() {
    srand(time(NULL));
    snake.pos.x = WIDTH / 4;
    snake.pos.y = HEIGHT / 4;
    snake.dir.x = 1;
    snake.dir.y = 0;
    place_food();
    game_over = 0;
    snake.size = 1; 
}

void update_game() {
    snake.pos.x += snake.dir.x;
    snake.pos.y += snake.dir.y;

    // Check for collisions with walls
    if (snake.pos.x < 0 || snake.pos.x >= WIDTH || snake.pos.y < 0 || snake.pos.y >= HEIGHT) {
        game_over = 1;
    }

    // Check for collisions with food
    if (snake.pos.x == food.x && snake.pos.y == food.y) {
        place_food();
        snake.size++;
    }
}

void set_direction(int x, int y) {
    snake.dir.x = x;
    snake.dir.y = y;
}

int get_snake_x() { return snake.pos.x; }
int get_snake_y() { return snake.pos.y; }
int get_food_x() { return food.x; }
int get_food_y() { return food.y; }
int is_game_over() { return game_over; }
int get_snake_size() { return snake.size; }
