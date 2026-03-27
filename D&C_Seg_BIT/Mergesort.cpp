#include <bits/stdc++.h>
#define int long long
using namespace std;

int inversoes=0;
vector<int> temp; 

void merge_sort(vector<int>& a,int l,int r){
    if(l>=r) return;
    
    int mid=l+(r-l)/2;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);

    int R=mid+1; 
    for(int i=l;i<=mid;i++){
        while(R<=r && a[R]<=a[i]){ 

            R++;
        }
        inversoes+=(R-(mid+1)); 
    }

    int i=l, j=mid+1, k=l;
    while(i<=mid && j<=r){

        if(a[i]<=a[j]) temp[k++]=a[i++];
        else temp[k++]=a[j++];
    }
    
    while(i<=mid) temp[k++]=a[i++];
    while(j<=r) temp[k++]=a[j++];
    
    for(int p=l;p<=r;p++) a[p]=temp[p];
}

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        temp.resize(n);  
        inversoes=0;   

        merge_sort(a,0,n-1);

        cout<<inversoes<<'\n';
    }

}