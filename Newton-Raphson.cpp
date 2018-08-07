#include<bits/stdc++.h>
#include<math.h>
using namespace std;

double f(double x){
    return pow(x,3)- .165*x*x+ 3.993e-4;
}

double f_prime(double x){
    return 3*x*x- .33*x;
}

double f2(double x){
    return pow(x-4,2) * (x+2);
}

double f2_prime(double x){
    return 2*(x-4)*(x+2)+pow(x-4,2);
}

double Newton_Raphson(double x){
    int i=0;
    double re=0, tmp;

    puts("i\t Xi\t\t f(Xi)\t\t f'(Xi)\t\t Relative Approx Error\n");

    while(1){
        printf("%d\t %.10f\t %.10f\t %.10f\t %.3f %%\n",i++,x,f(x),f_prime(x),re);

        tmp= x;
        x= x- f(x)/f_prime(x);

        if(abs(x-tmp)<.0001)
            break;

        re= abs((x-tmp)/x *100);
    }

    return x;

}


main(){
    double x=-2.3, root;

    root= Newton_Raphson(x);

    printf("\nRoot= %f\n",root);
}
