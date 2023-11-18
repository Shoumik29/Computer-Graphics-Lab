#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

void make_circle(int x, int y, int X, int Y){

    putpixel(X+x,Y+y,14);
    putpixel(X-x,Y+y,14);
    putpixel(X+x,Y-y,14);
    putpixel(X-x,Y-y,14);
    putpixel(Y+y,X+x,14);
    putpixel(Y-y,X+x,14);
    putpixel(Y+y,X-x,14);
    putpixel(Y-y,X-x,14);

    delay(100); //set to 100 for better view
}

void mid_point_circle(int X, int Y, int r){
    int x,y,p;
    x = 0;
    y = r;
    p = 1-r;

    while(x<y){
        x++;
        make_circle(x,y, X,Y);
        if(p<0) p = p+(2*x)+1;
        else{
            y--;
            p = p+(2*x)+1-(2*y);
        }
    }
}

int main(){
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");

    mid_point_circle(250,250, 200);

    getch();
    closegraph();
    return 0;
}
