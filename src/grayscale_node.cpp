#include "ros/ros.h"
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

cv_bridge::CvImagePtr cv_ptr;
cv::Mat image;

void publishGrayscale(const sensor_msgs::ImageConstPtr& rosImage)
{
  cv_ptr = cv_bridge::toCvCopy(rosImage, sensor_msgs::image_encodings::BGR8);
  image = cv_ptr->image;
  if(!image.empty()){
    cv::cvtColor(image, image, cv::COLOR_BGR2GRAY);
    cv::imshow("win", image);
    cv::waitKey(1);
  }
  else{
    std::cout << "error loading image, are you running usb_cam?" << std::endl;
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "grayscale_node");
  ros::NodeHandle n;
  image_transport::ImageTransport it(n);
  image_transport::Subscriber image_sub_;
  image_sub_ = it.subscribe("/usb_cam/image_raw", 1, publishGrayscale);
  ros::spin();
  return 0;
}
