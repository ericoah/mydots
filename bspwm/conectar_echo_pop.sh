#!/bin/bash

MAC="28:73:F6:93:A4:5B"


bluetoothctl disconnect $MAC

sleep 5

bluetoothctl connect $MAC


