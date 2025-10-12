#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int grid_y, grid_x;
    float x, y;
    string character = "*";
    float maxX;
    cout<<"Enter Maximum Value of x ";
    while (!(cin>>maxX) || maxX <= 0){
        cin.clear();
        cin.ignore();
    }
    float minX = -maxX;
    int maxY = 1;
    int minY = -1;
    x = minX;
    string xaxis, yaxis;
    int grid_width = 80;
    int grid_height = 20;
    string grid[20][80];
    for (int i = 0; i < 20; ++i)
        for (int j = 0; j < 80; ++j)
            grid[i][j] = ' ';
    for (int i = 0; i < 80; i++)
        grid[grid_height/2][i] = "-";
    for (int i = 0; i < 20; i++)
        grid[i][grid_width/2] = "|";

    for (; x <= maxX;) {
        y = sin(-x);
        grid_x = round(((x - minX) / (maxX - minX)) * (grid_width-1));
        grid_y = round(((y - minY) / (maxY - minY)) * (grid_height-1));
        x += 0.05;
        grid [grid_y][grid_x+1] = character;
    }

    for(int i = 0; i < 20; i++){
        for (int j = 0; j < 80; j++)
            cout<<grid[i][j];
        cout<<endl;
    }
    return 0;
}