
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int N = 1000010;
int n, m;

struct Edge {
    int x, y;

    Edge() {}

    Edge(int x_, int y_):
        x(x_), y(y_) {}
};

vector<Edge> adj[N];
int in[N], out[N];
int seen[N];
int t; /* Current time */

/* Is x an ancestor of y in DFS tree */
bool isAncector(int x, int y) {
    return (in[x] < in[y] && out[y] < out[x]);
}

bool isForwardEdge(int x, int y) {
    return isAncector(x, y);
}

bool isBackEdge(int x, int y) {
    return isAncector(y, x);
}

bool isCrossEdge(int x, int y) {
    if(isForwardEdge(x, y) || isBackEdge(x, y))
        return false;
    return true;
}

void listBackEdges(void) {
    for(int i = 0; i < n; i++)
        for(auto e: adj[i]) if(isBackEdge(i, e.y))
            cout << "(" << (i + 1) << " " << (e.y + 1) << ")" << endl;
}

void listForwardEdges(void) {
    for(int i = 0; i < n; i++)
        for(auto e: adj[i]) if(isForwardEdge(i, e.y))
            cout << "(" << (i + 1) << " " << (e.y + 1) << ")" << endl;
}

void listCrossEdges(void) {
    for(int i = 0; i < n; i++)
        for(auto e: adj[i]) if(isCrossEdge(i, e.y))
            cout << "(" << (i + 1) << " " << (e.y + 1) << ")" << endl;
}

void dfs(int x) {
    in[x] = t++;
    seen[x] = 1;
    for(auto e: adj[x])
        if(seen[e.y] == 0)
            dfs(e.y);
    out[x] = t++;
}

int main( void ) {

    /* Read graph */
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y;

        cin >> x >> y;
        x -= 1, y -= 1;
        adj[x].push_back(Edge(x, y));
    }

    dfs(0);

    cout << "Forward edges:" << endl;
    listForwardEdges();

    cout << "Back edges:" << endl;
    listBackEdges();

    cout << "Cross edges:" << endl;
    listCrossEdges();

    return 0;
}
