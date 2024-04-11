#pragma clang diagnostic push
#pragma ide diagnostic ignored "cert-err34-c"
#include<stdlib.h>
#include<stdio.h>


typedef struct Term {
    int coefficient;
    int power;
    struct Term* next;
} Term;

typedef struct Polynomial {
    Term* start;
} Polynomial;

Term* createTerm(int coefficient, int power) {
    Term* term = (Term*) malloc(sizeof(Term));
    term->coefficient = coefficient;
    term->power = power;
    return term;
}

Polynomial* createPolynomial() {
    Polynomial* polynomial = (Polynomial*) malloc(sizeof(Polynomial));
    return polynomial;
}


void insertPolynomial(Polynomial* poly) {
    int degree;
    int leading_coefficient;
    printf("Enter the DEGREE of the POLYNOMIAL:");
    scanf("%d", &degree);
    printf("\nEnter the LEADING co-efficient of the POLYNOMIAL:");
    scanf("%d", &leading_coefficient);
    Term* leading_term = createTerm(leading_coefficient, degree);
    poly->start = leading_term;

    for(int power = degree-1; power >= 0; power--) {
        int coefficient;
        printf("\n");
        printf("Enter the co-efficient of X^%d:", power);
        scanf("%d", &coefficient);
        Term* term = createTerm(coefficient, power);
        leading_term->next = term;
        leading_term = leading_term->next;
    }
    leading_term->next = NULL;
}

void displayPolynomial(Polynomial* poly) {
    Term* temp = poly->start;
    printf("The POLYNOMIAL is:\n");
    while(temp != NULL) {
        if(temp->next != NULL) {
            printf("%d*x^%d + ", temp->coefficient, temp->power);
        }
        else {
            printf("%d*x^%d = 0\n", temp->coefficient, temp->power);
        }
        temp = temp->next;
    }
}

Polynomial* addPolynomials(Polynomial* poly1, Polynomial* poly2) {
    Term* ptr1 = poly1->start;
    Term* ptr2 = poly2->start;
    Term* leading_term = NULL;

    Polynomial* poly = createPolynomial();
    if(ptr1->power == ptr2->power) {
        leading_term = createTerm(ptr1->coefficient + ptr2->coefficient, ptr1->power);
        poly->start = leading_term;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    else {
        if(ptr1->power > ptr2->power) {
            leading_term = createTerm(ptr1->coefficient, ptr1->power);
            ptr1 = ptr1->next;
        }
        else {
            leading_term = createTerm(ptr2->coefficient, ptr2->power);
            ptr2 = ptr2->next;
        }
        poly->start = leading_term;
    }

    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1->power > ptr2->power) {
            Term* term = createTerm(ptr1->coefficient, ptr1->power);
            leading_term->next = term;
            leading_term = leading_term->next;
            ptr1 = ptr1->next;
        }
        else if(ptr1->power < ptr2->power) {
            Term* term = createTerm(ptr2->coefficient, ptr2->power);
            leading_term->next = term;
            leading_term = leading_term->next;
            ptr2 = ptr2->next;
        }
        else {
            int sum = ptr1->coefficient + ptr2->coefficient;
            Term* term = createTerm(sum, ptr1->power);
            leading_term->next = term;
            leading_term = leading_term->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }

    if(ptr1 == NULL) {
        while(ptr2 != NULL) {
            Term* term = createTerm(ptr2->coefficient, ptr2->power);
            leading_term->next = term;
            leading_term = leading_term->next;
            ptr2 = ptr2->next;
        }
    }

    if(ptr2 == NULL) {
        while(ptr1 != NULL) {
            Term* term = createTerm(ptr1->coefficient, ptr1->power);
            leading_term->next = term;
            leading_term = leading_term->next;
            ptr1 = ptr1->next;
        }
    }
    leading_term->next = NULL;

    return poly;
}

#pragma clang diagnostic pop