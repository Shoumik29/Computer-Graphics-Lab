#include <bits/stdc++.h>
#include <graphics.h>
#define eps 0.00005

using namespace std;

int factorial(int n){
    if(n==0) return 1;
    return n * factorial(n-1);
}

double ncr(int n, int k){
    return factorial(n)/(factorial(k) * factorial(n-k));
}

double bezier_blending_function(double u, int k, int n){
    return ncr(n,k) * pow(u,k) * pow((1-u),(n-k));
}

void bezier_curve(vector<pair<int, int>> cp){
    //Printing the control points
    for(auto val: cp){
        putpixel(val.first, val.second, 15);
        setcolor(10); //changing the color
        circle(val.first, val.second, 5);
    }
    //Printing the curve
    int n = cp.size()-1;
    for(double u=0; u<=1; u+=eps){
        double x=0, y=0;
        for(int i=0;i<=n;i++){
            double bez = bezier_blending_function(u,i,n);
            x = x + cp[i].first * bez;
            y = y + cp[i].second * bez;
        }
        putpixel(x,y,15);
        //delay(1);
    }
}

int main(){
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");

    vector<pair<int, int>> cp = {{27, 243}, {101, 47}, {324, 197}, {437, 23}};
    bezier_curve(cp);

    getch();
    closegraph();
    return 0;
}
