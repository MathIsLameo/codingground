#include <math.h>
#include <stdio.h>
#include <complex.h>

/*gcc -std=c99 -o main *.c -lm */

int
main(void)
{
    int size = 600;
    int imax = 256;
    int frames = 540;
    double radius = 1.0;

    for (int f = 0; f < frames; f++) {
        double theta = f * 3.141592653589793 * 2.0 / frames;
        printf("P6 %d %d 255\n", size, size);
        for (int y = 0; y < size; y++) {
            for (int x = 0; x < size; x++) {
                complex double z =
                    ((x / (size - 1.0) - 0.5) * radius * 2) +
                    ((y / (size - 1.0) - 0.5) * radius * 2) * I;
                complex double c =
                    (-0.80 + 0.1 * sin(theta)) +
                    (+0.00 + 0.1 * cos(theta)) * I;
                int i = 0;
                for (; i < imax && cabs(z) <= 2.0; i++)
                    z = z * z + c;
                int v = i * 255 / imax;
                unsigned char pixel[] = {v, v, v};
                fwrite(pixel, 1, 3, stdout);
            }
        }
    }
    return 0;
}
