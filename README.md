# MCP3424
This is a driver for raspberry py

# Requirements
```sh
$ apt install libi2c-dev
```
# Compilation
```sh
$ g++ MCP3424.cpp demo-adcread.cpp -o test
```
# API
```
MCP3424(char address,char rate=18);
  /**
  * @param address - I2C address for the target device e.g. 0x68
  * @param channel - 1 to 4
  * @param rate - 12, 14, 16 or 18
  * @param pg - 1, 2, 4 or 8
  * @param conv_mode - 0 = one shot conversion, 1 = continuous conversion
  */
  void set_config_values(char address,char channel,char rate,char pg,char conv_mode);
  /**
  * Reads the raw value from the selected ADC channel
  * @param channel - 1 to 4
  * @returns - raw long value from ADC buffer
  */
  int read_raw(char channel);
  /**
  * Returns the voltage from the selected ADC channel
  * @param channel - 1 to 4
  * @returns - double voltage value from ADC
  */
  double read_voltage(char channel);
  /**
  * Programmable Gain Amplifier gain selection
  * @param gain - Set to 1, 2, 4 or 8
  */
  void set_pga(char gain);
  /**
  * Set the sample resolution
  * @param rate - 12 = 12 bit(240SPS max), 14 = 14 bit(60SPS max), 16 = 16 bit(15SPS max), 18 = 18 bit(3.75SPS max)
  */
  void set_bit_rate(char rate);
  /**
  * Set the conversion mode for ADC
  * @param mode - 0 = One shot conversion mode, 1 = Continuous conversion mode
  */
  void set_conversion_mode(char mode);
```

This program is free software: you can redistribute it and/or modify it under the terms of the GNU Gene ral Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses/.
