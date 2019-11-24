#define _CRT_SECURE_NO_WARNINGS
/************************************************
Filename:Frame.cpp
Version: 1.0
Author:	Johnathon Cameron
Assignment Number:3
Assignment Name:Animation Project in C++
Course Name: C++
Course Code:CST219
Lab Section Number: 302
Professor's Name: Surbhi Bahri (Lecture) Mariusz Makos  (Lab)
Due Date: November 30th 2019
Submission Date:N/A
List of source files: Animation.pp,Animation.h,Frame.cpp,Frame.h,Assignment2.cpp,AnimationManager.cpp, Animation.h,VideoFrame.h, VideoFrame.cpp, AudioFrame.h, AudioFrame.cpp
Purpose: Class is an abstract class of frame, parent of Video and Audio Frame, with CalculateFrameRessource and the 
destructor being both virtual functions meant for the child classes to override.
**********************************/
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <forward_list>
#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"


/***********************************************
Function name: operator<<
Purpose: Function used to return output stream reference. It is used to print the 
default of the abtract frame class, also to determine the of what type the frame reference is
frame object.
In parameters: ostream&, Frame&
Out Parameters: ostream&
Version: 1.0
Author: Johnathon Cameron
************************************************/
ostream& operator<<(ostream& out,Frame& frame) {
	
	//Try casting to find type of frame it is
	try {
		//determine the frame type NOTE: dynamic_cast returns nullptr if reference is not of right type
		AudioFrame& audio = dynamic_cast<AudioFrame&>(frame);
		//output  audio Frame output and Frame default output
		out << audio << "Frame Name= " << frame.frameName << endl;
	//empty catch
	}catch (const bad_cast& e) {}
	
	try {
		//determine the frame type NOTE: dynamic_cast returns nullptr if reference is not of right type
		VideoFrame& vidFrame = dynamic_cast<VideoFrame&>(frame);
		//output videoFrame and frame default
		out <<vidFrame<< "Frame Name= " << frame.frameName <<  endl;
	}catch (const bad_cast& e) {}
	
	return out;
}