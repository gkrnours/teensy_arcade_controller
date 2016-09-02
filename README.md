Arcade Controller Teensy Powered
================================

![Overview of the controller](photos/controller.jpg?raw=true)

This is the code running on a Teensy LC powering my arcade-style controller.
There is 12 buttons in all, same as on a snes controller.

Buttons are managed by a loop on a array of struct, allowing to change
the configuration easily. Bounce2 is used to provide accurate typing.

Default settings
----------------

In the current form, the code will make the controller work out of the
box with retroarch and other project based on libretro.

| Buttons | Keyboard touch | Pin |
| ------- | -------------- | --- |
| UP      | up arrow       |  0  |
| RIGHT   | right arrow    |  1  |
| DOWN    | down arrow     |  2  |
| LEFT    | left arrow     |  3  |
| A       | x              |  4  |
| B       | z              |  5  |
| X       | s              |  6  |
| Y       | a              |  7  |
| L       | q              |  8  |
| R       | w              |  9  |
| START   | return         | 10  |
| SELECT  | right shift    | 11  |


Config
------

The configuration is done in the btns array. It's a list of struct
tbutton. They take 3 values, an int for the pin, a constant from arduino
keyboard library for the keyboard key and a bounce object.
The array end with an empty struct whose char is 0.

Hooking up
----------

![A lot of electric wires](photos/wires.jpg?raw=true)

A teensy LC or 3.2 can handle up to 24 connections. I might be able to
make the computer believe there is two gamepad behind a single usb
connection while only doing simple stuff. Like in the photos.

A ground wire, the black one, go through every buttons ground tab and
back to the teensy ground. Colored wire go from each used pin to the
corresponding button. The button's pin is set have a high value. When
the button is pressed, the pin is connected to the ground and get a low
value. The code simply loop through every pin and check if the button is
pressed or not.

A more compact version of thing would use a some kind of matrix. Instead
of a common ground, button are hooked to two different pins, one
configured as an output, the other as an input. One of the output pin is
set high while all the other are set low. Looking at which input is low
and which is high can tell which of the button connected at this output.

The naive version is extra simple, making the code dead and circuit dead
simple. The matrix version require a bit more of thinking and an extra
diode per button to prevent some issue. But it would allow a lot more of
button to be connected to the same teensy. While all the 24 pins are
required for the 2 gamepad on the naive version, only 10 are needed for
the matrix one. And each extra gamepad is only two more pins. And 12
diodes.

Also, LED are diode making light.

Future work
-----------

Reusing bounce object would save a lot of byte in the tiny ram of these
teensy. Also, moving the config into a header file might help.
