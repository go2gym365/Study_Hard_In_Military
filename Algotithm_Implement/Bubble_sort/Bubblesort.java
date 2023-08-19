import java.util.*;
import java.io.*;

class Bubblesort {
    static int [] arr = {2, 5, 3, 1, 4};

    public static void main(String[] args) {
        bubbleSort();

        for(int a : arr) {
            System.out.println(a);
        }
    }

    public static void bubbleSort() {
        for(int i = 0; i < arr.length; i++) {
            for(int j = 1; j < arr.length - i; j++) {
                if(arr[j - 1] > arr[j]) {
                    int temp = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}