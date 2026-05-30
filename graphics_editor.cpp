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

int main()
{
    initializeCanvas();

    drawPoint(2,5);

    displayCanvas();

    return 0;
}
