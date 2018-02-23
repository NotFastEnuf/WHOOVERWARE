#include "defines.h"
#include "hardware.h"

// adjust pids in pid.c file

//**********************************************************************************************************************
//***********************************************HARDWARE SELECTION*****************************************************

// *************DEFINE FLIGHT CONTROLLER HARDWARE
// *************SELECT ONLY ONE 
// *************uncomment BWHOOP define for bwhoop, bwhoop pro, E011C Santa Edition, and Beta FPV Lite Flight Controllers
// *************uncomment E011 define for E011 flight Controller
// *************uncomment H8mini_blue_board for the H8 mini flight controller with blue circuit board
//#define BWHOOP
#define E011
//#define H8mini_blue_board


//**********************************************************************************************************************
//***********************************************RECEIVER SETTINGS******************************************************

// *************rate in deg/sec
// *************for acro mode
#define MAX_RATE 860.0
#define MAX_RATEYAW 500.0

// *************max angle for level mode
#define MAX_ANGLE_HI 70.0f

// ************* low rates multiplier if rates are assigned to a channel
#define LOW_RATES_MULTI 0.5f

// *************EXPO from 0.00 to 1.00 , 0 = no exp
// *************positive = less sensitive near center 
#define EXPO_XY 0.8
#define EXPO_YAW 0.6

// *************transmitter stick adjustable deadband for roll/pitch/yaw
// *************.01f = 1% of stick range - comment out to disable
#define STICKS_DEADBAND .01f

// *************Radio protocol selection
// *************select only one
//#define RX_CG023_PROTOCOL
//#define RX_H7_PROTOCOL
//#define RX_BAYANG_PROTOCOL
#define RX_BAYANG_PROTOCOL_TELEMETRY
//#define RX_BAYANG_PROTOCOL_BLE_BEACON
//#define RX_BAYANG_BLE_APP
//#define RX_CX10BLUE_PROTOCOL
//#define RX_SBUS

// *************Transmitter Type Selection
//#define USE_STOCK_TX
#define USE_DEVO
//#define USE_MULTI

// *******************************SWITCH SELECTION*****************************
// *************CHAN_ON - on always ( all protocols)
// *************CHAN_OFF - off always ( all protocols)
// *************Aux channels are selectable as CHAN_5 through CHAN_10 for DEVO and MULTIMODULE users
// *************Toy transmitter mapping is CHAN_5 (rates button), CHAN_6 (stick gestures RRD/LLD), 
//**************CHAN_7 (headfree button), CHAN_8 (roll trim buttons), CHAN_9 (pitch trim buttons)

//*************Idle up-Arm switch
//*************comment out to disable
#define IDLE_UP CHAN_5
#define IDLE_THR 0.05f

//*************Assign feature to auxiliary channel.  NOTE - Switching on LEVELMODE is required for any leveling modes to 
//*************be active.  With LEVELMODE active - MCU will apply RACEMODE if racemode channel is on, HORIZON if horizon 
//*************channel is on, or racemodeHORIZON if both channels are on - and will be standard LEVELMODE if neither 
//*************racemode or horizon are switched on.
#define LEVELMODE CHAN_6
	#define RACEMODE  CHAN_OFF
	#define HORIZON   CHAN_OFF
#define RATES CHAN_ON
#define LEDS_ON CHAN_ON

// *************switch for fpv / other, requires fet
// *************comment out to disable
//#define FPV_ON CHAN_ON

// *************start in level mode for toy tx.
//#define AUX1_START_ON

// *************automatically remove center bias in toy tx ( needs throttle off for 1 second )
//#define STOCK_TX_AUTOCENTER



//**********************************************************************************************************************
//***********************************************VOLTAGE SETTINGS*******************************************************

// *************battery saver
// *************do not start software if battery is too low
// *************flashes 2 times repeatedly at startup
//#define STOP_LOWBATTERY

// *************voltage to start warning
#define VBATTLOW 3.5

// *************compensation for battery voltage vs throttle drop
#define VDROP_FACTOR 0.7
// *************calculate above factor automatically
#define AUTO_VDROP_FACTOR

// *************voltage hysteresys in volts
#define HYST 0.10

// *************lower throttle when battery below treshold - forced landing low voltage cutoff
//#define LVC_LOWER_THROTTLE
#define LVC_LOWER_THROTTLE_VOLTAGE 3.30
#define LVC_LOWER_THROTTLE_VOLTAGE_RAW 2.70
#define LVC_LOWER_THROTTLE_KP 3.0




//**********************************************************************************************************************
//***********************************************FILTER SETTINGS********************************************************

// *************gyro low pass filter ( iir )
// *************set only one below - kalman, 1st order, or second order - and adjust frequency
//**************ABOVE 100 ADJUST IN INCRIMENTS OF 20, BELOW 100 ADJUST IN INCRIMENTS OF 10
#define SOFT_KALMAN_GYRO KAL1_HZ_90
//#define SOFT_LPF_1ST_HZ 80
//#define SOFT_LPF_2ND_HZ 80


// *************D term low pass filter type - set only one below and adjust frequency if adjustable filter is used
// *************1st order adjustable, second order adjustable, or 3rd order fixed (non adjustable)
//#define DTERM_LPF_1ST_HZ 100
#define  DTERM_LPF_2ND_HZ 100
//#define DTERM_LPF3_88

//**********************************************************************************************************************
//***********************************************MOTOR OUTPUT SETTINGS**************************************************

// *************enable motor output filter - select and adjust frequency
#define MOTOR_FILTER2_ALPHA MFILT1_HZ_90
//#define MOTOR_KAL KAL1_HZ_70

// *************pwm frequency for motor control
// *************a higher frequency makes the motors more linear
// *************in Hz
#define PWMFREQ 32000

// *************motor curve to use - select one
// *************the pwm frequency has to be set independently
#define MOTOR_CURVE_NONE
//#define MOTOR_CURVE_6MM_490HZ
//#define MOTOR_CURVE_85MM_8KHZ
//#define MOTOR_CURVE_85MM_32KHZ
//#define BOLDCLASH_716MM_8K
//#define BOLDCLASH_716MM_24K

// *************clip feedforward attempts to resolve issues that occur near full throttle
//#define CLIP_FF

// *************torque boost is a highly eperimental feature.  it is a lpf D term on motor outputs that will accelerate the response
// *************of the motors when the command to the motors is changing by increasing or decreasing the voltage thats sent.  It differs
// *************from throttle transient compensation in that it acts on all motor commands - not just throttle changes.  this feature
// *************is very noise sensative so D term specifically has to be lowered and gyro/d filtering may need to be increased.
// *************reccomendation right now is to leave boost at or below 2, drop your p gains a few points, then cut your D in half and 
// *************retune it back up to where it feels good.  I'm finding about 60 to 65% of my previous D value seems to work.
#define TORQUE_BOOST 8.0

// *************makes throttle feel more poppy - can intensify small throttle imbalances visible in FPV if factor is set too high
#define THROTTLE_TRANSIENT_COMPENSATION 
#define THROTTLE_TRANSIENT_COMPENSATION_FACTOR 4.0 
 
// *************throttle angle compensation in level mode
//#define AUTO_THROTTLE

// *************mix lower throttle reduces thrust imbalances by reducing throttle proportionally to the adjustable reduction percent
// *************mix increase throttle increases the authority of the pid controller at lowest throttle values like airmode when combined with idle up
// *************mix3 has a stronger effect and works better with brushless
//#define MIX_LOWER_THROTTLE
#define MIX_THROTTLE_REDUCTION_PERCENT 10
//#define MIX_INCREASE_THROTTLE

//#define MIX_LOWER_THROTTLE_3
//#define MIX_INCREASE_THROTTLE_3

// *************invert yaw pid for "PROPS OUT" configuration
//#define INVERT_YAW_PID



//**********************************************************************************************************************
//***********************************************ADDITIONAL FEATURES****************************************************

// *************lost quad beeps using motors (30 sec timeout)
//#define MOTOR_BEEPS

// *************0 - 7 - power for telemetry
#define TX_POWER 7

// *************Flash saving features
//#define DISABLE_GESTURES2

// *************led brightness in-flight ( solid lights only)
// *************0- 15 range
#define LED_BRIGHTNESS 15

// *************external buzzer - pins in hardware.h
//#define BUZZER_ENABLE

// *************Comment out to disable pid tuning gestures
#define PID_GESTURE_TUNING
#define COMBINE_PITCH_ROLL_PID_TUNING

// *************flash save method
// *************flash_save 1: pids + accel calibration
// *************flash_save 2: accel calibration to option bytes
#define FLASH_SAVE1
//#define FLASH_SAVE2


// enable inverted flight code ( brushless only )
//#define INVERTED_ENABLE
//#define FN_INVERTED CH_OFF //for brushless only







//#############################################################################################################################
//#############################################################################################################################
// debug / other things
// this should not be usually changed
//#############################################################################################################################
//#############################################################################################################################

// Gyro LPF filter frequency
// gyro filter 0 = 250hz delay 0.97mS
// gyro filter 1 = 184hz delay 2.9mS
// gyro filter 2 = 92hz delay 3.9mS
// gyro filter 3 = 41hz delay 5.9mS (Default)
// gyro filter 4 = 20hz
// gyro filter 5 = 10hz
// gyro filter 6 = 5hz
// gyro filter 7 = 3600hz delay 0.17mS
#define GYRO_LOW_PASS_FILTER 0

// disable inbuilt expo functions
//#define DISABLE_EXPO

#define DISABLE_FLIP_SEQUENCER
#define STARTFLIP CHAN_OFF

// level mode "manual" trims ( in degrees)
// pitch positive forward
// roll positive right
#define TRIM_PITCH 0.0
#define TRIM_ROLL 0.0

// disable motors for testing
//#define NOMOTORS

// throttle direct to motors for thrust measure
// #define MOTORS_TO_THROTTLE

// throttle direct to motors for thrust measure as a flight mode
//#define MOTORS_TO_THROTTLE_MODE MULTI_CHAN_8


// loop time in uS
// this affects soft gyro lpf frequency if used
#define LOOPTIME 1000

// failsafe time in uS
#define FAILSAFETIME 1000000  // one second

// max rate used by level pid ( limit )
#define LEVEL_MAX_RATE 360

// debug things ( debug struct and other)
//#define DEBUG

// rxdebug structure
//#define RXDEBUG

// enable motors if pitch / roll controls off center (at zero throttle)
// possible values: 0 / 1
// use in acro build only
#define ENABLESTIX 0
#define ENABLESTIX_TRESHOLD 0.3
#define ENABLESTIX_TIMEOUT 1e6

// overclock to 64Mhz
//#define ENABLE_OVERCLOCK


// limit minimum motor output to a value (0.0 - 1.0)
//#define MOTOR_MIN_ENABLE
#define MOTOR_MIN_VALUE 0.05





#pragma diag_warning 1035 , 177 , 4017
#pragma diag_error 260

//--fpmode=fast





// define logic - do not change
///////////////

// used for pwm calculations
#ifdef ENABLE_OVERCLOCK
#define SYS_CLOCK_FREQ_HZ 64000000
#else
#define SYS_CLOCK_FREQ_HZ 48000000
#endif



#ifdef MOTOR_BEEPS
#ifdef USE_ESC_DRIVER
#warning "MOTOR BEEPS_WORKS WITH BRUSHED MOTORS ONLY"
#endif
#endif



// for the ble beacon to work after in-flight reset
#ifdef RX_BAYANG_PROTOCOL_BLE_BEACON
#undef STOP_LOWBATTERY
#endif


// gcc warnings in main.c



//Hardware defines moved from hardware.h so that board selection of bwhoop or e011 can be performed in config.h file

#ifdef BWHOOP
#define LED_NUMBER 2
#define LED1PIN GPIO_Pin_2
#define LED1PORT GPIOA
#define LED1_INVERT
#define LED2_INVERT
#define GYRO_ID_2 0x98 // new id
#define SENSOR_ROTATE_90_CW
// SPI PINS DEFINITONS ( for radio ic )
#define SPI_MOSI_PIN GPIO_Pin_0
#define SPI_MOSI_PORT GPIOA
//#define SPI_MISO_PIN GPIO_Pin_15
//#define SPI_MISO_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_1
#define SPI_CLK_PORT GPIOF
#define SPI_SS_PIN GPIO_Pin_0
#define SPI_SS_PORT GPIOF

// Assingment of pin to motor
// back-left motor ( motor 0 )
#define MOTOR0_PIN_PB1
// front-left motor ( motor 1 )
#define MOTOR1_PIN_PA4
// back-right motor ( motor 2 )
#define MOTOR2_PIN_PA6
// front-right motor ( motor 3 )
#define MOTOR3_PIN_PA7
#endif

#ifdef E011
#define LED_NUMBER 2
#define LED1PIN GPIO_Pin_2
#define LED1PORT GPIOA
#define LED1_INVERT
#define LED2_INVERT
#define GYRO_ID_2 0x98 // new id
#define SENSOR_ROTATE_90_CW
#define SOFTI2C_PUSHPULL_CLK
// SPI PINS DEFINITONS ( for radio ic )
#define SPI_MOSI_PIN GPIO_Pin_0
#define SPI_MOSI_PORT GPIOF
//#define SPI_MISO_PIN GPIO_Pin_15
//#define SPI_MISO_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_1
#define SPI_CLK_PORT GPIOF
#define SPI_SS_PIN GPIO_Pin_0
#define SPI_SS_PORT GPIOA

// Assingment of pin to motor
// back-left motor ( motor 0 )
#define MOTOR0_PIN_PA6
// front-left motor ( motor 1 )
#define MOTOR1_PIN_PA4
// back-right motor ( motor 2 )
#define MOTOR2_PIN_PB1
// front-right motor ( motor 3 )
#define MOTOR3_PIN_PA7
#endif

#ifdef H8mini_blue_board
#define LED_NUMBER 1
#define LED1PIN GPIO_Pin_1
#define LED1PORT GPIOF
#define SOFTI2C_PUSHPULL_CLK
#define GYRO_ID_2 0x78 // common h8 gyro
#define SENSOR_ROTATE_180
#define SPI_MOSI_PIN GPIO_Pin_1
#define SPI_MOSI_PORT GPIOA
#define SPI_CLK_PIN GPIO_Pin_2
#define SPI_CLK_PORT GPIOA
#define SPI_SS_PIN GPIO_Pin_3
#define SPI_SS_PORT GPIOA
#define MOTOR0_PIN_PA6
#define MOTOR1_PIN_PA4
#define MOTOR2_PIN_PB1
#define MOTOR3_PIN_PA7
#endif
