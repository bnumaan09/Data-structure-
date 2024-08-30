#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int visited[N] = {0};
vector<int>adj_list[N];

void DFS(int node){
    cout<<node<<" ";
    visited[node] = 1;
    for(int adj_node: adj_list[node]){
        if(visited[adj_node] == 0){
            DFS(adj_node);
        }
    }

}

/*
6 6

0 1
1 2
2 3
2 4
4 5
1 5
*/
int main()
{

    int nodes,edge;
    cin>>nodes>>edge;

    for(int i = 0; i<edge; i++)
    {
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

    }

    int source = 0;
    DFS(source);

    return 0;
}

