#include <iostream>

using namespace std;

int main() {
    long long int N = 0;
    cin >> N;

    long double lower = 0;
    long double bigger = 0;
    long double max_mist = 1e-17;

    for (long long int i = 0; true; i++) {
        if (i * i > N) {
            bigger = i;
            lower = i - 1;
            break;
        }
    }

    long double root = lower;

    for (int i = 0; true; i++) {
        if (root * root < N) {
            lower = root;
            root = root + (bigger - lower) / 2;
        }
        else {
            bigger = root;
            root = root - (bigger - lower) / 2;
        }
        if ((N - root * root >= 0 && N - root * root <= max_mist) || 
            (N - root * root <= 0 && N + root * root <= max_mist)) break;
        if (i == 100000) { 
            //cout << "too many\n"; 
            break; 
        }
    }
    cout.precision(32);
    cout << root << endl;
    cout << root * root;
}