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
    public int rangeSumBST(TreeNode root, int low, int high) {
        int[] res = new int[1];
        solve(root,low,high,res);
        return res[0];
    }

   public void solve(TreeNode root, int low, int high, int[] sum){
        if (root == null){
            return;
        }
        if (root.val > high){
            solve(root.left,low,high,sum);
        }else if (root.val < low){
            solve(root.right,low,high,sum);
        }else{
            sum[0] += root.val;
            solve(root.right,low,high,sum);
            solve(root.left,low,high,sum);
        }
    }
}