var findPermutations = function(nums, i, permutations) {
  
    if(i == nums.length) {
        permutations.push(nums.map(val => val));
    } else {
        for(let j = i; j < nums.length; ++j) {
            [nums[i], nums[j]] = [nums[j], nums[i]];
            findPermutations(nums, i + 1, permutations);
            [nums[i], nums[j]] = [nums[j], nums[i]];
        }
    }
    
}

var permute = function(nums) {
    
    let permutations = new Array();
    
    findPermutations(nums, 0, permutations);
    
    return permutations
};