#include <iostream>
#include <cmath>
using namespace std;

// Function to compute the value of the equation at a given point x
double fun(double x, double coef[], int n){
    double result = 0;
    for(int i = 0; i <= n; ++i){
        result += coef[i] * pow(x, n - i);
    }
    return result;
}

double root(double x1, double x2){
    return (x1+x2)/2;
}

int main(){
    int n; // Highest power of the equation
    cout << "Enter the highest power of the equation: ";
    cin >> n;

    double coef[n+1]; // Coefficients of the equation
    cout << "Enter the coefficients of the equation from highest power to constant term: ";
    for(int i = 0; i <= n; ++i){
        cin >> coef[i];
    }

    double x1, x2, x0, stopping_error, error;
    double xnew, xold = 0;
    double f1, f2, f0;
    int iteration;
    cout << "Enter initial values of x1 and x2 : ";
    cin >> x1 >> x2;
    cout << "Enter iteration and stopping error : ";
    cin >> iteration >> stopping_error;

    for(int i = 1; i <= iteration; i++){
        x0 = root(x1, x2);
        f1 = fun(x1, coef, n);
        f2 = fun(x2, coef, n);
        f0 = fun(x0, coef, n);

        //Error part
        xnew = x0;
        error = (xnew - xold)*100/xnew;
        xold = x0;

        cout << "Iteration " << i << " : "<< endl<< "x1 = "
        << x1 << ", x2 = " << x2 << ", x0 = " << x0 <<
        ", f1 = " << f1 << ", f2 = " << f2 << ", f0 = " << f0 << endl;

        if(f1*f2 > 0){
            break;
        }else if(error <= stopping_error){
            break;
        }else if(f1*f0 < 0){
            x2 = x0;
            f2 = f0;
        }else if(f1*f0 > 0){
            x1 = x0;
            f1 = f0;
        }
    }
    return 0;
}
