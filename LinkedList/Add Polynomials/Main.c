#include "Polynomial.c"

int main() {
    Polynomial* poly1 = createPolynomial();
    printf("Enter details of first polynomial..\n");
    insertPolynomial(poly1);
    displayPolynomial(poly1);
    Polynomial* poly2 = createPolynomial();
    printf("Enter details of second polynomial..\n");
    insertPolynomial(poly2);
    displayPolynomial(poly2);
    Polynomial* poly3 = addPolynomials(poly1, poly2);
    printf("Polynomial after adding two polynomials:\n");
    displayPolynomial(poly3);
    return 0;
}