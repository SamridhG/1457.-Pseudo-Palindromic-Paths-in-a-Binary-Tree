As we know value in node is in between 1 to 9 means value in path also from 1 to 9
lets count how many times this value come in every path
if more than one time one element occur odd times then its is not pseudo palindrom
// one of properties of Palindrome

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>>A;
    int countpath;
    Solution()
    {
        countpath=0;
    }
    void path(TreeNode *root,vector<int>array)
    {
        if(root!=NULL)
        {
            if(root->left==NULL && root->right==NULL)
            {
                array[root->val]++;
                count(array);
            }
            else
            {
                array[root->val]++;
                path(root->left,array);
                path(root->right,array);
            }
        }
    }
    void count(vector<int>array)
    {
            int odd=0;
            int flag=0;
            for(int p=1;p<10;p++)
            {
                if(array[p]%2!=0)
                {
                    odd++;
                    if(odd>1)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0)
            {
                countpath++;
            }
        }
       
    
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>array(10,0);
        path(root,array);
        
         return countpath;}
      
};
