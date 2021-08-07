/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    int ans = 0;
    public int maxDepth(Node root) {
        DFS(root, 0);
        return ans;
    }
    
    public void DFS(Node root, int depth){
        if(root == null) return;
        ans = Math.max(ans, depth + 1);
        
        for(int i = 0; root.children != null && i < root.children.size(); i++){
            DFS(root.children.get(i), depth + 1);
        }
    }
}