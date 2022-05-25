 #include <iostream>
//  #include "cryptopp860/cryptlib.h"
//  #include "cryptopp860/integer.h"
//  #include "cryptopp860/osrng.h"
//  #include "cryptopp860/algparam.h"
#include <gmp.h>
#include <tgmath.h>
 using namespace std;
//  using namespace CryptoPP;

class bivPoly_Com {
    private:

    public:

};


void generate_bytes_len_primes(int bytes, int value){
    mpz_t x;
    mp_bitcnt_t b = bytes;
    mpz_init2 (x, b);
    mpz_set_si(x, value);
    mpz_t p;
    mpz_init (p);
    mpz_nextprime(p, x);
    gmp_printf("Test : %Zd \n", p);
    gmp_printf("Size in bits : %d \n", mpz_sizeinbase(p, 2));
}

int get_random_int_in_range(int max_bits){
    gmp_randstate_t state;
    gmp_randinit_default(state);
    gmp_randseed_ui(state, time(NULL));
    mp_bitcnt_t n = max_bits;

    mpz_t t;
    mpz_init(t);
    mpz_urandomb(t, state, n);
    gmp_printf("T mpz is : %Zd\n", t);
    gmp_printf("Size in bits : %d \n", mpz_sizeinbase(t, 2));

    return mpz_get_si(t);
}

int secure_lambda_param = 1024;


int main() {
    int n = get_random_int_in_range(secure_lambda_param);
    printf("\nT int is : %d", n);
    // generate_bytes_len_primes(secure_lambda_param, n);

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