#include "stdafx.h"
using namespace std;

void _init(int** graph, char* map,int n){
    graph = (int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        graph[i] = (int*)malloc(sizeof(int)*n);
    }
    map = (char*)malloc(sizeof(char*)*n);

    for(int i=0;i<n;i++){
        map[i]=0;
        for(int j=0;j<n;j++)    graph[i][j]=MAX;
        graph[i][i]=0;
    }    

    cout<<"graph init success!"<<endl;  
}