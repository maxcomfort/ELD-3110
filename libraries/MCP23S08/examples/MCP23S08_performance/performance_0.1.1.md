

# Performance test  

Test sketch  MCP23S08_performance.ino

Max clock frequency 10 MHz, for an UNO this is 8 MHz (divider of CPU clock)

### Library version: 0.1.1


|  Action                       |  SW SPI | HW 1 MHz | HW 2 MHz | HW 4 MHz | HW 8 MHz |
|:------------------------------|--------:|---------:|---------:|---------:|---------:|
| TEST digitalWrite(0, value)   |  xx.xx  |   xx.xx  |  xx.xx   |  xx.xx   |  34.50   |
| TEST digitalWrite(pin, value) |  xx.xx  |   xx.xx  |  xx.xx   |  xx.xx   |  36.00   |
| TEST digitalRead(pin)         |  xx.xx  |   xx.xx  |  xx.xx   |  xx.xx   |  24.00   |
|                               |         |          |          |          |          |
| TEST write8(port, mask)       |  xx.xx  |   xx.xx  |  xx.xx   |  xx.xx   |  24.00   |
| TEST read8(port)              |  xx.xx  |   xx.xx  |  xx.xx   |  xx.xx   |  24.00   |


### Notes

Performance as expected.

Note: 0.1.1 has optimized digitalWrite(pin, value);


### Future

- test ESP32 and other platforms
- register based IO version for the SW SPI on AVR ?


