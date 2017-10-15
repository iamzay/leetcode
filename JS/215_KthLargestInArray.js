/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
  return FindKthLargest(nums,0,nums.length,k);
};

function FindKthLargest(nums,begin,end,k){
  let index=findPivot(nums,begin,end);
  if(index-begin==k-1)
    return nums[index];
  else if(index-begin>k-1)
    return FindKthLargest(nums,begin,index,k);
  else
    return FindKthLargest(nums,index+1,end,k-(index-begin)-1);
}

function findPivot(nums,begin,end){  // end取不到
  let n=end-begin;
  if(n==1) return begin;
  if(n==2) {
    if(nums[begin]>nums[begin+1]) [nums[begin],nums[begin+1]]=[nums[begin+1],nums[begin]];
    return  begin;
  }
  let pivot=median3(nums,begin,end);
  let left=begin,right=end-2;
  for(;;){
    while(nums[++left]<pivot)
      ;
    while(nums[--right]>pivot)
      ;
    if(left>=right)
      break;
    [nums[left],nums[right]]=[nums[right],nums[left]];
  }
  [nums[left],nums[end-2]]=[nums[end-2],nums[left]];
  return left;
}

function median3(nums,begin,end){
  let left=begin,right=end-1;
  let middle=Math.floor((left+right)/2);
  if(nums[left]>nums[middle])
    [nums[left],nums[middle]]=[nums[middle],nums[left]];
  if(nums[middle]>nums[right])
    [nums[middle],nums[right]]=[nums[right],nums[middle]];
  if(nums[left]>nums[right])
    [nums[left],nums[right]]=[nums[right],nums[left]];
  [nums[middle],nums[right-1]]=[nums[right-1],nums[middle]];
  return nums[right-1];
}
