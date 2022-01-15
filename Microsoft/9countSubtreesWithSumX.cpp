int count(Node* root,int x ,int &cnt)
{
    if(!root) return 0;
    
    int leftSum = count(root->left,x,cnt);
    int rightSum = count(root->right,x,cnt);
    if((root->data + leftSum + rightSum)==x) cnt++;
    
    return leftSum+rightSum+root->data;
}

int countSubtreesWithSumX(Node* root, int X)
{
	
	int cnt=0;
	count(root,X,cnt);
	
	return cnt;
}