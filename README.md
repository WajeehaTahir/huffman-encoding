# Huffman Encoding

## Overview

This project showcases the implementation of Huffman encoding in C++ to compress and decompress text files using Huffman coding techniques. The code provided demonstrates a basic Huffman encoding and decoding process.

### File Structure

- **`fileIO.h`:** Header file containing functions to read from and write to files.
- **`Queue.h`:** Header file for the Queue data structure implementation.
- **`Tree.h`:** Header file for the Tree data structure implementation.
- **`fileIO.cpp`:** Implementation file defining file input/output functionalities.
- **`Queue.cpp`:** Implementation file for the Queue data structure.
- **`Tree.cpp`:** Implementation file for the Tree data structure.
- **`main.cpp`:** The main code file containing the Huffman encoding and decoding logic.

### Libraries Used

- `iostream`: Standard input-output library in C++.
- `string`: C++ library for string manipulation.
- Custom user-defined header files for file I/O, Queue, and Tree implementations.

## Implementation Details

The `main()` function in the `main.cpp` file represents the driver function for the Huffman encoding process. It performs the following steps:

1. Reads text data from a file named "Text".
2. Constructs a Huffman tree using the provided data.
3. Encodes the text data using the constructed Huffman tree.
4. Writes the Huffman tree and the encoded binary string to a file.
5. Reads the Huffman tree and the encoded data from the generated files.
6. Decodes the encoded data to retrieve the original text using the Huffman tree.

### Coding Logic

The implementation involves creating a Huffman tree from the given text data. This tree is then used to encode the text into binary data, followed by writing the encoded data and tree structure into separate files. Upon decoding, the original text is retrieved from the compressed binary data using the Huffman tree.

### How to Use

To use this code, follow these steps:

1. Compile the code using a C++ compiler.
2. Ensure that the text file named "Text" exists and contains the text to be encoded.
3. Run the compiled program.

---
*Documented by ChatGPT*
