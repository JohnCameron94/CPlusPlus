/************************************************
Filename:AnimationManager.cpp
Version: 1.0
Author:	Johnathon Cameron
Assignment Number:2
Assignment Name:Animation Project in C++
Course Name: C++
Course Code:CST219
Lab Section Number: 302
Professor's Name: Surbhi Bahri (Lecture) Mariusz Makos  (Lab)
Due Date: November 9th 2019
Submission Date:November 9th 2019
List of source files: Animation.pp,Animation.h,Frame.cpp,Frame.h,Assignment2.cpp,AnimationManager.cpp, Animation.h,VideoFrame.h, VideoFrame.cpp, AudioFrame.h, AudioFrame.cpp
Purpose:Purpose used to Create a vector of Animations that each hold a forward list of frames. These Animations can be edited
deleted, added and displayed. AnimationManagers is the class that controls the inserting of animations into the vector, by name
entered by the user.
**********************************/
using namespace std;
#include <crtdbg.h>
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
#include "Frame.h"
#include "Animation.h"
#include "AnimationManager.h"
#include "VideoFrame.h"
#include "AudioFrame.h"
/*****************************************
Function name : EditAnimation
Purpose : Used to access the frames menu within the animation
In Parameters:n/a
Out Parameters:n/a
Version : 1.0
Author : Johnathon Cameron
*****************************************/
void AnimationManager::EditAnimation() {
	
	//check if vector is empty
	if (animations.empty()) {
		cout << "No Animations to Edit" << endl;
	}else {
		//get the size of the vector -1, for indexing
		int size = animations.size() - 1, index = 0;
		cout << "Please Enter index(0-" << size << ") of which Animation you would like to edit:" << endl;
		cin >> index;

		//if the index is valid
		if (index <= size && index >= 0) {			
			//Edit the animations frames
			cout << "Edditing Animation #" << index << endl;
			cin >> animations[index];

			//completion display
			cout << "Animation #" << index << " is Complete!" << endl;
		}else 
			cout << "Animation doesn't exits" << endl;
		
	}

}

/*****************************************
Function name : DeleteAnimation
Purpose : Used to delete the first item of the vector
In parameters :n/a
Out Parameters :n/a
Version : 1.0
Author : Johnathon Cameron
*****************************************/
void AnimationManager::DeleteAnimation() {
	//index user wants to delete
	int index; 

	//check if vector is empty
	if (animations.empty()) {
		cout << "No Animations to Delete" << endl;
	}else {
		cout << "Delete Animation from Manager " << managerName
			 << " Which Animation do you which to delete. Enter index range from 0 to " << animations.size()-1 << endl;
		cin >> index;

		//if index is valid
		if (index < animations.size() && index >= 0) {
			cout << "Deleting Animation #" << index << endl;
			//erase index by starting and adding index value to the begin of vector
			animations.erase(animations.begin() + index);
		}else {
			cout << "Animation doesn't exits" << endl;
		}
	}
}
/*****************************************
Function name : operator>>
Purpose : Used to add Animation to vector, by overloading the input function in std
In parameters :istream& in, AnimationManager& mngr
Out Parameters :istream& in
Version : 1.0
Author : Johnathon Cameron
*****************************************/
istream& operator>>(istream& in, AnimationManager& mngr) {


	//animation name storage
	string anName;

	//Prompt user for animation name
	cout << "Please Enter Animation Name" << endl;
	in >> anName;
	//check if animation is empty, reserve the size to avoid destructor calls
	if (mngr.animations.empty()) {

		//reserving size of vecort limiting the size(temporary fix) 
		mngr.animations.reserve(64);
	}
	//push new animation object to back of the vector
	mngr.animations.push_back(Animation(anName));

	//returning istream
	return in;

}
/*****************************************
Function name : operator<<
Purpose : output the vector list of animations and the frames within the animation
In parameters : ostram& out, AnimationManager& mngr
Out Parameters : ostream out
Version : 1.0
Author : Johnathon Cameron
*****************************************/
ostream& operator<<(ostream& out, AnimationManager& mngr) {
	//if the there isn't any animations
	if (mngr.animations.empty()) {
		//display empty
		out << "No Animations to be Displayed" << endl;
	}else {
		//counter to keep track of the number of animations printed
		int counter = 0;
		//Print manager name
		out << "Animation Manager: " << mngr.managerName << endl;
		out << endl;

		// for loop to iterate through the animation vector. i is the iterator
		for (auto i = mngr.animations.begin(); i != mngr.animations.end(); i++) {
			//print the Animation
			out << "Animation: " << counter++  << endl
				<< *i;
		}
		out << endl;
		out << endl;
	}
	//return output stream
	return out;
}