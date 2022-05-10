#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


const int POLY_SIZE = 100;

class Polynomials {
    private:
        int degree;
        int coefs[POLY_SIZE];    
    
    public:
        Polynomials() {
            for (int i = 0; i < POLY_SIZE; i++){
                coefs[i] = 0;
            }
        }

        void set_coefs(int c, int pos) { 
            coefs[pos] = c;
            degree = degree_setter();
        }

        int degree_setter() {
            int d = 0;
            for (int i = 0; i < POLY_SIZE; i++) {
                if (coefs[i] != 0) {
                    d = i;
                }
            }
            return d;
        }

        
};



int main(){
    return 0;
}