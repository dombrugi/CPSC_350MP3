#include "SpeakerView.h"
#include "MonoStack.h"

using namespace std;

int main(int argc, char** argv){
    string inputFile = argv[1];
    SpeakerView s1;
    s1.FileProcessor(inputFile);
}