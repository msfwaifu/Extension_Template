Ayrias Extension Template
---

This repository serves as a starting-point for new developers and includes:

* A general directory structure to make your extension easy to read for other developers.
* An introduction to the eventdriven extension-interface as shown in /DllMain.cpp
* A platform to let you inject your existing code and have it integrated with the system in minutes.
* A basic library of utilities that is constantly being updated to give you the tools you need.


Extensionloading
--
While you can inject your new extension into an application and have it run, the easiest way would be to use the Bootstrap module from Ayria (https://github.com/AyriaPublic/NativeBootstrap).
Once injected, this module will attempt to load all extensions from ./Plugins/ and call the initialization exports as needed.
As such, if you are creating an extension for an existing system, simply drop it into your ./Plugins/ directory.
