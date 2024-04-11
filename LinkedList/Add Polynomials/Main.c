#include "Polynomial.c"

int main() {
    Polynomial* poly1 = createPolynomial();
    insertPolynomial(poly1);
    displayPolynomial(poly1);
    Polynomial* poly2 = createPolynomial();
    insertPolynomial(poly2);
    displayPolynomial(poly2);

    Polynomial* poly3 = addPolynomials(poly1, poly2);
    displayPolynomial(poly3);
    return 0;
}