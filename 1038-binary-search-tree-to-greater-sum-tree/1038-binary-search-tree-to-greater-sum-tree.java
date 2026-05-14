class Solution {
    public TreeNode bstToGst(TreeNode root) {
        dfs(root);
        return root;
        }

    public void dfs(TreeNode root){
        Stack<TreeNode> s = new Stack<>();
        s.push(root);
        HashMap<TreeNode,Boolean> visited = new HashMap<>();
        int sum = 0;
        while(!s.empty()){
            TreeNode curr = s.pop();
            if (!visited.containsKey(curr)){
                visited.put(curr,true);
                if (curr.left != null){
                    s.push(curr.left);
                }
                s.push(curr);
                if (curr.right != null){
                    s.push(curr.right);
                }
            }else{
                sum += curr.val;
                curr.val = sum ;
            }
        }
    }
}