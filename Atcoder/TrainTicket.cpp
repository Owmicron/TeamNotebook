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
#define pf push_front
#define pof pop_front
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
// end of Template

int op[4],dig[5];
str s;
bool valid = false;
bool validity(){
    int sum = 0;
    int a,b,c,d;
    a = dig[1];
    b = dig[2];
    c = dig[3];
    d = dig[4];

    if(op[1]==1){b*=-1;}
    if(op[2]==1){c*=-1;}
    if(op[3]==1){d*=-1;}

    sum = a+b+c+d;

    if(sum==7){return true;}
    else return false;
}
str sym(int x){
    if(x==0)return "+";
    else return "-";
}
void comb(){
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            for(int k=0;k<=1;k++){
                op[1] = i;
                op[2] = j;
                op[3] = k;
                valid = validity();
                if(valid){
                    cout<<dig[1]<<sym(op[1])<<dig[2]<<sym(op[2])<<dig[3]<<sym(op[3])<<dig[4]<<"=7\n";
                    break;
                }
            }
            if(valid)break;
        }
        if(valid)break;
    }
}
int main(){

//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s;
    for(int i=0;i<s.size();i++){
        dig[i+1] = numerize(s[i]);
    }
    comb();
}
