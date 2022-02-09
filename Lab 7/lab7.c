// 1. In thie question, you will familiarize yourself with working with images using c_img.c and png2bin.py,
//    files that were given to you as part of Project 2.

//    You can make an image brighter by multiplying all the pixel values by a constant
//    larger than 1; and you can make an image darker by multiplying all the pixel values
//    by a constant smaller than one.

//    c_img.c/c_img.h store reg/green/blue pixel values as uint8_t's -- values between 0
//    and 255. If you are trying to make an image brighter, you may need to round the products
//    you obtain by multiplying by a larger constant down to 255.

//    Download the image

//    https://www.president.utoronto.ca/secure-content/uploads/2017/09/UofTPresidentMericGertler-smaller.jpg

//    Convert the image to a bin file using png2bin.py

//    Write C code to create five different versions of the image at different levels of brightness.

#include "c_img.h"
#include <stdio.h>
#include <stdlib.h>

void modify_img(struct rgb_img *im, struct rgb_img **grad, double n) {
    int width = im->width;
    int height = im->height;
    create_img(grad, height, width);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = (int) (get_pixel(im, y, x, 0) * n);
            int g = (int) (get_pixel(im, y, x, 1) * n);
            int b = (int) (get_pixel(im, y, x, 2) * n);
            if(r>255) r = 255;
            if(g>255) g = 255;
            if(b>255) b = 255;

            set_pixel(*grad,y,x,r,g,b);
        }
    }
}

int main(void){
    struct rgb_img *im;
    struct rgb_img *cur_im;


    read_in_img(&im, "MG.bin");
    double arr[5] = {0.5,0.75,1.0,1.5,2.0};
    for(int i = 0; i < 5; i++){
        printf("i = %d\n", i);
        modify_img(im,&cur_im, arr[i]);

        char filename[200];
        sprintf(filename, "img%d.bin", i);
        write_img(cur_im, filename);
    }
    destroy_image(im);
}
