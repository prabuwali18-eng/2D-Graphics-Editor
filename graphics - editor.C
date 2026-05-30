#include <stdio.h>
#include <math.h>

#define ROWS 10
#define COLS 20

char canvas[ROWS][COLS];

void initializeCanvas()
{
    for(int i=0;i<ROWS;i++)
       for(int j=0;j<COLS;j++)
          canvas[i][j]='_';

}
void displayCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        printf("%c",canvas[i][j]);
        printf("\n");
    }
}
void drawPoint(int row,int col)
{
    if(row >=0 && row < ROWS && col >= 0 && col < COLS)
      canvas[row][col]='*';
}
void drawHorizontalLine(int row)
{
    for(int col=0;col < COLS;col++)
    {
        canvas[row][col] = '*';
    }
}
void drawRectangle(int row,int col,int height,int width)
{
    for(int i=row;i<row + height;i++)
    {
        for(int j=col;j<col + width;j++)
        {
            if(i >= 0 && i < ROWS && j >= 0 && j < COLS)
            {
                if(i == row || i == row + height - 1 ||
                   j == col || j == col + width - 1)
                   {
                    canvas[i][j] = '*';
                   }
            }
        }
    }
}
int main()
{
    initializeCanvas();
    drawPoint(2,5);
    drawHorizontalLine(4);
    drawRectangle(2,3,5,10);
    displayCanvas();

    return 0;
}
