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
    int value = -1;
    boolean ans = true;
    public boolean isUnivalTree(TreeNode root) {
        if(root == null) return false;
        this.value = root.val;
        DFS(root);
        return ans;
    }
    
    public void DFS(TreeNode root){
        if(root == null) return;
        ans = ans && root.val == this.value;
        DFS(root.left);
        DFS(root.right);
    }
}