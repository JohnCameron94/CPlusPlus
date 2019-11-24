/************************************************
					FILE HEADER

Filename:VideoFrame.cpp
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
List of source files: Animation.pp,Animation.h,Frame.cpp,Frame.h,Assignment2.cpp,AnimationManager.cpp, Animation.h,AudioFrame.h,AudioFrame.cpp,VideoFrame.h,VideoFrame.cpp
Purpose: Class used to implement a VideoFrame derived from the abstract Frame class. The user can chose to create which type of frame when they are prompt to do so
in the Animation Class implementation (Animation.cpp). Once the user selects a Video frame, it calculates the
Lempel-Ziv-Welch Lossless Compression with the equation size/ compression ratio x Bitdepth factor
**********************************/
using namespace std;
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <iomanip>
#include "Frame.h"
#include <forward_list>
#include "AudioFrame.h"
#include "VideoFrame.h"

/***********************************************
Function name: CalculateFrameRessource()
Purpose: Functtion used to calculate the Lempel-Ziv-Welch Lossless Compression 
within the data of he VideoFrame class. Function is overriden from the abstract Frame Class
Also prints out a formatted output of all the compression calculations.
In parameters:
Out Parameters:
Version: 1.0
Author: Johnathon Cameron
************************************************/
void VideoFrame::CalculateFrameResource() {
	
	//size in bytes
	int byteSize = 8;
	//result size 8 bytes
	double result[8];
	//calculation for compression store results into an array
	for (int i = 0; i < byteSize; i++) {
		result[i] = this->size / (this->COMPRESSION_RATIO * this->BITDEPTH_FACTOR[i]);
	}
	//cout <<*this<<(Frame&)*this<<endl;
	//Formatted Print out for compression calculation
	cout << "Lempel-Ziv-Welch Lossless Compression" << endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout<< "colours:"<<setw(9)<<"|" <<this->BITS / 4 <<setw(9)<<"|" << this->BITS / 2 << setw(9)<<"|" << this->BITS / 1 << setw(9)<<"|" << this->BITS * 2 <<setw(8)<< "|" << this->BITS * 4 << setw(8)<<"|" << this->BITS * 8 <<setw(8)<<"|" << this->BITS * 16 <<setw(7)<<"|"<< this->BITS * 64 << endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "file size (MB): |"<<setw(5);
	//Formatted print out
	for (int i = 0; i < byteSize; i++) {
		if (i == byteSize-1)
			cout <<setw(5)<<setprecision(3)<< result[i] << endl;
		else
		cout<<fixed<<setprecision(3)<<result[i]<<setw(5)<<"|";
	}
	//line seperator
	cout << "---------------------------------------------------------------------------------------------" << endl;
}
/***********************************************
Function name: operator<<
Purpose: Used for output default, showing the user it is an Video Frame type
In parameters: ostream&, VideoFrame&
Out Parameters:&ostream
Version: 1.0
Author: Johnathon Cameron
************************************************/
ostream& operator<<(ostream& out, VideoFrame& vidFrame) {
	//output VideoFrame
	out << "Video Frame: ";


	return out;
}