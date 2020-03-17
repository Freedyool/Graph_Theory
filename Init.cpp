#include "stdafx.h"
using namespace std;

void Init(int** graph, char* map,int n){
    
    for(int i=0;i<n;i++){
        map[i]=0;
        for(int j=0;j<n;j++)    graph[i][j]=MAX;
        graph[i][i]=0;
    }    

    cout<<"graph init success!"<<endl;  
}