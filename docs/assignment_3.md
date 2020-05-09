# Assignment 3
## Description
You have been given a 1D lidar sensor data.
Go through its datasheet provided within this folder
Especially the "Serial port data communication" part

## Task
In the file data.bin
you have been given a large set of binary stream received from the lidar.
Each data stream has been seperated by a `\x0A (newline byte)`
Extract the distance and signal info and plot a graph for both

This is a practically obtained data set
so discard any impractical values which may have been recorded
refer the datasheet to know what impractical means for this lidar

## Input
* `data.bin` file contains a large set of binary stream received from the lidar.
* The program on running must ask the user name of the file to be read

## Output
* The program must output two files `distance.txt` and `signal.txt` which contains distance and signal data on each line. The extracted data can be plotted using gnuplot

### Plotting using gnuplot

* Saharash add kar yaha, even installation details for windows and linux, amd how to use

## Submission Instructions
* You must create a zip file, which should contain source files, executable program, files distance.txt, signal.txt and screenshot of the plots for distance and signal value.

## Example
```
sra@sra20:~$ ./assignment
sra@sra20:~$ enter name of file to be read: data.txt
sra@sra20:~$ number of nodes: 4
sra@sra20:~$ number turns: 2
sra@sra20:~$ final direction: 1
```
