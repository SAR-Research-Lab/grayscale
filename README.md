Grayscle

The purpose of this node is to demonstrate how to retrieve images in ROS and manipulate them using opencv. This was created to support courses at UM-Dearborn. It is intended as a very simple OpenCV app working within ROS with dependencies configured correctly. 

Installation on RasPi
- install nodes:
  usb_cam
  image_common
 
- clone this package into the src folder of your workspace
- Run 'catkin_make' in the root of your workspace

Running the example
- Run 'source devel/setup.bash' in the root of your workspace
- Run 'roslaunch grayscale grayscale.launch'
