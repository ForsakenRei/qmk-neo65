# QMK firmware for neo65 wired PCB

Note that this keyboard is not in the upstream qmk repo yet. Additional `WinUSB` driver from `Zadig` is necessary.

Ref: https://qwertykeys.notion.site/Neo65-Build-Guide-240f14127a97483baa6968a84751c4fa

## Use QMK toolbox to flash
`Fn`+`\` to ender bootloader or hold `B` when plug the board in.

Remember to clear `EEPROM` before flash.

## Or use QMK CLI to flash
`qmk compile -kb neo/neo65/ansi -km shigure -j 32`

`qmk flash -kb neo/neo65/ansi -km shigure -j 32`

## Known Issue
Coil whine when a lot of RGB LEDs are on.
