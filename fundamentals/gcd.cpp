#include <bits\stdc++.h>
using namespace std;

#define PERFORMANCE static int depth = 0; \
depth ++; \
printf("(%d, %d)\n", a, b); \
if(b==0) cout<< "DEPTH: "<<depth<<endl;

#define PRINT(x) printf("\t\"%s\", details: \n", #x);\
cout<<"MCD: "<<x<<endl;

int gcd_euclidean(int a, int b){

    PERFORMANCE

    if (b==0) return a;
    return gcd_euclidean(b,a%b);
}

int gcd_euclidean2(int a, int b){
    if (b>a) swap(a,b);

    PERFORMANCE
    
    if (b==0) return a;
    if (a>b) return gcd_euclidean2(b, a-b*int(a/b + 0.5));
    return gcd_euclidean2(a, b-a*int(b/a + 0.5));
}

int lsbgcd(int a, int b) {
    if (b>a) swap(a,b);

    PERFORMANCE

    if (b==0) return a;
    int s=0;
    while(a>b*1<<s) s++;
    return lsbgcd(min(a-b*pow(2,s-1), b*pow(2,s)-a), b);
}

int main() {
    int a = 13, b= 21;
    PRINT( gcd_euclidean(a,b))
    PRINT( gcd_euclidean2(a,b))
    PRINT( lsbgcd(a,b))
}
