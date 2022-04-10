/**
* \file publisher.cpp
* \brief  the is the briefe
* \author ghani
* \version 1.0
*
* this is detailed description befor /
* 
* \details
* this is the details description
* 
* Publishes to: <BR>
*   /chatter
* 
* Subscribers to
*
*
* 
* 
*Descrption:
* this is description   
**/

#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>



int x; ///< x is a global variable 
int main(int argc, char **argv)
{
  /**
   * @brief this is the main function
   * @param argc 1st argument
   * @param **argv 2nd argument
   * @return nothing 
   */
  ros::init(argc, argv, "talker");

  
  ros::NodeHandle n;

  
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);


  int count = 0;
  while (ros::ok())
  {
  
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

   
    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
