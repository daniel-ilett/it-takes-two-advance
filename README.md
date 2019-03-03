# It Takes Two (Advance)
A port/demake of It Takes Two for the Game Boy Advance. No, seriously.

## Overview

The gameplay of It Takes Two isn't exactly taxing, making it a perfect fit for the newest Nintendo console - the Gameboy Advance! This backport/demake will incorporate most of the gameplay of It Takes Two in a smaller form factor. Maybe I'll even fix the recipes. Then again, maybe not.

The 1.0 release will target the latest version of VisualBoyAdvance-M (1.8.0.0). From there, I may try to get the game flashed on a physical GBA cart.

## Software

+ [A very old version of GCC](https://web.archive.org/web/20090123170129/http://webbesen.dk:80/gba/default.asp) with a GBA toolchain;
+ Sublime Text 3;
+ GIMP (I know, it saddens me too);
+ Pyxel Edit.

## Authors

Created and developed by [Daniel Ilett](https://github.com/daniel-ilett).

## Installation

The toolchain I'm using is very janky and resisted my attempts to make it play nice. I have [the devkit](https://web.archive.org/web/20090123170129/http://webbesen.dk:80/gba/default.asp) installed in my root directory, with the project contained inside `/devkitadv/projects/it-takes-two-advance`. You'll likely have to modify `make.bat` to point to the right places or rename files to whatever you'd like. Alternatively, you can set up a Makefile (both approaches are abject evil, so good luck).

Or be sensible and wait for me to throw up a working `itt-adv.bin` file!

## Release

It Takes Two (Advance) was released [on itch.io](https://danielilett.itch.io/it-takes-two-advance) on January 31st 2019.

## License
Feel free to play around with the source code for personal use, but please give the author credit and don't distribute this commercially.
