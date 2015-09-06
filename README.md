# Making sound with an Arduino

This program is designed to test the audio amp for an ARDUINO DUE described here : http://www.thingiverse.com/thing:1001442

In the folder readwav, there's a small C program which converts a 16bits signed WAV file into a C header file. You will need libsndfile to compile the program.

This C header can be used in the Arduino progrma audiotest_wav.  
