var findMedianSortedArrays = function(nums1, nums2) {
    let medianArr=[];
    for(let i=0;i<nums1.length;i++){
        medianArr.push(nums1[i]);
    }
    for(let i=0;i<nums2.length;i++){
        medianArr.push(nums2[i]);
    }
    let resulrArr=medianArr.sort((a,b)=>a-b);
    if(resulrArr.length>1){
    if(resulrArr.length%2!=0){
        let median=Math.floor(resulrArr.length/2);
        return resulrArr[median];
    }
    if(resulrArr.length%2==0){
        let median=Math.floor(resulrArr.length/2);
         
         return ((resulrArr[median-1]+resulrArr[median])/2);
    }
  
}

return resulrArr[0];

    
};