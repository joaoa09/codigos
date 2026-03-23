#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Point{
    int x, y;
    
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    // Operações com outros pontos (Vetores)
    Point operator+(Point p) const { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) const { return Point(x - p.x, y - p.y); }
    
    // Operações com constantes (Escalares)
    Point operator*(int c) const   { return Point(x * c, y * c); }
    Point operator/(int c) const   { return Point(x / c, y / c); }
    
    // Produtos (Retornam inteiros! Sem erro de precisão)
    int operator*(Point p) const   { return x * p.x + y * p.y; }
    int operator^(Point p) const   { return x * p.y - y * p.x; }
    
    // Comparadores (Cruciais para ordenar pontos no Convex Hull)
    bool operator<(Point p) const  { return x < p.x || (x == p.x && y < p.y); }
    bool operator==(Point p) const { return x == p.x && y == p.y; }
};

const int MAXN=200005;
Point pts[MAXN];
Point hull[MAXN];
int N, hull_sz;


// > 0 (Curva à esquerda / Anti-horário)
// < 0 (Curva à direita / Horário)
// = 0 (Colineares)
int cross(Point a, Point b, Point c) { 
    return (b - a) ^ (c - a); 
}

double norm(Point p) { return hypot(p.x, p.y); }
double dist(Point p, Point q) { return hypot(p.x - q.x, p.y - q.y); }

void convex_hull(){

    sort(pts,pts+N);

    bool colinear=true;
    
    for(int i=2;i<N;i++){
        if(cross(pts[0],pts[1],pts[i])!=0){

            colinear=false;
            break;
        }
    }
    
    if(colinear){
        hull_sz = N;
        for(int i = 0; i < N; i++) hull[i] = pts[i];
        return;
    }

    hull_sz=0;
    
    //Lower Hull
    for(int i=0;i<N;i++){

        while(hull_sz>=2 && cross(hull[hull_sz-2],hull[hull_sz-1],pts[i])<0) hull_sz--;
        hull[hull_sz++]=pts[i];
    }
    
    //Upper Hull
    for(int i=N-2,t=hull_sz+1;i>=0;i--){

        while(hull_sz>=t && cross(hull[hull_sz-2],hull[hull_sz-1],pts[i])<0) hull_sz--;
        hull[hull_sz++]=pts[i];
    }
    
    hull_sz--;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
        
        cin>>N;
        for(int i=0;i<N;i++){

            cin>>pts[i].x>>pts[i].y;
        }

        convex_hull();
        
    
    
    return 0;
}