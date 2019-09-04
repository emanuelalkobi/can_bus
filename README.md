# CAN bus 2.0A
can_bus 2.0A software transmission emulation.

based on the next pages:
- http://socialledge.com/sjsu/index.php/DBC_Format
- https://en.wikipedia.org/wiki/CAN_bus#Frames

**Input parameters to the program**

- STRESS_FACTOR = 1.0 - 20.0
This parameter is used as multiplier to the above table values, in order to perform stress test
Default value: [1.0]

- DRIVE_SESSION_TIME = 1.0 sec – 30 min
Drive session emulation time. The program should run and generate the messages in a cyclic way with the:
TX_FREQUENCY * STRESS_FACTOR * DRIVE_SESSION_TIME in seconds, until the duration is reached.
Default value - [10 minutes]


**Data frame **
The data frame format in CAN bus 2.0A has the next structure:

- Start-of-frame [1]	Denotes the start of frame transmission
- Identifier (green)	11	A (unique) identifier which also represents the message priority
- Remote transmission request (RTR) (blue)	1	Must be dominant (0) for data frames and recessive (1) for remote request frames (see Remote Frame, below)
Identifier extension bit (IDE)	1	Must be dominant (0) for base frame format with 11-bit identifiers
- Reserved bit (r0)	1	Reserved bit. Must be dominant (0), but accepted as either dominant or recessive.
- Data length code (DLC) (yellow)	4	Number of bytes of data (0–8 bytes)[a]
- Data field (red)	0–64 (0-8 bytes)	Data to be transmitted (length in bytes dictated by DLC field)
- CRC	15	Cyclic redundancy check
- CRC delimiter	1	Must be recessive (1)
- ACK slot	1	Transmitter sends recessive (1) and any receiver can assert a dominant (0)
- ACK delimiter	1	Must be recessive (1)
- End-of-frame (EOF)	7	Must be recessive (1)

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






