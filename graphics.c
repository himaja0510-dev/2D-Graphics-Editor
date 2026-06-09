#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 30
#define COLS 60

char canvas[ROWS][COLS];

void initializeCanvas()
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            canvas[i][j]='_';
        }
    }
 }

void displayCanvas()
{
    printf("\n");

    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

void drawRectangle(int x, int y, int width, int height)
{
    for(int i=y;i<y+height;i++)
    {
        for(int j=x;j<x+width;j++)
        {
            if(i>=0 && i<ROWS && j>=0 && j<COLS)
            {
                canvas[i][j] = '*';
            }
        }
    }
}


void drawLine(int x1, int y1, int x2, int y2)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (1)
    {
        if (x1 >= 0 && x1 < COLS &&
            y1 >= 0 && y1 < ROWS)
        {
            canvas[y1][x1] = '*';
        }

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}


void drawTriangle(int x,int y,int height)
{
    for(int i=0;i<height;i++)
    {
        for(int j=-i;j<=i;j++)
        {
            if(y+i<ROWS &&
               x+j>=0 &&
               x+j<COLS)
            {
                canvas[y+i][x+j] = '*';
            }
        }
    }
}


void drawCircle(int xc,int yc,int r)
{
    for(int y=0;y<ROWS;y++)
    {
        for(int x=0;x<COLS;x++)
        {
            int dx = x - xc;
            int dy = y - yc;

            if(dx*dx + dy*dy <= r*r)
            {
                canvas[y][x] = '*';
            }
        }
    }
}


void deleteArea(int x,int y,int width,int height)
{
    for(int i=y;i<y+height;i++)
    {
        for(int j=x;j<x+width;j++)
        {
            if(i>=0 && i<ROWS &&
               j>=0 && j<COLS)
            {
                canvas[i][j] = '_';
            }
        }
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n");
        printf("===== 2D GRAPHICS EDITOR =====\n");
        printf("1. Draw Rectangle\n");
        printf("2. Draw Line\n");
        printf("3. Draw Triangle\n");
        printf("4. Draw Circle\n");
        printf("5. Delete Area\n");
        printf("6. Modify Rectangle\n");
        printf("7. Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
            {
                initializeCanvas();

                int x,y,w,h;

                printf("Enter X Y Width Height: ");
                scanf("%d%d%d%d",&x,&y,&w,&h);

                drawRectangle(x,y,w,h);

                printf("\nRectangle:\n");
                displayCanvas();
                break;
            }

            case 2:
            {
                initializeCanvas();

                int x1,y1,x2,y2;

                printf("Enter X1 Y1 X2 Y2: ");
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

                drawLine(x1,y1,x2,y2);

                printf("\nLine:\n");
                displayCanvas();
                break;
            }

            case 3:
            {
                initializeCanvas();

                int x,y,h;

                printf("Enter CenterX StartY Height: ");
                scanf("%d%d%d",&x,&y,&h);

                drawTriangle(x,y,h);

                printf("\nTriangle:\n");
                displayCanvas();
                break;
            }

            case 4:
            {
                initializeCanvas();

                int x,y,r;

                printf("Enter CenterX CenterY Radius: ");
                scanf("%d%d%d",&x,&y,&r);

                drawCircle(x,y,r);

                printf("\nCircle:\n");
                displayCanvas();
                break;
            }

            case 5:
            {
                int x,y,w,h;

                initializeCanvas();

                printf("Enter X Y Width Height to delete: ");
                scanf("%d%d%d%d",&x,&y,&w,&h);

                deleteArea(x,y,w,h);

                printf("\nAfter Delete:\n");
                displayCanvas();
                break;
            }

            case 6:
            {
               initializeCanvas();

               int x,y,w,h;

               printf("Enter New X Y Width Height: ");
               scanf("%d%d%d%d",&x,&y,&w,&h);

               drawRectangle(x,y,w,h);

               printf("\nModified Rectangle:\n");
               displayCanvas();
               break;
            }


            case 7:
            {
                printf("Exiting Program....\n");
                return 0;

            }

            default:
            {
                printf("Invalid Choice!\n");
            }
        }
    }

    return 0;
}