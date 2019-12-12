#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int data;
	node *left,*right;
};
node* Getnode(int data)
{
	node* temp=new node;
	temp->data=data;
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}
node* insert(node* root,int key)
{
	queue<node*> q;
	node* temp=root;
	if(temp==NULL)
		root=Getnode(key);
	else
	{
		q.push(temp);
		while(!q.empty())
		{
			node* current=q.front();
			q.pop();
			if(current->left==NULL){
				current->left=Getnode(key);
				break;
			}
			else
				q.push(current->left);
			if(current->right==NULL){
				current->right=Getnode(key);
				break;
			}
			else
				q.push(current->right);

		}
	}
	return root;
}
//depth first search
int dfs(node* root)
{
	node* temp=root;
	if(temp==NULL){
		return 0;
	}
	cout<<temp->data<<" ";
	dfs(temp->left);
	dfs(temp->right);
}
// BFS or Levelorder traversal
void Levelorder(node* root)
{
	queue<node*> q;
	q.push(root);
	if(root==NULL)
		cout<<"empty"<<endl;
	else
	{
		while(!q.empty())
		{
			node* temp=q.front();
			q.pop();
			cout<<temp->data<<" ";
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}
	}
}
// Deletion by level order travesal so that the tree remains dence
int DeleteDeepNode(node* root,node* temp)
{
	if(root==NULL)
		return 0;
	if(root->left==temp){
		root->left=NULL;
		delete temp;
		return 1;
	}
	else if(root->right==temp)
	{
		root->right=NULL;
		delete temp;
		return 1;
	}
	DeleteDeepNode(root->left,temp);
	DeleteDeepNode(root->right,temp);
}
void Delete(node* root,int key)
{
	if(root==NULL)
		cout<<"empty"<<endl;
	else
	{
		queue<node*> q;
		node *d_node=NULL,*temp=NULL;
		q.push(root);
		while(!q.empty())
		{
			temp=q.front();
			q.pop();
			if(temp->data==key)
				d_node=temp;
			if(temp->left!=NULL)
				q.push(temp->left);
			if(temp->right!=NULL)
				q.push(temp->right);
		}
		d_node->data=temp->data;
		//cout<<temp->data<<endl;
		//cout<<d_node->data<<endl;
		DeleteDeepNode(root,temp);
	}
}
int main()
{
	node* root=NULL;
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,30);
	root=insert(root,400);
	root=insert(root,204);
	root=insert(root,304);
	Delete(root,20);
	Levelorder(root);
	cout<<endl;
	
}