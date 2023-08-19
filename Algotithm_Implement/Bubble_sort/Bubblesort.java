import java.util.*;
import java.io.*;

class Bubblesort {
    int [] arr = {2, 5, 3, 1, 4};

    public static void main(String[] args) {
        Bubblesort bs = new Bubblesort();

        bs.bubbleSort();

        for(int a : bs.arr) {
            System.out.println(a);
        }

        int i = 0;
    }

    public void bubbleSort() {
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