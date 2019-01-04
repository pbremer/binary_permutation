/**
 * TODO: Insert license agreement
 */

/**
 * TODO: Do file preamble, description, usage, etc...
 */

#ifndef BINARY_PERMUTATION_H
#define BINARY_PERMUTATION_H

#include <stdlib.h>

/**
 * TODO: Insert documentation for struct
 */
typedef struct BinaryPermutationContext_t {
  int num_bits;
  int num_bits_on;
  unsigned int *bit_shifts;
} BinaryPermutationContext;

/**
 * TODO: Insert documentation for typedef function pointer
 */
typedef void (*binary_permutation_callback)(unsigned int);

/**
 * Initalizes BinaryPermutationContext
 */
int init_BinaryPermutationContext(const size_t num_bits,
                                  const size_t num_bits_on,
                                  BinaryPermutationContext *context);

/**
 * Destroys BinaryPermutationContext
 */
void destroy_BinaryPermutationContext(BinaryPermutationContext *context);

/**
 * TODO: Insert documentation for permutation
 */
int permutate(const BinaryPermutationContext *context,
              const binary_permutation_callback cb);

#endif /* BINARY_PERMUTATION_H */