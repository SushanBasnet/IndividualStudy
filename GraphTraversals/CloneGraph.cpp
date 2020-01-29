/*
// Definition for a Node.
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
*/

#include <unordered_set>
#include <unordered_map>
#include <queue>


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node==NULL) return NULL;
        queue<Node*> fq;
        unordered_map<Node*, Node*> visited;
        visited[node] = new Node(node->val, {});
        fq.push(node);
        Node* tmp;
        while(!fq.empty()) {
            tmp = fq.front();
            fq.pop();
            for(Node* n: tmp->neighbors) {
                if (visited.find(n) == visited.end()) {
                    //not visited yet
                    fq.push(n);
                    Node* newNode = new Node(n->val, {});
                    visited[n] = newNode;
                    visited[tmp]->neighbors.push_back(newNode);
                } else {
                    visited[tmp]->neighbors.push_back(visited[n]);
                }
            }
        }
        return visited[node];
    }
};