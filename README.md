# JavaGen
An easy Javadoc notation generator!

JavaGen is a fast, user-friendly command line application to generate Javadoc headers for your
code. Currently, Java/C++ and Python headers are supported. The only dependency is the C++ STL,
specifically iostream, string, size_t, queue, and exception.

```
/**
 * @param <vega> this parameter maps the constellation vega
 */
```

### Prerequisites:
- Operating System
- C++ compiler
- CMake
- CPU

**Compiler Note**: Tested on g++ and clang++.

### Future Improvements:
- Support for copy paste into terminal
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

  - g++

  ```g++ -o javagen javagendriver.cpp```

  - clang++

  ```clang++ -o javagen javagendriver.cpp```

- Finally, run the following command to execute.

  - On Mac:

  ```./javagen```

  - On Windows:

  ```start javagen```

- Follow the prompts to generate your Javadoc header!

**Tags Note**: If "param" is entered as the tag name, a special branch will be triggered asking
for the parameter name. Like so:

```
Enter tag: param
What is the parameter name? vega
```

### Open Source
If you have any ideas or encounter any problems, feel free to make a pull request or contact
me directly!

**~ Zach**

### Acknowledgements
CS2201 for teaching me C++ and CS3251 for inspiring me.

[GitHub URL](https://github.com/zstoebs/JavaGen.git)
