 #include <iostream>
//  #include "cryptopp860/cryptlib.h"
//  #include "cryptopp860/integer.h"
//  #include "cryptopp860/osrng.h"
//  #include "cryptopp860/algparam.h"
#include <gmp.h>
#include <tgmath.h>
 using namespace std;
//  using namespace CryptoPP;

class BivPoly_Com {
    private:
        const int secure_lambda_param = 1024;
        mpz_t q;
        
    public:
        void generate_bytes_len_primes(mpz_t prime, mpz_t num){
            // mpz_t x;
            // mp_bitcnt_t b = bytes;
            // mpz_init (x);
            mpz_nextprime(prime, num);
            gmp_printf("2) We get the prime : %Zd \n", prime);
            gmp_printf("   Size in bits : %d \n", mpz_sizeinbase(prime, 2));
        }

        void get_random_int_in_range(mpz_t prime){
            gmp_randstate_t state;
            gmp_randinit_default(state);
            gmp_randseed_ui(state, time(NULL));
            mp_bitcnt_t n = secure_lambda_param;

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



int main() {
    mpz_t prime;
    mpz_init(prime);
    BivPoly_Com com;
    com.get_random_int_in_range(prime);
    com.generate_bytes_len_primes(prime, prime);
    com.set_q(prime);
    com.print_stuff();
    return 0;
}

/*

int generator(int lambda) {

}

class Biv_ComGen {

}

class Biv_Com {

}

class Biv_ComVer {

}

class Biv_OpenVer {

}

*/