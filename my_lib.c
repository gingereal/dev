#include "my_lib.h"

/**
 * @brief
 *
 * @param cycle_result
 * @return Error
 */
Error cycle_print(const CycleResult *cycle_result)
{
    if (cycle_result == NULL)
    {
        return NULL_POINTER_ERROR;
    }

    printf("count: %llu\n", cycle_result->count);
    printf("aver: %llu, max: %llu, min: %llu\n, std: %llu\n",
           cycle_result->aver, cycle_result->max, cycle_result->min, cycle_result->std);

    printf("\n");

    return NO_ERROR;
}

/**
 * @brief
 *
 * @param data
 * @param size
 * @return Error
 */
Error debug_print(const void *data, size_t size)
{
    if (data == NULL)
    {
        return NULL_POINTER_ERROR;
    }

    u8 *data_ptr = (u8 *)data;

    for (int i = 0; i < size; i++)
    {
        if (i != 0 && i % 32 == 0)
        {
            printf("\n");
        }

        printf("%02x ", *data_ptr++);
    }

    printf("\nsize: %zu (bytes)\n", size);

    return NO_ERROR;
}