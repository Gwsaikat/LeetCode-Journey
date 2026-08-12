class Solution {
public:
    // We need to map the original node to its new cloned node so we can retrieve it!
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        // Base case: Check if the graph is completely empty
        if (node == NULL) {
            return NULL;
        }
        
        // If we have already visited and cloned this node, just return the clone
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Create the new clone node
        Node* cloneNode = new Node(node->val);
        
        // Mark it as visited by storing the mapping: original -> clone
        visited[node] = cloneNode;
        
        // Iterate through the neighbors of the ORIGINAL node
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return cloneNode;
    }
};