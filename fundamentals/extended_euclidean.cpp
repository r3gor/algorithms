#include <iostream>
#include <tuple>

std::tuple<int,int,int> extended_euclidean(int a, int b) {

    int r0 = a>b? a:b;
    int r1 = r0==a? b:a;
    int s0=1, s1=0, t0=0, t1=1;

    while (r1 != 0) {
        int r = r0 % r1;
        int q = int(r0/r1);
        int s = s0 - q * s1;
        int t = t0 - q * t1;

        r0 = r1;
        r1 = r;
        s0 = s1;
        s1 = s;
        t0 = t1;
        t1 = t;
    }

    return std::make_tuple(r0, s0, t0);
}

int inverse_mod(int n, int m) {
    int mcd, s, t;
    std::tie(mcd, s, t) = extended_euclidean(n, m);
    if (mcd != 1)
        throw std::overflow_error("GCD is not one, inverse modular doesn't exist\n");
    return n<m? t%m:s%m;
}

int main() {
    int mcd, s, t;
    int a=4013, b=4057;
    std::tie(mcd, s, t)= extended_euclidean(a,b);
    printf("\t.::Bezout Coeficients::.\n");
    printf("MCD(%d, %d) = %d = %d*(%d) + %d*(%d) \n", a,b,mcd,a,s,b,t);

    printf("\t.:: 4013^(-1) mod 4057 ::.\n");
    printf(" = %d\n", inverse_mod(4013, 4057));

    printf("\t.:: 4057^(-1) mod 4013 ::.\n");
    printf(" = %d\n", inverse_mod(4057, 4013));

    printf("\t.:: 2^(-1) mod 4 ::.\n");
    try {
        printf(" = %d\n", inverse_mod(2, 4));
    } catch (std::overflow_error e) {
        std::cout << e.what() ;
    }

    printf("\t.:: END ::.");


}