#include "stdafx.h"
#include "func.cpp"
#include "include.h"
#include "Init.cpp"
#include "AddEdges.cpp"
#include "Dijkstra.cpp"
#include "Floyd.cpp"
#include "Prim.cpp"
using namespace std;

int main(){
    int n;  
    int **graph;
    char *map;
    string temp;

    cout<<"please enter the quantity of nodes:"<<endl;
    cin>>n;

    graph = (int**)malloc(sizeof(int*)*n);
    for(int i=0;i<n;i++){
    graph[i] = (int*)malloc(sizeof(int)*n);
    }
    map = (char*)malloc(sizeof(char*)*n);
    
    Init(graph,map,n);
    
    cout<<"please enter the edges like 'AB=1' for example:(use '#' to end entering)"<<endl;

    AddEdges(graph,map,n);
    
    cout<<endl<<"select mode you want:"<<endl<<"Dijkstra[1]"<<'\t'<<"Floyd[2]"<<endl<<"Prim[3]"<<endl<<"quit[q]"<<endl;

    while(cin>>temp){
        if(temp=="1")   //Dijkstra  
        {
            Dijkstra(graph,map,n);
            
        }

        else if(temp=="2")  //Floyd 
        {
            Floyd(graph,map,n);
        }

        else if(temp=="3")  //Prim
        {
            Prim(graph,map,n);
        }

        else if(temp=="q")
        {
            break;
        }

        else
        {
            cout<<"please check out your entering"<<endl;
        }
        
        cout<<endl<<"select mode you want:"<<endl<<"Dijkstra[1]"<<'\t'<<"Floyd[2]"<<endl<<"Prim[3]"<<endl<<"quit[q]"<<endl;
        
    }

    return 0;

}