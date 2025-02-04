#include<bits/stdc++.h>
using namespace std;
#include<list>
class Graph{
    int V;
    list<int> *l;
    public:
        Graph(int v){
            V = v;
            l=new list<int>[V];
        }
        void addEdge(int i,int j, bool undir=true){
            l[i].push_back(j);
            if(undir){
                l[j].push_back(i);
            }
        }
    void bfs(int source,int dest=-1){
        queue<int> q;
        bool *visited=new bool[V]{0};
        int *shortestDist=new int[V]{0};
        int *parent=new int[V]{-1};
        q.push(source);
        visited[source]=true;
        while(!q.empty()){
            int f=q.front();
            cout<<f<<endl;
            q.pop();
            for(auto nbrs  : l[f]){
                if(!visited[nbrs]){
                    q.push(nbrs);
                    parent[nbrs]=f;
                    shortestDist[nbrs]=shortestDist[f]+1;
                    visited[nbrs]=true;
                }
            }
            
        }
        for(int i=0;i<V;i++){
            cout<<"Shortest distance to "<<i<<" is->"<<shortestDist[i]<<endl;;
        }
        if(dest!=-1){
            int temp=dest;
            while(temp!=source){
                cout<<temp<<"--";
                temp=parent[temp];
            }
            cout<<source<<endl;
        }

    }

    
};
int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);
    g.bfs(1,6);
    return 0;
}