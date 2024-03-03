#include <stdio.h>
#include "libs/data_structures/vector/vector.h"

void test_pushBack_emptyVector() {
    vector v;
    v.data = NULL;
    v.size = 0;
    v.capacity = 0;

    pushBack(&v, 1);

    assert(v.size == 1);
    assert(v.capacity >= 1);
    assert(v.data != NULL);
    assert(v.data[0] == 1);

    free(v.data);
}

void test_pushBack_fullVector() {
    vector v;
    v.data = (int *) malloc(sizeof(int) * 2); //  заполнение вектора
    v.size = 2;
    v.capacity = 2;
    v.data[0] = 1;
    v.data[1] = 2;

    pushBack(&v, 3);

    assert(v.size == 3);
    assert(v.capacity >= 3);
    assert(v.data != NULL);
    assert(v.data[0] == 1);
    assert(v.data[1] == 2);
    assert(v.data[2] == 3);

    free(v.data);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

int main() {
    test();
    return 0;
}