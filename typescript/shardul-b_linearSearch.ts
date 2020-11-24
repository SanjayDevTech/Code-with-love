const arr:number[]= [1, 2, 3, 4, 5];
let value:number = 2;

const linearSearch=(arr:number[], value:number)=>{
	let i:any;
	for (i of arr) {
		if (i === value) {
		  return true;
		}
	}
  	return false;
}


let flag:any = linearSearch(arr, value);
flag?console.log(`The number ${value} is present`):console.log(`The number ${value} is present`);
