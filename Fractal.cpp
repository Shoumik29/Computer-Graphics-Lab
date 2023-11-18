#include <bits/stdc++.h>
#include <graphics.h>

using namespace std;

void draw_fractal(vector<pair<int, int>> points){
    for(int i=0;(i+1)<points.size();i++) line(points[i].first, points[i].second, points[i+1].first, points[i+1].second);
}

/*vector<pair<int,int>> trisection_points(int x1, int y1, int x2, int y2){
    vector<pair<int, int>> tri_points;
    tri_points.push_back({(x2+(2*x1))/3, (y2+(2*y1))/3});
    tri_points.push_back({(x1+(2*x2))/3, (y1+(2*y2))/3});
    return tri_points;
} kept this for the formula of tri section points*/

void snowflake(vector<pair<int, int>> fractal_points, int iteration){
    for(int j=0;j<iteration;j++){
        vector<pair<int, int>> tmp_vec;
        for(int i=0;(i+1)<fractal_points.size();i++){
            tmp_vec.push_back(fractal_points[i]);

            pair<int, int> tri_p1, tri_p2;
            tri_p1 = {(fractal_points[i+1].first+(2*fractal_points[i].first))/3,
                              (fractal_points[i+1].second+(2*fractal_points[i].second))/3};
            tri_p2 = {(fractal_points[i].first+(2*fractal_points[i+1].first))/3,
                              (fractal_points[i].second+(2*fractal_points[i+1].second))/3};

            tmp_vec.push_back(tri_p1);

            double angle = 60*M_PI/180;
            int x = tri_p1.first + (tri_p2.first-tri_p1.first)*cos(angle) + (tri_p2.second-tri_p1.second)*sin(angle);
            int y = tri_p1.second - (tri_p2.first-tri_p1.first)*sin(angle) + (tri_p2.second-tri_p1.second)*cos(angle);

            tmp_vec.push_back({x,y});

            tmp_vec.push_back(tri_p2);

            tmp_vec.push_back(fractal_points[i+1]);
        }
        fractal_points.clear();
        fractal_points = tmp_vec;
        tmp_vec.clear();
    }
    draw_fractal(fractal_points);
}

int main(){
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");

    vector<pair<int, int>> points = {{150,350}, {300,90}, {450,350}, {150,350}}; //{150,350}, {300,90}, {450,350}, {150,350} good sample
    snowflake(points, 6); //input 0 to see the initiator

    getch();
    closegraph;
    return 0;
}
