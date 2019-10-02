# Alternative Controller for ITT Courier 110169

This firmware can be used to convert an ITT Courier 110169 keyboard to USB. 
It was written with the [Teensy 2.0](https://www.pjrc.com/store/teensy.html) microcontroller in mind,
because with it you only need to make minor modifications to the PCB.
This project makes use of the [tmk_core](https://github.com/tmk/tmk_core) keyboard firmware library.

## Wiring

The first thing you have to do is to desolder the original [8048](https://en.wikipedia.org/wiki/Intel_MCS-48) microcontroller.
Then you have to connect the Teensy to hole 9 - 32 on the PCB:

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
After that take a look at the bottom side of the PCB, where the microcontroller sits. Here you have to do a few things:
- Sever the connection between pin 10 and 26
- Bridge pins 8 and 9
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
Now you have to connect the Teensy to an USB cable. Theoretically you could directly connect a cable to the Teensy, but a cleaner way would be to repurpose the connector the original cable used and build a custom USB cable. For that you have to connect the Data - and Data + pins of the Teensy USB connector to pin 3 and 4 of the connector on the PCB:

```
  |  |  |  |  |  |
+-|--|--|--|--|--|-+
|                  |
+------------------+
 +5v  Data-  GND
    +5v  Data+  GND
```


## Build Instructions
Clone the repository with the following command:
```sh
git clone --recurse-submodules git@github.com:DrCracket/itt-courier-110169-to-usb.git
```
See [tmk_core/doc/build.md](tmk_core/doc/build.md).

To build the firmware and program the controller run this command:
```sh
make teensy [KEYMAP=yourname]
```

You can select a keymap name with optional `KEYMAP=` ('plain' is the default name).

You can change keymap by editing code of `keymap_plain.c` directly, or copy it to your own keymap file like `keymap_yourname.c` and edit the file.
How to define the keymap is probably obvious. You can find key symbols in [tmk_core/doc/keycode.txt](tmk_core/doc/keycode.txt). See [tmk_core/doc/keymap.md](tmk_core/doc/keymap.md) for more detail.
