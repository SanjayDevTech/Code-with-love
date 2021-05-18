function insertion_Sort_algo(arr)
{
for (var i = 1; i < arr.length; i++)
{
if (arr[i] < arr[0])
{
arr.unshift(arr.splice(i,1)[0]);
}
else if (arr[i] > arr[i-1])
{
continue;
}
else {
for (var j = 1; j < i; j++) {
if (arr[i] > arr[j-1] && arr[i] < arr[j])
{
arr.splice(j,0,arr.splice(i,1)[0]);
}
}
}
}
return arr;
}
console.log(insertion_Sort_algo([44, 20, 26, 54, -9, 41, 16]));