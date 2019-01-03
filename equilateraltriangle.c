#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define ROUND(a) ((int)(a + 0.5))
#define PII 3.14

void triangle(int, int, int, int, int, int);
void rotation(int, int, int, int, int, int, float);
void dda(int, int, int, int);


int main()
{
    int gd = DETECT, gm;
    int x1, y1, x2, y2, x3, y3;
    initgraph(&gd, &gm, NULL);

    printf("The equilateral triangle has co-ordinates (330, 61), (250, 200) and (410, 200) and its centroid is (330, 154)\n");

    triangle(330,61,250,200,410,200);
    delay(1000);

    printf("The equilateral triangle should be rotated by an angle of 45 degrees.\n");

    rotation(330,61,250,200,410,200,-45);
    delay(2000);
}

void triangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
   dda(x1, y1, x2, y2);
   dda(x2, y2, x3, y3);
   dda(x3, y3, x1, y1);
}

void rotation(int x1, int y1, int x2, int y2, int x3, int y3, float angle)
{
    int p1, q1, p2, q2, p3, q3, xf = 330, yf = 154;

    angle = (angle * PII) / 180;

    p1 = xf + (x1 - xf)*cos(angle) - (y1 - yf)*sin(angle);
    q1 = yf + (x1 - xf)*sin(angle) + (y1 - yf)*cos(angle);
    p2 = xf + (x2 - xf)*cos(angle) - (y2 - yf)*sin(angle);
    q2 = yf + (x2 - xf)*sin(angle) + (y2 - yf)*cos(angle);
    p3 = xf + (x3 - xf)*cos(angle) - (y3 - yf)*sin(angle);
    q3 = yf + (x3 - xf)*sin(angle) + (y3 - yf)*cos(angle);
    triangle(p1, q1, p2, q2, p3, q3);
}

void dda(int xa, int ya, int xb, int yb)
{
    int dx, dy, steps, i;
    float xNext, yNext, x = xa, y = ya;

    dx = xb - xa;
    dy = yb - ya;
    if(abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);
    xNext = dx / float(steps);
    yNext = dy / float(steps);
    putpixel(ROUND(x),ROUND(y), RED);
    for(i = 1; i <= steps; i++)
    {
        x = x + xNext;
        y = y + yNext;
        putpixel(ROUND(x), ROUND(y), RED);
    }
}
