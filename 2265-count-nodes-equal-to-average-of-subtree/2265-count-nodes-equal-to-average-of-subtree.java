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
    class Result {
            int sum;
            int count;

            Result(int sum, int count) {
                this.sum = sum;
                this.count = count;
            }
        }
    public int averageOfSubtree(TreeNode root) {
            int[] res = new int[1];
            solve(root,res);
            return res[0];
        }

        public Result solve(TreeNode root,int[] res){
            if (root == null){
                return new Result(0,0);
            }
            Result left = solve(root.left,res);
            Result right = solve(root.right,res);
            int sum = left.sum + right.sum + root.val;
            int nodes = right.count +left.count; 
            if (sum/(nodes+1) == root.val){
                res[0] += 1;
            }

            return new Result(sum, nodes+1);
        }
}