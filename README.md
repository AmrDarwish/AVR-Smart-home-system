
# Smart Home Embedded System Project

This project involves creating a smart home system using multiple microcontrollers and various components. The system will enable users to control home devices through a smart interface.

### Components:

- Atmega32 microcontroller: Quantity > 2
- LCD 16X2: Quantity > 1
- KeyPad 4x4: Quantity > 1
- LM35 temperature sensor: Quantity > 1
- LDR sensor: Quantity > 1
- External EEPROM: Quantity > 1
- Limited Servo Motor: Quantity > 1
- DC Motor: Quantity > 1
- Stepper Motor: Quantity > 1
- LED: Quantity > 8
- Seven-Segment Display: Quantity > 2

### Project Description:

1. **System Overview:**
    - **Master Microcontroller (MCU1):** Responsible for system input.
    - **Modes Available:** Users can choose from three modes:
        1. Open Smart System
        2. Change Password

2. **Open Smart System:**
    - Users authenticate by entering a User ID and password.
    - MCU1 verifies credentials:
        - Incorrect ID prompts for a valid ID.
        - Correct password grants control of home devices via a smartphone.
        - Three incorrect password attempts return users to the main menu.

    - **Slave Microcontroller (MCU2):** Controls various behaviors based on inputs received:
        - Temperature regulation
        - Ambient light control
        - Controlling devices such as door, fan, garage door, and lights via Bluetooth commands.

    - **Notes:**
        - Data transmission between MCUs via SPI protocol.
        - Passwords stored in non-volatile memory (External EEPROM).
        - Display temperature degrees on two Seven-Segment displays.
        - Use timers instead of _delay_ms function for delay operations.

3. **Change Password:**
    - Users can change their password after authentication.
    - Validate User ID and previous password.
        - Incorrect ID prompts for a valid ID.
        - Correct previous password allows entry of a new password.
        - One incorrect attempt returns users to the main menu.



