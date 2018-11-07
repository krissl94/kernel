#/bin/bash
#!/bin/bash
# Ask the user for their name
while true; do
  echo What would you like to do with leds? Type "1 1 1" to turn them all on, "0 0 0" to turn them off etc.
  read leds
  echo $leds > /sys/gpiodriver/leds

done
