# Le code fonctionne 

import machine
import ssd1306
i2c = machine.I2C(-1, sda=machine.Pin(9), scl=machine.Pin(8))
oled = ssd1306.SSD1306_I2C(128, 32, i2c)

oled.fill(0)
oled.text('Hello', 0, 0)
oled.text('World', 0, 10)
oled.show()

