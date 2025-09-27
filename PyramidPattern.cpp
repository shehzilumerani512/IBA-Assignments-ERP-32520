#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int n;
    cout<<"Enter number of rows in pyramid pattern: ";
    cin>>n;

    for (int m = 1; m < n+1 ; m++) {
        for (int j = n-1; j >= m ; j--) {
            cout<<"  ";
        }
        for (int f = 1; f <= m ; f++) {
            cout<<f<<" ";
        }
        for (int k = 2; k <= m ; k++) {
            cout<<m-k+1<<" ";
        }
        cout<<"\n";

    }

/*    for (int i = 1; i < n+1 ; i++) {
        for (int k = 1; k <= i ; k++) {
            cout<<i-k+1<<" ";
        }
        cout<<"\n";
    }
*/
    return 0;
}