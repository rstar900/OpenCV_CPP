#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

using namespace cv;

int main()
{
    //Find the path of the image file in samples (samples folder path could be different for you)
    samples::addSamplesDataSearchPath("/home/rachit/Applications/OpenCV/opencv-master/samples/data");
    std::string filePath = samples::findFile("starry_night.jpg");
    
    //Read the image file into a cv::Mat datatype
    Mat inputImg = imread(filePath, IMREAD_COLOR);

    //Check whether the file can be read or not
    if(inputImg.empty())
    {
        std::cout << "Cannot read the image file" << std::endl;
        return 1;
    }

    //if the image can be read display it
    imshow("Display Image", inputImg);

    //wait forever for a keypress to exit (0 means forever)
    int k = waitKey(0);

    //save the image if s is pressed
    if(k == 's')
    {
        imwrite("starry_night.png", inputImg);
    }

    return 0;
}

