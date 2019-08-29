# JavaGen
An easy Javadoc notation generator!

JavaGen is a fast, user-friendly command line application to generate Javadoc headers for your 
code. Currently, Java/C++ and Python headers are supported. The only dependency is the C++ STL, 
specifically iostream, string, size_t, queue, and exception.

### Prerequisites:
- Operating System
- C++ compiler
- CMake
- CPU

**Compiler Note**: g++ works fine. Clang may or may not work.

### Future Improvements:
- Make it a web app
- Make it an iOS/Android app

## Getting Started
**Installation**:
- Open the terminal.
- Clone this repo.

```git clone https://github.com/zstoebs/JavaGen.git```

**Usage**:
- Navigate to directory housing this repo on your local machine on the terminal.
- Run the following command to compile to an executable.

```g++ -o javagen javagendriver.cpp```

- Finally, run the following command to execute.

  - On Mac:

  ```./javagen```

  - On Windows:
  
  ```start javagen```

### Acknowledgements
CS2201 for teaching me C++ and CS3251 for inspiring me.

[GitHub URL](https://github.com/zstoebs/JavaGen.git)
