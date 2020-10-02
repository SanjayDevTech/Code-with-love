#include<bits/stdc++.h>
#define int long long
#define pb emplace_back
#define mp make_pair
#define tci(v,i) for(auto i=v.begin();i!=v.end();i++)
#define all(v) v.begin(),v.end()
#define rep(i,start,lim) for(long long (i)=(start);i<(lim);i++)
#define revrep(i,n) for(long long i=n-1;i>=0;i--)
#define boost ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define osit ostream_iterator<int> output (cout," ")
#define pv(x) copy(all(x),output)
#define pa(a) rep(i,0,sizeof(a)/sizeof(a[0]))cout<<a[i]<<" "
#define endl '\n'
#define f first
#define s second
#define PI 3.141592653589793
#define set0(x) memset(x,0,sizeof(x))
#define set1(x) memset(x,1,sizeof(x))
#define getarr(arr,n) int arr[n];rep(i,0,n)cin>>a[i]
#define getvec(vec,n) vi vec;int x;rep(i,0,n){cin>>x;vec.pb(x);}
#define sort_uniq(c) (sort(c.begin(), c.end()), c.resize(distance(c.begin(), unique(c.begin(), c.end()))))
#define uniq(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define dg(x) cout<<#x<<':'<<x<<endl;
#define dg2(x,y) cout<<#x<<':'<<x<<' '<<#y<<':'<<y<<endl;
#define dg3(x,y,z) cout<<#x<<':'<<x<<' '<<#y<<':'<<y<<' '<<#z<<':'<<z<<endl;
#define dg4(x,y,z,zz) cout<<#x<<':'<<x<<' '<<#y<<':'<<y<<' '<<#z<<':'<<z<<' '<<#zz<<':'<<zz<<endl;
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
template<typename T> T gcd(T a,T b){if(a==0) return b; return gcd(b%a,a);}
int isPowerof2(int x) { return (x && !(x & x-1)); }

struct TreeNode{
	int val;
	TreeNode *left,*right;
};

TreeNode* createNode(int data){
	TreeNode *ptr=new TreeNode;
	ptr->val=data;
	ptr->left=NULL;
	ptr->right=NULL;
	return ptr;
}

void inorder(TreeNode *root){
	if(root==NULL)return ;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

TreeNode* LCA(TreeNode *root,int key1,int key2){
	if(root==NULL)return root;
	if(root->val==key1 || root->val==key2){
		return root;
	}
	TreeNode *l=LCA(root->left,key1,key2);
	TreeNode *r=LCA(root->right,key1,key2);
	if(l && r)return root;
	else if(l && !r)return l;
	else if(!l && r)return r;
	else return NULL;
}

int32_t main(){
	TreeNode *root=createNode(3);
	root->left=createNode(6);
	root->right=createNode(8);
	root->left->left=createNode(2);
	root->left->right=createNode(11);
	root->right->right=createNode(13);
	root->left->right->left=createNode(9);
	root->left->right->right=createNode(5);
	root->right->right->left=createNode(7);
	TreeNode *node=LCA(root,6,7);
	cout<<node->val;
	return 0;
}