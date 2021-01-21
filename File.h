//
// Created by Niccolò Niccoli on 20/01/2021.
//

#ifndef WHATSAPPCHATEXTRACTOR_FILE_H
#define WHATSAPPCHATEXTRACTOR_FILE_H


#include <string>
#include <vector>

class File {
    public:
        File(const std::string& fileName);
        void print();

    [[nodiscard]] const std::string &getName() const;

    std::vector<std::string> fullText;

private:
        std::string name;

};


#endif //WHATSAPPCHATEXTRACTOR_FILE_H
