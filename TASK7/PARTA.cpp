#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

// Function to preprocess the image (if required)
Mat preprocessImage(const Mat& inputImage) {
    
    return inputImage; // Placeholder, no preprocessing applied
}

// Function to detect the grid cells in the image
void detectGridCells(const Mat& inputImage) {
    Mat grayImage;
    cvtColor(inputImage, grayImage, COLOR_BGR2GRAY);
    
    // Applying thresholding to binarize the image
    Mat binaryImage;
    threshold(grayImage, binaryImage, 100, 255, THRESH_BINARY_INV);

    // Finding contours in the binary image
    vector<vector<Point>> contours;
    findContours(binaryImage, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // Drawing contours on the original image
    Mat resultImage = inputImage.clone();
    drawContours(resultImage, contours, -1, Scalar(0, 0, 255), 2);

    // Displaying the result
    imshow("Grid Detection Result", resultImage);
    waitKey(0);
}

int main() {
    // Reading the input image
    Mat inputImage = imread("grid_image.jpg");

    // Checking if the image is loaded successfully
    if (inputImage.empty()) {
        cerr << "Error: Could not open or find the image" << endl;
        return -1;
    }

    // Preprocessing the image (if required)
    Mat preprocessedImage = preprocessImage(inputImage);

    // Detecting grid cells
    detectGridCells(preprocessedImage);

    return 0;
}
