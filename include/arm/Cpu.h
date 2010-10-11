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

#ifndef CPU_H_
#define CPU_H_

#include <stdint.h>
#include "stm32f10x.h"
#include "core_cm3.h"

/* Call intrinsic functions directly */
#define Irq_Disable()					__disable_irq()
#define Irq_Enable()					__enable_irq()

#define Irq_Save(_flags)     			_flags = _Irq_Save();
#define Irq_Restore(_flags)			_Irq_Restore(_flags);

#define Irq_SuspendAll() 	Irq_Disable()
#define Irq_ResumeAll() 	Irq_Enable()

#define Irq_SuspendOs() 	Irq_Disable()
#define Irq_ResumeOs() 	Irq_Enable()

static inline unsigned long _Irq_Save(void)
{
   unsigned long val = 0;
   return val;
}

/*-----------------------------------------------------------------*/

static inline void _Irq_Restore(unsigned mask) {

}

#define CallService(index,param)

#endif /* CPU_H_ */
