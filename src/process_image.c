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
        int xa = (x < 0) ? 0 : ((x >= im.w) ? im.w : x);
        int ya = (y < 0) ? 0 : ((y >= im.h) ? im.h : y);
        int ca = (c < 0) ? 0 : ((c >= im.c) ? im.c : c);
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
        im.data[i + im.w * im.h * c] += v; // Adding is fine, since we are shifting
    }
}

// Adding a scaling function

void scale_image(image im, int c, float v)
{
    for (int i = 0; i < im.w * im.h; i++)
    {
        im.data[i + im.w * im.h * c] *= v; // Multiplying since we are scaling
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
    for (int i = 0; i < im.w * im.h; i++)
    {
        float V = three_way_max(im.data[i], im.data[i + im.w * im.h], im.data[i + 2 * im.w * im.h]);
        float m = three_way_min(im.data[i], im.data[i + im.w * im.h], im.data[i + 2 * im.w * im.h]);
        float S = 0, C = V - m;
        if (fabs(C - 0) < .00001)
            S = 0;
        else
            S = (V - m) / V;
        float R = im.data[i], G = im.data[i + im.w * im.h], B = im.data[i + 2 * im.w * im.h];
        float H_ = 0;
        if (fabs(C - 0) < .00001)
            H_ = 0;
        else if (fabs(V - R) < .00001)
            H_ = (G - B) / C;
        else if (fabs(V - G) < .00001)
            H_ = (B - R) / C + 2;
        else if (fabs(V - B) < 0.00001)
            H_ = (R - G) / C + 4;

        float H = 0;
        if (H_ < 0)
            H = H_ / 6 + 1;
        else
            H = H_ / 6;

        im.data[i] = H;
        im.data[i + im.w * im.h] = S;
        im.data[i + 2 * im.w * im.h] = V;
    }
    return;
}

void hsv_to_rgb(image im)
{
    // for (int i = 0; i < im.w * im.h; i++)
    // {
    //     float H = im.data[i];
    //     float S_V = im.data[i + im.w * im.h];
    //     float V = im.data[i + 2 * im.w * im.h];
    //     float C = V * S_V;
    //     float H_ = 6 * H;
    //     float meow = (int)H_ / 2;
    //     float X = C * (1 - (fabs(H_ - 2 * meow - 1)));
    //     if (0 < H_ && H_ < 1.0)
    //         im.data[i] = C, im.data[i + im.w * im.h] = X, im.data[i + 2 * im.w * im.h] = 0;
    //     else if (1.0 <= H_ && H_ < 2.0)
    //         im.data[i] = X, im.data[i + im.w * im.h] = C, im.data[i + 2 * im.w * im.h] = 0;
    //     else if (2.0 <= H_ && H_ < 3.0)
    //         im.data[i] = 0, im.data[i + im.w * im.h] = C, im.data[i + 2 * im.w * im.h] = X;
    //     else if (3.0 <= H_ && H_ < 4.0)
    //         im.data[i] = 0, im.data[i + im.w * im.h] = X, im.data[i + 2 * im.w * im.h] = C;
    //     else if (4.0 <= H_ && H_ < 5.0)
    //         im.data[i] = X, im.data[i + im.w * im.h] = 0, im.data[i + 2 * im.w * im.h] = C;
    //     else if (5.0 <= H_ && H_ < 1.0)
    //         im.data[i] = C, im.data[i + im.w * im.h] = 0, im.data[i + 2 * im.w * im.h] = X;

    //     float m = V - C;

    //     im.data[i] += m;
    //     im.data[i + im.w * im.h] += m;
    //     im.data[i + 2 * im.w * im.h] += m;
    // }

    for (int i = 0; i < im.w * im.h; i++)
    {
        float H = im.data[i];
        float S = im.data[i + im.w * im.h];
        float V = im.data[i + 2 * im.w * im.h];
        float H_ = H * 6;
        if (H_ >= 6)
            H_ -= 6; // H must be < 1
        float P = V * (1.0 - S);
        float Q = V * (1.0 - S * (H_ - floor(H_)));
        float T = V * (1.0 - S * (1.0 - (H_ - floor(H_))));
        if (0 < H_ && H_ < 1.0)
            im.data[i] = V, im.data[i + im.w * im.h] = T, im.data[i + 2 * im.w * im.h] = P;
        else if (1.0 <= H_ && H_ < 2.0)
            im.data[i] = Q, im.data[i + im.w * im.h] = V, im.data[i + 2 * im.w * im.h] = P;
        else if (2.0 <= H_ && H_ < 3.0)
            im.data[i] = P, im.data[i + im.w * im.h] = V, im.data[i + 2 * im.w * im.h] = T;
        else if (3.0 <= H_ && H_ < 4.0)
            im.data[i] = P, im.data[i + im.w * im.h] = Q, im.data[i + 2 * im.w * im.h] = V;
        else if (4.0 <= H_ && H_ < 5.0)
            im.data[i] = T, im.data[i + im.w * im.h] = P, im.data[i + 2 * im.w * im.h] = V;
        else if (5.0 <= H_ && H_ < 6.0)
            im.data[i] = V, im.data[i + im.w * im.h] = P, im.data[i + 2 * im.w * im.h] = Q;
        // else
        //     im.data[i] = 0, im.data[i + im.w * im.h] = 0, im.data[i + 2 * im.w * im.h] = 0;
    }
    return;
}
