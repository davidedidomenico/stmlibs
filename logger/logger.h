/*
 * "THE BEER-WARE LICENSE" (Revision 69):
 * Squadra Corse firmware team wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you 
 * think this stuff is worth it, you can buy us a beer in return.
 * 
 * Authors
 * - Federico Carbone [federico.carbone.sc@gmail.com]
 */

#ifndef LOGGER_H
#define LOGGER_H

#include "main.h"

typedef enum { LOGGER_INFO, LOGGER_DEBUG, LOGGER_WARNING, LOGGER_ERROR } LOGGER_MODE;

typedef HAL_StatusTypeDef (*LOGGER_flushTypeDef)(char *buffer, uint32_t size);

struct LOGGER_HandleStruct {
    char *buffer;
    uint32_t buffer_len;
    uint32_t index;
    LOGGER_flushTypeDef flush_raw;
};
typedef struct LOGGER_HandleStruct LOGGER_HandleTypeDef;

HAL_StatusTypeDef LOGGER_init(
    LOGGER_HandleTypeDef *handle,
    char *buffer,
    uint32_t buffer_len,
    LOGGER_flushTypeDef flush_raw);
HAL_StatusTypeDef LOGGER_log(LOGGER_HandleTypeDef *handle, LOGGER_MODE mode, char *template, ...);
HAL_StatusTypeDef LOGGER_flush(LOGGER_HandleTypeDef *handle);

#endif  //LOGGER_H