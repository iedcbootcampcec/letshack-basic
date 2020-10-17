
class FibonacciSequence {

    private static int[] fibonacciSequence(int n) {
        int[] result = new int[n + 1];
        result[1] = 0;
        result[2] = 1;

        for (int i = 3; i <= n; i++) {
            result[i] = result[i - 1] + result[i - 2];
        }

        return result;
    }

}
