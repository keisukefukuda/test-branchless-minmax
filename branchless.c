// SPDX-License-Identifier: MIT
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define SIZE 100000
int numbers[SIZE];
int small_numbers[SIZE];
int smlen;

double ts(void) {
    static double t0;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    double h = t0;
    t0 = tv.tv_sec + tv.tv_usec / 1000000.0;
    return t0 - h;
}
void init(void) {
    srand(1);
    for (int i = 0; i < SIZE; i++) numbers[i] = rand() % 1000;
    ts();
}
void small_if(void) {
    smlen = 0;
    for (int i = 0; i < SIZE; i++) {
        if (numbers[i] < 500) {
            small_numbers[smlen] = numbers[i];
            smlen += 1;
        }
    }
}
void small_bl(void) {
    smlen = 0;
    for (int i = 0; i < SIZE; i++) {
        small_numbers[smlen] = numbers[i];
        smlen += (numbers[i] < 500);
    }
}
int main(void) {
    init();
    for (int i = 0; i < 1000; i++) small_if();
    printf("Time if: %.3f\n", ts());
    init();
    for (int i = 0; i < 1000; i++) small_bl();
    printf("Time bl: %.3f\n", ts());
}
