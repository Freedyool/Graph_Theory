#include <iostream>
#include <string>
#include <cmath>
#define MAX 9999
using namespace std;

int maps(char *map,int n,char a);
int minimum(int *t,int n);
int string_to_int(string s);

void _init(int** graph, char* map,int n);
void add_edges(int** graph, char* map,int n);
void Dijkstra(int** graph, char* map,int n);
void Floyd(int** graph, char* map,int n);
void Prim(int** graph, char* map,int n);

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

void add_edges(int** graph, char* map,int n){
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
        cout<<"ok ";
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

void Dijkstra(int** graph, char* map,int n){
    string temp;
    int* P=(int*)malloc(sizeof(int)*n); //deposit nodes in (P)
    int* l=(int*)malloc(sizeof(int)*n); //indicator(指标)
    int* fl=(int*)malloc(sizeof(int)*n); //final_indicator(指标)
    int* Pro=(int*)malloc(sizeof(int)*n);   //front node

    cout<<"please enter the start node:"<<endl;
    while(cin>>temp)
    {
        int start=maps(map,n,temp[0]);
        if(start==-1)  {
            cout<<"entering error! pleease try again"<<endl;
            continue;
        }

        //init
        for(int i=0;i<n;i++){
            l[i]=MAX;
            fl[i]=MAX;
            Pro[i]=i;
        }
        P[0]=start;
        fl[start]=0;
        graph[start][start]=1;

        for(int i=1;i<n;i++)    //time clock
        {
            for(int j=0;j<n;j++)    //travel nodes
            {
                if(graph[j][j])  continue;  //node in (M-P)
                int* newp = (int*)malloc(sizeof(int)*i); 
                for(int k=0;k<i;k++){
                    newp[k] = fl[P[k]]+graph[P[k]][j];
                    // cout<<"i="<<i<<"\tj="<<j<<"\tk="<<k<<'\t'<<newp[k]<<endl;
                }
                Pro[j] = P[minimum(newp,i)];
                l[j] = newp[minimum(newp,i)];
            }
            P[i]=minimum(l,n);
            // cout<<P[i]<<endl;
            fl[P[i]]=l[P[i]];
            l[P[i]]=MAX;
            graph[P[i]][P[i]]=1;
        }

        for(int i=0;i<n;i++)    graph[i][i]=0;

        break;
    }
    
    cout<<"please enter the end node:"<<endl;
    while(cin>>temp)
    {
        int index=maps(map,n,temp[0]);
        if(index==-1)  {
            cout<<"entering error"<<endl;
            continue;    
        }
        cout<<"the shortest length is:"<<fl[index]<<endl;
        cout<<"the shortest path is:"<<map[index];
        do{
            if(index==Pro[index])
            break;
            index = Pro[index];
            cout<<"<-"<<map[index];
        }while(index!=P[0]);
        break;
    }
    
    free(P);free(l);free(fl);free(Pro);

}

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