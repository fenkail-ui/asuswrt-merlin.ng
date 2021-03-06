/*
   <:copyright-BRCM:2013-2016:DUAL/GPL:standard
   
      Copyright (c) 2013-2016 Broadcom 
      All Rights Reserved
   
   Unless you and Broadcom execute a separate written software license
   agreement governing use of this software, this software is licensed
   to you under the terms of the GNU General Public License version 2
   (the "GPL"), available at http://www.broadcom.com/licenses/GPLv2.php,
   with the following added to such license:
   
      As a special exception, the copyright holders of this software give
      you permission to link this software with independent modules, and
      to copy and distribute the resulting executable under terms of your
      choice, provided that you also meet, for each linked independent
      module, the terms and conditions of the license of that module.
      An independent module is a module which is not derived from this
      software.  The special exception does not apply to any modifications
      of the software.
   
   Not withstanding the above, under no circumstances may you combine
   this software in any way with any other Broadcom software provided
   under a license other than the GPL, without Broadcom's express prior
   written consent.
   
:>
*/

#ifndef _RDD_IC_H
#define _RDD_IC_H

#define NUM_OF_GENERIC_RULE_CFG 4

void rdd_ic_debug_mode_enable(bdmf_boolean enable);
#ifdef CM3390
int rdd_ic_context_cfg(rdpa_traffic_dir direction, uint32_t context_id, const rdd_ic_context_t *context);
int rdd_ic_context_get(rdpa_traffic_dir direction, uint32_t context_id, rdd_ic_context_t *context);
#endif

#endif /* _RDD_IC_H */
