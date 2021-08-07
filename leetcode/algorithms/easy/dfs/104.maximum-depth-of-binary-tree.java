/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans = 0;
    public int maxDepth(TreeNode root) {
        DFS(root, 0);
        return ans;
    }
    
    public void DFS(TreeNode root, int depth){
        if(root == null) return;
        ans = Math.max(ans, depth + 1);
        DFS(root.left, depth + 1);
        DFS(root.right, depth + 1);
    }
}