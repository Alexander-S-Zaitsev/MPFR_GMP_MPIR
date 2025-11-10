#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4146)  // унарный минус к беззнаковому типу
#pragma warning(disable: 4244)  // преобразование типов с потерей данных
#pragma warning(disable: 4267)  // преобразование size_t
#endif

#include <stdio.h>
#include <stdlib.h>
#include <mpfr.h>

int main(void)
{
    mpfr_t x, y, z;
    mpfr_rnd_t rnd = MPFR_RNDN;  // Round to nearest

    // Initialize variables with default precision (53 bits)
    mpfr_init2(x, 53);
    mpfr_init2(y, 53);
    mpfr_init2(z, 53);

    printf("=== Basic MPFR Operations Test ===\n");

    // Set values
    mpfr_set_d(x, 1.5, rnd);
    mpfr_set_d(y, 2.25, rnd);

    // Addition
    mpfr_add(z, x, y, rnd);
    printf("1.5 + 2.25 = ");
    mpfr_out_str(stdout, 10, 0, z, rnd);
    printf("\n");

    // Multiplication
    mpfr_mul(z, x, y, rnd);
    printf("1.5 * 2.25 = ");
    mpfr_out_str(stdout, 10, 0, z, rnd);
    printf("\n");

    // Division
    mpfr_div(z, y, x, rnd);
    printf("2.25 / 1.5 = ");
    mpfr_out_str(stdout, 10, 0, z, rnd);
    printf("\n");

    // Square root
    mpfr_sqrt(z, y, rnd);
    printf("sqrt(2.25) = ");
    mpfr_out_str(stdout, 10, 0, z, rnd);
    printf("\n");

    // Clear variables
    mpfr_clear(x);
    mpfr_clear(y);
    mpfr_clear(z);

    return 0;
}