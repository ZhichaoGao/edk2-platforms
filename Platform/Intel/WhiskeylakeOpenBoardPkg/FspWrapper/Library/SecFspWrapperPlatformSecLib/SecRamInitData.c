/** @file
  Provide TempRamInitParams data.


  Copyright (c) 2019, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <Library/PcdLib.h>
#include <FspEas.h>
#include "FsptCoreUpd.h"

typedef struct {
  FSP_UPD_HEADER    FspUpdHeader;
  FSPT_CORE_UPD     FsptCoreUpd;
} FSPT_UPD_CORE_DATA;

GLOBAL_REMOVE_IF_UNREFERENCED CONST FSPT_UPD_CORE_DATA FsptUpdDataPtr = {
  {
    0x4450555F54505346,
    0x00,
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    }
  },
  {
    ((UINT32)FixedPcdGet64 (PcdCpuMicrocodePatchAddress) + FixedPcdGet32 (PcdFlashMicrocodeOffset)),
    ((UINT32)FixedPcdGet64 (PcdCpuMicrocodePatchRegionSize) - FixedPcdGet32 (PcdFlashMicrocodeOffset)),
    0,          // Set CodeRegionBase as 0, so that caching will be 4GB-(CodeRegionSize > LLCSize ? LLCSize : CodeRegionSize) will be used.
    FixedPcdGet32 (PcdFlashCodeCacheSize),
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    }
  }
};


