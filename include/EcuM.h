/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/

/** @addtogroup EcuM ECU State Manager
 *  @{ */

/** @file EcuM.h
 * API and type definitions for ECU State Manager.
 */

#ifndef ECUM_H_
#define ECUM_H_

#define ECUM_MODULE_ID			MODULE_ID_ECUM
#define ECUM_VENDOR_ID			1

#define ECUM_SW_MAJOR_VERSION	2
#define ECUM_SW_MINOR_VERSION	0
#define ECUM_SW_PATCH_VERSION	0

#define ECUM_AR_MAJOR_VERSION	1
#define ECUM_AR_MINOR_VERSION	2
#define ECUM_AR_PATCH_VERSION	2

#include "EcuM_Cfg.h"

#if defined(USE_COM)
#include "ComStack_Types.h"
#endif


/** @name Error Codes */
//@{
#define ECUM_E_NOT_INITIATED (0x10)
#define ECUM_E_SERVICE_DISABLED (0x11)
#define ECUM_E_NULL_POINTER (0x12)
#define ECUM_E_INVALID_PAR (0x13)
#define ECUM_E_MULTIPLE_RUN_REQUESTS (0x14)
#define ECUM_E_MISMATCHED_RUN_RELEASE (0x15)
#define ECUM_E_STATE_PAR_OUT_OF_RANGE (0x16)
#define ECUM_E_UNKNOWN_WAKEUP_SOURCE (0x17)
#define ECUM_E_ARC_TIMERERROR (0x18)
//@}

/** @name Service id's */
//@{
#define ECUM_REQUESTRUN_ID (0x03)
#define ECUM_RELEASERUN_ID (0x04)
#define ECUM_SELECTSHUTDOWNTARGET_ID (0x06)
#define ECUM_GETSTATE_ID (0x07)
#define ECUM_GETSHUTDOWNTARGET_ID (0x09)
#define ECUM_COMM_REQUESTRUN_ID (0x0e)
#define ECUM_REQUESTPOSTRUN_ID (0x0a)
#define ECUM_RELEASEPOSTRUN_ID (0x0b)
#define ECUM_SELECTAPPMODE_ID (0x0f)
#define ECUM_COMM_RELEASERUN_ID (0x10)
#define ECUM_GETAPPMODE_ID (0x11)
#define ECUM_SELECT_BOOTARGET_ID (0x12)
#define ECUM_GET_BOOTARGET_ID (0x13)
#define ECUM_MAINFUNCTION_ID (0x18)
#define ECUM_COMM_HASREQUESTEDRUN_ID (0x1b)
#define ECUM_ARC_STARTUPTWO_ID (0x20)

#if ( ECUM_VERSION_INFO_API == STD_ON)
#define EcuM_GetVersionInfo(_vi) STD_GET_VERSION_INFO(_vi,ECUM)
#endif

void EcuM_Init( void );
void EcuM_StartupTwo(void);
void EcuM_Shutdown(void);

Std_ReturnType EcuM_GetState(EcuM_StateType* state);

Std_ReturnType EcuM_RequestRUN(EcuM_UserType user);
Std_ReturnType EcuM_ReleaseRUN(EcuM_UserType user);

Std_ReturnType EcuM_RequestPOST_RUN(EcuM_UserType user);
Std_ReturnType EcuM_ReleasePOST_RUN(EcuM_UserType user);

void EcuM_KillAllRUNRequests(void);

#if defined(USE_COMM)
Std_ReturnType EcuM_ComM_RequestRUN(NetworkHandleType channel);
Std_ReturnType EcuM_ComM_ReleaseRUN(NetworkHandleType channel);
boolean EcuM_ComM_HasRequestedRUN(NetworkHandleType channel);
#endif

Std_ReturnType EcuM_SelectShutdownTarget(EcuM_StateType shutdownTarget, uint8 sleepMode);
Std_ReturnType EcuM_GetShutdownTarget(EcuM_StateType* shutdownTarget, uint8* sleepMode);
Std_ReturnType EcuM_GetLastShutdownTarget(EcuM_StateType* shutdownTarget, uint8* sleepMode);

EcuM_WakeupSourceType EcuM_GetPendingWakeupEvents(void);
void EcuM_ClearWakeupEvent(EcuM_WakeupSourceType sources);
EcuM_WakeupSourceType EcuM_GetValidatedWakeupEvents(void);
EcuM_WakeupSourceType EcuM_GetExpiredWakeupEvents(void);
EcuM_WakeupStatusType EcuM_GetStatusOfWakeupSource(EcuM_WakeupSourceType sources);

Std_ReturnType EcuM_SelectApplicationMode(AppModeType appMode);
Std_ReturnType EcuM_GetApplicationMode(AppModeType* appMode);

Std_ReturnType EcuM_SelectBootTarget(EcuM_BootTargetType target);
Std_ReturnType EcuM_GetBootTarget(EcuM_BootTargetType* target);

void EcuM_MainFunction(void);

#endif /*ECUM_H_*/
/** @} */
