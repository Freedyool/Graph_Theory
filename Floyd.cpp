#include "stdafx.h"
using namespace std;

extern int maps(char *map,int n,char a);

void Floyd(int** graph, char* map,int n){
    //init
    string temp;
    int **d = (int**)malloc(sizeof(int*)*n);
    int **r = (int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
        d[i] = (int*)malloc(sizeof(int)*n);
        r[i] = (int*)malloc(sizeof(int)*n);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j]=graph[i][j];
            r[i][j]=j;
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][k]+d[k][j]<d[i][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    r[i][j]=r[i][k];
                }
            }
        }
    }

    cout<<"please enter two nodes (example:'AB'):"<<endl;
    while(cin>>temp){
        int a = maps(map,n,temp[0]);
        int b = maps(map,n,temp[1]);
        if((a+1)*(b+1))
        {
            cout<<"the shortest length is:"<<d[a][b]<<endl;
            cout<<"the shortest path is:";
            do{
                cout<<map[a]<<"->";
                a=r[a][b];
            }while(a!=b);
            cout<<map[a]<<endl;
            break;
        }
        else
        {
            cout<<a<<' '<<b<<endl;  //judge which node is in error
            cout<<"please check out your entering"<<endl;
            continue;
        } 
        break;
    }

    for(int i=0;i<n;i++){
        free(d[i]);
        free(r[i]);
    }
    free(d);free(r);
}