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

int main()
{
    initializeCanvas();
    displayCanvas();

    return 0;
}
