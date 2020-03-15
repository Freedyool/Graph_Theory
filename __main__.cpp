#include "stdafx.h"
using namespace std;

extern void _init(int** graph, char* map,int n);
extern void add_edges(int** graph, char* map,int n);
extern void Dijkstra(int** graph, char* map,int n);
extern void Floyd(int** graph, char* map,int n);
extern void Prim(int** graph, char* map,int n);

int main(){
    int n;  
    int **graph;
    char *map;
    string temp;
    
    cout<<"please enter the quantity of nodes:"<<endl;
    cin>>n;
    
    _init(graph,map,n);
    
    cout<<"please enter the edges like 'AB=1' for example:(use '#' to end entering)"<<endl;

    add_edges(graph,map,n);
    
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


int maps(char *map, int n, char a){
    int i;
    for(i=0;i<n;i++){
        if(map[i]==a)   
            return i;
        if(map[i]==0)
        {
            map[i]=a;
            return i;  
        } 
    }
    return -1;
}

int minimum(int *t,int n){
    int i,num=MAX;
    for(i=0;i<n;i++){
        num=(t[i]<num)?t[i]:num;
    }
    while(t[--i]!=num);
    return i;
}

int string_to_int(string s){
    int num = 0;
    for(int i=s.size()-4;i>=0;i--){
        num+=(s[s.size()-i-1]-48)*pow(10,i);
    }
    return num;
}
