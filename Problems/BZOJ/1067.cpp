/*
[SCOI2007]降雨量
分析：离散化，维护区间最小值（RMQ或线段树） 
		需要考虑很多情况。比如第x年到第y年
		如果y<x，不知道有没这种情况，应该是false吧
		true的情况需要满足
		x与y的值都已知且y值<x值且x+1到y-1都已知并且都小于y值
		maybe满足
		1.x值y值均未知
		2.已知x值未知y值并且x+1到y-1都已知并且都小于y值
		3.已知y值未知x值并且x+1到y-1都已知并且都小于x值
		4.x为年份最大一年，y>x
		5.y为年份最小一年，x<y
		6.x，y均已知且y<x并且x+1到y-1有未知并且都小于x值
		其它都是false
	  自己的代码WA一个点。。 
*/

#include<iostream>
#include<cstdio>
using namespace std;
struct data{int ly,ry,mx,know;}tr[200001];
int n,m;
void build(int k,int l,int r)
{
     if(l==r){scanf("%d%d",&tr[k].ly,&tr[k].mx);tr[k].ry=tr[k].ly;tr[k].know=1;return;}
     int mid=(l+r)>>1;
     build(k<<1,l,mid);build(k<<1|1,mid+1,r);
     tr[k].know=(tr[k<<1].know&&tr[k<<1|1].know);
     if(tr[k<<1].ry+1!=tr[k<<1|1].ly)tr[k].know=0;
     tr[k].ly=tr[k<<1].ly;tr[k].ry=tr[k<<1|1].ry;
     tr[k].mx=max(tr[k<<1].mx,tr[k<<1|1].mx);
 }
int get(int k,int x)
{    
    if(tr[k].ly==tr[k].ry)
    {
        if(tr[k].ly!=x)return 0;                
        else return tr[k].mx;
                        }
    if(x<=tr[k<<1].ry)return get(k<<1,x);
    else if(x>=tr[k<<1|1].ly)return get(k<<1|1,x);
    return 0;
}
int ask(int k,int x,int y,int num)
{
    bool f=0;
    if(x<tr[k].ly){f=1;x=tr[k].ly;}
    if(tr[k].ly==x&&tr[k].ry==y)
    {
                  if(tr[k].mx>=num)return 0;
                  else if(tr[k].know&&!f)return 1;
                  else return 2;
                  }
    if(y<=tr[k<<1].ry)
    {         
         return ask(k<<1,x,y,num);
     }
    else if(x>=tr[k<<1|1].ly)
    {
         return ask(k<<1|1,x,y,num);
     }
    else 
    {
         int t1=ask(k<<1,x,tr[k<<1].ry,num);
         int t2=ask(k<<1|1,tr[k<<1|1].ly,y,num);
         if(!t1||!t2)return 0;
         else if(tr[k<<1].ry+1!=tr[k<<1|1].ly)return 2;
         else return 1;
     } 
}
int getnext(int k,int x)
{
    int l=tr[k].ly,r=tr[k].ry;
    if(l==r)return tr[k].ly;
    if(x<tr[k<<1].ry)return getnext(k<<1,x);
    else return getnext(k<<1|1,x);
}
int getlast(int k,int x)
{
    int l=tr[k].ly,r=tr[k].ry;
    if(l==r)return tr[k].ly;
    if(x>tr[k<<1|1].ly)return getlast(k<<1|1,x);
    else return getlast(k<<1,x);
} 
int main()
{
    scanf("%d",&n);
    build(1,1,n);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
            int l,r;
            scanf("%d%d",&l,&r);
            if(r<l){printf("false\n");continue;}
            int lnum=get(1,l),rnum=get(1,r);
            if(!lnum&&!rnum)printf("maybe\n");
            else 
			{
			int s=getnext(1,l),t=getlast(1,r);
            if(!lnum)
            {
            	if(s>t||r==t){printf("maybe\n");continue;}
           	    int f=ask(1,s,t,rnum);
            	if(f==0)printf("false\n");
				else printf("maybe\n");
            }
            else if(!rnum)
            {
            	if(s>t||l==s){printf("maybe\n");continue;}
           	    int f=ask(1,s,t,lnum);
            	if(f==0)printf("false\n");
				else printf("maybe\n");
            }
            else 
            {
            	if(rnum>lnum){printf("false\n");continue;}
            	if(s>t){
				     if(l+1==r) printf("true\n");
				     else printf("maybe\n");
				     continue;
					 }
            	int f=ask(1,s,t,rnum);
            	if(f==0)printf("false\n");
            	else if(f==1)
            	{
           	        if(l+1==s&&r-1==t)printf("true\n");
           	        else printf("maybe\n");
           	    }
            	else if(ask(1,s,t,rnum)==2)printf("maybe\n");
            	else printf("false\n");
            }
        }
    }
    return 0;
}

/*My code WA#1
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50000+10,INF=0x3f3f3f3f;
int mx[MAXN+3][30];
int Y[MAXN+3],R[MAXN+3],n;
int getmax(int x,int y){
	if(x>y)return -INF;//传进来的可能是非法的，因为不包含l,r两个端点，所以(l+1..r-1)可能不存在 
	int k=(y-x+1),c=0;
	while((1<<c+1)<=k)c++;
	return max(mx[x][c],mx[y-(1<<c)+1][c]);
}
int solve(int x,int y){//y is the max in [x+1..y] && v[x]>=y ->1
	if(y<x)return -1;
	int l=lower_bound(Y+1,Y+n+1,x)-Y,r=lower_bound(Y+1,Y+n+1,y)-Y;//l: >= x 的第一个位置 
	
	if(Y[l]!=x&&Y[r]!=y)return 0;
	if(Y[r]!=y){//Y[l]=x,Y[r]>y 
		if(getmax(l+1,r-1)>R[l])return -1;
		else return 0;
	}
	if(Y[l]!=x){//Y[l]>x,Y[r]=y 
		if(getmax(l,r-1)>=R[r])return -1;//注意是严格小于 
		else return 0;
	}
	//Y[l]=x,Y[r]=y 
	if(R[r]>R[l])return -1;
	//Y[l]=x,Y[r]=y,Y[r]<=Y[l]
	if(getmax(l+1,r-1)>=R[r])return -1;//注意是严格小于 
	return r-l+1==y-x+1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&Y[i],&R[i]);
	for(int i=1;i<=n;i++)mx[i][0]=R[i];
	for(int i=1;i<18;i++){
		for(int j=1;j+(1<<i)-1<=n;j++)mx[j][i]=max(mx[j][i-1],mx[j+(1<<i-1)][i-1]);
	}
	int m;scanf("%d",&m);
	for(int x,y;m;m--){
		scanf("%d%d",&x,&y);//cout<<solve(x,y)<<" ";
		switch(solve(x,y)){
			case 0:puts("maybe");break;
			case 1:puts("true");break;
			case -1:puts("false");break;
		}
	}
	return 0;
}*/

