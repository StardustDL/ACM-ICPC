/*
Î¬»¤ÊýÁÐ
*/
#include<iostream>
#include<stack> 
#include<algorithm>
#include<cstring>
#include<vector> 
using namespace std;
const int MAXN=200000,INF=0x3f3f3f3f; 
typedef long long LL;
struct node{
	int size,ch[2],tag,rev,val,pnt;
	LL sum;
	
	void init(){
		size=ch[0]=ch[1]=tag=rev=sum=val=pnt=0;
	}
};
struct Splay{
	node N[MAXN+31];
	int root,cnt;
	stack<int> emp;
	
	void init(){
		memset(N,0,sizeof(N));
		root=cnt=0;
		while(!emp.empty())emp.pop();
	}
	
	int newnode(int pnt,int val){
		int pos=0;
		if(!emp.empty()){
			pos=emp.top(); emp.pop();
		}
		else pos=++cnt;
		N[pos].init();
		N[pos].size=1;
		N[pos].sum=N[pos].val=val;
		N[pos].pnt=pnt;
		return pos;
	}
	
	void downtag(int x){
		node &X=N[x],&L=N[N[x].ch[0]],&R=N[N[x].ch[1]];
		if(X.rev){
			L.rev^=1;R.rev^=1;
			swap(L.ch[0],L.ch[1]);
			swap(R.ch[0],R.ch[1]);
			X.rev=0;
		}
		if(X.tag){
			if(X.ch[0]){
				L.tag+=X.tag;
				L.val+=X.tag;
				L.sum+=X.tag*L.size;
			}
			if(X.ch[1]){
				R.tag+=X.tag;
				R.val+=X.tag;
				R.sum+=X.tag*R.size;
			}
			X.tag=0;
		}
	} 
	
	void update(int x){
		int l=N[x].ch[0],r=N[x].ch[1];
		N[x].size=N[l].size+N[r].size+1;
		N[x].sum=N[l].sum+N[r].sum+N[x].val;
	}
	
	void rotate(int x,bool b){
		downtag(x);
		int l=N[x].ch[!b],r=N[x].ch[b],f=N[x].pnt,g=N[f].pnt;
		N[x].pnt=g;N[f].pnt=x;
		if(r)N[r].pnt=f;
		N[x].ch[b]=f;
		N[f].ch[!b]=r;
		if(g)if(N[g].ch[0]==f)N[g].ch[0]=x;else N[g].ch[1]=x;
		update(f);
	}
	
	void splay(int x,int target){
		while(N[x].pnt!=target){
			int f=N[x].pnt,g=N[f].pnt;
			if(N[f].ch[0]==x){
				if(g!=target&&N[g].ch[0]==f)rotate(f,true);
				rotate(x,true);
			}
			else{
				if(g!=target&&N[g].ch[1]==f)rotate(f,false);
				rotate(x,false);
			}
		}
		update(x);
		if(target==0)root=x;
	}
	
	int search(int x,int target){
		int pos=root,t;
		while(1){
			//cout<<x<<" "<<pos<<endl;cin>>t;
			downtag(pos);t=N[pos].ch[0];
			if(x==N[t].size+1){
				splay(pos,target);return pos;
			}
			if(x<N[t].size+1){
				pos=t; 
			}
			else{
				x=x-N[t].size-1;
				pos=N[pos].ch[1];
			}
		}
	}
	
	int split(int l,int r,int target){
		int t=search(l-1,target);
		search(r+1,t);
		return N[N[t].ch[1]].ch[0];
	}
	
	void reverse(int x){
		N[x].rev^=1;
		swap(N[x].ch[0],N[x].ch[1]);
	}
	
	int insert(int x,int val,int target){
		int t=search(x-1,target);
		int p=search(x,t);
		int pos=newnode(p,val);
		N[p].ch[0]=pos;
		update(p);
		splay(pos,0);
	}
	
	void erase(int x){
		emp.push(x);
		if(N[x].ch[0])erase(N[x].ch[0]);
		if(N[x].ch[1])erase(N[x].ch[1]);
		N[x].init();
	}
	
	void remove(int x){
		int t=search(x-1,0);
		int p=search(x,t);
		N[p].ch[0]=0;
		update(p);
		erase(x);
	}
	
	void remove(int l,int r){
		remove(split(l,r,0));
	}
	
	void build(int *a,int l,int r,int p){
		int mid=(l+r)>>1;
		int cur=++cnt;
		N[cur].pnt=p;
		N[cur].val=a[mid];
		N[cur].size=1;
		if(l<mid){
			N[cur].ch[0]=cnt+1;
			build(a,l,mid-1,cur);
		}
		if(r>mid){
			N[cur].ch[1]=cnt+1;
			build(a,mid+1,r,cur);
		}
		update(cur);
		if(p==0)root=cur;
	}
	
	LL sum(int x){
		//splay(x,0);
		return N[x].sum;
	}
	
	void add(int x,int ad){
		N[x].tag+=ad;
		N[x].val+=ad;
		N[x].sum+=N[x].size*ad;
		splay(x,0);
	}
}S;
int n,a[MAXN+3],x,y,z,t,m;
char str[10];
int main(){
	cin>>n>>m;S.init();
	for(int i=2;i<=n+1;i++){
		cin>>a[i];
	}
	S.build(a,1,n+2,0);
	while(m-->0){
		cin>>str;
		if(str[0]=='I'){
			cin>>x>>y>>z;
			S.add(S.split(x+1,y+1,0),z);
		}
		else if(t==2){
			cin>>x>>y;
			cout<<S.sum(S.split(x+1,y+1,0))<<endl;
		}
	}
	return 0;
}
