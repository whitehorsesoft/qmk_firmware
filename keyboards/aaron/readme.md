Forked from https://github.com/qmk/qmk_firmware, merged with https://github.com/Cyboard-DigitalTailor/qmk_firmware/tree/cyboard_usb_c, merged with https://github.com/Cyboard-DigitalTailor/vial-qmk/tree/rigid-flex-matrix, with my custom layout and hold logic added.

Work in progress, need to clean up and add better attribution.

# aaron

![aaron](imgur.com image replace me!)

*A short description of the keyboard/project*

* Keyboard Maintainer: [aaron](https://github.com/aaron)
* Hardware Supported: *The PCBs, controllers supported*
* Hardware Availability: *Links to where you can find this hardware*

Make example for this keyboard (after setting up your build environment):

    make aaron:default

Flashing example for this keyboard:

    make aaron:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
