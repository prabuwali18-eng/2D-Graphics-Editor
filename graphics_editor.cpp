#include <iostream>
using namespace std;

const int ROWS =10;
const int COLS=20;

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
        cout << canvas[i][j];
        cout <<endl;
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
void drawTriangle(int row,int col,int height)
{
    for(int i = 0;i < height;i++)
    {
        for(int j = 0;j <= i;j++)
        {
            canvas[row + i][col + j] = '*';
            }
    }
}
void drawCircle(int centerRow,int centerCol,int radius)
{
   for(int i = 0;i < ROWS;i++)
   {
    for(int j = 0;j < COLS;j++)
    {
        int dx = i - centerRow;
        int dy = j - centerCol;

        if(dx * dx + dy <= radius * radius)
        {
            canvas[i][j] = '*';
        }

    }
   } 
}
void deletePoint(int row,int col)
{
    if(row >= 0 && row < ROWS && col >= 0 && col < COLS)
    {
        canvas[row][col] = '_';
    }
}
void modifyPoint(int oldRow,int oldCol,int newRow,int newCol)
{
    deletePoint(oldRow,oldCol);
    drawPoint(newRow,newCol);

}


int main()
{
    initializeCanvas();

    drawPoint(2,5);
    drawHorizontalLine(4);

    drawRectangle(2,3,5,10);

    drawTriangle(6,2,4);
    drawCircle(5,15,2);

    deletePoint(2,5);
    modifyPoint(2,5,8,15);

    displayCanvas();

    return 0;
}
