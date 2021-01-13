#include<map>
#include<set>
#include<iterator>
#include<algorithm>
#include<cstring>
#include<climits>
#include<cstdlib>
#include<cstdio>
using namespace std;
int N,M;
char dict[7][7];
int visited[7][7]={0};
vector<char> word;
//set<string> finalWords;
typedef struct trie
{
    struct trie *children[123];
    bool leaf;
}Trie;
Trie *getNode()
{
    Trie *node = new Trie;
    for(int i=0;i<123;i++)
        node->children[i]=NULL;
    node->leaf=false;
    return node;
}

void insert(Trie *root,char key[])
{
    int level;
    int index;
    Trie *pNode=root;
    int len=strlen(key);
    for(level=0;level<len;level++)
    {
        index=key[level];
        if(pNode->children[index]==NULL)
        {
            pNode->children[index]=getNode();
        }
        pNode=pNode->children[index];
    }
    pNode->leaf=true;
}

int search(Trie *root,char key[])
{
    int level;
    int index;
    int len=strlen(key);
    Trie *pNode=root;
    for(level=0;level<len;level++)
    {
        index=key[level];
        if(pNode->children[index]==NULL)
            return 0;
        pNode=pNode->children[index];
    }
    if(pNode && pNode->leaf)
        return 1;
    return 0;
}
void getWord(Trie *root,int i,int j,set<string> &finalWords)
{
    if(i<0 || j<0 || i>=N || j>=M )
        return ;
    if(visited[i][j]==1)
        return;
    if(root==NULL)
        return;
    Trie *node = root;
    int in=dict[i][j];
    if(node->children[in])
    {
        visited[i][j]=1;
        word.push_back(dict[i][j]);
        node=node->children[in];
        if(node->leaf)
        {
            string w;
            for(auto it=word.begin();it!=word.end();it++)
                w.push_back(*it);
            finalWords.insert(w);
        }
        getWord(node,i-1,j,finalWords);
        getWord(node,i-1,j-1,finalWords);
        getWord(node,i,j-1,finalWords);
        getWord(node,i+1,j-1,finalWords);
        getWord(node,i+1,j,finalWords);
        getWord(node,i+1,j+1,finalWords);
        getWord(node,i,j+1,finalWords);
        getWord(node,i-1,j+1,finalWords);
        visited[i][j]=0;
        word.pop_back();
    }
}
int main()
 {
	//code
        int t;
        cin>>t;
        while(t--)
        {
            set<string> finalWords;
            int n;
            cin>>n;
            //string wordlist[n];
            char wordlist[10][100];
            for(int i=0;i<n;i++)
            {
                scanf("%s",wordlist[i]);
            }
            cin>>N>>M;
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<M;j++)
                    cin>>dict[i][j];
            }
            Trie *root=getNode();
            for(int i=0;i<n;i++)
                insert(root,wordlist[i]);
           // cout<<search(root,"bcd");
           for(int i=0;i<N;i++)
           {
               for(int j=0;j<M;j++)
               {
                   getWord(root,i,j,finalWords);
               }
           }
           for(auto it=finalWords.begin();it!=finalWords.end();it++)
            cout<<*it<<" ";
            if(!finalWords.size())
                cout<<"-1";
          cout<<endl;
        }
	return 0;}
