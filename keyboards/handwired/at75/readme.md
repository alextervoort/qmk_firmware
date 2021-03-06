# AT75 

![Imgur](https://i.imgur.com/SBjwVwIm.jpg)

Firmware for a handwired 5x15 ortholinear keyboard based on a XD75 plate with a cheap pro micro as controller.

MCU is a pro micro, because of the limitation in IO pins some creativity had to be used setting up the matrix.
The keyboard matrix is actually logically 10 rows and 8 columns with 2 rows physically in 1 row, odd and even positions in seperate logical rows. 

![Imgur](https://i.imgur.com/owW5ATPm.jpg)

Keyboard Maintainer: https://github.com/alextervoort  
Hardware Supported: 32u4 pro micro  (clone)
Hardware Availability: pro micro can be found for <$3, XD75 stainless plate is around $15

Make example for this keyboard (after setting up your build environment):

    make handwired/at75:default


See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
