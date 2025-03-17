// @copyright 2019 Günter Kolousek

#include "sorting.h"

void sorting::bubble_sort(unsigned int n, int numbers[]) {
    // each element up to the second last
    for (unsigned int i{}; i < n - 1; ++i) {
        // each element up to the second last
        for (unsigned int j{}; j < n - 1; ++j) {
            if (numbers[j] > numbers[j + 1]) {
                int tmp{numbers[j]};
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = tmp;
            }
        }
    }
}

void sorting::selection_sort(unsigned int n, int numbers[]) {
    for (unsigned int i{}; i < n - 1; ++i) {
        unsigned int min{i};
        // j in [i + 1, n - 1]
        for (unsigned int j{i + 1}; j < n; ++j) {
            if (numbers[j] < numbers[min])
                min = j;
        }
        int tmp{numbers[min]};
        numbers[min] = numbers[i];
        numbers[i] = tmp;
    }
}

void sorting::insertion_sort(unsigned int n, int numbers[]) {
    for (unsigned int i{1}; i < n; ++i) {
        int val{numbers[i]};
        unsigned int j{i};
        while (true) {
            if (j == 0 or numbers[j - 1] <= val)
                break;
            numbers[j] = numbers[j - 1];
            --j ;
        }
        numbers[j] = val;
    }
}
