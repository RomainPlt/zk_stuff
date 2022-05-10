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

        void set_all_coefs(int *c, int size){
            for (int i = 0; i < size ; i++){
                (*this).set_coefs(c[i], i);
            }
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

        int* get_coefs(){
            return (*this).coefs;
        }

        int get_degree(){
            return (*this).degree;
        }

        void print_poly(){
            cout << "Polynomial degree is : " << (*this).degree << "\n";
            cout << "And its coefficients are : \n{";
            for (int i = 0; i < (*this).degree; i++){
                cout << (*this).coefs[i] << ", ";
            }
            cout << (*this).coefs[(*this).degree] << "}\n\n";

        }

        void addition(int s, int pos){
            (*this).coefs[pos] = (*this).coefs[pos] + s;
        }

        void poly_addition(Polynomials poly){
            int d = poly.get_degree();
            int* coefs = poly.get_coefs();

            for (int i = 0; i < ((d < (*this).degree) ? d : (*this).degree); i++){
                (*this).addition(coefs[i], i);
                // (*this).coefs[i] = (*this).coefs[i] + coefs[i];
            }
        }

        
        void multiplication(Polynomials poly){

        }

        
};



int main(){

    Polynomials poly;
    int c[] = {10,23,40, 4, 15};
    int size_of_c = sizeof(c)/sizeof(c[0]);

    poly.set_all_coefs(c, size_of_c);
    poly.print_poly();


    Polynomials poly2;
    int c2[]  = {1,2,3};
    int size_of_c2 = sizeof(c2)/sizeof(c2[0]);

    poly2.set_all_coefs(c2, size_of_c2);
    poly2.print_poly();

    poly.poly_addition(poly2);
    poly.print_poly();

    return 0;
}