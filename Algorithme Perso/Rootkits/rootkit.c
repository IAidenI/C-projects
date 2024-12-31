#include "ninja.h"

int main() {
    if (Shadow() == FAILED) {
        fprintf(stderr, "Impossible de se cacher.\n");
        return FAILED;
    }
    return SUCCES;
}
