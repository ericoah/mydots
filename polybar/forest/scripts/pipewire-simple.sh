#!/bin/sh

getDefaultSink() {
    defaultSink=$(pactl info | awk -F : '/Fonte padrão:/{print $2}')
    description=$(pactl list sinks | sed -n "/${defaultSink}/,/Descrição/s/^\s*Descrição\(.*\)/\1/p")
    echo "${description}"
}

getDefaultSource() {
    defaultSource=$(pactl info | awk -F : '/Fonte padrão:/{print $2}')
    description=$(pactl list sources | sed -n "/${defaultSource}/,/Descrição/s/^\s*Descrição\(.*\)/\1/p")
    echo "${description}"
}

VOLUME=$(pamixer --get-volume-human)
SINK=$(getDefaultSink)
SOURCE=$(getDefaultSource)

case $1 in
    "--up")
        pamixer --increase 10
        ;;
    "--down")
        pamixer --decrease 10
        ;;
    "--mute")
        pamixer --toggle-mute
        ;;
    *)
        echo "Vol: ${VOLUME}"
esac
