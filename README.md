# QMK firmware for neo65 wired PCB

## Use QMK toolbox to flash
`Fn`+`\` to ender bootloader or hold `B` when plug the board in.

Remember to clear `EEPROM` before flash.

## Or use QMK CLI to flash
`qmk compile -kb neo/neo65/ansi -km shigure -j 32`

`qmk flash -kb neo/neo65/ansi -km shigure -j 32`

## Known Issue
Coil whine when a lot of RGB LEDs are on.
