/*
[SCOI2008]斜堆
分析：考虑斜堆中最后插入的那个结点，容易发现：
		（1）它一定是一个极左结点（就是从根往它的路上一直都是沿着左链走），因为插入的时候每次都是插入到左子树中；
		（2）它一定木有右子树，因为插入的时候每次都是把原来的某棵子树作为新结点的左子树；
		满足（1）（2）的结点可能有多个，
		但紧接着可以发现，这个斜堆中的每个结点如果木有左子结点，那么也木有右子结点（或者说，每个非叶结点都有左子树），
		而在插入一个结点之前，其所有的祖先都被交换了左右子树，
		所以，如果新结点的祖先中有满足（1）（2）的，且新结点不是叶结点，那么在新结点插入之前，这个满足（1）（2）的祖先必然是只有右子树而木有左子树的，这与上面的那个性质矛盾，
		所以，可以得出：最后插入的那个结点一定是满足（1）（2）的结点中，深度最小的那个（设为X），
		除非X的左子结点是叶结点，此时为了满足字典序最小，应该取X的左子结点为最后插入的。
		找到这个最后插入的结点以后，只需要把它删掉，并把它的所有祖先交换左右子树，就是插入该结点以前的状态了。
		这样可以找到字典序最小的插入顺序。 
*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,top,root;
int ls[105],rs[105],fa[105],ans[105];
void solve(){
	int x=root;
	while(rs[x]!=-1)x=ls[x];
	int t=ls[x];
	if(t!=-1&&ls[t]==-1&&rs[t]==-1)x=t;
	ans[++top]=x;
	if(x==root)root=ls[root];
	int f=fa[x];
	if(f!=-1)ls[f]=ls[x],fa[ls[f]]=f;
	while(f!=-1)swap(ls[f],rs[f]),f=fa[f];
}
int main(){
	fa[0]=-1;
	memset(ls,-1,sizeof(ls));memset(rs,-1,sizeof(rs));
	scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(x<100)ls[x]=i,fa[i]=x;
		else rs[x-100]=i,fa[i]=x-100;
	}
	for(int i=1;i<=n+1;i++)solve();
	while(top)printf("%d ",ans[top--]);
	return 0;
}
