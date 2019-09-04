# can_bus
can_bus 2.0A software transmission emulation.

Input parameters to the program
- STRESS_FACTOR = 1.0 - 20.0
This parameter is used as multiplier to the above table values, in order to perform stress test
**Default value: [1.0]
**- DRIVE_SESSION_TIME = 1.0 sec – 30 min
Drive session emulation time. The program should run and generate the messages in a cyclic way with the:
TX_FREQUENCY * STRESS_FACTOR * DRIVE_SESSION_TIME in seconds, until the duration is reached.
**Default value - [10 minutes]
**

In this emulation there are only 3 type of messages:
1.**wheel_speeds**
- id:464
- data size : 8 bytes
- frequency:100 hz

**2.brake_module**
- id:446
- data size : 3 bytes
- frequency:10 hz

**3.powertrain_data:**
- id:380
- data size : 8 bytes
- frequency:25 hz






