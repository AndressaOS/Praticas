#include <iostream>
#include <vector>

using namespace std;

#define MAXN 100100

int n, a, b, componete[MAXN];
vector< int > aresta[MAXN];

void dfs(int id){
    componete[id] = -1;
    for(int i = 0; i < aresta[id].size(); i++){
        int v = aresta[id][i];
        if(componete[v] == 0){
            dfs(v);
        }
    }
}

int main(int argc, char** argv) {
   cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        aresta[a].push_back(b);
        aresta[b].push_back(a);
    }
    dfs(1);
    return 0;
}
