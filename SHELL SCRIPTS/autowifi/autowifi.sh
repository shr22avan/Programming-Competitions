#!/bin/bash
WiFi=`iwconfig 2>&1 | grep ESSID | tr -s " " | cut -d " " -f 4 | cut -d "\"" -f 2`
if [ $WiFi = "NITT-WiFi" ]
then
	echo "HI"
fi
