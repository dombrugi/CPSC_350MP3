#include "SpeakerView.h"
#include "MonoStack.h"
#include <fstream>

SpeakerView::SpeakerView(){
}

SpeakerView::~SpeakerView(){
}

void SpeakerView::FileProcessor(string inputFile){
    ifstream file;



    //if I could figure out how to read doubles from a file
    //I would use a for loop to pass all of the values into a 2d array
    //then use a for loop to push the values from the array, column by column onto the monostack
    //then I would pop the values back off the stack and print to terminal the height of the people in there, since they could see
    //I would repeat this until the 2d array was empty
}
