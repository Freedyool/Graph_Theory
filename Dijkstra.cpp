#include "stdafx.h"
using namespace std;

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
