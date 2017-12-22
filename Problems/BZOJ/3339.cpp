/*
Rmq Problem
�����������ȱ����������mex[1..i]��Ȼ��ע��mex�ǵ������ģ�
		ά����ǰ��˵�Ϊl��mex���顣 
		����ѯ�ʣ�����˵����򣬵���˵�=��ǰ��˵��ʱ��ֱ�����
		��������ڣ���ô���Ǽ�¼��ǰ����һ������λ��next[i]
		��ô[i+1..next[i]-1]��Щλ�õ�mexֵֻҪ����a[i]�ģ��ͻ�����a[i]����Ϊmex�ǵ����ģ����Դ�next[i]-1��i+1�����£�һ�����ܸ��¾�break 
	  ��ȷ���Ӷȵ��㷨���߶����޸�
	  ����Ī��+Ȩֵ�ֿ飺����ÿ�β�ѯ������[l,r]����Ȩֵ�ֿ飬ά��ÿһ�������ֵĳ��ִ�������ÿ��Ȩֵ�ĳ��ִ�������Ϊmexֵ���ᳬ�����䳤�ȣ��������ǾͿ�����O(��n)��ʱ���ڵõ�һ��û��ȫ�����ǵ����䣬Ȼ����O(��n)��ʱ�䱩��ö�ٵ�ǰ���ڵ�ÿ���������Ƿ���ֹ������ɵõ��𰸡����Ƿ���ͳ�Ƶ���Ϣ������O(1)��ʱ����ת�ƣ�������Ī���㷨��֧�ֶ��ѯ�ʡ� 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=200000;
typedef int arr[MAXN+3];
arr a,v,last,mex,next,ans;
int n,q;
struct query{int l,r,id;}qs[MAXN+3];
bool cmp(query x,query y){return x.l<y.l;}
void change(int x){
	int ed=next[x]?next[x]:(n+1);
    mex[x]=0;
    for(int i=ed-1;i>x;i--){//���ﵹ�Ÿ��£� ���͸��Ӷ� 
        if(mex[i]<=a[x])break;
        mex[i]=a[x];
    }
}
int main(){
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int cur=0,i=1;i<=n;i++){
    	v[a[i]]=1;
        while(v[cur]!=0)cur++;
        mex[i]=cur;
    }
    for(int i=1;i<=n;i++){
        next[last[a[i]]]=i;
        next[i]=n+1;
        last[a[i]]=i;
    }
    for(int i=1;i<=q;i++){
        scanf("%d%d",&qs[i].l,&qs[i].r);
        qs[i].id=i;
    }
    sort(qs+1,qs+1+q,cmp);
    int curl=1;
    for(int i=1;i<=q;i++){
    	for(int j=curl;j<qs[i].l;j++)change(j);
        ans[qs[i].id]=mex[qs[i].r];
        curl=qs[i].l;
    }
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}
