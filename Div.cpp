
#include "Div.h"

/**
 * Constructor.
 */
Div::Div(Expression* left, Expression* right):
        BinaryExpression(left, right) {
}

/**
 * Calculate the result.
 * @return the result.
 */
double Div::calculate() {
    return this->getLeftArg()->calculate() /
           this->getRightArg()->calculate();
}
