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
    public static Map<Integer, Integer> counter;
    public int deepestLeavesSum(TreeNode root) {
        counter = new HashMap<>();
        visit(root, 1);
        int levels = counter.size();
        return counter.get(levels);
    }
    
    public void visit(TreeNode node, int level){
        if(node == null)return;
        Integer levelSum = counter.get(level);
        if(levelSum == null){
            levelSum = 0;
        }
        levelSum += (node.val);
        counter.put(level, levelSum);
        
        visit(node.left, level + 1);
        visit(node.right, level + 1);
    }
}