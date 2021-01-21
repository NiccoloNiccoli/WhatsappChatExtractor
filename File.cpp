//
// Created by Niccolò Niccoli on 20/01/2021.
//

#include <fstream>
#include <iostream>
#include "File.h"

File::File(const std::string &fileName) {
    name = fileName;
    std::ifstream file(name);
    if(file.is_open()){
       std::string currentLine;
        while(std::getline(file, currentLine)){
            fullText.push_back(currentLine);
        }
    }
}

void File::print() {
    for(auto i:fullText)
        std::cout<<i<<std::endl;
}

const std::string &File::getName() const {
    return name;
}



