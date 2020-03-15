#include "stdafx.h"
using namespace std;

extern int maps(char *map,int n,char a);
extern int minimum(int *t,int n);

void Prim(int** graph, char* map,int n){
    //init
    int* P = (int*)malloc(sizeof(int)*n);
    int* l = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)    l[i]=MAX;
    P[0]=0;
    graph[0][0]=1;
    for(int i=1;i<n;i++)    //time clock
    {
        for(int j=0;j<n;j++)    //travel nodes
        {
            if(graph[j][j])  continue;  //node in (M-P)
            int* newp = (int*)malloc(sizeof(int)*i); 
            for(int k=0;k<i;k++){
                newp[k] = graph[P[k]][j];
                cout<<"i="<<i<<"\tj="<<j<<"\tk="<<k<<'\t'<<newp[k]<<endl;
            }
            l[j] = newp[minimum(newp,i)];
        }
        P[i]=minimum(l,n);
        // cout<<P[i]<<endl;
        l[P[i]]=MAX;
        graph[P[i]][P[i]]=1;
    }
    for(int i=0;i<n;i++){
        cout<<P[i]<<' ';
        graph[i][i]=0;
    }
}