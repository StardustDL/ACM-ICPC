/*
[HNOI2008]明明的烦恼
分析：Caylay定理的一个有趣的推广是，n个节点的度依次为D1, D2, ..., Dn的无根树共有(n-2)! / [ (D1-1)!(D2-1)!..(Dn-1)! ]个，因为此时Prüfer编码中的数字i恰好出现Di-1次。
	  这里的度数无限制其实就是：sum=sigma{各度数-1},cnt:有限制的点的个数 
	  	(n-2)!*(n-cnt)^(n-2-sum)
	  	------------------------
	  	(n-2-sum)!*PI{(各度数-1)!}
	  无解 可以判一下n=1,n=2的情况，度数不能太大。 
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
typedef int bign[7012];
const int MAXL=4000;
bign ans,p,w,a;
void mul(bign &x,int y){
	for(int i=1;i<=MAXL;i++)x[i]*=y;
	for(int i=1;i<=MAXL;i++)
		if(x[i]>9)x[i+1]+=x[i]/10,x[i]%=10;
}
bool bigger(bign &x,bign &y,int k){
	for(int i=MAXL;i;i--)
		if(x[i]>y[k+i])return 1;
			else if(x[i]<y[k+i])return 0;
	return 1;
}
inline void div(bign &x,bign &y){
	memset(ans,0,sizeof(ans));
	int t=MAXL,l=MAXL,num=1,tail=0;
	while(!x[t])t--;
	while(!y[l])l--;
	for(int i=t;i>t-l;i--)y[i]=y[i-(t-l)];
	for(int i=t-l;i;i--)y[i]=0,num++;
	while(t){
		if(bigger(x,y,tail)){
			ans[num]++;
			for(int i=t;i;i--)x[i]-=y[tail+i];
			for(int i=1;i<=t;i++)
				if(x[i]<0)x[i]+=10,x[i+1]--;
			for(;t;t--)if(x[t])break;
		}else tail++,num--;
	}
}
int main(){
	int n,sum=0,k=0;
	scanf("%d",&n);
	memset(w,0,sizeof(w));
	memset(p,0,sizeof(p));
	w[1]=p[1]=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=-1){
			sum+=a[i]-1,k++;
			for(int j=1;j<=a[i]-1;j++)mul(p,j);
		}
	}
	for(int i=n-2;i>=n-2-sum+1;i--)mul(w,i);
	int t=n-k,l=MAXL;
	for(int i=1;i<=n-2-sum;i++)mul(w,t);
	div(w,p);
	while(!ans[l])l--;
	for(int i=l;i;i--)putchar('0'+ans[i]);
	puts("");
	return 0;
}

