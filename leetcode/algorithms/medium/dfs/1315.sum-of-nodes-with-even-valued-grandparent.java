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
    int sum;
    public int sumEvenGrandparent(TreeNode root) {
        this.sum = 0;
        visit(root, null);
        return this.sum;
    }
    
     public void visit(TreeNode node, TreeNode parent){
        int left = 0, right = 0;
        if(node == null)return;  
       
        if(parent != null && parent.val % 2 == 0){
            left = node.left != null ? node.left.val : 0;
            right = node.right != null ? node.right.val : 0;
        }
        
        sum += left + right;
         
        visit(node.left, node);
        visit(node.right, node);
    }
}