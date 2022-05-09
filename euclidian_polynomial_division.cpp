 #include <iostream>

int get_degree() {
    int q,p;

    std::cout << "Enter the degree of the two polynomials : \n";
    std::cin >> q;
    std::cin >> p;
    std::cout << "Your degrees are : " << q << " and " << p << " ! \n";
    return q,p;
}

int main() {
  std::cout << "Polynomial division !\n";
  get_degree();
  return 0;
} 