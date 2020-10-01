function unique(arr1,arr2,uniqueArr) { 
	for(var i=0; i<arr1.length; i++) { 
		flag = 0; 
		for(var j=0; j<arr2.length; j++) { 
			if(arr1[i] === arr2[j]) { 
				arr2.splice(j,1); 
				j--; 
				flag = 1; 
			} 
		} 

		if(flag == 0) { 
			uniqueArr.push(arr1[i]); 
		} 
	} 
	uniqueArr.push(arr2); 
	return uniqueArr; 
} 

var arr1 = [54, 71, 58, 95, 20]; 

var arr2 = [71, 51, 54, 33, 80]; 

var uniqueArr = []; 

console.log("Unique elements in the two arrays are:"); 
console.log(unique(arr1,arr2,uniqueArr).flat()); 
