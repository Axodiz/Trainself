# TRAINSELF

## Introduction

TRAINSELF is Open-Source, multi-platform application for creating physical 
exercises and training programs with the ability to add user data.

TRAINSELF is written on C++17, using utilities likes:
- Graphics: OpenGL, GLFW, GLAD
- UI: Dear ImGui
- Make: Cmake

## Requirement

TRAINSELF requires **windows** or **linux** os and also:
- CMake >= 3.15
- C++17 Compiler
- Git

## Quick start

1. Clone repository with submodules:
```
git clone --recursive https://github.com/Axodiz/Trainself.git
cd Trainself
```

**If you forget --recursive:**
```
git submodule update --init --recursive
```

2. Build:
``` 
mkdir build && cd build
cmake ..
cmake --build .
```

## License

TRAINSELF uses **MIT** License.

## Contacts

To contact with me write on email **axodizmic@gmail.com**
