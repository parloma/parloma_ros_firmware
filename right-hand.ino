#include <ros.h>
#include <sensor_msgs/JointState.h>
#include "Joint.hpp"
#include <string.h>

ros::NodeHandle  nh;

Joint *fingers[5];

void jointCb( const sensor_msgs::JointState& joints) {
    for (int i = 0; i < joints.position_length; i++) {
        for (int j = 0; j < 5; j++) {
            if (fingers[j]->has_name(joints.name[i])){
                fingers[j]->move(joints.position[i]);
            }
        }
    }
}

ros::Subscriber<sensor_msgs::JointState> sub("right_hand", jointCb );

void setup() {
    fingers[0] = new Joint("thumb", 6, 135, 40);
    fingers[1] = new Joint("index", 2, 140, 10);
    fingers[2] = new Joint("middle", 3, 135, 30);
    fingers[3] = new Joint("ring", 4, 20, 140);
    fingers[4] = new Joint("pinky", 5, 160, 35);

    for (int i = 0; i < 5; i++) {
        fingers[i]->attach();
    }
    nh.initNode();
    nh.subscribe(sub);
}

void loop() {
    nh.spinOnce();
}