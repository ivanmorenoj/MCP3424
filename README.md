# MCP3424
This is a driver for raspberry py

# Requirements
```sh
$ apt install libi2c-dev
```
# Compilation
```sh
$ make
```
# Execute
```sh
$ ./mcp3424
```
# Usage
```
  MCP3424();

  MCP3424(struct MCP3424Config *_cnf);

  MCP3424Config *getConfig();

  void setConfigValues(struct MCP3424Config *_cnf);

  void setChannel(uint8_t channel);

  double readVoltage();

  double readVoltage(uint8_t channel);


  struct MCP3424Config {
    uint8_t address;
    uint8_t bitrate;
    uint8_t gain;
    uint8_t conv_mode;
    uint8_t channel;
  };

```

This program is free software: you can redistribute it and/or modify it under the terms of the GNU Gene ral Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses/.
