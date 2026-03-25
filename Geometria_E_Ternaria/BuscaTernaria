#include <bits/stdc++.h>
using namespace std;



double f(double x){
    return x * x;
}


double ter(double l, double r){
    for(int i=0;i<100;i++){

        double m1=l+(r-l)/3.0;
        double m2=r-(r-l)/3.0;

        if (f(m1)<f(m2)){
            r=m2;
        }
        else{
            l=m1;
        }
    }

    return l;
}