# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\mliha\Documents\Lab_3_Embedded\BLE Lab 3\BLE Lab 3.cydsn\BLE Lab 3.cyprj
# Date: Tue, 18 Oct 2016 15:06:01 GMT
#set_units -time ns
create_clock -name {Clock_1(FFB)} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/ff_div_7}]]
create_clock -name {ADC_intClock(FFB)} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/ff_div_6}]]
create_clock -name {CyHFCLK} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/hfclk}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 2 3} [list]
create_generated_clock -name {ADC_intClock} -source [get_pins {ClockBlock/hfclk}] -edges {1 5 9} [list]
create_clock -name {CyIMO} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CySYSCLK} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/sysclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyWCO} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/wco}]]
create_clock -name {CyLFCLK} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyECO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/eco}]]
create_clock -name {CyRouted1} -period 83.333333333333329 -waveform {0 41.6666666666667} [list [get_pins {ClockBlock/dsi_in_0}]]


# Component constraints for C:\Users\mliha\Documents\Lab_3_Embedded\BLE Lab 3\BLE Lab 3.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\mliha\Documents\Lab_3_Embedded\BLE Lab 3\BLE Lab 3.cydsn\BLE Lab 3.cyprj
# Date: Tue, 18 Oct 2016 15:05:56 GMT
