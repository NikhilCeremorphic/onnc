#include <onnc/Runtime/operator/argmax.h>

#include <float.h>
#include <stdbool.h>
#include <stdint.h>

static int32_t findIndex(int32_t index, int32_t axisDim, int32_t elementDistance)
{
  return (index / (axisDim * elementDistance)) * elementDistance + index % elementDistance;
}

#include "internal/argmax.inc"