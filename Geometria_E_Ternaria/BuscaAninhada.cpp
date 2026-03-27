#include <bits/stdc++.h>
using namespace std;

double f(double x,double y){
    return x +y;
}


double f_externa(double x){
    double ly=-1000,ry=1000;
    for(int i=0;i<80;i++){

        double my1=ly+(ry-ly)/3.0;
        double my2=ry-(ry-ly)/3.0;

        if(f(x,my1)<f(x,my2)) ry=my2; else ly=my1;

    }
    return f(x, ly); 
}

// na main:
    double lx = -1000, rx = 1000;

    for(int i = 0; i < 80; i++) {
        double mx1 = lx + (rx - lx) / 3.0;
        double mx2 = rx - (rx - lx) / 3.0;
        if (f_externa(mx1) < f_externa(mx2)) rx = mx2; else lx = mx1;
    }
// O ponto ideal de X está em lx