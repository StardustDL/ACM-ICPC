/*
[POI2007]对称轴osi
分析：有意思的题目。计算几何的味道如此浓厚，最后却用的是字符串算法来解决。
	  考虑求一个多边形有多少条对称轴，我们可以把多边形表示成一个由边长和角度组成的序列，这样如果两个
	  点的连线 i 和 j 是一条对称轴的话，那么这两个点分割成的两个序列连起来应该是一个回文串。具体方法就是我
	  们找一个长度为 2n 的序列，第一个是边长，第二个是角度，第三个是边长，依次类推。记得到的这个串为 S，
	  我们复制 S 得到 SS，及 S 的反串为 S’，则原问题就变成了 S’在 SS 中出现了多少次，这个可以用 kmp 解决。注意
	  如果角度会挂精度的话可以直接用叉积来代替，因为如果边长不等的话肯定就不行了，如果边长相等的话叉积不
	  等，就说明了角度不等。
	  后面这一部分也可以直接上manacher，不用实数又没精度误差又好写
	  注意每条对称轴有两个顶点，最后答案/2 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define sqr(x) ((x)*(x))
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
struct data{
	bool isp;int val;
	bool operator ==(const data &d)const{
		return isp==d.isp&&val==d.val;
	}
}ds[2*2*MAXN+3];
int x[MAXN+3],y[MAXN+3],n,p[2*2*MAXN+3];
int dist(int i,int j){
	return sqr(x[i]-x[j])+sqr(y[i]-y[j]);
}
int cross(int i,int j,int k){
	return (x[j]-x[i])*(y[k]-y[i])-(x[k]-x[i])*(y[j]-y[i]);
}
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d%d",&x[i],&y[i]);
		for(int i=0;i<n;i++){
			ds[i<<1|1].isp=1;
			ds[i<<1|1].val=dist(i,(i+1)%n);
		}
		for(int i=0;i<n;i++){
			ds[i<<1].isp=0;
			ds[i<<1].val=cross(i,(i-1+n)%n,(i+1)%n);
		}
		int len=n<<1;
		for(int i=0;i<len;i++)ds[i+len]=ds[i];
		len<<=1;
		int mx=0,id=0;memset(p,0,sizeof(p));
		for(int i=0;i<len;i++){
			if(mx>i)p[i]=min(mx-i,p[2*id-i]);
			for(;i-p[i]>=0&&i+p[i]<len&&ds[i-p[i]]==ds[i+p[i]];p[i]++);
			if(i+p[i]>mx)mx=i+p[i],id=i;
		}
		int ans=0;
		for(int i=0;i<len;i++)if(p[i]-1>=n)ans++;//p[i]-1，排除自己的回文半径 
		printf("%d\n",ans>>1);
	}
	return 0;
}
