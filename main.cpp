#include <iostream>
#include "File.h"
#include "Extractor.h"

int main() {
    std::string fileName = "C:\\Users\\super\\OneDrive\\Desktop\\data.txt";
    /*std::cout<<"Insert the full path of your file (Ex: C:\\Users\\Me\\Desktop\\chat.txt): "<<std::endl;
    std::cin>>fileName;
    std::cout<<std::endl;*/
    File file(fileName);
    Extractor extractor;
    extractor.extract(file);
    /*TODO
     * stampare la chat in un file di testo
     * leggere anche i messaggi _ * ~ ```
     * leggere i messaggi delle foto
     * leggere i messaggi multi-riga
     * */
    return 0;
}
