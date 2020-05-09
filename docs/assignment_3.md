# Assignment 3
## Download 
[Download](<Add download link here>)
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
* The program on running must ask the name of the file to be read

## Output
* The program must output two files `distance.txt` and `signal.txt` which contains distance and signal data.
* Each line in file must be of the form `<reading_number_as_per_data>, <distance or strength_value>`
* The extracted data can be plotted using gnuplot

### Installing gnuplot
* For Ubuntu
    sudo apt-get install gnuplot
Running `gnuplot` should result in:
    G N U P L O T
        Version 5.0 patchlevel 3    last modified 2016-02-21 

        Copyright (C) 1986-1993, 1998, 2004, 2007-2016
        Thomas Williams, Colin Kelley and many others

        gnuplot home:     http://www.gnuplot.info
        faq, bugs, etc:   type "help FAQ"
        immediate help:   type "help"  (plot window: hit 'h')

    Terminal type set to 'qt'
    gnuplot>

### Plotting using gnuplot

    gnuplot> plot "./distance.txt" using 1:2 with linespoints  

    gnuplot> plot "./signal.txt" using 1:2 with linespoints  

## Submission Instructions
* You must create a zip file, which should contain source files, executable program, files distance.txt, signal.txt and screenshot of the plots for distance and signal value.

## Example
```
sra@sra20:~$ ./assignment
sra@sra20:~$ enter name of file to be read: data.bin
```
