/**
 * TODO: Insert license agreement
 */

/**
 * TODO: Do file preamble, description, usage, etc...
 */

#include <stdio.h>

#include "binarypermutation.h"

void slow_print(const unsigned int num) { printf("%u\n", num); }

int main(int argc, char **argv) {

  BinaryPermutationContext context;
  init_BinaryPermutationContext(32, 26, &context);

  size_t permutations = 0;

  while (permutate(&context, &slow_print)) {
    permutations++;
  };

    printf("Number of permutations: %lu\n", permutations);

  return EXIT_SUCCESS;
}