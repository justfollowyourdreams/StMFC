# __StMFC__ — Stereo to Mono Fast Converter.

---
![Showcase](showcase.gif)

**StMFC** is a free software that helps you to convert your stereo WAV-files to mono in purpose of saving memory.

Firstly it is utility for Ableton Live users, but **it can be used by everyone!**
I've made it just because Ableton Live has no ability to freeze and flatten to mono which is annoying for me.
Especially when I freeze my tuned vocals.

This little utility allows you to save _50%_ of your memory just because you'll store one channel on your drive instead of two.

## Get started 🚀
To get started, download the latest setup from [GitHub Releases](https://github.com/justfollowyourdreams/StMFC/releases). Than install it and use.

To convert a file, just drop it into the utility's window *(works from Live's browser also)*, and then you'll get a file called **[OriginalName]_mono.wav**.
Then just replace an old audio with new one.
*PROGRAM DOES NOT REMOVE ORIGINAL FILES! YOU HAVE TO DELETE IT MANUALLY!*

macOS build provided was built on **x86_64 Intel Macbook**. AFAIK it could be run on M-chips Macs.

## Build 🛠️
For building from source, you need:
- C and C++ compilers (I used [MinGW-w64](https://winlibs.com/)),
- [CMake](https://cmake.org/) build system,
- [Conan](https://conan.io/) package manager.

Install and prepare all of these and then follow the instruction:

0. Prepare compiler and Conan *(you might need to run `conan profile detect`)*.
1. Clone repo: `git clone --recursive https://github.com/justfollowyourdreams/StMFC.git`.
2. Go to the project directory: `cd ./StMFC`.
3. Install Conan in project: `conan install . -b=missing -sbuild_type=Release`.
4. Run CMake: `cmake --preset conan-release`.
5. Build the program: `cmake --build ./build/Release`.

Done! Built executable is located in **./build/Release/bin** directory.
