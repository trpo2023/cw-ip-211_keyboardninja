# Keyboard Ninja 

Fun typing game for beginners.</br> 
Keyboard Ninja gives you easy, medium, or hard typing practice so you can improve your typing skills. </br>

**Features**:

- 3 difficulty levels: `easy`,`medium`,`hard`.
- get experience on each test completed and grow your ninja to be the best
- view yours and others best score

## Project setup

You need to install [Git][] to clone this repo, then install [CMake][] as a build system.</br>

**On Debian/Ubuntu based distributions, use the following command:**

```sh
sudo apt install git build-essential pkg-config cmake cmake-data
```

## Build instructions
```sh
# Clone this repo
git clone https://github.com/trpo2023/cw-ip-211_keyboardninja.git
cd cw-ip-211_keyboardninja

# Create a build folder
mkdir build
cd build

# Build
cmake ..
make

# Run
./geometry
```

## In one command
```sh
git clone https://github.com/trpo2023/cw-ip-211_keyboardninja.git && cd cw-ip-211_keyboardninja && mkdir build && cd build && cmake .. && make
```

[CMake]: https://cmake.org
[Git]: https://git-scm.com