#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){

        int s[9][9];
        vector<pair<int,int>> vazios;

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                cin>>s[i][j];
                if(s[i][j]==0){

                    vazios.push_back({i, j});
                }
            }
        }

        int k=0;
        bool possivel=true;
        int n_vazios=vazios.size();

        while(k>=0 && k<n_vazios){

            int r=vazios[k].first;
            int c=vazios[k].second;
            int v=s[r][c]+1;
            bool achou=false;

            while(v<=9){

                bool pode=true;
                for(int i=0;i<9;i++){

                    if(s[r][i]==v || s[i][c]==v){

                        pode=false;
                        break;
                    }
                }

                if(pode){

                    int start_r=(r/3)*3;
                    int start_c=(c/3)*3;
                    for(int i=0;i<3;i++){
                        for(int j=0;j<3;j++){

                            if(s[start_r+i][start_c+j]==v){

                                pode=false;
                                break;
                            }
                        }

                        if(!pode) break;
                    }
                }

                if(pode){

                    s[r][c]=v;
                    achou=true;
                    break;
                }
                v++;
            }

            if(achou){

                k++;
            }
            else{

                s[r][c]=0;
                k--;
            }
        }

        if(k==n_vazios){
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){

                    cout<<s[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
        else{

            cout<<"No solution\n";
        }
    }
//a
}