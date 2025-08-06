class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] temp = new int[nums1.length+nums2.length];
        int i = 0,j=0,k=0;
        while(i< nums1.length || j<nums2.length){
            if(i< nums1.length){
                temp[k++] = nums1[i];
                i++;
            }
            else if(j<nums2.length){
                temp[k++] = nums2[j];
                j++;
            }
        }
        Arrays.sort(temp);
        if(temp.length%2 == 0){
            return (temp[temp.length/2]+temp[temp.length/2 - 1])/2.0;
        }
        else{
            return temp[temp.length/2];
        }
    }
}