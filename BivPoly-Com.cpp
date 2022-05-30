 #include <iostream>
//  #include "cryptopp860/cryptlib.h"
//  #include "cryptopp860/integer.h"
//  #include "cryptopp860/osrng.h"
//  #include "cryptopp860/algparam.h"
#include <gmp.h>
#include <tgmath.h>
#include "Prime.cpp"
 using namespace std;
//  using namespace CryptoPP;

class BivPoly_Com {
    private:
        const int secure_lambda_param = 1024;
        
    public:

      
};



int main() {
    mpz_t prime;
    mpz_init(prime);
    Prime com;
    com.set_bytes(1024);
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