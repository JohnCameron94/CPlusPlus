/************************************************
					FILE HEADER

Filename:AudioFrame.cpp
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
List of source files: Animation.pp,Animation.h,Frame.cpp,Frame.h,Assignment2.cpp,AnimationManager.cpp, Animation.h,AudioFrame.h,AudioFrame.cpp,
Purpose: Class used to implement a AudioFrame derived from the abstract Frame class. The user can chose to create which type of frame when they are prompt to do so
in the Animation Class implementation (Animation.cpp). Once the user selects a Audio frame, it calculates the MP3 lossy compression with the equation size/ all compression ratios
**********************************/
using namespace std;
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <iomanip>
#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"
/***********************************************
Function name: CalculateFrameRessource()
Purpose: Functtion used to calculate the MP3 Lossy Compression within the data of he AudioFrame class.
Also prints out a formatted output of all the compression calculations.
In parameters: 
Out Parameters:
Version: 1.0
Author: Johnathon Cameron
************************************************/
void AudioFrame::CalculateFrameResource() {
	//size variable	
	int size = 3;
	//result array to store calculations
	double result[3];
	//for loop to calculate compresion
	for (int i = 0; i < size; i++) {
		result[i] = this->size / this->COMPRESSION_RATIO[i];
	}

	//Formatted compression output
	cout << "MP3 Lossy Compression"<< endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "bitrate:"<< setw(9) << "|" << this->BITRATE[0] << setw(7) << "|" << this->BITRATE[1] << setw(7) << "|" << this->BITRATE[2]<< endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;
	cout << "file size (MB): |" << setw(5);
	//Formatted output in for loop
	for (int i = 0; i < size; i++) {
		//last position in the array don't print pipe
		if (i == size - 1)
			cout << setw(5) << setprecision(2) << result[i] << endl;
		//any other position besides the last
		else
			cout << fixed << setprecision(2) << result[i] << setw(5) << "|";
	}
	//line seperator
	cout << "---------------------------------------------------------------------------------------------" << endl;

}
/***********************************************
Function name: operator<<
Purpose: Used for output default, showing the user it is an Audio Frame type
In parameters: ostream&, AudioFrame&
Out Parameters:&ostream
Version: 1.0
Author: Johnathon Cameron
************************************************/
ostream& operator<<(ostream& out, AudioFrame& audio_Frame) {
	out << "Audio Frame: " ;
	return out;
}