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
    int visited[] = new int[10001];
    List<Integer> ans = new ArrayList<>();
    public List<Integer> preorder(Node root) {
        DFS(root);
        return ans;
    }
    
    public void DFS(Node root){
        if(root == null) return;
        //visited[root.val] = 1;
        ans.add(root.val); 
        
        for(int i = 0; root.children != null && i < root.children.size(); i++){
            //if(visited[root.children.get(i).val] == 0){
                 DFS(root.children.get(i));
            //}        
        }
    }
}