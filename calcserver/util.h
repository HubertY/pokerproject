#ifndef UTIL_H
#define UTIL_H


void multiply(double a1[169], double a2[169], double out[169]) {
    for (int i = 0; i < 169; i++) {
        out[i] = a1[i] * a2[i];
    }
}

void multiply(double a1[169], double n, double out[169]) {
    for (int i = 0; i < 169; i++) {
        out[i] = a1[i] * n;
    }
}


void copy(double a1[169], double out[169]) {
    for (int i = 0; i < 169; i++) {
        out[i] = a1[i];
    }
}

double sum(double a[169]) {
    double ret = 0;
    for (int i = 0; i < 169; i++) {
        ret += a[i];
    }
    return ret;
}


double dot(double a1[169], double a2[169]) {
    double prods[169];
    multiply(a1, a2, prods);
    return(sum(prods));
}

#endif