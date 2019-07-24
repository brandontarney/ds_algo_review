//This is the recursive binary search
class BinarySearch {

	int binarySearch (int[] arr, int l, int r, int x) {
		if (r >= 1) {
			int mid = 1 + (r-1)/2
			
			//if the element is present at the middle
			if (arr[mid] == x) {
				return mid
			}
			
			//If element is smaller than mid, do left subarray
			
			if (arr[mid] > x) {
				return binarySearch(arr, 1, mid-1, x);
			}
			
			//otherwise the element must be in the right subarray
			return binarySearch(arr, mid+1, r, x);
		}
		//We reach here when the elemnt is not present in the array
		return -1;
}