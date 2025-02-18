/*
** EPITECH PROJECT, 2025
** my radar
** File description:
** Calcs
*/

#include "myradar.h"

float distance(float x, float y)
{
    return sqrt(pow(x, 2) + pow(y, 2));
}

void closest_to_rect(float *val, float ref, float ref_rad)
{
    if (*val > ref + ref_rad)
        *val = ref + ref_rad;
    else if (*val < ref - ref_rad)
        *val = ref - ref_rad;
}

void closest_to_chunk(float *val, float x, float w)
{
    if (*val > x + w)
        *val = x + w;
    else if (*val < x)
        *val = x;
}
