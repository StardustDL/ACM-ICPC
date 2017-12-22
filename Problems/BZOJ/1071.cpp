/*
[SCOI2007]���
������A * ( height �C minH ) + B * ( speed �C minV ) <= C���Ի�Ϊ A*height+B*speed-C <= A*minh + B*minv 
	  �ȸ�sum = A * h + B * s�����ٸ�h����Ȼ��ö��h��s����Сֵ��(h -- Height, s -- Speed)
	  Ȼ��ά������ �����ָ�롣�ǳ������� 
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN=5000;
struct data{
    int s,h,sum;
}x[MAXN+3], y[MAXN+3];
inline bool cmp1(const data &a, const data &b){
    return a.h < b.h;
}
inline bool cmp2(const data &a, const data &b){
    return a.sum < b.sum;
}
int n,Maxs,Mins,l,r,cnt,ans;
int A,B,C;
inline bool check1(int p){
    return y[p].s <= Maxs && y[p].s >= Mins;
}
inline bool check2(int p){
    return x[p].s <= Maxs && x[p].s >= Mins;
}
int main(){
    scanf("%d", &n);
    scanf("%d%d%d", &A, &B, &C);
    for (int i = 1; i <= n; ++i){
        scanf("%d%d", &x[i].h, &x[i].s);    
        x[i].sum = A * x[i].h + B * x[i].s;
        y[i] = x[i];
    }
    sort(x + 1, x + n + 1, cmp1);//��h 
    sort(y + 1, y + n + 1, cmp2);//��sum 
    for (int i = 1; i <= n; ++i){//ö����С��speed 
        Mins = x[i].s, Maxs = Mins + C / B; 
        //Ҫ������Ͻ磬��������Ͻ���ζ�ţ�����ĵ�һ������ʽ��A*h<A*minh�����ǲ��Ϸ��ģ������Ϸ�ȴ���ᱻ�ڶ���ѭ������������Ϊl�������������ǰ���h�����û���Ͻ磬��ôlǰ��ľͻ��ظ����� 
        l = 0, r = 0, cnt = 0;
        for (int j = 1; j <= n; ++j){//ö����С��height
            while (r < n && y[r + 1].sum <= A * x[j].h + B * x[i].s + C)//����������һ��ֻ��֤sum��ȷ 
                ++r, cnt += check1(r);
            while (l < n && x[l + 1].h < x[j].h)//�ڶ��μ��߶Ȳ����㣬ͬʱ�ֱ���һ����ӽ�ȥ�� 
                ++l, cnt -= check2(l);
            ans = max(ans, cnt);
        }
    }
    printf("%d\n", ans);
    return 0;
}
