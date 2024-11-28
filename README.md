# Tic Tac Toe with TDD


## Setup

```sheel
sudo apt update
sudo apt install g++
sudo apt install cmake
cd ../Dowloads
git clone https://github.com/googletest/googletest
sudo apt install libtest-dev
cd googletests
cmake CMakeLists.txt
make
sudo cp lib/lib*.a /usr/lib
sudo cp -r googletest/include/gtest /usr/include
sudo cp -r googletest/include/gmock /usr/include
```