#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Function to preprocess the image (if required)
Mat preprocessImage(const Mat& inputImage) {
    // preprocessing code 
    return inputImage; // Placeholder, no preprocessing applied
}

// Function to find the shortest path on the grid
void findShortestPath(const Mat& inputImage) {
    //  path planning code 
    //  drawing a straight line from top-left to bottom-right
    Mat resultImage = inputImage.clone();
    line(resultImage, Point(0, 0), Point(inputImage.cols - 1, inputImage.rows - 1), Scalar(0, 255, 0), 2);
    
    // Printing coordinates of grid blocks involved in the shortest path
    for (int y = 0; y < resultImage.rows; y += 50) {
        for (int x = 0; x < resultImage.cols; x += 50) {
            // Checking if the pixel color is green (indicating the path)
            if (resultImage.at<Vec3b>(y, x) == Vec3b(0, 255, 0)) {
                // Printing coordinates on the image
                string text = "(" + to_string(x) + "," + to_string(y) + ")";
                putText(resultImage, text, Point(x, y), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 255, 255), 1);
            }
        }
    }

    // Displaying the result
    imshow("Shortest Path Result", resultImage);
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

    // Finding shortest path
    findShortestPath(preprocessedImage);

    return 0;
}
