#include<bits/stdc++.h>
using namespace std;
#include<list>
class Node{
    public:
    string name;
    list<string> nbrs;
    Node(string name){
        this->name=name;
    }
};
class Graph{
    unordered_map<string, Node*> mp;
    public:
        Graph(vector<string> cities){
            for(auto city:cities){
                mp[city]= new Node(city);
            }
        }
        void addEdge(string x, string y, bool undir=false){
            mp[x]->nbrs.push_back(y);
            if(undir){
                mp[y]->nbrs.push_back(x);
            }

        }
        void print(){
            for(auto cityPair: mp){
                auto city=cityPair.first;
                Node *node=cityPair.second;
                cout<<city<<"->";
                for(auto nbr:node->nbrs){
                    cout<<nbr<<",";
                }
                cout<<endl;
            }
        }
};

int main(){
    vector<string> cities={"Delhi","London","Paris","New York"};
    Graph g(cities);
    g.addEdge("Delhi","London");
    g.addEdge("New York","London");
    g.addEdge("Delhi","Paris");
    g.addEdge("Paris","New York");
    g.print();
    return 0;

}