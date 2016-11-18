#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define NODE_NUM 100000
#define RAND_SEED 0x15310314


struct BST_Node{
	int value;
	struct BST_Node *left;
	struct BST_Node *right;
};

void insert_n(struct BST_Node *p,struct BST_Node *x);
void insert_v(struct BST_Node *p,int x);
int compute_height(struct BST_Node*p);
int Max(int x,int y);
void tree_shape(struct BST_Node*p);

int main(void){
	struct BST_Node *T_root; int i;
	T_root=(struct BST_Node*)malloc(sizeof(struct BST_Node));
	T_root->left=T_root->right=NULL;
	T_root->value=0; srand(RAND_SEED);

	for(i=0;i<NODE_NUM; i++){
		insert_v(T_root,rand()/(double)RAND_MAX*NODE_NUM*10);
	}

	printf("%d‚Å‚·\n",compute_height (T_root));
	//tree_shape (T_root);

	getchar ();
	getchar ();
}

void insert_v(struct BST_Node *p,int x){
	struct BST_Node *new_node;
	new_node=(struct BST_Node*)malloc(sizeof(struct BST_Node));
	new_node -> left=NULL; new_node -> right=NULL;
	new_node ->value=x; insert_n(p,new_node);
}
void insert_n(struct BST_Node *p,struct BST_Node *x){
	
	if(x==NULL){
		return;
	}

	if(x->value < p ->value){
		if(p->left==NULL){
			p->left=x;
		}
		else{
			insert_n(p->left,x);
		}
	}
	else if(p->value < x->value){
		if(p->right==NULL){
			p->right=x;
		}
		else {
			insert_n(p->right,x);
		}
	}
}

int compute_height (struct BST_Node *p){
	int lh=-1,rh=-1;
	if(p==NULL){
		return -1;
	}

	lh=compute_height (p->left);
	rh=compute_height (p->right);
	return Max(lh,rh)+1;
}
int Max(int x,int y){
	int max;
	if(x>y){ max=x;
	}
	else if(x<y){
		max=y;
	}
	else if(x==y){
		max=x;
	}
	return max;
}

void tree_shape(struct BST_Node*p){
	if(p==NULL){
		return ;
	}
	printf("(");
		if(p->left!=NULL){
			tree_shape(p->left);
		} printf("%d",p->value);
		if(p->right!=NULL){
			tree_shape (p->right);
		}
		printf(")");
	}