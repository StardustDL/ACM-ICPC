/*
���յ���
����������+��֦�������ԺͿ����ԣ�ע��ֻ��������ʱ��������ɣ���Ϊ�������������ǵ������2�� 
*/
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f;
int m,n,ans,mins[25],minv[25];;
void dfs(int curf,int lastr,int lasth,int leftv,int sum){//д�Ķ�һ��͸����һЩ�������ܹ����������ʹ�ã�curf����ǰ������lastr����һ�㵰��İ뾶ֵ��lasth����һ�㵰��ĸ߶ȣ�leftv�����µĿ�ʹ�������sum�����쵰�������ĺͣ������ײ�ĵ������
    int maxh,curv,curs,h;
    if(sum+mins[curf]>=ans||leftv<minv[curf])return;//��֦������������1.��ǰ�����+��С�Ŀɼ������Ҫ����С�ļ�¼�������ô��Ҫ��֦��2.��ǰ��ʣ�����ֵ����С��ʣ�����ֵС����ô��֦
    if(curf==0){
        if(leftv==0&&sum<ans)ans=sum;//��ǰ������0����ʣ�����Ϊ0������Сֵmin���ڸ�����sumֵ������м�¼
        return;
    }
    for(int i=lastr-1;i>=curf;i--){//���i��ֵ��curfС�ˣ��Ժ��û�����𽥽���С�ˣ�ö��i
        h=(int)((leftv-minv[curf-1])/(double)(i*i));//��֦����h����ֵ��h/i*i��
        maxh=min(h,lasth-1);
        for(int j=maxh;j>=curf;j--){
            curs=2*i*j;
            curv=i*i*j;
            if(2*(leftv-curv)/i+sum+curs>=ans)continue;//��֦,�����ǰ��С���>=�Ѿ���õ����
            if(curf==m) curs+=i*i;//�����ǰ����Ϊ��m�㣬����Ҫ���ϵ����
            dfs(curf-1,i,j,leftv-curv,sum+curs);//�ݹ����
        }
    }
}
int main(){
    for(int i=1;i<=20;i++){//�������������ں���ļ�֦����Ϊr��h��ֵ�������μ�һ�ģ����ʣ���ֵ�������漸���𽥼�һ�Ļ��϶�Ҫ��֦���������������������Ȼ��������������ļ�֦���д���
        mins[i]=mins[i-1]+2*i*i;//����Ӹýڵ㵽Ŀ��ڵ���С�����ֵ�����ϼ��㵰��������������һ�㵰��Ĳ����ֵ������С��rֵǰ���£��������Ժ�ıȽ��Լ�����
        minv[i]=minv[i-1]+i*i*i;//ͬ������ýڵ㵽Ŀ��ڵ���С�����ֵ�����ϼ��㵰�������������һ�㵰������ֵ����һ�㵰������ֵ����Ϊr*r*h����������hҲ����r�ĵݼ����ʣ���������ط�������i������
    }
    while(scanf("%d%d",&n,&m)!=EOF&&m&&n){
        ans=INF;
        int beg=(int)sqrt(n/(double)m)+1;
        dfs(m,beg,beg,n,0);
        if(ans==INF)printf("0\n");
        else printf("%d\n",ans);
    }
    return 0;
}
