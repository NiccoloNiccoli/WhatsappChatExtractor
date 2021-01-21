#include <iostream>
#include "File.h"
#include "Extractor.h"

int main() {
    std::string fileName = "C:\\Users\\super\\OneDrive\\Desktop\\chat2.txt";
    /*std::cout<<"Insert the full path of your file (Ex: C:\\Users\\Me\\Desktop\\chat.txt): "<<std::endl;
    std::cin>>fileName;
    std::cout<<std::endl;*/
    File file(fileName);
    Extractor extractor;
    extractor.extract(file);
    return 0;
}
