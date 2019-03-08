#ifndef __MCP9600_H__
#define __MCP9600_H__

#include <stdint.h>

// MCP9600 registers
#define MCP9600_ADDR0 0x60  // 1100 000x
#define MCP9600_ADDR1 0x61  // 1100 001x
#define MCP9600_ADDR2 0x62  // 1100 010x
#define MCP9600_ADDR3 0x63  // 1100 011x
#define MCP9600_ADDR4 0x64  // 1100 100x
#define MCP9600_ADDR5 0x65  // 1100 101x
#define MCP9600_ADDR6 0x66  // 1100 110x
#define MCP9600_ADDR7 0x67  // 1100 111x

#define MCP9600_REG_HJT 0x00        // Hot-Junction Temperature – TH
#define MCP9600_REG_JTD 0x01        // Junctions Temperature Delta – T∆
#define MCP9600_REG_CJT 0x02        // Cold-Junction Temperature – TC

#define MCP9600_REG_ADC 0x03        // Raw Data ADC

#define MCP9600_REG_STAT 0x04       // STATUS
#define MCP9600_REG_TCFG 0x05       // Thermocouple Sensor Configuration
#define MCP9600_REG_CFG 0x06        // Device Configuration

#define MCP9600_REG_ALRT1CFG 0x08   // Alert 1 Configuration
#define MCP9600_REG_ALRT2CFG 0x09   // Alert 2 Configuration
#define MCP9600_REG_ALRT3CFG 0x0A   // Alert 3 Configuration
#define MCP9600_REG_ALRT4CFG 0x0B   // Alert 4 Configuration

#define MCP9600_REG_ALRT1HYS 0x0C   // Alert 1 Hysteresis
#define MCP9600_REG_ALRT2HYS 0x0D   // Alert 2 Hysteresis
#define MCP9600_REG_ALRT3HYS 0x0E   // Alert 3 Hysteresis
#define MCP9600_REG_ALRT4HYS 0x0F   // Alert 4 Hysteresis

#define MCP9600_REG_ALRT1LIM 0x10   // Alert 1 Limit
#define MCP9600_REG_ALRT2LIM 0x11   // Alert 2 Limit
#define MCP9600_REG_ALRT3LIM 0x12   // Alert 3 Limit
#define MCP9600_REG_ALRT4LIM 0x13   // Alert 4 Limit

#define MCP9600_REG_ID 0x20         // Device ID/Revision

// BME280_REG_STATUS
#define MCP9600_BURST_COMP  0x80    // Burst Mode Conversions Status Flag bit
#define MCP9600_TH_UPDT     0x40    // Temperature Update Flag bit
#define MCP9600_TIN_RNG     0x10    // Temperature Range Detection bit (read-only)
#define MCP9600_ALRT4       0x08    // Alert 4: Status bit (read-only)
#define MCP9600_ALRT3       0x04    // Alert 3: Status bit (read-only)
#define MCP9600_ALRT2       0x02    // Alert 2: Status bit (read-only)
#define MCP9600_ALRT1       0x01    // Alert 1: Status bit (read-only)

// BME280_REG_SENSOR_CFG
#define MCP9600_TYPE_K      0x00    // Thermocouple Type Select bits
#define MCP9600_TYPE_J      0x10    // Thermocouple Type Select bits
#define MCP9600_TYPE_T      0x20    // Thermocouple Type Select bits
#define MCP9600_TYPE_N      0x30    // Thermocouple Type Select bits
#define MCP9600_TYPE_S      0x40    // Thermocouple Type Select bits
#define MCP9600_TYPE_E      0x50    // Thermocouple Type Select bits   
#define MCP9600_TYPE_B      0x60    // Thermocouple Type Select bits
#define MCP9600_TYPE_R      0x70    // Thermocouple Type Select bits

#define MCP9600_FILT_COEF_0 0x00    // Filter off
#define MCP9600_FILT_COEF_1 0x00    // Minimum filter
#define MCP9600_FILT_COEF_2 0x00    //
#define MCP9600_FILT_COEF_3 0x00    //
#define MCP9600_FILT_COEF_4 0x00    // Mid filter
#define MCP9600_FILT_COEF_5 0x00    // 
#define MCP9600_FILT_COEF_6 0x00    // 
#define MCP9600_FILT_COEF_7 0x00    // Maximum filter

// BME280_REG_CFG
#define MCP9600_CJ_RES      0x80    // Cold-Junction Resolution bit

#define MCP9600_ADC_RES     5       // ADC Resolution bits offset
#define MCP9600_ADC_RES_18b 0x00    // ADC Resolution bits - 18-bit Resolution 
#define MCP9600_ADC_RES_16b 0x20    // ADC Resolution bits - 16-bit Resolution 
#define MCP9600_ADC_RES_14b 0x40    // ADC Resolution bits - 14-bit Resolution 
#define MCP9600_ADC_RES_12b 0x60    // ADC Resolution bits - 12-bit Resolution 

#define MCP9600_BURST_TS    2       // Burst Mode Temperature Samples offset
#define MCP9600_BURST_TS_1  0x00    // Number of Temperature Samples 1
#define MCP9600_BURST_TS_2  0x02    // Number of Temperature Samples 2
#define MCP9600_BURST_TS_4  0x04    // Number of Temperature Samples 4
#define MCP9600_BURST_TS_8  0x06    // Number of Temperature Samples 8
#define MCP9600_BURST_TS_16  0x08    // Number of Temperature Samples 16
#define MCP9600_BURST_TS_32  0x0A    // Number of Temperature Samples 32
#define MCP9600_BURST_TS_64  0x0C    // Number of Temperature Samples 64
#define MCP9600_BURST_TS_128  0x0E    // Number of Temperature Samples 128


// MCP9600_FUNCS 

uint8_t mcp9600_init();

void mcp9600_software_reset();

double mcp9600_read_temperature();

uint8_t mcp9600_get_status();
uint8_t mcp9600_get_id();

void mcp9600_set_control(uint16_t usControl);
uint16_t mcp9600_get_control();

void mcp9600_set_config(uint8_t ubConfig);
uint8_t mcp9600_get_config();

#endif  // __MCP9600_H__