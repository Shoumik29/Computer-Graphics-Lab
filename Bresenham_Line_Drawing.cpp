#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

void bresenham_line(int x1, int y1, int x2, int y2){
    if(x2<x1){
        swap(x1,x2);
        swap(y1,y2);
    }

    int dx, dy;
    dx = x2-x1;
    dy = y2-y1;
    int p = (2*dy)-dx;

    //Printing two end points
    setcolor(10);
    putpixel(x1,y1,15);
    circle(x1,y1,3);
    putpixel(x2,y2,15);
    circle(x2,y2,3);

    //Printing the line
    while(x1<=x2){
        x1++;
        if(p<0) p = p+(2*dy);
        else{
            y1++;
            p = p+(2*(dy-dx));
        }
        putpixel(x1,y1,15);
        delay(1);
    }
}

int main(){
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");

    bresenham_line(23, 90, 500, 105 ); //500, 105, 3, 200 jhamela wala test case

    getch();
    closegraph();
    return 0;
}
