#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

//Defining the window
int xMin = 120, xMax = 500, yMin = 100, yMax = 350;

// Assigning region code
int Left = 1, Right = 2, Bottom = 4, Top = 8;

//Defining region code
int region_code(int x, int y){
    int code = 0;
    if(x<xMin) code = code|Left;
    else if(x>xMax) code = code|Right;
    if(y<yMin) code = code|Bottom;
    else if(y>yMax) code = code|Top;
    return code;
}

void cohen_sutherland(int x1, int y1, int x2, int y2){

    int code1 = region_code(x1, y1);
    int code2 = region_code(x2, y2);
    bool inside = false;

    int x,y;
    while(true){
        if(!(code1|code2)){
            inside = true;
            break;
        }
        else if(code1&code2) break;
        else if(!(code1&code2)){
            int code;
            if(code1) code = code1;
            else code = code2;

            if(code&Top){
                y = yMax;
                x = x1+(x2-x1)/(y2-y1)*(y-y1);
            }
            else if(code&Bottom){
                y = yMin;
                x = x1+(x2-x1)/(y2-y1)*(y-y1);
            }
            else if(code&Left){
                x = xMin;
                y = y1+(y2-y1)/(x2-x1)*(x-x1);
            }
            else if(code&Right){
                x = xMax;
                y = y1+(y2-y1)/(x2-x1)*(x-x1);
            }
            if(code==code1){
                x1 = x;
                y1 = y;
                code1 = region_code(x1,y1);
            }
            else{
                x2 = x;
                y2 = y;
                code2 = region_code(x2,y2);
            }
        }
    }
    if(inside){
        rectangle(xMin, yMin, xMax, yMax);
        setcolor(14);
        line(x1, y1, x2, y2);
    }
}

int main(){
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");

    while(true){
        cohen_sutherland(100, rand() % 1000, 700, 400);
        delay(5);
    }

    getch();
    closegraph();
    return 0;
}
