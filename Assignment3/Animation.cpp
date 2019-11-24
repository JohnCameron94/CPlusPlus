/************************************************
Filename:Animation.cpp
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
Purpose: Class used to implement a forward_list of frames under a animation object (animations within a vector)
The user can input through the overloaded function of std (operator >>) to insert and modify frames within the forward
list. It also implements a delete functionality that will delete the first frame from the forward_list.
**********************************/
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"
#include "Animation.h"
#include "AnimationManager.h"

/***********************************************
Function name: ~Animation
Purpose:Destruct all the allocated memory before program termination from the forward_list
In parameters: none
Out Parameters:none
Version: 1.0
Author: Johnathon Cameron
************************************************/
Animation::~Animation() {
	//check for empty list
	forward_list<Frame*> ::iterator it;
	if (!frames.empty()) {
		//loop through list and deallocate memory
			for(it = frames.begin(); it!=frames.end(); it++)
				delete* it;
		
	}
}

/***********************************************
Function name: EditFrame
Purpose:Edit Frame prompt to by the user to change frame name and file size
In parameters: none
Out Parameters:none
Version: 1.0
Author: Johnathon Cameron
************************************************/
void Animation::EditFrame() {
	//AudioFrame pointer
	AudioFrame* pAF;
	//Video frame pointer
	VideoFrame* pVF;
	//iterator
	forward_list<Frame*>::iterator it;
	//Counter variable for the amount of elements in list
	int size = distance(frames.begin(), frames.end());
	//Variables for index number entered by the user
	int index = 0;
	//temporary variables that holds changed frameName
	string tempName;
	//temp double that holds changed durations
	double fileSize;
	
	//If list is empty
	if (frames.empty()) {
		cout << "No Frames to be changed" << endl;
	}else{
		//Prompt user
		cout << "There are " << size << " Frame(s) in the list. Please specify the index (<=0) to edit at : " << endl;
		cin >> index;//user index choice

		//check if index is valid
		if (index >=size || index < 0) {
			cout << "Index doesn't exist" << endl;
		}else {
			//count variable to match index
			int count = 0;
			//for loop using iterator from begin to end of forward_list
			for (it = frames.begin(); it != frames.end(); it++) {
				//if index matches count
				if (index == count) {
					//display data members from frame
					cout << "The name of this Frame is " << **it << endl;
					//prompt user to enter new values (two inputs required)
					cout << "What do You Wish to change them to?(Name/size)" << endl;
					//input new data
					cin >> tempName >> fileSize;

					if ((pAF = dynamic_cast<AudioFrame*>(*it)) != nullptr){
						*pAF = AudioFrame(tempName, fileSize);
						*it = pAF;
						
					}else if((pVF = dynamic_cast<VideoFrame*>(*it)) != nullptr) {
						*pVF = VideoFrame(tempName, fileSize);
						*it = pVF;
					}
					//break iterator when complete
					break;
				}
				//increment counter if index doesn't match
				count++;
			}
		}
	}
}
/***********************************************
Function name: DeleteFrame
Purpose:Edit Delete last node within the list
In parameters: none
Out Parameters:none
Version: 1.0
Author: Johnathon Cameron
************************************************/
void Animation::DeleteFrame() {

	//Must check if frames are empty first
	if (!frames.empty()) {
		cout << "Delete first Frame" << endl;
		//poping first element from list

		frames.pop_front();
	}
	else // if frames are empty let user know
		cout << "No Frames to be deleted" << endl;
}

/*****************************************
Function name : operator<<
Purpose : output the forward list of frames
In parameters : ostram& out, Animation& an
Out Parameters : ostream out
Version : 1.0
Author : Johnathon Cameron
*****************************************/
ostream& operator<<(ostream& out, Animation& RA) {
	//counter to keep track of the index of each frame
	int counter = 0;
	//iterator for forward_list of Frame pointers
	forward_list<Frame*>::iterator it;
	//Display in which animation the frames are from
	out << "	Animation Name : " << RA.animationName << endl;
	out << "	Report Animation: " << endl;

	//check if frames are empty
	if (RA.frames.empty())
		out << "	No frames" << endl;
	else {
		//iterate through the frames forwardList
		for (it = RA.frames.begin(); it != RA.frames.end(); it++) {
			out << "Frame #" << counter++ << endl;
			//calculate the frames ressources
			(*it)->CalculateFrameResource();
		}
	}
	//return ostream
	return out;
}

/*****************************************
Function name : operator>>
Purpose : animation menu, used to insert edit and delete frames from the animations
In parameters : ostram& in, Animation& an
Out Parameters : ostream in
Version : 1.0
Author : Johnathon Cameron
*****************************************/
istream& operator>>(istream& in, Animation& RA) {
	forward_list<Frame*> temp_list;
	//temp storage for string
	string name;
	//switch case handler
	char response;
	//while loop boolean
	bool back_to_main = false;
	//double for frame member variable
	double size;
	
	//while user wants to modify frames
	while (!back_to_main) {
		//menu display
		cout << "MENU\n 1. Insert a Frame at the front\n 2. Delete last Frame\n 3. Edit a Frame\n 4.Back to Animation" << endl;
		in >> response;

		//user response
		switch (response){

		case '1':

			Frame* vF;
			//prompt user for input
			cout << "Insert a Frame to the front" << endl;
			//ask user for frameName
			cout << "Please enter the Frame name: ";
			in >> name;

			cout << "Please enter the size : ";
			in >> size;

			//Type of frame creation
			char type;
			//prompt user to create Audio or Video frame
			cout << "Please enter 'A' for AudioFile or 'V' for Videofile" << endl;
			cin >> type;
			switch (type) {
				//condition on user input
			case 'A':

				vF = new  AudioFrame(name, size);
				cout << "Frame " << name << " of type Audio added to the front of the list" << endl;
				break;

			case 'V':
				vF = new VideoFrame(name, size);
				cout << "Frame " << name << " Frame* of Type Video added to the front of the list" << endl;
				break;
			default:
				cout << "Invalid Entry" << endl;
				break;

			}
			//pushing frame to front
			RA.frames.push_front(vF);
			
	
			break;

		//delete frame
		case '2':RA.DeleteFrame(); break;
		//edit frame
		case '3':RA.EditFrame(); break;
		//back to main menu
		case '4':back_to_main = true;
			break;
		//handle invalid values
		default:cout << "Please enter a valid option" << endl;
		}
	}
	//return istream
	return in;
}