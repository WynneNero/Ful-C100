/***********************************************************************
*   Copyright (C) Huizhou Desay SV Automotive Co., Ltd.				   *
*				  All Rights Reserved.          					   *
*   Department : CT AD NJ   									   *
*   AUTHOR	   : 									   *
************************************************************************
* Object        :
* Module        :
* Instance      :
* Description   :
*-----------------------------------------------------------------------
* Version:
* Date:
* Author:
***********************************************************************/
/*-History--------------------------------------------------------------
* Version       Date         Name               Changes and comments
* ----------------------------------------------------------------------
* 0.1    July 25 ,2016      ShangQiuju       Init version
* ----------------------------------------------------------------------
* 0.2    Feb 09 ,2017      ShangQiuju       Remove unused definition.
* ----------------------------------------------------------------------
* 0.3    Feb 10 ,2017      ShangQiuju       Add USE_CS_CAPTURE_FUNCTION to change
                                                           resync mode:ioread or cap.
* ----------------------------------------------------------------------
* 0.4    Feb 11 ,2017      ShangQiuju       Open USE_CS_CAPTURE_FUNCTION,and update 
                                                            cap init function according timer_uinit.c update.
*----------------------------------------------------------------------------------------------
*0.5   Feb 20,2017         PeiJingli            PWM interface renamed
*----------------------------------------------------------------------------------------------
*0.6   Mar 31,2017         ZhangJie           Extend SPI date length.
*=====================================================================*/
#ifndef _SOC_DRIVER_H_
#define _SOC_DRIVER_H_ 
#include "CONFIG.H"
#include "TYPES.H"   
#include "GPIO_IF.H"
#include "FIFO_IF.H"
/**** Definition of constants ****/
#define USE_CS_CAPTURE_FUNCTION   

#define NAVI_BASE_LEN 5
#define	TX_HQ 0
#define TX_LQ 1

#define	RX_HQ 0
#define RX_LQ 1

#define TOTAL_TXQ 2
#define TOTAL_RXQ 2
#define FIFO_DEPTH 8
/**** Definition of types ****/
//frame format: header + frame_id + frame_length + command + checksum
//starting from header 0xff,0xa5,0x5a (byte0,1,2)
#define SPI_FRAME_IDBYTE 3
#define SPI_FRAME_LENGTHBYTE 4
#define SPI_FRAME_CMDTYPEBYTE 5
#define SPI_FRAME_CMDIDBYTE_H 6 
#define SPI_FRAME_CMDIDBYTE_L 7
#define SPI_FRAME_CMDDATASIZEBYTE 8
#define SPI_FRAME_CMDFLAGBYTE 9
#define SPI_FRAME_CMDPARABYTE 10

#define SPI_FRAME_OVERHEAD 6 //beyond app command payload

#define FRAMEID_Q_BIT 0x80 //bit7 of frame id, 1:HQ, 0:LQ
#define FRAMEID_MS_BIT 0x40 //bit6 of frame id, 1:Slave, 0:Master
#define RUNNING_NUMBER_MAX 0x3F //bit5..0 for running number

#define SPI_SEND_TIMEOUT 3000/5 //time limit for a command to send out
#define SPI_ACK_TIMEOUT 200 //time limit for an ack to arrive
#define SPI_SEND_TIMEOUT_LIMIT 5 	//5 times sending timeout to trigger system reset
#define SPI_ACK_TIMEOUT_LIMIT 5 	//5 times hq ack timeout to trigger system reset

#define SPI_RX_TIMEOUT 1000/5 //time limit for all packets of a command to arrive
#define SPI_MASTER_TIMEOUT 10000 //5second, time limit for an alive command to arrive

#define SPI_RESYNC_TIMEOUT 2000 //10s

#define MAX_RETRY 0x04

#define MAX_CONTINUOUS_SEND 5

#define SPI_RX_TIMEOUT_ERROR 0x80
#define SPI_RX_BUFFERFULL_ERROR 0x40
#define SPI_RX_BUFFERALIGN_ERROR 0x08
#define SPI_RX_COMMANDCS_ERROR 0x04
#define SPI_RX_PACKETCS_ERROR 0x02
#define SPI_RX_OVE_ERROR 0x01

#define SPI_TX_RESYNC_ERROR 0x80
#define SPI_TX_TIMEOUT_ERROR 0x40
#define SPI_TX_ACKTIMEOUT_ERROR 0x20


#define RECV_BUF_SIZE 2
#define SOC_SPI CSIH_0
//buffer size for TX,RX
//buffer size for TXHQ, TXLQ, RXHQ, RXLQ
#define SPI_NAVI_INP_HQBUF_SIZE 4096 //888phase2 4096
#define SPI_NAVI_INP_LQBUF_SIZE 4096 //888phase2 4096
#define SPI_NAVI_OUT_HQBUF_SIZE 4096 //888phase2 4096
#define SPI_NAVI_OUT_LQBUF_SIZE 512  //888phase2 512
#define SPI_FRAME_MAXLENGTH 512


typedef struct
{
    FIFO_TYPE fifo_info;
    U8  *pBuff;
} SPI_NAVI_FIFO_TYPE;

//rx, tx buffer, with head and tail for complete commands in buffer
typedef struct
{
    FIFO_TYPE buffer;
    U16  cmd_head;
    U16 cmd_tail;
} SPI_NAVI_CMD_FIFO;
typedef struct
{
    U8 timer_counter;/** Timer = polling period*timer_counter **/
    U8 timeout_counter;
} SPI_NAVI_TIMER_TYPE;

typedef enum
{
    //tx channel status
    TX_IDLE = 0,
    ACKOK, //can tx new cmd now
    SENDING,
    WAITING_ACK,
    TX_TIMEOUT,  //tx channel timeout
    TX_RESYNC, //master call to restart spi
} SPI_NAVI_TX_STATE;

typedef struct
{
    U8 len;
    U8 buf[SPI_FRAME_MAXLENGTH];
}RECV_BUF_STRUCT;

typedef enum
{
    RX_IDLE = 10,
    RECEIVING,
    OVE = 20, //fifo stopped
    CS_ERROR, //packet to be dropped until new ack/data cmd arrives
    RX_TIMEOUT,
    //application sync status
    MASTER_TIMEOUT, //no handshake from navi, TBD!!!
} SPI_NAVI_RX_STATE;


typedef struct
{
    U8 status;/** rx status **/
    U8 cs;/** cs  =ID^LENGTH^DATA1^DATA2^....^DATAn **/
    U8 last_frame_id;/** last successfully received frame **/
    U8 frame_id;/** received currentlly **/
    U8 frame_len;/** data frame len,  not including the len byte **/
    U8 byte_index;
} SPI_NAVI_RX_INFO_TYPE;

typedef struct
{
    BOOL req_send_sync_byte;
    BOOL req_send_ack;
    BOOL req_send_frame;
    BOOL req_restart_crq;
    U8 send_type;/*is sending ack or frame or nothing?*/
    U8 ack_wait_state;
    U8 status;/** tx status **/
    U8 cs; /** cs  =ID^LENGTH^DATA1^DATA2^....^DATAn **/
    U8 ack_id;/** id that just received and need to sent it's ack **/
    U8 frame_id;/** id value that will be sent in a new frame**/
    U8 frame_len; /** data frame len,  not including the len byte **/
    U8 byte_index;
} SPI_NAVI_TX_INFO_TYPE;

typedef struct
{
    U8 q_id; //current tx buffer used
    U8 frame_id; //running number for each command transferred, M3 marks the id, ack command from navi uses the same id
    SPI_NAVI_TX_STATE tx_state; //idle/ack_OK, sending, wait_ack, ack_timeout, master_timeout and other errors, etc
    U8 total_packet; //total #packet for the command
    U8 packet_transmitted; //#packet sucessfully sent
    U8 retry_counter; //#resend to navi, total 3
    BOOL hq_ack_request;
    SPI_NAVI_CMD_FIFO tx_q[TOTAL_TXQ]; //info on cmd tx fifo
} SPI_NAVI_TX_STATUS;

typedef struct
{
    U8 q_id;
    U8 frame_id; //running number for each command received, navi side marks the id, same id for the ack command
    SPI_NAVI_RX_STATE rx_state; //idle/cmd_complete, receiving, OVE, cs_error, cmd_timeout, resend_req, other errors, etc
    U8 total_packet; //total #packet of the command
    U8 packet_received; //#packet sucessfully received
    U8 repeat_counter; //#resend by navi, total 3
    SPI_NAVI_CMD_FIFO rx_q[TOTAL_RXQ]; //info on cmd rx fifo
} SPI_NAVI_RX_STATUS;


/**** Definition of macros ****/
/**** Declaration of constants ****/

#define SET_REQ_PIN_FOR_DATA_SENDING()  GPIO_SetVal(GPIO_PORT_0,GPIO_PIN_4,FALSE)
#define CLEAR_REQ_PIN_FOR_DATA_SENDING()  GPIO_SetVal(GPIO_PORT_0,GPIO_PIN_4,TRUE)

#define GET_CS_STATUS()  GPIO_GetVal(GPIO_PORT_0,GPIO_PIN_0)

#define INIT_CS_FUNC() do{TAU_Capture_Config(TAUD0_U2, TAU_CH2, (CAP_TYPE_ST)4);\
						   TAU_Capture_Cmd(TAUD0_U2, TAU_CH2, ENABLE);\
                           			  }while(0)

/**** Declaration of variables ****/

typedef enum
{
    E_DRIVER_IDLE,
    E_DRIVER_TRANSMIT,
    E_DRIVER_STOP
}E_SOCDRIVER_STATE;

typedef enum
{
    E_IDLE_WORKSTATE,
    E_REQ_START_WORK,
    E_REQ_STOP_WORK,
    E_WOKING_NOW,
}E_DRIVER_CONTROL_STATE;

enum
{
	CAMERA_CTRL_IDEL,
	CAMERA_CTRL_EN,
	CAMERA_CTRL_R,
	CAMERA_CTRL_L,
	CAMERA_CTRL_F,
	CAMERA_CTRL_B,
	CAMERA_CTRL_COMPLETE,
}E_CAMERA_CONTROL_STATE;

/**** Declaration of functions ****/
void ResyncHandler(void);
void SendAck(U8 framid);
void SendDataToSoc(void);
void TxHandler(void);
void SocDriver_ReceiveIsr(void* indata);
void SocDriver_SentIsr(void);
void MonitorResynReq(void);
void trap_log_spi_error(U8 rx_error, U8 tx_error, char*debugging_info);
void trap_restart_system(void);
U8 get_camera_power_step(void);
void Open_SOC_Power(void);
void Open_CAM_Power(void);
void Close_SOC_Power(void);
void Close_CAM_Power(void);
BOOL bSocSendBufferEmpty(void);
U8 GetRecBufEmptyIndex(void);
static void init_var(void);
void CheckCameraPower(void);
void soc_startup_from_sd(void);
void SocControlCameraPower(void);
extern void open_pmic_pwr(void);
void Camera2FHandler(void);

extern void power_camera_F_on(void);
extern void power_camera_F_off(void);
extern void power_camera_B_on(void);
extern void power_camera_B_off(void);
extern void power_camera_R_on(void);
extern void power_camera_R_off(void);
extern void power_camera_L_on(void);
extern void power_camera_L_off(void);
extern U8 EolUpdateFlag;


#endif /*_SOC_DRIVER_H_*/
/****************************** END OF FILE ***************************/

