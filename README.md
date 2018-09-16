# ReBandicoot

**ReBandicoot** is the result of the reverse engineering of the **Crash Bandicoot N. Sane Trilogy**'s game engine.

The project contains a headers implementation of some engine functions and structures, thanks to which the engine can be controlled. In addition, the project contains a library that injects in the game and provides some engine control capabilities.

The project is divided into two subprojects: **Injector** and **Library**. Injector is a program for injecting a library using the blackbone library, using the manual map method, and **Library** is a library that contains the main functionality for controlling the engine.

# Goals

The main goal of this project is to increase knowledge of reverse engineering of applications with x64 architecture, and just for the sake of interest to study the structure of the engine. Crash Bandicoot is my favorite childhood game, working with it is pleasant to me so far, so I chose this engine.

# Features

At the moment the project contains only the header implementation of some engine classes. Some classes were not checked and, most likely, contain errors. In general, I'm not even sure about the correctness of their implementation, so maybe in the future they will be greatly altered.

# License

This project is licensed under the MIT License.