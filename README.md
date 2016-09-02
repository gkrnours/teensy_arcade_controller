Arcade Controller Teensy Powered
================================

![Overview of the controller](photos/controller.jpg?raw=true)

This is the code running on a Teensy LC powering my arcade-style controller.
There is 12 buttons in all, same as on a snes controller.

Buttons are managed by a loop on a array of struct, allowing to change the configuration easily. Bounce2 is used to provide accurate typing.
