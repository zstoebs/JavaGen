/**
 * @name javagendriver.cpp
 * @brief Driver for JavaGen
 * @author Zach Stoebner
 * @date 8-24-2019
 * Copyright 2019 All rights reserved.
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>

///HELPER FUNCTIONS

/**
 * @brief converts all chars in string to lowercase
 * @param str
 * @return lowercase string
 */
void strToLower(std::string& str);

/**
 * @brief continuously gets tags and body text until terminated
 * @details Uses queues to store body strings and tags
 * @param <q> queue to hold tags and descriptions
 * @param <LENGTH> line length of descriptions
 * @pre queue is passed by ref
 * @post queue contains strings of tag + description
 */
void getTags(std::queue<std::string>& q, const size_t& LENGTH);

/**
 * @brief Main function to execute JavaDoc generation
 *
 */
int main() {

    bool state = true;
    do {

        //determining which language
        std::string response;
        std::cout << "Java, c++, or python? [1,2,3] -> ";
        std::cin >> response;
        strToLower(response);
        std::cout << std::endl;

        while
        (response != "1" &&
         response != "2" &&
         response != "3" &&
         response != "java" &&
         response != "c++" &&
         response != "python"
        ) {

            std::cout << "Please type 1 for java, 2 for c++, 3 for python, or type the name: ";
            std::cin >> response;
            strToLower(response);
            std::cout << std::endl;

        }

        //getting line length for descriptions
        size_t lineLength;
        bool first = true;
        do {

            if (first) {
                std::cout << "What is the line length of the descriptions? ";
                first = false;
            } else {
                std::cin.clear();
                std::cout << "Please enter a valid line length: ";
            }

        } while (!(std::cin >> lineLength));
        const size_t LINE_LENGTH = lineLength;

        std::cout << std::endl;

        //getting tags and descriptions
        std::queue<std::string> tags;
        if (response == "1" ||
            response == "2" ||
            response == "java" ||
            response == "c++") { //if java or c++

            std::string init = "/**\n";
            std::string term = " */";
            getTags(tags,LINE_LENGTH);

            while (!tags.empty()) {

                init += " * " + tags.front();

            }
            init += term;
            std::cout << "Here's your Javadoc header!\n" << std::endl;
            std::cout << init << std::endl;

        } else if (response == "3" ||
                   response == "python") { //if python

            std::string init = "\"\"\"\n";
            getTags(tags,LINE_LENGTH);

            while (!tags.empty()) {

                init += " * " + tags.front();

            }
            init += "\"\"\"";
            std::cout << "Here's your Javadoc header!\n" << std::endl;
            std::cout << init << std::endl;

        } else {

            throw std::invalid_argument("The response catching is bugged! Please notify me!");

        }

        std::cout << "Would you like to create another Javadoc header? [Y | N] ";
        std::cin >> response;
        strToLower(response);

        if (response == "n" || response == "no") {
            state = false;
        }


    } while(state);

    return 0;

}

/**
 * @brief converts all chars in string to lowercase
 * @param str
 * @return lowercase string
 */
void strToLower(std::string& str) {

    for (size_t i = 0; i < str.length(); ++i) {

        char c = std::tolower(str[i]);
        str[i] = c;

    }

}

/**
 * @brief continuously gets tags and body text until terminated
 * @details Uses queues to store body strings and tags
 * @param <q> queue to hold tags and descriptions
 * @param <LENGTH> line length of descriptions
 * @pre queue is passed by ref
 * @post queue contains strings of tag + description
 */
void getTags(std::queue<std::string>& q, const size_t& LENGTH) {

    bool state = true;
    do {

        //getting and formatting tag
        std::string tag;
        std::cout << "Enter tag: ";
        std::cin >> tag;
        strToLower(tag);
        tag = "@" + tag;
        if (tag == "param") {

            std::string paramName;
            std::cout << "Whats the parameter name? ";
            std::cin >> paramName;
            tag += "<" + paramName + ">";

        }
        std::cout << std::endl;

        //getting description
        std::string descrip;
        std::cout << "Enter tag description: ";
        std::cin >> descrip;
        std::cout << std::endl;

        //formatting description
        size_t i = LENGTH-1;
        size_t descripLength = descrip.length();
        while (i < descripLength) {


            while (i < descripLength && descrip[i] != ' ') {
                ++i;
            }

            if (i != descripLength-1) {
                descrip.insert(i, "\n\t");
            }

            i += LENGTH;

        }

        std::string line = tag + " " + descrip + "\n";
        q.push(line);

        std::string res;
        std::cout << "Would you like to enter another tag? [Y | N] ";
        std::cin >> res;
        strToLower(res);
        std::cout << std::endl;

        if (res == "n" || res == "no") {
            state = false;
        }

    } while (state);

}

