#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int mat1[9] = {10,20,30,40,50,60,70,80,90};
    int mat2[9] = {80,40,90,20,70,10,30,50,60};
    int matans[9];
    int i;
/*
    cout<<"Enter 9 elements for the first 3x3 matrix (row-wise):\n";
    for (i = 0; i < 9; i++)
        cin>>mat1[i];

    cout<<"Enter 9 elements for the second 3x3 matrix (row-wise):\n";
    for (i = 0; i < 9; i++)
        cin>>mat2[i];
*/
    matans[0] = mat1[0] * mat2[0] + mat1[1] * mat2[3] + mat1[2] * mat2[6];
    matans[1] = mat1[0] * mat2[1] + mat1[1] * mat2[4] + mat1[2] * mat2[7];
    matans[2] = mat1[0] * mat2[2] + mat1[1] * mat2[5] + mat1[2] * mat2[8];
    matans[3] = mat1[3] * mat2[0] + mat1[4] * mat2[3] + mat1[5] * mat2[6];
    matans[4] = mat1[3] * mat2[1] + mat1[4] * mat2[4] + mat1[5] * mat2[7];
    matans[5] = mat1[3] * mat2[2] + mat1[4] * mat2[5] + mat1[5] * mat2[8];
    matans[6] = mat1[6] * mat2[0] + mat1[7] * mat2[3] + mat1[8] * mat2[6];
    matans[7] = mat1[6] * mat2[1] + mat1[7] * mat2[4] + mat1[8] * mat2[7];
    matans[8] = mat1[6] * mat2[2] + mat1[7] * mat2[5] + mat1[8] * mat2[8];
    
    cout<<"The resultant 3x3 matrix is:\n";
    for (i = 0; i < 3; i++)
        cout<<matans[i]<<" ";
    cout<<endl;
    for (i = 3; i < 6; i++)
        cout<<matans[i]<<" ";
    cout<<endl;
    for (i = 6; i < 9; i++)
        cout<<matans[i]<<" ";

    return 0;
}