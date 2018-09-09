#include<bits/stdc++.h>
#include<math.h>
using namespace std;

#define e 2.71828

double func(double x){
    double p= pow(e,x);
    double r= pow(x,2);

    return p-5*r;
}


double false_position(double rL, double rU, double accuracy){
    double r=999999,re,root;

    puts("\ni\t  rL\t\t rU\t\t rMid\t\t Relative Approx Error\n");
    for(int i=1; ;i++){
        root= -1*func(rU)*(rU-rL)/(func(rU)-func(rL));

        if(i==1)
            re=0;
        else{
            re= abs((root-r)/root);
        }

        printf("%d\t %f\t %f\t %f\t %f %%\n",i,rL,rU,root,re);

        if(abs(root-r)<accuracy)
            break;

        r=root;

        if(func(root)>0)
            rU=root;

        else if(func(root)<0)
            rL=root;

        else
            break;

    }

    return root;

}

main(){

    //trace();

    double rL, rU,accuracy, root;
    puts("Enter lower boundary, upper boundary, and accuracy thershold: ");
    cin>>rL>>rU>>accuracy;

    root= false_position(rL,rU,accuracy);

    printf("\nRoot= %f\n",root);


}



