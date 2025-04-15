#include <cs50.h>
#include <stdio.h>

int main(void){
    int height;
    do{
        height = get_int("Enter hight here:");
    }
    while(height < 1 || height > 8);

    for(int row = 0; row < height; row++){
        for(int space = 0; space < height - row - 1;space++){
            printf(" ");
        }
        for(int column = 0; column <= row; column++){
            printf("#");
        }
        printf("#");
    }
}
