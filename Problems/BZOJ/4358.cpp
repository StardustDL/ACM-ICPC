/*
permu
�����������ѯ��֧�����ߣ�Ī�ӣ�����L�ֿ�
	  ���ֻ���ǲ�ɾ���������ÿ����һ��������ֱ���ò��鼯ά����
	  ��Ī�ӷֿ�󣬶�����˵���ͬһ�����ѯ�ʣ��Ҷ˵��Ǵ�С�����ŵģ����Ƕ�����˵��ǿ��������Ϳ���ֻ���벻ɾ���� 
	  Ȼ���������˵��������ǿ�ı��ˣ�����ͳ�ơ� 
*/
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=50000,BS=300;
int m,n,a[MAXN+3],blo[MAXN+3],fa[MAXN+3],sz[MAXN+3],rk[MAXN+3],pos[MAXN+3],Ans[MAXN+3];
struct query{int l,r,id;bool operator <(const query&b)const{return(blo[l]<blo[b.l])||(blo[l]==blo[b.l])&&(r<b.r);}}q[MAXN+3];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void unite(int l,int r){
	l=find(l),r=find(r);
	fa[r]=l,sz[l]+=sz[r];
}
int main(){
	scanf("%d%d",&n,&m); 
    for(int i=1;i<=n;++i)scanf("%d",&a[i]); 
    for(int i=1;i<=m;++i){scanf("%d%d",&q[i].l,&q[i].r);q[i].id=i;}
    for(int i=1;i<=n;++i)blo[i]=i/BS;
    sort(q+1,q+m+1);
    for(int curb=-1,curr=0,L,R,ans,i=1;i<=m;++i){//ansά��ʹ��[R+1..q[i].r]��������ܵõ��������������  
    	int &qans=Ans[q[i].id]; 
        if(blo[q[i].l]!=curb){//��˵��������� 
            memset(fa,0,sizeof(fa));memset(sz,0,sizeof(sz));
            L=blo[q[i].l]*BS+1,R=min(n,L+BS-1);//������˵����������Ϣ������Ĵ���ʽ�Ǳ�������û�мӵ����鼯�У����鼯ֻά�������֮���ֵ 
            for(int j=L;j<=R;++j)pos[a[j]]=j,rk[j]=a[j];//pos[i]ά��i�����������a�е�λ�ã�rk[i]��ʾ�ŵ�iλ�����Ǽ� 
            curr=R;sort(rk+L,rk+R+1);ans=0;//curRά����ǰά�������Ҷ˵� 
        }
        curb=blo[q[i].l];
        if(q[i].r<=R){//q[i].l��q[i].r����ͬһ�� 
            for(int cnt=0,last=-1,j=L;j<=R;++j){
                int k=rk[j];
                if(pos[k]>=q[i].l&&pos[k]<=q[i].r){ 
					cnt=1+(last==k-1?cnt:0);
                	qans=max(qans,cnt);
					last=k;
				}
            }
			continue;
        }
        while(curr<q[i].r){//�����Ҷ˵������ 
            int k=a[++curr];
			fa[k]=k,sz[k]=1;
            if(find(k+1))unite(k,k+1);
            if(find(k-1))unite(k,k-1);
            ans=max(ans,sz[k]);//ά��ans�������´�ѭ�����������ã�ֻҪ��˵����ڿ鲻�䣩 
        }
		qans=ans;
        for(int cnt=0,last=-1,j=L;j<=R;++j){//���ǽ���˵����ڿ�[L..R]����[R+1..q[i].r]��������ܵõ�������������� 
            int k=rk[j];
            if(pos[k]>=q[i].l){//Ҫ�������Ҫ��ѯ�������� 
            	//����һ�����У������������ֻ����һ�ֳ��� 
                if(find(k-1))cnt=find(last+1)==fa[k-1]?cnt+1:sz[fa[k-1]]+1;//��һ�����ڵ�(last+1)��k-1������ͨ����ͬ������������һ�𣩣�����������1(������һ��k) 
                else if(last==k-1)++cnt;//��ͨ�����鼯��ֱ�Ӿ��ǰ��ŵģ�cnt����1 
				else cnt=1;
                if(find(k+1))cnt+=sz[fa[k+1]];
				last=k;
                qans=max(qans,cnt);
            }
        }
    }
    for(int i=1;i<=m;++i)printf("%d\n",Ans[i]);
}
