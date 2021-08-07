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
    public TreeNode invertTree(TreeNode root) {   
        TreeNode ans = new TreeNode(0, root, null);
        DFS(root);
        return ans.left;
    }
    
    public void DFS(TreeNode root){
        if(root == null) return;
        TreeNode right = root.right;
        TreeNode left = root.left;
        root.left = right;
        root.right = left;
        DFS(root.left);
        DFS(root.right);
    }
}