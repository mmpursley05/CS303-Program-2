// CS303Pgm2Starter.cpp : This file contains the 'main' function. Program execution begins and ends there.
// NAME: Maggie Pursley
// CS303
// PROGRAM 2
#include "SingleLinkedList.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// function to process commands for integer list
void processIntCommands(const std::string &filename) {
  std::ifstream inFile(filename);
  std::ofstream outFile("logFileInt.txt");

  // Katy:
  // check if file opened successfully
  if (!inFile) {
    std::cerr << "Error opening input file: " << filename << std::endl;
    return;
  }

  // Katy:
  // check if output file opened successfully
  if (!outFile) {
    std::cerr << "Error opening output file: logFileInt.txt" << std::endl;
    return;
  }

  // Maggie:
  // create single linked list for integers
  SingleLinkedList<int> list;
  std::string line, command;
  // initialize integers value and value 2
  int value, value2;

  // Sivkan:
  // reads each line from file
  while (std::getline(inFile, line)) {
    std::istringstream iss(line);
    iss >> command;
    outFile << "Command: " << line << std::endl;

    // Maggie: implemented try and all if/else if statements
    try {
      // if function to be called is push front
      if (command == "pushFront") {
        // get value
        iss >> value;
        // call function
        list.pushFront(value);
        // write success mesage
        outFile << "Pushed " << value << " to front. List now has "
                << list.getNumItems() << " items." << std::endl;
      }
      // else if command is pushBack
      else if (command == "pushBack") {
        iss >> value;
        // call function to push back and pass in value
        list.pushBack(value);
        outFile << "Pushed " << value << " to back. List now has "
                << list.getNumItems() << " items." << std::endl;
      }
      // else if command is popFront
      else if (command == "popFront") {
        value = list.popFront();
        outFile << "Popped " << value << " from front. List now has "
                << list.getNumItems() << " items." << std::endl;
      }
      // else if command is popBack
      else if (command == "popBack") {
        value = list.popBack();
        outFile << "Popped " << value << " from back. List now has "
                << list.getNumItems() << " items." << std::endl;
      }
      // else if command is front
      else if (command == "front") {
        value = list.front();
        outFile << "Front item is: " << value << std::endl;
      }
      // else if command is back
      else if (command == "back") {
        value = list.back();
        outFile << "Back item is: " << value << std::endl;
      }
      // else if command is empty
      else if (command == "empty") {
        outFile << "List is " << (list.empty() ? "empty" : "not empty")
                << std::endl;
      }
      // else if command is find
      else if (command == "find") {
        if (iss >> value) {
          bool found = list.find(value);
          outFile << value << " is " << (found ? "found" : "not found")
                  << " in the list." << std::endl;
        } else {
          outFile << "Error: Missing value for find command." << std::endl;
        }
      }
      // else if command is remove
      else if (command == "remove") {
        iss >> value;
        bool removed = list.remove(value);
        outFile << value << " was " << (removed ? "removed" : "not found")
                << ". List now has " << list.getNumItems() << " items."
                << std::endl;
      }
      // else if command is add before
      else if (command == "addBefore") {
        iss >> value >> value2;
        list.addBefore(value, value2);
        outFile << "Added " << value2 << " before " << value
                << ". List now has " << list.getNumItems() << " items."
                << std::endl;
      }
      // else if command is insert
      else if (command == "insert") {
        size_t pos;
        iss >> pos >> value;
        list.insert(pos, value);
        outFile << "Inserted " << value << " at position " << pos
                << ". List now has " << list.getNumItems() << " items."
                << std::endl;
      }
      // if command is print
      else if (command == "print") {
        outFile << "List contents: ";
        if (list.empty()) {
          outFile << "List is empty." << std::endl;
        } else {
          // create copy of linked list
          SingleLinkedList<int> tempList = list;
          // loop through while list is not empty
          while (!tempList.empty()) {
            // output the head
            outFile << tempList.front() << " ";
            // remove the head
            tempList.popFront();
          }
          // formatting
          outFile << std::endl;
        }
      }
      // if command is quit
      else if (command == "quit") {
        outFile << "Quitting program." << std::endl;
        break;
      } else {
        outFile << "Unknown command: " << command << std::endl;
      }
    } catch (const std::exception &e) {
      outFile << "Error: " << e.what() << std::endl;
    }

    outFile << std::endl;
  }

  inFile.close();
  outFile.close();
}

// Katy:
// function to process commands for float list
void processFloatCommands(const std::string &filename) {
  std::ifstream inFile(filename);
  std::ofstream outFile("logFileFloat.txt");

  // Sivkan:
  if (!inFile) {
    std::cerr << "Error opening input file: " << filename << std::endl;
    return;
  }

  // Sivkan:
  if (!outFile) {
    std::cerr << "Error opening output file: logFileFloat.txt" << std::endl;
    return;
  }

  // Katy:
  SingleLinkedList<float> list;
  std::string line, command;
  float value, value2;

  // Maggie:
  // loop through and read lines
  while (std::getline(inFile, line)) {
    std::istringstream iss(line);
    iss >> command;

    outFile << "Command: " << line << std::endl;
    // Katy: implemented try and all if/else if statements
    try {
      if (command == "pushFront") {
        iss >> value;
        list.pushFront(value);
        outFile << "Pushed " << value << " to front. List now has "
                << list.getNumItems() << " items." << std::endl;
      } else if (command == "pushBack") {
        iss >> value;
        list.pushBack(value);
        outFile << "Pushed " << value << " to back. List now has "
                << list.getNumItems() << " items." << std::endl;
      } else if (command == "popFront") {
        value = list.popFront();
        outFile << "Popped " << value << " from front. List now has "
                << list.getNumItems() << " items." << std::endl;
      } else if (command == "popBack") {
        value = list.popBack();
        outFile << "Popped " << value << " from back. List now has "
                << list.getNumItems() << " items." << std::endl;
      } else if (command == "front") {
        value = list.front();
        outFile << "Front item is: " << value << std::endl;
      } else if (command == "back") {
        value = list.back();
        outFile << "Back item is: " << value << std::endl;
      } else if (command == "empty") {
        outFile << "List is " << (list.empty() ? "empty" : "not empty")
                << std::endl;
      } else if (command == "find") {
        if (iss >> value) {
          bool found = list.find(value);
          outFile << value << " is " << (found ? "found" : "not found")
                  << " in the list." << std::endl;
        } else {
          outFile << "Error: Missing value for find command." << std::endl;
        }
      } else if (command == "remove") {
        iss >> value;
        bool removed = list.remove(value);
        outFile << value << " was " << (removed ? "removed" : "not found")
                << ". List now has " << list.getNumItems() << " items."
                << std::endl;
      } else if (command == "addBefore") {
        iss >> value >> value2;
        list.addBefore(value, value2);
        outFile << "Added " << value2 << " before " << value
                << ". List now has " << list.getNumItems() << " items."
                << std::endl;
      } else if (command == "insert") {
        size_t pos;
        iss >> pos >> value;
        list.insert(pos, value);
        outFile << "Inserted " << value << " at position " << pos
                << ". List now has " << list.getNumItems() << " items."
                << std::endl;
      } else if (command == "print") {
        outFile << "List contents: ";
        if (list.empty()) {
          outFile << "List is empty." << std::endl;
        } else {
          SingleLinkedList<float> tempList = list; // Create a copy
          while (!tempList.empty()) {
            outFile << tempList.front() << " ";
            tempList.popFront();
          }
          outFile << std::endl;
        }
      } else if (command == "quit") {
        outFile << "Quitting program." << std::endl;
        break;
      } else {
        outFile << "Unknown command: " << command << std::endl;
      }
    } catch (const std::exception &e) {
      outFile << "Error: " << e.what() << std::endl;
    }

    outFile << std::endl;
  }

  inFile.close();
  outFile.close();
}

// main function
int main() {
  // file initialize
  std::string filename;

  std::cout << "Enter the input file name: ";
  std::cin >> filename;

  // Sivkan: else/else if statements
  // determine data type based on filename
  if (filename.find("Int") != std::string::npos ||
      filename.find("int") != std::string::npos) {
    std::cout << "Processing integer commands from " << filename << std::endl;
    processIntCommands(filename);
  } else if (filename.find("Float") != std::string::npos ||
             filename.find("float") != std::string::npos) {
    std::cout << "Processing float commands from " << filename << std::endl;
    processFloatCommands(filename);
  } else {
    std::cout << "Unable to determine data type from filename. Please enter "
                 "data type (int/float): ";
    std::string dataType;
    std::cin >> dataType;

    if (dataType == "int") {
      processIntCommands(filename);
    } else if (dataType == "float") {
      processFloatCommands(filename);
    } else {
      std::cout << "Invalid data type. Please run the program again."
                << std::endl;
      return 1;
    }
  }

  std::cout << "Processing complete. Check log file for results." << std::endl;

  return 0;
}
