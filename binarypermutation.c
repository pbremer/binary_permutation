/**
 * TODO: Insert license agreement
 */

/**
 * TODO: Do file preamble, description, usage, etc...
 */

#include "binarypermutation.h"

/**
 * TODO: Insert documentation for private permutation
 */
static int _permutate(const BinaryPermutationContext *context,
                      const binary_permutation_callback cb);

/**
 * TODO: Insert documentation for private array rest
 */
static void _reset_bit_shifts(unsigned int *const bit_shifts,
                              const size_t index);

/**
 * TODO: Insert documentation for private build number
 */
static unsigned int _convert_bit_shifts_to_uint(const unsigned int *bit_shifts,
                                                const size_t num_bits_on);

int init_BinaryPermutationContext(const size_t num_bits,
                                  const size_t num_bits_on,
                                  BinaryPermutationContext *context) {
  int return_code = 0;

  if (context) {
    context->num_bits = num_bits;
    context->num_bits_on = num_bits_on;

    unsigned int *bit_shifts =
        (unsigned int *)malloc(num_bits_on * sizeof(unsigned int));
    if (bit_shifts) {
      context->bit_shifts = bit_shifts;
      _reset_bit_shifts(bit_shifts, num_bits_on);
    } else {
      /* TODO: Set return code to something else */
      printf("Array not initalized\n");
    }
  } else {
    /* Error code */
  }

  return return_code; /* Good */
}

void destroy_BinaryPermutationContext(BinaryPermutationContext *context) {
  if (context && context->bit_shifts) {
    free(context->bit_shifts);
    free(context);
  }
}

int permutate(const BinaryPermutationContext *context,
              const binary_permutation_callback cb) {
  int return_code = 0;

  if (!cb) {
    /* Error */
  }

  if (context && context->bit_shifts) {
    return_code = _permutate(context, cb);
  } else {
    /* Error */
  }

  return return_code;
}

static int _permutate(const BinaryPermutationContext *context,
                      const binary_permutation_callback cb) {
  int return_code = 0;

  unsigned int num =
      _convert_bit_shifts_to_uint(context->bit_shifts, context->num_bits_on);

  for (size_t i = 0; i < context->num_bits_on; i++) {
    if (context->bit_shifts[i] == context->num_bits - 1) {
      continue;
    }
    if (i != context->num_bits_on - 1) { /* If not the MSB */
      if (context->bit_shifts[i + 1] - context->bit_shifts[i] > 1) {
        context->bit_shifts[i]++;
        _reset_bit_shifts(context->bit_shifts, i);
        return_code = 1; /* Has next */
        break;
      }
    } else if (i == context->num_bits_on - 1) { /* On MSB */
      context->bit_shifts[i]++;
      _reset_bit_shifts(context->bit_shifts, i);
      return_code = 1; /* Has next */
      break;
    }
  }

  (*cb)(num);

  return return_code;
}

static void _reset_bit_shifts(unsigned int *const bit_shifts,
                              const size_t index) {
  for (unsigned int i = 0; i < index; i++) {
    bit_shifts[i] = i;
  }
}

static unsigned int _convert_bit_shifts_to_uint(const unsigned int *bit_shifts,
                                                const size_t num_bits_on) {
  unsigned int num = 0;
  for (size_t i = 0; i < num_bits_on; i++) {
    num |= 1 << bit_shifts[i];
  }
  return num;
}