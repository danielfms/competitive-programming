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
    int sum, low, high;
    public int rangeSumBST(TreeNode root, int low, int high) {
        this.sum = 0;
        this.low = low;
        this.high = high;
        visit(root);
        return sum;
    }
    
     public void visit(TreeNode node){
        if(node == null)return;  
        sum += (node.val >= low && node.val <= high) ? node.val : 0;
        visit(node.left);
        visit(node.right);
    }
}