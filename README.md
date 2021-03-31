# HW2
### 1. Setup of 3 buttons : <br>
- D13 for "confirm" frequency<br>
- D12 for "select down"<br>
- D11 for "select up"<br>
### 2. Setup of DAC and ADC pin name: <br>
- D7 for DAC pin<br>
- A0 for ADC pin<br>
### 3. Some other electronic component : <br>
- RC filter : 9400ohm of resistor and 47nF of capacitor.<br>
- uLCD : tx <-> D1, rx <-> D0, reset <-> D2.<br>
### 4. Compile "main.cpp" with mbed command.<br>
### 5. Frequency selection : <br>
- I design a menu form of frequency selection. Please focus on uLCD screen.<br>
- Four frequency choice : 100Hz, 200Hz, 400Hz and 500Hz.<br>
- "select down" will move down the selection rectangle, "select up" will move up the selection rectangle.<br>
- Push "confirm" to input frequency to system.<br>
### 6. You can use picoscope to observe waveform.(after or not pass through RC filter)<br>
### 7. Python analysis : <br>
- Compile "FFT.py" with python command : sudo python3 FFT.py<br>
- You will see two figure, the first is the waveform after RC filter, second is the frequency response of FFT.<br>

![image](https://github.com/LeoWu979/HW2/blob/master/Screenshot%20from%202021-03-31%2002-48-20.png)
