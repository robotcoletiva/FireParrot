CU-AR Drone
============
CU-AR Drone is an extensible interface between the Parrot AR Drone and multiple input devices. This project's main goal is to create an interface between the drone and Coventry University's merlin flight simulator, and is a joint effort between members of the university's Computer Club.

Current implementation thoughts
--------------------------------
Summarised here are the current thoughts on implementation. Class diagrams will be completed at a later date.

Input:
The framework will provide a generalised interface that input devices will implement. This allows the system to gather basic input information such as current movement direction/speed. It will then feed this information to the output module, and in turn to the drone. The system will also provide a mechanism that feeds back video output, gyroscope output etc.

Output:
We will write a high level wrapper around the api which makes it easy for us to control the drone. This provides basic movement control for rotation, height adjustment, and movement.

Things to do
-------------
+ Find out more information about the interface between the machine and the flight simulator's hardware, particularly hydraulics.
+ Meet up to design class diagrams describing the framework
+ Get to grips with the AR-Drone's API (<https://projects.ardrone.org>)
