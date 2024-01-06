//////////top view***************

void topv(TreeNode<int> *root, map<int,int>& m,int x){
    if(!root)return;
    if(m.find(x)==m.end())m[x]=root->data;

    if(root->left)topv(root->left, m, x-1);
    if(root->right)topv(root->right, m, x+1);
}
vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    map<int,int> m;
    queue<pair<TreeNode<int> *,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
       TreeNode<int> *tmp=it.first;
        int line=it.second;
        if(m.find(line)==m.end())m[line]=tmp->data;

        if(tmp->left)q.push({tmp->left,line-1});
        if(tmp->right)q.push({tmp->right,line+1});

    }
    vector<int> res;
    for(auto it:m){
        res.push_back(it.second);
    }
    return res;
}

/////////bottom view*************3

vector<int> bottomView(TreeNode<int> * root){
    // Write your code here.
     map<int,int> m;
    queue<pair<TreeNode<int> *,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it=q.front();
        q.pop();
       TreeNode<int> *tmp=it.first;
        int line=it.second;
        m[line]=tmp->data;

        if(tmp->left)q.push({tmp->left,line-1});
        if(tmp->right)q.push({tmp->right,line+1});

    }
    vector<int> res;
    for(auto it:m){
        res.push_back(it.second);
    }
    return res;
}
