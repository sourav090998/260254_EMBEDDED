# AUTOMATIC HEATED SEAT

## HARWARE INTERFACE AND CIRCUIT
![CIRCUIT](https://github.com/sourav090998/260254_EMBEDDED/blob/3cd52b633f245c972de1f65136a537d4de3d3694/simulation/CIRCUIT.png)


## In Action

### Until and unless the seat is occupied and at the same time the heater switch is activated, the Heater should not turn on.

|SW1|SW2|LED|SIMULATION|
|:--:|:--:|:--:|:--:|
|0|0|0|![](https://github.com/sourav090998/260254_EMBEDDED/blob/54924e6169ad7057edaa93f7d98ad6f968bf692c/simulation/1%20OFF%202%20OFF.png)|
|0|1|0|![](https://github.com/sourav090998/260254_EMBEDDED/blob/76887153bdeef2a8c958db9a378044be3d528cba/simulation/1%20OFF%202%20ON.png)|
|1|0|0|![](https://github.com/sourav090998/260254_EMBEDDED/blob/76887153bdeef2a8c958db9a378044be3d528cba/simulation/1%20ON%202%20OFF.png)|
|1|1|1|![](https://github.com/sourav090998/260254_EMBEDDED/blob/76887153bdeef2a8c958db9a378044be3d528cba/simulation/SW1%20and%20SW2%20ON.png)|

## PWM OUTPUT SIMULATIONS

|Input Analog value|Output PWM|Serial Data Trans|SIMULATION|
|:--:|:--:|:--:|:--:|
|0-200|20|20 C|![](https://github.com/sourav090998/260254_EMBEDDED/blob/e1d0cd95f4b80a04c81b0797c855949a140d2675/simulation/Screenshot%20(30).png)|
|210-500|40|25 C|![](https://github.com/sourav090998/260254_EMBEDDED/blob/e1d0cd95f4b80a04c81b0797c855949a140d2675/simulation/Screenshot%20(29).png)|
|510-700|70|29 C|![](https://github.com/sourav090998/260254_EMBEDDED/blob/e1d0cd95f4b80a04c81b0797c855949a140d2675/simulation/Screenshot%20(28).png)|
|710-1024|95|33-C|![](https://github.com/sourav090998/260254_EMBEDDED/blob/6a96d71ed88214d4b819318cbf3c0529f62aac1e/simulation/Screenshot(31).png)|

|Build|Cppcheck|Codacy|
|:--:|:--:|:--:|
|[![Compile-Linux](https://github.com/sourav090998/260254_EMBEDDED/actions/workflows/compile.yml/badge.svg)](https://github.com/sourav090998/260254_EMBEDDED/actions/workflows/compile.yml)|[![Cppcheck](https://github.com/sourav090998/260254_EMBEDDED/actions/workflows/cppcheck.yml/badge.svg)](https://github.com/sourav090998/260254_EMBEDDED/actions/workflows/cppcheck.yml)|[![Codacy Badge](https://api.codacy.com/project/badge/Grade/9d2d418664164d1c86a333e5ae0e701e)](https://app.codacy.com/gh/sourav090998/260254_EMBEDDED?utm_source=github.com&utm_medium=referral&utm_content=sourav090998/260254_EMBEDDED&utm_campaign=Badge_Grade_Settings)
