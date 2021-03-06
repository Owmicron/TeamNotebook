#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector <pii> vpii;
typedef vector <pll> vpll;
typedef map <str,int> mapsi;
typedef map <str,int> :: iterator mapsitr;
typedef map <int , int> mint;
typedef map <ll , ll> mll;
typedef set <int> si;
typedef set <ll> sll;
typedef si :: iterator sitr;
typedef si :: reverse_iterator rsitr;
typedef sll :: iterator sltr;
typedef sll :: reverse_iterator rsltr;
#define mset multiset
typedef mset <int> msi;
typedef mset <ll> msll;
typedef msi :: iterator msitr;
typedef msi :: reverse_iterator msritr;
typedef msll :: iterator msltr;
typedef msll :: reverse_iterator mslritr;
#define mp make_pair
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define fs first.second
#define ss second.second
#define ff first.first
#define sf second.first
#define newl '\n'
char to_upper (char x){
    if( 97 <= int(x) && int(x) <= 126)return char(x-32);
    else if( 65 <= int(x) && int(x) <= 90)return x;
}
char to_lower (char x){
    if( 97 <= int(x) && int(x) <= 126)return x;
    else if( 65 <= int(x) && int(x) <= 90)return char(x+32);
}
int numerize (char x){
    if(48 <= int(x) && int(x) <= 57)return int(x-'0');
    else if( 97 <= int(x) && int(x) <= 126)return int(x-96);
    else if( 65 <= int(x) && int(x) <= 90)return int(x-64);
}
//void IO(){
//	#ifndef ONLINE_JUDGE
//	    freopen("input.txt", "r", stdin);
//	    freopen("output.txt", "w", stdout);
//	#endif
//}
// end of Template

ll pre[300],t,n;
ll kth(ll digit , ll x){
    stack <ll> s;
    while(x>0){
        s.push(x%10);
        x/=10;
    }
    for(int i=1;i<digit;i++)s.pop();
    return s.top();
}
int main(){
	//IO();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    t = 1;
    for(int i=1;i<=13;i++){
        pre[i] = pre[i-1];
        pre[i] += 9 * t * i;
        t*=10;
    }

    cin>>n;
    for(int i=1;i<=13;i++){
        if(n<=pre[i]){
            n-=pre[i-1];
            ll start = 1;
            for(int j=1;j<i;j++){
                start *=10;
            }
            start--;
            ll x = n/i;
            if(n%i!=0)x++;
            ll k = n%i;
            if(k==0)k=i;
            ll num = start + x;

            cout<<kth(k,num)<<newl;
            break;
        }
    }


}
