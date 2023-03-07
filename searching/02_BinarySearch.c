int binarySearch(int array[], int x, int low, int high) {
	if(low>high) return -1;
	int mid = (low + high) / 2;
	if (array[mid] == x) 
		return mid;
	else if (array[mid] < x) 
		return binarySearch(arr, x, mid + 1, high);
	else 
		return binarySearch(arr, x, low, mid - 1);
}