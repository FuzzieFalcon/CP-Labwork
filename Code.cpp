class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))
         return -1;

         int flag=0;

        stack <TreeNode*> st;
        st.push(root);
        int rootVal = root->val;
        int ans=INT_MAX;
        while(!st.empty())
        {
            TreeNode* top = st.top();
            st.pop();
            if(top->left!=NULL)
            {
                st.push(top->left);
                if(top->left->val!=rootVal)
                {
                 ans= min(ans, top->left->val);
                  if(ans==INT_MAX)
                     flag=1;
                }
            }
            if(top->right!=NULL)
            {
                st.push(top->right);
                if(top->right->val!=rootVal)
                 {
                     ans= min(ans, top->right->val);
                     if(ans==INT_MAX)
                     flag=1;
                 }
            }
        }
        if(flag==1)
        return ans;
        return (ans==INT_MAX?-1:ans);
    }
};
