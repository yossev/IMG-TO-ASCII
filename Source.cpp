#include <iostream>
#include <fstream>  // Add this include for file operations
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cmath>

int calculateAvg(cv::Mat image, int row, int col, int scale)
{
    int sum = 0;
    int pixelCount = 0;
    int r = row, c = col;
    while (r <= row + scale && r < image.rows)
    {
        while (c <= col + scale && c < image.cols)
        {
            sum += static_cast<int>(image.at<uchar>(r, c));
            pixelCount++;
            c++;
        }
        r++;
    }
    return sum / pixelCount;
}

int main(int, char**)
{
    cv::Mat img = cv::imread("C:/Users/PC/Downloads/killua.jpg");

    cv::Mat GrayImg;
    cv::cvtColor(img, GrayImg, cv::COLOR_BGR2GRAY);
    std::string gscale = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:,\"^`'. ";

    std::ofstream outputFile("ascii.txt"); 

    if (!outputFile.is_open()) {
        std::cout << "Failed to open file" << std::endl;
        return -1;  
    }

    if (img.empty()) {
        std::cout << "Empty Image" << std::endl;
        return -1;  
    }

    int scale = 4;
    for (int i = 0; i < GrayImg.rows; i += scale) {
        std::string text = "";
        for (int j = 0; j < GrayImg.cols; j += scale) {
            int pixel = calculateAvg(GrayImg, i, j, scale);
            text += gscale[std::min(static_cast<size_t>(gscale.length() - 1), static_cast<size_t>(pixel * (gscale.length() - 1) / 255))];
            text += gscale[std::min(static_cast<size_t>(gscale.length() - 1), static_cast<size_t>(pixel * (gscale.length() - 1) / 255))];
        }
        outputFile << text << std::endl; 
    }

    outputFile.close();
    return 0;
}
