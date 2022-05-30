#include <iostream>
#include <gmp.h>
#include <tgmath.h>
using namespace std;

class Prime {
    private:
        int n_bytes;
        mpz_t q;
        
    public:

        void set_bytes(int b){
            n_bytes = b;
        }
        
        int get_bytes(){
            return n_bytes;
        }

        void generate_bytes_len_primes(mpz_t prime, mpz_t num){
            mpz_nextprime(prime, num);
            gmp_printf("2) We get the prime : %Zd \n", prime);
            gmp_printf("   Size in bits : %d \n", mpz_sizeinbase(prime, 2));
        }

        void get_random_int_in_range(mpz_t prime){
            gmp_randstate_t state;
            gmp_randinit_default(state);
            gmp_randseed_ui(state, time(NULL));
            mp_bitcnt_t n = n_bytes;

            mpz_urandomb(prime, state, n);
            gmp_printf("1) Initial number is : %Zd\n", prime);
            gmp_printf("   Size in bits : %d \n", mpz_sizeinbase(prime, 2));
        }

        void set_q(mpz_t prime){
            mpz_set(q, prime);
        }

        void print_stuff(){
            gmp_printf("Q is : %Zd\n", q);
        }

      
};

