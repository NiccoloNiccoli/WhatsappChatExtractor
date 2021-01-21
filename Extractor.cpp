//
// Created by Niccolò Niccoli on 20/01/2021.
//
#include <iostream>
#include <sstream>
#include<algorithm>
#include<iterator>
#include "Extractor.h"

Extractor::Extractor() {

}

int Extractor::extract(File file) {
    for(auto i = file.fullText.begin(); i<=file.fullText.end(); ++i){
        std::string time="", date="", sender="", msg="";
        while((time.empty() || date.empty() || sender.empty() || msg.empty())&&(i!=file.fullText.end())) {
            std::istringstream iss(*i);
            std::vector<std::string> currentString{std::istream_iterator<std::string>{iss},
                                                   std::istream_iterator<std::string>{}};
            //now I have every word separated by the others
            //I have to check if the string has some important infos (like the date and the sender)

            for (auto j = currentString.begin(); j != currentString.end(); ++j) {
                if (*j == "class=\"copyable-text\"") {//this is the right string
                    std::string tmpString = *(j + 1); //it should be something like "data-pre-...-"[hh:mm, date]
                    auto k = tmpString.find('[');
                    ++k;
                    time = "";
                    for (int q = 0; q < 5; q++) //hh:mm
                        time += tmpString.at(k + q);
                    //now it's time for the date
                    tmpString = *(j + 2);
                    tmpString.erase(tmpString.end() - 1);
                    date = tmpString;
                    //now it's time for the sender
                    tmpString = "";
                    for (int q = 3; j + q != currentString.end(); ++j) {
                        tmpString += *(j + q) + " ";
                    }
                    k = tmpString.find(":");
                    for (int q = 0; q < k; ++q)
                        sender += tmpString.at(q);
                    break;
                }
                else if((*j == "<span" && *(j+1) == "dir=\"ltr\"")){//from this/the next one/two lines after the text begins
                    //now I check every word until I find <span>, which is the thing before the message
                    std::string tmpString =*i;
                    tmpString.erase(tmpString.begin(), tmpString.begin()+tmpString.find('<')+1);
                    auto beginning = tmpString.find_first_of('<');
                    beginning+=5; //for span>
                    tmpString.erase(tmpString.begin(),tmpString.begin()+beginning);
                    auto end = tmpString.find('<');
                    tmpString.erase(tmpString.end()-tmpString.size()+end,tmpString.end());
                    msg = tmpString;
                    break;
                }
            }
            ++i;
        }
        std::cout<<date<< ", " <<time<<" - "<<sender<<":"<<msg<<std::endl;

    }
}

