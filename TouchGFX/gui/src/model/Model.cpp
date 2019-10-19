#include <gui/model/Model.hpp>
#include <stdio.h>
#include <stdint.h>
#include <gui/model/ModelListener.hpp>
#include <touchgfx/Utils.hpp>

#ifndef SIMULATOR
#include "cmsis_os.h"
#if 0
extern osMessageQId buttonQueueHandle;
extern osMessageQId ledQueueHandle;
extern osMessageQId tcpQueueHandle;
extern osMessageQId logQueueHandle;
extern osMessageQId logDumpQueueHandle;
extern osMessageQId logClearQueueHandle;
extern osMessageQId logSentQueueHandle;
extern osMessageQId getIPQueueHandle;
extern osMessageQId setIPQueueHandle;
#endif
#endif

Model::Model() : modelListener(0)
{
}

void Model::tick()
{
#ifdef SIMULATOR
#elif 0
  uint8_t buttonStateReceived = 0;
  char* ip_addr_ptr = NULL;
  if (xQueueReceive(buttonQueueHandle, &buttonStateReceived, 0) == pdTRUE)
  {
    modelListener->m2p_ButtonPressed();
  }
#if 1
  else if (xQueueReceive(setIPQueueHandle, &ip_addr_ptr, 0) == pdTRUE)
  {
    modelListener->m2p_SetIPAddress(ip_addr_ptr);
  }
#endif
#endif
} 

void Model::p2m_SetLEDState(bool led_state)
{
#ifdef SIMULATOR
  touchgfx_printf("Model::%s: %d\r\n\r\n", __FUNCTION__, led_state);
#elif 0
  xQueueSend(ledQueueHandle, &led_state, 0);
#endif
}

void Model::p2m_SendTCPData(int data)
{
  uint8_t u8Data = 0;
  u8Data = (uint8_t)data;
#ifdef SIMULATOR
  touchgfx_printf("Model::%s: %u\r\n\r\n", __FUNCTION__, u8Data);
#elif 0
  xQueueSend(tcpQueueHandle, &u8Data, 0);
#endif
}

void Model::p2m_LogData(int data)
{
  uint8_t u8Data = 0;
  u8Data = (uint8_t)data;
#ifdef SIMULATOR
  touchgfx_printf("Model::%s: %u\r\n\r\n", __FUNCTION__, u8Data);
#elif 0
  xQueueSend(logQueueHandle, &u8Data, 0);
#endif
}

void Model::p2m_DumpData(void)
{
  uint8_t u8Data = 0;
#ifdef SIMULATOR
  touchgfx_printf("Model::%s: %u\r\n\r\n", __FUNCTION__, u8Data);
#elif 0
  xQueueSend(logDumpQueueHandle, &u8Data, 0);
#endif
}

void Model::p2m_SentData(void)
{
  uint8_t u8Data = 0;
#ifdef SIMULATOR
  touchgfx_printf("Model::%s: %u\r\n\r\n", __FUNCTION__, u8Data);
#elif 0
  xQueueSend(logSentQueueHandle, &u8Data, 0);
#endif
}

void Model::p2m_ClearData(void)
{
  uint8_t u8Data = 0;
#ifdef SIMULATOR
  touchgfx_printf("Model::%s: %u\r\n\r\n", __FUNCTION__, u8Data);
#elif 0
  xQueueSend(logClearQueueHandle, &u8Data, 0);
#endif
}

void Model::p2m_getIPAddress(void)
{
  uint8_t u8Data = 0;
#ifdef SIMULATOR
  touchgfx_printf("Model::%s: %u\r\n\r\n", __FUNCTION__, u8Data);
#elif 0
  xQueueSend(getIPQueueHandle, &u8Data, 0);
#endif
}
