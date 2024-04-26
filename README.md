# CMake_Core

This CMake template enables the setup of C++ projects. Please bear in mind that while this project isn't flawless, it's designed to help new programmers establish C++ projects swiftly and effectively. We plan to periodically enhance its features, so stay tuned for updates. We hope you find it valuable!

<br>
<br>

## Getting Started

Follow these instructions to set up a C++ project using this template.

<br>

### Prerequisites

Ensure that you have the following set of tools installed on your personal machine:

```diff
CMake (version 3.27.0)
C++ Compiler (e.g., g++, clang++, MSVC)
```

<br>

### Usage

In the 'source' directory, please make sure the following set of external party libraries are downloaded and placed into their respective folders before attempting to generate the project:
```diff
Boost      # Must be placed under "CMake_Core/source/lib/Boost".
wxWidgets  # Must be placed under "CMake_Core/source/lib/wxWidgets".
Curl       # Must be placed under "CMake_Core/source/lib/Curl".
```

<br>

You are now prepared to configure and build your project using CMake. Please make sure to open the terminal and navigate to the folder path of "CMake_Core/build". You can now copy the appropriate commands in the "Instructions.txt" file and execute them to start generating and working on your project. Something changed.
