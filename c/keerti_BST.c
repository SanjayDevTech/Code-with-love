#include<stdio.h>
#include<stdlib.h>

struct tree
{
	int data;
	struct tree *left,*right;
	
};
struct tree *root;

struct tree * insert (struct tree *root)
{
	int val;
	printf("enter the value to be inserted");
	scanf("%d",&val);
	struct tree *nod,*parent,*ptr;
	ptr=(struct tree *)malloc(sizeof(struct tree));
	ptr->data=val;
	ptr->left=NULL;
	ptr->right=NULL;
	if(root==NULL)
	{
		root=ptr;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{
		parent=NULL;
		nod=root;
		while(nod!=NULL)
		{
			parent=nod;
			if(val<nod->data)
			nod=nod->right;
			else
			nod=nod->left;
		
		}
		if(val<parent->data)
		parent->left=ptr;
		else
		parent->right=ptr;
	}
	return root;
}


void preorder(struct tree *root)
{
	if(root!=NULL)
	{
		printf("%d-",root->data);
		preorder(root->left);
		preorder(root->right);
		
	}
}

void inorder(struct tree *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d-",root->data);
		inorder(root->right);
	}
}

void postorder(struct tree *roo)
{
	if(roo!=NULL)
	{
		postorder(roo->left);
		postorder(roo->right);
		printf("%d-",roo->data);
		
	}
}


int main()
{root=NULL;
	int option;
	printf("1.insert\n2.postorder\n3.inorder\n4.preorder\n5.exit");
	
	do{
		printf("\nenter option");
		scanf("%d",&option);
		switch(option)
		{
			case 1:root=insert(root);break;
			case 2:preorder(root);break;
			case 3:inorder(root);break;
			case 4:postorder(root);break;
		}
		
	}while(option!=5);
	return 0;
	
}