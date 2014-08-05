/**
 * data.h
 * granaSAT.Client
 *
 *  Created on: Jun 24, 2014
 *      Author: Mario Román
 */

// Avoids redefinition
#ifndef DATA_H
#define DATA_H

#include <images.h>
#include <stdio.h>
#include <stdint.h>
#include "log.h"

#define IMAGE_FILE "images/sample1.jpg"

// Status
//static int SPEED = 0;
static int MODE = 1;

// Measures
static float MAG[3];
static float ACC[3];

// Star Tracker
static int CATALOG = 4;
static int UNIT_VECTORS = 5;
static int PIXEL_THRESHOLD = 100;
static int ROI = 3;
static int POINTS = 1;
static float ERROR = 2.50;

// Camera
#define IMAGEBMP_SIZE 100
uint8_t IMAGE_STREAM [960*1280];
uint8_t IMAGEBMP_STREAM [IMAGEBMP_SIZE];
static int BRIGHTNESS = 0;
static int GAMMA = 100;
static int GAIN = 260;
static int EXPVALUE = 200;

// Horizon Sensor
static int BIN_TH = 50;
static int CANNY_TH = 100;

// Sending to server
// Defined in client.h
static void send_magnitude();
static void send_threshold();
static void send_unitaryVectors();
static void send_roi();
static void send_points();
static void send_error();
static void send_roi();
static void send_brightness();
static void send_gamma();
static void send_gain();
static void send_expvalue();
static void send_binthres();
static void send_canny();
static void send_mode();

// Setting variables
static void set_magnitude(int new_magnitude) {
    CATALOG = new_magnitude;
    printlog("");
    printf("[Star Tracker] Using star tracker catalog: %d\n", new_magnitude);
    send_magnitude();
}

static void set_unitary_vectors(int new_vectors) {
    UNIT_VECTORS = new_vectors;
    printlog("");
    printf("[Star Tracker] Using %d unitary vectors\n", new_vectors);
    send_unitaryVectors();
}

static void set_threshold(int threshold) {
    PIXEL_THRESHOLD = threshold;
    printlog("");
    printf("[Star Tracker] Using %d as threshold\n", threshold);
    send_threshold();
}

static void set_roi(int roi) {
    ROI = roi;
    printlog("");
    printf("[Star Tracker] Using %d as ROI\n", roi);
    send_roi();
}

static void set_points(int points) {
    POINTS = points;
    printlog("");
    printf("[Star Tracker] Using %d points\n", points);
    send_points();
}

static void set_error(float error) {
    ERROR = error;
    printlog("");
    printf("[Star Tracker] Using %f as error\n", error);
    send_error();
}

static void set_brightness(int bright) {
    BRIGHTNESS = bright;
    printlog("");
    printf("[Camera] Brightness changed to %d\n", bright);
    send_brightness();
}

static void set_gamma(int gamma) {
    GAMMA = gamma;
    printlog("");
    printf("[Camera] Gamma changed to %d\n", gamma);
    send_gamma();
}

static void set_gain(int gain) {
    GAIN = gain;
    printlog("");
    printf("[Camera] Gain changed to %d\n", gain);
    send_gain();
}

static void set_exposure_value(int expvalue) {
    EXPVALUE = expvalue;
    printlog("");
    printf("[Camera] Exposure value changed to %d\n", expvalue);
    send_expvalue();
}

static void set_binthres(int binthres) {
    BIN_TH = binthres;
    printlog("");
    printf("[Horizon Sensor] Binary threshold change to %d\n", binthres);
    send_binthres();
}

static void set_canny(int canny) {
    CANNY_TH = canny;
    printlog("");
    printf("[Horizon Sensor] Canny threshold change to %d\n", canny);
    send_canny();
}

static void set_magnetometer(float x, float y, float z) {
    printlog("");
    printf("[Data] Magnetometer measures:  %f,%f,%f\n", x,y,z);
    MAG[0] = x;
    MAG[1] = y;
    MAG[2] = z;
}

static void set_accelerometer(float x, float y, float z) {
    printlog("");
    printf("[Data] Accelerometer measures: %f,%f,%f\n", x,y,z);
    ACC[0] = x;
    ACC[1] = y;
    ACC[2] = z;
}

static void set_mode(int mode) {
    MODE = mode;
    printlog("");
    printf("Altitude determination mode changed\n");
    send_mode();
}

static void set_image() {
    write_image_to_file("image.raw");
    //transform_image("image.bmp");
}

static void set_imagebmp() {
    write_bmp_to_file("image.bmp");
    //transform_image("image.bmp");
}

#endif
