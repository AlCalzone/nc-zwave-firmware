
#ifndef APPS_SERIALAPI_CMD_PROPRIETARY_H_
#define APPS_SERIALAPI_CMD_PROPRIETARY_H_

#include <stdint.h>
#include <ZAF_types.h>
/* FUNC_ID_PROPRIETARY_0 (Nabu Casa) command definitions */
typedef enum
{
  NABU_CASA_CMD_SUPPORTED = 0,
  NABU_CASA_LED_ONOFF_GET = 1,
  NABU_CASA_LED_ONOFF_SET = 2,
  NABU_CASA_LED_RGB_GET = 3,
  NABU_CASA_LED_RGB_SET = 4,
  NABU_CASA_GYRO_MEASURE = 5,
} eNabuCasaCmd;

#endif /* APPS_SERIALAPI_CMD_PROPRIETARY_H_ */
