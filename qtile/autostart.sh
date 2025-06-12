 #! /bin/sh

 # Autostart
 setxkbmap -layout us -variant intl &
 compton --backend glx --vsync opengl-swc &
 nitrogen --restore &
 xsetroot -cursor_name left_ptr &
 nm-applet &
 blueman-applet &
 flameshot &

