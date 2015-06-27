package com.acalabrese.core;

import java.util.Arrays;

/**
 * Keeps track of the internal state for the interpreter, such as the data array
 * and the pointer to the current spot.
 */
public class InterpreterState {
    public static int NUMBER_OF_CELLS = 30000;

    private int dataPointer;
    private byte[] data;

    public InterpreterState() {
        dataPointer = 0;
        data = new byte[NUMBER_OF_CELLS];
        Arrays.fill(data, (byte) 0);
    }

    public static void main(String[] args) {
        InterpreterState state = new InterpreterState();
        System.out.println("OKAY!!!");
    }
}