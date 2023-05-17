#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "image.h"

float get_pixel(image im, int x, int y, int c)
{
    if (x < 0 || x >= im.w || y < 0 || y >= im.h || c < 0 || c >= im.c)
    {
        // Implementing the "clamp" padding strategy
        int xa = (x < 0) ? 0 : im.w;
        int ya = (y < 0) ? 0 : im.h;
        int ca = (c < 0) ? 0 : im.c;
        return im.data[xa + im.w * ya + im.w * im.h * ca];
    }
    else
        return im.data[x + im.w * y + im.w * im.h * c];
}

void set_pixel(image im, int x, int y, int c, float v)
{
    if (x < 0 || x >= im.w || y < 0 || y >= im.h || c < 0 || c >= im.c)
        return;
    else
        im.data[x + im.w * y + im.w * im.h * c] = v;
    return;
}

image copy_image(image im)
{
    image copy = make_image(im.w, im.h, im.c);
    memcpy(copy.data, im.data, im.w * im.h * im.c * sizeof(float));
    return copy;
}

image rgb_to_grayscale(image im)
{
    assert(im.c == 3);
    image gray = make_image(im.w, im.h, 1);
    for (int i = 0; i < im.w * im.h; i++)
    {
        gray.data[i] = 0.299 * im.data[i] + 0.587 * im.data[i + im.w * im.h] + 0.114 * im.data[i + 2 * im.w * im.h];
        // Using the given formula Y' = 0.299 R' + 0.587 G' + .114 B' to convert RGB to grayscale
    }
    return gray;
}

void shift_image(image im, int c, float v)
{
    for (int i = 0; i < im.w * im.h; i++)
    {
        im.data[i + im.w * im.h * c] += v; // Should I add or multiply (?)
    }
}

void clamp_image(image im)
{
    for (int i = 0; i < im.w * im.h * im.c; i++)
    {
        if (im.data[i] > 1)
            im.data[i] = 1;
        else if (im.data[i] < 0)
            im.data[i] = 0;
    }
}

// These might be handy
float three_way_max(float a, float b, float c)
{
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

float three_way_min(float a, float b, float c)
{
    return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
}

void rgb_to_hsv(image im)
{
    // TODO Fill this in
}

void hsv_to_rgb(image im)
{
    // TODO Fill this in
}
