# bannerlogo for AgonLight
[![Build Status](https://github.com/coffeemuse/bannerlogo/actions/workflows/main.yml/badge.svg)](https://github.com/coffeemuse/bannerlogo/actions)

This project is a C-based reimplementation inspired by the original [bootlogo](https://github.com/sijnstra/agon-projects/tree/main/bootlogo), written in z80 assembly by Shawn Sinjnstra. While not a direct port, it recreates core functionality using similar logic and structure. The original work is licensed under the MIT License, which this project continues to honor.

Initially this project was just a quick playground to test the new [agondev C/C++ Toolchain](https://github.com/AgonPlatform/agondev). Instead of a boring Hello World, I produced this as a learning project.

# Screenshot

![Screenshot of bannerlogo running in Fab Agon Emulator](./assets/BannerLogo-Screenshot.png)

# Build Instructions

To build this project, you need the [agondev C/C++ Toolchain](https://github.com/AgonPlatform/agondev) installed and available in your `PATH`.

1. Clone this repository:
    ```sh
    git clone https://github.com/coffeemuse/bannerlogo.git
    cd bannerlogo
    ```

2. Build the project using `make`:
    ```sh
    make
    ```

This will produce the `bannerlogo` binary in the `./bin` project subdirectory.

To run the program, copy the binary to your AgonLight system or use an emulator such as [Fab Agon Emulator](https://github.com/fabgl/fab-agon-emulator).

