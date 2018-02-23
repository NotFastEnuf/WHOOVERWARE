[![Build Status](https://travis-ci.org/silver13/BoldClash-BWHOOP-B-03.svg?branch=master)](https://travis-ci.org/silver13/BoldClash-BWHOOP-B-03)

## NotFastEnuf Notes - Bwhoop B03 Silverware modified FOR TINY WHOOVERS to work on BWHOOP, E011, H8mini_blue_board, or BetaFPV Lite.
Last major update 2.23.18

##  CURRENT WHOOVER CONFIGURATION IS THROTTLE AND YAW MAPPED TO PUSH MOTORS - PITCH STICK IS MAPPED TO LIFT MOTORS AS A THROTTLE - WHOOVER ARMS/HOVERS UP ON AUX CHANNEL 5.

##  LOTS OF WORK STILL NEEDS TO BE DONE TO CLEAN UP CONFIG.H & README NOTES TO MAKE IT MORE TAYLORED TO TINY WHOOVERS - BUT THIS IS CURRENTLY TUNED, TESTED, AND WORKING FIRMWARE!!!!!!!!!

OLD nfe SILVERWARE NOTES BELOW - TO BE CLEANED UP LATER - SOME OF THIS STILL APPLIES LIKE BOARD TYPE, RADIO TYPE, AND LOW VOLTAGE SETTINGS.  EVERYTHING ELSE SHOULD RUN FINE AS IS FOR WHOOVING
Testing a new layout for config.h  - feel free to let me know what you think.  Your feedback is appreciated. 

There are two main steps to prep this file for flash.  The first will be in config.h and the second will be in pid.c file.

STEP 1:  Open config.h with keil and make edits to set your selections in 6 categories.

         _Hardware Selection_ - select bwhoop, e011, or H8mini_blue_board based hardware
         
         _Receiver Settings_ - set rates, expo, radio protocol, transmitter type and assign features to auxiliary channel switches
                              
         _Voltage Settings_ - low voltage cutoff and other voltage related settings
         
         _Filter Settings_ -set gyro filter and D term filter frequencies and orders
         
         _Motor Output Settings_ - set pwm rate, motor curves, inverted yaw for props out, and features related to motor output
                                 
         _Additional Features_ - remaining special features 
         
STEP 2:  Open pid.c with keil and either edit pids to your preferred values or select a set of pids that I have prepared.   I plan to keep all my tunes in pid.c and will have them labeled and noted with the associated filter settings for each type of build.  All you have to do to use one of my tunes is uncomment the pid group you want to use and make sure the others are commented out.  I will keep whatever pids I'm using updated here if I change them and the default set will always be for a 7mm whoop with fpv gear installed.  Setpoint weight values are also just below pids - if you want a sharper stick feel on one of my tunes then change these values closer to 1.0

## Current Experimental Features 

 - E011 or Bwhoop Selection:  define your board type and hardware settings are automatically selected for E011, Bwhoop, bwhoop pro, E011c,  and beta fpv lite
 - Radio Type Selection:  Renamed aux channels as chan_5 through chan_10 and proper mapping is now controlled by defining your transmitter type.  Simply select devo, multi (for taranis or other multimodule), or stock (for toy tx) and assign the features you want to chan_#
 - Racemode:  flight mode with leveling on roll, acro on pitch, and yaw axis rotates about gravity vector.  Can be activated on an aux channel when in level mode.
 - Racemode Horizon: same as above with horizon on roll.
 - Horizon: leveling when upright, will flip or roll.
 - Kalman Gyro Filter:  adjustable gyro filter that's very similar to a 1st order filter but to me feels a little faster and a little weaker.  You decide...
 - Kalman Motor Filter:  adjustable motor output filter.  Same evaluation as the gyro version.
 - Idle up/Arming on aux channel:  idle speed is also adjustable.  Paired with mix increase throttle feature it behaves like airmode
 - Sticks Deadband:  adjustable deadband for transmitter inputs to compensate for gimbals that don't perfectly center
 - Motor Filter Frequencies:  motor filters are adjustable by a frequency instead of a decimal value.


_Easiest way to find me for feedback & discussion is here https://community.micro-motor-warehouse.com/t/notfastenuf-e011-bwhoop-silverware-fork/5501?u=notfastenuf_

_end NFE notes_

## SilverWare - BoldClash BWHOOP B-03 version

_Also works with B03 Pro_

Currently does not account for centered throttle! ( no altitude hold ) It uses normal throttle, low = motors off. That means it should be used with Devo / multimodule or another tx.

Programming connector is a Microjst 1.25 pitch connector. Don't wire positive to st-link as you may overcharge the battery if connected or damage the st-link.

Programming instructions ( uses St-link Utility program ):
https://www.rcgroups.com/forums/showthread.php?2876797-Boldclash-bwhoop-B-03-opensource-firmware

Compiling instructions ( uses Keil uVision IDE):
https://www.rcgroups.com/forums/showthread.php?2877480-Compilation-instructions-for-silverware#post37391059

### Level / acro mode change
By default "gestures" are used to change modes, move the stick *left-left-down* for acro mode , and *right-right-down* for level mode.

### Pid gestures and save
Pid gestures allow the pilot to change the acro mode pids by a percentage, and such tune the quadcopter without a computer. The new pids can be saved so that they will be restored after the quad is power cycled.The new pids will remain active if saved, until the pid values in file pid.c are changed. If the values are not changed, flashing the quad will not erase the pids unless the erase command is manually issued when programming.

*See also*
http://sirdomsen.diskstation.me/dokuwiki/doku.php?id=pidgesture

### Accel calibration / pid save
The gesture for accel calibration is down - down - down. If pids have been changed using the respective gestures since the last powerup or save, the pids will be saved instead.

### Telemetry
DeviationTx and multimodule+taranis can support telemetry, this requires no changes from the defaults on the quad. For devo, when selecting the Bayang protocol, hit Enter to see options, and enable telemetry there. Telemetry currently contains received number of data and telemetry packets, and 2 voltages, battery raw voltage and compensated voltage ( against voltage drop )

For multimodule, you need to add telemetry ( as an option ) to the bayang protocol in the protocol table ( configuration file ). Note the telemetry protocol won't work with stock quads.

*See also*
http://sirdomsen.diskstation.me/dokuwiki/doku.php?id=telemetry

### Android App telemetry
The Android app "SilverVISE" by SilverAG (not me) is able to receive telemetry from the quad using BLE packets. To use, the app protocol should be set in the quadcopter. The app will also show the pids.

*More information*
http://sirdomsen.diskstation.me/dokuwiki/doku.php?id=silvervise

### Linux/gcc version
The gcc version compiles close to 16k, and may need turning off features in order to make it fit. It's also possible to flash up to 32K with changes. Read __install.md__ for additional information. 

The boldclash settings may need changes to work with gcc well. Turn off the software lpf filters except the last 2, the loop time is longer, at 1400, which affects the frequency of other soft lpf filters. You could set loop time to 1500 but it may not be needed.

### Wiki
http://sirdomsen.diskstation.me/dokuwiki/doku.php?id=start

### 01.18
* 2 new D term filters, 1st and 2nd order with custom frequency
* improved led flash timing
* the throttle smooth feature is gone 
* nrf24 support added, bayang protocol + telemetry
* softi2c support for 1 pullup only ( e011 )

### 29.08.17
* moved flash save to 31k
* added 2 looptime independent soft lpf
* added lowerthrottlemix3 from h8
* added motor filter 2 replacing original,much better performance
* pid save has own led flash now
* cleanup of unused features: headless and some other


### xx.06.17
* pid gestures - pids can be changed by gestures at the field
* pid save - new pids are saved to flash by the d-d-d gesture

### 02.05.17
* level pid is tuned more aggressive
* added filter between level pid and  acro pid
* fixed issue where "Overclock" option broke level mode (i2c) - overclock can be used on the bwhoop now
* removed level mode I term - this was not usually used
* minor cleanup and efficiency
* GCC autovdrop now functional
* LVC throttle lowering disabled by default just in case it malfunctions

### initial changes

* autovdrop improved, and better compensation
* new measured motor curve at 24K pwm
* added a new way of lowering throttle below a certain voltage
* lvc now flashes below an "uncompensated" voltage, too, just in case
