/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg2910;

import java.util.Scanner;

/**
 *
 * @author Gordon Restivo
 */
public class Main {

    Scanner keyboard = new Scanner(System.in);

    /**
     * @param args the command line arguments
     */
    public void main(String[] args) {

        while (true) {
            System.out.println("Please input the length of the n-tuple (3-12)");
            int lexArraySize = keyboard.nextInt();

            int lexArray[] = new int[lexArraySize];
            int num = 1;
            for (int i = 0; i < lexArraySize; i++) {
                lexArray[i] = num;
                num++;
            }

            int j = 0;
            int endArray[] = new int[lexArraySize];
            for (int i = lexArraySize - 1; i >= 0; i--) {
                endArray[i] = lexArray[j];
                j++;
            }

            while (true) {
                int i = lexArray.length - 1;
                while (i > 0 && lexArray[i - 1] >= lexArray[i]) {
                    i--;
                }
                if (i <= 0) {
                    System.out.println("Done");
                    break;
                    //somehow end it
                }

                // Let lexArray[i - 1] be the pivot
                // Find rightmost element that exceeds the pivot
                int size = lexArray.length - 1;
                while (lexArray[j] <= lexArray[i - 1]) {
                    size--;
                }
                // Now the value lexArray[j] will become the new pivot
                // Assertion: j >= i

                // Swap the pivot with j
                int temp = lexArray[i - 1];
                lexArray[i - 1] = lexArray[j];
                lexArray[size] = temp;

                // Reverse the suffix
                size = lexArray.length - 1;
                while (i < size) {
                    temp = lexArray[i];
                    lexArray[i] = lexArray[size];
                    lexArray[size] = temp;
                    i++;
                    size--;
                }

                // Successfully computed the next permutation
            }

        }

    }

}
