/* 
* Configuration of module Os (Os_Cfg.c)
* 
* Created by: ArcCore AB
* Configured for (MCU): Undefined MCU
* 
* Module vendor:  ArcCore
* Module version: 2.0.6
* 
* Copyright ArcCore AB 2010
* Generated by Arctic Studio (http://arccore.com)
*           on Thu Apr 08 12:34:10 CEST 2010
*/

	

#include <stdlib.h>
#include <stdint.h>
#include "Platform_Types.h"
#include "Os.h"				// includes Os_Cfg.h
#include "os_config_macros.h"
#include "kernel.h"
#include "kernel_offset.h"
#include "alist_i.h"
#include "Mcu.h"

extern void dec_exception( void );

// Set the os tick frequency
OsTickType OsTickFreq = 1000;


// ###############################    DEBUG OUTPUT     #############################
uint32 os_dbg_mask = D_RESOURCE |D_SCHTBL |D_EVENT |D_TASK |D_ALARM;
 


// #################################    COUNTERS     ###############################
GEN_COUNTER_HEAD {
	GEN_COUNTER(	COUNTER_ID_OsTick,
					"OsTick",
					COUNTER_TYPE_HARD,
					COUNTER_UNIT_NANO,
					0xffff,
					1,
					1,
					0),
};

CounterType Os_Arc_OsTickCounter = COUNTER_ID_OsTick;

// ##################################    ALARMS     ################################

GEN_ALARM_HEAD {
	GEN_ALARM(	ALARM_ID_alarm10,
				"alarm10",
				COUNTER_ID_OsTick,
				NULL,
				ALARM_ACTION_ACTIVATETASK,
				TASK_ID_bTask10,
				NULL,
				NULL ),
	GEN_ALARM(	ALARM_ID_alarm100,
				"alarm100",
				COUNTER_ID_OsTick,
				NULL,
				ALARM_ACTION_ACTIVATETASK,
				TASK_ID_bTask100,
				NULL,
				NULL ),
	GEN_ALARM(	ALARM_ID_alarm25,
				"alarm25",
				COUNTER_ID_OsTick,
				NULL,
				ALARM_ACTION_ACTIVATETASK,
				TASK_ID_bTask25,
				NULL,
				NULL ),
};

// ################################    RESOURCES     ###############################
GEN_RESOURCE_HEAD {
	GEN_RESOURCE(	
		RES_SCHEDULER,
		RESOURCE_TYPE_STANDARD,
		0
	),
};

// ##############################    STACKS (TASKS)     ############################
DECLARE_STACK(OsIdle,OS_OSIDLE_STACK_SIZE);
DECLARE_STACK(Startup,2048);
DECLARE_STACK(bTask10,2048);
DECLARE_STACK(bTask100,2048);
DECLARE_STACK(bTask25,2048);

// ##################################    TASKS     #################################
GEN_TASK_HEAD {
	GEN_ETASK(	OsIdle,
				0,
				FULL,
				TRUE,
				NULL,
				0 
	),
	GEN_BTASK(
		Startup,
		1,
		FULL,
		TRUE,
		NULL,
		0,
		1
	),
				
	GEN_BTASK(
		bTask10,
		1,
		FULL,
		FALSE,
		NULL,
		0,
		1
	),
				
	GEN_BTASK(
		bTask100,
		1,
		FULL,
		FALSE,
		NULL,
		0,
		1
	),
				
	GEN_BTASK(
		bTask25,
		1,
		FULL,
		FALSE,
		NULL,
		0,
		1
	),
				
};

// ##################################    HOOKS     #################################
GEN_HOOKS( 
	StartupHook, 
	NULL, 
	ShutdownHook, 
	ErrorHook,
	PreTaskHook, 
	PostTaskHook 
);

// ##################################    ISRS     ##################################


// ############################    SCHEDULE TABLES     #############################

// Table heads
GEN_SCHTBL_HEAD {
};

GEN_PCB_LIST()

uint8_t os_interrupt_stack[OS_INTERRUPT_STACK_SIZE] __attribute__ ((aligned (0x10)));

GEN_IRQ_VECTOR_TABLE_HEAD {};
GEN_IRQ_ISR_TYPE_TABLE_HEAD {};
GEN_IRQ_PRIORITY_TABLE_HEAD {};

#include "os_config_funcs.h"
