
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                               proc.c
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                                                    Forrest Yu, 2005
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include "type.h"
#include "const.h"
#include "protect.h"
#include "proto.h"
#include "string.h"
#include "proc.h"
#include "global.h"

/*======================================================================*
                              schedule
 *======================================================================*/
PUBLIC void schedule()
{
	PROCESS* p;
	if(enkeyboard == 1){
		p = proc_table+1;
		if(p->ticks>0){
			p_proc_ready = p;
		}else{
			p->ticks = p->priority;
			p_proc_ready = p+1;
		}
	}
	else{
		p_proc_ready = proc_table;
	}
}

/*======================================================================*
                           sys_get_ticks
 *======================================================================*/
PUBLIC int sys_get_ticks()
{
	return ticks;
}
PUBLIC void sys_disenkeyboard()
{
	enkeyboard = 0;
}

