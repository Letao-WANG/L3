import java.util.Collections;
import java.util.PriorityQueue;

public class Util {
    public static void priorityQueueTest() {
        System.out.println("Priority Queue Test:");
        PriorityQueue<Integer> pQueue = new PriorityQueue<>();
        pQueue.add(12);
        pQueue.add(-10);
        pQueue.add(-4);
        pQueue.add(2);
        pQueue.add(7);
        pQueue.add(4);
        long startTime = System.nanoTime();
        pQueue.poll();
        long stopTime = System.nanoTime();
        System.out.println("Extract min time: " + (stopTime - startTime));

        startTime = System.nanoTime();
        getTail(pQueue);
        stopTime = System.nanoTime();
        System.out.println("Extract max time: " + (stopTime - startTime));
        System.out.println(" ");
    }

    public static Object getTail(PriorityQueue pq) {
        PriorityQueue newPq = new PriorityQueue<>(Collections.reverseOrder());
        while (pq.size() > 0) {
            newPq.add(pq.poll());
        }
        pq.clear();
        return newPq.poll();
    }

    public static void quickSortTest(){
        System.out.println("Quick Sort Test:");
        int intArray[] = {4, 7, 2, -4, -10, 12};
        long startTime = System.nanoTime();
        quickSort(intArray, 0, intArray.length-1);
        int poll = intArray[0];
        long stopTime = System.nanoTime();
        System.out.println("Extract min time: " + (stopTime - startTime));

        startTime = System.nanoTime();
        quickSort(intArray, 0, intArray.length-1);
        int tail = intArray[intArray.length-1];
        stopTime = System.nanoTime();
        System.out.println("Extract max time: " + (stopTime - startTime));

    }

    //selects last element as pivot, pi using which array is partitioned.
    public static int partition(int intArray[], int low, int high) {
        int pi = intArray[high];
        int i = (low-1); // smaller element index
        for (int j=low; j<high; j++) {
            // check if current element is less than or equal to pi
            if (intArray[j] <= pi) {
                i++;
                // swap intArray[i] and intArray[j]
                int temp = intArray[i];
                intArray[i] = intArray[j];
                intArray[j] = temp;
            }
        }

        // swap intArray[i+1] and intArray[high] (or pi)
        int temp = intArray[i+1];
        intArray[i+1] = intArray[high];
        intArray[high] = temp;

        return i+1;
    }


    //routine to sort the array partitions recursively
    public static void quickSort(int intArray[], int low, int high) {
        if (low < high) {
            //partition the array around pi=>partitioning index and return pi
            int pi = partition(intArray, low, high);

            // sort each partition recursively
            quickSort(intArray, low, pi-1);
            quickSort(intArray, pi+1, high);
        }
    }

}
