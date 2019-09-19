#include <iostream>
#include <random>
#include <cmath>
#include <limits>
using namespace std;

//a(n+1) = a(n) * (4n+10) / (n+1) * x
void difference(long double right_sum, long double x){
    int i = 1;

    long double a0 = 6.0*powl(x,0), sum = a0, tmp;
    long double dif = powl(10, -10);

    std::cout.setf(std::ios::fixed);
    std::cout.precision(11);

    cout<<"sum = "<<sum<<", a0 = "<<a0<<endl;

    while (abs(sum - right_sum) >= dif){

        tmp = (4*i+10);
        tmp /= i+1;
       // cout<<"tmp = "<<tmp;
        a0 = a0 * x*tmp;
        sum += a0;

       //if(i % 100000 == 0)
           cout<<"rigth_sum = "<<right_sum<<", sum = "<<sum<<", a"<<i<<" = "<<a0<<endl;
        i++;

    }
    cout << "i = " << i << endl << "sum = " << sum << endl << "ak = " << a0;
}



int main()
{
    //x in [-1/4;1/4)

    long double x=0.2;
    long double t1 = -5.0;
    long double t2 = 2.0;
    long double a = 1.0-x*4.0, b = t1/t2;

    long double rightRes = pow(a,b);
    cout<<"pow = "<<rightRes;
    rightRes *=6;
    rightRes -= 60*pow(x,-1.3);

    cout << "right_sum = " << rightRes <<", x="<<x<< endl;

    difference(rightRes, x);
    return 0;
}



long double getRes(){
    long double res = rand()%25*0.001;
    cout<<"rand = "<<res<<endl;
    return res;
}


bool is_equal(double x, double y) {
    return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}