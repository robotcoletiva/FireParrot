CU-AR Drone v1.0
=================
CU-AR Drone is an extensible interface between the Parrot AR Drone and multiple input devices. This project's main goal is to create an interface between the drone and Coventry University's merlin flight simulator, and is a joint effort between members of the university's Computer Club.

Building
---------
This project uses the cmake build system (<http://www.cmake.org/>). If you have CMake installed, type `cmake .` within the root folder to generate project/make files for your platform.

Dependencies
------------
Windows:

+ XInput

Linux:

+ libudev
+ commonc++ (<http://www.hyperrealm.com/main.php?s=commoncpp>)
+ libX11

TODO
-----
+ Come up with a better project name!!!
+ Change namespaces to reflect said project name
+ Create our own drone interface api
+ Add more cool input devices :)

Thanks
-------
With thanks to Sean Middleditch (<https://github.com/elanthis>) for his gamepad library and Pongsak Suvanpong of the ARDrone forums for the temporary ardrone API.

More info
-----------
Some more information about the projects development can be found in the Wiki:
<https://github.com/PhoenixClub/CU-ARDrone/wiki>
You can also find documentation here: <http://tom.gascoigne.me/ardrone/documentation/doxygen/html/>
