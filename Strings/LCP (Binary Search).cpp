#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5+10;

const int P1=31;
const int P2=37;
const int M1=1e9+33;
const int M2=1e9+93;

int h1[MAXN],h2[MAXN],p1[MAXN],p2[MAXN];

pair<int,int> substr_hash(int i,int j){

    int len=j-i+1;
    int hash1=(((h1[j+1]-(h1[i]*p1[len])%M1)%M1)+M1)%M1;
    int hash2=(((h2[j+1]-(h2[i]*p2[len])%M2)%M2)+M2)%M2;
    return {hash1,hash2};
}

int get_lcp(int i,int j,int n){

    int l=1,r=min(n-i,n-j),ans=0;
    while(l<=r){

        int mid=(l+r)/2;
        if(substr_hash(i,i+mid-1)==substr_hash(j,j+mid-1)){

            ans=mid;
            l=mid+1;
        }
        else{

            r=mid-1;
        }
    }
    return ans;
}

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    p1[0]=1;
    p2[0]=1;
    for(int i=1;i<MAXN;i++){

        p1[i]=(p1[i-1]*P1)%M1;
        p2[i]=(p2[i-1]*P2)%M2;
    }

    string s;
    cin>>s;
    int n=s.size();

    h1[0]=0;
    h2[0]=0;
    for(int i=0;i<n;i++){

        int val=s[i];
        h1[i+1]=(h1[i]*P1+val)%M1;
        h2[i+1]=(h2[i]*P2+val)%M2;
    }

    /*
    se quiser comparar duas strings diferentes, concatena como s1+'#'+s2
    i é o começo da primeira (0) e j é o começo da segunda (s1.size()+1)
    */

    return 0;
}