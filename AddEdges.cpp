#include "stdafx.h"
using namespace std;

int string_to_int(string s){
    int num = 0;
    for(int i=s.size()-4;i>=0;i--){
        num+=(s[s.size()-i-1]-48)*pow(10,i);
    }
    return num;
}

void AddEdges(int** graph, char* map,int n){
    string temp;
    while(cin>>temp){

        if(temp=="#") break;
        
        if(temp[2]=='=')
        {
            int a = maps(map,n,temp[0]);
            int b = maps(map,n,temp[1]);

            if((a+1)*(b+1))
            {
                graph[a][b] = string_to_int(temp);
                graph[b][a] = string_to_int(temp);
            }
            else
            {
                cout<<a<<' '<<b<<endl;  //judge which node is in error
                cout<<"please check out your entering"<<endl;
            }
        }
        else
        {
            cout<<"please check out your entering"<<endl;
        }    
    }
    
    //show graph
    cout<<"adjacent matrix:"<<endl<<'\t';
    for(int i=0;i<n;i++)    cout<<map[i]<<'\t';
    for(int i=0;i<n;i++){
        cout<<endl<<'\v'<<map[i]<<'\t';
        for(int j=0;j<n;j++)
            cout<<graph[i][j]<<'\t';
    }
}