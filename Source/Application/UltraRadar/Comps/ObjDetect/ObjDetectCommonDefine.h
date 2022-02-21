#ifndef _OBJDETECTCOMMONDEFINE_H_
#define _OBJDETECTCOMMONDEFINE_H_

#include "DataTypeDef.h"

#ifndef DisableInterrupts
	#define DisableInterrupts	  __asm("DI")
#endif

#ifndef EnableInterrupts
	#define EnableInterrupts	  __asm("EI")
#endif


#define NO_OBJ_DISTANCE                   0x7fff
//#define NO_OBJ_DISTANCE                   6000
#define NO_OBJ_DISTANCE_WORD              0x7fff
#define NO_OBJ_TIME                       0xffff

#define SNS_DRIVE_FREQUENCY_UPA_SNS						(55000) // unit: hz 
#define SNS_DRIVE_FREQUENCY_APA_SNS						(48000) // unit: hz
#define SNS_DRIVE_FREQUENCY_NORMINAL					( (SNS_DRIVE_FREQUENCY_UPA_SNS + SNS_DRIVE_FREQUENCY_APA_SNS) / 2) // unit: hz


#define SOUND_SPEED_AT_NEGATIVE_40_DEGREE				306720
#define TEMPERATURE_COEFFICIENT_FOR_SOUND_SPEED      	303
#define SOUND_SPEED_UNIT_FACTOR							100
#define SNS_SUPPORT_MAX_DT_OBJ_NUM                    5
#define SNS_INPUT_CAPTURE_CHANNEL_NUM                       12


#define MCU_PORT_VOLTAGE_0_1V						20
#define MCU_PORT_VOLTAGE_0_3V						61
#define MCU_PORT_VOLTAGE_0_5V						102
#define MCU_PORT_VOLTAGE_0_6V						123
#define MCU_PORT_VOLTAGE_0_7V						143
#define MCU_PORT_VOLTAGE_0_8V						164
#define MCU_PORT_VOLTAGE_0_9V						184
#define MCU_PORT_VOLTAGE_1V							205
#define MCU_PORT_VOLTAGE_1_1V						225
#define MCU_PORT_VOLTAGE_1_2V						246
#define MCU_PORT_VOLTAGE_1_4V						287
#define MCU_PORT_VOLTAGE_1_6V						328
#define MCU_PORT_VOLTAGE_1_7V						348
#define MCU_PORT_VOLTAGE_1_8V						369
#define MCU_PORT_VOLTAGE_1_9V						389
#define MCU_PORT_VOLTAGE_2V							410
#define MCU_PORT_VOLTAGE_2_1V						431
#define MCU_PORT_VOLTAGE_2_6V						536

/**********************************************************************************************************/

#define VOLTAGE_5_5V								174									
#define VOLTAGE_6V									193									
#define VOLTAGE_6_5V								211
#define VOLTAGE_7_5V								247
#define VOLTAGE_8V									265
#define VOLTAGE_8_3V						    	276
#define VOLTAGE_8_5V                                283
#define VOLTAGE_8_8V                                294
#define VOLTAGE_9V                                  302
#define VOLTAGE_9_2V                                309
#define VOLTAGE_9_5V                                320
#define VOLTAGE_10V                                 338
#define VOLTAGE_11V									374
#define VOLTAGE_12V									411
#define VOLTAGE_13_8V								476
#define VOLTAGE_14V									483
#define VOLTAGE_15V                                 520
#define VOLTAGE_15_5V                               538
#define VOLTAGE_15_8V                               549
#define VOLTAGE_16V                                 556
#define VOLTAGE_16_2V                               563
#define VOLTAGE_16_5V                               574
#define VOLTAGE_17V                                 592
#define VOLTAGE_17_5V                               610
#define VOLTAGE_18V                                 629
#define VOLTAGE_18_5V                               648
#define VOLTAGE_26V									919
#define VOLTAGE_26_5V								938
#define VOLTAGE_27V									957
#define VOLTAGE_28V									995

#define ECU_MIN_VOLTAGE_THRESHOLD                     VOLTAGE_9V
#define ECU_MAX_VOLTAGE_THRESHOLD                     VOLTAGE_16V


#define TIMER_CLOCK                       				((double)(80))
#define TIMER_PRESCALE									((double)(80))

#define OBJECT_TIMER_CLOCK                       		((double)(80))
#define OBJECT_TIMER_PRESCALE							((double)(80))

#define SNS_OP_DATA_LOGIC_BIT_COMPENSATE_TIME					((word)((double)0 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))	// 6
#define SNS_TX_RX_CMD_INT_PROCESS_COMPENSATE_TIME				((word)((double)20 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))	// 6
#define SNS_TX_RX_CMD_INT_FOR_RC_VAR_COMPENSATE_TIME			((word)((double)8 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))	// 8
#define SNS_APA_UPA_TX_RX_DELAY_PROCESS_COMPENSATE_TIME			((word)(0)) // 1us.	

#define SNS_OP_CMD_EEPROM_RD_CMD_RX_DATA_TIME					((word)((double)30000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))//(SNS_OP_DATA_LOGIC_BIT_TIME_12T * (SNS_SUPPORT_EEPROM_DATA_BIT_NUM + 5))
#define SNS_OP_CMD_THRESHOLD_RD_CMD_RX_DATA_TIME                ((word)((double)60000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define SNS_OP_CMD_MEASUREMENT_RD_CMD_RX_DATA_TIME              ((word)((double)30000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define SNS_DATA_SEND_SEQ_DELAY_TO_INIT_TIME                    ((word)((double)35000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define SNS_DIAGNOSIS_READ_STATUS_CYCLE_TIME                    ((word)((double)30000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define SNS_POWER_UP_INIT_DELAY_CYCLE_TIME                    	((word)((double)10000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define SNS_CMD_SEND_DELAY_TIME                    				((word)((double)1000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))

#define OBJECT_TIME1US                           ((word)((double)1 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME10US                          ((word)((double)10 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME30US                          ((word)((double)30 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME40US                          ((word)((double)40 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME50US                          ((word)((double)50 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME80US                          ((word)((double)80 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME100US                         ((word)((double)100 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME150US                         ((word)((double)150 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME160US                         ((word)((double)160 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME200US                         ((word)((double)200 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME250US                         ((word)((double)250 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME280US                         ((word)((double)280 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME300US                         ((word)((double)300 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME320US                         ((word)((double)320 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME350US                         ((word)((double)350 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME400US                         ((word)((double)400 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME480US                         ((word)((double)480 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME500US                         ((word)((double)500 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME600US                         ((word)((double)600 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME640US                         ((word)((double)640 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME700US                         ((word)((double)700 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME800US                         ((word)((double)800 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME900US                         ((word)((double)900* OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME960US                         ((word)((double)960 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME1000US                        ((word)((double)1000  * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME1280US                        ((word)((double)1280 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME1300US						 ((word)((double)1300 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME1500US                        ((word)((double)1500 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME1600US                        ((word)((double)1600 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME1700US                        ((word)((double)1700 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME2MS                           ((word)((double)2000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME2_3MS                           ((word)((double)2300 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME2_5MS                         ((word)((double)2500 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME2880US                        ((word)((double)2880 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME3MS                           ((word)((double)3000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME3_62MS                        ((word)((double)3620 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME4MS                           ((word)((double)4000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME5MS                           ((word)((double)5000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME5_5MS                         ((word)((double)5500 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME5600US                        ((word)((double)5600 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME6MS                           ((word)((double)6000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME7MS                           ((word)((double)7000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME8MS                           ((word)((double)8000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME10MS                          ((word)((double)10000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME11MS                          ((word)((double)11000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME13MS                          ((word)((double)13000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME15MS                          ((word)((double)15000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME17MS                          ((word)((double)17000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME17_3MS			   ((word)((double)17300 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME18MS                          ((word)((double)18000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME20MS                          ((word)((double)20000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME25MS                          ((word)((double)25000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME28MS                          ((word)((double)28000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME30MS                          ((word)((double)30000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME31MS                          ((word)((double)31000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))
#define OBJECT_TIME34MS							 ((word)((double)34000 * OBJECT_TIMER_CLOCK / OBJECT_TIMER_PRESCALE))


#define TIME30US				((word)((double)30 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME40US				((word)((double)40 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME50US				((word)((double)50 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME80US				((word)((double)80 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME100US				((word)((double)100 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME150US				((word)((double)150 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME160US				((word)((double)160 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME200US				((word)((double)200 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME250US				((word)((double)250 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME280US				((word)((double)280 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME300US				((word)((double)300 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME320US				((word)((double)320 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME350US				((word)((double)350 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME400US				((word)((double)400 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME480US				((word)((double)480 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME500US				((word)((double)500 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME600US				((word)((double)600 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME640US				((word)((double)640 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME700US				((word)((double)700 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME750US				((word)((double)750 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME800US 				((word)((double)800 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME850US				((word)((double)850 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME900US				((word)((double)900 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME950US				((word)((double)950 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME960US				((word)((double)960 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME1000US				((word)((double)1000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME1100US				((word)((double)1100 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME1200US				((word)((double)1200 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME1280US				((word)((double)1280 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME1300US				((word)((double)1300 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME1400US				((word)((double)1400 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME1500US				((word)((double)1500 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME1600US				((word)((double)1600 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME1700US				((word)((double)1700 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME2200US				((word)((double)2200 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME2400US				((word)((double)2400 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME2MS					((word)((double)2000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME2_5MS				((word)((double)2500 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME2880US				((word)((double)2880 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME3MS					((word)((double)3000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME3_62MS				((word)((double)3620 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME4MS					((word)((double)4000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME5MS					((word)((double)5000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME5_5MS				((word)((double)5500 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME5600US				((word)((double)5600 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME6MS					((word)((double)6000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME7MS					((word)((double)7000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME8MS					((word)((double)8000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME10MS				((word)((double)10000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME11MS				((word)((double)11000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME13MS				((word)((double)13000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME15MS				((word)((double)15000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME17MS				((word)((double)17000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME18MS				((word)((double)18000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME20MS				((word)((double)20000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME25MS				((word)((double)25000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME28MS				((word)((double)28000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME30MS				((word)((double)30000 * TIMER_CLOCK / TIMER_PRESCALE))
#define TIME34MS				((word)((double)34000 * TIMER_CLOCK / TIMER_PRESCALE))


// This is sound speed which unit is mm/s

/// This coefficient is used to calculate the distance between the object and
// the sensor.
#define DISTANCE_UNIT_FACTOR							100000

#define DISTANCE5CM_TIME                 (5 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE10CM_TIME                (10 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE15CM_TIME                (15 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE20CM_TIME                (20 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE25CM_TIME                (25 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE30CM_TIME                (30 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)

#define DISTANCE35CM_TIME                (35 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2) 

#define DISTANCE40CM_TIME                (40 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE50CM_TIME                (50 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE60CM_TIME                (60 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE70CM_TIME                (70 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE80CM_TIME                (80 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE90CM_TIME                (90 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE100CM_TIME               (100 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE110CM_TIME               (110 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE120CM_TIME               (120 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE125CM_TIME               (125 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE130CM_TIME               (130 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE140CM_TIME               (140 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE150CM_TIME               (150 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE160CM_TIME               (160 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE170CM_TIME               (170 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE180CM_TIME               (180 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE190CM_TIME               (190 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE250CM_TIME               (250 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE255CM_TIME               (255 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE260CM_TIME               (260 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE270CM_TIME               (270 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE280CM_TIME               (280 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE500CM_TIME               (500 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)
#define DISTANCE530CM_TIME               (530 * DISTANCE_UNIT_FACTOR / DISTANCE_COEFFICIENT * 2)


//------------- Object Distance calculation const data used -----------------
// UNIT_FACTOR is used as a factor between units transformation
#define DISTANCE_UNIT_FACTOR1                       1000
#define DISTANCE_UNIT_FACTOR1_APA                   20000  // accuracy to : 1mm
#define DISTANCE_UNIT_FACTOR2                       100 /* accuracy to : 0.1 mm */
#define DISTANCE_UNIT_FACTOR3												10 /* accuracy to : mm */
#define DISTANCE_UNIT_FACTOR4												10 /* accuracy to : cm */

#define SOUND_SPEED_NORMALLY			          		3400	
#define DISTANCE_COEFFICIENT              (SOUND_SPEED_NORMALLY / 1)


#define DTCPRO_VALID                   														0
#define DTCPRO_INVALID                   													1

#define SNS_SUPPORT_TOTAL_DTC_TYPE_NUM									5


#define DTC_RECORD_TOTAL_NUM											99
#define DTC_TO_BE_STORED_FLAG_NUM										(DTC_RECORD_TOTAL_NUM / 8 + 1)

#define DTC_LOW_SPEED_CAN_COMMUNICATION_PERFORMANCE 					0
#define DTC_CHASSIS_EXPANSION_CAN_COMMUNICATION_BUS_OFF					1
#define DTC_LOW_SPEED_CAN_COMMUNICATION_BUS_OFF  						2

#define DTC_LOSS_OF_COMM_WITH_BCM 										3
#define DTC_LOSS_OF_COMM_WITH_IPC 										4
#define DTC_LOSS_OF_COMM_WITH_CHM 										5
#define DTC_LOSS_OF_COMM_WITH_IRC 										6

#define DTC_LOSS_OF_COMM_WITH_AMP										7
#define DTC_LOSS_OF_COMM_WITH_MSM 										8
#define DTC_LOSS_OF_COMM_WITH_TIM 										9

#define SIGNAL_1_WAS_RECEIVED_WITH_INVALID_VALUE						10
#define SIGNAL_2_WAS_RECEIVED_WITH_INVALID_VALUE						11
#define SIGNAL_3_WAS_RECEIVED_WITH_INVALID_VALUE						12	

#define PA_PHYSICAL_SWITCH_SHOT_TO_GND 									13
#define APA_PHYSICAL_SWITCH_SHORT_TO_GND								14

#define ECU_VIN_CHECK_ERROR 											15

#define RAM_FAIL														16
#define FLASH_MEMORY_FAIL												17
#define EEPROM_FAIL														18
#define ADC_FAIL														19
#define INTERNAL_COMMUNICATIONS_FAIL									20									

#define INTERNAL_SELF_TEST_FAILED										21
#define OPTION_CONFIG_ERROR												22
#define EEPROM_ERROR													23
#define XML_CONFIG_ERROR												24
#define CIRCUIT_COMPONENT_PROTECTION_TIMEOUT							25
	
#define DEVICE_POWER_VOLTAGE_TOO_LOW 									26
#define DEVICE_POWER_VOLTAGE_TOO_HIGH 									27

#define SENSOR_FEED_VOLTAGE_SHORT_TO_GND								28
#define SENSOR_FEED_VOLTAGE_TOO_LOW										29
#define SENSOR_FEED_VOLTAGE_TOO_HIGH									30

#define LEFT_SIDE_OBJ_DETECT_INDICATOR_CIRCUIT_SHORT_TO_BATTERY			31
#define LEFT_SIDE_OBJ_DETECT_INDICATOR_CIRCUIT_SHORT_TO_GND				32
#define LEFT_SIDE_OBJ_DETECT_INDICATOR_CIRCUIT_OPEN						33
#define RIGHT_SIDE_OBJ_DETECT_INDICATOR_CIRCUIT_SHORT_TO_BATTERY		34
#define RIGHT_SIDE_OBJ_DETECT_INDICATOR_CIRCUIT_SHORT_TO_GND			35
#define RIGHT_SIDE_OBJ_DETECT_INDICATOR_CIRCUIT_OPEN					36

#define PA_INDICATOR_LED_CIRCUIT_SHORT_TO_GND_OR_OPEN					37
#define PA_INDICATOR_LED_CIRCUIT_SHORT_TO_BATTERY						38

#define REAR_RIGHT_SIDE_SENSOR_SHORT_TO_BATTERY 						39
#define REAR_RIGHT_SIDE_SENSOR_SHORT_TO_GROUND_OR_OPEN 					40
#define REAR_RIGHT_SIDE_SENSOR_SIGNAL_INVALID							41
#define REAR_RIGHT_SIDE_SENSOR_RING_TIME 								42
#define REAR_RIGHT_SIDE_SENSOR_COMPONENT_INCORRECT						43

#define REAR_RIGHT_CORNER_SENSOR_SHORT_TO_BATTERY 						44
#define REAR_RIGHT_CORNER_SENSOR_SHORT_TO_GROUND_OR_OPEN				45
#define REAR_RIGHT_CORNER_SENSOR_SIGNAL_INVALID 						46
#define REAR_RIGHT_CORNER_SENSOR_RING_TIME 								47
#define REAR_RIGHT_CORNER_SENSOR_COMPONENT_INCORRECT					48

#define REAR_RIGHT_INNER_SENSOR_SHORT_TO_BATTERY 						49
#define REAR_RIGHT_INNER_SENSOR_SHORT_TO_GROUND_OR_OPEN 				50
#define REAR_RIGHT_INNER_SENSOR_SIGNAL_INVALID 							51
#define REAR_RIGHT_INNER_SENSOR_RING_TIME 								52
#define REAR_RIGHT_INNER_SENSOR_COMPONENT_INCORRECT 					53

#define REAR_LEFT_INNER_SENSOR_SHORT_TO_BATTERY 						54
#define REAR_LEFT_INNER_SENSOR_SHORT_TO_GROUND_OR_OPEN 					55
#define REAR_LEFT_INNER_SENSOR_SIGNAL_INVALID 							56
#define REAR_LEFT_INNER_SENSOR_RING_TIME 								57
#define REAR_LEFT_INNER_SENSOR_COMPONENT_INCORRECT 						58

#define REAR_LEFT_CORNER_SENSOR_SHORT_TO_BATTERY 						59
#define REAR_LEFT_CORNER_SENSOR_SHORT_TO_GROUND_OR_OPEN 				60
#define REAR_LEFT_CORNER_SENSOR_SIGNAL_INVALID							61
#define REAR_LEFT_CORNER_SENSOR_RING_TIME 								62
#define REAR_LEFT_CORNER_SENSOR_COMPONENT_INCORRECT						63

#define REAR_LEFT_SIDE_SENSOR_SHORT_TO_BATTERY 							64
#define REAR_LEFT_SIDE_SENSOR_SHORT_TO_GROUND_OR_OPEN 					65
#define REAR_LEFT_SIDE_SENSOR_SIGNAL_INVALID 							66
#define REAR_LEFT_SIDE_SENSOR_RING_TIME 								67
#define REAR_LEFT_SIDE_SENSOR_COMPONENT_INCORRECT 						68

#define FRONT_RIGHT_SIDE_SENSOR_SHORT_TO_BATTERY 						69
#define FRONT_RIGHT_SIDE_SENSOR_SHORT_TO_GROUND_OR_OPEN 				70
#define FRONT_RIGHT_SIDE_SENSOR_SIGNAL_INVALID							71
#define FRONT_RIGHT_SIDE_SENSOR_RING_TIME 								72
#define FRONT_RIGHT_SIDE_SENSOR_COMPONENT_INCORRECT						73

#define FRONT_RIGHT_CORNER_SENSOR_SHORT_TO_BATTERY 						74
#define FRONT_RIGHT_CORNER_SENSOR_SHORT_TO_GROUND_OR_OPEN				75
#define FRONT_RIGHT_CORNER_SENSOR_SIGNAL_INVALID 						76
#define FRONT_RIGHT_CORNER_SENSOR_RING_TIME 							77
#define FRONT_RIGHT_CORNER_SENSOR_COMPONENT_INCORRECT					78

#define FRONT_RIGHT_INNER_SENSOR_SHORT_TO_BATTERY 						79
#define FRONT_RIGHT_INNER_SENSOR_SHORT_TO_GROUND_OR_OPEN 				80
#define FRONT_RIGHT_INNER_SENSOR_SIGNAL_INVALID 						81
#define FRONT_RIGHT_INNER_SENSOR_RING_TIME 								82
#define FRONT_RIGHT_INNER_SENSOR_COMPONENT_INCORRECT 					83

#define FRONT_LEFT_INNER_SENSOR_SHORT_TO_BATTERY 						84
#define FRONT_LEFT_INNER_SENSOR_SHORT_TO_GROUND_OR_OPEN 				85
#define FRONT_LEFT_INNER_SENSOR_SIGNAL_INVALID 							86
#define FRONT_LEFT_INNER_SENSOR_RING_TIME 								87
#define FRONT_LEFT_INNER_SENSOR_COMPONENT_INCORRECT 					88

#define FRONT_LEFT_CORNER_SENSOR_SHORT_TO_BATTERY 						89
#define FRONT_LEFT_CORNER_SENSOR_SHORT_TO_GROUND_OR_OPEN 				90
#define FRONT_LEFT_CORNER_SENSOR_SIGNAL_INVALID							91
#define FRONT_LEFT_CORNER_SENSOR_RING_TIME 								92
#define FRONT_LEFT_CORNER_SENSOR_COMPONENT_INCORRECT					93

#define FRONT_LEFT_SIDE_SENSOR_SHORT_TO_BATTERY 						94
#define FRONT_LEFT_SIDE_SENSOR_SHORT_TO_GROUND_OR_OPEN 					95
#define FRONT_LEFT_SIDE_SENSOR_SIGNAL_INVALID 							96
#define FRONT_LEFT_SIDE_SENSOR_RING_TIME 								97
#define FRONT_LEFT_SIDE_SENSOR_COMPONENT_INCORRECT 						98

//------------- calculate warning zone macro define -----------------

#define NO_OBJ_ZONE							  0
#define OBJ_ZONE1                             1
#define OBJ_ZONE2							  2
#define OBJ_ZONE3							  3
#define OBJ_ZONE4							  4

#define REGION_NUM                            4
#define REAR_REGION_RIGHT                     0
#define REAR_REGION_MID                       1
#define REAR_REGION_LEFT                      2
#define REAR_REGION_RESERVE                   3
#define FRONT_REGION_RIGHT                    0
#define FRONT_REGION_MID                      1
#define FRONT_REGION_LEFT                     2
#define FRONT_REGION_RESERVE                  3

#define CHECK_TRAILER_WHEN_REVERSE
#define CHECK_BIKE_RACK_WHEN_REVERSE
#define RIGHT_SIDE_OF_VEHICLE                 0
#define LEFT_SIDE_OF_VEHICLE				  1


/* S1 - EMIT, S2, S3 */
typedef enum
{
  S1_EMIT_S1_RX_INDEX = 0,
  S1_EMIT_S2_RX_INDEX,/*1*/
  S1_EMIT_S3_RX_INDEX,/*2*/
  S1_TRIANGLE_INDEX	/*3*/
}SnsRxIndexType;

typedef enum
{
  RS_SNS_INDEX = 0,
  R_SNS_INDEX, /*1*/
  RM_SNS_INDEX,/*2*/
  LM_SNS_INDEX,/*3*/
  L_SNS_INDEX, /*4*/
  LS_SNS_INDEX/*5*/
} SnsIndexType;


typedef enum
{
  PARearSys = 0,
  PAFrontSys
} PASysType;

typedef enum
{
	READ_THRES_SETUP_CMD = 1, /*1*/
	READ_MEAS_SETUP_CMD, /*2*/
	READ_CALIB_CMD, /*3*/
	READ_IDLE
} SnsRegsReadCmdType;


#define SNS_CHANNEL_DISABLED_INDEX                          0xff

#define APA_FL_SNS_CHANNEL_INDEX                        11
#define APA_FR_SNS_CHANNEL_INDEX                        6
#define APA_RL_SNS_CHANNEL_INDEX                        5//SNS_CHANNEL_DISABLED_INDEX
#define APA_RR_SNS_CHANNEL_INDEX                        0//SNS_CHANNEL_DISABLED_INDEX
#define APA_FL_SNS_INDEX_MASK                           (1 << LS_SNS_INDEX)
#define APA_FR_SNS_INDEX_MASK                           (1 << RS_SNS_INDEX)
#define APA_RL_SNS_INDEX_MASK                           (1 << LS_SNS_INDEX)               // Channel is disabled
#define APA_RR_SNS_INDEX_MASK                           (1 << RS_SNS_INDEX)               // Channel is disabled
#define APA_FRONT_SNS_INDEX_MASK				(APA_FL_SNS_INDEX_MASK | APA_FR_SNS_INDEX_MASK)
#define APA_REAR_SNS_INDEX_MASK				(APA_RL_SNS_INDEX_MASK | APA_RR_SNS_INDEX_MASK)
#define APA_SNS_INDEX_MASK                              (APA_FL_SNS_INDEX_MASK | APA_FR_SNS_INDEX_MASK \
                                                        | APA_RL_SNS_INDEX_MASK | APA_RR_SNS_INDEX_MASK)

#define APA_R_SNS_SYS_TYPE_INDEX                        PAFrontSys
#define APA_R_SNS_INDEX                                 RS_SNS_INDEX
#define APA_L_SNS_INDEX                                 LS_SNS_INDEX
#define APA_SNS_SYS_TYPE_INDEX                          PAFrontSys
#define APA_FRONT_SYS_TYPE_INDEX						PAFrontSys
#define APA_REAR_SYS_TYPE_INDEX							PARearSys

#define SBSA_LED_DRIVER_SIDE_INDEX						0
#define SBSA_LED_PASSENGER_SIDE_INDEX					1

#define SBSA_LED_NIGHT_TIME_INDEX						0
#define SBSA_LED_DAY_TIME_INDEX							1
#define SBSA_LED_NUM									2


typedef enum{
	PAWithRearOnlyHardWare = 0,
	PAWithBothFrontAndRearHardWare
} HardWareType;

typedef enum{
  PASysWith0FSnsAnd4RSns = 0,
  PASysWith0FSnsAnd6RSns,
  PASysWith4FSnsAnd4RSns,
  PASysWith4FSnsAnd6RSns,
  PASysWith6FSnsAnd4RSns,
  PASysWith6FSnsAnd6RSns
} PASysSnsType;

#define  SYS_WITHOUT_SNS_MASK								        0x00
#define  PA_SNS_MASK												0x3f
#define  PA_SNS_MASK1												0x07
#define  PA_SNS_MASK2												0x38
#define  RS_SNS_MASK												0x01
#define  R_SNS_MASK													0x02
#define  RM_SNS_MASK												0x04
#define  LM_SNS_MASK												0x08
#define  L_SNS_MASK													0x10
#define  LS_SNS_MASK												0x20


typedef enum{
  RRS_SNS_INDEX = 0,
  RR_SNS_INDEX, /*1*/
  RRM_SNS_INDEX,/*2*/
  RLM_SNS_INDEX,/*3*/
  RL_SNS_INDEX, /*4*/
  RLS_SNS_INDEX,/*5*/
  FRS_SNS_INDEX,/*6*/
  FR_SNS_INDEX, /*7*/
  FRM_SNS_INDEX,/*8*/
  FLM_SNS_INDEX,/*9*/
  FL_SNS_INDEX, /*10*/
  FLS_SNS_INDEX/*11*/
} PASysSnsIndexType;

#define UPA_SNS_DT_OBJ_DIS_ARRAY_INVALID_INDEX				0xff

typedef enum {

  R_RM_TRIANGLE_OBJ_INDEX = 0,
  RM_LM_TRIANGLE_OBJ_INDEX, /* 1 */
  RM_R_TRIANGLE_OBJ_INDEX,  /* 2 */
  LM_RM_TRIANGLE_OBJ_INDEX, /* 3 */
  LM_L_TRIANGLE_OBJ_INDEX,  /* 4 */
  L_LM_TRIANGLE_OBJ_INDEX   /* 5 */

} UPASnsDtTirangleObjInfoType;

typedef enum{

  R_RM_TRIANGLE_H_OBJ_INDEX = 0,
  RM_LM_TRIANGLE_H_OBJ_INDEX, /* 1 */
  RM_R_TRIANGLE_H_OBJ_INDEX,  /* 2 */
  LM_RM_TRIANGLE_H_OBJ_INDEX, /* 3 */
  LM_L_TRIANGLE_H_OBJ_INDEX,  /* 4 */
  L_LM_TRIANGLE_H_OBJ_INDEX  /* 5 */

} TriangleHObjArrayType;


#define TOTAL_TRIANGLE_OBJ_INDEX							6
#define UPA_SNS_DT_TRIANGLE_OBJ_ARRAY_NUM					6
#define UPA_SNS_DT_OBJ_BUF_SIZE                   			10
#define UPA_SNS_DT_OBJ_LAST_VALUE_INDEX              		(UPA_SNS_DT_OBJ_BUF_SIZE - 1)

typedef enum{

  UPA_APA_SNS_RS_EMIT_RS_RX_OBJ_INDEX = 0,
  UPA_APA_SNS_R_EMIT_R_RX_OBJ_INDEX,   // 1
  UPA_APA_SNS_R_EMIT_RM_RX_OBJ_INDEX,   /* 2 */
  UPA_APA_SNS_RM_EMIT_RM_RX_OBJ_INDEX,  /* 3 */
  UPA_APA_SNS_RM_EMIT_LM_RX_OBJ_INDEX,  /* 4 */
  UPA_APA_SNS_RM_EMIT_R_RX_OBJ_INDEX,   /* 5 */
  UPA_APA_SNS_LM_EMIT_LM_RX_OBJ_INDEX,  /* 6 */
  UPA_APA_SNS_LM_EMIT_RM_RX_OBJ_INDEX,  /* 7 */
  UPA_APA_SNS_LM_EMIT_L_RX_OBJ_INDEX,   /* 8 */
  UPA_APA_SNS_L_EMIT_L_RX_OBJ_INDEX,    /* 9 */
  UPA_APA_SNS_L_EMIT_LM_RX_OBJ_INDEX ,  /* 10 */
  UPA_APA_SNS_LS_EMIT_LS_RX_OBJ_INDEX   // 11

} UPAAPASnsDtObjInfoType;

#define UPA_APA_SNS_DT_NON_TRIANGLE_OBJ_ARRAY_NUM			12

#define SUPPORT_REINIT_GMLAN_SIGNAL_WHEN_VN_REINIT

#define MCU_CLOCK_OSC_WITH_PLL_64MHZ

#define SUPPORT_READ_SNS_INIT_DATA_CHECK_SUM_WITH_PARITY_BIT
#define SUPPORT_ONLY_CHECK_VIN_ONCE_WHEN_POWER_UP

#define PA_POWER_UP_SNS_SELFTEST_TIME						8000 /* 8s */
#define PA_POWER_UP_SNS_INIT_TIME							2000 /* 1s */


#define PA_SYS_NUM									        2
#define SNS_CAPTURE_INTERRUPT_PRIORITY          12
#define PA_REAR_SYS_TYPE_NUM                    2

#define PA_REAR_SNS_NUM                         6
#define PA_FRONT_SNS_NUM                        6

#define PA_SNS_NUM                              (PA_REAR_SNS_NUM + PA_FRONT_SNS_NUM)

#define DTM_DRV_INFO_OUTPUT_TASK_CALL_TIME		        	10
#define DTM_SPK_CHIME_CMD_TASK_CALL_TIME			    	10
#define SPK_CHIME_TASK_CALL_TIME                DTM_SPK_CHIME_CMD_TASK_CALL_TIME
#define SBSA_LED_TASK_CALL_TIME								10		
#define DTM_SNS_DT_ST_TASK_CALL_TIME						10
#define BIKE_RAKE_DETECTION_TASK_CALL_TIME		        	30
#define TRAILER_DETECTION_TASK_CALL_TIME			    	30
#define WALL_DETECTION_TASK_CALL_TIME						30
#define GET_OBJ_INFO_TASK_CALL_TIME							30
#define DTM_OBJ_STATE_AND_NEAREST_DIS_CALL_TIME             30
#define DISPLAY_LED_TASK_CALL_TIME							10
#define DISABLE_ENABLE_LED_TASK_CALL_TIME			    	10
#define PA_PHY_SW_DT_TASK_CALL_CYCLE_TIME			    	10
#define PA_PERIOD_DIAG_TASK_CALL_CYCLE_TIME		        	100
#define PRS_DRV_INPT_AND_DTM_PA_OPR_ST_TASK_CALL_CYCLE_TIME 10
#define ECU_POWER_MONITOR_TASK_CALL_CYCLE_TIME	            5
#define SBSA_TASK_CALL_TIME									10


#define FRONT_SNS_PORT_MASK_6_SNS          0x3F/*0011,1111*/
#define FRONT_SNS_PORT_MASK_4_SNS          0x1E/*0001,1110*/
#define REAR_SNS_PORT_MASK_6_SNS           0x3F/*0011,1111*/
#define REAR_SNS_PORT_MASK_4_SNS           0x17/*0001,0111*/


#define APA_DISABLE_ENABLE_LED_PIN							//SBSA_DISABLE_ENABLE_RIGHT_LED_PIN
#define APA_DISABLE_ENABLE_LED_FEED_BACK_PIN				//SBSA_RIGHT_LED_FEED_BACK_PIN

/* Define Sensor State */
#define SENSOR_OFF												0
#define SENSOR_ACTIVE											1
#define SENSOR_DIAGNOSIS										2
#define SENSOR_DIAGNOSIS_READ_RING_TIME   						3

#define PA_DISABLE_HISTORY_BUF_SIZE								7

/********************** GMLAN Signals definition **************************/

#define VEHICLE_SPEED_AVG_NON_DRVN_FACTOR			1

//--------------------- System power mode ----------------------------------
#define SYS_PWR_MD_OFF                        0
#define SYS_PWR_MD_ACC                        1
#define SYS_PWR_MD_RUN                        2
#define SYS_PWR_MD_CRANK                      3

//--------------------- System back power mode -----------------------------
#define SYS_BK_PWR_MD_OFF                     0
#define SYS_BK_PWR_MD_ACC                     1
#define SYS_BK_PWR_MD_RUN                     2
#define SYS_BK_PWR_MD_CRANK                   3

//---------------- Transmission Shift Lever Position Validity ---------------------
#define TRAN_POS_VLD                          0
#define TRAN_POS_INVLD                        1


//-------------- Transmission Virtual Device Availability =------------------
#define TRNS_UNAVL                            0
#define TRNS_AVL                              1

//------------------ Engine Virtual Device Availability ---------------------
#define ENG_UNAVL                             0
#define ENG_AVL                               1

//--------------- Park Brake Virtual Device Availability --------------------
#define PRK_BRK_UNAVL                         0
#define PRK_BRK_AVL                           1

//-------------------- Parking assistance status ----------------------------
#define PRK_AST_ST_DISABLED                   0
#define PRK_AST_ST_ENABLED                    1
#define PRK_AST_ST_INHIBITED                  2
#define PRK_AST_ST_FAILED                     3

//------------------- Parking Assistance Rear System Status -----------------
#define PA_RR_SYS_STAT_DISABLED                   0
#define PA_RR_SYS_STAT_ENABLED                    1
#define PA_RR_SYS_STAT_INHIBITED                  2
#define PA_RR_SYS_STAT_FAILED                     3

//------------------- Parking Assistance Front System Status ----------------
#define PA_FR_SYS_STAT_DISABLED                   0
#define PA_FR_SYS_STAT_ENABLED                    1
#define PA_FR_SYS_STAT_INHIBITED                  2
#define PA_FR_SYS_STAT_FAILED                     3
//------------------- Parking Assistance APA System Status -----------------
#define PA_APA_SYS_STAT_DISABLED                   0
#define PA_APA_SYS_STAT_ENABLED                    1
#define PA_APA_SYS_STAT_INHIBITED                  2
#define PA_APA_SYS_STAT_FAILED                     3

/* ODI definition */

#define ODI_PARK_ASSIST_OPTION_OFF															0
#define ODI_PARK_ASSIST_OPTION_ON																1

#define ODI_PARK_ASSIST_WITH_TOWBAR_OPTION_OFF									0
#define ODI_PARK_ASSIST_WITH_TOWBAR_OPTION_ON										1
#define ODI_PARK_ASSIST_WITH_TOWBAR_OPTION_TOW_BAR							2

#define ODI_ACTION_RESTORE_FACTORY_DEFAULT_SETTINGS							1
#define ODI_ACTION_SET_PARK_ASSIST_SETTING											2
#define ODI_ACTION_SET_PARK_ASSIST_WITH_TOWBAR_SETTING					3


#define CRASH_ALERT_DRIVER_SELECTED_TYPE_CHIME									0
#define CRASH_ALERT_DRIVER_SELECTED_TYPE_SEAT										1

#define HAPTIC_SEAT_STATE_NORMAL																0
#define HAPTIC_SEAT_STATE_UNKNOWN																1
#define HAPTIC_SEAT_STATE_FAILED																2

#define PARK_ASSISTANCE_OPERATOR_DESIRED_STATUS_OFF							0
#define PARK_ASSISTANCE_OPERATOR_DESIRED_STATUS_ON							1
#define PARK_ASSISTANCE_OPERATOR_DESIRED_STATUS_TB							2


/************************ End of GMLAN signals definitions ****************/

typedef union 
{
  unsigned char Byte;
  struct 
  {
    unsigned int  BIT0        :1;                                       /* Bit 0 */
    unsigned int  BIT1        :1;                                       /* Bit 1 */
    unsigned int  BIT2        :1;                                       /* Bit 2 */
    unsigned int  BIT3        :1;                                       /* Bit 3 */
    unsigned int  BIT4        :1;                                       /* Bit 4 */
    unsigned int  BIT5        :1;                                       /* Bit 5 */
    unsigned int  BIT6        :1;                                       /* Bit 6 */
    unsigned int  BIT7        :1;                                       /* Bit 7 */
  } Bits;
} tByteBitType;

typedef union
{
  unsigned int Word;
  struct 
  {
    unsigned int  BIT0        :1;                                       /* Bit 0 */
    unsigned int  BIT1        :1;                                       /* Bit 1 */
    unsigned int  BIT2        :1;                                       /* Bit 2 */
    unsigned int  BIT3        :1;                                       /* Bit 3 */
    unsigned int  BIT4        :1;                                       /* Bit 4 */
    unsigned int  BIT5        :1;                                       /* Bit 5 */
    unsigned int  BIT6        :1;                                       /* Bit 6 */
    unsigned int  BIT7        :1;                                       /* Bit 7 */
    unsigned int  BIT8        :1;                                       /* Bit 8 */
    unsigned int  BIT9        :1;                                       /* Bit 9 */
    unsigned int  BIT10       :1;                                       /* Bit 10 */
    unsigned int  BIT11       :1;                                       /* Bit 11 */
    unsigned int  BIT12       :1;                                       /* Bit 12 */
    unsigned int  BIT13       :1;                                       /* Bit 13 */
    unsigned int  BIT14       :1;                                       /* Bit 14 */
    unsigned int  BIT15       :1;                                       /* Bit 15 */
  } Bits;
} tWordBitType;

typedef union
{
  dword DWord;
  struct
  {
    dword  BIT0        :1;                                       /* Bit 0 */
    dword  BIT1        :1;                                       /* Bit 1 */
    dword  BIT2        :1;                                       /* Bit 2 */
    dword  BIT3        :1;                                       /* Bit 3 */
    dword  BIT4        :1;                                       /* Bit 4 */
    dword  BIT5        :1;                                       /* Bit 5 */
    dword  BIT6        :1;                                       /* Bit 6 */
    dword  BIT7        :1;                                       /* Bit 7 */
    dword  BIT8        :1;                                       /* Bit 8 */
    dword  BIT9        :1;                                       /* Bit 9 */
    dword  BIT10       :1;                                       /* Bit 10 */
    dword  BIT11       :1;                                       /* Bit 11 */
    dword  BIT12       :1;                                       /* Bit 12 */
    dword  BIT13       :1;                                       /* Bit 13 */
    dword  BIT14       :1;                                       /* Bit 14 */
    dword  BIT15       :1;                                       /* Bit 15 */
    dword  BIT16       :1;                                       /* Bit 16 */
    dword  BIT17       :1;                                       /* Bit 17 */
    dword  BIT18       :1;                                       /* Bit 18 */
    dword  BIT19       :1;                                       /* Bit 19 */
    dword  BIT20       :1;                                       /* Bit 20 */
    dword  BIT21       :1;                                       /* Bit 21 */
    dword  BIT22       :1;                                       /* Bit 22 */
    dword  BIT23       :1;                                       /* Bit 23 */
    dword  BIT24       :1;                                       /* Bit 24 */
    dword  BIT25       :1;                                       /* Bit 25 */
    dword  BIT26       :1;                                       /* Bit 26 */
    dword  BIT27       :1;                                       /* Bit 27 */
    dword  BIT28       :1;                                       /* Bit 28 */
    dword  BIT29       :1;                                       /* Bit 29 */
    dword  BIT30       :1;                                       /* Bit 30 */
    dword  BIT31       :1;                                       /* Bit 31 */
  } Bits;
} tDWordBitType;

typedef struct {
	byte WheelSize								  	: 5; // Byte0.bit0
	byte TowBarOptionOff							: 1;
	byte TrailerHitchCompensation					: 1;
	byte SpeedSignalType							: 1; // Byte0.bit7

	byte GMLANTrailerSwitch				         	: 1; // Byte1.bit0
	byte TransmissionType			     			: 1;
	byte DrivenWheel								: 1;
	byte PAEnableDisableMethod						: 3;
	byte SteeringWheelLocation     					: 1;
	byte ParkingBrakeSwitchEnabled					: 1;  // Byte1.bit7

	byte APA2ActivationMethod						: 2; 
	byte UPAStrategy								: 1;
	byte PASystemType								: 1;
	byte BiDirectionalWheelSpdSnsConfig				: 2;
	byte MemorizationCustomization                 	: 1;
	byte GearSignalSelect   						: 1; 
} tDIDA1ECUConfigOrCustomizationData1BitType;


typedef union {
	byte Byte;
	struct {
		/* Byte */
		byte DescDisableNormalComm 					: 1;
		byte DescDisableAllDTC						: 1;
		byte DescEnDTCDuringDevCtrl					: 1;
		byte DescOnChangeDTCCountStart 				: 1;
		byte Reserve								: 4;
	} Bits;
} tDescEventType;


typedef union {
	byte cByte[3];
	tDIDA1ECUConfigOrCustomizationData1BitType Bits;
} tDIDA1ECUConfigOrCustomizationData1Type;

extern    tDIDA1ECUConfigOrCustomizationData1Type 	DIDA1ECUConfigOrCustomizationData1;
#define bWheelSize														DIDA1ECUConfigOrCustomizationData1.Bits.WheelSize
#define bTowBarOptionOff    											DIDA1ECUConfigOrCustomizationData1.Bits.TowBarOptionOff
#define bSpeedSignalType												DIDA1ECUConfigOrCustomizationData1.Bits.SpeedSignalType

#define bGMLANTrailerSwitch												DIDA1ECUConfigOrCustomizationData1.Bits.GMLANTrailerSwitch
#define bTransmissionType												DIDA1ECUConfigOrCustomizationData1.Bits.TransmissionType
#define bDrivenWheel													DIDA1ECUConfigOrCustomizationData1.Bits.DrivenWheel
#define bPAEnableDisableMethod											DIDA1ECUConfigOrCustomizationData1.Bits.PAEnableDisableMethod
#define bSteeringWheelLocation											DIDA1ECUConfigOrCustomizationData1.Bits.SteeringWheelLocation
#define bParkingBrakeSwitchEnabled										DIDA1ECUConfigOrCustomizationData1.Bits.ParkingBrakeSwitchEnabled

#define bAPA2ActivationMethod											DIDA1ECUConfigOrCustomizationData1.Bits.APA2ActivationMethod
#define bUPAStrategy													DIDA1ECUConfigOrCustomizationData1.Bits.UPAStrategy
#define bPASystemType													DIDA1ECUConfigOrCustomizationData1.Bits.PASystemType
#define bBiDirectionalWheelSpdSnsConfig									DIDA1ECUConfigOrCustomizationData1.Bits.BiDirectionalWheelSpdSnsConfig
#define bMemorizationCustomization										DIDA1ECUConfigOrCustomizationData1.Bits.MemorizationCustomization
#define bGearSignalSelect												DIDA1ECUConfigOrCustomizationData1.Bits.GearSignalSelect

/*------------------------ Byte 0----------------------*/
#define WHEEL_SIZE1_MASK										0x00
#define WHEEL_SIZE2_MASK										0x01
#define WHEEL_SIZE3_MASK										0x02
#define WHEEL_SIZE4_MASK										0x03
#define WHEEL_SIZE5_MASK										0x04
#define WHEEL_SIZE6_MASK										0x05
#define WHEEL_SIZE7_MASK										0x06
#define WHEEL_SIZE8_MASK										0x07
#define WHEEL_SIZE9_MASK										0x08
#define WHEEL_SIZE10_MASK										0x09
#define WHEEL_SIZE11_MASK										0x0A
#define WHEEL_SIZE12_MASK										0x0B
#define WHEEL_SIZE13_MASK										0x0C
#define WHEEL_SIZE14_MASK										0x0D
#define WHEEL_SIZE15_MASK										0x0E
#define WHEEL_SIZE16_MASK										0x0F
#define WHEEL_SIZE17_MASK										0x10
#define WHEEL_SIZE18_MASK										0x11
#define WHEEL_SIZE19_MASK										0x12
#define WHEEL_SIZE20_MASK										0x13
#define WHEEL_SIZE21_MASK										0x14
#define WHEEL_SIZE22_MASK										0x15
#define WHEEL_SIZE23_MASK										0x16
#define WHEEL_SIZE24_MASK										0x17
#define WHEEL_SIZE25_MASK										0x18
#define WHEEL_SIZE26_MASK										0x19
#define WHEEL_SIZE27_MASK										0x1A
#define WHEEL_SIZE28_MASK										0x1B
#define WHEEL_SIZE29_MASK										0x1C
#define WHEEL_SIZE30_MASK										0x1D
#define WHEEL_SIZE31_MASK										0x1E
#define WHEEL_SIZE32_MASK										0x1F

#define TOWBAR_OPTION_OFF_DISABLE_MASK 							0x00
#define TOWBAR_OPTION_OFF_ENABLE_MASK  							0x20

#define TRAILER_HITCH_COMPENSATION_DISABLE_MASK					0x00
#define TRAILER_HITCH_COMPENSATION_ENABLE_MASK					0x40

#define SPEED_SIGNAL_TYPE_NON_DRIVEN_MASK						0x00
#define SPEED_SIGNAL_TYPE_DRIVEN_MASK							0x80

/*------------------------ Byte 1----------------------*/
#define GMLAN_WITHOUT_TRAILER_SWITCH_MASK 						0x00
#define GMLAN_WITH_TRAILER_SWITCH_MASK 							0x01


extern tWordBitType _Flag0;

#define Flag0											(_Flag0.Word)
#define bDTCSetEnabledByVoltage							(_Flag0.Bits.BIT0)
#define bPowerUpSnsParHasBeenInited						(_Flag0.Bits.BIT1)
#define bGearOrSpeedSignalInvalid						(_Flag0.Bits.BIT3)
#define bUPASupposedToBeActive							(_Flag0.Bits.BIT4)
#define bPAPhyDisableSw									(_Flag0.Bits.BIT5)
#define bPAStatePASwitchDepressed						(_Flag0.Bits.BIT6)
#define bUPAInitialStateSwPressDownSincePowerUp			(_Flag0.Bits.BIT7)
#define bRamCheckFail									(_Flag0.Bits.BIT8)
#define bFlashRomCheckFinished							(_Flag0.Bits.BIT9)
#define bAppFlashRomCheckFinished						(_Flag0.Bits.BIT10)
#define bDisplayLEDPowerOverVoltage						(_Flag0.Bits.BIT11)
#define bFrontAndRearSensorDTCSetDisabled				(_Flag0.Bits.BIT12)
#define bSwitchSpeakerLEDDTCSetDisabled					(_Flag0.Bits.BIT13)

extern tWordBitType _Flag1;

#define Flag1                          					(_Flag1.Word)
#define bSnsNormalRingTimeChanged        				(_Flag1.Bits.BIT0)
#define bSnsDeltaRingTimeChanged						(_Flag1.Bits.BIT1)
#define bDTCDataChanged									(_Flag1.Bits.BIT2)
#define DATA_NEED_TO_BE_WRITTEN_TO_EEPROM_MASK			0x0007
#define bApplTrcvrSleep									(_Flag1.Bits.BIT3)
#define bDoNotSaveDTCDataToEEPROM						(_Flag1.Bits.BIT4)
#define bBatteryVoltageAbnormalShutDownSystem			(_Flag1.Bits.BIT5)
#define bSnsSpkLedPowerHasBeenDrived					(_Flag1.Bits.BIT6)
#define bSpkLedPowerAbnormal							(_Flag1.Bits.BIT7)
#define bSnsPowerAbnormal								(_Flag1.Bits.BIT8)
#define bSpkLedPowerDtcCheckDisabled					(_Flag1.Bits.BIT9)
#define bHighVoltageWakeUp100MsgRxd						(_Flag1.Bits.BIT10)
#define bApplTrcvrSleepConfirmed						(_Flag1.Bits.BIT11)
#define bESSReqRearSnsActive							(_Flag1.Bits.BIT12)
#define bHapticSeatFailed                           	(_Flag1.Bits.BIT13)
#define bSnsRingTimeCheckedAfterSpeedGoesDown			(_Flag1.Bits.BIT15)


extern tWordBitType _Flag2;
#define Flag2                          					(_Flag2.Word)
#define bAPARequestUPAEnterActive        				(_Flag2.Bits.BIT0)
#define bAPAStateAPASwitchDepressed						(_Flag2.Bits.BIT1)
#define bAPAStateAPASwitchLongDepressed					(_Flag2.Bits.BIT2)
#define bCANSignalInvalidDTCSet							(_Flag2.Bits.BIT3)
#define bSlotMirrorChange								(_Flag2.Bits.BIT4)  

#define bSDGFailed										(_Flag2.Bits.BIT6)
#define bSDGStateSDGSwitchPressed						(_Flag2.Bits.BIT7)
#define bCarTrafficLightTurnToLeft						(_Flag2.Bits.BIT8)
#define bCarTrafficLightTurnToRight						(_Flag2.Bits.BIT9)

#define bEEpromNeedToWritte								(_Flag2.Bits.BIT10)		
#define bDTCWriteToEEpromStart							(_Flag2.Bits.BIT11)		
#define bEEPROMPendingWriteStart						(_Flag2.Bits.BIT12)		
#define bEEPROMTaskActive								(_Flag2.Bits.BIT13)		
#define bDefaultParkingTestSwitchPress					(_Flag2.Bits.BIT14)		
#define bDefaultParkingTestActive						(_Flag2.Bits.BIT15)		


extern tWordBitType _Flag3;		
#define Flag3                          					(_Flag3.Word)
#ifdef SUPPORT_ONLY_CHECK_VIN_ONCE_WHEN_POWER_UP
#define bVINHasBeenCheckedSincePowerUp					(_Flag3.Bits.BIT0)
#endif
#define bSensorSpeakerLEDPowerDTCSetDisabled			(_Flag3.Bits.BIT1)
#define bDescPASwitchState								(_Flag3.Bits.BIT2)
#define bObjDetectTaskStart								(_Flag3.Bits.BIT4)		
#define bApaTaskStart									(_Flag3.Bits.BIT5)		
#define bUPASensorInitInhibit               			(_Flag3.Bits.BIT6)
#define bVehicleSpeedZoneChangeReqSnsInit				(_Flag3.Bits.BIT7) 
#define bFirsttimeofChangeTempDoneFlag               	(_Flag3.Bits.BIT8)
#define bFirsttimeOfTempZoneChangeReqSnsInit			(_Flag3.Bits.BIT9)		
#define bTemperatureZoneChangeReqSnsInit				(_Flag3.Bits.BIT10)	
#define bAPASysFailed									(_Flag3.Bits.BIT11)		
#define bUPASysFailed									(_Flag3.Bits.BIT12)		
#define bSBSASysFailed									(_Flag3.Bits.BIT13)		
#define bSnsRecoveryFromFailedReInitSns					(_Flag3.Bits.BIT14)
#define bPAFailedChimeCommandIsSent						(_Flag3.Bits.BIT15)



#define GEAR_SIGNAL_SELECT_TRANSMISSION_SHIFT_LEVER_POS_MASK	0x00
#define GEAR_SIGNAL_SELECT_VEHICLE_MOVEMENT_STATE_MASK			0x80
#define MEMORIZATION_CUSTOMIZATION_DISABLE_MASK					0x00
#define MEMORIZATION_CUSTOMIZATION_ENABLE_MASK					0x40
#define VEHICLE_WITHOUT_BI_DIR_WHEEL_SPD_SNS_MASK						0x00
#define NONDRIVEN_WHEELS_EQUIP_BI_DIR_WHEEL_SPD_SNS_MASK				0x10
#define DRIVEN_WHEELS_EQUIP_BI_DIR_WHEEL_SPD_SNS_MASK					0x20
#define DRIVEN_AND_NONDRIVEN_WHEELS_EQUIP_BI_DIR_WHEEL_SPD_SNS_MASK		0x30
#define UPA_STRATEGY_AUTOMATIC_MASK										0x00
#define UPA_STRATEGY_SEMIAUTOMATIC_MASK									0x04

#define UPA_WITH_REAR_ONLY_SYSTEM_MASK									0x00
#define UPA_WITH_FRONT_AND_REAR_SYSTEM_MASK								0x08

#define APA2_ACTIVATION_METHOD_APA2_BUTTON_AND_BUTTON_LONG_PRESS_MASK	0x00
#define APA2_ACTIVATION_METHOD_APA2_BUTTON_AND_TOUCH_SCREEN_MASK		0x01
#define APA2_ACTIVATION_METHOD_APA2_BUTTON_AND_SET_CLR_BUTTON_MASK		0x02
#define APA2_ACTIVATION_METHOD_SINGLE_BUTTON_AND_TOUCH_SCREEN_MASK		0x03

#define PARKING_BRAKE_SWITCH_DISABLED_MASK						0x00
#define PARKING_BRAKE_SWITCH_ENABLED_MASK					  	0x80

#define	MANUAL_GEAR_BOX_MASK									0x00
#define AUTO_GEAR_BOX_MASK										0x02

#define DRIVEN_WHEEL_FRONT_MASK									0x00
#define DRIVEN_WHEEL_REAR_OR_4X4_OR_ALL_WHEEL_DRIVEN_MASK		0x04

#define PA_ENABLE_DISABLE_METHOD_ALWAYS_ENABLE_MASK 			0x00
#define PA_ENABLE_DISABLE_METHOD_PH_SW_MASK         			0x08
#define PA_ENABLE_DISABLE_METHOD_VEHICLE_MENU_MASK  			0x10
#define PA_ENABLE_DISABLE_METHOD_PH_SW_AND_VEHICLE_MENU_MASK 	0x18
#define PA_ENABLE_DISABLE_METHOD_ESS_CONTROLLER_MASK 			0x20

#define STEERING_LOCATION_LEFT_MASK								0x00
#define STEERING_LOCATION_RIGHT_MASK							0x40

#define UPA_STRATEGY_AUTOMATIC_MASK										0x00
#define UPA_STRATEGY_SEMIAUTOMATIC_MASK									0x04

#define UPA_WITH_REAR_ONLY_SYSTEM_MASK									0x00
#define UPA_WITH_FRONT_AND_REAR_SYSTEM_MASK								0x08

#define VEHICLE_WITHOUT_BI_DIR_WHEEL_SPD_SNS_MASK						0x00
#define NONDRIVEN_WHEELS_EQUIP_BI_DIR_WHEEL_SPD_SNS_MASK				0x10
#define DRIVEN_WHEELS_EQUIP_BI_DIR_WHEEL_SPD_SNS_MASK					0x20
#define DRIVEN_AND_NONDRIVEN_WHEELS_EQUIP_BI_DIR_WHEEL_SPD_SNS_MASK		0x30

#define MEMORIZATION_CUSTOMIZATION_DISABLE_MASK					0x00
#define MEMORIZATION_CUSTOMIZATION_ENABLE_MASK					0x40

#define GEAR_SIGNAL_SELECT_TRANSMISSION_SHIFT_LEVER_POS_MASK	0x00
#define GEAR_SIGNAL_SELECT_VEHICLE_MOVEMENT_STATE_MASK			0x80


#define PA_DISABLE_METHOD_ALWAYS_ENABLE									0
#define PA_DISABLE_METHOD_PHYSICAL_SWITCH								1
#define PA_DISABLE_METHOD_VEHICLE_MENU									2
#define PA_DISABLE_METHOD_VEHICLE_MENU_PHY_SW							3
#define PA_DISABLE_METHOD_ESS_CONTROLLER								4

#define APA2_ACTIVATION_METHOD_APA2_BUTTON_AND_BUTTON_LONG_PRESS		0
#define APA2_ACTIVATION_METHOD_APA2_BUTTON_AND_TOUCH_SCREEN				1
#define APA2_ACTIVATION_METHOD_APA2_BUTTON_AND_SET_CLR_BUTTON			2
#define APA2_ACTIVATION_METHOD_SINGLE_BUTTON_AND_TOUCH_SCREEN			3

#define SPEED_SIGNAL_TYPE_NON_DRIVEN									0
#define SPEED_SIGNAL_TYPE_DRIVEN										1

#define GEAR_SIGNAL_SELECT_TRANSMISSION_SHIFT_LEVER_POS					0
#define GEAR_SIGNAL_SELECT_VEHICLE_MOVEMENT_STATE						1

#define UPA_STRATEGY_AUTOMATIC											0
#define UPA_STRATEGY_SEMIAUTOMATIC										1

#define STEERING_LOCATION_LEFT											0
#define STEERING_LOCATION_RIGHT											1

typedef union {
	word	wFlag;
	struct {
		word Bit0: 1;
		word Bit1: 1;
		word Bit2: 1;
		word Bit3: 1;
		word Bit4: 1;
		word Bit5: 1;
		word Bit6: 1;
		word Bit7: 1;
		word Bit8: 1;
		word Bit9: 1;
		word Bit10: 1;
		word Bit11: 1;
		word Bit12: 1;
		word Bit13: 1;
		word Bit14: 1;
		word Bit15: 1;
	} Bits;
} tAppGmlanFlagType;



extern       tAppGmlanFlagType AppGmlanFlag;
#define bSpeakerChimeCmdSigSending									AppGmlanFlag.Bits.Bit8



#define TOTAL_MONITOR_SIGNAL_NUM								5
#define SysPwrMdSigTimeOutIndex									0
#define SysBkupPwrMdSigTimeOutIndex							1
#define TrnsVDASigTimeOutIndex									2
#define PrkBrkVDASigTimeOutIndex						    3
#define EngCtrlVDASigTimeOutIndex								4

typedef struct{
	uchar	APAMaxParkingSpeedInGuidenceMode;
	uchar	APAOutSideAirTemperatureInGuidenceMode;
}_EEPROMVehicleSpeedandOutsideAirTemperature;

extern volatile _EEPROMVehicleSpeedandOutsideAirTemperature EEPROMVehicleSpeedAndOutsideAirTemperature;



typedef struct _c_UUDT_Resp_From_UPA_APA_LS_msgTypeTag
{
  unsigned char DgnInf_LS559_7 : 8;
  unsigned char DgnInf_LS559_6 : 8;
  unsigned char DgnInf_LS559_5 : 8;
  unsigned char DgnInf_LS559_4 : 8;
  unsigned char DgnInf_LS559_3 : 8;
  unsigned char DgnInf_LS559_2 : 8;
  unsigned char DgnInf_LS559_1 : 8;
  unsigned char DgnInf_LS559_0 : 8;
} _c_UUDT_Resp_From_UPA_APA_LS_msgType;
typedef struct _c_USDT_Resp_From_UPA_APA_LS_msgTypeTag
{
  unsigned char DgnInf_0_7 : 8;
  unsigned char DgnInf_0_6 : 8;
  unsigned char DgnInf_0_5 : 8;
  unsigned char DgnInf_0_4 : 8;
  unsigned char DgnInf_0_3 : 8;
  unsigned char DgnInf_0_2 : 8;
  unsigned char DgnInf_0_1 : 8;
  unsigned char DgnInf_0_0 : 8;
} _c_USDT_Resp_From_UPA_APA_LS_msgType;
typedef struct _c_Teen_Driver_Control_Info_LS_msgTypeTag
{
  unsigned char unused0 : 8;
  unsigned char unused1 : 8;
  unsigned char unused2 : 8;
  unsigned char unused3 : 8;
  unsigned char unused4 : 1;
  unsigned char TeenDrvAct : 1;
  unsigned char unused5 : 6;
} _c_Teen_Driver_Control_Info_LS_msgType;
typedef struct _c_Park_Assist_ESSprocess_Info_LS_msgTypeTag
{
  unsigned char unused0 : 3;
  unsigned char PrkAstOprtrDsrdStat : 2;
  unsigned char PrkAstRrObjSnsngRqAct : 1;
  unsigned char PrkAstInhbtReq : 1;
  unsigned char ClsnMtgtnInhbtd : 1;
} _c_Park_Assist_ESSprocess_Info_LS_msgType;
typedef struct _c_Park_Assist_ESSbased_Info_LS_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char PrkAstRrSysStatUnfltd : 2;
  unsigned char PrkAstRrExtdDstUnfltd_1 : 4;
  unsigned char PrkAstRrExtdDstUnfltd_0 : 8;
  unsigned char unused1 : 1;
  unsigned char PrkAstRrObjSnsngAct : 1;
  unsigned char ClsnMtgtnInhbtReqtd : 1;
  unsigned char PrkAstFntnClnPrkAstIO : 1;
  unsigned char PrkAstFntnDsbldIO : 1;
  unsigned char PrkAstFntnFld : 1;
  unsigned char PrkAstFntnSnrsBlkd : 1;
  unsigned char PrkAstFntnSnsDstrbdIO : 1;
  unsigned char PARrRgn4ObjStatUnfltd : 4;
  unsigned char PARrRgn3ObjStatUnfltd : 4;
  unsigned char PARrRgn2ObjStatUnfltd : 4;
  unsigned char PARrRgn1ObjStatUnfltd : 4;
} _c_Park_Assist_ESSbased_Info_LS_msgType;
typedef struct _c_Park_Assistant_Right_Status_LS_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char PrkAstRtSysStat : 2;
  unsigned char PARtRgn1ObjStat : 4;
  unsigned char PARtRgn2ObjStat : 4;
  unsigned char PARtRgn3ObjStat : 4;
} _c_Park_Assistant_Right_Status_LS_msgType;
typedef struct _c_Park_Assistant_Left_Status_LS_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char PrkAstLtSysStat : 2;
  unsigned char PALtRgn1ObjStat : 4;
  unsigned char PALtRgn2ObjStat : 4;
  unsigned char PALtRgn3ObjStat : 4;
} _c_Park_Assistant_Left_Status_LS_msgType;
typedef struct _c_Haptic_Seat_Status_LS_msgTypeTag
{
  unsigned char unused0 : 4;
  unsigned char HptcStVbnStat : 2;
  unsigned char CrshAlrtStPrsnt : 1;
  unsigned char CrshAlrtDrvrSlctdType : 1;
} _c_Haptic_Seat_Status_LS_msgType;
typedef struct _c_Frnt_Prk_Ast_Drv_Seat_Vib_Req_LS_msgTypeTag
{
  unsigned char FPAHptcStVbnReq : 6;
  unsigned char FPAHptcStVbnRqSeqN : 2;
} _c_Frnt_Prk_Ast_Drv_Seat_Vib_Req_LS_msgType;
typedef struct _c_Rear_Prk_Ast_Drv_Seat_Vib_Req_LS_msgTypeTag
{
  unsigned char RPAHptcStVbnReq : 6;
  unsigned char RPAHptcStVbRqSeqN : 2;
} _c_Rear_Prk_Ast_Drv_Seat_Vib_Req_LS_msgType;
typedef struct _c_Analog_Values_Slow_LS_msgTypeTag
{
  unsigned char unused0 : 3;
  unsigned char OAT_PT_EstM : 1;
  unsigned char OAT_PT_EstV : 1;
  unsigned char unused1 : 1;
  unsigned char EngIntAirTmpV : 1;
  unsigned char EngCltTmpV : 1;
  unsigned char unused2 : 8;
  unsigned char unused3 : 8;
  unsigned char unused4 : 8;
  unsigned char OAT_PT_Est : 8;
  unsigned char unused5 : 8;
  unsigned char EngIntAirTmp : 8;
  unsigned char EngCltTmp : 8;
} _c_Analog_Values_Slow_LS_msgType;
typedef struct _c_Analog_Values_Slow_LS_EngCltTmpGroup_msgTypeTag
{
  unsigned char unused0 : 3;
  unsigned char cunused11 : 5;
  unsigned char cunused10 : 8;
  unsigned char cunused9 : 8;
  unsigned char cunused8 : 8;
  unsigned char cunused7 : 8;
  unsigned char cunused1 : 8;
  unsigned char cunused0 : 8;
  unsigned char EngCltTmpGroup_0 : 8;
} _c_Analog_Values_Slow_LS_EngCltTmpGroup_msgType;
typedef struct _c_Analog_Values_Slow_LS_EngIntAirTmpGroup_msgTypeTag
{
  unsigned char unused0 : 3;
  unsigned char cunused12 : 5;
  unsigned char cunused11 : 8;
  unsigned char cunused10 : 8;
  unsigned char cunused9 : 8;
  unsigned char cunused8 : 8;
  unsigned char EngIntAirTmpGroup_1 : 8;
  unsigned char EngIntAirTmpGroup_0 : 8;
  unsigned char cunused0 : 8;
} _c_Analog_Values_Slow_LS_EngIntAirTmpGroup_msgType;
typedef struct _c_Analog_Values_Slow_LS_OAT_PT_EstGroup_msgTypeTag
{
  unsigned char unused0 : 3;
  unsigned char OAT_PT_EstGroup_4 : 5;
  unsigned char OAT_PT_EstGroup_3 : 8;
  unsigned char OAT_PT_EstGroup_2 : 8;
  unsigned char OAT_PT_EstGroup_1 : 8;
  unsigned char OAT_PT_EstGroup_0 : 8;
  unsigned char cunused9 : 8;
  unsigned char cunused8 : 8;
  unsigned char cunused0 : 8;
} _c_Analog_Values_Slow_LS_OAT_PT_EstGroup_msgType;
typedef struct _c_Wheel_Pulses_LS_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char WhlPlsPerRevDrvn_0 : 7;
  unsigned char unused1 : 1;
  unsigned char WhlPlsPerRevNonDrvn_0 : 7;
} _c_Wheel_Pulses_LS_msgType;
typedef struct _c_ODIIndication_LS_msgTypeTag
{
  unsigned char ODII_FUCID : 8;
  unsigned char ODII_ODIInd1 : 1;
  unsigned char ODII_ODIInd2 : 1;
  unsigned char ODII_ODIInd3 : 1;
  unsigned char ODII_ODIInd4 : 1;
  unsigned char ODII_ODIInd5 : 1;
  unsigned char ODII_ODIInd6 : 1;
  unsigned char ODII_ODIInd7 : 1;
  unsigned char ODII_ODIInd8 : 1;
  unsigned char ODII_ODIInd9 : 1;
  unsigned char ODII_ODIInd10 : 1;
  unsigned char ODII_ODIInd11 : 1;
  unsigned char ODII_ODIInd12 : 1;
  unsigned char ODII_ODIInd13 : 1;
  unsigned char ODII_ODIInd14 : 1;
  unsigned char ODII_ODIInd15 : 1;
  unsigned char ODII_ODIInd16 : 1;
  unsigned char ODII_ODIInd17 : 1;
  unsigned char ODII_ODIInd18 : 1;
  unsigned char ODII_ODIInd19 : 1;
  unsigned char ODII_ODIInd20 : 1;
  unsigned char ODII_ODIInd21 : 1;
  unsigned char ODII_ODIInd22 : 1;
  unsigned char ODII_ODIInd23 : 1;
  unsigned char ODII_ODIInd24 : 1;
  unsigned char ODII_ODIInd25 : 1;
  unsigned char ODII_ODIInd26 : 1;
  unsigned char ODII_ODIInd27 : 1;
  unsigned char ODII_ODIInd28 : 1;
  unsigned char ODII_ODIInd29 : 1;
  unsigned char ODII_ODIInd30 : 1;
  unsigned char ODII_ODIInd31 : 1;
  unsigned char ODII_ODIInd32 : 1;
  unsigned char ODII_ODIInd33 : 1;
  unsigned char ODII_ODIInd34 : 1;
  unsigned char ODII_ODIInd35 : 1;
  unsigned char ODII_ODIInd36 : 1;
  unsigned char ODII_ODIInd37 : 1;
  unsigned char ODII_ODIInd38 : 1;
  unsigned char ODII_ODIInd39 : 1;
  unsigned char ODII_ODIInd40 : 1;
  unsigned char ODII_ODIInd41 : 1;
  unsigned char ODII_ODIInd42 : 1;
  unsigned char ODII_ODIInd43 : 1;
  unsigned char ODII_ODIInd44 : 1;
  unsigned char ODII_ODIInd45 : 1;
  unsigned char ODII_ODIInd46 : 1;
  unsigned char ODII_ODIInd47 : 1;
  unsigned char ODII_ODIInd48 : 1;
  unsigned char ODII_ODIInd49 : 1;
  unsigned char ODII_ODIInd50 : 1;
  unsigned char ODII_ODIInd51 : 1;
  unsigned char ODII_ODIInd52 : 1;
  unsigned char ODII_ODIInd53 : 1;
  unsigned char ODII_ODIInd54 : 1;
  unsigned char ODII_ODIInd55 : 1;
  unsigned char ODII_ODIInd56 : 1;
} _c_ODIIndication_LS_msgType;
typedef struct _c_ODIIndication_LS_ODIInd_msgTypeTag
{
  unsigned char ODIInd_7 : 8;
  unsigned char ODIInd_6 : 8;
  unsigned char ODIInd_5 : 8;
  unsigned char ODIInd_4 : 8;
  unsigned char ODIInd_3 : 8;
  unsigned char ODIInd_2 : 8;
  unsigned char ODIInd_1 : 8;
  unsigned char ODIInd_0 : 8;
} _c_ODIIndication_LS_ODIInd_msgType;
typedef struct _c_ODIEvent_LS_msgTypeTag
{
  unsigned char unused0 : 8;
  unsigned char unused1 : 2;
  unsigned char ODIE_EvID : 6;
  unsigned char ODIE_FUCID : 8;
  unsigned char ODIE_MultiFrRetCh : 8;
} _c_ODIEvent_LS_msgType;
typedef struct _c_ODIEvent_LS_ODIEvntPkt_msgTypeTag
{
  unsigned char unused0 : 8;
  unsigned char unused1 : 2;
  unsigned char ODIEvntPkt_2 : 6;
  unsigned char ODIEvntPkt_1 : 8;
  unsigned char ODIEvntPkt_0 : 8;
} _c_ODIEvent_LS_ODIEvntPkt_msgType;
typedef struct _c_Infrastructure_Timer_Status_LS_msgTypeTag
{
  unsigned char unused0 : 7;
  unsigned char EngOffTmExtRngV : 1;
  unsigned char unused1 : 8;
  unsigned char unused2 : 8;
  unsigned char unused3 : 8;
  unsigned char EngOffTmExtRng : 8;
} _c_Infrastructure_Timer_Status_LS_msgType;
typedef struct _c_Infrastructure_Timer_Status_LS_EngOffTmExtRngGroup_msgTypeTag
{
  unsigned char unused0 : 7;
  unsigned char EngOffTmExtRngGroup_4 : 1;
  unsigned char EngOffTmExtRngGroup_3 : 8;
  unsigned char EngOffTmExtRngGroup_2 : 8;
  unsigned char EngOffTmExtRngGroup_1 : 8;
  unsigned char EngOffTmExtRngGroup_0 : 8;
} _c_Infrastructure_Timer_Status_LS_EngOffTmExtRngGroup_msgType;
typedef struct _c_Park_Assistant_General_Status_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char TnDrvPrkAstOffUnbIO : 1;
  unsigned char PrkAstSnsDistrbdIO : 1;
  unsigned char PrkAstSnrsBlk : 1;
  unsigned char PrkAstFld : 1;
  unsigned char PrkAsstDisablIO : 1;
  unsigned char PrkAsstClnPrkAstIO : 1;
} _c_Park_Assistant_General_Status_msgType;
typedef struct _c_Chime_Active_msgTypeTag
{
  unsigned char unused0 : 7;
  unsigned char ChmAct : 1;
} _c_Chime_Active_msgType;
typedef struct _c_ODIDynamicData_LS_msgTypeTag
{
  unsigned char unused0 : 8;
  unsigned char unused1 : 1;
  unsigned char ODD_DataType : 6;
  unsigned char ODD_InvldData : 1;
  unsigned char ODD_FUCID : 8;
  unsigned char ODD_DataId : 8;
  unsigned char ODD_DataVal_3 : 8;
  unsigned char ODD_DataVal_2 : 8;
  unsigned char ODD_DataVal_1 : 8;
  unsigned char ODD_DataVal_0 : 8;
} _c_ODIDynamicData_LS_msgType;
typedef struct _c_ODIDynamicData_LS_ODIDynData_msgTypeTag
{
  unsigned char unused0 : 8;
  unsigned char unused1 : 1;
  unsigned char ODIDynData_6 : 7;
  unsigned char ODIDynData_5 : 8;
  unsigned char ODIDynData_4 : 8;
  unsigned char ODIDynData_3 : 8;
  unsigned char ODIDynData_2 : 8;
  unsigned char ODIDynData_1 : 8;
  unsigned char ODIDynData_0 : 8;
} _c_ODIDynamicData_LS_ODIDynData_msgType;
typedef struct _c_ODIEnumDynamicData_LS_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIEDD_Data1Value : 3;
  unsigned char ODIEDD_Data2Value : 3;
  unsigned char ODIEDD_Data3Value : 3;
  unsigned char ODIEDD_Data4Value : 3;
  unsigned char ODIEDD_Data5Value_1 : 2;
  unsigned char ODIEDD_Data5Value_0 : 1;
  unsigned char ODIEDD_Data6Value : 3;
  unsigned char ODIEDD_Data7Value : 3;
  unsigned char ODIEDD_Data8Value_1 : 1;
  unsigned char ODIEDD_Data8Value_0 : 2;
  unsigned char ODIEDD_Data9Value : 3;
  unsigned char ODIEDD_Data10Value : 3;
  unsigned char ODIEDD_Data11Value : 3;
  unsigned char ODIEDD_Data12Value : 3;
  unsigned char ODIEDD_Data13Value_1 : 2;
  unsigned char ODIEDD_Data13Value_0 : 1;
  unsigned char ODIEDD_Data14Value : 3;
  unsigned char ODIEDD_Data15Value : 3;
  unsigned char ODIEDD_Data16Value_1 : 1;
  unsigned char ODIEDD_Data16Value_0 : 2;
  unsigned char ODIEDD_Data17Value : 3;
  unsigned char ODIEDD_Data18Value : 3;
  unsigned char ODIEDD_FUCID : 8;
} _c_ODIEnumDynamicData_LS_msgType;
typedef struct _c_ODIEnumDynamicData_LS_ODIEnmDynData_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIEnmDynData_7 : 6;
  unsigned char ODIEnmDynData_6 : 8;
  unsigned char ODIEnmDynData_5 : 8;
  unsigned char ODIEnmDynData_4 : 8;
  unsigned char ODIEnmDynData_3 : 8;
  unsigned char ODIEnmDynData_2 : 8;
  unsigned char ODIEnmDynData_1 : 8;
  unsigned char ODIEnmDynData_0 : 8;
} _c_ODIEnumDynamicData_LS_ODIEnmDynData_msgType;
typedef struct _c_ODIAction_CntrStack_LS_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIAC_DaTy : 6;
  unsigned char ODIAC_FUCID : 8;
  unsigned char ODIAC_ActnID : 8;
  unsigned char ODIAC_DspMID : 8;
  unsigned char ODIAC_ActnVal_3 : 8;
  unsigned char ODIAC_ActnVal_2 : 8;
  unsigned char ODIAC_ActnVal_1 : 8;
  unsigned char ODIAC_ActnVal_0 : 8;
} _c_ODIAction_CntrStack_LS_msgType;
typedef struct _c_ODIAction_CntrStack_LS_ODIActn_CntrStck_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIActn_CntrStck_7 : 6;
  unsigned char ODIActn_CntrStck_6 : 8;
  unsigned char ODIActn_CntrStck_5 : 8;
  unsigned char ODIActn_CntrStck_4 : 8;
  unsigned char ODIActn_CntrStck_3 : 8;
  unsigned char ODIActn_CntrStck_2 : 8;
  unsigned char ODIActn_CntrStck_1 : 8;
  unsigned char ODIActn_CntrStck_0 : 8;
} _c_ODIAction_CntrStack_LS_ODIActn_CntrStck_msgType;
typedef struct _c_Man_Prk_Brk_LS_msgTypeTag
{
  unsigned char unused0 : 5;
  unsigned char PrkBrkSwAtv : 1;
  unsigned char unused1 : 2;
} _c_Man_Prk_Brk_LS_msgType;
typedef struct _c_Vehicle_Stability_LS_msgTypeTag
{
  unsigned char StWhAnVDA : 1;
  unsigned char StrWhAngV_0 : 1;
  unsigned char VSEAct : 1;
  unsigned char unused0 : 1;
  unsigned char TCSysAtv : 1;
  unsigned char VSELongAccLoResV : 1;
  unsigned char VSELongAccLoRes_1 : 2;
  unsigned char VSELongAccLoRes_0 : 8;
  unsigned char StrWhlAngSenCalStat_0 : 2;
  unsigned char unused1 : 3;
  unsigned char VehStabEnhmntStat : 3;
  unsigned char unused2 : 2;
  unsigned char TCSysOpStat : 3;
  unsigned char unused3 : 3;
  unsigned char StrWhAng_0_1 : 8;
  unsigned char StrWhAng_0_0 : 8;
} _c_Vehicle_Stability_LS_msgType;
typedef struct _c_Vehicle_Stability_LS_VSELongAccLoResGroup_msgTypeTag
{
  unsigned char cunused8 : 1;
  unsigned char unused0 : 1;
  unsigned char cunused1 : 1;
  unsigned char unused1 : 1;
  unsigned char cunused0 : 1;
  unsigned char VSELongAccLoResGroup_1 : 3;
  unsigned char VSELongAccLoResGroup_0 : 8;
  unsigned char cunused10 : 2;
  unsigned char unused2 : 3;
  unsigned char cunused9 : 3;
  unsigned char unused3 : 2;
  unsigned char cunused11 : 3;
  unsigned char unused4 : 3;
  unsigned char cunused3 : 8;
  unsigned char cunused2 : 8;
} _c_Vehicle_Stability_LS_VSELongAccLoResGroup_msgType;
typedef struct _c_Vehicle_Stability_LS_StrWhAngGroup_0_msgTypeTag
{
  unsigned char cunused4 : 1;
  unsigned char unused0 : 1;
  unsigned char cunused3 : 1;
  unsigned char unused1 : 1;
  unsigned char cunused2 : 1;
  unsigned char cunused1 : 3;
  unsigned char cunused0 : 8;
  unsigned char cunused6 : 2;
  unsigned char unused2 : 3;
  unsigned char cunused5 : 3;
  unsigned char unused3 : 2;
  unsigned char cunused7 : 3;
  unsigned char unused4 : 3;
  unsigned char StrWhAngGroup_0_1 : 8;
  unsigned char StrWhAngGroup_0_0 : 8;
} _c_Vehicle_Stability_LS_StrWhAngGroup_0_msgType;
typedef struct _c_Wheel_Grnd_Velocity_LS_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char WhlGrndVlctyLftDrvnV_0 : 1;
  unsigned char WhlGrndVlctyLftDrvn_0_1 : 6;
  unsigned char WhlGrndVlctyLftDrvn_0_0 : 8;
  unsigned char unused1 : 1;
  unsigned char WhlGrndVlctyLftNnDrvnV_0 : 1;
  unsigned char WhlGrndVlctyLftNnDrvn_0_1 : 6;
  unsigned char WhlGrndVlctyLftNnDrvn_0_0 : 8;
  unsigned char unused2 : 1;
  unsigned char WhlGrndVlctyRtDrvnV_0 : 1;
  unsigned char WhlGrndVlctyRtDrvn_0_1 : 6;
  unsigned char WhlGrndVlctyRtDrvn_0_0 : 8;
  unsigned char unused3 : 1;
  unsigned char WhlGrndVlctyRtNnDrvnV_0 : 1;
  unsigned char WhlGrndVlctyRtNnDrvn_0_1 : 6;
  unsigned char WhlGrndVlctyRtNnDrvn_0_0 : 8;
} _c_Wheel_Grnd_Velocity_LS_msgType;
typedef struct _c_Wheel_Grnd_Velocity_LS_WhlGrndVlctyLftDrvnGroup_0_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char WhlGrndVlctyLftDrvnGroup_0_1 : 7;
  unsigned char WhlGrndVlctyLftDrvnGroup_0_0 : 8;
  unsigned char unused1 : 1;
  unsigned char cunused1 : 7;
  unsigned char cunused0 : 8;
  unsigned char unused2 : 1;
  unsigned char cunused3 : 7;
  unsigned char cunused2 : 8;
  unsigned char unused3 : 1;
  unsigned char cunused5 : 7;
  unsigned char cunused4 : 8;
} _c_Wheel_Grnd_Velocity_LS_WhlGrndVlctyLftDrvnGroup_0_msgType;
typedef struct _c_Wheel_Grnd_Velocity_LS_WhlGrndVlctyLftNnDrvnGroup_0_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char cunused1 : 7;
  unsigned char cunused0 : 8;
  unsigned char unused1 : 1;
  unsigned char WhlGrndVlctyLftNnDrvnGroup_0_1 : 7;
  unsigned char WhlGrndVlctyLftNnDrvnGroup_0_0 : 8;
  unsigned char unused2 : 1;
  unsigned char cunused3 : 7;
  unsigned char cunused2 : 8;
  unsigned char unused3 : 1;
  unsigned char cunused5 : 7;
  unsigned char cunused4 : 8;
} _c_Wheel_Grnd_Velocity_LS_WhlGrndVlctyLftNnDrvnGroup_0_msgType;
typedef struct _c_Wheel_Grnd_Velocity_LS_WhlGrndVlctyRtDrvnGroup_0_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char cunused1 : 7;
  unsigned char cunused0 : 8;
  unsigned char unused1 : 1;
  unsigned char cunused3 : 7;
  unsigned char cunused2 : 8;
  unsigned char unused2 : 1;
  unsigned char WhlGrndVlctyRtDrvnGroup_0_1 : 7;
  unsigned char WhlGrndVlctyRtDrvnGroup_0_0 : 8;
  unsigned char unused3 : 1;
  unsigned char cunused5 : 7;
  unsigned char cunused4 : 8;
} _c_Wheel_Grnd_Velocity_LS_WhlGrndVlctyRtDrvnGroup_0_msgType;
typedef struct _c_Wheel_Grnd_Velocity_LS_WhlGrndVlctyRtNnDrvnGroup_0_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char cunused1 : 7;
  unsigned char cunused0 : 8;
  unsigned char unused1 : 1;
  unsigned char cunused3 : 7;
  unsigned char cunused2 : 8;
  unsigned char unused2 : 1;
  unsigned char cunused5 : 7;
  unsigned char cunused4 : 8;
  unsigned char unused3 : 1;
  unsigned char WhlGrndVlctyRtNnDrvnGroup_0_1 : 7;
  unsigned char WhlGrndVlctyRtNnDrvnGroup_0_0 : 8;
} _c_Wheel_Grnd_Velocity_LS_WhlGrndVlctyRtNnDrvnGroup_0_msgType;
typedef struct _c_Non_Drvn_Whl_Rot_Status_LS_msgTypeTag
{
  unsigned char WRSLNDWhlDisTpRC_0 : 2;
  unsigned char WRSLNDSeqNum_0 : 2;
  unsigned char WRSLNDWhlRotStRst_0 : 1;
  unsigned char WRSLNDWhlDistVal_0 : 1;
  unsigned char WRSLNDWhlDistPCntr_0_1 : 2;
  unsigned char WRSLNDWhlDistPCntr_0_0 : 8;
  unsigned char WRSLNDWhlDistTstm_0_1 : 8;
  unsigned char WRSLNDWhlDistTstm_0_0 : 8;
  unsigned char WRSRNDWhlDisTpRC_0 : 2;
  unsigned char WRSRNDSeqNum_0 : 2;
  unsigned char WRSRNDWhlRotStRst_0 : 1;
  unsigned char WRSRNDWhlDistVal_0 : 1;
  unsigned char WRSRNDWhlDistPCntr_0_1 : 2;
  unsigned char WRSRNDWhlDistPCntr_0_0 : 8;
  unsigned char WRSRNDWhlDistTstm_0_1 : 8;
  unsigned char WRSRNDWhlDistTstm_0_0 : 8;
} _c_Non_Drvn_Whl_Rot_Status_LS_msgType;
typedef struct _c_Non_Drvn_Whl_Rot_Status_LS_WhlRotStatLftNDrvn_0_msgTypeTag
{
  unsigned char WhlRotStatLftNDrvn_0_3 : 8;
  unsigned char WhlRotStatLftNDrvn_0_2 : 8;
  unsigned char WhlRotStatLftNDrvn_0_1 : 8;
  unsigned char WhlRotStatLftNDrvn_0_0 : 8;
  unsigned char cunused3 : 8;
  unsigned char cunused2 : 8;
  unsigned char cunused1 : 8;
  unsigned char cunused0 : 8;
} _c_Non_Drvn_Whl_Rot_Status_LS_WhlRotStatLftNDrvn_0_msgType;
typedef struct _c_Non_Drvn_Whl_Rot_Status_LS_WhlRotStatRghtNDrvn_0_msgTypeTag
{
  unsigned char cunused3 : 8;
  unsigned char cunused2 : 8;
  unsigned char cunused1 : 8;
  unsigned char cunused0 : 8;
  unsigned char WhlRotStatRghtNDrvn_0_3 : 8;
  unsigned char WhlRotStatRghtNDrvn_0_2 : 8;
  unsigned char WhlRotStatRghtNDrvn_0_1 : 8;
  unsigned char WhlRotStatRghtNDrvn_0_0 : 8;
} _c_Non_Drvn_Whl_Rot_Status_LS_WhlRotStatRghtNDrvn_0_msgType;
typedef struct _c_Driven_Whl_Rotational_Stat_LS_msgTypeTag
{
  unsigned char WRSLDWhlDisTpRC_0 : 2;
  unsigned char WRSLDSeqNum_0 : 2;
  unsigned char WRSLDWhlRotStatRst_0 : 1;
  unsigned char WRSLDWhlDistVal_0 : 1;
  unsigned char WRSLDWhlDistPlsCntr_0_1 : 2;
  unsigned char WRSLDWhlDistPlsCntr_0_0 : 8;
  unsigned char WRSLDWhlDistTmstm_0_1 : 8;
  unsigned char WRSLDWhlDistTmstm_0_0 : 8;
  unsigned char WRSRDWhlDisTpRC_0 : 2;
  unsigned char WRSRDSeqNum_0 : 2;
  unsigned char WRSRDWhlRotStatRst_0 : 1;
  unsigned char WRSRDWhlDistVal_0 : 1;
  unsigned char WRSRDWhlDistPlsCntr_0_1 : 2;
  unsigned char WRSRDWhlDistPlsCntr_0_0 : 8;
  unsigned char WRSRDWhlDistTmstm_0_1 : 8;
  unsigned char WRSRDWhlDistTmstm_0_0 : 8;
} _c_Driven_Whl_Rotational_Stat_LS_msgType;
typedef struct _c_Driven_Whl_Rotational_Stat_LS_WhlRotatStatLftDrvn_0_msgTypeTag
{
  unsigned char WhlRotatStatLftDrvn_0_3 : 8;
  unsigned char WhlRotatStatLftDrvn_0_2 : 8;
  unsigned char WhlRotatStatLftDrvn_0_1 : 8;
  unsigned char WhlRotatStatLftDrvn_0_0 : 8;
  unsigned char cunused3 : 8;
  unsigned char cunused2 : 8;
  unsigned char cunused1 : 8;
  unsigned char cunused0 : 8;
} _c_Driven_Whl_Rotational_Stat_LS_WhlRotatStatLftDrvn_0_msgType;
typedef struct _c_Driven_Whl_Rotational_Stat_LS_WhlRotatStatRtDrvn_0_msgTypeTag
{
  unsigned char cunused3 : 8;
  unsigned char cunused2 : 8;
  unsigned char cunused1 : 8;
  unsigned char cunused0 : 8;
  unsigned char WhlRotatStatRtDrvn_0_3 : 8;
  unsigned char WhlRotatStatRtDrvn_0_2 : 8;
  unsigned char WhlRotatStatRtDrvn_0_1 : 8;
  unsigned char WhlRotatStatRtDrvn_0_0 : 8;
} _c_Driven_Whl_Rotational_Stat_LS_WhlRotatStatRtDrvn_0_msgType;
typedef struct _c_Power_Mode_Info_LS_msgTypeTag
{
  unsigned char TrStLgMdAtv : 1;
  unsigned char unused0 : 7;
  unsigned char unused1 : 5;
  unsigned char VehMovState : 3;
} _c_Power_Mode_Info_LS_msgType;
typedef struct _c_Park_Assistant_Rear_Status_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char PrkAstRrSysStat : 2;
  unsigned char PrkAsstRrExtdDist_1 : 4;
  unsigned char PrkAsstRrExtdDist_0 : 8;
  unsigned char PARrRgn2ObjStat : 4;
  unsigned char PARrRgn1ObjStat : 4;
  unsigned char PARrRgn4ObjStat : 4;
  unsigned char PARrRgn3ObjStat : 4;
} _c_Park_Assistant_Rear_Status_msgType;
typedef struct _c_Park_Assistant_Front_Status_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char PrkAstAdvSysAct : 1;
  unsigned char PrkAstFrSysStat : 2;
  unsigned char PrkAsstFrtExtdDist_1 : 4;
  unsigned char PrkAsstFrtExtdDist_0 : 8;
  unsigned char PAFrtRgn2ObjStat : 4;
  unsigned char PAFrtRgn1ObjStat : 4;
  unsigned char PAFrtRgn4ObjStat : 4;
  unsigned char PAFrtRgn3ObjStat : 4;
} _c_Park_Assistant_Front_Status_msgType;
typedef struct _c_Chassis_Information_LS_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ABSAtv : 1;
  unsigned char unused1 : 5;
  unsigned char BrkSysVDA : 1;
  unsigned char unused2 : 2;
  unsigned char PrkBrkVDA : 1;
  unsigned char unused3 : 4;
  unsigned char unused4 : 5;
  unsigned char SprTireSt : 3;
  unsigned char unused5 : 8;
  unsigned char ElecPrkBrkStat : 2;
  unsigned char unused6 : 6;
} _c_Chassis_Information_LS_msgType;
typedef struct _c_ODIDynDataMultiRequest_AuxIP_LS_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODDMA_ReqType : 2;
  unsigned char ODDMA_DataID5Vld : 1;
  unsigned char ODDMA_DataID4Vld : 1;
  unsigned char ODDMA_DataID3Vld : 1;
  unsigned char ODDMA_DataID2Vld : 1;
  unsigned char ODDMA_FUCID : 8;
  unsigned char ODDMA_DispMID : 8;
  unsigned char ODDMA_DataID1 : 8;
  unsigned char ODDMA_DataID2 : 8;
  unsigned char ODDMA_DataID3 : 8;
  unsigned char ODDMA_DataID4 : 8;
  unsigned char ODDMA_DataID5 : 8;
} _c_ODIDynDataMultiRequest_AuxIP_LS_msgType;
typedef struct _c_ODIDynDataMultiRequest_AuxIP_LS_ODIDynDataMltRq_AuxIP_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIDynDataMltRq_AuxIP_7 : 6;
  unsigned char ODIDynDataMltRq_AuxIP_6 : 8;
  unsigned char ODIDynDataMltRq_AuxIP_5 : 8;
  unsigned char ODIDynDataMltRq_AuxIP_4 : 8;
  unsigned char ODIDynDataMltRq_AuxIP_3 : 8;
  unsigned char ODIDynDataMltRq_AuxIP_2 : 8;
  unsigned char ODIDynDataMltRq_AuxIP_1 : 8;
  unsigned char ODIDynDataMltRq_AuxIP_0 : 8;
} _c_ODIDynDataMultiRequest_AuxIP_LS_ODIDynDataMltRq_AuxIP_msgType;
typedef struct _c_ODIDynDataMultiReq_CntrStack_LS_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODDMC_ReqType : 2;
  unsigned char ODDMC_DataID5Vld : 1;
  unsigned char ODDMC_DataID4Vld : 1;
  unsigned char ODDMC_DataID3Vld : 1;
  unsigned char ODDMC_DataID2Vld : 1;
  unsigned char ODDMC_FUCID : 8;
  unsigned char ODDMC_DispMID : 8;
  unsigned char ODDMC_DataID1 : 8;
  unsigned char ODDMC_DataID2 : 8;
  unsigned char ODDMC_DataID3 : 8;
  unsigned char ODDMC_DataID4 : 8;
  unsigned char ODDMC_DataID5 : 8;
} _c_ODIDynDataMultiReq_CntrStack_LS_msgType;
typedef struct _c_ODIDynDataMultiReq_CntrStack_LS_ODIDynDataMltRq_CntrStck_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIDynDataMltRq_CntrStck_7 : 6;
  unsigned char ODIDynDataMltRq_CntrStck_6 : 8;
  unsigned char ODIDynDataMltRq_CntrStck_5 : 8;
  unsigned char ODIDynDataMltRq_CntrStck_4 : 8;
  unsigned char ODIDynDataMltRq_CntrStck_3 : 8;
  unsigned char ODIDynDataMltRq_CntrStck_2 : 8;
  unsigned char ODIDynDataMltRq_CntrStck_1 : 8;
  unsigned char ODIDynDataMltRq_CntrStck_0 : 8;
} _c_ODIDynDataMultiReq_CntrStack_LS_ODIDynDataMltRq_CntrStck_msgType;
typedef struct _c_ODIDynDataMultiRequest_IPC_LS_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODDMI_ReqType : 2;
  unsigned char ODDMI_DataID5Vld : 1;
  unsigned char ODDMI_DataID4Vld : 1;
  unsigned char ODDMI_DataID3Vld : 1;
  unsigned char ODDMI_DataID2Vld : 1;
  unsigned char ODDMI_FUCID : 8;
  unsigned char ODDMI_DispMID : 8;
  unsigned char ODDMI_DataID1 : 8;
  unsigned char ODDMI_DataID2 : 8;
  unsigned char ODDMI_DataID3 : 8;
  unsigned char ODDMI_DataID4 : 8;
  unsigned char ODDMI_DataID5 : 8;
} _c_ODIDynDataMultiRequest_IPC_LS_msgType;
typedef struct _c_ODIDynDataMultiRequest_IPC_LS_ODIDynDataMltRq_IPC_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIDynDataMltRq_IPC_7 : 6;
  unsigned char ODIDynDataMltRq_IPC_6 : 8;
  unsigned char ODIDynDataMltRq_IPC_5 : 8;
  unsigned char ODIDynDataMltRq_IPC_4 : 8;
  unsigned char ODIDynDataMltRq_IPC_3 : 8;
  unsigned char ODIDynDataMltRq_IPC_2 : 8;
  unsigned char ODIDynDataMltRq_IPC_1 : 8;
  unsigned char ODIDynDataMltRq_IPC_0 : 8;
} _c_ODIDynDataMultiRequest_IPC_LS_ODIDynDataMltRq_IPC_msgType;
typedef struct _c_Outside_Air_Temperature_LS_msgTypeTag
{
  unsigned char unused0 : 5;
  unsigned char OtsAirTmpCrValMsk : 1;
  unsigned char OtsAirTmpV : 1;
  unsigned char OtsAirTmpCrValV : 1;
  unsigned char OtsAirTmpCrVal : 8;
  unsigned char OtsAirTmp : 8;
} _c_Outside_Air_Temperature_LS_msgType;
typedef struct _c_Outside_Air_Temperature_LS_OtsAirTmpCrValGroup_msgTypeTag
{
  unsigned char unused0 : 5;
  unsigned char cunused3 : 1;
  unsigned char unused1 : 1;
  unsigned char OtsAirTmpCrValGroup_1 : 1;
  unsigned char OtsAirTmpCrValGroup_0 : 8;
  unsigned char cunused0 : 8;
} _c_Outside_Air_Temperature_LS_OtsAirTmpCrValGroup_msgType;
typedef struct _c_Outside_Air_Temperature_LS_OtsAirTmpGroup_msgTypeTag
{
  unsigned char unused0 : 5;
  unsigned char cunused2 : 1;
  unsigned char unused1 : 1;
  unsigned char cunused1 : 1;
  unsigned char cunused0 : 8;
  unsigned char OtsAirTmpGroup_0 : 8;
} _c_Outside_Air_Temperature_LS_OtsAirTmpGroup_msgType;
typedef struct _c_Trailer_Status_LS_msgTypeTag
{
  unsigned char unused0 : 7;
  unsigned char TrlrHtchSwAtv : 1;
  unsigned char unused1 : 2;
  unsigned char RrEndCrrStat : 1;
  unsigned char unused2 : 5;
} _c_Trailer_Status_LS_msgType;
typedef struct _c_ACC_YawRate_Information_LS_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char ACCAct370 : 1;
  unsigned char unused1 : 6;
  unsigned char unused2 : 8;
  unsigned char unused3 : 8;
  unsigned char unused4 : 8;
  unsigned char unused5 : 3;
  unsigned char VehDynYawRateV : 1;
  unsigned char VehDynYawRate_1 : 4;
  unsigned char VehDynYawRate_0 : 8;
} _c_ACC_YawRate_Information_LS_msgType;
typedef struct _c_ACC_YawRate_Information_LS_VehDynYawRateGroup_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char cunused0 : 1;
  unsigned char unused1 : 6;
  unsigned char unused2 : 8;
  unsigned char unused3 : 8;
  unsigned char unused4 : 8;
  unsigned char unused5 : 3;
  unsigned char VehDynYawRateGroup_1 : 5;
  unsigned char VehDynYawRateGroup_0 : 8;
} _c_ACC_YawRate_Information_LS_VehDynYawRateGroup_msgType;
typedef struct _c_Side_Blind_Zone_Alert_Status_msgTypeTag
{
  unsigned char unused0 : 4;
  unsigned char SBZATmpUnvIndOn : 1;
  unsigned char SBZASysSrvIndOn : 1;
  unsigned char SBZASysOffIndOn : 1;
  unsigned char SBZASysClnIndOn : 1;
} _c_Side_Blind_Zone_Alert_Status_msgType;
typedef struct _c_VIN_Digits_10_to_17_msgTypeTag
{
  unsigned char VehIdNmDig10_17_7 : 8;
  unsigned char VehIdNmDig10_17_6 : 8;
  unsigned char VehIdNmDig10_17_5 : 8;
  unsigned char VehIdNmDig10_17_4 : 8;
  unsigned char VehIdNmDig10_17_3 : 8;
  unsigned char VehIdNmDig10_17_2 : 8;
  unsigned char VehIdNmDig10_17_1 : 8;
  unsigned char VehIdNmDig10_17_0 : 8;
} _c_VIN_Digits_10_to_17_msgType;
typedef struct _c_VIN_Digits_2_to_9_msgTypeTag
{
  unsigned char VehIdNmDig2_9_7 : 8;
  unsigned char VehIdNmDig2_9_6 : 8;
  unsigned char VehIdNmDig2_9_5 : 8;
  unsigned char VehIdNmDig2_9_4 : 8;
  unsigned char VehIdNmDig2_9_3 : 8;
  unsigned char VehIdNmDig2_9_2 : 8;
  unsigned char VehIdNmDig2_9_1 : 8;
  unsigned char VehIdNmDig2_9_0 : 8;
} _c_VIN_Digits_2_to_9_msgType;
typedef struct _c_DTC_Triggered_msgTypeTag
{
  unsigned char DTCIUnused7 : 1;
  unsigned char DTCIUnused6 : 1;
  unsigned char DTCIUnused5 : 1;
  unsigned char DTCIUnused4 : 1;
  unsigned char DTCIUnused3 : 1;
  unsigned char DTCIUnused2 : 1;
  unsigned char DTCIUnused1 : 1;
  unsigned char DTCI_DTCTriggered : 1;
  unsigned char DTCI_DTCSource : 8;
  unsigned char DTCI_DTCNumber_1 : 8;
  unsigned char DTCI_DTCNumber_0 : 8;
  unsigned char DTCI_DTCFailType : 8;
  unsigned char DTCI_WrnIndRqdSt : 1;
  unsigned char DTCI_TstFldPwrUpSt : 1;
  unsigned char DTCI_TstNPsdPwrUpSt : 1;
  unsigned char DTCI_HistStat : 1;
  unsigned char DTCI_TstFldCdClrdStat : 1;
  unsigned char DTCI_TstNPsdCdClrdSt : 1;
  unsigned char DTCI_CurrentStatus : 1;
  unsigned char DTCI_CodeSupported : 1;
  unsigned char DTCI_DTCFaultType : 8;
} _c_DTC_Triggered_msgType;
typedef struct _c_DTC_Triggered_DTCInfo_msgTypeTag
{
  unsigned char DTCInfo_6 : 8;
  unsigned char DTCInfo_5 : 8;
  unsigned char DTCInfo_4 : 8;
  unsigned char DTCInfo_3 : 8;
  unsigned char DTCInfo_2 : 8;
  unsigned char DTCInfo_1 : 8;
  unsigned char DTCInfo_0 : 8;
} _c_DTC_Triggered_DTCInfo_msgType;
typedef struct _c_Chime_Command_msgTypeTag
{
  unsigned char SC_SndTne : 4;
  unsigned char SndLocRtRr : 1;
  unsigned char SndLocLftRr : 1;
  unsigned char SndLocPasFr : 1;
  unsigned char SndLocDrFr : 1;
  unsigned char SC_SndCdnPrd : 8;
  unsigned char SC_NmofRp : 8;
  unsigned char SC_SndDutCyc : 8;
  unsigned char SndPriority : 8;
} _c_Chime_Command_msgType;
typedef struct _c_Chime_Command_SndChrs_msgTypeTag
{
  unsigned char cunused0 : 4;
  unsigned char SndChrs_3 : 4;
  unsigned char SndChrs_2 : 8;
  unsigned char SndChrs_1 : 8;
  unsigned char SndChrs_0 : 8;
  unsigned char cunused1 : 8;
} _c_Chime_Command_SndChrs_msgType;
typedef struct _c_Chime_Command_SndLoc_msgTypeTag
{
  unsigned char SndLoc : 4;
  unsigned char cunused3 : 4;
  unsigned char cunused2 : 8;
  unsigned char cunused1 : 8;
  unsigned char cunused0 : 8;
  unsigned char cunused4 : 8;
} _c_Chime_Command_SndLoc_msgType;
typedef struct _c_System_Power_Mode_Backup_LS_msgTypeTag
{
  unsigned char unused0 : 4;
  unsigned char SysBkUpPwrMdV : 1;
  unsigned char SysBkupPwrMdEn : 1;
  unsigned char SysBkUpPwrMd : 2;
} _c_System_Power_Mode_Backup_LS_msgType;
typedef struct _c_System_Power_Mode_Backup_LS_SysBkUpPwrMdGroup_msgTypeTag
{
  unsigned char unused0 : 5;
  unsigned char cunused0 : 1;
  unsigned char unused1 : 2;
} _c_System_Power_Mode_Backup_LS_SysBkUpPwrMdGroup_msgType;
typedef struct _c_ODIAction_IPC_LS_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIAI_DaTy : 6;
  unsigned char ODIAI_FUCID : 8;
  unsigned char ODIAI_ActnID : 8;
  unsigned char ODIAI_DspMID : 8;
  unsigned char ODIAI_ActnVal_3 : 8;
  unsigned char ODIAI_ActnVal_2 : 8;
  unsigned char ODIAI_ActnVal_1 : 8;
  unsigned char ODIAI_ActnVal_0 : 8;
} _c_ODIAction_IPC_LS_msgType;
typedef struct _c_ODIAction_IPC_LS_ODIActn_IPC_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIActn_IPC_7 : 6;
  unsigned char ODIActn_IPC_6 : 8;
  unsigned char ODIActn_IPC_5 : 8;
  unsigned char ODIActn_IPC_4 : 8;
  unsigned char ODIActn_IPC_3 : 8;
  unsigned char ODIActn_IPC_2 : 8;
  unsigned char ODIActn_IPC_1 : 8;
  unsigned char ODIActn_IPC_0 : 8;
} _c_ODIAction_IPC_LS_ODIActn_IPC_msgType;
typedef struct _c_ODIAction_AuxIP_LS_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIAA_DaTy : 6;
  unsigned char ODIAA_FUCID : 8;
  unsigned char ODIAA_ActnID : 8;
  unsigned char ODIAA_DspMID : 8;
  unsigned char ODIAA_ActnVal_3 : 8;
  unsigned char ODIAA_ActnVal_2 : 8;
  unsigned char ODIAA_ActnVal_1 : 8;
  unsigned char ODIAA_ActnVal_0 : 8;
} _c_ODIAction_AuxIP_LS_msgType;
typedef struct _c_ODIAction_AuxIP_LS_ODIActn_AxIP_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIActn_AxIP_7 : 6;
  unsigned char ODIActn_AxIP_6 : 8;
  unsigned char ODIActn_AxIP_5 : 8;
  unsigned char ODIActn_AxIP_4 : 8;
  unsigned char ODIActn_AxIP_3 : 8;
  unsigned char ODIActn_AxIP_2 : 8;
  unsigned char ODIActn_AxIP_1 : 8;
  unsigned char ODIActn_AxIP_0 : 8;
} _c_ODIAction_AuxIP_LS_ODIActn_AxIP_msgType;
typedef struct _c_Engine_Information_2_LS_msgTypeTag
{
  unsigned char unused0 : 8;
  unsigned char unused1 : 7;
  unsigned char EngRunAtv : 1;
  unsigned char TrnsVDA : 1;
  unsigned char EngVDA : 1;
  unsigned char unused2 : 6;
} _c_Engine_Information_2_LS_msgType;
typedef struct _c_Engine_Information_1_LS_msgTypeTag
{
  unsigned char unused0 : 8;
  unsigned char TrnsShftLvrPosV_0 : 1;
  unsigned char unused1 : 7;
  unsigned char unused2 : 8;
  unsigned char unused3 : 8;
  unsigned char unused4 : 8;
  unsigned char unused5 : 8;
  unsigned char unused6 : 4;
  unsigned char TrnsShftLvrPos_0 : 4;
} _c_Engine_Information_1_LS_msgType;
typedef struct _c_Engine_Information_1_LS_TrnsShftLvrPosGroup_0_msgTypeTag
{
  unsigned char unused0 : 8;
  unsigned char TrnsShftLvrPosGroup_0_5 : 8;
  unsigned char TrnsShftLvrPosGroup_0_4 : 8;
  unsigned char TrnsShftLvrPosGroup_0_3 : 8;
  unsigned char TrnsShftLvrPosGroup_0_2 : 8;
  unsigned char TrnsShftLvrPosGroup_0_1 : 8;
  unsigned char TrnsShftLvrPosGroup_0_0 : 8;
} _c_Engine_Information_1_LS_TrnsShftLvrPosGroup_0_msgType;
typedef struct _c_Driver_Door_Status_msgTypeTag
{
  unsigned char DDAjrSwAtvM : 1;
  unsigned char unused0 : 6;
  unsigned char DDAjrSwAtv : 1;
} _c_Driver_Door_Status_msgType;
typedef struct _c_Driver_Door_Status_DDAjrSwAtvGroup_msgTypeTag
{
  unsigned char DDAjrSwAtvGroup : 8;
} _c_Driver_Door_Status_DDAjrSwAtvGroup_msgType;
typedef struct _c_Lighting_Status_LS_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char TrnSwAct : 2;
  unsigned char unused1 : 2;
  unsigned char HazSwAtv : 1;
  unsigned char unused2 : 1;
  unsigned char OtsdAmbtLtLvlStatV : 1;
  unsigned char unused3 : 8;
  unsigned char unused4 : 8;
  unsigned char unused5 : 2;
  unsigned char LftTrnLmpAtv : 2;
  unsigned char OtsdAmbtLtLvlStat : 2;
  unsigned char RtTrnLmpAtv : 2;
} _c_Lighting_Status_LS_msgType;
typedef struct _c_Lighting_Status_LS_OtsdAmbtLtLvlStatGroup_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char cunused1 : 2;
  unsigned char unused1 : 2;
  unsigned char cunused0 : 1;
  unsigned char unused2 : 1;
  unsigned char OtsdAmbtLtLvlStatGroup_3 : 1;
  unsigned char OtsdAmbtLtLvlStatGroup_2 : 8;
  unsigned char OtsdAmbtLtLvlStatGroup_1 : 8;
  unsigned char unused3 : 2;
  unsigned char cunused3 : 2;
  unsigned char unused4 : 2;
  unsigned char cunused2 : 2;
} _c_Lighting_Status_LS_OtsdAmbtLtLvlStatGroup_msgType;
typedef struct _c_Vehicle_Speed_Information_msgTypeTag
{
  unsigned char VehSpdAvgDrvnV : 1;
  unsigned char VehSpdAvgDrvn_1 : 7;
  unsigned char VehSpdAvgDrvn_0 : 8;
  unsigned char unused0 : 1;
  unsigned char DistRollCntAvgDrvnV : 1;
  unsigned char unused1 : 1;
  unsigned char DistRollCntAvgDrvn_1 : 5;
  unsigned char DistRollCntAvgDrvn_0 : 8;
  unsigned char unused2 : 1;
  unsigned char VehSpdAvgNDrvn_1 : 7;
  unsigned char VehSpdAvgNDrvn_0 : 8;
  unsigned char unused3 : 1;
  unsigned char VehSpdAvgNDrvnV : 1;
  unsigned char unused4 : 6;
} _c_Vehicle_Speed_Information_msgType;
typedef struct _c_Vehicle_Speed_Information_VehSpdAvgDrvnGroup_msgTypeTag
{
  unsigned char VehSpdAvgDrvnGroup_1 : 8;
  unsigned char VehSpdAvgDrvnGroup_0 : 8;
  unsigned char unused0 : 1;
  unsigned char cunused1 : 7;
  unsigned char cunused0 : 8;
  unsigned char unused1 : 1;
  unsigned char cunused4 : 7;
  unsigned char cunused3 : 8;
  unsigned char cunused2 : 2;
  unsigned char unused2 : 6;
} _c_Vehicle_Speed_Information_VehSpdAvgDrvnGroup_msgType;
typedef struct _c_Vehicle_Speed_Information_DistRollCntAvgDrvnGroup_msgTypeTag
{
  unsigned char cunused1 : 8;
  unsigned char cunused0 : 8;
  unsigned char unused0 : 1;
  unsigned char DistRollCntAvgDrvnGroup_1 : 7;
  unsigned char DistRollCntAvgDrvnGroup_0 : 8;
  unsigned char unused1 : 1;
  unsigned char cunused4 : 7;
  unsigned char cunused3 : 8;
  unsigned char cunused2 : 2;
  unsigned char unused2 : 6;
} _c_Vehicle_Speed_Information_DistRollCntAvgDrvnGroup_msgType;
typedef struct _c_Vehicle_Speed_Information_VehSpdAvgNDrvnGroup_msgTypeTag
{
  unsigned char cunused1 : 8;
  unsigned char cunused0 : 8;
  unsigned char unused0 : 1;
  unsigned char cunused3 : 7;
  unsigned char cunused2 : 8;
  unsigned char unused1 : 1;
  unsigned char VehSpdAvgNDrvnGroup_2 : 7;
  unsigned char VehSpdAvgNDrvnGroup_1 : 8;
  unsigned char VehSpdAvgNDrvnGroup_0 : 2;
  unsigned char unused2 : 6;
} _c_Vehicle_Speed_Information_VehSpdAvgNDrvnGroup_msgType;
typedef struct _c_System_Power_Mode_LS_msgTypeTag
{
  unsigned char unused0 : 5;
  unsigned char SysPwrMdV : 1;
  unsigned char SysPwrMd : 2;
} _c_System_Power_Mode_LS_msgType;
typedef struct _c_System_Power_Mode_LS_SysPwrMdGroup_msgTypeTag
{
  unsigned char unused0 : 5;
  unsigned char SysPwrMdGroup : 3;
} _c_System_Power_Mode_LS_SysPwrMdGroup_msgType;
typedef struct _c_UUDT_Resp_From_APA_CE_msgTypeTag
{
  unsigned char DgnInf_CE559_7 : 8;
  unsigned char DgnInf_CE559_6 : 8;
  unsigned char DgnInf_CE559_5 : 8;
  unsigned char DgnInf_CE559_4 : 8;
  unsigned char DgnInf_CE559_3 : 8;
  unsigned char DgnInf_CE559_2 : 8;
  unsigned char DgnInf_CE559_1 : 8;
  unsigned char DgnInf_CE559_0 : 8;
} _c_UUDT_Resp_From_APA_CE_msgType;
typedef struct _c_USDT_Resp_From_APA_CE_msgTypeTag
{
  unsigned char DgnInf_1_7 : 8;
  unsigned char DgnInf_1_6 : 8;
  unsigned char DgnInf_1_5 : 8;
  unsigned char DgnInf_1_4 : 8;
  unsigned char DgnInf_1_3 : 8;
  unsigned char DgnInf_1_2 : 8;
  unsigned char DgnInf_1_1 : 8;
  unsigned char DgnInf_1_0 : 8;
} _c_USDT_Resp_From_APA_CE_msgType;
typedef struct _c_Trans_General_Status_2_CE_msgTypeTag
{
  unsigned char TrnsShftLvrPosV_1 : 1;
  unsigned char unused0 : 7;
  unsigned char unused1 : 8;
  unsigned char unused2 : 1;
  unsigned char TrnsShftLvrPos_1 : 4;
  unsigned char unused3 : 3;
} _c_Trans_General_Status_2_CE_msgType;
typedef struct _c_Trans_General_Status_2_CE_TrnsShftLvrPosGroup_1_msgTypeTag
{
  unsigned char TrnsShftLvrPosGroup_1_2 : 8;
  unsigned char TrnsShftLvrPosGroup_1_1 : 8;
  unsigned char TrnsShftLvrPosGroup_1_0 : 5;
  unsigned char unused0 : 3;
} _c_Trans_General_Status_2_CE_TrnsShftLvrPosGroup_1_msgType;
typedef struct _c_NonDriven_Wheel_Grnd_Velocity_CE_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char WhlGrndVlctyLftNnDrvnV_1 : 1;
  unsigned char WhlGrndVlctyLftNnDrvn_1_1 : 6;
  unsigned char WhlGrndVlctyLftNnDrvn_1_0 : 8;
  unsigned char unused1 : 1;
  unsigned char WhlGrndVlctyRtNnDrvnV_1 : 1;
  unsigned char WhlGrndVlctyRtNnDrvn_1_1 : 6;
  unsigned char WhlGrndVlctyRtNnDrvn_1_0 : 8;
  unsigned char unused2 : 1;
  unsigned char WhlPlsPerRevNonDrvn_1 : 7;
} _c_NonDriven_Wheel_Grnd_Velocity_CE_msgType;
typedef struct _c_NonDriven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyLftNnDrvnGroup_1_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char WhlGrndVlctyLftNnDrvnGroup_1_1 : 7;
  unsigned char WhlGrndVlctyLftNnDrvnGroup_1_0 : 8;
  unsigned char unused1 : 1;
  unsigned char cunused1 : 7;
  unsigned char cunused0 : 8;
  unsigned char unused2 : 1;
  unsigned char cunused2 : 7;
} _c_NonDriven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyLftNnDrvnGroup_1_msgType;
typedef struct _c_NonDriven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyRtNnDrvnGroup_1_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char cunused1 : 7;
  unsigned char cunused0 : 8;
  unsigned char unused1 : 1;
  unsigned char WhlGrndVlctyRtNnDrvnGroup_1_1 : 7;
  unsigned char WhlGrndVlctyRtNnDrvnGroup_1_0 : 8;
  unsigned char unused2 : 1;
  unsigned char cunused2 : 7;
} _c_NonDriven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyRtNnDrvnGroup_1_msgType;
typedef struct _c_Driven_Wheel_Grnd_Velocity_CE_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char WhlGrndVlctyLftDrvnV_1 : 1;
  unsigned char WhlGrndVlctyLftDrvn_1_1 : 6;
  unsigned char WhlGrndVlctyLftDrvn_1_0 : 8;
  unsigned char unused1 : 1;
  unsigned char WhlGrndVlctyRtDrvnV_1 : 1;
  unsigned char WhlGrndVlctyRtDrvn_1_1 : 6;
  unsigned char WhlGrndVlctyRtDrvn_1_0 : 8;
  unsigned char unused2 : 1;
  unsigned char WhlPlsPerRevDrvn_1 : 7;
} _c_Driven_Wheel_Grnd_Velocity_CE_msgType;
typedef struct _c_Driven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyLftDrvnGroup_1_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char WhlGrndVlctyLftDrvnGroup_1_1 : 7;
  unsigned char WhlGrndVlctyLftDrvnGroup_1_0 : 8;
  unsigned char unused1 : 1;
  unsigned char cunused1 : 7;
  unsigned char cunused0 : 8;
  unsigned char unused2 : 1;
  unsigned char cunused2 : 7;
} _c_Driven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyLftDrvnGroup_1_msgType;
typedef struct _c_Driven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyRtDrvnGroup_1_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char cunused1 : 7;
  unsigned char cunused0 : 8;
  unsigned char unused1 : 1;
  unsigned char WhlGrndVlctyRtDrvnGroup_1_1 : 7;
  unsigned char WhlGrndVlctyRtDrvnGroup_1_0 : 8;
  unsigned char unused2 : 1;
  unsigned char cunused2 : 7;
} _c_Driven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyRtDrvnGroup_1_msgType;
typedef struct _c_PPEI_Steering_Wheel_Angle_CE_msgTypeTag
{
  unsigned char StrWhAngV_1 : 1;
  unsigned char StrWhlAngSenCalStat_1 : 2;
  unsigned char unused0 : 2;
  unsigned char StrWhAngMsk : 1;
  unsigned char unused1 : 2;
  unsigned char StrWhAng_1_1 : 8;
  unsigned char StrWhAng_1_0 : 8;
  unsigned char StrWhAngGrdV : 1;
  unsigned char StWhlAngAliveRollCnt : 2;
  unsigned char unused2 : 1;
  unsigned char StrWhAngGrd_1 : 4;
  unsigned char StrWhAngGrd_0 : 8;
  unsigned char unused3 : 8;
  unsigned char unused4 : 5;
  unsigned char StrAngSnsChksm_1 : 3;
  unsigned char StrAngSnsChksm_0 : 8;
} _c_PPEI_Steering_Wheel_Angle_CE_msgType;
typedef struct _c_PPEI_Steering_Wheel_Angle_CE_StrWhAngGroup_1_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char cunused1 : 2;
  unsigned char unused1 : 2;
  unsigned char cunused0 : 1;
  unsigned char unused2 : 2;
  unsigned char StrWhAngGroup_1_1 : 8;
  unsigned char StrWhAngGroup_1_0 : 8;
  unsigned char unused3 : 1;
  unsigned char cunused2 : 2;
  unsigned char unused4 : 5;
  unsigned char cunused3 : 8;
  unsigned char unused5 : 8;
  unsigned char unused6 : 5;
  unsigned char cunused6 : 3;
  unsigned char cunused5 : 8;
} _c_PPEI_Steering_Wheel_Angle_CE_StrWhAngGroup_1_msgType;
typedef struct _c_PPEI_Steering_Wheel_Angle_CE_StrWhAngGrdGroup_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char cunused1 : 2;
  unsigned char unused1 : 2;
  unsigned char cunused0 : 1;
  unsigned char unused2 : 2;
  unsigned char cunused3 : 8;
  unsigned char cunused2 : 8;
  unsigned char unused3 : 1;
  unsigned char cunused5 : 2;
  unsigned char unused4 : 5;
  unsigned char StrWhAngGrdGroup_0 : 8;
  unsigned char unused5 : 8;
  unsigned char unused6 : 5;
  unsigned char cunused7 : 3;
  unsigned char cunused6 : 8;
} _c_PPEI_Steering_Wheel_Angle_CE_StrWhAngGrdGroup_msgType;
typedef struct _c_Brake_Apply_Information_CE_msgTypeTag
{
  unsigned char unused0 : 8;
  unsigned char unused1 : 8;
  unsigned char unused2 : 8;
  unsigned char unused3 : 8;
  unsigned char unused4 : 8;
  unsigned char unused5 : 8;
  unsigned char unused6 : 5;
  unsigned char WhlRotStatTmstmpRes_1 : 3;
  unsigned char WhlRotStatTmstmpRes_0 : 8;
} _c_Brake_Apply_Information_CE_msgType;
typedef struct _c_NonDrivn_Whl_Rotationl_Stat_CE_msgTypeTag
{
  unsigned char WRSLNDWhlDisTpRC_1 : 2;
  unsigned char WRSLNDSeqNum_1 : 2;
  unsigned char WRSLNDWhlRotStRst_1 : 1;
  unsigned char WRSLNDWhlDistVal_1 : 1;
  unsigned char WRSLNDWhlDistPCntr_1_1 : 2;
  unsigned char WRSLNDWhlDistPCntr_1_0 : 8;
  unsigned char WRSLNDWhlDistTstm_1_1 : 8;
  unsigned char WRSLNDWhlDistTstm_1_0 : 8;
  unsigned char WRSRNDWhlDisTpRC_1 : 2;
  unsigned char WRSRNDSeqNum_1 : 2;
  unsigned char WRSRNDWhlRotStRst_1 : 1;
  unsigned char WRSRNDWhlDistVal_1 : 1;
  unsigned char WRSRNDWhlDistPCntr_1_1 : 2;
  unsigned char WRSRNDWhlDistPCntr_1_0 : 8;
  unsigned char WRSRNDWhlDistTstm_1_1 : 8;
  unsigned char WRSRNDWhlDistTstm_1_0 : 8;
} _c_NonDrivn_Whl_Rotationl_Stat_CE_msgType;
typedef struct _c_NonDrivn_Whl_Rotationl_Stat_CE_WhlRotStatLftNDrvn_1_msgTypeTag
{
  unsigned char WhlRotStatLftNDrvn_1_3 : 8;
  unsigned char WhlRotStatLftNDrvn_1_2 : 8;
  unsigned char WhlRotStatLftNDrvn_1_1 : 8;
  unsigned char WhlRotStatLftNDrvn_1_0 : 8;
  unsigned char cunused3 : 8;
  unsigned char cunused2 : 8;
  unsigned char cunused1 : 8;
  unsigned char cunused0 : 8;
} _c_NonDrivn_Whl_Rotationl_Stat_CE_WhlRotStatLftNDrvn_1_msgType;
typedef struct _c_NonDrivn_Whl_Rotationl_Stat_CE_WhlRotStatRghtNDrvn_1_msgTypeTag
{
  unsigned char cunused3 : 8;
  unsigned char cunused2 : 8;
  unsigned char cunused1 : 8;
  unsigned char cunused0 : 8;
  unsigned char WhlRotStatRghtNDrvn_1_3 : 8;
  unsigned char WhlRotStatRghtNDrvn_1_2 : 8;
  unsigned char WhlRotStatRghtNDrvn_1_1 : 8;
  unsigned char WhlRotStatRghtNDrvn_1_0 : 8;
} _c_NonDrivn_Whl_Rotationl_Stat_CE_WhlRotStatRghtNDrvn_1_msgType;
typedef struct _c_Driven_Whl_Rotational_Stat_CE_msgTypeTag
{
  unsigned char WRSLDWhlDisTpRC_1 : 2;
  unsigned char WRSLDSeqNum_1 : 2;
  unsigned char WRSLDWhlRotStatRst_1 : 1;
  unsigned char WRSLDWhlDistVal_1 : 1;
  unsigned char WRSLDWhlDistPlsCntr_1_1 : 2;
  unsigned char WRSLDWhlDistPlsCntr_1_0 : 8;
  unsigned char WRSLDWhlDistTmstm_1_1 : 8;
  unsigned char WRSLDWhlDistTmstm_1_0 : 8;
  unsigned char WRSRDWhlDisTpRC_1 : 2;
  unsigned char WRSRDSeqNum_1 : 2;
  unsigned char WRSRDWhlRotStatRst_1 : 1;
  unsigned char WRSRDWhlDistVal_1 : 1;
  unsigned char WRSRDWhlDistPlsCntr_1_1 : 2;
  unsigned char WRSRDWhlDistPlsCntr_1_0 : 8;
  unsigned char WRSRDWhlDistTmstm_1_1 : 8;
  unsigned char WRSRDWhlDistTmstm_1_0 : 8;
} _c_Driven_Whl_Rotational_Stat_CE_msgType;
typedef struct _c_Driven_Whl_Rotational_Stat_CE_WhlRotatStatLftDrvn_1_msgTypeTag
{
  unsigned char WhlRotatStatLftDrvn_1_3 : 8;
  unsigned char WhlRotatStatLftDrvn_1_2 : 8;
  unsigned char WhlRotatStatLftDrvn_1_1 : 8;
  unsigned char WhlRotatStatLftDrvn_1_0 : 8;
  unsigned char cunused3 : 8;
  unsigned char cunused2 : 8;
  unsigned char cunused1 : 8;
  unsigned char cunused0 : 8;
} _c_Driven_Whl_Rotational_Stat_CE_WhlRotatStatLftDrvn_1_msgType;
typedef struct _c_Driven_Whl_Rotational_Stat_CE_WhlRotatStatRtDrvn_1_msgTypeTag
{
  unsigned char cunused3 : 8;
  unsigned char cunused2 : 8;
  unsigned char cunused1 : 8;
  unsigned char cunused0 : 8;
  unsigned char WhlRotatStatRtDrvn_1_3 : 8;
  unsigned char WhlRotatStatRtDrvn_1_2 : 8;
  unsigned char WhlRotatStatRtDrvn_1_1 : 8;
  unsigned char WhlRotatStatRtDrvn_1_0 : 8;
} _c_Driven_Whl_Rotational_Stat_CE_WhlRotatStatRtDrvn_1_msgType;
typedef struct _c_Park_Assist_Parallel_CE_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char StrWhlTctlFdbkReqActProtVal : 2;
  unsigned char StrWhlTctlFdbkReqAct : 1;
  unsigned char unused1 : 1;
  unsigned char StrWhlTctlFdbkReqActRC : 2;
  unsigned char unused2 : 6;
  unsigned char SWAR_ReqAct : 1;
  unsigned char SWAR_ReqActV : 1;
  unsigned char SWAR_TrgtAng_1 : 8;
  unsigned char SWAR_TrgtAng_0 : 8;
  unsigned char unused3 : 4;
  unsigned char StrWhlAngReqARC : 2;
  unsigned char StrWhlAngReqPrtVal_2 : 2;
  unsigned char StrWhlAngReqPrtVal_1 : 8;
  unsigned char StrWhlAngReqPrtVal_0 : 8;
} _c_Park_Assist_Parallel_CE_msgType;
typedef struct _c_Park_Assist_Parallel_CE_StrWhlAngReq_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char cunused2 : 2;
  unsigned char cunused1 : 1;
  unsigned char unused1 : 1;
  unsigned char cunused0 : 2;
  unsigned char unused2 : 6;
  unsigned char StrWhlAngReq_2 : 2;
  unsigned char StrWhlAngReq_1 : 8;
  unsigned char StrWhlAngReq_0 : 8;
  unsigned char unused3 : 4;
  unsigned char cunused6 : 2;
  unsigned char cunused5 : 2;
  unsigned char cunused4 : 8;
  unsigned char cunused3 : 8;
} _c_Park_Assist_Parallel_CE_StrWhlAngReq_msgType;
typedef struct _c_Electric_Power_Steering_CE_msgTypeTag
{
  unsigned char DrvStrIntfrDetPrtVal : 2;
  unsigned char DrvStrIntfrDetARC : 2;
  unsigned char DrvStrIntfrDtcd : 1;
  unsigned char DrvStrIntfrDtcdV : 1;
  unsigned char ElecPwrStrAvalStat : 2;
  unsigned char unused0 : 4;
  unsigned char ElcPwrStrAvalStatPVal : 2;
  unsigned char ElcPwrStrAvalStatARC : 2;
} _c_Electric_Power_Steering_CE_msgType;
typedef struct _c_Electric_Power_Steering_CE_DrvStrIntfrDtcdGroup_msgTypeTag
{
  unsigned char cunused2 : 2;
  unsigned char cunused1 : 2;
  unsigned char DrvStrIntfrDtcdGroup : 2;
  unsigned char cunused0 : 2;
  unsigned char unused0 : 4;
  unsigned char cunused4 : 2;
  unsigned char cunused3 : 2;
} _c_Electric_Power_Steering_CE_DrvStrIntfrDtcdGroup_msgType;
typedef struct _c_HS_Information_1_CE_msgTypeTag
{
  unsigned char unused0 : 8;
  unsigned char unused1 : 8;
  unsigned char unused2 : 6;
  unsigned char WhlDistPrRevDrvn_1 : 2;
  unsigned char WhlDistPrRevDrvn_0 : 8;
  unsigned char unused3 : 6;
  unsigned char WhlDistPrRevNDrvn_1 : 2;
  unsigned char WhlDistPrRevNDrvn_0 : 8;
} _c_HS_Information_1_CE_msgType;
typedef struct _c_IMU_Yaw_Long_Acc_CE_msgTypeTag
{
  unsigned char unused0 : 4;
  unsigned char IMURollCntSec : 2;
  unsigned char unused1 : 2;
  unsigned char unused2 : 8;
  unsigned char unused3 : 2;
  unsigned char IMULonAccPriV : 1;
  unsigned char unused4 : 5;
  unsigned char unused5 : 8;
  unsigned char unused6 : 4;
  unsigned char IMULonAccPri_1 : 4;
  unsigned char IMULonAccPri_0 : 8;
  unsigned char unused7 : 5;
  unsigned char IMUChksumSec_1 : 3;
  unsigned char IMUChksumSec_0 : 8;
} _c_IMU_Yaw_Long_Acc_CE_msgType;
typedef struct _c_IMU_Yaw_Long_Acc_CE_IMULonAccPriGroup_msgTypeTag
{
  unsigned char unused0 : 4;
  unsigned char cunused0 : 2;
  unsigned char unused1 : 2;
  unsigned char unused2 : 8;
  unsigned char unused3 : 2;
  unsigned char IMULonAccPriGroup_3 : 6;
  unsigned char IMULonAccPriGroup_2 : 8;
  unsigned char IMULonAccPriGroup_1 : 8;
  unsigned char IMULonAccPriGroup_0 : 8;
  unsigned char unused4 : 5;
  unsigned char cunused2 : 3;
  unsigned char cunused1 : 8;
} _c_IMU_Yaw_Long_Acc_CE_IMULonAccPriGroup_msgType;
typedef struct _c_IMU_Yaw_Latitud_Acc_CE_msgTypeTag
{
  unsigned char IMULatAccPrimV : 1;
  unsigned char IMURollCntPri : 2;
  unsigned char IMUYawRtPri_1 : 5;
  unsigned char IMUYawRtPri_0 : 8;
  unsigned char unused0 : 2;
  unsigned char IMUYawRtPriV : 1;
  unsigned char unused1 : 5;
  unsigned char unused2 : 8;
  unsigned char unused3 : 8;
  unsigned char unused4 : 3;
  unsigned char IMULatAccPrim_1 : 5;
  unsigned char IMULatAccPrim_0 : 5;
  unsigned char IMUChksumPri_1 : 3;
  unsigned char IMUChksumPri_0 : 8;
} _c_IMU_Yaw_Latitud_Acc_CE_msgType;
typedef struct _c_IMU_Yaw_Latitud_Acc_CE_IMUYawRtPriGroup_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char cunused0 : 2;
  unsigned char IMUYawRtPriGroup_2 : 5;
  unsigned char IMUYawRtPriGroup_1 : 8;
  unsigned char IMUYawRtPriGroup_0 : 3;
  unsigned char unused1 : 5;
  unsigned char cunused4 : 8;
  unsigned char cunused3 : 8;
  unsigned char cunused2 : 8;
  unsigned char cunused1 : 5;
  unsigned char cunused9 : 3;
  unsigned char cunused8 : 8;
} _c_IMU_Yaw_Latitud_Acc_CE_IMUYawRtPriGroup_msgType;
typedef struct _c_IMU_Yaw_Latitud_Acc_CE_IMULatAccPrimGroup_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char cunused3 : 2;
  unsigned char cunused2 : 5;
  unsigned char cunused1 : 8;
  unsigned char cunused0 : 3;
  unsigned char unused1 : 5;
  unsigned char IMULatAccPrimGroup_3 : 8;
  unsigned char IMULatAccPrimGroup_2 : 8;
  unsigned char IMULatAccPrimGroup_1 : 8;
  unsigned char IMULatAccPrimGroup_0 : 5;
  unsigned char cunused5 : 3;
  unsigned char cunused4 : 8;
} _c_IMU_Yaw_Latitud_Acc_CE_IMULatAccPrimGroup_msgType;
typedef struct _c_SSAE_Debug_Msg_0F_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_0F_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_0F_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_0F_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_0F_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_0F_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_0F_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_0F_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_0F_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_0F_msgType;
typedef struct _c_SSAE_Debug_Msg_0E_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_0E_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_0E_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_0E_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_0E_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_0E_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_0E_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_0E_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_0E_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_0E_msgType;
typedef struct _c_SSAE_Debug_Msg_0D_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_0D_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_0D_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_0D_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_0D_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_0D_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_0D_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_0D_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_0D_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_0D_msgType;
typedef struct _c_SSAE_Debug_Msg_0C_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_0C_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_0C_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_0C_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_0C_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_0C_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_0C_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_0C_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_0C_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_0C_msgType;
typedef struct _c_SSAE_Debug_Msg_0B_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_0B_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_0B_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_0B_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_0B_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_0B_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_0B_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_0B_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_0B_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_0B_msgType;
typedef struct _c_SSAE_Debug_Msg_0A_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_0A_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_0A_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_0A_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_0A_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_0A_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_0A_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_0A_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_0A_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_0A_msgType;
typedef struct _c_SSAE_Debug_Msg_09_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_09_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_09_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_09_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_09_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_09_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_09_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_09_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_09_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_09_msgType;
typedef struct _c_SSAE_Debug_Msg_08_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_08_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_08_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_08_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_08_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_08_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_08_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_08_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_08_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_08_msgType;
typedef struct _c_SSAE_Debug_Msg_07_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_07_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_07_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_07_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_07_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_07_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_07_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_07_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_07_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_07_msgType;
typedef struct _c_SSAE_Debug_Msg_06_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_06_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_06_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_06_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_06_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_06_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_06_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_06_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_06_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_06_msgType;
typedef struct _c_SSAE_Debug_Msg_05_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_05_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_05_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_05_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_05_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_05_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_05_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_05_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_05_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_05_msgType;
typedef struct _c_SSAE_Debug_Msg_04_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_04_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_04_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_04_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_04_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_04_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_04_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_04_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_04_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_04_msgType;
typedef struct _c_SSAE_Debug_Msg_03_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_03_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_03_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_03_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_03_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_03_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_03_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_03_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_03_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_03_msgType;
typedef struct _c_SSAE_Debug_Msg_02_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_02_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_02_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_02_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_02_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_02_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_02_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_02_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_02_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_02_msgType;
typedef struct _c_SSAE_Debug_Msg_01_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_01_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_01_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_01_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_01_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_01_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_01_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_01_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_01_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_01_msgType;
typedef struct _c_SSAE_Debug_Msg_00_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_00_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_00_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_00_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_00_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_00_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_00_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_00_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_00_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_00_msgType;
typedef struct _c_SSAE_Debug_Msg_16_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_16_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_16_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_16_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_16_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_16_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_16_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_16_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_16_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_16_msgType;
typedef struct _c_SSAE_Debug_Msg_15_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_15_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_15_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_15_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_15_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_15_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_15_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_15_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_15_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_15_msgType;
typedef struct _c_SSAE_Debug_Msg_14_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_14_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_14_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_14_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_14_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_14_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_14_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_14_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_14_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_14_msgType;
typedef struct _c_SSAE_Debug_Msg_13_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_13_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_13_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_13_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_13_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_13_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_13_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_13_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_13_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_13_msgType;
typedef struct _c_SSAE_Debug_Msg_12_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_12_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_12_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_12_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_12_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_12_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_12_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_12_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_12_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_12_msgType;
typedef struct _c_SSAE_Debug_Msg_11_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_11_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_11_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_11_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_11_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_11_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_11_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_11_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_11_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_11_msgType;
typedef struct _c_SSAE_Debug_Msg_10_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_10_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_10_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_10_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_10_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_10_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_10_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_10_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_10_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_10_msgType;
typedef struct _c_SSAE_Debug_Msg_18_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_18_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_18_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_18_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_18_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_18_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_18_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_18_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_18_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_18_msgType;
typedef struct _c_SSAE_Debug_Msg_17_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_17_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_17_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_17_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_17_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_17_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_17_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_17_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_17_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_17_msgType;
typedef struct _c_SSAE_Debug_Msg_1A_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_1A_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_1A_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_1A_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_1A_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_1A_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_1A_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_1A_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_1A_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_1A_msgType;
typedef struct _c_SSAE_Debug_Msg_19_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_19_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_19_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_19_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_19_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_19_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_19_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_19_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_19_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_19_msgType;
typedef struct _c_SSAE_Debug_Msg_1B_msgTypeTag
{
  unsigned char SSAE_Debug_Msg_1B_Bytes_7 : 8;
  unsigned char SSAE_Debug_Msg_1B_Bytes_6 : 8;
  unsigned char SSAE_Debug_Msg_1B_Bytes_5 : 8;
  unsigned char SSAE_Debug_Msg_1B_Bytes_4 : 8;
  unsigned char SSAE_Debug_Msg_1B_Bytes_3 : 8;
  unsigned char SSAE_Debug_Msg_1B_Bytes_2 : 8;
  unsigned char SSAE_Debug_Msg_1B_Bytes_1 : 8;
  unsigned char SSAE_Debug_Msg_1B_Bytes_0 : 8;
} _c_SSAE_Debug_Msg_1B_msgType;
/* -----------------------------------------------------------------------------
    &&&~ Signal Structures for group signals
 ----------------------------------------------------------------------------- */

typedef struct _c_ODIDynData_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char ODD_DataType : 6;
  unsigned char ODD_InvldData : 1;
  unsigned char ODD_FUCID : 8;
  unsigned char ODD_DataId : 8;
  unsigned char ODD_DataVal_3 : 8;
  unsigned char ODD_DataVal_2 : 8;
  unsigned char ODD_DataVal_1 : 8;
  unsigned char ODD_DataVal_0 : 8;
} _c_ODIDynData_msgType;
typedef struct _c_ODIEnmDynData_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIEDD_Data1Value : 3;
  unsigned char ODIEDD_Data2Value : 3;
  unsigned char ODIEDD_Data3Value : 3;
  unsigned char ODIEDD_Data4Value : 3;
  unsigned char ODIEDD_Data5Value_1 : 2;
  unsigned char ODIEDD_Data5Value_0 : 1;
  unsigned char ODIEDD_Data6Value : 3;
  unsigned char ODIEDD_Data7Value : 3;
  unsigned char ODIEDD_Data8Value_1 : 1;
  unsigned char ODIEDD_Data8Value_0 : 2;
  unsigned char ODIEDD_Data9Value : 3;
  unsigned char ODIEDD_Data10Value : 3;
  unsigned char ODIEDD_Data11Value : 3;
  unsigned char ODIEDD_Data12Value : 3;
  unsigned char ODIEDD_Data13Value_1 : 2;
  unsigned char ODIEDD_Data13Value_0 : 1;
  unsigned char ODIEDD_Data14Value : 3;
  unsigned char ODIEDD_Data15Value : 3;
  unsigned char ODIEDD_Data16Value_1 : 1;
  unsigned char ODIEDD_Data16Value_0 : 2;
  unsigned char ODIEDD_Data17Value : 3;
  unsigned char ODIEDD_Data18Value : 3;
  unsigned char ODIEDD_FUCID : 8;
} _c_ODIEnmDynData_msgType;
typedef struct _c_ODIInd_msgTypeTag
{
  unsigned char ODII_FUCID : 8;
  unsigned char ODII_ODIInd1 : 1;
  unsigned char ODII_ODIInd2 : 1;
  unsigned char ODII_ODIInd3 : 1;
  unsigned char ODII_ODIInd4 : 1;
  unsigned char ODII_ODIInd5 : 1;
  unsigned char ODII_ODIInd6 : 1;
  unsigned char ODII_ODIInd7 : 1;
  unsigned char ODII_ODIInd8 : 1;
  unsigned char ODII_ODIInd9 : 1;
  unsigned char ODII_ODIInd10 : 1;
  unsigned char ODII_ODIInd11 : 1;
  unsigned char ODII_ODIInd12 : 1;
  unsigned char ODII_ODIInd13 : 1;
  unsigned char ODII_ODIInd14 : 1;
  unsigned char ODII_ODIInd15 : 1;
  unsigned char ODII_ODIInd16 : 1;
  unsigned char ODII_ODIInd17 : 1;
  unsigned char ODII_ODIInd18 : 1;
  unsigned char ODII_ODIInd19 : 1;
  unsigned char ODII_ODIInd20 : 1;
  unsigned char ODII_ODIInd21 : 1;
  unsigned char ODII_ODIInd22 : 1;
  unsigned char ODII_ODIInd23 : 1;
  unsigned char ODII_ODIInd24 : 1;
  unsigned char ODII_ODIInd25 : 1;
  unsigned char ODII_ODIInd26 : 1;
  unsigned char ODII_ODIInd27 : 1;
  unsigned char ODII_ODIInd28 : 1;
  unsigned char ODII_ODIInd29 : 1;
  unsigned char ODII_ODIInd30 : 1;
  unsigned char ODII_ODIInd31 : 1;
  unsigned char ODII_ODIInd32 : 1;
  unsigned char ODII_ODIInd33 : 1;
  unsigned char ODII_ODIInd34 : 1;
  unsigned char ODII_ODIInd35 : 1;
  unsigned char ODII_ODIInd36 : 1;
  unsigned char ODII_ODIInd37 : 1;
  unsigned char ODII_ODIInd38 : 1;
  unsigned char ODII_ODIInd39 : 1;
  unsigned char ODII_ODIInd40 : 1;
  unsigned char ODII_ODIInd41 : 1;
  unsigned char ODII_ODIInd42 : 1;
  unsigned char ODII_ODIInd43 : 1;
  unsigned char ODII_ODIInd44 : 1;
  unsigned char ODII_ODIInd45 : 1;
  unsigned char ODII_ODIInd46 : 1;
  unsigned char ODII_ODIInd47 : 1;
  unsigned char ODII_ODIInd48 : 1;
  unsigned char ODII_ODIInd49 : 1;
  unsigned char ODII_ODIInd50 : 1;
  unsigned char ODII_ODIInd51 : 1;
  unsigned char ODII_ODIInd52 : 1;
  unsigned char ODII_ODIInd53 : 1;
  unsigned char ODII_ODIInd54 : 1;
  unsigned char ODII_ODIInd55 : 1;
  unsigned char ODII_ODIInd56 : 1;
} _c_ODIInd_msgType;
typedef struct _c_ODIEvntPkt_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIE_EvID : 6;
  unsigned char ODIE_FUCID : 8;
  unsigned char ODIE_MultiFrRetCh : 8;
} _c_ODIEvntPkt_msgType;
typedef struct _c_DTCInfo_msgTypeTag
{
  unsigned char DTCIUnused7 : 1;
  unsigned char DTCIUnused6 : 1;
  unsigned char DTCIUnused5 : 1;
  unsigned char DTCIUnused4 : 1;
  unsigned char DTCIUnused3 : 1;
  unsigned char DTCIUnused2 : 1;
  unsigned char DTCIUnused1 : 1;
  unsigned char DTCI_DTCTriggered : 1;
  unsigned char DTCI_DTCSource : 8;
  unsigned char DTCI_DTCNumber_1 : 8;
  unsigned char DTCI_DTCNumber_0 : 8;
  unsigned char DTCI_DTCFailType : 8;
  unsigned char DTCI_WrnIndRqdSt : 1;
  unsigned char DTCI_TstFldPwrUpSt : 1;
  unsigned char DTCI_TstNPsdPwrUpSt : 1;
  unsigned char DTCI_HistStat : 1;
  unsigned char DTCI_TstFldCdClrdStat : 1;
  unsigned char DTCI_TstNPsdCdClrdSt : 1;
  unsigned char DTCI_CurrentStatus : 1;
  unsigned char DTCI_CodeSupported : 1;
  unsigned char DTCI_DTCFaultType : 8;
} _c_DTCInfo_msgType;
typedef struct _c_SndChrs_msgTypeTag
{
  unsigned char unused0 : 4;
  unsigned char SC_SndTne : 4;
  unsigned char SC_SndCdnPrd : 8;
  unsigned char SC_NmofRp : 8;
  unsigned char SC_SndDutCyc : 8;
} _c_SndChrs_msgType;
typedef struct _c_SndLoc_msgTypeTag
{
  unsigned char SndLocDrFr : 1;
  unsigned char SndLocPasFr : 1;
  unsigned char SndLocLftRr : 1;
  unsigned char SndLocRtRr : 1;
  unsigned char unused0 : 4;
} _c_SndLoc_msgType;
typedef struct _c_StrWhlAngReq_msgTypeTag
{
  unsigned char unused0 : 6;
  unsigned char SWAR_ReqAct : 1;
  unsigned char SWAR_ReqActV : 1;
  unsigned char SWAR_TrgtAng_1 : 8;
  unsigned char SWAR_TrgtAng_0 : 8;
} _c_StrWhlAngReq_msgType;
typedef struct _c_ODIDynDataMltRq_IPC_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODDMI_ReqType : 2;
  unsigned char ODDMI_DataID5Vld : 1;
  unsigned char ODDMI_DataID4Vld : 1;
  unsigned char ODDMI_DataID3Vld : 1;
  unsigned char ODDMI_DataID2Vld : 1;
  unsigned char ODDMI_FUCID : 8;
  unsigned char ODDMI_DispMID : 8;
  unsigned char ODDMI_DataID1 : 8;
  unsigned char ODDMI_DataID2 : 8;
  unsigned char ODDMI_DataID3 : 8;
  unsigned char ODDMI_DataID4 : 8;
  unsigned char ODDMI_DataID5 : 8;
} _c_ODIDynDataMltRq_IPC_msgType;
typedef struct _c_ODIDynDataMltRq_CntrStck_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODDMC_ReqType : 2;
  unsigned char ODDMC_DataID5Vld : 1;
  unsigned char ODDMC_DataID4Vld : 1;
  unsigned char ODDMC_DataID3Vld : 1;
  unsigned char ODDMC_DataID2Vld : 1;
  unsigned char ODDMC_FUCID : 8;
  unsigned char ODDMC_DispMID : 8;
  unsigned char ODDMC_DataID1 : 8;
  unsigned char ODDMC_DataID2 : 8;
  unsigned char ODDMC_DataID3 : 8;
  unsigned char ODDMC_DataID4 : 8;
  unsigned char ODDMC_DataID5 : 8;
} _c_ODIDynDataMltRq_CntrStck_msgType;
typedef struct _c_ODIDynDataMltRq_AuxIP_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODDMA_ReqType : 2;
  unsigned char ODDMA_DataID5Vld : 1;
  unsigned char ODDMA_DataID4Vld : 1;
  unsigned char ODDMA_DataID3Vld : 1;
  unsigned char ODDMA_DataID2Vld : 1;
  unsigned char ODDMA_FUCID : 8;
  unsigned char ODDMA_DispMID : 8;
  unsigned char ODDMA_DataID1 : 8;
  unsigned char ODDMA_DataID2 : 8;
  unsigned char ODDMA_DataID3 : 8;
  unsigned char ODDMA_DataID4 : 8;
  unsigned char ODDMA_DataID5 : 8;
} _c_ODIDynDataMltRq_AuxIP_msgType;
typedef struct _c_ODIActn_IPC_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIAI_DaTy : 6;
  unsigned char ODIAI_FUCID : 8;
  unsigned char ODIAI_ActnID : 8;
  unsigned char ODIAI_DspMID : 8;
  unsigned char ODIAI_ActnVal_3 : 8;
  unsigned char ODIAI_ActnVal_2 : 8;
  unsigned char ODIAI_ActnVal_1 : 8;
  unsigned char ODIAI_ActnVal_0 : 8;
} _c_ODIActn_IPC_msgType;
typedef struct _c_ODIActn_CntrStck_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIAC_DaTy : 6;
  unsigned char ODIAC_FUCID : 8;
  unsigned char ODIAC_ActnID : 8;
  unsigned char ODIAC_DspMID : 8;
  unsigned char ODIAC_ActnVal_3 : 8;
  unsigned char ODIAC_ActnVal_2 : 8;
  unsigned char ODIAC_ActnVal_1 : 8;
  unsigned char ODIAC_ActnVal_0 : 8;
} _c_ODIActn_CntrStck_msgType;
typedef struct _c_ODIActn_AxIP_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char ODIAA_DaTy : 6;
  unsigned char ODIAA_FUCID : 8;
  unsigned char ODIAA_ActnID : 8;
  unsigned char ODIAA_DspMID : 8;
  unsigned char ODIAA_ActnVal_3 : 8;
  unsigned char ODIAA_ActnVal_2 : 8;
  unsigned char ODIAA_ActnVal_1 : 8;
  unsigned char ODIAA_ActnVal_0 : 8;
} _c_ODIActn_AxIP_msgType;
typedef struct _c_WhlGrndVlctyLftDrvnGroup_0_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char WhlGrndVlctyLftDrvnV_0 : 1;
  unsigned char WhlGrndVlctyLftDrvn_0_1 : 6;
  unsigned char WhlGrndVlctyLftDrvn_0_0 : 8;
} _c_WhlGrndVlctyLftDrvnGroup_0_msgType;
typedef struct _c_WhlGrndVlctyLftNnDrvnGroup_0_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char WhlGrndVlctyLftNnDrvnV_0 : 1;
  unsigned char WhlGrndVlctyLftNnDrvn_0_1 : 6;
  unsigned char WhlGrndVlctyLftNnDrvn_0_0 : 8;
} _c_WhlGrndVlctyLftNnDrvnGroup_0_msgType;
typedef struct _c_WhlGrndVlctyRtDrvnGroup_0_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char WhlGrndVlctyRtDrvnV_0 : 1;
  unsigned char WhlGrndVlctyRtDrvn_0_1 : 6;
  unsigned char WhlGrndVlctyRtDrvn_0_0 : 8;
} _c_WhlGrndVlctyRtDrvnGroup_0_msgType;
typedef struct _c_WhlGrndVlctyRtNnDrvnGroup_0_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char WhlGrndVlctyRtNnDrvnV_0 : 1;
  unsigned char WhlGrndVlctyRtNnDrvn_0_1 : 6;
  unsigned char WhlGrndVlctyRtNnDrvn_0_0 : 8;
} _c_WhlGrndVlctyRtNnDrvnGroup_0_msgType;
typedef struct _c_DDAjrSwAtvGroup_msgTypeTag
{
  unsigned char DDAjrSwAtvM : 1;
  unsigned char unused0 : 6;
  unsigned char DDAjrSwAtv : 1;
} _c_DDAjrSwAtvGroup_msgType;
typedef struct _c_EngOffTmExtRngGroup_msgTypeTag
{
  unsigned char unused0 : 7;
  unsigned char EngOffTmExtRngV : 1;
  unsigned char unused1 : 8;
  unsigned char unused2 : 8;
  unsigned char unused3 : 8;
  unsigned char EngOffTmExtRng : 8;
} _c_EngOffTmExtRngGroup_msgType;
typedef struct _c_OtsAirTmpCrValGroup_msgTypeTag
{
  unsigned char unused0 : 7;
  unsigned char OtsAirTmpCrValV : 1;
  unsigned char OtsAirTmpCrVal : 8;
} _c_OtsAirTmpCrValGroup_msgType;
typedef struct _c_OtsAirTmpGroup_msgTypeTag
{
  unsigned char unused0 : 6;
  unsigned char OtsAirTmpV : 1;
  unsigned char unused1 : 1;
  unsigned char unused2 : 8;
  unsigned char OtsAirTmp : 8;
} _c_OtsAirTmpGroup_msgType;
typedef struct _c_EngCltTmpGroup_msgTypeTag
{
  unsigned char unused0 : 7;
  unsigned char EngCltTmpV : 1;
  unsigned char unused1 : 8;
  unsigned char unused2 : 8;
  unsigned char unused3 : 8;
  unsigned char unused4 : 8;
  unsigned char unused5 : 8;
  unsigned char unused6 : 8;
  unsigned char EngCltTmp : 8;
} _c_EngCltTmpGroup_msgType;
typedef struct _c_EngIntAirTmpGroup_msgTypeTag
{
  unsigned char unused0 : 6;
  unsigned char EngIntAirTmpV : 1;
  unsigned char unused1 : 1;
  unsigned char unused2 : 8;
  unsigned char unused3 : 8;
  unsigned char unused4 : 8;
  unsigned char unused5 : 8;
  unsigned char unused6 : 8;
  unsigned char EngIntAirTmp : 8;
} _c_EngIntAirTmpGroup_msgType;
typedef struct _c_OAT_PT_EstGroup_msgTypeTag
{
  unsigned char unused0 : 3;
  unsigned char OAT_PT_EstM : 1;
  unsigned char OAT_PT_EstV : 1;
  unsigned char unused1 : 3;
  unsigned char unused2 : 8;
  unsigned char unused3 : 8;
  unsigned char unused4 : 8;
  unsigned char OAT_PT_Est : 8;
} _c_OAT_PT_EstGroup_msgType;
typedef struct _c_TrnsShftLvrPosGroup_0_msgTypeTag
{
  unsigned char TrnsShftLvrPosV_0 : 1;
  unsigned char unused0 : 7;
  unsigned char unused1 : 8;
  unsigned char unused2 : 8;
  unsigned char unused3 : 8;
  unsigned char unused4 : 8;
  unsigned char unused5 : 4;
  unsigned char TrnsShftLvrPos_0 : 4;
} _c_TrnsShftLvrPosGroup_0_msgType;
typedef struct _c_SysBkUpPwrMdGroup_msgTypeTag
{
  unsigned char unused0 : 4;
  unsigned char SysBkUpPwrMdV : 1;
  unsigned char unused1 : 1;
  unsigned char SysBkUpPwrMd : 2;
} _c_SysBkUpPwrMdGroup_msgType;
typedef struct _c_SysPwrMdGroup_msgTypeTag
{
  unsigned char unused0 : 5;
  unsigned char SysPwrMdV : 1;
  unsigned char SysPwrMd : 2;
} _c_SysPwrMdGroup_msgType;
typedef struct _c_VSELongAccLoResGroup_msgTypeTag
{
  unsigned char unused0 : 5;
  unsigned char VSELongAccLoResV : 1;
  unsigned char VSELongAccLoRes_1 : 2;
  unsigned char VSELongAccLoRes_0 : 8;
} _c_VSELongAccLoResGroup_msgType;
typedef struct _c_StrWhAngGroup_0_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char StrWhAngV_0 : 1;
  unsigned char unused1 : 6;
  unsigned char unused2 : 8;
  unsigned char unused3 : 8;
  unsigned char unused4 : 8;
  unsigned char StrWhAng_0_1 : 8;
  unsigned char StrWhAng_0_0 : 8;
} _c_StrWhAngGroup_0_msgType;
typedef struct _c_WhlRotStatLftNDrvn_0_msgTypeTag
{
  unsigned char WRSLNDWhlDisTpRC_0 : 2;
  unsigned char WRSLNDSeqNum_0 : 2;
  unsigned char WRSLNDWhlRotStRst_0 : 1;
  unsigned char WRSLNDWhlDistVal_0 : 1;
  unsigned char WRSLNDWhlDistPCntr_0_1 : 2;
  unsigned char WRSLNDWhlDistPCntr_0_0 : 8;
  unsigned char WRSLNDWhlDistTstm_0_1 : 8;
  unsigned char WRSLNDWhlDistTstm_0_0 : 8;
} _c_WhlRotStatLftNDrvn_0_msgType;
typedef struct _c_WhlRotStatRghtNDrvn_0_msgTypeTag
{
  unsigned char WRSRNDWhlDisTpRC_0 : 2;
  unsigned char WRSRNDSeqNum_0 : 2;
  unsigned char WRSRNDWhlRotStRst_0 : 1;
  unsigned char WRSRNDWhlDistVal_0 : 1;
  unsigned char WRSRNDWhlDistPCntr_0_1 : 2;
  unsigned char WRSRNDWhlDistPCntr_0_0 : 8;
  unsigned char WRSRNDWhlDistTstm_0_1 : 8;
  unsigned char WRSRNDWhlDistTstm_0_0 : 8;
} _c_WhlRotStatRghtNDrvn_0_msgType;
typedef struct _c_WhlRotatStatLftDrvn_0_msgTypeTag
{
  unsigned char WRSLDWhlDisTpRC_0 : 2;
  unsigned char WRSLDSeqNum_0 : 2;
  unsigned char WRSLDWhlRotStatRst_0 : 1;
  unsigned char WRSLDWhlDistVal_0 : 1;
  unsigned char WRSLDWhlDistPlsCntr_0_1 : 2;
  unsigned char WRSLDWhlDistPlsCntr_0_0 : 8;
  unsigned char WRSLDWhlDistTmstm_0_1 : 8;
  unsigned char WRSLDWhlDistTmstm_0_0 : 8;
} _c_WhlRotatStatLftDrvn_0_msgType;
typedef struct _c_WhlRotatStatRtDrvn_0_msgTypeTag
{
  unsigned char WRSRDWhlDisTpRC_0 : 2;
  unsigned char WRSRDSeqNum_0 : 2;
  unsigned char WRSRDWhlRotStatRst_0 : 1;
  unsigned char WRSRDWhlDistVal_0 : 1;
  unsigned char WRSRDWhlDistPlsCntr_0_1 : 2;
  unsigned char WRSRDWhlDistPlsCntr_0_0 : 8;
  unsigned char WRSRDWhlDistTmstm_0_1 : 8;
  unsigned char WRSRDWhlDistTmstm_0_0 : 8;
} _c_WhlRotatStatRtDrvn_0_msgType;
typedef struct _c_VehDynYawRateGroup_msgTypeTag
{
  unsigned char unused0 : 3;
  unsigned char VehDynYawRateV : 1;
  unsigned char VehDynYawRate_1 : 4;
  unsigned char VehDynYawRate_0 : 8;
} _c_VehDynYawRateGroup_msgType;
typedef struct _c_VehSpdAvgDrvnGroup_msgTypeTag
{
  unsigned char VehSpdAvgDrvnV : 1;
  unsigned char VehSpdAvgDrvn_1 : 7;
  unsigned char VehSpdAvgDrvn_0 : 8;
} _c_VehSpdAvgDrvnGroup_msgType;
typedef struct _c_DistRollCntAvgDrvnGroup_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char DistRollCntAvgDrvnV : 1;
  unsigned char unused1 : 1;
  unsigned char DistRollCntAvgDrvn_1 : 5;
  unsigned char DistRollCntAvgDrvn_0 : 8;
} _c_DistRollCntAvgDrvnGroup_msgType;
typedef struct _c_VehSpdAvgNDrvnGroup_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char VehSpdAvgNDrvn_1 : 7;
  unsigned char VehSpdAvgNDrvn_0 : 8;
  unsigned char unused1 : 1;
  unsigned char VehSpdAvgNDrvnV : 1;
  unsigned char unused2 : 6;
} _c_VehSpdAvgNDrvnGroup_msgType;
typedef struct _c_OtsdAmbtLtLvlStatGroup_msgTypeTag
{
  unsigned char unused0 : 7;
  unsigned char OtsdAmbtLtLvlStatV : 1;
  unsigned char unused1 : 8;
  unsigned char unused2 : 8;
  unsigned char unused3 : 4;
  unsigned char OtsdAmbtLtLvlStat : 2;
  unsigned char unused4 : 2;
} _c_OtsdAmbtLtLvlStatGroup_msgType;
typedef struct _c_WhlGrndVlctyLftNnDrvnGroup_1_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char WhlGrndVlctyLftNnDrvnV_1 : 1;
  unsigned char WhlGrndVlctyLftNnDrvn_1_1 : 6;
  unsigned char WhlGrndVlctyLftNnDrvn_1_0 : 8;
} _c_WhlGrndVlctyLftNnDrvnGroup_1_msgType;
typedef struct _c_WhlGrndVlctyRtNnDrvnGroup_1_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char WhlGrndVlctyRtNnDrvnV_1 : 1;
  unsigned char WhlGrndVlctyRtNnDrvn_1_1 : 6;
  unsigned char WhlGrndVlctyRtNnDrvn_1_0 : 8;
} _c_WhlGrndVlctyRtNnDrvnGroup_1_msgType;
typedef struct _c_WhlGrndVlctyLftDrvnGroup_1_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char WhlGrndVlctyLftDrvnV_1 : 1;
  unsigned char WhlGrndVlctyLftDrvn_1_1 : 6;
  unsigned char WhlGrndVlctyLftDrvn_1_0 : 8;
} _c_WhlGrndVlctyLftDrvnGroup_1_msgType;
typedef struct _c_WhlGrndVlctyRtDrvnGroup_1_msgTypeTag
{
  unsigned char unused0 : 1;
  unsigned char WhlGrndVlctyRtDrvnV_1 : 1;
  unsigned char WhlGrndVlctyRtDrvn_1_1 : 6;
  unsigned char WhlGrndVlctyRtDrvn_1_0 : 8;
} _c_WhlGrndVlctyRtDrvnGroup_1_msgType;
typedef struct _c_DrvStrIntfrDtcdGroup_msgTypeTag
{
  unsigned char unused0 : 4;
  unsigned char DrvStrIntfrDtcd : 1;
  unsigned char DrvStrIntfrDtcdV : 1;
  unsigned char unused1 : 2;
} _c_DrvStrIntfrDtcdGroup_msgType;
typedef struct _c_TrnsShftLvrPosGroup_1_msgTypeTag
{
  unsigned char TrnsShftLvrPosV_1 : 1;
  unsigned char unused0 : 7;
  unsigned char unused1 : 8;
  unsigned char unused2 : 1;
  unsigned char TrnsShftLvrPos_1 : 4;
  unsigned char unused3 : 3;
} _c_TrnsShftLvrPosGroup_1_msgType;
typedef struct _c_StrWhAngGroup_1_msgTypeTag
{
  unsigned char StrWhAngV_1 : 1;
  unsigned char unused0 : 7;
  unsigned char StrWhAng_1_1 : 8;
  unsigned char StrWhAng_1_0 : 8;
} _c_StrWhAngGroup_1_msgType;
typedef struct _c_StrWhAngGrdGroup_msgTypeTag
{
  unsigned char StrWhAngGrdV : 1;
  unsigned char unused0 : 3;
  unsigned char StrWhAngGrd_1 : 4;
  unsigned char StrWhAngGrd_0 : 8;
} _c_StrWhAngGrdGroup_msgType;
typedef struct _c_IMULonAccPriGroup_msgTypeTag
{
  unsigned char unused0 : 2;
  unsigned char IMULonAccPriV : 1;
  unsigned char unused1 : 5;
  unsigned char unused2 : 8;
  unsigned char unused3 : 4;
  unsigned char IMULonAccPri_1 : 4;
  unsigned char IMULonAccPri_0 : 8;
} _c_IMULonAccPriGroup_msgType;
typedef struct _c_IMUYawRtPriGroup_msgTypeTag
{
  unsigned char unused0 : 3;
  unsigned char IMUYawRtPri_1 : 5;
  unsigned char IMUYawRtPri_0 : 8;
  unsigned char unused1 : 2;
  unsigned char IMUYawRtPriV : 1;
  unsigned char unused2 : 5;
} _c_IMUYawRtPriGroup_msgType;
typedef struct _c_IMULatAccPrimGroup_msgTypeTag
{
  unsigned char IMULatAccPrimV : 1;
  unsigned char unused0 : 7;
  unsigned char unused1 : 8;
  unsigned char unused2 : 8;
  unsigned char unused3 : 8;
  unsigned char unused4 : 8;
  unsigned char unused5 : 3;
  unsigned char IMULatAccPrim_1 : 5;
  unsigned char IMULatAccPrim_0 : 5;
  unsigned char unused6 : 3;
} _c_IMULatAccPrimGroup_msgType;
typedef struct _c_WhlRotStatLftNDrvn_1_msgTypeTag
{
  unsigned char WRSLNDWhlDisTpRC_1 : 2;
  unsigned char WRSLNDSeqNum_1 : 2;
  unsigned char WRSLNDWhlRotStRst_1 : 1;
  unsigned char WRSLNDWhlDistVal_1 : 1;
  unsigned char WRSLNDWhlDistPCntr_1_1 : 2;
  unsigned char WRSLNDWhlDistPCntr_1_0 : 8;
  unsigned char WRSLNDWhlDistTstm_1_1 : 8;
  unsigned char WRSLNDWhlDistTstm_1_0 : 8;
} _c_WhlRotStatLftNDrvn_1_msgType;
typedef struct _c_WhlRotStatRghtNDrvn_1_msgTypeTag
{
  unsigned char WRSRNDWhlDisTpRC_1 : 2;
  unsigned char WRSRNDSeqNum_1 : 2;
  unsigned char WRSRNDWhlRotStRst_1 : 1;
  unsigned char WRSRNDWhlDistVal_1 : 1;
  unsigned char WRSRNDWhlDistPCntr_1_1 : 2;
  unsigned char WRSRNDWhlDistPCntr_1_0 : 8;
  unsigned char WRSRNDWhlDistTstm_1_1 : 8;
  unsigned char WRSRNDWhlDistTstm_1_0 : 8;
} _c_WhlRotStatRghtNDrvn_1_msgType;
typedef struct _c_WhlRotatStatLftDrvn_1_msgTypeTag
{
  unsigned char WRSLDWhlDisTpRC_1 : 2;
  unsigned char WRSLDSeqNum_1 : 2;
  unsigned char WRSLDWhlRotStatRst_1 : 1;
  unsigned char WRSLDWhlDistVal_1 : 1;
  unsigned char WRSLDWhlDistPlsCntr_1_1 : 2;
  unsigned char WRSLDWhlDistPlsCntr_1_0 : 8;
  unsigned char WRSLDWhlDistTmstm_1_1 : 8;
  unsigned char WRSLDWhlDistTmstm_1_0 : 8;
} _c_WhlRotatStatLftDrvn_1_msgType;
typedef struct _c_WhlRotatStatRtDrvn_1_msgTypeTag
{
  unsigned char WRSRDWhlDisTpRC_1 : 2;
  unsigned char WRSRDSeqNum_1 : 2;
  unsigned char WRSRDWhlRotStatRst_1 : 1;
  unsigned char WRSRDWhlDistVal_1 : 1;
  unsigned char WRSRDWhlDistPlsCntr_1_1 : 2;
  unsigned char WRSRDWhlDistPlsCntr_1_0 : 8;
  unsigned char WRSRDWhlDistTmstm_1_1 : 8;
  unsigned char WRSRDWhlDistTmstm_1_0 : 8;
} _c_WhlRotatStatRtDrvn_1_msgType;




/* -----------------------------------------------------------------------------
    &&&~ Signal value names
 ----------------------------------------------------------------------------- */

#define kTeenDrvAct_true                     1
#define kTeenDrvAct_false                    0


#define kClsnMtgtnInhbtd_true                1
#define kClsnMtgtnInhbtd_false               0

#define kPrkAstInhbtReq_true                 1
#define kPrkAstInhbtReq_false                0

#define kPrkAstRrObjSnsngRqAct_true          1
#define kPrkAstRrObjSnsngRqAct_false         0

#define kPrkAstOprtrDsrdStat_Off             0
#define kPrkAstOprtrDsrdStat_On              1
#define kPrkAstOprtrDsrdStat_Tow_Bar_Attached 2


#define kPrkAstRrSysStatUnfltd_Disabled      0
#define kPrkAstRrSysStatUnfltd_Enabled       1
#define kPrkAstRrSysStatUnfltd_Inhibited     2
#define kPrkAstRrSysStatUnfltd_Failed        3

#define kPrkAstFntnSnsDstrbdIO_true          1
#define kPrkAstFntnSnsDstrbdIO_false         0

#define kPrkAstFntnSnrsBlkd_true             1
#define kPrkAstFntnSnrsBlkd_false            0

#define kPrkAstFntnFld_true                  1
#define kPrkAstFntnFld_false                 0

#define kPrkAstFntnDsbldIO_true              1
#define kPrkAstFntnDsbldIO_false             0

#define kPrkAstFntnClnPrkAstIO_true          1
#define kPrkAstFntnClnPrkAstIO_false         0

#define kClsnMtgtnInhbtReqtd_true            1
#define kClsnMtgtnInhbtReqtd_false           0

#define kPrkAstRrObjSnsngAct_true            1
#define kPrkAstRrObjSnsngAct_false           0

#define kPARrRgn3ObjStatUnfltd_No_Object     0
#define kPARrRgn3ObjStatUnfltd_Zone_1        1
#define kPARrRgn3ObjStatUnfltd_Zone_2        2
#define kPARrRgn3ObjStatUnfltd_Zone_3        3
#define kPARrRgn3ObjStatUnfltd_Zone_4        4
#define kPARrRgn3ObjStatUnfltd_Zone_5        5
#define kPARrRgn3ObjStatUnfltd_Zone_6        6
#define kPARrRgn3ObjStatUnfltd_Zone_7        7
#define kPARrRgn3ObjStatUnfltd_Zone_8        8
#define kPARrRgn3ObjStatUnfltd_Zone_9        9
#define kPARrRgn3ObjStatUnfltd_Zone_10       10
#define kPARrRgn3ObjStatUnfltd_Zone_11       11
#define kPARrRgn3ObjStatUnfltd_Zone_12       12
#define kPARrRgn3ObjStatUnfltd_Zone_13       13
#define kPARrRgn3ObjStatUnfltd_Zone_14       14
#define kPARrRgn3ObjStatUnfltd_Zone_15       15

#define kPARrRgn4ObjStatUnfltd_No_Object     0
#define kPARrRgn4ObjStatUnfltd_Zone_1        1
#define kPARrRgn4ObjStatUnfltd_Zone_2        2
#define kPARrRgn4ObjStatUnfltd_Zone_3        3
#define kPARrRgn4ObjStatUnfltd_Zone_4        4
#define kPARrRgn4ObjStatUnfltd_Zone_5        5
#define kPARrRgn4ObjStatUnfltd_Zone_6        6
#define kPARrRgn4ObjStatUnfltd_Zone_7        7
#define kPARrRgn4ObjStatUnfltd_Zone_8        8
#define kPARrRgn4ObjStatUnfltd_Zone_9        9
#define kPARrRgn4ObjStatUnfltd_Zone_10       10
#define kPARrRgn4ObjStatUnfltd_Zone_11       11
#define kPARrRgn4ObjStatUnfltd_Zone_12       12
#define kPARrRgn4ObjStatUnfltd_Zone_13       13
#define kPARrRgn4ObjStatUnfltd_Zone_14       14
#define kPARrRgn4ObjStatUnfltd_Zone_15       15

#define kPARrRgn1ObjStatUnfltd_No_Object     0
#define kPARrRgn1ObjStatUnfltd_Zone_1        1
#define kPARrRgn1ObjStatUnfltd_Zone_2        2
#define kPARrRgn1ObjStatUnfltd_Zone_3        3
#define kPARrRgn1ObjStatUnfltd_Zone_4        4
#define kPARrRgn1ObjStatUnfltd_Zone_5        5
#define kPARrRgn1ObjStatUnfltd_Zone_6        6
#define kPARrRgn1ObjStatUnfltd_Zone_7        7
#define kPARrRgn1ObjStatUnfltd_Zone_8        8
#define kPARrRgn1ObjStatUnfltd_Zone_9        9
#define kPARrRgn1ObjStatUnfltd_Zone_10       10
#define kPARrRgn1ObjStatUnfltd_Zone_11       11
#define kPARrRgn1ObjStatUnfltd_Zone_12       12
#define kPARrRgn1ObjStatUnfltd_Zone_13       13
#define kPARrRgn1ObjStatUnfltd_Zone_14       14
#define kPARrRgn1ObjStatUnfltd_Zone_15       15

#define kPARrRgn2ObjStatUnfltd_No_Object     0
#define kPARrRgn2ObjStatUnfltd_Zone_1        1
#define kPARrRgn2ObjStatUnfltd_Zone_2        2
#define kPARrRgn2ObjStatUnfltd_Zone_3        3
#define kPARrRgn2ObjStatUnfltd_Zone_4        4
#define kPARrRgn2ObjStatUnfltd_Zone_5        5
#define kPARrRgn2ObjStatUnfltd_Zone_6        6
#define kPARrRgn2ObjStatUnfltd_Zone_7        7
#define kPARrRgn2ObjStatUnfltd_Zone_8        8
#define kPARrRgn2ObjStatUnfltd_Zone_9        9
#define kPARrRgn2ObjStatUnfltd_Zone_10       10
#define kPARrRgn2ObjStatUnfltd_Zone_11       11
#define kPARrRgn2ObjStatUnfltd_Zone_12       12
#define kPARrRgn2ObjStatUnfltd_Zone_13       13
#define kPARrRgn2ObjStatUnfltd_Zone_14       14
#define kPARrRgn2ObjStatUnfltd_Zone_15       15


#define kPARtRgn1ObjStat_No_Object           0
#define kPARtRgn1ObjStat_Zone_1              1
#define kPARtRgn1ObjStat_Zone_2              2
#define kPARtRgn1ObjStat_Zone_3              3
#define kPARtRgn1ObjStat_Zone_4              4
#define kPARtRgn1ObjStat_Zone_5              5
#define kPARtRgn1ObjStat_Zone_6              6
#define kPARtRgn1ObjStat_Zone_7              7
#define kPARtRgn1ObjStat_Zone_8              8
#define kPARtRgn1ObjStat_Zone_9              9
#define kPARtRgn1ObjStat_Zone_10             10
#define kPARtRgn1ObjStat_Zone_11             11
#define kPARtRgn1ObjStat_Zone_12             12
#define kPARtRgn1ObjStat_Zone_13             13
#define kPARtRgn1ObjStat_Zone_14             14
#define kPARtRgn1ObjStat_Zone_15             15

#define kPrkAstRtSysStat_Disabled            0
#define kPrkAstRtSysStat_Enabled             1
#define kPrkAstRtSysStat_Inhibited           2
#define kPrkAstRtSysStat_Failed              3

#define kPARtRgn3ObjStat_No_Object           0
#define kPARtRgn3ObjStat_Zone_1              1
#define kPARtRgn3ObjStat_Zone_2              2
#define kPARtRgn3ObjStat_Zone_3              3
#define kPARtRgn3ObjStat_Zone_4              4
#define kPARtRgn3ObjStat_Zone_5              5
#define kPARtRgn3ObjStat_Zone_6              6
#define kPARtRgn3ObjStat_Zone_7              7
#define kPARtRgn3ObjStat_Zone_8              8
#define kPARtRgn3ObjStat_Zone_9              9
#define kPARtRgn3ObjStat_Zone_10             10
#define kPARtRgn3ObjStat_Zone_11             11
#define kPARtRgn3ObjStat_Zone_12             12
#define kPARtRgn3ObjStat_Zone_13             13
#define kPARtRgn3ObjStat_Zone_14             14
#define kPARtRgn3ObjStat_Zone_15             15

#define kPARtRgn2ObjStat_No_Object           0
#define kPARtRgn2ObjStat_Zone_1              1
#define kPARtRgn2ObjStat_Zone_2              2
#define kPARtRgn2ObjStat_Zone_3              3
#define kPARtRgn2ObjStat_Zone_4              4
#define kPARtRgn2ObjStat_Zone_5              5
#define kPARtRgn2ObjStat_Zone_6              6
#define kPARtRgn2ObjStat_Zone_7              7
#define kPARtRgn2ObjStat_Zone_8              8
#define kPARtRgn2ObjStat_Zone_9              9
#define kPARtRgn2ObjStat_Zone_10             10
#define kPARtRgn2ObjStat_Zone_11             11
#define kPARtRgn2ObjStat_Zone_12             12
#define kPARtRgn2ObjStat_Zone_13             13
#define kPARtRgn2ObjStat_Zone_14             14
#define kPARtRgn2ObjStat_Zone_15             15


#define kPALtRgn1ObjStat_No_Object           0
#define kPALtRgn1ObjStat_Zone_1              1
#define kPALtRgn1ObjStat_Zone_2              2
#define kPALtRgn1ObjStat_Zone_3              3
#define kPALtRgn1ObjStat_Zone_4              4
#define kPALtRgn1ObjStat_Zone_5              5
#define kPALtRgn1ObjStat_Zone_6              6
#define kPALtRgn1ObjStat_Zone_7              7
#define kPALtRgn1ObjStat_Zone_8              8
#define kPALtRgn1ObjStat_Zone_9              9
#define kPALtRgn1ObjStat_Zone_10             10
#define kPALtRgn1ObjStat_Zone_11             11
#define kPALtRgn1ObjStat_Zone_12             12
#define kPALtRgn1ObjStat_Zone_13             13
#define kPALtRgn1ObjStat_Zone_14             14
#define kPALtRgn1ObjStat_Zone_15             15

#define kPrkAstLtSysStat_Disabled            0
#define kPrkAstLtSysStat_Enabled             1
#define kPrkAstLtSysStat_Inhibited           2
#define kPrkAstLtSysStat_Failed              3

#define kPALtRgn3ObjStat_No_Object           0
#define kPALtRgn3ObjStat_Zone_1              1
#define kPALtRgn3ObjStat_Zone_2              2
#define kPALtRgn3ObjStat_Zone_3              3
#define kPALtRgn3ObjStat_Zone_4              4
#define kPALtRgn3ObjStat_Zone_5              5
#define kPALtRgn3ObjStat_Zone_6              6
#define kPALtRgn3ObjStat_Zone_7              7
#define kPALtRgn3ObjStat_Zone_8              8
#define kPALtRgn3ObjStat_Zone_9              9
#define kPALtRgn3ObjStat_Zone_10             10
#define kPALtRgn3ObjStat_Zone_11             11
#define kPALtRgn3ObjStat_Zone_12             12
#define kPALtRgn3ObjStat_Zone_13             13
#define kPALtRgn3ObjStat_Zone_14             14
#define kPALtRgn3ObjStat_Zone_15             15

#define kPALtRgn2ObjStat_No_Object           0
#define kPALtRgn2ObjStat_Zone_1              1
#define kPALtRgn2ObjStat_Zone_2              2
#define kPALtRgn2ObjStat_Zone_3              3
#define kPALtRgn2ObjStat_Zone_4              4
#define kPALtRgn2ObjStat_Zone_5              5
#define kPALtRgn2ObjStat_Zone_6              6
#define kPALtRgn2ObjStat_Zone_7              7
#define kPALtRgn2ObjStat_Zone_8              8
#define kPALtRgn2ObjStat_Zone_9              9
#define kPALtRgn2ObjStat_Zone_10             10
#define kPALtRgn2ObjStat_Zone_11             11
#define kPALtRgn2ObjStat_Zone_12             12
#define kPALtRgn2ObjStat_Zone_13             13
#define kPALtRgn2ObjStat_Zone_14             14
#define kPALtRgn2ObjStat_Zone_15             15


#define kCrshAlrtDrvrSlctdType_Chime         0
#define kCrshAlrtDrvrSlctdType_Seat          1

#define kCrshAlrtStPrsnt_true                1
#define kCrshAlrtStPrsnt_false               0

#define kHptcStVbnStat_Normal_Operation      0
#define kHptcStVbnStat_Unknown               1
#define kHptcStVbnStat_Failed                2


#define kEngCltTmpV_Invalid                  1
#define kEngCltTmpV_Valid                    0

#define kEngIntAirTmpV_Invalid               1
#define kEngIntAirTmpV_Valid                 0

#define kOAT_PT_EstV_Invalid                 1
#define kOAT_PT_EstV_Valid                   0
#define kOAT_PT_EstM_Use_Data                1
#define kOAT_PT_EstM_Don_t_Use_Data          0


#define kODII_ODIInd8_true                   1
#define kODII_ODIInd8_false                  0
#define kODII_ODIInd7_true                   1
#define kODII_ODIInd7_false                  0
#define kODII_ODIInd6_true                   1
#define kODII_ODIInd6_false                  0
#define kODII_ODIInd5_true                   1
#define kODII_ODIInd5_false                  0
#define kODII_ODIInd4_true                   1
#define kODII_ODIInd4_false                  0
#define kODII_ODIInd3_true                   1
#define kODII_ODIInd3_false                  0
#define kODII_ODIInd2_true                   1
#define kODII_ODIInd2_false                  0
#define kODII_ODIInd1_true                   1
#define kODII_ODIInd1_false                  0
#define kODII_ODIInd16_true                  1
#define kODII_ODIInd16_false                 0
#define kODII_ODIInd15_true                  1
#define kODII_ODIInd15_false                 0
#define kODII_ODIInd14_true                  1
#define kODII_ODIInd14_false                 0
#define kODII_ODIInd13_true                  1
#define kODII_ODIInd13_false                 0
#define kODII_ODIInd12_true                  1
#define kODII_ODIInd12_false                 0
#define kODII_ODIInd11_true                  1
#define kODII_ODIInd11_false                 0
#define kODII_ODIInd10_true                  1
#define kODII_ODIInd10_false                 0
#define kODII_ODIInd9_true                   1
#define kODII_ODIInd9_false                  0
#define kODII_ODIInd24_true                  1
#define kODII_ODIInd24_false                 0
#define kODII_ODIInd23_true                  1
#define kODII_ODIInd23_false                 0
#define kODII_ODIInd22_true                  1
#define kODII_ODIInd22_false                 0
#define kODII_ODIInd21_true                  1
#define kODII_ODIInd21_false                 0
#define kODII_ODIInd20_true                  1
#define kODII_ODIInd20_false                 0
#define kODII_ODIInd19_true                  1
#define kODII_ODIInd19_false                 0
#define kODII_ODIInd18_true                  1
#define kODII_ODIInd18_false                 0
#define kODII_ODIInd17_true                  1
#define kODII_ODIInd17_false                 0
#define kODII_ODIInd32_true                  1
#define kODII_ODIInd32_false                 0
#define kODII_ODIInd31_true                  1
#define kODII_ODIInd31_false                 0
#define kODII_ODIInd30_true                  1
#define kODII_ODIInd30_false                 0
#define kODII_ODIInd29_true                  1
#define kODII_ODIInd29_false                 0
#define kODII_ODIInd28_true                  1
#define kODII_ODIInd28_false                 0
#define kODII_ODIInd27_true                  1
#define kODII_ODIInd27_false                 0
#define kODII_ODIInd26_true                  1
#define kODII_ODIInd26_false                 0
#define kODII_ODIInd25_true                  1
#define kODII_ODIInd25_false                 0
#define kODII_ODIInd40_true                  1
#define kODII_ODIInd40_false                 0
#define kODII_ODIInd39_true                  1
#define kODII_ODIInd39_false                 0
#define kODII_ODIInd38_true                  1
#define kODII_ODIInd38_false                 0
#define kODII_ODIInd37_true                  1
#define kODII_ODIInd37_false                 0
#define kODII_ODIInd36_true                  1
#define kODII_ODIInd36_false                 0
#define kODII_ODIInd35_true                  1
#define kODII_ODIInd35_false                 0
#define kODII_ODIInd34_true                  1
#define kODII_ODIInd34_false                 0
#define kODII_ODIInd33_true                  1
#define kODII_ODIInd33_false                 0
#define kODII_ODIInd48_true                  1
#define kODII_ODIInd48_false                 0
#define kODII_ODIInd47_true                  1
#define kODII_ODIInd47_false                 0
#define kODII_ODIInd46_true                  1
#define kODII_ODIInd46_false                 0
#define kODII_ODIInd45_true                  1
#define kODII_ODIInd45_false                 0
#define kODII_ODIInd44_true                  1
#define kODII_ODIInd44_false                 0
#define kODII_ODIInd43_true                  1
#define kODII_ODIInd43_false                 0
#define kODII_ODIInd42_true                  1
#define kODII_ODIInd42_false                 0
#define kODII_ODIInd41_true                  1
#define kODII_ODIInd41_false                 0
#define kODII_ODIInd56_true                  1
#define kODII_ODIInd56_false                 0
#define kODII_ODIInd55_true                  1
#define kODII_ODIInd55_false                 0
#define kODII_ODIInd54_true                  1
#define kODII_ODIInd54_false                 0
#define kODII_ODIInd53_true                  1
#define kODII_ODIInd53_false                 0
#define kODII_ODIInd52_true                  1
#define kODII_ODIInd52_false                 0
#define kODII_ODIInd51_true                  1
#define kODII_ODIInd51_false                 0
#define kODII_ODIInd50_true                  1
#define kODII_ODIInd50_false                 0
#define kODII_ODIInd49_true                  1
#define kODII_ODIInd49_false                 0


#define kEngOffTmExtRngV_Invalid             1
#define kEngOffTmExtRngV_Valid               0


#define kPrkAsstClnPrkAstIO_true             1
#define kPrkAsstClnPrkAstIO_false            0

#define kPrkAsstDisablIO_true                1
#define kPrkAsstDisablIO_false               0

#define kPrkAstFld_true                      1
#define kPrkAstFld_false                     0

#define kPrkAstSnrsBlk_true                  1
#define kPrkAstSnrsBlk_false                 0

#define kPrkAstSnsDistrbdIO_true             1
#define kPrkAstSnsDistrbdIO_false            0

#define kTnDrvPrkAstOffUnbIO_true            1
#define kTnDrvPrkAstOffUnbIO_false           0


#define kChmAct_true                         1
#define kChmAct_false                        0


#define kODD_InvldData_true                  1
#define kODD_InvldData_false                 0
#define kODD_DataType_Bitmap                 21
#define kODD_DataType_DecimalShort           20
#define kODD_DataType_HoursOfDay             19
#define kODD_DataType_Character              18
#define kODD_DataType_Fuel_Consumption_Inverted 17
#define kODD_DataType_Fuel_Consumption       16
#define kODD_DataType_Pressure               15
#define kODD_DataType_Temperature            14
#define kODD_DataType_Volume                 13
#define kODD_DataType_DistanceShort          12
#define kODD_DataType_DistanceLong           11
#define kODD_DataType_BitmapId               10
#define kODD_DataType_TextId                 9
#define kODD_DataType_Pictogram              8
#define kODD_DataType_List_                  7
#define kODD_DataType_Date                   6
#define kODD_DataType_Time_                  5
#define kODD_DataType_Decimal                4
#define kODD_DataType_EnumerationValue       3
#define kODD_DataType_Integer                2
#define kODD_DataType_String                 1
#define kODD_DataType_Speed                  0


#define kODIAC_DaTy_Bitmap                   21
#define kODIAC_DaTy_DecimalShort             20
#define kODIAC_DaTy_HoursOfDay               19
#define kODIAC_DaTy_Character                18
#define kODIAC_DaTy_Fuel_Consumption_Inverted 17
#define kODIAC_DaTy_Fuel_Consumption         16
#define kODIAC_DaTy_Pressure                 15
#define kODIAC_DaTy_Temperature              14
#define kODIAC_DaTy_Volume                   13
#define kODIAC_DaTy_DistanceShort            12
#define kODIAC_DaTy_DistanceLong             11
#define kODIAC_DaTy_BitmapId                 10
#define kODIAC_DaTy_TextId                   9
#define kODIAC_DaTy_Pictogram                8
#define kODIAC_DaTy_List_                    7
#define kODIAC_DaTy_Date                     6
#define kODIAC_DaTy_Time_                    5
#define kODIAC_DaTy_Decimal                  4
#define kODIAC_DaTy_EnumerationValue         3
#define kODIAC_DaTy_Integer                  2
#define kODIAC_DaTy_String                   1
#define kODIAC_DaTy_Speed                    0
#define kODIAC_DspMID_Reserved               128
#define kODIAC_DspMID_Reserved0               64
#define kODIAC_DspMID_OTIM                   32
#define kODIAC_DspMID_RearDisplayTwo         16
#define kODIAC_DspMID_RearDisplayOne         8
#define kODIAC_DspMID_AuxIP                  4
#define kODIAC_DspMID_CenterStack            2
#define kODIAC_DspMID_IPC                    1


#define kPrkBrkSwAtv_true                    1
#define kPrkBrkSwAtv_false                   0


#define kVSELongAccLoResV_Invalid            1
#define kVSELongAccLoResV_Valid              0

#define kTCSysAtv_true                       1
#define kTCSysAtv_false                      0

#define kVSEAct_true                         1
#define kVSEAct_false                        0

#define kStrWhAngV_0_Invalid                 1
#define kStrWhAngV_0_Valid                   0

#define kStWhAnVDA_VirtualDeviceAvailable    1
#define kStWhAnVDA_VirtualDeviceUnavailable  0

#define kVehStabEnhmntStat_Not_Ready         4
#define kVehStabEnhmntStat_Warming_Up        3
#define kVehStabEnhmntStat_Fault             2
#define kVehStabEnhmntStat_Active            1
#define kVehStabEnhmntStat_Inactive          0

#define kStrWhlAngSenCalStat_0_Calibrated    2
#define kStrWhlAngSenCalStat_0_Estimated     1
#define kStrWhlAngSenCalStat_0_Unknown       0

#define kTCSysOpStat_Fault                   2
#define kTCSysOpStat_Active                  1
#define kTCSysOpStat_Inactive                0


#define kWhlGrndVlctyLftDrvnV_0_Invalid      1
#define kWhlGrndVlctyLftDrvnV_0_Valid        0

#define kWhlGrndVlctyLftNnDrvnV_0_Invalid    1
#define kWhlGrndVlctyLftNnDrvnV_0_Valid      0

#define kWhlGrndVlctyRtDrvnV_0_Invalid       1
#define kWhlGrndVlctyRtDrvnV_0_Valid         0

#define kWhlGrndVlctyRtNnDrvnV_0_Invalid     1
#define kWhlGrndVlctyRtNnDrvnV_0_Valid       0


#define kWRSLNDWhlDistVal_0_Invalid          1
#define kWRSLNDWhlDistVal_0_Valid            0
#define kWRSLNDWhlRotStRst_0_true            1
#define kWRSLNDWhlRotStRst_0_false           0

#define kWRSRNDWhlDistVal_0_Invalid          1
#define kWRSRNDWhlDistVal_0_Valid            0
#define kWRSRNDWhlRotStRst_0_true            1
#define kWRSRNDWhlRotStRst_0_false           0


#define kWRSLDWhlDistVal_0_Invalid           1
#define kWRSLDWhlDistVal_0_Valid             0
#define kWRSLDWhlRotStatRst_0_true           1
#define kWRSLDWhlRotStatRst_0_false          0

#define kWRSRDWhlDistVal_0_Invalid           1
#define kWRSRDWhlDistVal_0_Valid             0
#define kWRSRDWhlRotStatRst_0_true           1
#define kWRSRDWhlRotStatRst_0_false          0


#define kTrStLgMdAtv_true                    1
#define kTrStLgMdAtv_false                   0

#define kVehMovState_Invalid                 4
#define kVehMovState_Reverse                 3
#define kVehMovState_Forward                 2
#define kVehMovState_Neutral                 1
#define kVehMovState_Parked                  0


#define kPrkAstRrSysStat_Failed              3
#define kPrkAstRrSysStat_Inhibited           2
#define kPrkAstRrSysStat_Enabled             1
#define kPrkAstRrSysStat_Disabled            0

#define kPARrRgn1ObjStat_Zone_15             15
#define kPARrRgn1ObjStat_Zone_14             14
#define kPARrRgn1ObjStat_Zone_13             13
#define kPARrRgn1ObjStat_Zone_12             12
#define kPARrRgn1ObjStat_Zone_11             11
#define kPARrRgn1ObjStat_Zone_10             10
#define kPARrRgn1ObjStat_Zone_9              9
#define kPARrRgn1ObjStat_Zone_8              8
#define kPARrRgn1ObjStat_Zone_7              7
#define kPARrRgn1ObjStat_Zone_6              6
#define kPARrRgn1ObjStat_Zone_5              5
#define kPARrRgn1ObjStat_Zone_4              4
#define kPARrRgn1ObjStat_Zone_3              3
#define kPARrRgn1ObjStat_Zone_2              2
#define kPARrRgn1ObjStat_Zone_1              1
#define kPARrRgn1ObjStat_No_Object           0

#define kPARrRgn2ObjStat_Zone_15             15
#define kPARrRgn2ObjStat_Zone_14             14
#define kPARrRgn2ObjStat_Zone_13             13
#define kPARrRgn2ObjStat_Zone_12             12
#define kPARrRgn2ObjStat_Zone_11             11
#define kPARrRgn2ObjStat_Zone_10             10
#define kPARrRgn2ObjStat_Zone_9              9
#define kPARrRgn2ObjStat_Zone_8              8
#define kPARrRgn2ObjStat_Zone_7              7
#define kPARrRgn2ObjStat_Zone_6              6
#define kPARrRgn2ObjStat_Zone_5              5
#define kPARrRgn2ObjStat_Zone_4              4
#define kPARrRgn2ObjStat_Zone_3              3
#define kPARrRgn2ObjStat_Zone_2              2
#define kPARrRgn2ObjStat_Zone_1              1
#define kPARrRgn2ObjStat_No_Object           0

#define kPARrRgn3ObjStat_Zone_15             15
#define kPARrRgn3ObjStat_Zone_14             14
#define kPARrRgn3ObjStat_Zone_13             13
#define kPARrRgn3ObjStat_Zone_12             12
#define kPARrRgn3ObjStat_Zone_11             11
#define kPARrRgn3ObjStat_Zone_10             10
#define kPARrRgn3ObjStat_Zone_9              9
#define kPARrRgn3ObjStat_Zone_8              8
#define kPARrRgn3ObjStat_Zone_7              7
#define kPARrRgn3ObjStat_Zone_6              6
#define kPARrRgn3ObjStat_Zone_5              5
#define kPARrRgn3ObjStat_Zone_4              4
#define kPARrRgn3ObjStat_Zone_3              3
#define kPARrRgn3ObjStat_Zone_2              2
#define kPARrRgn3ObjStat_Zone_1              1
#define kPARrRgn3ObjStat_No_Object           0

#define kPARrRgn4ObjStat_Zone_15             15
#define kPARrRgn4ObjStat_Zone_14             14
#define kPARrRgn4ObjStat_Zone_13             13
#define kPARrRgn4ObjStat_Zone_12             12
#define kPARrRgn4ObjStat_Zone_11             11
#define kPARrRgn4ObjStat_Zone_10             10
#define kPARrRgn4ObjStat_Zone_9              9
#define kPARrRgn4ObjStat_Zone_8              8
#define kPARrRgn4ObjStat_Zone_7              7
#define kPARrRgn4ObjStat_Zone_6              6
#define kPARrRgn4ObjStat_Zone_5              5
#define kPARrRgn4ObjStat_Zone_4              4
#define kPARrRgn4ObjStat_Zone_3              3
#define kPARrRgn4ObjStat_Zone_2              2
#define kPARrRgn4ObjStat_Zone_1              1
#define kPARrRgn4ObjStat_No_Object           0


#define kPrkAstFrSysStat_Failed              3
#define kPrkAstFrSysStat_Inhibited           2
#define kPrkAstFrSysStat_Enabled             1
#define kPrkAstFrSysStat_Disabled            0

#define kPrkAstAdvSysAct_true                1
#define kPrkAstAdvSysAct_false               0

#define kPAFrtRgn1ObjStat_Zone_15            15
#define kPAFrtRgn1ObjStat_Zone_14            14
#define kPAFrtRgn1ObjStat_Zone_13            13
#define kPAFrtRgn1ObjStat_Zone_12            12
#define kPAFrtRgn1ObjStat_Zone_11            11
#define kPAFrtRgn1ObjStat_Zone_10            10
#define kPAFrtRgn1ObjStat_Zone_9             9
#define kPAFrtRgn1ObjStat_Zone_8             8
#define kPAFrtRgn1ObjStat_Zone_7             7
#define kPAFrtRgn1ObjStat_Zone_6             6
#define kPAFrtRgn1ObjStat_Zone_5             5
#define kPAFrtRgn1ObjStat_Zone_4             4
#define kPAFrtRgn1ObjStat_Zone_3             3
#define kPAFrtRgn1ObjStat_Zone_2             2
#define kPAFrtRgn1ObjStat_Zone_1             1
#define kPAFrtRgn1ObjStat_No_Object          0

#define kPAFrtRgn2ObjStat_Zone_15            15
#define kPAFrtRgn2ObjStat_Zone_14            14
#define kPAFrtRgn2ObjStat_Zone_13            13
#define kPAFrtRgn2ObjStat_Zone_12            12
#define kPAFrtRgn2ObjStat_Zone_11            11
#define kPAFrtRgn2ObjStat_Zone_10            10
#define kPAFrtRgn2ObjStat_Zone_9             9
#define kPAFrtRgn2ObjStat_Zone_8             8
#define kPAFrtRgn2ObjStat_Zone_7             7
#define kPAFrtRgn2ObjStat_Zone_6             6
#define kPAFrtRgn2ObjStat_Zone_5             5
#define kPAFrtRgn2ObjStat_Zone_4             4
#define kPAFrtRgn2ObjStat_Zone_3             3
#define kPAFrtRgn2ObjStat_Zone_2             2
#define kPAFrtRgn2ObjStat_Zone_1             1
#define kPAFrtRgn2ObjStat_No_Object          0

#define kPAFrtRgn3ObjStat_Zone_15            15
#define kPAFrtRgn3ObjStat_Zone_14            14
#define kPAFrtRgn3ObjStat_Zone_13            13
#define kPAFrtRgn3ObjStat_Zone_12            12
#define kPAFrtRgn3ObjStat_Zone_11            11
#define kPAFrtRgn3ObjStat_Zone_10            10
#define kPAFrtRgn3ObjStat_Zone_9             9
#define kPAFrtRgn3ObjStat_Zone_8             8
#define kPAFrtRgn3ObjStat_Zone_7             7
#define kPAFrtRgn3ObjStat_Zone_6             6
#define kPAFrtRgn3ObjStat_Zone_5             5
#define kPAFrtRgn3ObjStat_Zone_4             4
#define kPAFrtRgn3ObjStat_Zone_3             3
#define kPAFrtRgn3ObjStat_Zone_2             2
#define kPAFrtRgn3ObjStat_Zone_1             1
#define kPAFrtRgn3ObjStat_No_Object          0

#define kPAFrtRgn4ObjStat_Zone_15            15
#define kPAFrtRgn4ObjStat_Zone_14            14
#define kPAFrtRgn4ObjStat_Zone_13            13
#define kPAFrtRgn4ObjStat_Zone_12            12
#define kPAFrtRgn4ObjStat_Zone_11            11
#define kPAFrtRgn4ObjStat_Zone_10            10
#define kPAFrtRgn4ObjStat_Zone_9             9
#define kPAFrtRgn4ObjStat_Zone_8             8
#define kPAFrtRgn4ObjStat_Zone_7             7
#define kPAFrtRgn4ObjStat_Zone_6             6
#define kPAFrtRgn4ObjStat_Zone_5             5
#define kPAFrtRgn4ObjStat_Zone_4             4
#define kPAFrtRgn4ObjStat_Zone_3             3
#define kPAFrtRgn4ObjStat_Zone_2             2
#define kPAFrtRgn4ObjStat_Zone_1             1
#define kPAFrtRgn4ObjStat_No_Object          0


#define kABSAtv_true                         1
#define kABSAtv_false                        0

#define kPrkBrkVDA_VirtualDeviceAvailable    1
#define kPrkBrkVDA_VirtualDeviceUnavailable  0

#define kBrkSysVDA_VirtualDeviceAvailable    1
#define kBrkSysVDA_VirtualDeviceUnavailable  0

#define kSprTireSt_Spare_Detected            2
#define kSprTireSt_No_Spare_Detected         1
#define kSprTireSt_Undetermined              0

#define kElecPrkBrkStat_Fault                2
#define kElecPrkBrkStat_Applied              1
#define kElecPrkBrkStat_Released             0


#define kODDMA_DataID2Vld_true               1
#define kODDMA_DataID2Vld_false              0
#define kODDMA_DataID3Vld_true               1
#define kODDMA_DataID3Vld_false              0
#define kODDMA_DataID4Vld_true               1
#define kODDMA_DataID4Vld_false              0
#define kODDMA_DataID5Vld_true               1
#define kODDMA_DataID5Vld_false              0
#define kODDMA_ReqType_Subscribe__FU_sends_DynData_back_and_then_on_change__ 0
#define kODDMA_ReqType_Unsubscribe__cancel_previous_Subscribe 1
#define kODDMA_DispMID_Reserved              128
#define kODDMA_DispMID_Reserved0              64
#define kODDMA_DispMID_OTIM                  32
#define kODDMA_DispMID_RearDisplayTwo        16
#define kODDMA_DispMID_RearDisplayOne        8
#define kODDMA_DispMID_AuxIP                 4
#define kODDMA_DispMID_CenterStack           2
#define kODDMA_DispMID_IPC                   1


#define kODDMC_DataID2Vld_true               1
#define kODDMC_DataID2Vld_false              0
#define kODDMC_DataID3Vld_true               1
#define kODDMC_DataID3Vld_false              0
#define kODDMC_DataID4Vld_true               1
#define kODDMC_DataID4Vld_false              0
#define kODDMC_DataID5Vld_true               1
#define kODDMC_DataID5Vld_false              0
#define kODDMC_ReqType_Subscribe__FU_sends_DynData_back_and_then_on_change__ 0
#define kODDMC_ReqType_Unsubscribe__cancel_previous_Subscribe 1
#define kODDMC_DispMID_Reserved              128
#define kODDMC_DispMID_Reserved0              64
#define kODDMC_DispMID_OTIM                  32
#define kODDMC_DispMID_RearDisplayTwo        16
#define kODDMC_DispMID_RearDisplayOne        8
#define kODDMC_DispMID_AuxIP                 4
#define kODDMC_DispMID_CenterStack           2
#define kODDMC_DispMID_IPC                   1


#define kODDMI_DataID2Vld_true               1
#define kODDMI_DataID2Vld_false              0
#define kODDMI_DataID3Vld_true               1
#define kODDMI_DataID3Vld_false              0
#define kODDMI_DataID4Vld_true               1
#define kODDMI_DataID4Vld_false              0
#define kODDMI_DataID5Vld_true               1
#define kODDMI_DataID5Vld_false              0
#define kODDMI_ReqType_Subscribe__FU_sends_DynData_back_and_then_on_change__ 0
#define kODDMI_ReqType_Unsubscribe__cancel_previous_Subscribe 1
#define kODDMI_DispMID_Reserved              128
#define kODDMI_DispMID_Reserved0              64
#define kODDMI_DispMID_OTIM                  32
#define kODDMI_DispMID_RearDisplayTwo        16
#define kODDMI_DispMID_RearDisplayOne        8
#define kODDMI_DispMID_AuxIP                 4
#define kODDMI_DispMID_CenterStack           2
#define kODDMI_DispMID_IPC                   1


#define kOtsAirTmpCrValV_Invalid             1
#define kOtsAirTmpCrValV_Valid               0

#define kOtsAirTmpV_Invalid                  1
#define kOtsAirTmpV_Valid                    0

#define kOtsAirTmpCrValMsk_Don_t_Use_Data    0
#define kOtsAirTmpCrValMsk_Use_Data          1


#define kTrlrHtchSwAtv_true                  1
#define kTrlrHtchSwAtv_false                 0

#define kRrEndCrrStat_Not_Extended           0
#define kRrEndCrrStat_Extended               1


#define kACCAct370_true                      1
#define kACCAct370_false                     0

#define kVehDynYawRateV_Invalid              1
#define kVehDynYawRateV_Valid                0


#define kSBZASysClnIndOn_true                1
#define kSBZASysClnIndOn_false               0

#define kSBZASysOffIndOn_true                1
#define kSBZASysOffIndOn_false               0

#define kSBZASysSrvIndOn_true                1
#define kSBZASysSrvIndOn_false               0

#define kSBZATmpUnvIndOn_true                1
#define kSBZATmpUnvIndOn_false               0


#define kDTCI_DTCTriggered_true              1
#define kDTCI_DTCTriggered_false             0
#define kDTCIUnused1_true                    1
#define kDTCIUnused1_false                   0
#define kDTCIUnused2_true                    1
#define kDTCIUnused2_false                   0
#define kDTCIUnused3_true                    1
#define kDTCIUnused3_false                   0
#define kDTCIUnused4_true                    1
#define kDTCIUnused4_false                   0
#define kDTCIUnused5_true                    1
#define kDTCIUnused5_false                   0
#define kDTCIUnused6_true                    1
#define kDTCIUnused6_false                   0
#define kDTCIUnused7_true                    1
#define kDTCIUnused7_false                   0
#define kDTCI_CodeSupported_true             1
#define kDTCI_CodeSupported_false            0
#define kDTCI_CurrentStatus_true             1
#define kDTCI_CurrentStatus_false            0
#define kDTCI_TstNPsdCdClrdSt_true           1
#define kDTCI_TstNPsdCdClrdSt_false          0
#define kDTCI_TstFldCdClrdStat_true          1
#define kDTCI_TstFldCdClrdStat_false         0
#define kDTCI_HistStat_true                  1
#define kDTCI_HistStat_false                 0
#define kDTCI_TstNPsdPwrUpSt_true            1
#define kDTCI_TstNPsdPwrUpSt_false           0
#define kDTCI_TstFldPwrUpSt_true             1
#define kDTCI_TstFldPwrUpSt_false            0
#define kDTCI_WrnIndRqdSt_true               1
#define kDTCI_WrnIndRqdSt_false              0
#define kDTCI_DTCFaultType_Type_C            3
#define kDTCI_DTCFaultType_Type_B            2
#define kDTCI_DTCFaultType_Type_A            1
#define kDTCI_DTCFaultType_Not_Supported     0


#define kSC_SndTne_Beep__750_Hz__Radio_Source_Muted 10
#define kSC_SndTne_High_Frequency_Broadband  9
#define kSC_SndTne_Harp                      8
#define kSC_SndTne_Gong__2000_Hz_            7
#define kSC_SndTne_Gong__750_Hz_             6
#define kSC_SndTne_Beep__2000_Hz_            5
#define kSC_SndTne_Beep__750_Hz_             4
#define kSC_SndTne_Click_Clack               3
#define kSC_SndTne_Click                     2
#define kSC_SndTne_Clack                     1
#define kSC_SndTne_Clock                     0
#define kSC_SndTne_No_Chime_with_Radio_Source_Muted 14
#define kSC_SndTne_Gong__2000_Hz__Radio_Source_Muted 13
#define kSC_SndTne_Gong__750_Hz__Radio_Source_Muted 12
#define kSC_SndTne_Beep__2000_Hz__Radio_Source_Muted 11

#define kSndLocRtRr_true                     1
#define kSndLocRtRr_false                    0
#define kSndLocLftRr_true                    1
#define kSndLocLftRr_false                   0
#define kSndLocPasFr_true                    1
#define kSndLocPasFr_false                   0
#define kSndLocDrFr_true                     1
#define kSndLocDrFr_false                    0


#define kSysBkupPwrMdEn_true                 1
#define kSysBkupPwrMdEn_false                0

#define kSysBkUpPwrMd_Crank_Request          3
#define kSysBkUpPwrMd_Run                    2
#define kSysBkUpPwrMd_Accessory              1
#define kSysBkUpPwrMd_Off                    0
#define kSysBkUpPwrMdV_Invalid               1
#define kSysBkUpPwrMdV_Valid                 0


#define kODIAI_DaTy_Bitmap                   21
#define kODIAI_DaTy_DecimalShort             20
#define kODIAI_DaTy_HoursOfDay               19
#define kODIAI_DaTy_Character                18
#define kODIAI_DaTy_Fuel_Consumption_Inverted 17
#define kODIAI_DaTy_Fuel_Consumption         16
#define kODIAI_DaTy_Pressure                 15
#define kODIAI_DaTy_Temperature              14
#define kODIAI_DaTy_Volume                   13
#define kODIAI_DaTy_DistanceShort            12
#define kODIAI_DaTy_DistanceLong             11
#define kODIAI_DaTy_BitmapId                 10
#define kODIAI_DaTy_TextId                   9
#define kODIAI_DaTy_Pictogram                8
#define kODIAI_DaTy_List_                    7
#define kODIAI_DaTy_Date                     6
#define kODIAI_DaTy_Time_                    5
#define kODIAI_DaTy_Decimal                  4
#define kODIAI_DaTy_EnumerationValue         3
#define kODIAI_DaTy_Integer                  2
#define kODIAI_DaTy_String                   1
#define kODIAI_DaTy_Speed                    0
#define kODIAI_DspMID_Reserved               128
#define kODIAI_DspMID_Reserved0               64
#define kODIAI_DspMID_OTIM                   32
#define kODIAI_DspMID_RearDisplayTwo         16
#define kODIAI_DspMID_RearDisplayOne         8
#define kODIAI_DspMID_AuxIP                  4
#define kODIAI_DspMID_CenterStack            2
#define kODIAI_DspMID_IPC                    1


#define kODIAA_DaTy_Bitmap                   21
#define kODIAA_DaTy_DecimalShort             20
#define kODIAA_DaTy_HoursOfDay               19
#define kODIAA_DaTy_Character                18
#define kODIAA_DaTy_Fuel_Consumption_Inverted 17
#define kODIAA_DaTy_Fuel_Consumption         16
#define kODIAA_DaTy_Pressure                 15
#define kODIAA_DaTy_Temperature              14
#define kODIAA_DaTy_Volume                   13
#define kODIAA_DaTy_DistanceShort            12
#define kODIAA_DaTy_DistanceLong             11
#define kODIAA_DaTy_BitmapId                 10
#define kODIAA_DaTy_TextId                   9
#define kODIAA_DaTy_Pictogram                8
#define kODIAA_DaTy_List_                    7
#define kODIAA_DaTy_Date                     6
#define kODIAA_DaTy_Time_                    5
#define kODIAA_DaTy_Decimal                  4
#define kODIAA_DaTy_EnumerationValue         3
#define kODIAA_DaTy_Integer                  2
#define kODIAA_DaTy_String                   1
#define kODIAA_DaTy_Speed                    0
#define kODIAA_DspMID_Reserved               128
#define kODIAA_DspMID_Reserved0               64
#define kODIAA_DspMID_OTIM                   32
#define kODIAA_DspMID_RearDisplayTwo         16
#define kODIAA_DspMID_RearDisplayOne         8
#define kODIAA_DspMID_AuxIP                  4
#define kODIAA_DspMID_CenterStack            2
#define kODIAA_DspMID_IPC                    1


#define kEngRunAtv_true                      1
#define kEngRunAtv_false                     0

#define kEngVDA_VirtualDeviceAvailable       1
#define kEngVDA_VirtualDeviceUnavailable     0

#define kTrnsVDA_VirtualDeviceAvailable      1
#define kTrnsVDA_VirtualDeviceUnavailable    0


#define kTrnsShftLvrPosV_0_Invalid           1
#define kTrnsShftLvrPosV_0_Valid             0
#define kTrnsShftLvrPos_0_Lever_Position_Unknown 15
#define kTrnsShftLvrPos_0_Forward_Range_H    11
#define kTrnsShftLvrPos_0_Forward_Range_G    10
#define kTrnsShftLvrPos_0_Forward_Range_F    9
#define kTrnsShftLvrPos_0_Forward_Range_E    8
#define kTrnsShftLvrPos_0_Forward_Range_D    7
#define kTrnsShftLvrPos_0_Forward_Range_C    6
#define kTrnsShftLvrPos_0_Forward_Range_B    5
#define kTrnsShftLvrPos_0_Forward_Range_A    4
#define kTrnsShftLvrPos_0_Neutral_Range      3
#define kTrnsShftLvrPos_0_Reverse_Range      2
#define kTrnsShftLvrPos_0_Park_Range         1
#define kTrnsShftLvrPos_0_Between_Ranges     0


#define kDDAjrSwAtv_true                     1
#define kDDAjrSwAtv_false                    0
#define kDDAjrSwAtvM_Don_t_Use_Data          0
#define kDDAjrSwAtvM_Use_Data                1


#define kOtsdAmbtLtLvlStatV_Invalid          1
#define kOtsdAmbtLtLvlStatV_Valid            0
#define kOtsdAmbtLtLvlStat_Day               2
#define kOtsdAmbtLtLvlStat_Night             1
#define kOtsdAmbtLtLvlStat_Unknown           0

#define kHazSwAtv_true                       1
#define kHazSwAtv_false                      0

#define kTrnSwAct_Right                      2
#define kTrnSwAct_Left                       1
#define kTrnSwAct_No_Activation              0

#define kRtTrnLmpAtv_On_with_telltale        2
#define kRtTrnLmpAtv_On_without_telltale     1
#define kRtTrnLmpAtv_Off                     0

#define kLftTrnLmpAtv_On_with_telltale       2
#define kLftTrnLmpAtv_On_without_telltale    1
#define kLftTrnLmpAtv_Off                    0


#define kVehSpdAvgDrvnV_Invalid              1
#define kVehSpdAvgDrvnV_Valid                0

#define kDistRollCntAvgDrvnV_Invalid         1
#define kDistRollCntAvgDrvnV_Valid           0

#define kVehSpdAvgNDrvnV_Invalid             1
#define kVehSpdAvgNDrvnV_Valid               0


#define kSysPwrMd_Crank_Request              3
#define kSysPwrMd_Run                        2
#define kSysPwrMd_Accessory                  1
#define kSysPwrMd_Off                        0
#define kSysPwrMdV_Invalid                   1
#define kSysPwrMdV_Valid                     0


#define kTrnsShftLvrPosV_1_Invalid           1
#define kTrnsShftLvrPosV_1_Valid             0
#define kTrnsShftLvrPos_1_Lever_Position_Unknown 15
#define kTrnsShftLvrPos_1_Forward_Range_H    11
#define kTrnsShftLvrPos_1_Forward_Range_G    10
#define kTrnsShftLvrPos_1_Forward_Range_F    9
#define kTrnsShftLvrPos_1_Forward_Range_E    8
#define kTrnsShftLvrPos_1_Forward_Range_D    7
#define kTrnsShftLvrPos_1_Forward_Range_C    6
#define kTrnsShftLvrPos_1_Forward_Range_B    5
#define kTrnsShftLvrPos_1_Forward_Range_A    4
#define kTrnsShftLvrPos_1_Neutral_Range      3
#define kTrnsShftLvrPos_1_Reverse_Range      2
#define kTrnsShftLvrPos_1_Park_Range         1
#define kTrnsShftLvrPos_1_Between_Ranges     0


#define kWhlGrndVlctyLftNnDrvnV_1_Invalid    1
#define kWhlGrndVlctyLftNnDrvnV_1_Valid      0

#define kWhlGrndVlctyRtNnDrvnV_1_Invalid     1
#define kWhlGrndVlctyRtNnDrvnV_1_Valid       0


#define kWhlGrndVlctyLftDrvnV_1_Invalid      1
#define kWhlGrndVlctyLftDrvnV_1_Valid        0

#define kWhlGrndVlctyRtDrvnV_1_Invalid       1
#define kWhlGrndVlctyRtDrvnV_1_Valid         0


#define kStrWhAngMsk_Don_t_Use_Data          0
#define kStrWhAngMsk_Use_Data                1

#define kStrWhlAngSenCalStat_1_Calibrated    2
#define kStrWhlAngSenCalStat_1_Estimated     1
#define kStrWhlAngSenCalStat_1_Unknown       0

#define kStrWhAngV_1_Invalid                 1
#define kStrWhAngV_1_Valid                   0

#define kStrWhAngGrdV_Valid                  0
#define kStrWhAngGrdV_Invalid                1



#define kWRSLNDWhlDistVal_1_Invalid          1
#define kWRSLNDWhlDistVal_1_Valid            0
#define kWRSLNDWhlRotStRst_1_true            1
#define kWRSLNDWhlRotStRst_1_false           0

#define kWRSRNDWhlDistVal_1_Invalid          1
#define kWRSRNDWhlDistVal_1_Valid            0
#define kWRSRNDWhlRotStRst_1_true            1
#define kWRSRNDWhlRotStRst_1_false           0


#define kWRSLDWhlDistVal_1_Invalid           1
#define kWRSLDWhlDistVal_1_Valid             0
#define kWRSLDWhlRotStatRst_1_true           1
#define kWRSLDWhlRotStatRst_1_false          0

#define kWRSRDWhlDistVal_1_Invalid           1
#define kWRSRDWhlDistVal_1_Valid             0
#define kWRSRDWhlRotStatRst_1_true           1
#define kWRSRDWhlRotStatRst_1_false          0


#define kStrWhlTctlFdbkReqAct_true           1
#define kStrWhlTctlFdbkReqAct_false          0

#define kSWAR_ReqActV_Invalid                1
#define kSWAR_ReqActV_Valid                  0
#define kSWAR_ReqAct_true                    1
#define kSWAR_ReqAct_false                   0


#define kElecPwrStrAvalStat_Temp_inhibit     0
#define kElecPwrStrAvalStat_Available_for_control 1
#define kElecPwrStrAvalStat_Active           2
#define kElecPwrStrAvalStat_Permanently_failed 3

#define kDrvStrIntfrDtcdV_Invalid            1
#define kDrvStrIntfrDtcdV_Valid              0
#define kDrvStrIntfrDtcd_true                1
#define kDrvStrIntfrDtcd_false               0



#define kIMULonAccPriV_Valid                 0
#define kIMULonAccPriV_Invalid               1


#define kIMUYawRtPriV_Invalid                1
#define kIMUYawRtPriV_Valid                  0

#define kIMULatAccPrimV_Invalid              1
#define kIMULatAccPrimV_Valid                0




/* -----------------------------------------------------------------------------
    &&&~ Message Unions
 ----------------------------------------------------------------------------- */

typedef union _c_UUDT_Resp_From_UPA_APA_LS_bufTag
{
  unsigned char _c[8];
  _c_UUDT_Resp_From_UPA_APA_LS_msgType UUDT_Resp_From_UPA_APA_LS;
} _c_UUDT_Resp_From_UPA_APA_LS_buf;
typedef union _c_USDT_Resp_From_UPA_APA_LS_bufTag
{
  unsigned char _c[8];
  _c_USDT_Resp_From_UPA_APA_LS_msgType USDT_Resp_From_UPA_APA_LS;
} _c_USDT_Resp_From_UPA_APA_LS_buf;
typedef union _c_Teen_Driver_Control_Info_LS_bufTag
{
  unsigned char _c[5];
  _c_Teen_Driver_Control_Info_LS_msgType Teen_Driver_Control_Info_LS;
} _c_Teen_Driver_Control_Info_LS_buf;
typedef union _c_Park_Assist_ESSprocess_Info_LS_bufTag
{
  unsigned char _c[1];
  _c_Park_Assist_ESSprocess_Info_LS_msgType Park_Assist_ESSprocess_Info_LS;
} _c_Park_Assist_ESSprocess_Info_LS_buf;
typedef union _c_Park_Assist_ESSbased_Info_LS_bufTag
{
  unsigned char _c[5];
  _c_Park_Assist_ESSbased_Info_LS_msgType Park_Assist_ESSbased_Info_LS;
} _c_Park_Assist_ESSbased_Info_LS_buf;
typedef union _c_Park_Assistant_Right_Status_LS_bufTag
{
  unsigned char _c[2];
  _c_Park_Assistant_Right_Status_LS_msgType Park_Assistant_Right_Status_LS;
} _c_Park_Assistant_Right_Status_LS_buf;
typedef union _c_Park_Assistant_Left_Status_LS_bufTag
{
  unsigned char _c[2];
  _c_Park_Assistant_Left_Status_LS_msgType Park_Assistant_Left_Status_LS;
} _c_Park_Assistant_Left_Status_LS_buf;
typedef union _c_Haptic_Seat_Status_LS_bufTag
{
  unsigned char _c[1];
  _c_Haptic_Seat_Status_LS_msgType Haptic_Seat_Status_LS;
} _c_Haptic_Seat_Status_LS_buf;
typedef union _c_Frnt_Prk_Ast_Drv_Seat_Vib_Req_LS_bufTag
{
  unsigned char _c[1];
  _c_Frnt_Prk_Ast_Drv_Seat_Vib_Req_LS_msgType Frnt_Prk_Ast_Drv_Seat_Vib_Req_LS;
} _c_Frnt_Prk_Ast_Drv_Seat_Vib_Req_LS_buf;
typedef union _c_Rear_Prk_Ast_Drv_Seat_Vib_Req_LS_bufTag
{
  unsigned char _c[1];
  _c_Rear_Prk_Ast_Drv_Seat_Vib_Req_LS_msgType Rear_Prk_Ast_Drv_Seat_Vib_Req_LS;
} _c_Rear_Prk_Ast_Drv_Seat_Vib_Req_LS_buf;
typedef union _c_Analog_Values_Slow_LS_bufTag
{
  unsigned char _c[8];
  _c_Analog_Values_Slow_LS_msgType Analog_Values_Slow_LS;
  _c_Analog_Values_Slow_LS_EngCltTmpGroup_msgType Analog_Values_Slow_LS_EngCltTmpGroup;
  _c_Analog_Values_Slow_LS_EngIntAirTmpGroup_msgType Analog_Values_Slow_LS_EngIntAirTmpGroup;
  _c_Analog_Values_Slow_LS_OAT_PT_EstGroup_msgType Analog_Values_Slow_LS_OAT_PT_EstGroup;
} _c_Analog_Values_Slow_LS_buf;
typedef union _c_Wheel_Pulses_LS_bufTag
{
  unsigned char _c[2];
  _c_Wheel_Pulses_LS_msgType Wheel_Pulses_LS;
} _c_Wheel_Pulses_LS_buf;
typedef union _c_ODIIndication_LS_bufTag
{
  unsigned char _c[8];
  _c_ODIIndication_LS_msgType ODIIndication_LS;
  _c_ODIIndication_LS_ODIInd_msgType ODIIndication_LS_ODIInd;
} _c_ODIIndication_LS_buf;
typedef union _c_ODIEvent_LS_bufTag
{
  unsigned char _c[4];
  _c_ODIEvent_LS_msgType ODIEvent_LS;
  _c_ODIEvent_LS_ODIEvntPkt_msgType ODIEvent_LS_ODIEvntPkt;
} _c_ODIEvent_LS_buf;
typedef union _c_Infrastructure_Timer_Status_LS_bufTag
{
  unsigned char _c[5];
  _c_Infrastructure_Timer_Status_LS_msgType Infrastructure_Timer_Status_LS;
  _c_Infrastructure_Timer_Status_LS_EngOffTmExtRngGroup_msgType Infrastructure_Timer_Status_LS_EngOffTmExtRngGroup;
} _c_Infrastructure_Timer_Status_LS_buf;
typedef union _c_Park_Assistant_General_Status_bufTag
{
  unsigned char _c[1];
  _c_Park_Assistant_General_Status_msgType Park_Assistant_General_Status;
} _c_Park_Assistant_General_Status_buf;
typedef union _c_Chime_Active_bufTag
{
  unsigned char _c[1];
  _c_Chime_Active_msgType Chime_Active;
} _c_Chime_Active_buf;
typedef union _c_ODIDynamicData_LS_bufTag
{
  unsigned char _c[8];
  _c_ODIDynamicData_LS_msgType ODIDynamicData_LS;
  _c_ODIDynamicData_LS_ODIDynData_msgType ODIDynamicData_LS_ODIDynData;
} _c_ODIDynamicData_LS_buf;
typedef union _c_ODIEnumDynamicData_LS_bufTag
{
  unsigned char _c[8];
  _c_ODIEnumDynamicData_LS_msgType ODIEnumDynamicData_LS;
  _c_ODIEnumDynamicData_LS_ODIEnmDynData_msgType ODIEnumDynamicData_LS_ODIEnmDynData;
} _c_ODIEnumDynamicData_LS_buf;
typedef union _c_ODIAction_CntrStack_LS_bufTag
{
  unsigned char _c[8];
  _c_ODIAction_CntrStack_LS_msgType ODIAction_CntrStack_LS;
  _c_ODIAction_CntrStack_LS_ODIActn_CntrStck_msgType ODIAction_CntrStack_LS_ODIActn_CntrStck;
} _c_ODIAction_CntrStack_LS_buf;
typedef union _c_Man_Prk_Brk_LS_bufTag
{
  unsigned char _c[1];
  _c_Man_Prk_Brk_LS_msgType Man_Prk_Brk_LS;
} _c_Man_Prk_Brk_LS_buf;
typedef union _c_Vehicle_Stability_LS_bufTag
{
  unsigned char _c[6];
  _c_Vehicle_Stability_LS_msgType Vehicle_Stability_LS;
  _c_Vehicle_Stability_LS_VSELongAccLoResGroup_msgType Vehicle_Stability_LS_VSELongAccLoResGroup;
  _c_Vehicle_Stability_LS_StrWhAngGroup_0_msgType Vehicle_Stability_LS_StrWhAngGroup_0;
} _c_Vehicle_Stability_LS_buf;
typedef union _c_Wheel_Grnd_Velocity_LS_bufTag
{
  unsigned char _c[8];
  _c_Wheel_Grnd_Velocity_LS_msgType Wheel_Grnd_Velocity_LS;
  _c_Wheel_Grnd_Velocity_LS_WhlGrndVlctyLftDrvnGroup_0_msgType Wheel_Grnd_Velocity_LS_WhlGrndVlctyLftDrvnGroup_0;
  _c_Wheel_Grnd_Velocity_LS_WhlGrndVlctyLftNnDrvnGroup_0_msgType Wheel_Grnd_Velocity_LS_WhlGrndVlctyLftNnDrvnGroup_0;
  _c_Wheel_Grnd_Velocity_LS_WhlGrndVlctyRtDrvnGroup_0_msgType Wheel_Grnd_Velocity_LS_WhlGrndVlctyRtDrvnGroup_0;
  _c_Wheel_Grnd_Velocity_LS_WhlGrndVlctyRtNnDrvnGroup_0_msgType Wheel_Grnd_Velocity_LS_WhlGrndVlctyRtNnDrvnGroup_0;
} _c_Wheel_Grnd_Velocity_LS_buf;
typedef union _c_Non_Drvn_Whl_Rot_Status_LS_bufTag
{
  unsigned char _c[8];
  _c_Non_Drvn_Whl_Rot_Status_LS_msgType Non_Drvn_Whl_Rot_Status_LS;
  _c_Non_Drvn_Whl_Rot_Status_LS_WhlRotStatLftNDrvn_0_msgType Non_Drvn_Whl_Rot_Status_LS_WhlRotStatLftNDrvn_0;
  _c_Non_Drvn_Whl_Rot_Status_LS_WhlRotStatRghtNDrvn_0_msgType Non_Drvn_Whl_Rot_Status_LS_WhlRotStatRghtNDrvn_0;
} _c_Non_Drvn_Whl_Rot_Status_LS_buf;
typedef union _c_Driven_Whl_Rotational_Stat_LS_bufTag
{
  unsigned char _c[8];
  _c_Driven_Whl_Rotational_Stat_LS_msgType Driven_Whl_Rotational_Stat_LS;
  _c_Driven_Whl_Rotational_Stat_LS_WhlRotatStatLftDrvn_0_msgType Driven_Whl_Rotational_Stat_LS_WhlRotatStatLftDrvn_0;
  _c_Driven_Whl_Rotational_Stat_LS_WhlRotatStatRtDrvn_0_msgType Driven_Whl_Rotational_Stat_LS_WhlRotatStatRtDrvn_0;
} _c_Driven_Whl_Rotational_Stat_LS_buf;
typedef union _c_Power_Mode_Info_LS_bufTag
{
  unsigned char _c[2];
  _c_Power_Mode_Info_LS_msgType Power_Mode_Info_LS;
} _c_Power_Mode_Info_LS_buf;
typedef union _c_Park_Assistant_Rear_Status_bufTag
{
  unsigned char _c[4];
  _c_Park_Assistant_Rear_Status_msgType Park_Assistant_Rear_Status;
} _c_Park_Assistant_Rear_Status_buf;
typedef union _c_Park_Assistant_Front_Status_bufTag
{
  unsigned char _c[4];
  _c_Park_Assistant_Front_Status_msgType Park_Assistant_Front_Status;
} _c_Park_Assistant_Front_Status_buf;
typedef union _c_Chassis_Information_LS_bufTag
{
  unsigned char _c[5];
  _c_Chassis_Information_LS_msgType Chassis_Information_LS;
} _c_Chassis_Information_LS_buf;
typedef union _c_ODIDynDataMultiRequest_AuxIP_LS_bufTag
{
  unsigned char _c[8];
  _c_ODIDynDataMultiRequest_AuxIP_LS_msgType ODIDynDataMultiRequest_AuxIP_LS;
  _c_ODIDynDataMultiRequest_AuxIP_LS_ODIDynDataMltRq_AuxIP_msgType ODIDynDataMultiRequest_AuxIP_LS_ODIDynDataMltRq_AuxIP;
} _c_ODIDynDataMultiRequest_AuxIP_LS_buf;
typedef union _c_ODIDynDataMultiReq_CntrStack_LS_bufTag
{
  unsigned char _c[8];
  _c_ODIDynDataMultiReq_CntrStack_LS_msgType ODIDynDataMultiReq_CntrStack_LS;
  _c_ODIDynDataMultiReq_CntrStack_LS_ODIDynDataMltRq_CntrStck_msgType ODIDynDataMultiReq_CntrStack_LS_ODIDynDataMltRq_CntrStck;
} _c_ODIDynDataMultiReq_CntrStack_LS_buf;
typedef union _c_ODIDynDataMultiRequest_IPC_LS_bufTag
{
  unsigned char _c[8];
  _c_ODIDynDataMultiRequest_IPC_LS_msgType ODIDynDataMultiRequest_IPC_LS;
  _c_ODIDynDataMultiRequest_IPC_LS_ODIDynDataMltRq_IPC_msgType ODIDynDataMultiRequest_IPC_LS_ODIDynDataMltRq_IPC;
} _c_ODIDynDataMultiRequest_IPC_LS_buf;
typedef union _c_Outside_Air_Temperature_LS_bufTag
{
  unsigned char _c[3];
  _c_Outside_Air_Temperature_LS_msgType Outside_Air_Temperature_LS;
  _c_Outside_Air_Temperature_LS_OtsAirTmpCrValGroup_msgType Outside_Air_Temperature_LS_OtsAirTmpCrValGroup;
  _c_Outside_Air_Temperature_LS_OtsAirTmpGroup_msgType Outside_Air_Temperature_LS_OtsAirTmpGroup;
} _c_Outside_Air_Temperature_LS_buf;
typedef union _c_Trailer_Status_LS_bufTag
{
  unsigned char _c[2];
  _c_Trailer_Status_LS_msgType Trailer_Status_LS;
} _c_Trailer_Status_LS_buf;
typedef union _c_ACC_YawRate_Information_LS_bufTag
{
  unsigned char _c[6];
  _c_ACC_YawRate_Information_LS_msgType ACC_YawRate_Information_LS;
  _c_ACC_YawRate_Information_LS_VehDynYawRateGroup_msgType ACC_YawRate_Information_LS_VehDynYawRateGroup;
} _c_ACC_YawRate_Information_LS_buf;
typedef union _c_Side_Blind_Zone_Alert_Status_bufTag
{
  unsigned char _c[1];
  _c_Side_Blind_Zone_Alert_Status_msgType Side_Blind_Zone_Alert_Status;
} _c_Side_Blind_Zone_Alert_Status_buf;
typedef union _c_VIN_Digits_10_to_17_bufTag
{
  unsigned char _c[8];
  _c_VIN_Digits_10_to_17_msgType VIN_Digits_10_to_17;
} _c_VIN_Digits_10_to_17_buf;
typedef union _c_VIN_Digits_2_to_9_bufTag
{
  unsigned char _c[8];
  _c_VIN_Digits_2_to_9_msgType VIN_Digits_2_to_9;
} _c_VIN_Digits_2_to_9_buf;
typedef union _c_DTC_Triggered_bufTag
{
  unsigned char _c[7];
  _c_DTC_Triggered_msgType DTC_Triggered;
  _c_DTC_Triggered_DTCInfo_msgType DTC_Triggered_DTCInfo;
} _c_DTC_Triggered_buf;
typedef union _c_Chime_Command_bufTag
{
  unsigned char _c[5];
  _c_Chime_Command_msgType Chime_Command;
  _c_Chime_Command_SndChrs_msgType Chime_Command_SndChrs;
  _c_Chime_Command_SndLoc_msgType Chime_Command_SndLoc;
} _c_Chime_Command_buf;
typedef union _c_System_Power_Mode_Backup_LS_bufTag
{
  unsigned char _c[1];
  _c_System_Power_Mode_Backup_LS_msgType System_Power_Mode_Backup_LS;
  _c_System_Power_Mode_Backup_LS_SysBkUpPwrMdGroup_msgType System_Power_Mode_Backup_LS_SysBkUpPwrMdGroup;
} _c_System_Power_Mode_Backup_LS_buf;
typedef union _c_ODIAction_IPC_LS_bufTag
{
  unsigned char _c[8];
  _c_ODIAction_IPC_LS_msgType ODIAction_IPC_LS;
  _c_ODIAction_IPC_LS_ODIActn_IPC_msgType ODIAction_IPC_LS_ODIActn_IPC;
} _c_ODIAction_IPC_LS_buf;
typedef union _c_ODIAction_AuxIP_LS_bufTag
{
  unsigned char _c[8];
  _c_ODIAction_AuxIP_LS_msgType ODIAction_AuxIP_LS;
  _c_ODIAction_AuxIP_LS_ODIActn_AxIP_msgType ODIAction_AuxIP_LS_ODIActn_AxIP;
} _c_ODIAction_AuxIP_LS_buf;
typedef union _c_Engine_Information_2_LS_bufTag
{
  unsigned char _c[3];
  _c_Engine_Information_2_LS_msgType Engine_Information_2_LS;
} _c_Engine_Information_2_LS_buf;
typedef union _c_Engine_Information_1_LS_bufTag
{
  unsigned char _c[7];
  _c_Engine_Information_1_LS_msgType Engine_Information_1_LS;
  _c_Engine_Information_1_LS_TrnsShftLvrPosGroup_0_msgType Engine_Information_1_LS_TrnsShftLvrPosGroup_0;
} _c_Engine_Information_1_LS_buf;
typedef union _c_Driver_Door_Status_bufTag
{
  unsigned char _c[1];
  _c_Driver_Door_Status_msgType Driver_Door_Status;
  _c_Driver_Door_Status_DDAjrSwAtvGroup_msgType Driver_Door_Status_DDAjrSwAtvGroup;
} _c_Driver_Door_Status_buf;
typedef union _c_Lighting_Status_LS_bufTag
{
  unsigned char _c[4];
  _c_Lighting_Status_LS_msgType Lighting_Status_LS;
  _c_Lighting_Status_LS_OtsdAmbtLtLvlStatGroup_msgType Lighting_Status_LS_OtsdAmbtLtLvlStatGroup;
} _c_Lighting_Status_LS_buf;
typedef union _c_Vehicle_Speed_Information_bufTag
{
  unsigned char _c[7];
  _c_Vehicle_Speed_Information_msgType Vehicle_Speed_Information;
  _c_Vehicle_Speed_Information_VehSpdAvgDrvnGroup_msgType Vehicle_Speed_Information_VehSpdAvgDrvnGroup;
  _c_Vehicle_Speed_Information_DistRollCntAvgDrvnGroup_msgType Vehicle_Speed_Information_DistRollCntAvgDrvnGroup;
  _c_Vehicle_Speed_Information_VehSpdAvgNDrvnGroup_msgType Vehicle_Speed_Information_VehSpdAvgNDrvnGroup;
} _c_Vehicle_Speed_Information_buf;
typedef union _c_System_Power_Mode_LS_bufTag
{
  unsigned char _c[1];
  _c_System_Power_Mode_LS_msgType System_Power_Mode_LS;
  _c_System_Power_Mode_LS_SysPwrMdGroup_msgType System_Power_Mode_LS_SysPwrMdGroup;
} _c_System_Power_Mode_LS_buf;
typedef union _c_UUDT_Resp_From_APA_CE_bufTag
{
  unsigned char _c[8];
  _c_UUDT_Resp_From_APA_CE_msgType UUDT_Resp_From_APA_CE;
} _c_UUDT_Resp_From_APA_CE_buf;
typedef union _c_USDT_Resp_From_APA_CE_bufTag
{
  unsigned char _c[8];
  _c_USDT_Resp_From_APA_CE_msgType USDT_Resp_From_APA_CE;
} _c_USDT_Resp_From_APA_CE_buf;
typedef union _c_Trans_General_Status_2_CE_bufTag
{
  unsigned char _c[3];
  _c_Trans_General_Status_2_CE_msgType Trans_General_Status_2_CE;
  _c_Trans_General_Status_2_CE_TrnsShftLvrPosGroup_1_msgType Trans_General_Status_2_CE_TrnsShftLvrPosGroup_1;
} _c_Trans_General_Status_2_CE_buf;
typedef union _c_NonDriven_Wheel_Grnd_Velocity_CE_bufTag
{
  unsigned char _c[5];
  _c_NonDriven_Wheel_Grnd_Velocity_CE_msgType NonDriven_Wheel_Grnd_Velocity_CE;
  _c_NonDriven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyLftNnDrvnGroup_1_msgType NonDriven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyLftNnDrvnGroup_1;
  _c_NonDriven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyRtNnDrvnGroup_1_msgType NonDriven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyRtNnDrvnGroup_1;
} _c_NonDriven_Wheel_Grnd_Velocity_CE_buf;
typedef union _c_Driven_Wheel_Grnd_Velocity_CE_bufTag
{
  unsigned char _c[5];
  _c_Driven_Wheel_Grnd_Velocity_CE_msgType Driven_Wheel_Grnd_Velocity_CE;
  _c_Driven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyLftDrvnGroup_1_msgType Driven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyLftDrvnGroup_1;
  _c_Driven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyRtDrvnGroup_1_msgType Driven_Wheel_Grnd_Velocity_CE_WhlGrndVlctyRtDrvnGroup_1;
} _c_Driven_Wheel_Grnd_Velocity_CE_buf;
typedef union _c_PPEI_Steering_Wheel_Angle_CE_bufTag
{
  unsigned char _c[8];
  _c_PPEI_Steering_Wheel_Angle_CE_msgType PPEI_Steering_Wheel_Angle_CE;
  _c_PPEI_Steering_Wheel_Angle_CE_StrWhAngGroup_1_msgType PPEI_Steering_Wheel_Angle_CE_StrWhAngGroup_1;
  _c_PPEI_Steering_Wheel_Angle_CE_StrWhAngGrdGroup_msgType PPEI_Steering_Wheel_Angle_CE_StrWhAngGrdGroup;
} _c_PPEI_Steering_Wheel_Angle_CE_buf;
typedef union _c_Brake_Apply_Information_CE_bufTag
{
  unsigned char _c[8];
  _c_Brake_Apply_Information_CE_msgType Brake_Apply_Information_CE;
} _c_Brake_Apply_Information_CE_buf;
typedef union _c_NonDrivn_Whl_Rotationl_Stat_CE_bufTag
{
  unsigned char _c[8];
  _c_NonDrivn_Whl_Rotationl_Stat_CE_msgType NonDrivn_Whl_Rotationl_Stat_CE;
  _c_NonDrivn_Whl_Rotationl_Stat_CE_WhlRotStatLftNDrvn_1_msgType NonDrivn_Whl_Rotationl_Stat_CE_WhlRotStatLftNDrvn_1;
  _c_NonDrivn_Whl_Rotationl_Stat_CE_WhlRotStatRghtNDrvn_1_msgType NonDrivn_Whl_Rotationl_Stat_CE_WhlRotStatRghtNDrvn_1;
} _c_NonDrivn_Whl_Rotationl_Stat_CE_buf;
typedef union _c_Driven_Whl_Rotational_Stat_CE_bufTag
{
  unsigned char _c[8];
  _c_Driven_Whl_Rotational_Stat_CE_msgType Driven_Whl_Rotational_Stat_CE;
  _c_Driven_Whl_Rotational_Stat_CE_WhlRotatStatLftDrvn_1_msgType Driven_Whl_Rotational_Stat_CE_WhlRotatStatLftDrvn_1;
  _c_Driven_Whl_Rotational_Stat_CE_WhlRotatStatRtDrvn_1_msgType Driven_Whl_Rotational_Stat_CE_WhlRotatStatRtDrvn_1;
} _c_Driven_Whl_Rotational_Stat_CE_buf;
typedef union _c_Park_Assist_Parallel_CE_bufTag
{
  unsigned char _c[7];
  _c_Park_Assist_Parallel_CE_msgType Park_Assist_Parallel_CE;
  _c_Park_Assist_Parallel_CE_StrWhlAngReq_msgType Park_Assist_Parallel_CE_StrWhlAngReq;
} _c_Park_Assist_Parallel_CE_buf;
typedef union _c_Electric_Power_Steering_CE_bufTag
{
  unsigned char _c[2];
  _c_Electric_Power_Steering_CE_msgType Electric_Power_Steering_CE;
  _c_Electric_Power_Steering_CE_DrvStrIntfrDtcdGroup_msgType Electric_Power_Steering_CE_DrvStrIntfrDtcdGroup;
} _c_Electric_Power_Steering_CE_buf;
typedef union _c_HS_Information_1_CE_bufTag
{
  unsigned char _c[6];
  _c_HS_Information_1_CE_msgType HS_Information_1_CE;
} _c_HS_Information_1_CE_buf;
typedef union _c_IMU_Yaw_Long_Acc_CE_bufTag
{
  unsigned char _c[8];
  _c_IMU_Yaw_Long_Acc_CE_msgType IMU_Yaw_Long_Acc_CE;
  _c_IMU_Yaw_Long_Acc_CE_IMULonAccPriGroup_msgType IMU_Yaw_Long_Acc_CE_IMULonAccPriGroup;
} _c_IMU_Yaw_Long_Acc_CE_buf;
typedef union _c_IMU_Yaw_Latitud_Acc_CE_bufTag
{
  unsigned char _c[8];
  _c_IMU_Yaw_Latitud_Acc_CE_msgType IMU_Yaw_Latitud_Acc_CE;
  _c_IMU_Yaw_Latitud_Acc_CE_IMUYawRtPriGroup_msgType IMU_Yaw_Latitud_Acc_CE_IMUYawRtPriGroup;
  _c_IMU_Yaw_Latitud_Acc_CE_IMULatAccPrimGroup_msgType IMU_Yaw_Latitud_Acc_CE_IMULatAccPrimGroup;
} _c_IMU_Yaw_Latitud_Acc_CE_buf;
typedef union _c_SSAE_Debug_Msg_0F_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_0F_msgType SSAE_Debug_Msg_0F;
} _c_SSAE_Debug_Msg_0F_buf;
typedef union _c_SSAE_Debug_Msg_0E_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_0E_msgType SSAE_Debug_Msg_0E;
} _c_SSAE_Debug_Msg_0E_buf;
typedef union _c_SSAE_Debug_Msg_0D_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_0D_msgType SSAE_Debug_Msg_0D;
} _c_SSAE_Debug_Msg_0D_buf;
typedef union _c_SSAE_Debug_Msg_0C_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_0C_msgType SSAE_Debug_Msg_0C;
} _c_SSAE_Debug_Msg_0C_buf;
typedef union _c_SSAE_Debug_Msg_0B_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_0B_msgType SSAE_Debug_Msg_0B;
} _c_SSAE_Debug_Msg_0B_buf;
typedef union _c_SSAE_Debug_Msg_0A_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_0A_msgType SSAE_Debug_Msg_0A;
} _c_SSAE_Debug_Msg_0A_buf;
typedef union _c_SSAE_Debug_Msg_09_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_09_msgType SSAE_Debug_Msg_09;
} _c_SSAE_Debug_Msg_09_buf;
typedef union _c_SSAE_Debug_Msg_08_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_08_msgType SSAE_Debug_Msg_08;
} _c_SSAE_Debug_Msg_08_buf;
typedef union _c_SSAE_Debug_Msg_07_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_07_msgType SSAE_Debug_Msg_07;
} _c_SSAE_Debug_Msg_07_buf;
typedef union _c_SSAE_Debug_Msg_06_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_06_msgType SSAE_Debug_Msg_06;
} _c_SSAE_Debug_Msg_06_buf;
typedef union _c_SSAE_Debug_Msg_05_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_05_msgType SSAE_Debug_Msg_05;
} _c_SSAE_Debug_Msg_05_buf;
typedef union _c_SSAE_Debug_Msg_04_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_04_msgType SSAE_Debug_Msg_04;
} _c_SSAE_Debug_Msg_04_buf;
typedef union _c_SSAE_Debug_Msg_03_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_03_msgType SSAE_Debug_Msg_03;
} _c_SSAE_Debug_Msg_03_buf;
typedef union _c_SSAE_Debug_Msg_02_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_02_msgType SSAE_Debug_Msg_02;
} _c_SSAE_Debug_Msg_02_buf;
typedef union _c_SSAE_Debug_Msg_01_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_01_msgType SSAE_Debug_Msg_01;
} _c_SSAE_Debug_Msg_01_buf;
typedef union _c_SSAE_Debug_Msg_00_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_00_msgType SSAE_Debug_Msg_00;
} _c_SSAE_Debug_Msg_00_buf;
typedef union _c_SSAE_Debug_Msg_16_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_16_msgType SSAE_Debug_Msg_16;
} _c_SSAE_Debug_Msg_16_buf;
typedef union _c_SSAE_Debug_Msg_15_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_15_msgType SSAE_Debug_Msg_15;
} _c_SSAE_Debug_Msg_15_buf;
typedef union _c_SSAE_Debug_Msg_14_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_14_msgType SSAE_Debug_Msg_14;
} _c_SSAE_Debug_Msg_14_buf;
typedef union _c_SSAE_Debug_Msg_13_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_13_msgType SSAE_Debug_Msg_13;
} _c_SSAE_Debug_Msg_13_buf;
typedef union _c_SSAE_Debug_Msg_12_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_12_msgType SSAE_Debug_Msg_12;
} _c_SSAE_Debug_Msg_12_buf;
typedef union _c_SSAE_Debug_Msg_11_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_11_msgType SSAE_Debug_Msg_11;
} _c_SSAE_Debug_Msg_11_buf;
typedef union _c_SSAE_Debug_Msg_10_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_10_msgType SSAE_Debug_Msg_10;
} _c_SSAE_Debug_Msg_10_buf;
typedef union _c_SSAE_Debug_Msg_18_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_18_msgType SSAE_Debug_Msg_18;
} _c_SSAE_Debug_Msg_18_buf;
typedef union _c_SSAE_Debug_Msg_17_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_17_msgType SSAE_Debug_Msg_17;
} _c_SSAE_Debug_Msg_17_buf;
typedef union _c_SSAE_Debug_Msg_1A_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_1A_msgType SSAE_Debug_Msg_1A;
} _c_SSAE_Debug_Msg_1A_buf;
typedef union _c_SSAE_Debug_Msg_19_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_19_msgType SSAE_Debug_Msg_19;
} _c_SSAE_Debug_Msg_19_buf;
typedef union _c_SSAE_Debug_Msg_1B_bufTag
{
  unsigned char _c[8];
  _c_SSAE_Debug_Msg_1B_msgType SSAE_Debug_Msg_1B;
} _c_SSAE_Debug_Msg_1B_buf;
/* -----------------------------------------------------------------------------
    &&&~ Signal Unions for group signals
 ----------------------------------------------------------------------------- */

typedef union _c_ODIDynData_bufTag
{
  unsigned char _c[7];
  _c_ODIDynData_msgType ODIDynData;
} _c_ODIDynData_buf;
typedef union _c_ODIEnmDynData_bufTag
{
  unsigned char _c[8];
  _c_ODIEnmDynData_msgType ODIEnmDynData;
} _c_ODIEnmDynData_buf;
typedef union _c_ODIInd_bufTag
{
  unsigned char _c[8];
  _c_ODIInd_msgType ODIInd;
} _c_ODIInd_buf;
typedef union _c_ODIEvntPkt_bufTag
{
  unsigned char _c[3];
  _c_ODIEvntPkt_msgType ODIEvntPkt;
} _c_ODIEvntPkt_buf;
typedef union _c_DTCInfo_bufTag
{
  unsigned char _c[7];
  _c_DTCInfo_msgType DTCInfo;
} _c_DTCInfo_buf;
typedef union _c_SndChrs_bufTag
{
  unsigned char _c[4];
  _c_SndChrs_msgType SndChrs;
} _c_SndChrs_buf;
typedef union _c_SndLoc_bufTag
{
  unsigned char _c[1];
  _c_SndLoc_msgType SndLoc;
} _c_SndLoc_buf;
typedef union _c_StrWhlAngReq_bufTag
{
  unsigned char _c[3];
  _c_StrWhlAngReq_msgType StrWhlAngReq;
} _c_StrWhlAngReq_buf;
typedef union _c_ODIDynDataMltRq_IPC_bufTag
{
  unsigned char _c[8];
  _c_ODIDynDataMltRq_IPC_msgType ODIDynDataMltRq_IPC;
} _c_ODIDynDataMltRq_IPC_buf;
typedef union _c_ODIDynDataMltRq_CntrStck_bufTag
{
  unsigned char _c[8];
  _c_ODIDynDataMltRq_CntrStck_msgType ODIDynDataMltRq_CntrStck;
} _c_ODIDynDataMltRq_CntrStck_buf;
typedef union _c_ODIDynDataMltRq_AuxIP_bufTag
{
  unsigned char _c[8];
  _c_ODIDynDataMltRq_AuxIP_msgType ODIDynDataMltRq_AuxIP;
} _c_ODIDynDataMltRq_AuxIP_buf;
typedef union _c_ODIActn_IPC_bufTag
{
  unsigned char _c[8];
  _c_ODIActn_IPC_msgType ODIActn_IPC;
} _c_ODIActn_IPC_buf;
typedef union _c_ODIActn_CntrStck_bufTag
{
  unsigned char _c[8];
  _c_ODIActn_CntrStck_msgType ODIActn_CntrStck;
} _c_ODIActn_CntrStck_buf;
typedef union _c_ODIActn_AxIP_bufTag
{
  unsigned char _c[8];
  _c_ODIActn_AxIP_msgType ODIActn_AxIP;
} _c_ODIActn_AxIP_buf;
typedef union _c_WhlGrndVlctyLftDrvnGroup_0_bufTag
{
  unsigned char _c[2];
  _c_WhlGrndVlctyLftDrvnGroup_0_msgType WhlGrndVlctyLftDrvnGroup_0;
} _c_WhlGrndVlctyLftDrvnGroup_0_buf;
typedef union _c_WhlGrndVlctyLftNnDrvnGroup_0_bufTag
{
  unsigned char _c[2];
  _c_WhlGrndVlctyLftNnDrvnGroup_0_msgType WhlGrndVlctyLftNnDrvnGroup_0;
} _c_WhlGrndVlctyLftNnDrvnGroup_0_buf;
typedef union _c_WhlGrndVlctyRtDrvnGroup_0_bufTag
{
  unsigned char _c[2];
  _c_WhlGrndVlctyRtDrvnGroup_0_msgType WhlGrndVlctyRtDrvnGroup_0;
} _c_WhlGrndVlctyRtDrvnGroup_0_buf;
typedef union _c_WhlGrndVlctyRtNnDrvnGroup_0_bufTag
{
  unsigned char _c[2];
  _c_WhlGrndVlctyRtNnDrvnGroup_0_msgType WhlGrndVlctyRtNnDrvnGroup_0;
} _c_WhlGrndVlctyRtNnDrvnGroup_0_buf;
typedef union _c_DDAjrSwAtvGroup_bufTag
{
  unsigned char _c[1];
  _c_DDAjrSwAtvGroup_msgType DDAjrSwAtvGroup;
} _c_DDAjrSwAtvGroup_buf;
typedef union _c_EngOffTmExtRngGroup_bufTag
{
  unsigned char _c[5];
  _c_EngOffTmExtRngGroup_msgType EngOffTmExtRngGroup;
} _c_EngOffTmExtRngGroup_buf;
typedef union _c_OtsAirTmpCrValGroup_bufTag
{
  unsigned char _c[2];
  _c_OtsAirTmpCrValGroup_msgType OtsAirTmpCrValGroup;
} _c_OtsAirTmpCrValGroup_buf;
typedef union _c_OtsAirTmpGroup_bufTag
{
  unsigned char _c[3];
  _c_OtsAirTmpGroup_msgType OtsAirTmpGroup;
} _c_OtsAirTmpGroup_buf;
typedef union _c_EngCltTmpGroup_bufTag
{
  unsigned char _c[8];
  _c_EngCltTmpGroup_msgType EngCltTmpGroup;
} _c_EngCltTmpGroup_buf;
typedef union _c_EngIntAirTmpGroup_bufTag
{
  unsigned char _c[7];
  _c_EngIntAirTmpGroup_msgType EngIntAirTmpGroup;
} _c_EngIntAirTmpGroup_buf;
typedef union _c_OAT_PT_EstGroup_bufTag
{
  unsigned char _c[5];
  _c_OAT_PT_EstGroup_msgType OAT_PT_EstGroup;
} _c_OAT_PT_EstGroup_buf;
typedef union _c_TrnsShftLvrPosGroup_0_bufTag
{
  unsigned char _c[6];
  _c_TrnsShftLvrPosGroup_0_msgType TrnsShftLvrPosGroup_0;
} _c_TrnsShftLvrPosGroup_0_buf;
typedef union _c_SysBkUpPwrMdGroup_bufTag
{
  unsigned char _c[1];
  _c_SysBkUpPwrMdGroup_msgType SysBkUpPwrMdGroup;
} _c_SysBkUpPwrMdGroup_buf;
typedef union _c_SysPwrMdGroup_bufTag
{
  unsigned char _c[1];
  _c_SysPwrMdGroup_msgType SysPwrMdGroup;
} _c_SysPwrMdGroup_buf;
typedef union _c_VSELongAccLoResGroup_bufTag
{
  unsigned char _c[2];
  _c_VSELongAccLoResGroup_msgType VSELongAccLoResGroup;
} _c_VSELongAccLoResGroup_buf;
typedef union _c_StrWhAngGroup_0_bufTag
{
  unsigned char _c[6];
  _c_StrWhAngGroup_0_msgType StrWhAngGroup_0;
} _c_StrWhAngGroup_0_buf;
typedef union _c_WhlRotStatLftNDrvn_0_bufTag
{
  unsigned char _c[4];
  _c_WhlRotStatLftNDrvn_0_msgType WhlRotStatLftNDrvn_0;
} _c_WhlRotStatLftNDrvn_0_buf;
typedef union _c_WhlRotStatRghtNDrvn_0_bufTag
{
  unsigned char _c[4];
  _c_WhlRotStatRghtNDrvn_0_msgType WhlRotStatRghtNDrvn_0;
} _c_WhlRotStatRghtNDrvn_0_buf;
typedef union _c_WhlRotatStatLftDrvn_0_bufTag
{
  unsigned char _c[4];
  _c_WhlRotatStatLftDrvn_0_msgType WhlRotatStatLftDrvn_0;
} _c_WhlRotatStatLftDrvn_0_buf;
typedef union _c_WhlRotatStatRtDrvn_0_bufTag
{
  unsigned char _c[4];
  _c_WhlRotatStatRtDrvn_0_msgType WhlRotatStatRtDrvn_0;
} _c_WhlRotatStatRtDrvn_0_buf;
typedef union _c_VehDynYawRateGroup_bufTag
{
  unsigned char _c[2];
  _c_VehDynYawRateGroup_msgType VehDynYawRateGroup;
} _c_VehDynYawRateGroup_buf;
typedef union _c_VehSpdAvgDrvnGroup_bufTag
{
  unsigned char _c[2];
  _c_VehSpdAvgDrvnGroup_msgType VehSpdAvgDrvnGroup;
} _c_VehSpdAvgDrvnGroup_buf;
typedef union _c_DistRollCntAvgDrvnGroup_bufTag
{
  unsigned char _c[2];
  _c_DistRollCntAvgDrvnGroup_msgType DistRollCntAvgDrvnGroup;
} _c_DistRollCntAvgDrvnGroup_buf;
typedef union _c_VehSpdAvgNDrvnGroup_bufTag
{
  unsigned char _c[3];
  _c_VehSpdAvgNDrvnGroup_msgType VehSpdAvgNDrvnGroup;
} _c_VehSpdAvgNDrvnGroup_buf;
typedef union _c_OtsdAmbtLtLvlStatGroup_bufTag
{
  unsigned char _c[4];
  _c_OtsdAmbtLtLvlStatGroup_msgType OtsdAmbtLtLvlStatGroup;
} _c_OtsdAmbtLtLvlStatGroup_buf;
typedef union _c_WhlGrndVlctyLftNnDrvnGroup_1_bufTag
{
  unsigned char _c[2];
  _c_WhlGrndVlctyLftNnDrvnGroup_1_msgType WhlGrndVlctyLftNnDrvnGroup_1;
} _c_WhlGrndVlctyLftNnDrvnGroup_1_buf;
typedef union _c_WhlGrndVlctyRtNnDrvnGroup_1_bufTag
{
  unsigned char _c[2];
  _c_WhlGrndVlctyRtNnDrvnGroup_1_msgType WhlGrndVlctyRtNnDrvnGroup_1;
} _c_WhlGrndVlctyRtNnDrvnGroup_1_buf;
typedef union _c_WhlGrndVlctyLftDrvnGroup_1_bufTag
{
  unsigned char _c[2];
  _c_WhlGrndVlctyLftDrvnGroup_1_msgType WhlGrndVlctyLftDrvnGroup_1;
} _c_WhlGrndVlctyLftDrvnGroup_1_buf;
typedef union _c_WhlGrndVlctyRtDrvnGroup_1_bufTag
{
  unsigned char _c[2];
  _c_WhlGrndVlctyRtDrvnGroup_1_msgType WhlGrndVlctyRtDrvnGroup_1;
} _c_WhlGrndVlctyRtDrvnGroup_1_buf;
typedef union _c_DrvStrIntfrDtcdGroup_bufTag
{
  unsigned char _c[1];
  _c_DrvStrIntfrDtcdGroup_msgType DrvStrIntfrDtcdGroup;
} _c_DrvStrIntfrDtcdGroup_buf;
typedef union _c_TrnsShftLvrPosGroup_1_bufTag
{
  unsigned char _c[3];
  _c_TrnsShftLvrPosGroup_1_msgType TrnsShftLvrPosGroup_1;
} _c_TrnsShftLvrPosGroup_1_buf;
typedef union _c_StrWhAngGroup_1_bufTag
{
  unsigned char _c[3];
  _c_StrWhAngGroup_1_msgType StrWhAngGroup_1;
} _c_StrWhAngGroup_1_buf;
typedef union _c_StrWhAngGrdGroup_bufTag
{
  unsigned char _c[2];
  _c_StrWhAngGrdGroup_msgType StrWhAngGrdGroup;
} _c_StrWhAngGrdGroup_buf;
typedef union _c_IMULonAccPriGroup_bufTag
{
  unsigned char _c[4];
  _c_IMULonAccPriGroup_msgType IMULonAccPriGroup;
} _c_IMULonAccPriGroup_buf;
typedef union _c_IMUYawRtPriGroup_bufTag
{
  unsigned char _c[3];
  _c_IMUYawRtPriGroup_msgType IMUYawRtPriGroup;
} _c_IMUYawRtPriGroup_buf;
typedef union _c_IMULatAccPrimGroup_bufTag
{
  unsigned char _c[7];
  _c_IMULatAccPrimGroup_msgType IMULatAccPrimGroup;
} _c_IMULatAccPrimGroup_buf;
typedef union _c_WhlRotStatLftNDrvn_1_bufTag
{
  unsigned char _c[4];
  _c_WhlRotStatLftNDrvn_1_msgType WhlRotStatLftNDrvn_1;
} _c_WhlRotStatLftNDrvn_1_buf;
typedef union _c_WhlRotStatRghtNDrvn_1_bufTag
{
  unsigned char _c[4];
  _c_WhlRotStatRghtNDrvn_1_msgType WhlRotStatRghtNDrvn_1;
} _c_WhlRotStatRghtNDrvn_1_buf;
typedef union _c_WhlRotatStatLftDrvn_1_bufTag
{
  unsigned char _c[4];
  _c_WhlRotatStatLftDrvn_1_msgType WhlRotatStatLftDrvn_1;
} _c_WhlRotatStatLftDrvn_1_buf;
typedef union _c_WhlRotatStatRtDrvn_1_bufTag
{
  unsigned char _c[4];
  _c_WhlRotatStatRtDrvn_1_msgType WhlRotatStatRtDrvn_1;
} _c_WhlRotatStatRtDrvn_1_buf;


typedef union {
	dword dwFlag;
	struct {
		dword CPIDDeviceCtrlSysPwrMd				: 1;
		dword CPIDDeviceCtrlVehSpd					: 1;
		dword CPIDDeviceCtrlTrnsShftLvrPos			: 1;
		dword CPIDPAStateCtrl						: 1;
		dword CPIDDeviceCtrl						: 1;
		dword CPIDDsblSnsFd							: 1;
		dword CPIDSnsSelfTest						: 1;
		dword CPIDLedRunTestReq						: 1;
		
		dword CPIDPAPhyDisableSw					: 1;
		dword CPIDAPAPhySw							: 2;
		dword CPIDDirectionInd						: 1;
		dword CPIDLEDFeed							: 1;
		dword CPIDLEDOutPutCntrl					: 1;
		dword CPIDDisableAllSystemOutputs			: 1;		
		dword CPIDResetSystem						: 1;
		
		dword CPIDResetSystemConfirmed				: 1;
		dword CPIDDeviceControlActive				: 1; 
		dword Reserved1								: 6;

		dword Reserved2								: 8;		
	} Bits;
} tDescCPIDEventType;


typedef union {
  UINT8 Byte;
  struct {
    UINT8 DTCSupportedByCalibration          :1;            
    UINT8 CurrentDTC                         :1;          
    UINT8 TestNotPassedSinceDTCCleared       :1;         
    UINT8 TestFailedSinceDTCCleared          :1;           
    UINT8 HistoryDTC                         :1;           
    UINT8 TestNotPassedSinceCurrentPowerUp   :1;           
    UINT8 CurrentDTCSincePowerUp             :1;           
    UINT8 WarningIndicatorRequestedState     :1;           
  } Bits;
} tDTCStatusType;

typedef struct{
  word  DTCCodeNumber;
  UINT8 DTCFailureType;
} tDTCCodeNoAndFailType;

typedef struct{
  tDTCStatusType Status;
  UINT8 IGNCounter;
} tDTCRecordType;

typedef struct {  
  tDTCRecordType DTC[DTC_RECORD_TOTAL_NUM];
  const tDTCCodeNoAndFailType *pCodeNoAndFailType;
} tDTCStructType;

extern       unsigned short ObjDtdTimerTimeoutCnt;

typedef enum
{
   RM_EMIT_RX = 0,
   LM_EMIT_RX, /*1*/
   R_EMIT_RX,  /*2*/
   L_EMIT_RX,  /*3*/
   L_R_EMIT_RX,  /*4*/
   UPA_ALL_EMIT_RX  /*5*/
} UpaSnsSelfTxRxType;

typedef struct
{
     word  DtUpaObjDisSelfTxRxArray[PA_SYS_NUM][4];  //Record self Tx Rx SNS
     uchar DtUpaSnsTxSnsMask[PA_SYS_NUM];  //Record Tx SNS
}tSnsSaveUpaTxRxDisInfo;

extern tSnsSaveUpaTxRxDisInfo  SnsSaveUpaTxRxDisInfo;


#endif 
