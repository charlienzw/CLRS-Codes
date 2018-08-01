#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
	int key;
	TreeNode* left;
	TreeNode* right;
	TreeNode* p;
	TreeNode (int k);
	TreeNode (const TreeNode* r);
};

class BST
{
public:
	TreeNode * root;
};

TreeNode::TreeNode (int k)
{
	key = k;
}

TreeNode::TreeNode(const TreeNode* r)
{
	key = r->key;
	left = r->left;
	right = r->right;
	p = r->p;
}

void InorderTreeWalk(TreeNode* x)
{
	if (x != NULL)
	{
		InorderTreeWalk(x->left);
		printf("%d ", x->key);
		InorderTreeWalk(x->right);
	}
}

void PreorderTreeWalk(TreeNode* x)
{
	if (x != NULL)
	{
		printf("%d ", x->key);
		PreorderTreeWalk(x->left);
		PreorderTreeWalk(x->right);
	}
}

void PostorderTreeWalk(TreeNode* x)
{
	if (x != NULL)
	{
		PostorderTreeWalk(x->left);
		PostorderTreeWalk(x->right);
		printf("%d ", x->key);
	}
}

void InorderTreeWalk_stack(TreeNode* x)
{
	stack<TreeNode*> s;
	while (s.size() > 0 || x != NULL)
	{
		if (x == NULL)
		{
			x = s.top();
			s.pop();
			printf("%d ", x->key);
			x = x->right;
		}
		else
		{
			s.push(x);
			x = x->left;
		}
	}
	s.~stack();
}

void PreorderTreeWalk_stack(TreeNode* x)
{
	stack<TreeNode*> s;
	while (s.size() > 0 || x != NULL)
	{
		if (x == NULL)
		{
			x = s.top();
			s.pop();
			x = x->right;
		}
		else
		{
			printf("%d ", x->key);
			s.push(x);
			x = x->left;
		}
	}
	s.~stack();
}

void PostorderTreeWalk_twostack(TreeNode* x)
{
	stack<TreeNode*> s1;
	stack<TreeNode*> s2;
	while (s1.size() > 0 || x != NULL)
	{
		if (x == NULL)
		{
			x = s1.top();
			s1.pop();
			x = x->left;
		}
		else
		{
			s2.push(x);
			s1.push(x);
			x = x->right;
		}
	}
	while (s2.size() > 0)
	{
		x = s2.top();
		printf("%d ", x->key);
		s2.pop();
	}
	s1.~stack();
	s2.~stack();
}

void PostorderTreeWalk_stack(TreeNode* x)
{
	stack<TreeNode*> s;
	TreeNode* p;
	while (s.size() > 0 || x != NULL)
	{
		if (x == NULL)
		{
			x = s.top();
			s.pop();
			if (x->right != NULL&&s.size()>0&&s.top()==x->right)
			{
				p = s.top();
				s.pop();
				s.push(x);
				x = x->right;
			}
			else
			{
				printf("%d ", x->key);
				x = NULL;
			}
		}
		else
		{
			if(x->right!=NULL)
				s.push(x->right);
			s.push(x);
			x = x->left;
		}
	}
	s.~stack();
}

TreeNode* TreeSearch(TreeNode* x, int k)
{
	if (x == NULL || k == x->key)
	{
		return x;
	}
	if (k < x->key)
	{
		return TreeSearch(x->left, k);
	}
	else
		return TreeSearch(x->right, k);
}

TreeNode* IterativeTreeSearch(TreeNode* x, int k)
{
	while (x != NULL && k != x->key)
	{
		if (k < x->key)
		{
			x = x->left;
		}
		else
			x = x->right;
	}
	return x;
}

TreeNode* TreeMinimum(TreeNode* x)
{
	while (x->left != NULL)
	{
		x = x->left;
	}
	return x;
}

TreeNode* TreeMaximum(TreeNode* x)
{
	while (x->right != NULL)
	{
		x = x->right;
	}
	return x;
}

TreeNode* Successor(TreeNode* x)
{
	if (x->right != NULL)
	{
		return TreeMinimum(x->right);
	}
	TreeNode* y = x->p;
	while (y != NULL && x == y->right)
	{
		x = y;
		y = y->p;
	}
	return y;
}

TreeNode* Predecessor(TreeNode* x)
{
	if (x->left != NULL)
	{
		return TreeMaximum(x->left);
	}
	TreeNode* y = x->p;
	while (y != NULL && x == y->left)
	{
		x = y;
		y = y->p;
	}
	return y;
}

void TreeInsert(BST* T, TreeNode* z)
{
	TreeNode* y = NULL;
	TreeNode* x = T->root;
	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	z->p = y;
	if (y == NULL)
	{
		T->root=z;
	}
	else if (z->key < y->key)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}
} 

void Transplant(BST* T, TreeNode* u, TreeNode* v)
{
	if (u->p == NULL)
	{
		T->root = v;
	}
	else if (u == u->p->left)
	{
		u->p->left = v;
	}
	else
	{
		u->p->right = v;
	}
	if (v != NULL)
	{
		v->p = u->p;
	}
}

void TreeDelete(BST* T, TreeNode* z)
{
	if (z->left == NULL)
	{
		Transplant(T, z, z->right);
	}
	else if(z->right == NULL)
	{
		Transplant(T, z, z->left);
	}
	else
	{
		TreeNode* y = TreeMinimum(z->right);
		if (y->p != z)
		{
			Transplant(T, y, y->right);
			y->right = z->right;
			y->right->p = y;
		}
		Transplant(T, z, y);
		y->left = z->left;
		y->left->p = y;
	}
}

BST* TreeRandomizedInit(vector<int> key)
{
	random_shuffle(key.begin(), key.end());
	BST*T=new BST();
	for (int i = 0; i < key.size(); i++)
	{
		TreeInsert(T, new TreeNode(key[i]));
	}
	return T;
}

void BFSPrint(BST* T)
{
	TreeNode* x = T->root;
	queue<TreeNode*> q;
	q.push(x);
	int qs;
	TreeNode* tmp;
	int exist = 0;
	while (true)
	{
		exist = 0;
		qs = q.size();
		for (int i = 0; i < qs; i++)
		{
			tmp = q.front();
			q.pop();
			if (tmp == NULL)
			{
				printf("# ");
				q.push(NULL);
				q.push(NULL);
			}
			else
			{
				printf("%d ", tmp->key);
				exist = 1;
				if (tmp->left!= NULL)
				{
					q.push(tmp->left);
				}
				else
				{
					q.push(NULL);
				}
				if (tmp->right != NULL)
				{
					q.push(tmp->right);
				}
				else
				{
					q.push(NULL);
				}
			}
		}
		printf("\n");
		if (exist == 0)
		{
			break;
		}
		
	}
}

int main()
{
	int n;
	TreeNode* tmpnode;
	BST* tmptree=new BST();
	int k;
	while (scanf("%d", &n) != EOF)
	{
		vector<int> key(n);
		for (int i = 0; i < n; i++) scanf("%d", &key[i]);
		BST*T=TreeRandomizedInit(key);
		BFSPrint(T);
		printf("Recursive InorderTreeWalk:\n");
		InorderTreeWalk(T->root);
		printf("\n");
		printf("Nonrecursive InorderTreeWalk:\n");
		InorderTreeWalk_stack(T->root);
		printf("\n");
		printf("Recursive PreorderTreeWalk:\n");
		PreorderTreeWalk(T->root);
		printf("\n");
		printf("Nonrecursive PreorderTreeWalk:\n");
		PreorderTreeWalk_stack(T->root);
		printf("\n");
		printf("Recursive PostorderTreeWalk:\n");
		PostorderTreeWalk(T->root);
		printf("\n");
		printf("Nonrecursive PostorderTreeWalk with two stacks:\n");
		PostorderTreeWalk_twostack(T->root);
		printf("\n");
		printf("Nonrecursive PostorderTreeWalk with one stack:\n");
		PostorderTreeWalk_stack(T->root);
		printf("\n");
		printf("TreeSearch:");
		scanf("%d", &k);
		tmpnode=TreeSearch(T->root, k);
		tmptree->root = tmpnode;
		BFSPrint(tmptree);
		printf("IterativeTreeSearch:");
		scanf("%d", &k);
		tmpnode = IterativeTreeSearch(T->root, k);
		tmptree->root = tmpnode;
		BFSPrint(tmptree);
		printf("TreeMaximum:\n");
		tmpnode = TreeMaximum(T->root);
		tmptree->root = tmpnode;
		BFSPrint(tmptree);
		printf("TreeMinimum:\n");
		tmpnode = TreeMinimum(T->root);
		tmptree->root = tmpnode;
		BFSPrint(tmptree);
		printf("Inorder Successor:\n");
		tmpnode = Successor(T->root);
		tmptree->root = tmpnode;
		BFSPrint(tmptree);
		printf("Inorder Predecessor:\n");
		tmpnode = Predecessor(T->root);
		tmptree->root = tmpnode;
		BFSPrint(tmptree);
		printf("Delete one treenode of exact key:");
		scanf("%d", &k);
		TreeDelete(T, IterativeTreeSearch(T->root,k));
		BFSPrint(T);
	}
	return 0;
}