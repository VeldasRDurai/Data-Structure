void insertionSort(int array[], int n) {
    for (int i=1; i<n; i++) {
		int key = array[i];
		int j = i - 1;
		while ( key<array[j] && j >= 0 ) {
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
    }
}