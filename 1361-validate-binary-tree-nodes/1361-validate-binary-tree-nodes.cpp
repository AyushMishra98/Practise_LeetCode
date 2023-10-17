class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = findRoot(n, leftChild, rightChild);
        if (root == -1) {
            return false;
        }
        
        unordered_set<int> s;
        queue<int> q;
        s.insert(root);
        q.push(root);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            int children[] = {leftChild[node], rightChild[node]};
            for (int child : children) {
                if (child != -1) {
                    if (s.find(child) != s.end()) {
                        return false;
                    }
                    
                    q.push(child);
                    s.insert(child);
                }
            }
        }
        
        return s.size() == n;
    }
    
    int findRoot(int n, vector<int>& left, vector<int>& right) {
        unordered_set<int> children;
        children.insert(left.begin(), left.end());
        children.insert(right.begin(), right.end());
        
        for (int i = 0; i < n; i++) {
            if (children.find(i) == children.end()) {
                return i;
            }
        }
        
        return -1;
    }
};