## STM32F401-zephyr-blink - Run your first "Hello World" in the RTOS realm

This is repository for an example about running toggling built-in LED in Blackpill board (or any STM32F401 board) using scheduler of Zephyr RTOS; perfect for everyone who wishes to learn RTOS in the beginning.

Zephyr RTOS project consists of CMAKE build file (CMakeLists.txt), boards overlay (Zephyr RTOS devs called it Devicetree), project config and the source code.

Define your project name, project source code structure all in the CMakeLists.txt
Documentation: 
 - https://docs.zephyrproject.org/latest/build/zephyr_cmake_package.html
 - https://docs.zephyrproject.org/latest/contribute/style/cmake.html

Define your need in boards/board_name.overlay, this is important to tell the compiler what you need to do about the microcontroller pins, either GPIO, ADC, communication pin, etc.
Documentation: 
  - https://docs.zephyrproject.org/latest/build/dts/howtos.html

Project config (prj.conf) is the fragment of Zephyr RTOS KConfig and it must be aligned well with board overlay.
Documentation:
  - https://docs.zephyrproject.org/latest/develop/application/index.html

Edit to add your needs in the src/main.c


## Instruction to flash
When the author created this repository, Zephyr's meta tool -- west -- is not able to flash directly using STLink device, so you need to flash the project.elf (in this repo is blink.elf) yourself with STM32CubeProg or PlatformIO flash tool after you enter the DFU mode to prevent the data loss of DFU firmware.

(C) Copyleft 2025 - aviezab

Tangerang Selatan, Indonesia