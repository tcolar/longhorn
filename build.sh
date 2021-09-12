#!/bin/sh

export PATH=$PATH:/home/tcolar/.local/bin

cp -rf qmk_firmware/keyboards/handwired/longhorn/  ~/qmk_firmware/keyboards/handwired/
qmk compile -kb handwired/longhorn -km default