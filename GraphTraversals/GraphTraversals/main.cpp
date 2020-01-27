
//Graph Traversals using BFS and DFS implementation
// Week 3 - Graph Traversals 

#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {}
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


void DFS(Node* node, set<Node*>& visited) {
    if(visited.find(node) != visited.end()) return; //already visited
    visited.insert(node);
    cout << node->val << endl;
    for (Node* n: node->neighbors) {
        DFS(n, visited);
    }
}

void BFS(Node* node) {
    queue<Node*> fq;
    set<Node*> visited;
    Node* cur;
    fq.push(node);
    visited.insert(node);
    while(!fq.empty()) {
        cur = fq.front();
        fq.pop();
        cout << cur->val << endl;
        for(Node* n: cur->neighbors) {
            if (visited.find(n) != visited.end()) continue;
            visited.insert(n);
            fq.push(n);
        }
    }
}

Node* createGraph() {
    Node* one = new Node(1, {});
    Node* two = new Node(2, {});
    Node* three = new Node(3, {});
    Node* four = new Node(4, {});
    Node* five = new Node(5, {});
    Node* six = new Node(6, {});
    one->neighbors.push_back(five);
    four->neighbors.push_back(five);
    five->neighbors.push_back(one);
    five->neighbors.push_back(two);
    five->neighbors.push_back(four);
    five->neighbors.push_back(six);
    two->neighbors.push_back(three);
    two->neighbors.push_back(five);
    three->neighbors.push_back(two);
    three->neighbors.push_back(six);
    six->neighbors.push_back(five);
    six->neighbors.push_back(three);
    return one;
}



int main(int argc, const char * argv[]) {
    // DFS
    Node* start = createGraph();
    cout << "Depth First Search: " << endl;
    DFS(start, *new set<Node*>());
    
    cout << "Breadth First Search: " << endl;
    BFS(start);
    
}
