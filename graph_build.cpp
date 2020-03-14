/*
the default generation type is undirected weighted graph
you can choose directed weighted graph by commenting `code in line:70` 
*/
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

#define MAX 9999

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

int string_to_int(string s){
    int num = 0;
    for(int i=s.size()-4;i>=0;i--){
        num+=(s[s.size()-i-1]-48)*pow(10,i);
    }
    return num;
}

int main(){
    
    cout<<"please enter the quantity of nodes:"<<endl;
    int n;
    int **graph;
    char *map;
    cin>>n;

    //_init_
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
    cout<<"please enter the edges like 'AB=1' for example:(use '#' to end entering)"<<endl;

    //edge_adding
    string s;
    while(cin>>s){
        if(s=="#") break;
        
        if(s[2]=='=')
        {
            int a = maps(map,n,s[0]);
            int b = maps(map,n,s[1]);
            if((a+1)*(b+1))
            {
                graph[a][b] = string_to_int(s);
                graph[b][a] = string_to_int(s);   //comment out this line of code then you can build an undirected graph
            }
            else
            {
                cout<<a<<' '<<b<<endl;  //judge which node is in error
                cout<<"please check out your entering"<<endl;
            }
        }
        else
        {
            cout<<"please check out your entering2"<<endl;
        }    
    }

    cout<<"adjacent matrix:"<<endl<<'\t';
    for(int i=0;i<n;i++)    cout<<map[i]<<'\t';
    for(int i=0;i<n;i++){
        cout<<endl<<map[i]<<'\t';
        for(int j=0;j<n;j++)
            cout<<graph[i][j]<<'\t';
    }
    
    return 0;

}
