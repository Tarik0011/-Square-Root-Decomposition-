
/*
*   -------------- ?*?*? --------------
* |         In The Name of *Allah*     |
* |             Author : Tarik         |
* |                                    |
*  -------------- ?*?*? ---------------
*/
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define  pb        push_back
#define  all(v)    v.begin(),v.end()
#define  endl       '\n'  
#define  uint       long long
#define  int        long long
#define  BLOCK        700
#define  fastio    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set; 
 
const int mxn=1e6+123;
int a[mxn],ans[mxn],fre[mxn];
struct query{
	int l;
	int r;
	int i;
};
query Q[mxn];
int cnt=0;
bool cmp(query a,query b){
	if(a.l/BLOCK!=b.l/BLOCK)return a.l/BLOCK<b.l/BLOCK;
	else return a.r<b.r;
}
void add(int pos){
	fre[a[pos]]++;
	if(fre[a[pos]]==1)cnt++;
}
void remove(int pos){
	fre[a[pos]]--;
	if(fre[a[pos]]==0)cnt--;
}
void solve(){
	int n,q;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>Q[i].l>>Q[i].r;
		Q[i].i=i;
	}
	sort(Q+1,Q+q+1,cmp);
	//for(int i=1;i<=q;i++)cout<<Q[i].l<<" "<<Q[i].r<<endl;
	
	int ml=0,mr=-1;
	for(int i=1;i<=q;i++){
		int L=Q[i].l;
		int R=Q[i].r;
		while(ml>L){
			ml--,add(ml);
		}
		while(mr<R){
			mr++,add(mr);
		}
		while(ml<L){
			remove(ml),ml++;
		}
		while(mr>R){
			remove(mr),mr--;
		}
		ans[Q[i].i]=cnt;
	}
	for(int i=1;i<=q;i++)cout<<ans[i]<<endl;
	cout<<endl;
	
 
}
signed main(){ 
    fastio; 
    int t=1;
    //cin>>t;
    while(t--){
       solve();
    }
} 
