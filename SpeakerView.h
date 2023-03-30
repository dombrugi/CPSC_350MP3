#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

#include "MonoStack.h"

class SpeakerView{
    public:
        SpeakerView();
        virtual ~SpeakerView();
        void FileProcessor(string inputFile);
    private:
        int columnNumber;
        int N;
        int P;
};

#endif