#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

void draw_poly(vector<int> points){
    for(int i=0;(i+3)<points.size();i+=2) line(points[i], points[i+1], points[i+2],points[i+3]);
}

void rotation(vector<int>& poly_points, double angle, int clock, int pivot_x, int pivot_y){

    angle = angle*M_PI/180;

    for(int i=0;(i+1)<poly_points.size();i+=2){
        //clockwise
        int x,y;
        x = poly_points[i] - pivot_x;
        y = poly_points[i+1] - pivot_y;
        if(clock){
            poly_points[i] = pivot_x + (x*cos(angle) - y*sin(angle));
            poly_points[i+1] = pivot_y + (x*sin(angle) + y*cos(angle));
        }
        else{
            poly_points[i] = pivot_x + (x*cos(angle) + y*sin(angle));
            poly_points[i+1] = pivot_y + (-x*sin(angle) + y*cos(angle));
        }
    }
}

void scale(vector<int>& poly_points, double sfx, double sfy){
    for(int i=0;(i+1)<poly_points.size();i+=2){
        poly_points[i] = poly_points[i] * sfx;
        poly_points[i+1] = poly_points[i+1] * sfy;
    }
}

void translate(vector<int>& poly_points, int tx, int ty){
  for(int i=0;(i+1)<poly_points.size();i+=2){
        poly_points[i] = poly_points[i] + tx;
        poly_points[i+1] = poly_points[i+1] + ty;
    }
}

int main(){
    int gd = DETECT, gmode;
    initgraph(&gd, &gmode, "");

    vector<int> poly_points = {100, 100, 100, 200, 200, 200, 200, 100, 100, 100};  //pivot 200,200

    setcolor(WHITE);
    draw_poly(poly_points);
    int clock = 1; //1 clockwise, 0 anti clockwise
    double angle = 120;
    int pivot_x = 200, pivot_y = 200;

    rotation(poly_points, angle, clock, pivot_x, pivot_y);
    scale(poly_points, .5, .5);
    translate(poly_points, 200, 200);

    setcolor(YELLOW);
    draw_poly(poly_points);

    getch();
    closegraph();
    return 0;
}
