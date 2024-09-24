#include <app.h>
#include <cmds_proprietary.h>
#include <string.h>

#define BYTE_INDEX(x) (x / 8)
#define BYTE_OFFSET(x) (1 << (x % 8))
#define BITMASK_ADD_CMD(bitmask, cmd) (bitmask[BYTE_INDEX(cmd)] |= BYTE_OFFSET(cmd))

#define SUPPORT_LED_ONOFF 1
#define SUPPORT_LED_RGB 1
#define SUPPORT_GYRO 1

#if SUPPORT_LED_ONOFF
#include "sl_simple_led_instances.h"
#endif
#if SUPPORT_LED_RGB
#include "sl_simple_rgb_pwm_led_instances.h"
#endif
#if SUPPORT_GYRO
#include "sl_mpu.h"
extern bool bRequestGyroMeasurement;
#endif

void func_id_nabu_casa(uint8_t inputLength,
                       const uint8_t *pInputBuffer,
                       uint8_t *pOutputBuffer,
                       uint8_t *pOutputLength)
{
  uint8_t i = 0;
  uint8_t cmdRes;

  /* We assume operation is nonesuccessful */
  cmdRes = false;

  if (1 > inputLength)
  {
    /* Command length must be at least 1 byte. Return with negative response in the out buffer */
    BYTE_IN_AR(pOutputBuffer, i++) = cmdRes;
    *pOutputLength = i;
    return;
  }

  BYTE_IN_AR(pOutputBuffer, i++) = pInputBuffer[0]; /* Set output command ID equal input command ID */
  switch (pInputBuffer[0])
  {

  /* Report which subcommands are supported beside the NABU_CASA_CMD_SUPPORTED */
  case NABU_CASA_CMD_SUPPORTED:
    // HOST->ZW: NABU_CASA_CMD_SUPPORTED
    // ZW->HOST: NABU_CASA_CMD_SUPPORTED | supportedBitmask

    /* Report all supported commands as bitmask of their values */
    uint8_t supportedBitmask[32];
    memset(supportedBitmask, 0, sizeof(supportedBitmask));
    // Mark each command as supported
    BITMASK_ADD_CMD(supportedBitmask, NABU_CASA_CMD_SUPPORTED);
#if SUPPORT_LED_ONOFF
    BITMASK_ADD_CMD(supportedBitmask, NABU_CASA_LED_ONOFF_GET);
    BITMASK_ADD_CMD(supportedBitmask, NABU_CASA_LED_ONOFF_SET);
#endif
#if SUPPORT_LED_RGB
    BITMASK_ADD_CMD(supportedBitmask, NABU_CASA_LED_RGB_GET);
    BITMASK_ADD_CMD(supportedBitmask, NABU_CASA_LED_RGB_SET);
#endif
#if SUPPORT_GYRO
    BITMASK_ADD_CMD(supportedBitmask, NABU_CASA_GYRO_MEASURE);
#endif

    // Copy as few bytes as necessary into the output buffer
    for (int j = 0; j <= NABU_CASA_CMD_SUPPORTED / 8; j++)
    {
      BYTE_IN_AR(pOutputBuffer, i++) = supportedBitmask[j];
    }
    break;

#if SUPPORT_LED_ONOFF
  case NABU_CASA_LED_ONOFF_GET:
    // HOST->ZW: NABU_CASA_LED_ONOFF_GET
    // ZW->HOST: NABU_CASA_LED_ONOFF_GET | bStatus

    // Get the current state of the LED
    bool bStatus = (bool)sl_led_led0.get_state(sl_led_led0.context);
    BYTE_IN_AR(pOutputBuffer, i++) = bStatus;
    break;

  case NABU_CASA_LED_ONOFF_SET:
    // HOST->ZW: NABU_CASA_LED_ONOFF_SET | bStatus
    // ZW->HOST: NABU_CASA_LED_ONOFF_SET | true

    // Set the current state of the LED
    if (inputLength >= 2)
    {
      if (BYTE_IN_AR(pInputBuffer, 1))
      {
        sl_led_led0.turn_on(sl_led_led0.context);
      }
      else
      {
        sl_led_led0.turn_off(sl_led_led0.context);
      }
      cmdRes = true;
    }
    BYTE_IN_AR(pOutputBuffer, i++) = cmdRes;
    break;
#endif

#if SUPPORT_LED_RGB
  case NABU_CASA_LED_RGB_GET:
    // HOST->ZW: NABU_CASA_LED_RGB_GET
    // ZW->HOST: NABU_CASA_LED_RGB_GET | r | g | b

    // Get the current state of the LED
    uint16_t r, g, b;
    sl_simple_rgb_pwm_led_rgb_led0.get_rgb_color(
        sl_simple_rgb_pwm_led_rgb_led0.led_common.context,
        &r, &g, &b);
    // We only deal with 8-bit values for the LED
    BYTE_IN_AR(pOutputBuffer, i++) = r & 0xff;
    BYTE_IN_AR(pOutputBuffer, i++) = g & 0xff;
    BYTE_IN_AR(pOutputBuffer, i++) = b & 0xff;
    break;

  case NABU_CASA_LED_RGB_SET:
    // HOST->ZW: NABU_CASA_LED_RGB_SET | r | g | b
    // ZW->HOST: NABU_CASA_LED_RGB_SET | true

    if (inputLength >= 4)
    {
      // Set the current state of the LED
      uint16_t r = BYTE_IN_AR(pInputBuffer, 1);
      uint16_t g = BYTE_IN_AR(pInputBuffer, 2);
      uint16_t b = BYTE_IN_AR(pInputBuffer, 3);
      sl_simple_rgb_pwm_led_rgb_led0.set_rgb_color(
          sl_simple_rgb_pwm_led_rgb_led0.led_common.context,
          r, g, b);
      cmdRes = true;
    }
    BYTE_IN_AR(pOutputBuffer, i++) = cmdRes;
    break;
#endif

#if SUPPORT_GYRO
  case NABU_CASA_GYRO_MEASURE:
    // HOST->ZW (REQ): NABU_CASA_GYRO_MEASURE
    // ZW->HOST (RES): NABU_CASA_GYRO_MEASURE | true
    // later
    // ZW->HOST (CB):  NABU_CASA_GYRO_MEASURE
    //           | accel_x (MSB) | accel_x (LSB)
    //           | accel_y (MSB) | accel_y (LSB)
    //           | accel_z (MSB) | accel_z (LSB)

    bRequestGyroMeasurement = true;
    cmdRes = true;
    BYTE_IN_AR(pOutputBuffer, i++) = cmdRes;
    break;
#endif

  default:
    // Unsupported. Return false
    BYTE_IN_AR(pOutputBuffer, i++) = false;
    break;
  }

  *pOutputLength = i;
}
