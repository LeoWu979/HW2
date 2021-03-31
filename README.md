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
### 8. Some results : 

waveform for 100Hz<br>
![image](https://github.com/LeoWu979/HW2/blob/master/Screenshot%20from%202021-03-31%2002-48-20.png)
<br>
FFT of 100Hz data<br>
![image](https://github.com/LeoWu979/HW2/blob/master/Screenshot%20from%202021-03-31%2002-51-10.png)
<br>
waveform for 200Hz<br>
![image](https://github.com/LeoWu979/HW2/blob/master/Screenshot%20from%202021-03-31%2002-48-52.png)
<br>
FFT of 200Hz<br>
![image](https://github.com/LeoWu979/HW2/blob/master/Screenshot%20from%202021-03-31%2002-49-55.png)
<br>
waveform for 400Hz<br>
![image](https://github.com/LeoWu979/HW2/blob/master/Screenshot%20from%202021-03-31%2002-52-18.png)
<br>
FFT of 400Hz<br>
![image](https://github.com/LeoWu979/HW2/blob/master/Screenshot%20from%202021-03-31%2002-52-44.png)
<br>
waveform for 500Hz<br>
![image](https://github.com/LeoWu979/HW2/blob/master/Screenshot%20from%202021-03-31%2002-53-29.png)
<br>
FFT of 500Hz<br>
![image](https://github.com/LeoWu979/HW2/blob/master/Screenshot%20from%202021-03-31%2002-54-19.png)

