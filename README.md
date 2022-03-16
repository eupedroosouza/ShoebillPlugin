# Shoebill Plugin

[![Build Status](http://ci.gtaun.net/app/rest/builds/buildType:(id:Shoebill_Plugin_Deploy)/statusIcon)](http://ci.gtaun.net/project.html?projectId=Shoebill_Plugin)

# Download

The newest version can always be found here (always 32-Bit):
- Windows (0.3.7): [Download](https://github.com/eupedroosouza/ShoebillPlugin/releases/download/2.0/Shoebill.dll)
- Linux (0.3.7): [Download](https://github.com/eupedroosouza/ShoebillPlugin/releases/download/2.0/Shoebill)

# What is the Shoebill Plugin?

The shoebill-plugin is the heart of the shoebill project. It is directly used by the samp-server process. Internally,
it will create a Java Virtual Machine and it will launch the shoebill-launcher artifact. The plugin will invoke
callbacks in the shoebill java side, and respond to native function calls from shoebill-launcher.

# Version supported

The shoebill plugin currently supports version 0.3.7 of SAMP

# Used dependencies

### Windows:
- [cmake](http://cmake.org) (when building version 2 cmake/cmake-gui 3.2.0-rc2 32 bits was used, always look for the latest)
- [Visual Studio](https://visualstudio.microsoft.com/) (when building version 2, 32-bit Visual Studio 2017 was used, I had problems when trying to use Visual Studio 2012 and 2019, from my own experience I advise using Visual Studio 2017.)
- [32-bit JDK 1.8 for JNI](http://en.wikipedia.org/wiki/Java_Native_Interface) (when building version 2, 32-bit JDK 1.8 was used)

### Linux
- [libiconv](https://www.gnu.org/software/libiconv/) (when building version 2 libiconv version 1.5 was used)
- [32-bit JDK 1.8 for JNI](http://en.wikipedia.org/wiki/Java_Native_Interface) (jdk has the needed files included, just install jdk if you want to build the plugin)
- [cmake](http://cmake.org) (when building version 2, the latest version of cmake was used - at the moment it was 3.5.1)

# How to build it?
### Windows:
With the components mentioned above in hand, it was enough to configure the cmake-gui for Visual Studio 2017 and generate the settings, after that it was only necessary to open the project and build it.

###  Linux
On Linux we used a 32-bit version of Ubuntu 16 running in a virtual machine on VMware Workstation Player, the components were installed as described above and after cloning this repository I just ran the build.sh file.
(You can follow the instructions in commands_linux to make your own build)