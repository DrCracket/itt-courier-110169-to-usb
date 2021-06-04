#  ITT Courier 110169 Keyboard USB Conversion

This firmware can be used to convert an [ITT Courier
110169](https://www.youtube.com/watch?v=37tdDoC7rGA) keyboard to USB. It makes
use of the [tmk_core](https://github.com/tmk/tmk_core) keyboard firmware
library and was written with the [Teensy
2.0](https://www.pjrc.com/store/teensy.html) development board in mind, because
with it you only need to make minor modifications to the PCB. The project only
contains instructions on how to perform the necessary modifications and get
everything up and running. For information on how I reverse engineered that
thing look [here](https://deskthority.net/viewtopic.php?f=7&t=24822).

## Wiring

The first thing you have to do is to desolder the original
[8048](https://en.wikipedia.org/wiki/Intel_MCS-48) microcontroller. Then you
have to connect the Teensy to hole 9 - 32 on the PCB:
```
+-------\/-------+
[] 1         40 []
[] 2         39 []
[] 3         38 []
[] 4         37 []
[] 5         36 []
[] 6         35 []                              +-----+              
[] 7         34 []                +-------------|     |-------------+
[] 8         33 []                |             | USB |             |
[] 9         32 []   <---------   |[] GND       |     |       VCC []|
[] 10  8048  31 []                |[] PB0       +-----+       PF0 []|
[] 11 Socket 30 []                |[] PB1        ==     ||    PF1 []|
[] 12        29 []                |[] PB2               ||    PF4 []|
[] 13        28 []                |[] PB3 [] E6            [] PF5 []|
[] 14        27 []                |[] PB7      +-------+      PF6 []|
[] 15        26 []                |[] PD0      |       |      PF7 []|
[] 16        25 []                |[] PD1      |       |      PB6 []|
[] 17        24 []                |[] PD2      +-------+      PB5 []|
[] 18        23 []                |[] PD3    +-+  /–\   ||    PB4 []|
[] 19        22 []                |[] PC6    +-+  \-/   ||    PD7 []|
[] 20        21 []   <---------   |[] PC7 [ ] [ ] [ ] [ ] [ ] PD6 []|
+----------------+                |       PD5 VCC GND RST PD4       |
                                  +---------------------------------+
```
After that take a look at the bottom side of the PCB, where the microcontroller
sits. Here you have to do a few things:
- Sever the connection between pin 10 and 26
- Bridge pins 7 and 8
- Connect pins 26 and 32
- Connect pins 27 and 35

It should look somewhat like this:
```
      Before:                           After:
                               
   +-----\/-----+                   +-----\/-----+
40 []          []  1           40   []          []  1
39 []          []  2           39   []          []  2
38 []          []  3           38   []          []  3
37 []          []  4           37   []          []  4
36 []          []  5           36   []          []  5
35 []          []  6           35  +[]          []  6
34 []          []  7           34 / []         +[]  7
33 []         +[]  8           33 | []         +[]  8
32 []         +[]  9           32 | []+        +[]  9
31 []       --+[] 10           31 | [] \     --+[] 10
30 []      /   [] 11           30 | [] |    /   [] 11
29 []     /    [] 12           29 | [] |        [] 12
28 []    /     [] 13           28 \ [] |        [] 13
27 []   /      [] 14           27  +[] / /      [] 14
26 []+--       [] 15           26   []+--       [] 15
25 []+         [] 16           25   []+         [] 16
24 []          [] 17           24   []          [] 17
23 []          [] 18           23   []          [] 18
22 []          [] 19           22   []          [] 19
21 []          [] 20           21   []          [] 20
   +------------+                   +------------+   

```
Now you have to connect the Teensy to an USB cable. Theoretically you could
directly connect a cable to the Teensy, but a cleaner way would be to repurpose
the connector the original cable used and build a custom USB cable. For that
you have to connect the Data - and Data + pins of the Teensy USB connector to
pin 3 and 4 of the connector on the PCB:

```
  |  |  |  |  |  |
+-|--|--|--|--|--|-+
|                  |
+------------------+
 +5v  Data-  GND
    +5v  Data+  GND
```
If you want to, you can remove some components, that aren't needed anymore. You
can safely remove the 6.0Mhz crystal (Y1), the two DM7417N Buffers (IC6 & IC7),
the SN74LS74AN Flip-Flop (IC2) and the LM3905N timer (IC8).

## Build Instructions
Clone the repository with the following command:
```sh
git clone --recurse-submodules https://github.com/potamides/itt-courier-110169-to-usb
```
To build the firmware and program the controller run this command:
```sh
make teensy [KEYMAP=yourname]
```
You can select a keymap name with the optional `KEYMAP=` parameter ('plain' is
the default name). See
[tmk_core/doc/build.md](https://github.com/tmk/tmk_core/blob/master/doc/build.md)
for more information.

You can change the keymap by editing the code of `keymap_plain.c` directly, or
by copying it to your own keymap file like `keymap_yourname.c` and editing it
from there. How to define a keymap should be pretty straightforward. You can
find key symbols in
[tmk_core/doc/keycode.txt](https://github.com/tmk/tmk_core/blob/master/doc/keycode.txt).
Look at
[tmk_core/doc/keymap.md](https://github.com/tmk/tmk_core/blob/master/doc/keymap.md)
for more details.
