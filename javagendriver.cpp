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

#define LINE_LENGTH 60

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
 * @pre queue is passed by ref
 * @post queue contains strings of tag + descrip
 */
void getTags(std::queue<std::string>& q);

/**
 * @brief Main function to execute JavaDoc generation
 *
 */
int main() {

    //determining which language
    std::string response;
    std::cout << "Java, c++, or python? [1,2,3] -> ";
    std::cin >> response;
    std::cout << std::endl;
    strToLower(response);

    while (response != "1" &&
    response != "2" &&
    response != "3" &&
    response != "java" &&
    response != "c++" &&
    response != "python"
    ) {

        std::cout << "Please type 1 for java, 2 for c++, 3 for python, or type the name: ";
        std::cin >> response;

    }

    std::queue<std::string> tags;

    if (response == "1" ||
    response == "2" ||
    response == "java" ||
    response == "c++") { //if java or c++

        std::string init = "/**\n";
        std::string term = " */";
        getTags(tags);

    } else if (response == "3" ||
    response == "python") { //if python

        std::string close = "\"\"\"\n";
        getTags(tags);


    } else {

        throw std::invalid_argument("The response catching is bugged! Please notify me!");

    }

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
 * @pre queue is passed by ref
 * @post queue contains strings of tag + descrip
 */
void getTags(std::queue<std::string>& q) {

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

        //formatting description
        size_t i = LINE_LENGTH;
        while (i < descrip.length()) {

            size_t j = i;
            while (j < descrip.length() && descrip[j] != ' ') {
                ++j;
            }

            i = j;
            descrip.insert(i,"\n\t");

            i += LINE_LENGTH;

        }

        std::string line = tag + " " + descrip;
        q.push(line);

        std::string response;
        std::cout << "Would you like to enter another tag? [Y | N] ";
        std::cin >> response;
        strToLower(response);

        if (response == "n" || response == "no") {
            state = false;
        }

    } while (state);

}

