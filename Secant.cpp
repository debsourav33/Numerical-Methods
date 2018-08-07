#include<bits/stdc++.h>
#include<math.h>
using namespace std;

double f(double x){
    return pow(x,3)- .165*x*x+ 3.993e-4;
}


double f2(double x){
    return pow(x-4,2) * (x+2);
}

double Secant(double x0, double x1){
    int i=0;
    double re=0, tmp;

    double f_pr= (f(x0)-f(x1)/(x0-x1));

    puts("i\t Xi\t\t f(Xi)\t\t f'(Xi)\t\t Relative Approx Error\n");
    printf("%d\t %.10f\t %.10f\t %.10f\t %.10f %%\n",i,x0,f(x0),f_pr,re);

    while(1){
        re= abs((x1-x0)/x1 *100);

        f_pr= (f(x0)-f(x1)/(x0-x1));

        printf("%d\t %.10f\t %.10f\t %.10f\t %.3f %%\n",++i,x1,f(x1),f_pr,re);

        if(abs(x1-x0)<.0001)
            break;

        tmp= x1;
        x1= x1- ( f(x1)*(x0-x1)/ (f(x0)-f(x1) ));
        x0= tmp;



    }

    return x1;



}

main(){
    double x0=1, x1=-1, root;

    root= Secant(x0,x1);

    printf("\nRoot= %f\n",root);

}
