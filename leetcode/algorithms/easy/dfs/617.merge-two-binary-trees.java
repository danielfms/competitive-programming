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
    public TreeNode mergeTrees(TreeNode root1, TreeNode root2) {
        TreeNode ans = new TreeNode(0);
        if(root1 != null || root2 != null){
            visit(root1, root2,  ans);
            return ans;
        }
        return null;
    }
    
    public void visit(TreeNode root1, TreeNode root2, TreeNode merge){
        if(root1 == null && root2 == null) return;
        int sum = 0;
        boolean root1Exists = false, root2Exists = false;
        if(root1 != null){
            sum += root1.val;
            root1Exists = true;
        }
        if(root2 != null){
            sum += root2.val;
            root2Exists = true;
        }
        merge.val = sum;
        
        if((root1Exists && root1.right != null) || (root2Exists && root2.right != null)){
            merge.right = new TreeNode(0);
            visit(root1Exists ? root1.right : null, root2Exists ? root2.right : null, merge.right);
        }
        
        if((root1Exists && root1.left != null) || (root2Exists && root2.left != null)){
            merge.left = new TreeNode(0);
            visit(root1Exists ? root1.left : null, root2Exists ? root2.left : null, merge.left);
        }
    }
      
}