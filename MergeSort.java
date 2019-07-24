class MergeSort {

	public void merge(int[] array, int l, int m, int r) {
		//find sizes of 2 subarrays to be merged
		int n1 = m - l + 1;
		int n2 = r-m;
		
		//create temp arrays
		int[] left = new int[n1];
		int[] right = new int[n2];
		
		//Copy data to temp arrays
		for (int i = 0; i<n1; i++) {
			n1[i] = array[l+i]
		}
		for (int i = 0; i<n2; i++) {
			n1[i] = array[m+i + 1]
		}
		
		//Merge the 2 arrays...not shown here...
		
	}
	
	public void sort(int[] array, int l, int r) {
		if (l<r) {
			//find the middle point
			int m = (l+r)/2;
			
			//sort first and second halves
			sort(array, l, m);
			sort(array, m, r);
			
			//merge the sorted halves
			merge(array, l, m, r);
		}
}