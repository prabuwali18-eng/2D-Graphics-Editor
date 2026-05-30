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

        if(dx * dx + dy * dy <= radius * radius)
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
    int choice;

    initializeCanvas();
    do
    {
        printf("\n===== 2D Graphics Editor =====\n");
        printf("1. Draw Point\n");
        printf("2.Draw Line\n");
        printf("3. Draw Rectangle\n");
        printf("4. Draw Triangle\n");
        printf("5. Draw Circle\n");
        printf("6. Delete Point\n");
        printf("7. Modify Point\n");
        printf("8. Display Canvas\n");
        printf("9. EXit\n");
        printf("Enter choice:");
        scanf("%d",&choice);


    switch(choice)
    {
       case 1:
         drawPoint(2,5);
         displayCanvas();
         break;

       case  2:
         drawHorizontalLine(4);
         displayCanvas();
         break;

        case  3:
         drawRectangle(2,3,5,10);
         displayCanvas();
         break;

        case  4:
         drawTriangle(6,2,4);
         displayCanvas();
         break;

        case 5:
         drawCircle(5,15,2);
         displayCanvas();
         break;

        case 6:
         deletePoint(2,5);
         displayCanvas();
         break;

        case 7:
         modifyPoint(2,5,8,15);
         displayCanvas();
         
         break;

        case 8:
         displayCanvas();
         break;

        case 9:
          printf("Exiting...\n");
          break;
    }
    
}while(choice != 9);

    return 0;
}
