#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int record[100][100] {0};
    float infectprob; // = (rand() % 101) / 100.0 ;
    int recoverytime = 5;
    int healthy = 0;
    int recovered = 0;
    int dead = 0;
    int infected = 0;
    int simulationlength = 30;
    int initinfected;
    float prob = 0;
    float worsenprob = 0; //(rand() % 101) / 100.0;
    int Width, Height;
    cout<<"Enter Grid Width: ";
    while (!(cin>>Width) || Width < 1 || Width > 100) {
        cin.clear();
        cin.ignore();
    }
    cout<<"Enter Grid Height: ";
    while (!(cin>>Height) || Height < 1 || Height > 100) {
        cin.clear();
        cin.ignore();
    }

    cout<<"Enter initial infected people: ";
    while (!(cin>>initinfected) || initinfected < 0 || initinfected > (Width * Height)) {
        cin.clear();
        cin.ignore();
    }
    int i;
    int j;
    int k;
    int severity;
    cout<<"Enter Infection Probability (0-1): ";
    while (!(cin>>infectprob) || infectprob < 0 || infectprob > 1.0) {
        cin.clear();
        cin.ignore();
    }

    cout<<"Enter Worsening Probability (0-1): ";
    while (!(cin>>worsenprob) || worsenprob < 0 || worsenprob > 1.0) {
        cin.clear();
        cin.ignore();
    }

    int Grid [100][100] {0};

    // for (i = 0; i < Height; i++) {
    //     for (j = 0; j < Width; j++) {
    //         if (Grid[i][j] == 0)
    //             cout<<".";
    //         else
    //             cout<<Grid[i][j];
    //     }
    //     cout<<endl;
    // }
    i = initinfected;
    while (i > 0){
        j = rand() % (Height);
        k = rand() % Width;
        severity = (rand() % 9) + 1;
        if (Grid[j][k] == 0) {
            Grid[j][k] = severity;
            record[j][k] = 0;
            i--;
        }
    }
    cout<<"\nInitial grid State\n";

    for (i = 0; i < Height; i++) {
        for (j = 0; j < Width; j++) {
            if (Grid[i][j] == 0)
                cout<<".";
            else
                cout<<Grid[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    for (i = 1; i <= simulationlength; i++) {
        for ( j = 0; j < Height; j++) {
            for ( k = 0; k < Width; k++){                         
                int MaxSeverity = 0;       
                if (Grid[j][k] == 0) {  
                    int InfectedNeighbor = 0;
                    if (j > 0 && Grid[j-1][k] > 0 && Grid[j-1][k] < 10){
                        InfectedNeighbor++;
                        MaxSeverity = max(MaxSeverity, Grid[j-1][k]);}
                    if (j < Height - 1 && Grid[j+1][k] > 0 && Grid[j+1][k] < 10){
                        InfectedNeighbor++;
                        MaxSeverity = max(MaxSeverity, Grid[j+1][k]);}                   
                    if (k > 0 && Grid[j][k-1] > 0 && Grid[j][k-1] < 10){
                        InfectedNeighbor++;
                        MaxSeverity = max(MaxSeverity, Grid[j][k-1]); }                       
                    if (k < Width - 1 && Grid[j][k+1] > 0 && Grid[j][k+1] < 10) {
                        InfectedNeighbor++;
                        MaxSeverity = max(MaxSeverity, Grid[j][k+1]); 
                    }                       
                    if (InfectedNeighbor > 1) {
                        prob = (rand() % 101) / 100.0;
                        if (prob <= infectprob) {
                            Grid[j][k] = MaxSeverity;
                            record[j][k] = 0;                        
                        }
                        continue;
                    }
                    if (InfectedNeighbor == 1) {
                        prob = (rand() % 101) / 100.0;
                        if (prob <= infectprob && MaxSeverity > 0) { 
                            Grid[j][k] = (rand() % (MaxSeverity) + 1);
                            record[j][k] = 0;
                        }
                        continue;
                    }
                }
                if (Grid[j][k] == -1 or Grid[j][k] == 10) 
                    continue;
                prob = (rand() % 101) / 100.0;
                if (prob <= worsenprob) {
                    if (Grid[j][k] <= 9 and Grid[j][k] > 0) {
                        Grid[j][k] += 1;
                        record[j][k] += 1;
                    }
                }
                else {
                    if (Grid[j][k] > 1) {
                        Grid[j][k] -= 1;
                        record[j][k] += 1;
                    }
                }
                if (record[j][k] == recoverytime) {
                    Grid[j][k] = -1;
                    record[j][k] = 0;
                }
                if (Grid[j][k] == 10 or Grid[j][k] == -1)
                    record[j][k] = 0;

            }
        }
        for (j = 0; j < Height; j++) {
            for (k = 0; k < Width; k++) {
                if (Grid[j][k] == 0)
                    healthy += 1;
                else if (Grid[j][k] == -1)
                    recovered += 1;
                else if (Grid[j][k] == 10)
                    dead += 1;
                else 
                    infected += 1;
            }
        }
        cout<<"Day "<<i<<": Healthy: "<<healthy<<", Infected: "<<infected<<", Recovered: "<<recovered<<", Dead: "<<dead<<endl;
        healthy = 0;
        infected = 0;
        dead = 0;
        recovered = 0;
    }

    cout<<"\nFinal Grid State:\n";
    for (j = 0; j < Height; j++) {
        for (k = 0; k < Width; k++) {
            if (Grid[j][k] == -1)
                cout<<"R";
            else if (Grid[j][k] == 0)
                cout<<".";
            else if (Grid[j][k] == 10)
                cout<<"X";
            else
                cout<<Grid[j][k];
        }
        cout<<endl;
    }

    return 0;
}