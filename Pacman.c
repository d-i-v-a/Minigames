#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

#define arr_size 8 
#define player 'C'
#define food '+'
#define nullpoint '.'

char arr[arr_size][arr_size]; //2D ARRAY created called arr

int cood_X,cood_Y,point; // defined the x and y coordinates

//start_array is a function defined which creates the pacman playing field with the given number of rows and columns given by the user
//for the Question presented to us, the arr_size is 8 and it creates a 8x8 grid for the pacman to move in.
void start_array(){
    for(int rows=0;rows<arr_size;rows++){
        for(int column=0;column<arr_size;column++){
            arr[rows][column]=nullpoint;
        }
    }

//Here, the "srand(time(NULL))" function is called here in order to generate new variables each time it is called
//The point is incremented, if the food is collected by the pacman, then the number remains same else the space where it moves is empty then the food item which was incremented would go back 
    srand(time(NULL));
    for(int i=0;i<arr_size * arr_size/4;i++){
        int rows = rand() % arr_size;
        int column = rand() % arr_size;
        if(arr[rows][column] != food){
            arr[rows][column] = food;
        }else{
            i--;
        }
    }
//this updates the pacman to the center of the grid
    cood_Y=arr_size/2;
    cood_X=arr_size/2;
    arr[cood_Y][cood_X]= player;
}

// display function is used to store the points and display it on top of the grid
void display(){
    printf("total points earned : %d \n",point);
    for(int rows = 0;rows<arr_size;rows++){
        for(int column = 0;column<arr_size;column++){
            printf("%c", arr[rows][column]);
        }
        printf("\n");
    }
}

// new_pos function is used to ask the user where to move the pacman
void new_pos(char move){
    int newcood_X= cood_X;
    int newcood_Y= cood_Y;
    switch(move){
        case 'U':
            newcood_Y--;
            break;
        case 'u':
            newcood_Y--;
            break;
        case 'D':
            newcood_Y++;
            break;
        case 'd':
            newcood_Y++;
            break;
        case 'R':
            newcood_X++;
            break;
        case 'r':
            newcood_X++;
            break;
        case 'L':
            newcood_X--;
            break;
        case 'l':
            newcood_X--;
            break;
    }
    //food collected increases the points stored by 1
    if(newcood_X >=0 && newcood_X<arr_size && newcood_Y >=0 && newcood_Y < arr_size){
        if(arr[newcood_Y][newcood_X] == food){
            point++;
        }
        arr[cood_Y][cood_X] = nullpoint;
        cood_X = newcood_X;
        cood_Y = newcood_Y;
        arr[cood_Y][cood_X] = player;
    }
}

int main(){
    start_array();
    display();
    char a;
    while(true){
        printf("enter the direction to move to U/D/R/L");
        scanf(" %c", &a);
        new_pos(a);
        display();
        if(point == arr_size * arr_size / 4){
            printf("WINNER.GAME OVER \n");
            break;
        }
    }
    return 0 ;
    
}


