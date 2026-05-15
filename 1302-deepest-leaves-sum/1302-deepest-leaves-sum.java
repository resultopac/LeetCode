class Solution {
        public int deepestLeavesSum(TreeNode root) {
            int[] maxDepth = new int[1];
            int[] sum = new int[1];
            solve(root, maxDepth,0,sum);
            return sum[0];
        }
        
        public void solve(TreeNode root,int[] maxDepth, int currDepth, int[] sum){
            if (root == null){
                return;
            }
            if (currDepth > maxDepth[0]){
                maxDepth[0] = currDepth;
                sum[0] = root.val;
            }else if (currDepth == maxDepth[0]){
                sum[0] += root.val;
            }
            solve(root.left,maxDepth,currDepth+1,sum);
            solve(root.right,maxDepth,currDepth+1,sum);
        }
    }