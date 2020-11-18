/*
 * picture.c
 *
 *  Created on: Nov 10, 2020
 *      Author: lauri
 */
#include <ti/mw/grlib/grlib.h>
#include <stdio.h>

const uint8_t rightData[1140] = {

		0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x38,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x1e,0x1c,0x7,0xf9,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x3c,0x1e,0xf,0x81,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x38,0x3e,0xe,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x38,0x3f,0xe,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x3c,0x3f,0xe,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x1c,0x1f,0x8e,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x1e,0xbf,0xf,0x83,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x1f,0xfe,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0xf,0xfc,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x3,0xe0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,
		0xe0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,
		0xf3,0xff,0x80,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xf8,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,
		0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x1e,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x1c,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x1c,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,
		0x1c,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xc0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x7f,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,
		0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xff,
		0x60,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3f,
		0x70,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,
		0x70,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,
		0x70,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,
		0x70,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,
		0x70,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xf,
		0x78,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1f,
		0x3c,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,
		0x3f,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x7f,0xff,
		0x1f,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,0xff,
		0xf,0xff,0xff,0xff,0xff,0xe0,0x0,0xf,0xff,0xff,0xff,0xff,
		0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,



};


uint32_t imgPalette[] = {0, 0xFFFFFF};


const tImage right = {
    .BPP = IMAGE_FMT_1BPP_UNCOMP,
    .NumColors = 2,
    .XSize = 96,
    .YSize = 95,
    .pPalette = imgPalette,
    .pPixel = rightData
};

const uint8_t leftData[1140] = {
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x1c,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x9f,0xe0,0x38,0x78,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x81,0xf0,0x78,0x3c,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x70,0x7c,0x1c,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x70,0xfc,0x1c,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x70,0xfc,0x3c,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x71,0xf8,0x38,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc1,0xf0,0xfd,0x78,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x7f,0xf8,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x3f,0xf0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x7,0xc0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x7,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x1,0xff,0xcf,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x78,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x38,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x38,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x38,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,0x3,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0xfe,0x0,
		0xff,0xff,0xfc,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0xff,0xff,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0xff,0x80,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
		0xfc,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x6,
		0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xe,
		0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xe,
		0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xe,
		0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xe,
		0xf0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0xe,
		0xf8,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1e,
		0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x3c,
		0xff,0xfe,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x1,0xfc,
		0xff,0xff,0xff,0xe0,0x0,0x0,0x0,0x0,0x0,0x0,0xff,0xf8,
		0xff,0xff,0xff,0xff,0xf0,0x0,0x7,0xff,0xff,0xff,0xff,0xf0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x0,

};

const tImage left = {
    .BPP = IMAGE_FMT_1BPP_UNCOMP,
    .NumColors = 2,
    .XSize = 96,
    .YSize = 95,
    .pPalette = imgPalette,
    .pPixel = leftData
};


const uint8_t upData[1140] = {
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0x1f,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xfe,0x3,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xfe,0x3,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xfc,0x1,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xfc,0x1,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xfc,0x1,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xfc,0x1,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xfc,0x1,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xfc,0x1,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xfc,0x1,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xfc,0x1,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf8,0x1,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf8,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf8,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf8,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf8,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf8,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf8,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf8,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf8,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf8,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf8,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xc0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xc0,0x0,0x7f,0xff,0xfc,0x3f,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0xff,0xfc,0xf,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0xff,0xfc,0x7,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0xc0,0x78,0x7,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0x80,0x30,0x3,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0x0,0x38,0x3,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0x0,0x38,0x3,0x84,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7f,0x0,0x38,0x3,0x80,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7e,0x0,0x38,0x3,0x81,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7e,0x0,0x38,0x3,0x81,0xe3,
		0xff,0xff,0xff,0xff,0xe0,0x0,0x7e,0x0,0x38,0x3,0x83,0xe0,
		0xfc,0x0,0x0,0xf,0xe0,0x0,0x7e,0x0,0x38,0x3,0x83,0xe0,
		0x0,0x0,0x0,0x3,0xe0,0x0,0x7e,0x0,0x38,0x3,0x83,0xe0,
		0x0,0x0,0x0,0x1,0xe0,0x0,0x7e,0x0,0x38,0x1,0xc3,0xe0,
		0x0,0x0,0x0,0x1,0xe0,0x0,0x7c,0x0,0x38,0x1,0xff,0xe0,
		0x0,0x0,0x0,0x1,0xe0,0x0,0x7c,0x0,0x38,0x1,0xff,0xe0,
		0x0,0x0,0x0,0x1,0xe0,0x0,0x7c,0x0,0x38,0x0,0x7f,0xe0,
		0x0,0x0,0x0,0x1,0xe0,0x0,0x7c,0x0,0x38,0x0,0x0,0xe0,
		0x0,0x0,0x0,0x3,0xe0,0x0,0x7c,0x0,0x38,0x0,0x0,0xe0,
		0x0,0x0,0x0,0x3,0xe0,0x0,0x7c,0x0,0x38,0x0,0x0,0xe0,
		0x0,0x0,0x0,0x3,0xe0,0x0,0x7c,0x0,0x38,0x0,0x0,0xe0,
		0x0,0x0,0x0,0x3,0xe0,0x0,0xfc,0x0,0x1c,0x0,0xf0,0xe0,
		0x0,0x0,0x0,0x3,0xe0,0x0,0xfc,0x0,0x1c,0x1,0xfd,0xe0,
		0x0,0x0,0x0,0x3,0xe0,0x0,0xfc,0x0,0x1c,0x1,0xff,0xe0,
		0x0,0x0,0x0,0x3,0xe0,0x0,0xfc,0x0,0x1c,0x3,0xff,0xe0,
		0x0,0x0,0x0,0x3,0xe0,0x0,0xfc,0x0,0x3c,0x3,0xff,0xe0,
		0x0,0x0,0x0,0x3,0xc0,0x0,0xfc,0x0,0x1c,0x3,0xb9,0xc0,
		0x0,0x0,0x0,0x1,0xe0,0x0,0xfc,0x0,0x1c,0x3,0x81,0xc0,
		0x0,0x0,0x0,0x1,0xe0,0x0,0xfc,0x0,0x1c,0x3,0x81,0xc0,
		0x0,0x0,0x0,0x1,0xe0,0x1,0xfc,0x0,0x1c,0x3,0x81,0xc0,
		0x0,0x0,0x0,0x1,0xe0,0x1,0xfc,0x0,0x1c,0x3,0x83,0xc0,
		0x0,0x0,0x0,0x1,0xe0,0x1,0xfc,0x0,0x1c,0x3,0xe7,0xc0,
		0x0,0x0,0x0,0x1,0xe0,0x1,0xdc,0x0,0x1c,0x3,0xff,0xc0,
		0x0,0x0,0x0,0x1,0xe0,0x1,0xdc,0x0,0x1c,0x1,0xff,0xc0,
		0x0,0x0,0x0,0x0,0xf0,0x1,0x9c,0x0,0x1c,0x0,0x3f,0xc0,
		0x0,0x0,0x0,0x0,0xf0,0x0,0x1c,0x0,0x1c,0x0,0x1,0xc0,
		0x0,0x0,0x0,0x0,0xf0,0x0,0x1c,0x0,0x1c,0x0,0x1,0xc0,
		0x0,0x0,0x0,0x0,0xf0,0x0,0x1c,0x0,0x1c,0x0,0x1,0xc0,
		0x0,0x0,0x0,0x0,0x78,0x0,0x1c,0x0,0x3c,0x0,0x1,0xc0,
		0x0,0x0,0x0,0x0,0x3c,0x0,0x1c,0x1,0xf8,0x0,0x1,0xc0,
		0x0,0x0,0x0,0x0,0x3f,0xe0,0x1c,0x1,0xf8,0x0,0x1,0xc0,
		0x0,0x0,0x0,0x0,0x1f,0xf0,0x1c,0x0,0xfc,0x0,0x1,0xe0,
		0x0,0x0,0x0,0x0,0x7,0xf0,0x1c,0x0,0x1e,0x0,0x1,0xe0,

};


const tImage up = {
    .BPP = IMAGE_FMT_1BPP_UNCOMP,
    .NumColors = 2,
    .XSize = 96,
    .YSize = 95,
    .pPalette = imgPalette,
    .pPixel = upData
};



const uint8_t downData[1140] = {
		0x0,0x1c,0x0,0x1,0xc0,0x1,0xc0,0x0,0x7c,0x0,0x0,0x0,
		0x0,0x1d,0xe0,0x1,0xc0,0x0,0xcc,0x0,0x3c,0x0,0x0,0x0,
		0x0,0x1f,0xfc,0x1,0xc0,0x0,0xdc,0x0,0x3c,0x0,0x0,0x0,
		0x0,0x1f,0xfe,0x1,0xc0,0x0,0xdc,0x0,0x3c,0x0,0x0,0x0,
		0x0,0x1f,0x3e,0x1,0xc0,0x0,0xfc,0x0,0x3c,0x0,0x0,0x0,
		0x0,0x1e,0xe,0x1,0xc0,0x0,0xfc,0x0,0x3c,0x0,0x0,0x0,
		0x0,0x1c,0xe,0x1,0xc0,0x0,0xfc,0x0,0x3c,0x0,0x0,0x0,
		0x0,0x1c,0xe,0x1,0xc0,0x0,0xf8,0x0,0x3c,0x0,0x0,0x0,
		0x0,0x1c,0xe,0x1,0xe0,0x1,0xf8,0x0,0x1e,0x0,0x0,0x0,
		0x0,0x1e,0xee,0x0,0xe0,0x1,0xf8,0x0,0x1e,0x0,0x0,0x0,
		0x0,0x1f,0xfe,0x0,0xe0,0x1,0xf8,0x0,0x1e,0x0,0x0,0x0,
		0x0,0x1f,0xfe,0x0,0xe0,0x1,0xf8,0x0,0x1e,0x0,0x0,0x0,
		0x0,0x1f,0xfe,0x0,0xe0,0x1,0xf8,0x0,0x1e,0x0,0x0,0x0,
		0x0,0x1d,0xfc,0x0,0xe0,0x1,0xf8,0x0,0x1e,0x0,0x0,0x0,
		0x0,0x1c,0x78,0x0,0xe0,0x1,0xf8,0x0,0x1e,0x0,0x0,0x0,
		0x0,0x1c,0x10,0x0,0xe0,0x1,0xf8,0x0,0x1e,0x0,0x0,0x0,
		0x0,0x1c,0x0,0x0,0xe0,0x1,0xf8,0x0,0x1e,0x0,0x0,0x0,
		0x0,0x1c,0x0,0x0,0xe0,0x1,0xf8,0x0,0x1e,0x0,0x0,0x0,
		0x0,0x1c,0x0,0x0,0xe0,0x1,0xf8,0x0,0x1e,0x0,0x0,0x0,
		0x0,0x1f,0xf8,0x0,0xe0,0x1,0xf8,0x0,0x1e,0x0,0x0,0x0,
		0x80,0x1f,0xfc,0x0,0xe0,0x1,0xf8,0x0,0x1e,0x0,0x0,0x0,
		0x80,0x1f,0xfe,0x0,0xe0,0x1,0xf8,0x0,0x1e,0x0,0x0,0x0,
		0x80,0x1f,0xe,0x0,0x70,0x1,0xf8,0x0,0x1e,0x0,0x0,0x0,
		0x80,0x1e,0xe,0x0,0x70,0x1,0xf8,0x0,0x3e,0x0,0x0,0x0,
		0xc0,0x1e,0xf,0x0,0x70,0x1,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xf0,0x1e,0x7,0x0,0x70,0x3,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xfe,0x3e,0x7,0x0,0x70,0x3,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xfc,0xf,0x0,0x70,0x3,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xf8,0xe,0x0,0x70,0x3,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xfc,0xe,0x0,0x70,0x7,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0x0,0x70,0x7,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0x0,0x70,0xf,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0x0,0x70,0x1f,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0x80,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xc1,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xf1,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x7f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x7f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x7f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0x0,0x7f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x7f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x7f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x7f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x7f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x7f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x7f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x7f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x1,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x1,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x83,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,

};


const tImage down = {
    .BPP = IMAGE_FMT_1BPP_UNCOMP,
    .NumColors = 2,
    .XSize = 96,
    .YSize = 95,
    .pPalette = imgPalette,
    .pPixel = downData
};

const uint8_t winData[1140] = {
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x1,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x1,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0x0,0x3,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0x3,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0xfc,0x0,0x3,
	0xff,0xff,0xf3,0xfd,0xff,0xff,0xff,0xff,0xc1,0xfc,0x7,0x83,
	0xff,0xff,0xe3,0xfd,0xff,0xff,0xff,0xfc,0x3,0xf8,0x3f,0xc3,
	0xff,0xff,0xc3,0xf9,0xff,0xff,0xff,0xf0,0xff,0xf0,0xfc,0xc7,
	0xff,0xff,0xc3,0xf9,0xff,0xff,0xff,0xff,0xff,0xe3,0xe0,0xc7,
	0xff,0xff,0xc3,0xf9,0xff,0xff,0xff,0xff,0xe1,0xff,0x80,0xe7,
	0xff,0xff,0xc3,0xf9,0xff,0xfc,0xf,0xf8,0x1,0xfe,0x0,0x67,
	0xff,0xff,0xc3,0xf9,0xff,0x80,0xe,0x0,0xff,0xf8,0x0,0x67,
	0xff,0xff,0xc3,0xf1,0xf8,0xf,0xfe,0x3,0xff,0x98,0x78,0x6f,
	0xff,0xff,0xe1,0xf1,0xbf,0x9f,0xff,0xc7,0xe0,0x18,0x78,0x6f,
	0xff,0xff,0xe1,0xf1,0xbf,0x9c,0x3f,0xc6,0x0,0x1c,0x70,0x7f,
	0xff,0xff,0xe1,0xf1,0xb9,0x98,0xd,0xc6,0x70,0xc,0x0,0xff,
	0xff,0xff,0xe1,0xe3,0xb1,0x98,0xc,0xc6,0xff,0x8c,0x3,0xff,
	0xff,0xff,0xe1,0xe3,0xb1,0x98,0xc,0xc6,0xff,0xcc,0x7,0x9f,
	0xff,0xff,0xe1,0xe3,0xb1,0x98,0x5c,0xc6,0xc0,0xcc,0x7,0xff,
	0xff,0xff,0x61,0xe3,0xb1,0x98,0xfc,0xc7,0xc0,0xcc,0x0,0xff,
	0xff,0xfe,0x61,0xe3,0xb1,0x98,0xfc,0xc7,0xc0,0xce,0x0,0x3f,
	0xff,0xfc,0x61,0xc3,0xb1,0x98,0xc0,0xc7,0xcc,0xce,0x0,0x1f,
	0xff,0xfc,0x61,0xc3,0x31,0xb8,0xc0,0xc7,0xcc,0xc6,0x0,0x1f,
	0xff,0xfc,0x60,0xc3,0x31,0xb8,0xc0,0xc7,0xcc,0xc6,0x0,0x1f,
	0xff,0xfc,0x60,0xc3,0x31,0xb8,0xc0,0xc7,0xc0,0xc6,0x0,0x1f,
	0xff,0xf8,0x60,0x3,0x31,0xb0,0xf0,0xc7,0xc0,0xc6,0x1f,0xf,
	0xff,0xf8,0x60,0x3,0x33,0xb0,0xff,0xe7,0xc0,0xc6,0x1f,0x8f,
	0xff,0xf8,0x60,0x3,0x73,0xb0,0xff,0xe7,0xc0,0xc7,0x1b,0x8f,
	0xff,0xf8,0x60,0x3,0x73,0xb0,0x7,0xe7,0xfd,0xc7,0x19,0x8f,
	0xff,0xf8,0x60,0x7,0x73,0xb0,0x3,0xe7,0xff,0xc7,0x19,0x8f,
	0xff,0xf8,0x70,0x7,0x73,0x30,0x3,0x6e,0x7f,0xc7,0x19,0xcf,
	0xff,0xf0,0x70,0x6,0x63,0x30,0x7,0x7e,0x0,0x3,0x19,0xcf,
	0xff,0xf0,0x70,0x6,0x63,0x38,0x1f,0x78,0x0,0x3,0xf9,0xef,
	0xff,0xf0,0x70,0x6,0x7f,0x3f,0xfe,0x70,0x0,0x3,0xf9,0xef,
	0xff,0xf0,0x30,0x6,0x7f,0x1f,0xfc,0x20,0x0,0x0,0x1,0xff,
	0xff,0xf0,0x30,0xe,0x7f,0x0,0x0,0x0,0x0,0x0,0x3,0xff,
	0xff,0xe0,0x30,0xc,0x0,0x0,0x0,0x0,0x0,0x0,0x3,0xff,
	0xff,0xe0,0x30,0xc,0x0,0x0,0x1c,0x0,0x0,0x0,0x3,0xff,
	0xff,0xe0,0x38,0xc,0x0,0x0,0x3c,0x0,0x3,0xfc,0x3,0xff,
	0xff,0xe0,0x30,0x18,0x3,0xc0,0x7e,0x0,0x7,0xfc,0x7,0xff,
	0xff,0xc0,0x38,0x78,0xf,0xe0,0xee,0x0,0x6,0xc,0x7,0xff,
	0xff,0xc0,0x3f,0xf0,0x3e,0x70,0xe6,0xf,0xc6,0xe,0x7,0xff,
	0xff,0x80,0x1f,0xc0,0x78,0x30,0xc6,0x7f,0xc6,0xe,0x7,0xff,
	0xff,0x80,0x0,0x0,0x38,0x31,0xc6,0x7c,0xe6,0xe,0xf,0xff,
	0xff,0x81,0xf8,0x0,0x1c,0x3b,0x8e,0x70,0x67,0xe,0xf,0xff,
	0xff,0xff,0xfe,0x0,0x1c,0x1f,0x9c,0x70,0x63,0xe,0xf,0xff,
	0xff,0xff,0xff,0x3f,0xfe,0xf,0x18,0x60,0x73,0xe,0xf,0xff,
	0xff,0xc0,0x7,0x7f,0xfe,0x6,0x38,0x60,0x73,0x6,0x1f,0xff,
	0xff,0xc0,0x3,0x70,0x1f,0x0,0x38,0xe0,0x73,0x86,0x1f,0xff,
	0xfe,0xe0,0x3,0x30,0x1f,0x80,0x38,0xe0,0x31,0x86,0x1f,0xff,
	0xfe,0xe0,0x83,0x30,0x1d,0xc0,0x30,0xc0,0x31,0x86,0x1f,0xff,
	0xfe,0xe1,0xc3,0x30,0x1c,0xe0,0x30,0xc0,0x31,0x86,0x3f,0xff,
	0xfc,0x61,0xc3,0x38,0x1c,0x60,0x71,0xc0,0x39,0x86,0x3f,0xff,
	0xfc,0x61,0xc3,0x39,0x9c,0x60,0x71,0xc0,0x39,0x87,0x3f,0xff,
	0xfc,0x60,0x83,0x39,0x8c,0x60,0x61,0x83,0x19,0x87,0x7f,0xff,
	0xf8,0x60,0x7,0x19,0x8c,0x70,0x61,0x87,0x19,0xc7,0xff,0xff,
	0xf8,0x70,0xe,0x19,0x8c,0x70,0xe3,0x87,0x1d,0xc7,0xff,0xff,
	0xf8,0x70,0xe,0x19,0x8c,0x70,0xc3,0x8f,0x9d,0xc2,0x0,0xff,
	0xf8,0x70,0x1c,0x19,0x8e,0x30,0xc3,0xf,0x8c,0xc0,0x0,0xff,
	0xf0,0x30,0x38,0x18,0xe,0x30,0xc7,0xf,0x8c,0xc0,0x0,0x7f,
	0xf0,0x30,0xf0,0x1c,0x6,0x38,0xc7,0xf,0x8e,0xc0,0x1,0xff,
	0xe0,0x31,0xf0,0x1c,0x6,0x38,0xc7,0x7d,0xce,0xff,0xff,0xff,
	0xe0,0x30,0xf0,0x1c,0x6,0x18,0xc7,0xf8,0xfe,0xff,0xff,0xff,
	0xe0,0x38,0x3c,0xc,0x6,0x18,0xc7,0xe0,0xfe,0x1f,0xff,0xff,
	0xe0,0x38,0x1f,0xc,0x6,0x1b,0xc6,0x0,0x0,0x1,0xff,0xff,
	0xc0,0x38,0x7,0x8c,0xfe,0x1f,0xc0,0x0,0x0,0x3,0xff,0xff,
	0xc0,0x38,0x3,0xcf,0xfe,0xf,0x80,0x0,0x0,0x3,0xff,0xff,
	0xc0,0x18,0xe0,0xef,0xf0,0x0,0x0,0x0,0x0,0x3,0xff,0xff,
	0xc0,0x18,0xf0,0xe0,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,
	0x80,0x18,0xf8,0x70,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,
	0x80,0x1c,0xfc,0x78,0x0,0x0,0x0,0x0,0x0,0x7,0xff,0xff,
	0x80,0x1c,0xcf,0xf0,0x0,0x0,0x0,0x0,0x0,0xff,0xff,0xff,
	0x0,0xc,0xc7,0xe0,0x0,0x0,0x0,0x0,0x3f,0xff,0xff,0xff,
	0x0,0xf,0xc3,0x80,0x0,0x0,0x0,0x7,0xff,0xff,0xff,0xff,
	0x60,0xf,0xc6,0x0,0x0,0x0,0x1,0xff,0xff,0xff,0xff,0xff,
	0xe0,0xf,0x9e,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,
	0xe0,0x0,0x3f,0x0,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,
	0xe0,0x0,0x3f,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xe0,0x0,0x7f,0x0,0xf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xe0,0x0,0xff,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xc0,0x0,0xff,0x3f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xc0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xc0,0x7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0x80,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0x87,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
	0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
};

const tImage win = {
    .BPP = IMAGE_FMT_1BPP_UNCOMP,
    .NumColors = 2,
    .XSize = 96,
    .YSize = 95,
    .pPalette = imgPalette,
    .pPixel = winData
};

const uint8_t loseData[1140] = {
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0x0,0xff,0xff,0xff,0xff,
		0xfe,0x1f,0xff,0xff,0xff,0xff,0xf0,0x0,0x0,0xff,0xff,0xff,
		0xfc,0xf,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x7f,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xff,0xe0,0x0,0x0,0x3f,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xff,0xc0,0x0,0x0,0x3f,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x3f,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x1f,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0xf,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xff,0x0,0x7c,0x0,0x7,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xfe,0x0,0xff,0x0,0x7,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xfe,0x0,0xff,0x80,0x3,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xfc,0x1,0xff,0xe0,0x1,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xfc,0x1,0xff,0xf8,0x1,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xfc,0x3,0xff,0xfc,0x1,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xf8,0x3,0xff,0xfe,0x1,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xf8,0x3,0xff,0xfe,0x1,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xf8,0x7,0xff,0xfe,0x1,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xf8,0x7,0xff,0xfe,0x1,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xf8,0x7,0xff,0xfe,0x1,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xf8,0x7,0xff,0xfe,0x1,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xf8,0x7,0xff,0xfe,0x1,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xf8,0x7,0xff,0xfe,0x1,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xf8,0x7,0xff,0xfe,0x1,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xf8,0x7,0xff,0xfe,0x1,0xff,0xff,
		0xf8,0xf,0xff,0xff,0xff,0xf8,0x7,0xff,0xfc,0x1,0xff,0xff,
		0xf8,0xf,0xff,0xff,0xff,0xf8,0x7,0xff,0xfc,0x1,0xff,0xff,
		0xf0,0x7,0xff,0xff,0xff,0xf8,0x7,0xff,0xf8,0x3,0xff,0xff,
		0xf8,0xf,0xff,0xff,0xff,0xf8,0x7,0xff,0xf8,0x3,0xff,0xff,
		0xf8,0xf,0xff,0xff,0xff,0xf8,0x7,0xff,0xf0,0x7,0xff,0xff,
		0xf8,0xf,0xff,0xff,0xff,0xf8,0x3,0xff,0xe0,0x7,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xfc,0x1,0xff,0x80,0x7,0xff,0xff,
		0xf8,0xf,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0xf,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x1f,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xfc,0x0,0x0,0x0,0x3f,0xff,0xff,
		0xf8,0x7,0xff,0xff,0xff,0xfe,0x0,0x0,0x0,0x3f,0xff,0xff,
		0xf8,0x0,0x1f,0xff,0xff,0xfe,0x0,0x0,0x0,0xff,0xff,0xff,
		0xf8,0x0,0x0,0x3,0xff,0xff,0x0,0x0,0x1,0xff,0xff,0xff,
		0xf8,0x0,0x0,0x0,0xff,0xff,0xc0,0x0,0x3,0xff,0xff,0xff,
		0xf8,0x0,0x0,0x0,0xff,0xff,0xf8,0x0,0xf,0xff,0xff,0xff,
		0xf8,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xf8,0x0,0x0,0x0,0x7f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xfc,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0x0,0x0,0x0,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xc0,0x3,0xff,0xff,0xff,0xe0,0x0,0x0,0x3f,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0x1f,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x0,0x0,0xf,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0xf,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x0,0x0,0x0,0xf,0xff,
		0xff,0xff,0xff,0x0,0x3f,0xff,0xff,0x0,0x0,0x0,0x1f,0xff,
		0xff,0xff,0xfc,0x0,0x1f,0xff,0xff,0x0,0x0,0x0,0x3f,0xff,
		0xff,0xff,0xf8,0x0,0xf,0xff,0xff,0x0,0x1f,0xdf,0xff,0xff,
		0xff,0xff,0xf0,0x0,0xf,0xff,0xff,0x0,0x7f,0xff,0xff,0xff,
		0xff,0xff,0xe0,0x0,0xf,0xff,0xff,0x80,0x7f,0xff,0xff,0xff,
		0xff,0xff,0xc0,0x0,0x1f,0xff,0xff,0x80,0x7f,0xff,0xff,0xff,
		0xff,0xff,0xc0,0x0,0x3f,0xff,0xff,0x80,0x3f,0xff,0xff,0xff,
		0xff,0xff,0x80,0x3,0xff,0xff,0xff,0x80,0x3f,0xff,0xff,0xff,
		0xff,0xff,0x80,0x1f,0xff,0xff,0xff,0xc0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0x0,0x3f,0xff,0xff,0xff,0xc0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0x0,0x7f,0xff,0xff,0xff,0xc0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0x0,0x7f,0xff,0xff,0xff,0xc0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0x0,0x3,0xff,0xff,0xff,0xc0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0x0,0x0,0x3f,0xff,0xff,0xc0,0x0,0x0,0x1f,0xff,
		0xff,0xff,0x80,0x0,0x7,0xff,0xff,0xc0,0x0,0x0,0xf,0xff,
		0xff,0xff,0x80,0x0,0x1,0xff,0xff,0xc0,0x0,0x0,0x7,0xff,
		0xff,0xff,0xc0,0x0,0x0,0x7f,0xff,0xc0,0x0,0x0,0x7,0xff,
		0xff,0xff,0xe0,0x0,0x0,0x3f,0xff,0xc0,0x0,0x0,0x7,0xff,
		0xff,0xff,0xf0,0x0,0x0,0x1f,0xff,0xc0,0x0,0x0,0x7,0xff,
		0xff,0xff,0xfc,0x0,0x0,0xf,0xff,0xc0,0x0,0x0,0xf,0xff,
		0xff,0xff,0xff,0xf8,0x0,0x7,0xff,0xc0,0x0,0x0,0x1f,0xff,
		0xff,0xff,0xff,0xff,0x0,0x3,0xff,0xc0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xe0,0x1,0xff,0xc0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf0,0x0,0xff,0xc0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xfc,0x0,0xff,0xc0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xfe,0x0,0x7f,0xc0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0x0,0x7f,0xc0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0x0,0x3f,0xc0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0x80,0x3f,0xc0,0x3f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xc0,0x3f,0xc0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xc0,0x3f,0xe0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xc0,0x3f,0xe0,0x1f,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xc0,0x3f,0xe0,0x1,0xbf,0xff,0xff,
		0xff,0xff,0xff,0xff,0xf8,0x0,0x3f,0xe0,0x0,0x0,0x0,0xff,
		0xff,0xff,0xff,0xf8,0x0,0x0,0x3f,0xe0,0x0,0x0,0x0,0x7f,
		0xff,0xff,0xe0,0x0,0x0,0x0,0x3f,0xe0,0x0,0x0,0x0,0x7f,
		0xff,0xff,0xc0,0x0,0x0,0x0,0x3f,0xe0,0x0,0x0,0x0,0x7f,
		0xff,0xff,0x80,0x0,0x0,0x0,0x7f,0xf0,0x0,0x0,0x0,0x7f,
		0xff,0xff,0x80,0x0,0x0,0x0,0x7f,0xf8,0x0,0x0,0x0,0x7f,
		0xff,0xff,0x80,0x0,0x0,0x1,0xff,0xfc,0x0,0x0,0x0,0xff,
		0xff,0xff,0x80,0x0,0x0,0x3,0xff,0xff,0xfe,0xca,0x4f,0xff,
		0xff,0xff,0xc0,0x0,0x3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xe0,0x1,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
		0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,

};

const tImage lose = {
    .BPP = IMAGE_FMT_1BPP_UNCOMP,
    .NumColors = 2,
    .XSize = 96,
    .YSize = 95,
    .pPalette = imgPalette,
    .pPixel = loseData
};