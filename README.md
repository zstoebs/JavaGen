# JavaGen
An easy Javadoc notation generator

JavaGen is a fast, user-friendly command line application to generate Javadoc headers for your 
code. Currently, Java/C++ and Python headers are supported. The only dependency is the C++ STL, 
specifically iostream, string, size_t, queue, and exception.

### Prerequisites:
- Operating System
- C++ compiler
- CMake
- CPU

**Compiler Note**: g++ works fine. Clang may or may not work.

### Getting Started
Installation:
- Open terminal
- Clone this repo

```git clone https://github.com/zstoebs/JavaGen.git```

Usage:
- Open navigate to directory housing this repo on your local machine
- Run the following command to compile to an executable

```g++ -o javagen javagendriver.cpp```

- Finally, run the following command to execute

  - On Mac

  ```./javagen```

  - On Windows
  
  ```start javagen```

### Acknowledgements
At Vanderbilt University, CS2201 for teaching me C++ and CS3251 for inspiring to make this.

[GitHub URL](https://github.com/zstoebs/JavaGen.git)
