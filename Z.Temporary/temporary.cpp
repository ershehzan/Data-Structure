class Node{
    public:
    int data;
    Node *left,*right;
    
    Node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;
    }
};

class Solution{
    public:
    
     int find(int arr[],int start,int end,int x)
    {
        for(int i=start;i<=end;i++)
        {
            if(arr[i]==x)
            return i;
        }
        
        return -1;
    }
    
    Node *createTree1(int in[],int pre[],int inStart,int inEnd, int index,bool &valid)
    {
        
        if(inStart>inEnd)
        return NULL;
        
        Node *root = new Node(pre[index]);
        
        int pos = find(in,inStart,inEnd,pre[index]);
        
        if(pos==-1)
        {
            valid = 0;
            return NULL;
        }
        
        root->left=createTree1(in,pre,inStart,pos-1,index+1,valid);
        
        
        root->right=createTree1(in,pre,pos+1,inEnd,index+(pos-inStart)+1,valid);
        
        return root;
    }
    
    Node *createTree2(int in[],int post[],int inStart,int inEnd, int index,bool &valid)
    {
        
        if(inStart>inEnd)
        return NULL;
        
        Node *root = new Node(post[index]);
        
        int pos = find(in,inStart,inEnd,post[index]);
        
        if(pos==-1)
        {
            valid = 0;
            return NULL;
        }
        
        root->right=createTree2(in,post,pos+1,inEnd,index-1,valid);
        
        root->left=createTree2(in,post,inStart,pos-1,index-(inEnd-pos+1),valid);
        
        return root;
    }
    
    bool check(Node *root1,Node *root2)
    {
        if(!root1 && !root2)
        return 1;
        
        if(!root1 || !root2)
        return 0;
        
        if(root1->data != root2->data)
        return 0;
        
        return check(root1->left,root2->left) && check(root1->right,root2->right); 
    }
    
    bool checktree(int pre[], int in[], int post[], int n) 
    { 
    	// Your code goes here
    	bool valid = 1;
    	Node *tree1 = createTree1(in,pre,0,n-1,0,valid);
    	Node *tree2 = createTree2(in,post,0,n-1,n-1,valid);
    	
    	if(!valid)
    	return 0;
    	
    	if(!tree1 || !tree2)
    	return 0;
    	
    	return check(tree1,tree2);
    } 

};