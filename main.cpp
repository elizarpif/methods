#include <iostream>
#include <random>
#include <cmath>
#include <limits>

using namespace std;

//полученная рекуррентная формула
//a(n+1) = a(n) * (4n+10) / (n+1) * x

//функция, высчитывающая номер n, с которого разница справа и слева будет минимальная
void difference(long double right_sum, long double x){

    long double a0 = 6.0, sum = a0, tmp; //укажем первый член ряда

    long double dif = powl(10, -10); //и разницу

    //установим количество цифр, выводимых на консоль
    cout.setf(std::ios::fixed);
    cout.precision(11);

    //cout<<"sum = "<<sum<<", a0 = "<<a0<<endl;
    int i = 0;

    while (abs(sum - right_sum) >= dif){

        tmp = (4.00 * i + 10.00)/(i + 1.00);
        a0 *= x*tmp;
        sum += a0;

        i++;

    }
    cout << "i = " << i + 1 << endl << "sum_1 = " << sum << endl << "sum_2 = " << right_sum << endl << "ak = " << a0 << endl;
}



int main()
{
    //x in [-1/4;1/4)
    //задаем начальные значения
    long double x=0.05;

    long double a = 1.0-x*4.0, b = -1.0 * (5.0/2.0);

    long double rightRes = 6*pow(a,b);

    difference(rightRes, x);

    return 0;
}

//ниже неиспользуемые функции

long double getRes(){
    long double res = rand()%25*0.001;
    cout<<"rand = "<<res<<endl;
    return res;
}


bool is_equal(double x, double y) {
    return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}

