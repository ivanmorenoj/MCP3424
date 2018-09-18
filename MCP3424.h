/*
*  MCP3424 Driver for cpp
*  Author : Ivan Moreno
*
*  Based in ABE_ADCDifferentialPi from ABE Electronics
*
*  Required package{
*    apt-get install libi2c-dev}
*/
#ifndef MCP3424_H_
#define MCP3424_H_

class MCP3424{

private:
  // private variables
  int i2cbus;           // enumerate i2c bus
  char i2caddress;      // addres of i2c
  char config;          // config byte
  char currentchannel;  // actual channel
  char bitrate;         // bitrate of device
  char conversionmode;  // mode of conversion mode
  double pga;           // gain of device
  double lsb;           // least significative bit
  char writebuffer[1];  // write buffer
  char readbuffer[10];  // read buffer
  char signbit;         // sign bit

  // private methods
    /**
    * private method for writing a byte to the I2C port
    */
    void write_byte(char reg, char value);
    /**
    * private method for reading bytes from the I2C port
    */
    void read_byte_array(char address, char reg, char length);
    /**
    * private method for setting the value of a single bit within a byte
    */
    char update_byte(char byte, char bit, char value);
    /**
    * private method for setting the channel
    */
    void set_channel(char channel);

public:
  /*
  * The first constructor
  */
  MCP3424();
  /**
   * Initialises the ADCs
   * @param address - I2C address1 for the target device e.g. 0x68
   * @param bitrate (optional) - 12, 14, 16 or 18
   */
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
};

#endif
